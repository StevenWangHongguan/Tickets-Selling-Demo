#include<iostream>
#include<thread>
#include<mutex>
#include"TicketSeller4.h"
using namespace std;

void SellTicket(TicketSeller4& t){
	t.lock.lock();
	while (t.numTicketToSell > 0){
		cout << "agent:" << t.agent << " sells:" << t.numTicketToSell << " ticket" << endl;
		t.numTicketToSell--;
	}
	t.lock.unlock();
	cout << "agent:" << t.agent << " all done!" << endl;
}
int TicketSeller4::numTicketToSell = 0;
mutex TicketSeller4::lock;
int main(){
	int numAgent = 10;
	int numTicket = 150;
	thread threads[10]; //�߳����� ��10���߳� 
	clock_t start = clock(); //��¼��Ʊ��ʼʱ��
	TicketSeller4::numTicketToSell = numTicket; //��ƱԱҪ���۵�Ʊ����150��
	for (int agent = 1; agent <= numAgent; agent++){
		//��ʼ����ƱԱ ��ֵ��ƱԱ���������Ҫ��Ʊ������
		TicketSeller4 thisSeller(agent); //ע���2������ ����ƽ��������Ʊ���� 
		//���θ�ֵ���߳����� ���ø��߳�ִ�и���ƱԱ����Ʊ����
		threads[agent - 1] = thread(SellTicket, thisSeller);
	}
	clock_t end = clock(); //��¼��Ʊ����ʱ��
	for (auto& th : threads) th.join();
	cout << "��ʱ" << end - start << "ms" << endl; //��ӡ��Ʊ��ʱ
}