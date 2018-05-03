#include "Linked_List.h"



Linked_List::Linked_List()
{
	head = nullptr;
	length = 0;
}

bool Linked_List::insertFirst(int data)
{
	Node * newNode = new Node(data);
	if (newNode == nullptr)
		return false;

	if (head == nullptr) {
		head = newNode;
		length++;
		return true;
	}

	newNode->setNext(head);
	head = newNode;
	length++;
	return true;
}

bool Linked_List::insertLast(int data)
{
	Node * newNode = new Node(data);
	if (newNode == nullptr)
		return false;

	if (head == nullptr) {
		head = newNode;
		length++;
		return true;
	}

	Node * last = head;
	while (last->getNext() != nullptr) {
		last = last->getNext();
	}
	last->setNext(newNode);
	length++;
	return true;
}

bool Linked_List::insertByPos(int data, int index)
{
	if (head == nullptr&&index > 0 || index >length || index<0) {
		return false;
	}
	Node *newNode = new Node(data);
	if (newNode == nullptr)
		return false;

	if (index == 0) {
		newNode->setNext(head);
		head = newNode;
		length++;
		return true;
	}

	Node *prev = head;
	for (int i = 0; i < index-1; i++) {
		if (prev == nullptr) {
			delete newNode;
			return false;
		}
		prev = prev->getNext();
	}
	if(prev->getNext()!=nullptr)
		newNode->setNext(prev->getNext());
	prev->setNext(newNode);
	length++;
	return true;
}

bool Linked_List::removeFirst()
{
	if(head==nullptr)
		return false;
	Node *del = head;
	Node *temp = del->getNext();
	delete del;
	head = temp;
	length--;
	return true;
}

bool Linked_List::removeLast()
{
	if (head == nullptr)
		return false;

	if (head->getNext() == nullptr) {
		delete head;
		head = nullptr;
		length--;
		return true;
	}
	Node * last = head;
	Node *del = head->getNext();
	while(del->getNext() != nullptr) {
		last = del;
		del = del->getNext();
	} 
	last->setNext(nullptr);
	delete del;
	length--;
	return true;
}

bool Linked_List::removeByPos(int index)
{
	if (head == nullptr&&index >= 0 || index >length||index<0) {
		return false;
	}

	if (index == 0) {
		Node *delNode = head;
		head = head->getNext();
		delete delNode;
		length--;
		return true;
	}

	Node *prev = head;

	for (int i = 0; i < index - 1 ; i++) {
		prev = prev->getNext();

		if (prev->getNext() == nullptr)
			return false;
	}

	Node*del = prev->getNext();
	prev->setNext(del->getNext());
	delete del;
	length--;
	return true;
}

bool Linked_List::removeByVal(int data)
{
	if (head == nullptr) {
		return false;
	}

	if (head->getData() == data) {
		Node *delNode = head;
		head = head->getNext();
		delete delNode;
		length--;
		return true;
	}

	Node *prev = head;
	Node*del = prev->getNext();
	while(del->getData()!=data) {
		prev = del;
		del = del->getNext();

		if (del->getNext() == nullptr)
			return false;
	}

	prev->setNext(del->getNext());
	delete del;
	length--;
	return true;
}

void Linked_List::reverseList()
{
	if (head == nullptr || head->getNext() == nullptr)
		return;

	Node* prev = head;
	Node* curr = head->getNext();
	Node* next = nullptr;

	while (curr != nullptr) {
		next = curr->getNext();
		curr->setNext(prev);
		prev = curr;
		curr = next;
	}

	head->setNext(nullptr);
	head = prev;
}


int Linked_List::operator[](int index)
{
	if (head == nullptr&&index > 0 || index > length || index<0) {
		return -9999;
	}
	Node *node = head;
	for (int i = 0; i < index; i++) {
		node = node->getNext();
		if (node == nullptr)
			return -999;
	}

	return node->getData();
}

int Linked_List::getLength()
{
	return length;
}

Linked_List::~Linked_List()
{
	Node *delNode = head;
	while (delNode != nullptr) {
		Node *temp = delNode->getNext();
		delete delNode;
		delNode = temp;
	}
}

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}

Node * Node::getNext()
{
	return next;
}

void Node::setNext(Node *next)
{
	this->next = next;
}

int Node::getData()
{
	return data;
}

void Node::setData(int data)
{
	this->data = data;
}
