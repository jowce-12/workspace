#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_HOUSE 100000
#define MAX_PATH 1000000
using namespace::std;

int parentofhouse[MAX_HOUSE];
int checked_cnt = 0;
typedef struct Edge{
	int start;
	int end;
	int weight;
}Edge;

vector<Edge> path;

bool cmp(Edge a, Edge b) {
	if (a.weight < b.weight)
		return true;
	else
		return false;
}

int findParent(int idx) {
	if (parentofhouse[idx] < 0) return idx;
	
	return (parentofhouse[idx] = findParent(parentofhouse[idx]));
}
/*
void unionEdgeGroup(int start, int end) {
	int parent_start = findParent(start);
	int parent_end = findParent(end);

	if (parent_start == parent_end) return;

	if (parentofhouse[parent_start] < parentofhouse[parent_end]) {
		parentofhouse[parent_start] += parentofhouse[parent_end];
		parentofhouse[parent_end] = parent_start;
	}
	else {
		parentofhouse[parent_end] += parentofhouse[parent_start];
		parentofhouse[parent_start] = parent_end;
	}
}*/
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		parentofhouse[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		Edge edge;
		cin >> edge.start >> edge.end >> edge.weight;
		
		path.push_back(edge);
	}

	sort(path.begin(), path.end(), cmp);

	Edge temp_edge;
	long long result = 0;
	for (int i = 0; i < path.size();i++) {
		temp_edge = path[i];

		int parent_start = findParent(temp_edge.start);
		int parent_end = findParent(temp_edge.end);
		if (parent_start == parent_end) continue;

		if (checked_cnt >= N - 2) break;
		result += temp_edge.weight;

		//unionEdgeGroup(temp_edge.start, temp_edge.end);

		if (parentofhouse[parent_start] < parentofhouse[parent_end]) {
			parentofhouse[parent_start] += parentofhouse[parent_end];
			parentofhouse[parent_end] = parent_start;
		}
		else {
			parentofhouse[parent_end] += parentofhouse[parent_start];
			parentofhouse[parent_start] = parent_end;
		}

		checked_cnt++;
	}

	cout << result << "\n";

	return 0;
}