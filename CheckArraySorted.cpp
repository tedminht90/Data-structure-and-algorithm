#include<iostream>

using namespace std;

int isSorted(int arr[], int length) {
// Kiểm tra mảng có 1 hoặc không có phần tử, các phần tử còn lại đã được kiểm tra
	// đã thỏa mãn điều kiện
	if (length == 1 || length == 0) return 1;
	
	// Kiểm tra nếu phần tử đằng trước nữa lớn phần tử đằng trước -> trả về 0
	if (arr[length - 2] > arr[length - 1]) return 0;

	// Check xem cặp cuối cùng đã được sắp xếp hay chưa
	// Gọi đệ quy
	return isSorted(arr, length - 1);

}

int main() {
	//int arr[] = { 0,1,2,3,4,5,6,7,9,8 };
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int length = sizeof(arr) / sizeof(int);
	int result = isSorted(arr, length);
	
	if (result == 1) {
		cout << "Mang da duoc sap xep";
	}
	else cout << "Chua duoc sap xep";
	
	//cout << result << endl;

	
	return 0;
}