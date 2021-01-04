#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MALLOC(p,s)\
	if(!(p = malloc(s))){\
		exit(1);\
	}

void swap(int *a, int *b);



int main() {

	int N;//사람의 수
	int* pattern;//각 사람별로 왼쪽에 몇명 서 있는지
	int* turn;//현재 서있는 순서
	int i, j, k;
	int temp;

	scanf("%d", &N);

	MALLOC(pattern, N * sizeof(int));
	MALLOC(turn, N * sizeof(int));


	for (i = 0; i < N; i++) {
		scanf("%d", &pattern[i]);
		turn[i] = i + 1;
	}

	for (i = 1; i <= N; i++) {//1,2,3,4 순서대로
		for (j = 0; j < N; j++) {//현재 순서인 사람 자리 찾기
			if (turn[j] == i) {//찾으면 실행
				while (pattern[i - 1]) {//왼쪽에 있는 사람 수만큼 실행
					for (k = 1; k < N; k++) {//한 칸씩 오른쪽으로 옮겨가며
						if (turn[j + k] > i) {//현재 순서인 사람보다 키가 크면
							swap(&turn[j], &turn[j + k]);//자리 바꿈
							j += k;
							break;//자리바꿨으면 종료
						}
					}
					pattern[i - 1]--;
				}
				break;//한 명 순서가 끝났으므로 종료
			}
		}
	}

	for (i = 0; i < N; i++) {//출력
		printf("%d ", turn[i]);
	}


	return 0;
}



void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
