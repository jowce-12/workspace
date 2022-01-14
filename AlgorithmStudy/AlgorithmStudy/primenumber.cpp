#include<iostream>
using namespace::std;
bool isPrimeNumberBigON(int x) {  // O(N)
	for (int i = 2; i < x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

bool isPrimeNumberBigOHalf(int x) {
	int end = sqrt(x);
	for (int i = 2; i <= x / end; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int maxnum = 100000;
int num[100001];
void erastothenesPrime(int x) {
	
	for (int i = 2; i <= maxnum; i++) {
		num[i] = i;
	}

	for (int i = 2; i <= maxnum; i++) {
		if (num[i] == 0) continue;
		for (int j = i+i; j <= maxnum; j=j+i) {
			num[j] = 0;
		}
	}

	for (int i = 2; i <= maxnum; i++) {
		if (num[i] != 0)
			cout << i << " ";
	}

}
int main(void) {
	//printf("%d", isPrimeNumberBigOHalf(97));
	erastothenesPrime(97);
	return 0;
}