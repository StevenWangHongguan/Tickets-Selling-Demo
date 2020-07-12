#include<iostream>
#include<mutex>
using namespace std;
class TicketSeller5{
public:
	TicketSeller5(int a) :agent(a){}
	int agent;
	static int numTicketToSell;
};