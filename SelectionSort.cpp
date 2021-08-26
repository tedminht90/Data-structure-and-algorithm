#include<iostream>

using namespace std;


void swap(int* a, int* b) {
	int x = *a;
	*a = *b;
	*b = x;
}
// Thuật toán sắp xếp chọn độ phức tạp thuật toán là O(n^2)
// Sẽ chia mảng thành 2 phần, 1 phần đã được sắp xếp, 1 phần sẽ là mảng lộn xộn
// chưa được sắp xếp
// Nhiệm vụ: tìm phần từ min của mảng
void selectionSort(int arr[], int n) {
	int min_index = 0;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			// kiểm tra phần tử tại vị trí j nhỏ hơn phần tử 
			// tại vị trí min_index thì gán giá trị j vào min_index
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(arr[i], arr[min_index]);
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6 };
	int length = sizeof(arr) / sizeof(int);
	selectionSort(arr, length);
	output(arr, length);

	return 0;
}
