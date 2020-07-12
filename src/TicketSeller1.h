#include<iostream>
using namespace std;
class TicketSeller1{
public:
	void SellTicket(int agent, int numTicketToSell){
		while (numTicketToSell > 0){
			cout << "agent:" << agent << " sells a ticket" << endl;
			numTicketToSell--;
		}
	}
};