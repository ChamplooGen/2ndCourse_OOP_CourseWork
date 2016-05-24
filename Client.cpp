#include "ClientAndServer.h"
int Client::commonID = 0;

Client::Client() 
{
	commonID++;
	id = commonID;
	history = new MessageHistory();
}

Client::~Client()
{
	delete history;
}

void Client::ShowMessageHistory() const
{
	history->ShowHistory();
}

void Client::SendPrivateMessage(Server *server) const
{
	server->ShowListOfClients();
	Message mess;
	mess.FillMessage(this->GetUserID(), false);
	server->MessageForCurrClient(mess);
}

void Client::SendPublicMessage(Server *server) const
{
	server->ShowListOfClients();
	Message mess;
	mess.FillMessage(this->GetUserID(), true);
	server->MessageForEverybody(mess);
}

