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

	int N;//����� ��
	int* pattern;//�� ������� ���ʿ� ��� �� �ִ���
	int* turn;//���� ���ִ� ����
	int i, j, k;
	int temp;

	scanf("%d", &N);

	MALLOC(pattern, N * sizeof(int));
	MALLOC(turn, N * sizeof(int));


	for (i = 0; i < N; i++) {
		scanf("%d", &pattern[i]);
		turn[i] = i + 1;
	}

	for (i = 1; i <= N; i++) {//1,2,3,4 �������
		for (j = 0; j < N; j++) {//���� ������ ��� �ڸ� ã��
			if (turn[j] == i) {//ã���� ����
				while (pattern[i - 1]) {//���ʿ� �ִ� ��� ����ŭ ����
					for (k = 1; k < N; k++) {//�� ĭ�� ���������� �Űܰ���
						if (turn[j + k] > i) {//���� ������ ������� Ű�� ũ��
							swap(&turn[j], &turn[j + k]);//�ڸ� �ٲ�
							j += k;
							break;//�ڸ��ٲ����� ����
						}
					}
					pattern[i - 1]--;
				}
				break;//�� �� ������ �������Ƿ� ����
			}
		}
	}

	for (i = 0; i < N; i++) {//���
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
