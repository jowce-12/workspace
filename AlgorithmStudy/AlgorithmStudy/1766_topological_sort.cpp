#include<iostream>
#include<queue>

using namespace::std;

#define MAX 32001
struct cmp {
	bool operator() (int a, int b) {
		if (a > b) return true;
		else return false;
	}
};
vector<int> num_queue[MAX];
priority_queue<int, vector<int>, cmp> start_queue;
int input_cnt[MAX];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int left, right;
		cin >> left >> right;
		num_queue[left].push_back(right);

		input_cnt[right]++;
	}
	// topological sort
	for (int i = 1; i <= N; i++) {
		if (input_cnt[i] == 0) {
			start_queue.push(i);
		}
	}

	while (!start_queue.empty()) {
		int cur = start_queue.top();
		start_queue.pop();

		for (int i = 0; i < num_queue[cur].size(); i++) {
			int top = num_queue[cur][i];

			input_cnt[top]--;
			if (input_cnt[top] == 0) {
				start_queue.push(top);
			}			
		}
		cout << cur << " ";
	}
	
	return 0;
}