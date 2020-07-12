#include<iostream>
#include<thread>
#include"TicketSeller3.h"
using namespace std;

void SellTicket(TicketSeller3& t){
	while (t.numTicketToSell > 0){
		cout << "agent:" << t.agent << " sells:" 
			<< t.numTicketToSell << " ticket" << endl;
		t.numTicketToSell--;
	}
	cout << "agent:" << t.agent << " all done!" << endl;
}
int TicketSeller3::numTicketToSell = 0;
int main(){
	int numAgent = 10;
	int numTicket = 150;
	thread threads[10]; //线程数组 共10个线程 
	clock_t start = clock(); //记录售票开始时间
	TicketSeller3::numTicketToSell = numTicket; //售票员要销售的票量共150张
	for (int agent = 1; agent <= numAgent; agent++){
		//初始化售票员 赋值售票员号码和其需要售票的数量
		TicketSeller3 thisSeller(agent); //注意和2的区别 不再平均分配售票数量 
		//依次赋值给线程数组 并用该线程执行该售票员的售票过程
		threads[agent - 1] = thread(SellTicket, thisSeller); 
	}
	clock_t end = clock(); //记录售票结束时间
	for (auto& th : threads) th.join();
	cout << "用时" << end - start << "ms" << endl; //打印售票用时
}