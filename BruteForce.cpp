#include<string>
#include<iostream>
using namespace std;

int bruteForce(const char* des, const char* x, int n, int m) {
	//n là độ dài của xâu des
	//m là độ dài của xâu x
	int j = 0;
	int count = 0;
	for (int i = 0; i <= (n - m); i++) {
		for (j = 0; j < m && x[j] == des[i + j]; j++);
		if (j >= m) {
			count++;
		}
	}
	return count;
}


int main() {
	const char *des = "ABCCBACBABCABCA"; //xâu nguồn
	const char *x = "BC"; // xâu mẫ kiểm tra có bao nhiêu lần xuất hiện trong xâu mẫu

	int lenDes = strlen(des);
	int lenX = strlen(x);

	int res = bruteForce(des, x, lenDes, lenX);
	cout << "Xau x xuat hien: " << res << "lan tron xau des." << endl;
	return 0;
}