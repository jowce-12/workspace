#include<iostream>
using namespace::std;
#define MAX 3001
typedef struct Line {
	long startx;
	long starty;
	long endx;
	long endy;
	int group = -1;
}Line;

Line line[MAX];
int height[MAX];

int resultGroup[MAX];
int resultGroupNum[MAX];

int min(int a, int b) {
	if (a >= b) return b;
	else return a;
}
int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}
bool is_cross(Line line1, Line line2) {
	if (max(line1.startx, line1.endx) < min(line2.startx,line2.endx)) return false;
	if (min(line1.startx, line1.endx) > max(line2.startx, line2.endx)) return false;
	if (max(line1.starty, line1.endy) < min(line2.starty, line2.endy)) return false;
	if (min(line1.starty, line1.endy) > max(line2.starty, line2.endy)) return false;

	long product1 = (line1.endx - line1.startx) * (line2.starty - line1.starty) - (line1.endy - line1.starty) * (line2.startx - line1.startx);
	long product2 = (line1.endx - line1.startx) * (line2.endy - line1.starty) - (line1.endy - line1.starty) * (line2.endx - line1.startx);
	long product3 = (line2.endx - line2.startx) * (line1.starty - line2.starty) - (line2.endy - line2.starty) * (line1.startx - line2.startx);
	long product4 = (line2.endx - line2.startx) * (line1.endy - line2.starty) - (line2.endy - line2.starty) * (line1.endx - line2.startx);
	
	if (product1 == 0 && product2 == 0 && product3 == 0 && product4 == 0) return true;

	return (product1 * product2 <= 0) && (product3 * product4 <= 0);
}
int find(int cur) {
	if (cur == line[cur].group) return cur;
	else {
		int parent = find(line[cur].group);
		line[cur].group = parent;
		return parent;
	}
}
void unionLine(int line1, int line2) {
	int parentLine1 = find(line1);
	int parentLine2 = find(line2);

	if (parentLine1 == parentLine2) return;

	if (height[parentLine1] < height[parentLine2]) {
		line[parentLine1].group = parentLine2;
	}
	else {
		line[parentLine2].group = parentLine1;

		if (height[parentLine2] == height[parentLine1]) {
			height[parentLine1] ++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> line[i].startx;
		cin >> line[i].starty;
		cin >> line[i].endx;
		cin >> line[i].endy;
		line[i].group = i;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (is_cross(line[i], line[j])) {
				unionLine(i,j);
			}
		}
	}

	int result = 0;
	int resultMax = -1;
	for (int i = 0; i < N; i++) {
		int groupNum = find(i);
		if (groupNum != -1) {
			if (resultGroup[groupNum] == 0) {
				result++;
			}
			resultGroup[groupNum]++;
			if (resultGroup[groupNum] > resultMax) resultMax = resultGroup[groupNum];
		}
	}
	cout << result << endl;
	cout << resultMax << endl;
	return 0;
}