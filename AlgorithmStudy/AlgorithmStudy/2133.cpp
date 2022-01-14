#include<iostream>
using namespace::std;
int savesquare[1001];
int fillsquare(int N) {
	if (N == 0) return 1;
	if (N == 1) return 0;
	if (N == 2) return 3;
	if (N == 3) return 0;
	if (savesquare[N] != 0) return savesquare[N];

	savesquare[N] = 3 * fillsquare(N-2);
	for (int i = 3; i <= N; i++) {
		if (i % 2 == 0)
			savesquare[N] += 2 * fillsquare(N - i);
	}
	return savesquare[N];
}
int main(void) {
	int N;
	cin >> N;
	cout << fillsquare(N) << endl;
	return 0;
}