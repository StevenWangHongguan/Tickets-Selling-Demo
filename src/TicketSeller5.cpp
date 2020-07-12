#include<iostream>
#include<thread>
#include<mutex>
#include<stdexcept>
#include"TicketSeller5.h"
using namespace std;

mutex mtx; //������
void SellTicket(TicketSeller5& t){
	try{
		while (true){
			int num = 0;
			unique_lock<mutex> lck(mtx); //ʹ��unique_lock���л���������
			if (t.numTicketToSell > 0){
				num = t.numTicketToSell;
				t.numTicketToSell--;
			}
			else{ //Ʊ�Ѿ�����
				break; //unique_lock<mutex> lck���ں������ý������Զ��������������ͷ�mtx��
			}
			cout << "agent:" << t.agent << " sells " << num << " ticket" << endl;
			lck.unlock(); //�ֶ��ͷ� ��ֹ�����߳��ظ������������
		}
	}
	catch (exception &e){ //��׽��Ʊ�������׳����쳣
		cout << "Exception:" << e.what() << endl;
	}
	cout << "agent:" << t.agent << " all done!" << endl;
}
int TicketSeller5::numTicketToSell = 0;
int main(){
	int numAgent = 10;
	int numTicket = 150;
	thread threads[10]; //�߳����� ��10���߳� 
	TicketSeller5::numTicketToSell = numTicket; //��ƱԱҪ���۵�Ʊ����150��
	clock_t start = clock(); //��¼��Ʊ��ʼʱ��
	for (int agent = 1; agent <= numAgent; agent++){
		//��ʼ����ƱԱ ��ֵ��ƱԱ���������Ҫ��Ʊ������
		TicketSeller5 thisSeller(agent); //ע���2������ ����ƽ��������Ʊ���� 
		//���θ�ֵ���߳����� ���ø��߳�ִ�и���ƱԱ����Ʊ����
		threads[agent - 1] = thread(SellTicket, thisSeller);
	}
	clock_t end = clock(); //��¼��Ʊ����ʱ��
	for (auto& th : threads) th.join();
	cout << "��ʱ" << end - start << "ms" << endl; //��ӡ��Ʊ��ʱ
}