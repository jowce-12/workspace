#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace::std;

bool comp(const string& left, string& right) {
	if (left.size() == right.size()) return left < right;
	return left.size() < right.size();
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	FILE *fp;
	int N;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N;
		
	vector<string> wordlist(N);
	string word;
	for (int i = 0; i < N; i++) {
		cin >> word;
		wordlist[i] = word;
	}

	sort(wordlist.begin(), wordlist.end(), comp);
	//wordlist.erase(unique(wordlist.begin(), wordlist.end()), wordlist.end());

	for (int i = 0; i < N;i++) {
		if(i==0 || wordlist[i-1] != wordlist[i])
			cout << wordlist[i] << '\n';
	}   
}