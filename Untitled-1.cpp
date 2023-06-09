#include <iostream>
#include <string>
using namespace std;


class Node {
public:
int rollNumber;
string name;
Node* next;
};

class CircularLinkedList {
private:
Node* LAST;
Node* jodi;
Node* farkhani;
public:
CircularLinkedList() {
LAST = NULL;
}

void addNode();
bool search(int rollno, Node** farkhani, Node** jodi);
bool listEmpty();
bool delNode();
void traverse();
};

void CircularLinkedList::addNode() 
{ 
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;												
	cout << "\nEnter the name of the student : ";			
	cin >> nm;												

	Node* newNode = new Node(); 	//step 1.a
	newNode->rollNumber = nim;		//step 2.a
	newNode->name = nm;				//step 2.a

	//a. insert a node in the beginning of the list
	if (LAST->next == NULL || nim <= LAST->next->rollNumber) {		//check if data null
		if (LAST->next != NULL && nim == LAST->next->rollNumber) {
			cout << "\nDuplicate number no allowed" << endl;
			return;
		}
		newNode->next = LAST->next;		//Step 3.a
		LAST->next = newNode;			//step 4.a
		return;
	}

	//b. inserting a node between two nodes in the list
	jodi = LAST->next;		//step 1.b
	farkhani = NULL;		//step 2.b
	while(LAST != farkhani && jodi->next->rollNumber < nim )	//3.b
	{
		farkhani = jodi;	//4.b
		jodi = jodi->next;	//5.b
	}
	newNode->next = jodi->next;
	newNode->farkhani = jodi;

	//c. inserting a node in the end of the list
	if(newNode->rollNumber > LAST)
	{
	Node* newNode = new Node(); 	//step 1.c
	newNode->rollNumber = nim;		//step 2.c
	newNode->name = nm;				//step 2.c

	newNode->next = LAST->next;		//step 3.c
	LAST->next = newNode;			//step 4.c
	LAST = newNode;					//step 5.c
	}
}

bool CircularLinkedList::search(int rollno, Node** farkhani, Node** jodi) 
{
*farkhani = LAST->next;
*jodi = LAST->next;
while (*jodi != LAST) 
	{
	if (rollno == (*jodi)->rollNumber) {
	return true;
	}
	*farkhani = *jodi;
	*jodi = (*farkhani)->next;
	}
if (rollno == LAST->rollNumber) 
	{
	return true;
	}
	else 
	{
	return false;
	}
}

bool CircularLinkedList::listEmpty() 
{
return LAST == NULL;
}

bool CircularLinkedList::delNode() 
{ 
	Node* jodi, *farkhani;
	//a. deleting a node in the beginning of the list
	if (LAST->next == NULL || nim <= LAST->next->rollNumber){
	if (search(rollNo, &farkhani, &jodi) == false)
		return false;

	jodi = LAST->next; 	// step 2
	LAST->next = jodi -> next; // step3

	delete jodi;
	return;
	}

	//b. deleting a node in the last of the list
	if (search(rollNo, &farkhani, &jodi) == LAST)
	{
		farkhani = LAST->next;		//step 1.
		jodi = LAST -> next;		//step 2.
		while (farkhani != LAST && search(rollNo, &farkhani, &jodi) == true)	//step 3.
		{
			farkhani = jodi;
			jodi = jodi->next;
		}
	}

	//deleting a node between two nodes in the list.
	jodi = LAST;	//step 1.
	LAST-> farkhani = farkhani		//step 2.
	farkhani -> next = LAST->next;	//step 3.
	farkhani = farkhani -> next;	//step 4.
	
	delete jodi;	//step 5.
	return;

	
}

void CircularLinkedList::traverse() 
{
	if (listEmpty()) 
	{
	cout << "\nList is empty\n";
	}

	else 
	{
	cout << "\nRecords in the list are:\n";
	Node* currentNode = LAST->next;
	while (currentNode != LAST) 
		{
	cout << currentNode->rollNumber << " " << currentNode->name << endl;
	currentNode = currentNode->next;
		}
	cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
CircularLinkedList obj;
while (true) 
		{
		try 
			{
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) 
			{
			case '1': {
			obj.addNode();
			}
			case '2': {
			obj.delNode();
			}
			case '3': {
			obj.traverse();
			break;
			}
			case '4': {
			return 0;
			}
			default: {
			cout << "Invalid option" << endl;
			break;
			}
			}
		}
	catch (exception& e) {
	cout << e.what() << endl;
	}
}
return 0;
}