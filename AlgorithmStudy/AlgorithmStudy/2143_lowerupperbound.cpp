//https://www.acmicpc.net/problem/2143
#include<iostream>
#include<vector>
#include<algorithm>
using namespace::std;

#define MAX 1001
#define NUMMAX 1000001
long long T;
int N, M;

long long leftarr[MAX];
long long rightarr[MAX];

long long sum = 0;
long long result = 0;

vector<long long> leftSum;
vector<long long> rightSum;
int tos = -1;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	
	cin >> T;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> leftarr[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> rightarr[i];
	}

	for (int i = 0; i < N; i++) {
		sum = 0;
		for (int j = i; j < N; j++) {
			sum += leftarr[j];
			leftSum.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		sum = 0;
		for (int j = i; j < M; j++) {
			sum += rightarr[j];
			rightSum.push_back(sum);
		}
	}

	sort(leftSum.begin(), leftSum.end());
	sort(rightSum.begin(), rightSum.end());
	//quicksort(rightSum, 0, tos );

	for (int i = 0; i < leftSum.size(); i++) {
		sum = leftSum[i];
		long long remainSum = T - sum;
			
		vector<long long>::iterator iterStart = lower_bound(rightSum.begin(), rightSum.end(), remainSum);
		vector<long long>::iterator iterEnd = upper_bound(rightSum.begin(), rightSum.end(), remainSum);
		result += iterEnd - iterStart;
	}

	cout << result << "\n";
	return 0;
}