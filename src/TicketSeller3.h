#include<iostream>
using namespace std;
class TicketSeller3{
public:
	TicketSeller3(int a) :agent(a){}
	int agent;
	static int numTicketToSell;
};