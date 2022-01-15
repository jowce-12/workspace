#include<iostream>
#include<math.h>
using namespace::std;

typedef struct node {
	int x;
	int y;
}Node;
double total_x;
double total_y;
Node node[21];
double min_val = 382842;

void calc_vector(int N, int check_cnt, int num, int sum_x, int sum_y) {
	if (check_cnt == N / 2) {
		double result = sqrt((total_x - 2 * sum_x) * (total_x - 2 * sum_x) + (total_y - 2 * sum_y) * (total_y - 2 * sum_y));
		if (result < min_val) min_val = result;
		return;
	}
	for (int i = num; i <= N / 2 + check_cnt; i++) {
		calc_vector(N, check_cnt + 1, i + 1, sum_x + node[i].x, sum_y + node[i].y);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.precision(18);
	int T, N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		min_val = 382842;
		total_x = 0;
		total_y = 0;
		for (int j = 0; j < N; j++) {
			cin >> node[j].x;
			cin >> node[j].y;

			total_x += node[j].x;
			total_y += node[j].y;
		}
		calc_vector(N, 1, 1, node[0].x, node[0].y);
		cout << min_val << "\n";
	}
}