#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace::std;

priority_queue<pair<long long, long long>, vector<pair<long long, long long>>> jewel;
multiset<long long> bag;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> N >> K;
	for(int i=0;i<N;i++) {
		int weight;
		int value;
		cin >> weight >> value;
		jewel.push({value,weight});
	}

	for (int i = 0; i < K; i++) {
		int C;
		cin >> C;
		bag.insert(C);
	}

	long long result = 0;
	while (!jewel.empty()) {
		long long weight = jewel.top().second;
		long long value = jewel.top().first;
		jewel.pop();

		multiset<long long>::iterator itr = bag.lower_bound(weight);
		if (itr == bag.end()) continue;
		bag.erase(itr);
		result += value;
	}

	cout << result << "\n";

	return 0;
}