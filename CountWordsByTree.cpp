/*
Ý tưởng:
Xây dựng ra cấu trúc node của cây nhị phân, trong 1 node sẽ có 4 thành phần
- node left
- node right
- dữ liệu kiểu string -> từ muốn đếm xem xuất hiện bao nhiêu lần
- dữ liệu kiểu int -> biến đếm từ hiện thời trong node hiện thời xuất hiện bao nhiêu lần

Thuật toán: Mỗi node mà mình đọc được -> tạo 1 node chứa từ đó, đưa cái node chứa từ vừa đọc
được đưa vào cây nhị phân, so sánh nếu như gặp bất kỳ node nào chứ từ đó rồi chỉ việc 
tăng biến đếm tại node chưa từ đó lên. Trong trường hợp mà nó chưa xuất hiện, thì chúng 
ta sẽ thêm node mới đó vào trong cây nhị phân




*/

#include <iostream>
#include <fstream> //Thư viện đọc file
#include <iomanip>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	string data;
	int counter; // Giám sát xem data đấy đã xuất hiện trong bao nhiêu node
	
};

//Định nghĩa kiểu mới từ chính node ở trên
typedef Node* Tree;

//Tạo node cho mỗi từ data được
Node* createNode(string data) {
	Node* p = new Node();
	p->left = NULL;
	p->right = NULL;
	p->data = data;// data bên trái là data của node, data bên phải là data của tham số
	p->counter = 1;
	return p;
}

// Khi có 1 node rồi, ta sẽ phải đưa node đấy vào cây nhị phận
//Add node sẽ add vào Tree -> cây sẽ bị thay đổi, do có thể phải thêm node mới nếu data
//đấy chưa tồn tại nên ta phải truyền tham chiếu &t
void addNode( Tree &t, Node* p) {
	if (t != NULL) { // Kiểm tra cây hiện thời 
		if (t->data.compare(p->data) == 0) {
			t->counter++; // Nếu đã có thì tăng biến đếm node trong cây lên
		}
		else if (t->data.compare(p->data) > 0) {//Node hiện thời có data lớn hơn node đưa vào, chèn vào node mới sẽ ở bên trái node hiện thời đang kiểm tra
			addNode(t->left, p);//chèn trái
		}
		else {
			// data của node đưa vào > data của node hiện thời đang kiểm tra, khi đưa vào node đó phải năm bên tay phải
			addNode(t->right, p);//chèn phải
		}
	}
	else t = p; //Truy đến cuối cùng gặp cái node bằng null , thì gán bằng node p
	
}

//Hiển thị node ra trong cây
void showNode(Tree t) {
	if (t != NULL) {// Kết quả hiển thị theo bảng chữ cái
		showNode(t -> left);
		cout << left << setw(12) << t->data << ": " << t->counter << endl;
		showNode(t->right);
	}
}
//Hàm đọc dữ liệu từ file
void readData(Tree &t) {
	ifstream ifs("wordsInput.txt"); // Đọc file ra
	while (!ifs.eof()) { //Khi mà chưa đọc đến cuối file 
		string word;
		ifs >> word;  //chuyền dữ liệu vào biến word, đọc từng từ và gặp dấu cách sẽ ngừng
		Node* p = createNode(word); //Tạo node từ chính biến word
		addNode(t, p); // Thêm cái node p vào trong cây t
	}
	ifs.close();
}

int main() {
	Tree t = NULL;
	readData(t);
	showNode(t);

	return 0;
}
