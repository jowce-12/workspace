#include<iostream>
using namespace::std;

#define MAX 100001
int N, S;
int num[MAX];
int minLength = MAX;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FILE *fp;

	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int start = 0, end = 0;
	int sum = 0;
	if (S == 0) minLength = 0;

	sum = num[start];
	while (start <= end && end < N) {
		if (sum < S) {
			end++;
			sum += num[end];
		}
		else if (sum == S) {
			if (minLength > end - start + 1) {
				minLength = end - start + 1;
			}
			end++;
			sum += num[end];
		}
		else {
			if (minLength > end - start + 1) {
				minLength = end - start + 1;
			}
			sum -= num[start];
			start++;
		}
	}

	if (minLength == MAX) minLength = 0;
	cout << minLength << "\n";
	return 0;
}