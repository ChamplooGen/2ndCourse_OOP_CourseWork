#pragma once

#include "Message.h"
#include "MessageHistory.h"

class Client;

class Server{
private:
	struct Node
	{
		Node *next;
		Node *prev;
		Client *client;
		Node() { prev = next = NULL; client = NULL; }
	};
	Node *curr, // ������� ������� ������ ��������
		*tail;	// ����� ������ ��������
	int id;
	static int commonID;
	void MoveForward();
	void MoveBackward();
	Client * GetCurrClient() const;
	bool IsRegistered(Message &message);	// ���������, ��������������� �� ����������� �� ������ �������		<-- ��������� � private?

public:
	Server();
	~Server();
	void ShowListOfClients();	// �������� ������ ���� ��������
	void AddNewClient(Client &newClient);	// �������� ������� 
	void MessageForCurrClient(Message &message); // ��������� ��� ����������� ������������
	void MessageForEverybody(Message &message);	 // ��������� ��� ����
	static int GetCommonID() { return commonID; };
	int GetServerID() const { return id; };
};

class Client {
private:
	int id;
	static int commonID;	// ��������� �������� ID
	MessageHistory * history;

public:
	Client();
	~Client();

	int GetUserID() const { return id; };
	MessageHistory * GetHistory() const { return history; };
	static int GetCommonUserID() { return commonID; };

	void SendPrivateMessage(Server *server) const;
	void SendPublicMessage(Server *server) const;

	void ShowMessageHistory() const;
};