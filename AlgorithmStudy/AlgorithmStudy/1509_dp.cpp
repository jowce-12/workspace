#include<stdio.h>
#include<string.h>
#define MAX 2501
char str[MAX];
bool palindrome[MAX] = {};
int DP[MAX] = { 0 , };

#define min(a,b) a > b ? b : a
int main(void) {
	FILE *fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int len;
	scanf_s("%s", str, MAX);

	len = strlen(str);
	for (int i = 0; i < len; i++) {
		DP[i + 1] = 2147483647;
		for (int j = 0; j <= i; j++) {
			if (str[i] == str[j] && (i - j <= 1 || palindrome[j + 1])) {
				DP[i + 1] = min(DP[i + 1], DP[j] + 1);
				palindrome[j] = true;
			}
			else {
				palindrome[j] = false;
			}
		}
	}
	printf("%d\n", DP[len]);
	return 0;
}