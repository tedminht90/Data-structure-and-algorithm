#include<iostream>

using namespace std;

//Quicksort là thuật toán sắp xếp theo kiểu phân chia.
//Thuật toán hiệu quả dựa trên việc phân chia mảng dữ liệu thành các mảng nhỏ hơn
//Giải thuật chia mảng thành 2 phần bằng nhau bằng cách so sánh phần từ của mảng với 
//một phần tử gọi là phần tử chốt -> 1 mảng gồm các phần tử nhỏ hơn hoặc bằng chốt và
//1 mảng gồm các phần tử lớn hơn chốt. (Phần tử chốt thường được chuyển về vị trí đúng của mảng)
//Quá trình này diễn ra cho đến khi độ dài của các mảng con đều bằng 1.
void swap(int* a, int* b) {
	int x = *a;
	*a = *b;
	*b = x;
}

//Hàm này sẽ nhận phần tử cuối cùng của mảng làm chốt (pivot), đặt phần tử chốt
// vào đúng vị trí của nó trong mảng đã sắp xếp . Đặt tất cả các phần tử nhỏ hơn
// phần tử chốt(pivot) ở bên trái và các phần tử lớn hơn ở bên phải của chốt (pivot). 
// Gọi đệ quy đến hàm quickSort để sắp xếp tiếp 2 mảng đấy.
int partion(int arr[], int low, int high) {
	int pivot = arr[high]; // gán chốt
	int i = (low - 1);
	// chỉ mục của phần từ nhỏ hơn và cho biết vị trí đúng của chốt cho đến lúc này
	for (int j = low; j <= high - 1; j++) {
		// Nếu phần tử hiện tại nhỏ hơn chôt(pivot)
		if (arr[j] < pivot) {
			//cout << arr[j] << " ";
			i++; // tăng vị trí của phần tử nhỏ hơn lên 1
			swap(&arr[i], &arr[j]);

		}
	}
	//Tìm được vị trí chính xác của phần tử chốt (pivot)
	swap(&arr[i + 1], &arr[high]);

	return (i + 1); // tìm kiếm chính xác được vị tri của chốt phân ra làm 2 nửa low và high
}


//Chức năng chính thực hiện QuickSort
//arr [] -> mảng được sắp xếp
//low: chỉ số bắt đầu, high: chỉ số kết thúc
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		//pi là chỉ mục phân vùng, arr[p] bây giờ là ở đúng vị trí 
		int pi = partion(arr, low, high);
		//Sắp xếp riêng biệt các phần từ ở phân vùng trước và phân vùng sau
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	//int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6 };
	int arr[] = { 10,80,30,90,40,50,70 };
	int length = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, length - 1);
	cout << " \n Sorted array: \n";
	output(arr, length);
	return 0;
}