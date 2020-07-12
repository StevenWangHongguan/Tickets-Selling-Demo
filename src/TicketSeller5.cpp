#include<iostream>
#include<thread>
#include<mutex>
#include<stdexcept>
#include"TicketSeller5.h"
using namespace std;

mutex mtx; //互斥锁
void SellTicket(TicketSeller5& t){
	try{
		while (true){
			int num = 0;
			unique_lock<mutex> lck(mtx); //使用unique_lock进行互斥锁控制
			if (t.numTicketToSell > 0){
				num = t.numTicketToSell;
				t.numTicketToSell--;
			}
			else{ //票已经售完
				break; //unique_lock<mutex> lck会在函数调用结束后自动调用析构函数释放mtx锁
			}
			cout << "agent:" << t.agent << " sells " << num << " ticket" << endl;
			lck.unlock(); //手动释放 防止自身线程重复上锁造成死锁
		}
	}
	catch (exception &e){ //捕捉售票过程中抛出的异常
		cout << "Exception:" << e.what() << endl;
	}
	cout << "agent:" << t.agent << " all done!" << endl;
}
int TicketSeller5::numTicketToSell = 0;
int main(){
	int numAgent = 10;
	int numTicket = 150;
	thread threads[10]; //线程数组 共10个线程 
	TicketSeller5::numTicketToSell = numTicket; //售票员要销售的票量共150张
	clock_t start = clock(); //记录售票开始时间
	for (int agent = 1; agent <= numAgent; agent++){
		//初始化售票员 赋值售票员号码和其需要售票的数量
		TicketSeller5 thisSeller(agent); //注意和2的区别 不再平均分配售票数量 
		//依次赋值给线程数组 并用该线程执行该售票员的售票过程
		threads[agent - 1] = thread(SellTicket, thisSeller);
	}
	clock_t end = clock(); //记录售票结束时间
	for (auto& th : threads) th.join();
	cout << "用时" << end - start << "ms" << endl; //打印售票用时
}