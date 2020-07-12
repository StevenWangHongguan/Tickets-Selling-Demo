#include<iostream>
#include<thread>
#include"TicketSeller1.h"
using namespace std;
int main(){
	TicketSeller1 s;
	int numAgent = 10;
	int numTicket = 150;
	clock_t start = clock();
	for (int agent = 1; agent <= numAgent; agent++){
		s.SellTicket(agent, numTicket / numAgent);
	}
	clock_t end = clock();
	cout << "ÓÃÊ±" << end - start << "ms" << endl;
}
