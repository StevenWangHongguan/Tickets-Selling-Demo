#include<iostream>
#include<mutex>
using namespace std;
class TicketSeller4{
public:
	TicketSeller4(int a) :agent(a){}
	int agent;
	static int numTicketToSell;
	static mutex lock;
};