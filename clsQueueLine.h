#pragma once
#include<iostream>
#include<queue>
#include<stack>
#include<string>

#include"clsDate.h"
using namespace std;

class clsQueueLine
{
private:
	string _Prefix;
	int _TotalTickets;
	int _ServedClients = 0;
	int _ServingTime;

	

	struct _stTicketData {

		string TicketSerialNumber;
		string Date;
		int WaitingClients;
		int TimeRemainingToServe;
	};

	queue <_stTicketData> _TicketsQueue;
	queue <_stTicketData> _CopyQueue;

public:

	clsQueueLine(string Prefix, int ServingTime) {

		_Prefix = Prefix;
		_ServingTime = ServingTime;
	}

	void IssueTicket() {

		_TotalTickets++;
		
		_stTicketData TicketData;
		TicketData.TicketSerialNumber = _Prefix + to_string(_TotalTickets);
		TicketData.Date = clsDate::GetSystemDateTimeString();
		TicketData.WaitingClients = _TicketsQueue.size();
		TicketData.TimeRemainingToServe = _ServingTime * TicketData.WaitingClients;

		_TicketsQueue.push(TicketData);
	}

	void PrintInfo() {

		cout << "\n\t\t\t\t\t_________________________________\n\n";
		cout << "\t\t\t\t\t\tQueue Info\n\n";
		cout << "\t\t\t\t\t_________________________________\n\n";
		cout << "\t\t\t\t\t  Prefix   = " << _Prefix << endl;
		cout << "\t\t\t\t\t  Total Tickets = " << _TotalTickets << endl;
		cout << "\t\t\t\t\t  Served Clients  = " << _ServedClients << endl;
		cout << "\t\t\t\t\t  Waiting Clients  = " << _TicketsQueue.size() << endl;
		cout << "\n\t\t\t\t\t_________________________________\n\n";

	}

	void PrintTicketsLineRTL() {

		cout << "\n";

		while (!_TicketsQueue.empty()) {

			cout << _TicketsQueue.front().TicketSerialNumber << " <-- ";

			_CopyQueue.push(_TicketsQueue.front());
			_TicketsQueue.pop();
		}
		
		_CopyQueue.swap(_TicketsQueue);
	}

	void PrintTicketsLineLTR() {

		cout << "\n\n";

		stack <_stTicketData> TicketsStack;

		while (!_TicketsQueue.empty()) {

			TicketsStack.push(_TicketsQueue.front());
			_CopyQueue.push(_TicketsQueue.front());
			_TicketsQueue.pop();
		}

		while (!TicketsStack.empty()) {

			cout << TicketsStack.top().TicketSerialNumber << " --> ";
			TicketsStack.pop();
		}

		_CopyQueue.swap(_TicketsQueue);
	}

	void PrintAllTickets() {

		cout << "\n\n\t\t\t\t\t - - - Tickets - - -\n";
		cout << "\n\t\t\t\t_________________________________\n\n";

		while (!_TicketsQueue.empty()) {

			cout << "\n\t\t\t\t_________________________________\n\n";
			cout << "\n\t\t\t\t\t\t " << _TicketsQueue.front().TicketSerialNumber << endl;
			cout << "\n\t\t\t\t " << _TicketsQueue.front().Date << endl;
			cout << "\n\t\t\t\t Waiting Clients : " << _TicketsQueue.front().WaitingClients << endl;
			cout << "\n\t\t\t\t   Serve Time In \n\t\t\t\t\t\t" <<
				_TicketsQueue.front().TimeRemainingToServe << endl;
			cout << "\n\t\t\t\t_________________________________\n\n";

			_CopyQueue.push(_TicketsQueue.front());
			_TicketsQueue.pop();
		}

		_CopyQueue.swap(_TicketsQueue);
		
	}

	void ServeNextClient() {

		_ServedClients++;

		_TicketsQueue.pop();
	}
};

