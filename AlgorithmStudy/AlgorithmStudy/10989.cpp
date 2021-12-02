#include<iostream>
#include<algorithm>
using namespace::std;

#define MAX_NUM 10001
int list_num[MAX_NUM];
int str_num[6];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N, num, i, cnt_recur, tempi, k, len;
	cin >> N;

	for (i = 0; i < N; i++) {
		cin >> num;
		list_num[num]++;
	}

	for (i = 1; i < MAX_NUM; i++) {
		if (list_num[i] == 0) continue;

		k = 0;
		tempi = i;
		while (tempi > 0) {
			tempi = tempi / 10;
			k++;
		}
		len = k;
		str_num[k] = '\n';
		//str_num[k+1] = '\n';
		tempi = i;
		while (tempi>0) {
			str_num[k-1] = '0' + tempi % 10;
			tempi = tempi / 10;
			k--;
		}
		
		for (cnt_recur = list_num[i]; cnt_recur > 0; cnt_recur--) {
			fwrite(str_num, sizeof(str_num), 1, stdout);
		}
	}

	return 0;
}