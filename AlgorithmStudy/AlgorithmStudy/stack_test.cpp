#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace::std;

vector<int> nod[8];
int number = 7;
int c[7];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	c[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < nod[x].size(); i++) {
			int y = nod[x][i];
			if (!c[y]) {
				q.push(y);
				c[y] = true;
			}
		}
	}
}
int main(void) {

	nod[1].push_back(2);
	nod[2].push_back(1);

	nod[1].push_back(3);
	nod[3].push_back(1);

	nod[2].push_back(3);
	nod[3].push_back(2);

	nod[2].push_back(4);
	nod[4].push_back(2);

	nod[2].push_back(5);
	nod[5].push_back(2);

	nod[3].push_back(6);
	nod[6].push_back(3);

	nod[3].push_back(7);
	nod[7].push_back(3);

	nod[4].push_back(5);
	nod[5].push_back(4);

	nod[6].push_back(7);
	nod[7].push_back(6);

	bfs(1);
	return 0;
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		
		for (int i = 0; i < nod[x].size(); i++) {
			if(!nod[x][i]) {
				q.push(nod[x][i]);
				c[nod[x][i]] = true;
			}
		}
	}	
}