#include<iostream>
#include<thread>
#include"TicketSeller2.h"
using namespace std;

void SellTicket(TicketSeller2& t){
	while (t.numTicketToSell > 0){
		cout << "agent:" << t.agent << " sells:"
			<< t.numTicketToSell << " ticket" << endl;
		t.numTicketToSell--;
	}
}

int main(){
	int numAgent = 10;
	int numTicket = 150;
	thread threads[10];
	clock_t start = clock();
	for (int agent = 1; agent <= numAgent; agent++){
		TicketSeller2 thisSeller(agent, numTicket / numAgent);
		threads[agent - 1] = thread(SellTicket, thisSeller);
	}
	clock_t end = clock();
	for (auto& th : threads) th.join();
	cout << "ÓÃÊ±" << end - start << "ms" << endl;
}