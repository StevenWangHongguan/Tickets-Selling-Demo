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
	thread threads[10]; //�߳����� ��10���߳� 
	clock_t start = clock(); //��¼��Ʊ��ʼʱ��
	TicketSeller3::numTicketToSell = numTicket; //��ƱԱҪ���۵�Ʊ����150��
	for (int agent = 1; agent <= numAgent; agent++){
		//��ʼ����ƱԱ ��ֵ��ƱԱ���������Ҫ��Ʊ������
		TicketSeller3 thisSeller(agent); //ע���2������ ����ƽ��������Ʊ���� 
		//���θ�ֵ���߳����� ���ø��߳�ִ�и���ƱԱ����Ʊ����
		threads[agent - 1] = thread(SellTicket, thisSeller); 
	}
	clock_t end = clock(); //��¼��Ʊ����ʱ��
	for (auto& th : threads) th.join();
	cout << "��ʱ" << end - start << "ms" << endl; //��ӡ��Ʊ��ʱ
}