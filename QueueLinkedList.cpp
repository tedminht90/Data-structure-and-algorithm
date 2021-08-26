#include<iostream>
#include<string>

using namespace std;


struct Node
{
	int data;
	Node* next;
};

typedef struct Node* queue;

//Kiểm tra queue co rỗng hay không
bool isEmpty(queue q) {
	return q = NULL;
}

//tạo một node bất kỳ
Node* createNode(int data) {
	Node* p = new Node();
	if (p == NULL) {
		return p;
	}
	p->next = NULL;
	p->data = data;
}

void enQueue(queue& q, int data) {
	Node* p = createNode(data);
	if (q == NULL) {
		q = p;
	}
	else {
		Node* ptr = q;
		while (ptr != NULL && ptr->next != NULL) { //tìm node cuối cùng của ds liên kết 
			ptr = ptr->next;
		}
		//ptr chính là node cuối cùng trong danh sách liên kết
		ptr->next = p;
	}
}

//lấy phần tử ở trên đầu nhưng không xóa
int peek(queue q) {
	if (!isEmpty(q)) {
		return q->data;
	}
	else {
		return 0;
	}
}
//lấy phần tử ở trên đầu và xóa
int deQueue(queue& q) {
	if (!isEmpty(q)) {
		int data = q->data;
		Node* p = q;//lấy phần tử ở đầu queue
		q = q->next;//phải gán phần từ tiếp 
		delete(p);// giải phóng bộ nhớ
		return data;
	}
	else {
		return 0;
	}
}

int main() {
	queue q = NULL;
	enQueue(q, 10);
	enQueue(q, 100);
	enQueue(q, 1000);
	enQueue(q, 10000);
	enQueue(q, 100000);
	enQueue(q, 999999);
	cout << "QUEUE rong? " << isEmpty(q) << endl;


	cout << "First Element Of QUEUE ? " << peek(q) << endl;

	while (!isEmpty(q)) {
		int data = peek(q);
		deQueue(q);
		cout << " " << data << endl;
	}
	cout << "QUEUE rong ? " << isEmpty(q) << endl;

	return 0;
}



