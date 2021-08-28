

//Giải thuật quy hoạch động top-down tìm số fibonacci thứ n
/*
						   fibo(4)
					      /		  \
				      fibo(3)	   fibo(2)
				     /     \	   /	  \
				fibo(2)   fibo(1) fibo(1) fibo(2) 
				/   \
			fibo(1) fibo(0)
*/
#include<iostream>
#include<string>

using namespace std;

unsigned long long tmp[200]; // mảng để lưu giá trị các bước tính
//Tính fibonacci theo đệ quy bình thường
//unsigned long long fiboDQ(int n) {
//	if (n <= 1) {
//		return n;
//	}
//	else {
//		return fiboDQ(n - 1) + fiboDQ(n - 2);
//	}
//}
//Tính fibonacci theo quy hoạch động
// Kiểm tra phần tử tại vị trí cần tính = -1 là sẽ tính, còn khác -1 là đã có kết quả
// vậy sẽ lôi kết quả đấy ra
void init() {
	for (int i = 0; i < 200; i++) {
		tmp[i] = -1;
	}
}
unsigned long long fiboQHD(int n) {
	if (tmp[n] == -1) { // chưa được tính
		if (n <= 1) {
			tmp[n] = n;
		}
		else {
			tmp[n] = fiboQHD(n - 1) + fiboQHD(n - 2);
		}
	}
	return tmp[n];
}
	
int main() {
	//cout << fiboDQ(10);
	init();
	cout << fiboQHD(90) << endl;
	return 0;
}