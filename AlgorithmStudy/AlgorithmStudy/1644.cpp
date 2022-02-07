#include<iostream>
#include<math.h>
using namespace::std;
// 1 <= N <= 4000000
#define MAX 4000001
int numlist[MAX];
int primenum[MAX];
int tos = -1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N;
	cin >> N;

	numlist[0] = numlist[1] = 1;
	for (int num = 2; num <= sqrt(N); num++) { // sieve of eratosthenes
		if (numlist[num] == 0) primenum[++tos] = num;

		for (int j = num; j <= N; j = j + num) {
			numlist[j] = 1;
		}
	}
	for (int num = sqrt(N)+1; num <= N; num++) {
		if (numlist[num] == 0) primenum[++tos] = num;
	}

	long long result = 0;

	/*
	int sum = 0;
	for (int i = 0; i <= tos; i++) {
		sum = 0;
		for (int j = i; j <= tos; j++) {
			sum += primenum[j];

			if (sum == N) {
				result++;
				break;
			}
			else if (sum > N) break;
		}
	}
	*/

	int sum = 0;
	int start = 0, end = 0;

	while (end <= tos+1) {
		if (sum < N) {
			sum += primenum[end++];
		}
		else {
			if (sum == N) result++;
			sum -= primenum[start++];
		}
	}
	cout << result << "\n";

	return 0;
}