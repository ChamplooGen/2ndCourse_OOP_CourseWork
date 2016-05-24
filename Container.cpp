#include "Container.h"

//int Container::containerCommonId = 0;

Container::Container()
{
	/*containerCommonId++;
	containerId = containerCommonId;*/
	std::cout << " Работа конструктора контейнера\n";
	tail = curr = head = NULL;
}


Container::~Container()		// Check work-ability
{
	std::cout << " Работа деструктора контейнера\n";
	curr = tail;
	if (!head) { std::cout << "\n Список уже пуст.\n"; }
	else
	{
		tail->next = NULL;	// разрываем цикличность списка для удобства его удаления
		head->prev = NULL;
		while (head->next != NULL)
		{
			tail = tail->prev;
			tail->next = NULL;

			curr->ptr = NULL;
			curr->next = NULL;
			curr->prev = NULL;
			delete curr;
			curr = tail;
		}
		curr->prev = NULL;
		curr->next = NULL;
		curr->ptr = NULL;
		delete curr;
		curr = tail = head = NULL;
	}
}

void Container::AddElement(Base &obj)	// добавление нового элемента в список
{	
	if (head == NULL)	// если список пуст, создаем первый элемент списка
	{
		head = new Node;	// создаем элемент списка
		head->ptr = &obj;	// сохраняем указатель на объект
		/*head->next = NULL;	// зануляем ссылки на следующий и предыдущий объекты списка
		head->prev = NULL;*/
		head->next = head;
		head->prev = head;
		curr = tail = head;
	}
	else   // список не пуст - добавляем в конец элемент
	{
		curr = tail;	// переставляем текущий элемент на хвост списка
		tail->next = new Node;	// создаем за хвостом новый элемент
		tail = tail->next;		// перемещаем туда хвост.
		tail->prev = curr;		// связываем новый хвост с предыдущим
		tail->next = head;		// зацикливаем хвост на голову
		tail->ptr = &obj;		// сохраняем в элементе указатель на объект
		curr = tail;
		head->prev = tail;
	}
}

Base * Container::TakeElement()
{
	if (!curr)	// если пытаемся забрать несуществующий элемент
	{
		std::cout << "\n Error: wrong try to get a NULL element.\n";
		return NULL;
	}

	Base * temp = curr->ptr;	// сохраняем необходимый элемент
	if (curr->next != curr)	// если в списке остался не один элемент
	{
		curr = curr->prev;
		curr->next = (curr->next)->next;
		if (head == NULL) head = curr->next;	// если забрали головной элемент
		if (tail == NULL) tail = curr;	// если забрали хвостовой элемент
	}
	else   // если в списке остался один элемент
	{
		curr->ptr = NULL;
		curr->next = NULL;
		curr->prev = NULL;
		head = tail = curr = NULL;
	}; 
	return temp;
}

Base * Container::GetElementPtr()
{
	if (!curr)	// если пытаемся получить ссылку на несуществующий элемент
	{
		std::cout << "\n Error: wrong try to get a NULL element.\n";
		return NULL;
	}
	else return curr->ptr;
}

void Container::ShowCurrElement(HDC hDC, HPEN hPen)
{
	if (!curr) { std::cout << "\n Error: wrong try to show NULL element.\n";}
	else
		(curr->ptr)->Draw(hDC, hPen);
}

void Container::MoveItteratorForward()	// перемещает текущий элемент на следующий в списке
{
	if (!curr->next || !curr) { std::cout << "\n Error: wrong try to move at NULL.\n"; }
	else curr = curr->next;
}

void Container::MoveItteratorBackward()	// перемещает текущий элемент на предыдущий в списке
{
	if (!curr->prev || !curr) { std::cout << "\n Error: wrong try to move at NULL.\n"; }
	else curr = curr->next;
}

