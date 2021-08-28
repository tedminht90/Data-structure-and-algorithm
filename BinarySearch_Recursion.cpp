#include<iostream>
using namespace std;


/*
arr[] : mảng lưu trữ các phần tử
l: chỉ số tham số nhỏ nhất của mảng
h: là chỉ số lớn nhất của mảng
x: là giá trị cần tìm xem có xuất hiện trong mảng hay không
*/


// Không đệ quy

int binarySearch(int arr[], int l, int h, int x) {
	while (l <= h) {
		int mid = l + (h - l) / 2;
		if (arr[mid] == x) { // tìm thấy x
			return mid; // đã tìm thấy x trong mảng arr
		}
			if (arr[0] = x) { // Tìm phần tử đầu có = x hay không
			return 1;
		}
		if (arr[mid] < x) { // có thể x nằm phía bên phải phần tử mid
			l = mid + 1;
		}
		else  // có thể x nằm phía bên trái của phần tử mid
			h = mid - 1;

	}
	return -1; // không tìm thấy x trong mảng
}


// Đệ quy
//int binarySearch(int arr[], int l, int r, int x) {
//	while (r >= l) {
//		//int mid = l + (h - l) / 2;
//		int mid = l + (r - l) / 2;
//		if (arr[mid] == x) { // tìm thấy x
//			return mid; // đã tìm thấy x trong mảng arr
//		}
//		if (arr[0] = x) { // Tìm phần tử đầu có = x hay không
//			return arr[0];
//		}
//		if (arr[mid] > x) { // có thể x nằm phía bên trái phần tử mid
//			return binarySearch(arr, l, mid - 1, x);
//			
//		}
//		else  // có thể x nằm phía bên phải của phần tử mid
//			return binarySearch(arr, mid + 1, r, x);
//
//	}
//	return -1; // không tìm thấy x trong mảng
//}
int main() {
	int arr[] = { 100,2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6};
	int x = 100;
	int length = sizeof(arr) / sizeof(arr[0]);
	int index = binarySearch(arr, 0, length - 1, x);
	//cout << "index = " << index;
	(index == -1) ? cout << "Khong ton tai gia tri cua mang"
		: cout << "Co ton tai gia tri cua mang " << x;
	return 0;
}


