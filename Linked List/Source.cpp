#include <iostream>
#include "Linked_List.h"

using namespace std;

int main(int argc, char* argv[]) {
	Linked_List list;
	int choice;
	do {
		cout << endl;
		cout << "1. InsertFirst" << endl;
		cout << "2. InsertLast" << endl;
		cout << "3. InsertByPos" << endl;
		cout << "4. Display" << endl;
		cout << "5. RemoveFirst" << endl;
		cout << "6. RemoveLast" << endl;
		cout << "7. RemoveByPos" << endl;
		cout << "8. RemoveByVal" << endl;
		cout << "9. ReverseList" << endl;
		cout << "10. Exit" << endl;
		cout << "Enter Your choice::" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int value;
			cout << "Enter value to be inserted::";
			cin >> value;
			if (list.insertFirst(value)) {
				cout << "Value inserted";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 2:
		{
			int value;
			cout << "Enter value to be inserted::";
			cin >> value;
			if (list.insertLast(value)) {
				cout << "Value inserted";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 3:
		{
			int value,pos;
			cout << "Enter value to be inserted::";
			cin >> value;
			cout << "Enter Position";
			cin >> pos;
			if (list.insertByPos(value,pos)) {
				cout << "Value inserted";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 4:
		{
			for (int i = 0; i < list.getLength(); i++) {
				cout << list[i] << " ";
			}
		}
		break;
		case 5:
		{
			if (list.removeFirst() ) {
				cout << "Value Removed";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 6:
		{
			if (list.removeLast()) {
				cout << "Value Removed";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 7:
		{
			int pos;
			cout << "Enter Position";
			cin >> pos;
			if (list.removeByPos(pos)) {
				cout << "Value Removed";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 8:
		{
			int value;
			cout << "Enter value to be inserted::";
			cin >> value;
			if (list.removeByVal(value)) {
				cout << "Value Removed";
			}
			else {
				cout << "Something wrong happend";
			}
		}
		break;
		case 9:
		{
			list.reverseList();
			cout << "List Reversed";
			
		}
		break;
		case 10:
		break;
		default:
			cout << "Enter Correct Choice!!";
			break;
		}
	}while (choice < 10);
	return 0;
}