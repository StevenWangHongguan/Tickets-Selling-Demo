#include<iostream>
using namespace std;
class TicketSeller2{
public:
	TicketSeller2(int a, int n) :agent(a), numTicketToSell(n){}
	int agent;
	int numTicketToSell;
};