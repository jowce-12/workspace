#include<iostream>
using namespace::std;
long long int savesquare[1000001][2];
long long int square(int N) {
	savesquare[0][0] = 0;
	savesquare[1][0] = 2;
	savesquare[2][0] = 7;
	savesquare[2][1] = 1;

	for (int i = 3; i <= N; i++) {
		savesquare[i][1] = (savesquare[i - 1][1] + savesquare[i - 3][0]) % 1000000007;
		savesquare[i][0] = (2 * savesquare[i - 1][0] + 3 * savesquare[i - 2][0] + 2 * savesquare[i][1]) % 1000000007;
	}

	return savesquare[N][0];
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	cout << square(N) << "\n";
	return 0;
}