#include<iostream>

using namespace std;


struct Node {
	int data;
	Node* next;
};

typedef struct Node* stack;

bool isEmpty(stack s) {
	return (s == NULL);
}

Node* createNode(int data) {
	Node* p = new Node();
	if (p == NULL) {
		return NULL;
	}
	p->data = data;
	p->next = NULL;
	return p;
}


void push(stack& s, int data) {
	Node* ptr = createNode(data); //tao node moi co ten bien la ptr
	if (isEmpty(s)) {
		s = ptr;
	}
	else {
		ptr->next = s;
		s = ptr;
	}
}

int top(stack s) {
	if (!isEmpty(s)) {
		return s->data;
	}
	else {
		cout << "Stack is empty" << endl;
	}
}

int pop(stack& s) { // dữ liệu chỗ nào thay đổi thì cần tham chiếu
	if (!isEmpty(s)) {
		int data = s->data; //lấy giá trị của note hiện thời
		Node* x = s; // gán giá trị node đấy cho x
		s = s->next; // node head sẽ phải là node tiếp theo nốt hiện thời
		delete(x); // giải phong bộ nhớ lưu node x
		return data;
	}
	else {
		cout << "Stack is empty" << endl;
	}
}



int main() {
	stack s;
	push(s, 100);
	push(s, -99);
	push(s, 35);
	push(s, 26);

	cout << "TOP: " << top(s) << endl;
	pop(s); //xoa mot ptu tren top stack

	while (!isEmpty(s)) {
		int data = top(s);
		pop(s);
		cout << data << " <-- ";
	}
	cout << endl;
	return 0;
}
