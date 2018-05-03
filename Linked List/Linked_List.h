class Node {
private:
	int data;
	Node* next;
public:
	Node(int);
	Node* getNext();
	void setNext(Node*);
	int getData();
	void setData(int);
};
class Linked_List
{
	Node *head;
	int length;
public:
	Linked_List();
	bool insertFirst(int);
	bool insertLast(int);
	bool insertByPos(int, int);
	bool removeFirst();
	bool removeLast();
	bool removeByPos(int);
	bool removeByVal(int);
	void reverseList();
	int operator[](int);
	int getLength();
	~Linked_List();
};

