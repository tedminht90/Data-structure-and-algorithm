//n       sum
//1234		0
//123	    4
//12		3+4=7
//1			3+4+2=9

//Sử dụng đệ quy: Chia nhỏ bài toán. Gọi đệ quy tính tổng các số của n, 
//sau mỗi lần gọi tách phần tử của hàng đơn vị. 
//Khi n< 10 -> return của n, còn các trường hợp khác n % 10 + tongcs(n/10);


#include<stdio.h>

int sumALLDigits(int n) {
	if (n < 10) {
		return n;
	}
	else {
		return n % 10 + sumALLDigits(n / 10);
	}
}

int main() {
	//int result = sumALLDigits(99999999);
	int temp;
	scanf_s("%d", &temp);
	int result = sumALLDigits(temp);
	printf("%d", result);
	return 0;
}

