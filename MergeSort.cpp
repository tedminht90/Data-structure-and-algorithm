#include<iostream>
#include<string>

using namespace std;

// arr[] -> tham số mảng cần trộn, l là chỉ số phần tử nhỏ nhất trong mảng
// m là chỉ số ở mid, h là chỉ số lớn nhất trong mảng
void merge(int arr[], int l, int m, int h) {
	int i, j, k = l; // biến k làm biến lưu lại các mảnh đã đc sắp xếp
	int n1 = m - l + 1; //độ dài của nửa thứ nhất
	int n2 = h - m;
	/*
		0 ...7: 8 phần tử -> l = 0, h = 7 -> m = 3
		n1 = 3 - 0 + 1 = 4
		n2 = 7 - 3 = 4
	*/
	int* L = new int[n1]; // Mảng L lưu trữ các mảnh bên trái đã sắp xếp
	int* R = new int[n2]; // Mảng R lưu trữ các mảnh bên phải đã sắp xếp
	//int L[n1], R[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + 1 + j];
	}
	// trộn
	//int x = 0; 
	//int y = 0;
	i = 0; j = 0;
	while (i < n1 && j < n2) {
		//Nếu giá trị đầu ở bên trái nhỏ hơn giá trị đầu phía bên phải 
		// thì lấy bền trái L[i++] nếu không
		// trả về phía bên phải R[j++]
		//arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++]; // sắp xếp từ bé đến lớn
		arr[k++] = (L[i] >= R[j]) ? L[i++] : R[j++]; // sắp xếp từ lớn về bé
	}
	// Mảng left chưa được lấy hết các phần tử
	while (i < n1) {
		arr[k++] = L[i++];
	}
	// Mảng right chưa được lấy hết các phần tử
	while (j < n2) {
		arr[k++] = R[j++]; // arr[k] = R[j]; k++; j++;
	}

}


//Thuật toán sắp xếp theo mergesort có 3 tham số
// gồm có 1 mảng arr[], giá trị l chỉ số phần tử nhỏ nhất trong mảng,
// chỉ số lớn nhất của phần tử ở trong mảng
void mergeSort(int arr[], int l, int h) {
	/*
		1. Tìm phần tử middle
		2. Đệ quy nửa trước của mảng
		3. Đệ quy nửa sau của mảng
		4. trộn hai nửa mảng lại thành kết quả gọi đến hàm merge
	*/
	if (l < h) {
		int m = l + (h - l) / 2; //int m = l+(h-l)/ 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);
		merge(arr, l, m, h);
	}
}


void ouput(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6,-9,-99,-999 };
	int length = sizeof(arr) / sizeof(int);
	mergeSort(arr, 0, length - 1);
	ouput(arr, length);
	return 0;
}
