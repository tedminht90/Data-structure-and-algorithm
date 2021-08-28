#include<iostream>

using namespace std;
#define N 8
//showResult hiển thị ra mảng, 0 là không đặt, 1 là đặt
// sử dụng mảng 2 chiều để lưu bàn cờ được đánh dấu bởi các giá trị 0 và 1
void showResult(int b[][N]) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			cout << b[i][j] << " "; //hiển thị từng phần tử trang cais mảng của mình
		}
		cout << endl;
	}

}
bool isOK(int b[][N], int row, int col) {
	int i, j;
	//Kiểm tra theo đường ngang
	for (i = 0; i < col; i++) { //col là cột hiện thời đang xét
		if (b[row][i] == 1) {
			return false;
		}
	}
	// Kiểm tra theo hướng trái trên
	i = row; j = col;
	while (i >= 0 && j >= 0) {
		if (b[i][j] == 1) { // không đặt được hậu
			return false;
		}
		i--;
		j--;
	}
	// Kiểm tra trái dưới
	i = row; j = col;
	while (i < N && j >= 0) {
		if (b[i][j] == 1) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}
bool setQueen(int b[][N], int col) {
	if (col >= N) {
		return true;
	}
	for (size_t i = 0; i < N; i++) {
		if (isOK(b, i, col)) { // Đặt Queen từng vị trí ô nào đó trên cái cột đang chọn
			b[i][col] = 1;//Nếu đặt được thì đặt Queen = 1
			if (setQueen(b, col + 1)) { // Và tiếp tục đặt Queen ở vị trí kế tiếp
				return true;
			}
			b[i][col] = 0; // Nếu như không đặt được thì ta sẽ reset lại vị trí đã đặt trước đó, để chuyển sang ô khác

		}
	}
	return false;
}

int main() {
	// NQueen backtracking
	int b[N][N]; // Tạo ra bàn cờ N x N ô
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			b[i][j] = 0; // Khởi tạo giá trị của các ô trên bàn cờ = 0
		}
	}
	if (setQueen(b, 0)) { // thiết lập bàn cờ bằng cách đặt Queen vào từng cột xem ở vị trí nào của cột thì nó hợp lệ
		showResult(b);
	}
	else {
		cout << "No solution" << endl;
	}
	return 0;
}