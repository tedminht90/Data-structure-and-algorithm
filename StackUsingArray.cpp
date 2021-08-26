#include<iostream>
using namespace std;

int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty() { //Kiem tra stack co rong hay khong
	return (current_size == -1);
}

bool isFull() {//Kiem tra stack co day hay chua
	return (current_size == MAX_SIZE);
}

void push(int data) { //Them du lieu vao trong stack
	if (!isFull()) {
		current_size++;
		stack[current_size] = data;
	}
	else {
		cout << "Stack full!" << endl;
	}
}

int top() { // lay phan tu top nhung khong xoa stack
	if (!isEmpty()) {
		int data = stack[current_size];
		//current_size--;
		return data;
	}
	else {
		cout << "Stack is empty!" << endl;
	}
}
int pop() {
	if (!isEmpty()) { // lay phan tu top va xoa khoi stack
		int data = stack[current_size];
		current_size--;
		return data;
	}
	else {
		cout << "Stack is empty!" << endl;
	}
}

int main() {
	push(100);
	push(-255);
	push(-100);
	push(-50);
	push(-25);
	cout << "TOP: " << top() << endl;
	pop();
	cout << "TOP: " << top() << endl;
	//pop();
	while (!isEmpty()) {
		int data = pop();
		cout << data << " <-- ";
	}
	cout << endl;
	return 0;
}
