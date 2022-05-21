//https://www.acmicpc.net/problem/1987
#include<stdio.h>

#define MAX 21
char map[MAX][MAX];
int DP[MAX][MAX];

int R, C, resultMoveCnt = 0;

void traverse(int y, int x, int moveCnt, int alphabetHistory) {
	alphabetHistory |= (1 << map[y][x]);
	if (DP[y][x] == alphabetHistory) return;

	if (moveCnt > resultMoveCnt) {
		resultMoveCnt = moveCnt;
	}

	DP[y][x] = alphabetHistory;

	if (x + 1 < C && !(alphabetHistory & (1 << map[y][x+1]))) {
		traverse(y, x + 1, moveCnt + 1, alphabetHistory);
	}
	if (y + 1 < R && !(alphabetHistory & (1 << map[y + 1][x]))) {
		traverse(y + 1, x, moveCnt + 1, alphabetHistory);
	}
	if (y - 1 >= 0 && !(alphabetHistory & (1 << map[y - 1][x]))) {
		traverse(y - 1, x, moveCnt + 1, alphabetHistory);
	}
	if (x - 1 >= 0 && !(alphabetHistory & (1 << map[y][x - 1]))) {
		traverse(y, x - 1, moveCnt + 1, alphabetHistory);
	}
}
int main(void) {
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	scanf("%d %d",&R, &C);

	for (int row = 0; row < R; row++) {
		scanf("%s", &map[row][0]);
	}

	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			map[row][col] -= 'A';
		}
	}

	traverse(0,0,1,0);

	printf("%d\n", resultMoveCnt);

	return 0;
}