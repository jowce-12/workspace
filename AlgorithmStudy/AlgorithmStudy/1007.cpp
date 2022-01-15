#include<iostream>
using namespace::std;
typedef struct node {
	int x;
	int y;
}Node;

Node node[21];

double total_x;
double total_y;
double min_val = 382842;
bool checkVector(int num, int check_cnt, int N, double sum_x, double sum_y) {
	if (check_cnt == N / 2) {
		double sum = sqrt((total_x - 2*sum_x) * (total_x - 2*sum_x) + (total_y - 2*sum_y) * (total_y - 2*sum_y));
		if (sum < min_val) min_val = sum;
		return true;
	}
	else if ((N - num -1) < N/2 - check_cnt) return false;
	
	for (int i = num; i < N; i++) {
		if (!checkVector(i + 1, check_cnt+1, N, sum_x + node[i].x, sum_y + node[i].y)) {
			break;
		}
	}

	return true;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int T,N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		total_x = 0;
		total_y = 0;
		min_val = 382842;
		for (int j = 0; j < N; j++) {
			cin >> node[j].x;
			cin >> node[j].y;

			total_x += node[j].x;
			total_y += node[j].y;
		}

		checkVector(0, 0, N, 0, 0);
		cout.precision(18);
		cout << min_val << endl;
	}

	return 0;
}