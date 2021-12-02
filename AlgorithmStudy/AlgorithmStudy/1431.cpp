#include<algorithm>
#include<string>
#include<iostream>
using namespace::std;

#define NUM_LINE 50
#define LEN_LINE 50
string line[NUM_LINE];

bool compare_line(string& left, string& right) {
	if (left.length() < right.length()) return true;
	else if (left.length() > right.length()) return false;

	int i;
	int sum_left = 0, sum_right = 0;
	for (i = 0; i < left.length(); i++) {
		if (left[i] >= '0' && left[i] <= '9')
			sum_left += left[i] - '0';
	}
	for (i = 0; i < right.length(); i++) {
		if (right[i] >= '0' && right[i] <= '9')
			sum_right += right[i] - '0';
	}

	if (sum_left < sum_right) return true;
	else if (sum_left > sum_right) return false;

	if (left < right) return true;
	else return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, i;
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> N;

	for(i = 0; i < N; i++) {
		cin >> line[i];
	}

	sort(line, line +N, compare_line);

	for (i = 0; i < N; i++) {
		cout << line[i] << '\n';
	}
	return 0;
}