#include<iostream>
#include"clsQueueLine.h"

using namespace std;

int main() {

	clsQueueLine PayBillsQueue("A0", 10);
	clsQueueLine SubscriptionsQueue("B0", 5);

	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();

	cout << "\nPay Bills Info :\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	PayBillsQueue.ServeNextClient();
	cout << "\nPay Bills Queue After Serving One Client : \n";
	PayBillsQueue.PrintInfo();

	cout << "\nSubscriptions Queue Info : \n\n";
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();
	SubscriptionsQueue.IssueTicket();

	SubscriptionsQueue.PrintInfo();

	SubscriptionsQueue.PrintTicketsLineRTL();
	SubscriptionsQueue.PrintTicketsLineLTR();

	SubscriptionsQueue.PrintAllTickets();

	SubscriptionsQueue.ServeNextClient();

	cout << "\nSubscriptions Queue Info After Serving One Client: \n";
	SubscriptionsQueue.PrintInfo();

	system("pause>0");
}