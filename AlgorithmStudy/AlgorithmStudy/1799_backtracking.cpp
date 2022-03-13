#include<iostream>
using namespace::std;

#define MAX 10
int map[MAX+1][MAX+1];
int left_diag[2*MAX];
int right_diag[2*MAX];

int check_map(int N, int y, int x, int count, int color) {
	int result1 = 0;
	int result2 = 0;
	if (x >= N) {
		y = y + 1;
		if (x % 2 == 1) x = 0;
		else x = 1;
	}
	if (y >= N) {
		return count;
	}

	if (map[y][x] && !right_diag[N-1+x-y] && !left_diag[y+x]) {
		right_diag[N - 1 + x - y] = left_diag[y + x] = 1;
		result1 = check_map(N, y, x + 2, count+1, color);
		right_diag[N - 1 + x - y] = left_diag[y + x] = 0;
	}
	result2 = check_map(N, y, x+2, count, color);

	if (result1 >= result2) count = result1;
	else count = result2;

	return count;
}
int main(void) {
	ios::sync_with_stdio(NULL);
	cin.tie(false);
	cout.tie(false);

	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N;
	cin >> N;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	int result = 0;
	result += check_map(N, 0, 0, 0, 0);
	result += check_map(N, 0, 1, 0, 1);

	cout << result;

	return 0;
}