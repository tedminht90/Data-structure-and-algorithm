#include <iostream>
#include <string>


using namespace std;

struct Node {
	int data;
	Node* next;
};


int main() {

	Node* head = new Node();
	head->data = 1;
	head->next = NULL;

	Node* second = new Node();
	second->next = NULL;
	second->data = 2;

	Node* third = new Node();
	third->next = NULL;
	third->data = 3;

	// Lien ket cac node voi nhau
	head->next = second;
	second->next = third;

	//Truy cap
	//phan tu head
	int data = head->data;
	cout << data << endl;

	Node* p = head;
	while (p != NULL) {
		data = p->data;
		p = p->next; // truy cap tro den phan tu ke tiep
		cout << data << " -> ";
	}

	cout << endl;
	return 0;
}
