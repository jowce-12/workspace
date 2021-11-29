#include<stdio.h>
#include<string.h>
using namespace::std;

#define NUM_WORD 20000
#define LEN_WORD 50

typedef struct Word {
	char word[LEN_WORD];
	int len;
}Word;
Word heap_word[NUM_WORD+1];
void swap(Word* a, Word* b) {
	Word c;
	c = *a;
	*a = *b;
	*b = c;
}
int check_word_lower(Word* word_left, Word* word_right) {
	if (word_left->len < word_right->len) return 1;
	else if (word_left->len > word_right->len) return 2;

	for (int word_idx = 0; word_idx < LEN_WORD; word_idx++) {
		if (word_left->word[word_idx] == word_right->word[word_idx]) continue;
		else if (word_left->word[word_idx] > word_right->word[word_idx]) {
			return 2;
		}
		else {
			return 1;
		}
	}
	return 0;
}
int main(void) {
	int N;
	FILE *stream;
	freopen_s(&stream, "input.txt", "r", stdin);

	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {

	}

	for (int i = 1; i <= N; i++) { // make heap
		scanf_s("%s", heap_word[i].word, LEN_WORD);
		heap_word[i].len = strlen(heap_word[i].word);

		int cur_idx = i/2;
		int prev_idx = i;
		while (cur_idx > 0 && (check_word_lower(&heap_word[cur_idx],&heap_word[prev_idx])==2 || check_word_lower(&heap_word[cur_idx], &heap_word[prev_idx]) == 0)) {
			if (cur_idx != prev_idx) swap(&heap_word[cur_idx], &heap_word[prev_idx]);

			prev_idx = cur_idx;
			cur_idx = cur_idx / 2;
		}
	}

	int idx_head = 1;
	int idx_cur;
	for (int i = N-1; i >= 0; i--) {
		swap(&heap_word[idx_head], &heap_word[i + 1]);
		if(N < i+2 || check_word_lower(&heap_word[i+1], &heap_word[i+2]) != 0)
			printf("%s\n", heap_word[i+1].word);
		

		idx_cur = idx_head;
		while (idx_cur * 2 <= i) {
			if (idx_cur * 2 + 1 <= i) {
				if (check_word_lower(&heap_word[idx_cur * 2], &heap_word[idx_cur]) == 2 && check_word_lower(&heap_word[idx_cur * 2 + 1],&heap_word[idx_cur]) == 2) {
					break;
				}
				else if (check_word_lower(&heap_word[idx_cur * 2], &heap_word[idx_cur * 2 + 1]) == 2) {
					swap(&heap_word[idx_cur * 2 + 1], &heap_word[idx_cur]);
					idx_cur = idx_cur * 2 + 1;
				}
				else {
					swap(&heap_word[idx_cur * 2], &heap_word[idx_cur]);
					idx_cur = idx_cur * 2;
				}
			}
			else {
				if (check_word_lower(&heap_word[idx_cur * 2],&heap_word[idx_cur]) == 2) {
					break;
				}
				else {
					swap(&heap_word[idx_cur * 2], &heap_word[idx_cur]);
					idx_cur = idx_cur * 2;
				}
			}
		}
	}
	return 0;
}