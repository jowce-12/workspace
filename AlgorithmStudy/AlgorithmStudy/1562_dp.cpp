#include<iostream>
using namespace::std;

#define MAX 101
long long DP[10][MAX][1024];
int N;

long long max(long long a, long long b) {
	return a >= b ? a : b;
}
long long calcIncNum(int num, int num_cnt, int check_num) {
	long long cnt=0;
	
	if (num_cnt == N) {
		//if (check_num == 1023)
		if (check_num == 3)
			return 1;
		else
			return 0;
	}
	if (DP[num][N - num_cnt][check_num] > 0) return DP[num][N - num_cnt][check_num];

	if (num + 1 < 10) {
		//int new_check_num = check_num | (1 << (num + 1));
		cnt += calcIncNum(num + 1, num_cnt + 1, check_num | (num + 1 == 9 ? 2 : 0));
		cnt %= 1000000000;
	}
	if (num - 1 >= 0) {
		//int new_check_num = check_num | (1 << (num - 1));
		cnt += calcIncNum(num - 1, num_cnt + 1, check_num | (num - 1 == 0 ? 1 : 0));
		cnt %= 1000000000;
	}

	return (DP[num][N - num_cnt][check_num] = cnt);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N;
	
	
	long long result = 0;
	//int check_num = 0;

	for (int i = 1; i <= 9; i++) {
		//check_num = 1 << i;
		result += calcIncNum(i, 1, i==9 ? 2 : 0);
		result %= 1000000000;
	}

	cout << result << "\n";

	
	/*
	long long total_result = 0;
	long long result = 0;
	int check_num = 0;

	for (int j = 1; j <= 40; j++) {
		N = j;
		result = 0;
		for (int i = 1; i <= 9; i++) {
			check_num = 1 << i;
			result += calcIncNum(i, 1, check_num);
		}
		total_result += result;
	}

	cout << total_result << "\n";
	//126461847755
	*/
	return 0;
}