#include<iostream>
#include<string>

using namespace std;

/*In ra giá trị từ 1 đến n không sử dụng vòng lặp  */
void print(int n) {
	if (n < 1) {
		return;
	}
	else {
		print(n - 1);
	}
	cout << n << " ";
	
}

int main() {
	int n;
	cin >> n;
	if (n < 0) {
		n *= -1;
	}
	print(n);

	return 0;
}