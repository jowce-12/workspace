//https://www.acmicpc.net/problem/2098
#include<iostream>
using namespace::std;

#define MAX 16000001
#define MAXN 17
#define MAXHISTORY 65537
int N;
int visitedMax;

int weight[MAXN][MAXN];
int DP[MAXN][MAXHISTORY];

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int traverse(int now, int visitedHistory) {
	if (DP[now][visitedHistory] > 0) return DP[now][visitedHistory];
	if (visitedHistory == visitedMax) {
		if (weight[now][0] > 0) {
			return weight[now][0];
		}
		else {
			return MAX;
		}
	}

	int SumOfWeight = MAX;

	for (int i = 0, bit = 1; i < N; i++, bit = bit << 1) {
		if (!(visitedHistory & (bit)) && weight[now][i] > 0) {
			SumOfWeight = min(weight[now][i] + traverse(i, (visitedHistory | (bit))), SumOfWeight);
		}
	}
	return (DP[now][visitedHistory] = SumOfWeight);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> weight[i][j];
		}
	}

	visitedMax = (1 << N) -1;
		
	cout << traverse(0, 1) << "\n";

	return 0;
}