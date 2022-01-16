#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace::std;

vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> jewelry_queue;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first < b.first;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int N, K;
	cin >> N;
	cin >> K;

	for (int i = 0; i < N; i++) {
		int weight, value;
		cin >> weight;
		cin >> value;
		jewel.push_back(pair<int, int>(weight,value));
	}

	for (int i = 0; i < K; i++) {
		int C;
		cin >> C;
		bag.push_back(C);
	}

	sort(bag.begin(), bag.end());
	sort(jewel.begin(), jewel.end(), cmp);

	long long int result=0;
	int i = 0;
	for (int j = 0; j < bag.size(); j++) {
		for (; i < jewel.size(); i++) {
			if (bag[j] >= jewel[i].first)
				jewelry_queue.push(jewel[i].second);
			else
				break;
		}
		if (!jewelry_queue.empty()) {
			result += jewelry_queue.top();
			jewelry_queue.pop();
		}
	}

	cout << result << "\n";
	return 0;
}