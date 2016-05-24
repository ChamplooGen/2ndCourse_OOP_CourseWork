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
	Node *curr, // текущий элемент списка клиентов
		*tail;	// хвост списка клиентов
	int id;
	static int commonID;
	void MoveForward();
	void MoveBackward();
	Client * GetCurrClient() const;
	bool IsRegistered(Message &message);	// проверяет, зарегистрирован ли отправитель на данном сервере		<-- перенести в private?

public:
	Server();
	~Server();
	void ShowListOfClients();	// показать список всех клиентов
	void AddNewClient(Client &newClient);	// добавить клиента 
	void MessageForCurrClient(Message &message); // сообщение для конкретного пользователя
	void MessageForEverybody(Message &message);	 // сообщение для всех
	static int GetCommonID() { return commonID; };
	int GetServerID() const { return id; };
};

class Client {
private:
	int id;
	static int commonID;	// последний выданный ID
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