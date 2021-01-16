//2437�� �׸��� ���� "����"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MALLOC(p,s)\
	if(!(p = malloc(s))){\
		exit(1);\
	}

void swap(int *a, int *b);

void quick_sort(int t[], int left, int right);
void quick_sort_re(int t[], int left, int right);


int main() {
	
	int N;
	int* wei;
	int i;
	int sum = 0;
	int temp = 0;
	int key = 1;
	int key2 = -1;
	scanf("%d", &N);
	if (N > 1000 || N < 1)
		exit(1);
	MALLOC(wei, N * sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", &wei[i]);
		if (wei[i] > 1000000) {
			exit(1);
		}
	}

	quick_sort(wei, 0, N - 1);
	if (N == 1) {//�ϳ��ۿ�������
		if (wei[0] == 1)//�߰� 1�̸� 2
			sum = 2;
		else//�߰� 1�̾ƴϸ� 1
			sum = 1;
	}
	else {//�ΰ� �̻��̸� �˰��� ����. �˰����� �޸��� ����
		for (i = 0; i < N; i++) {
			if (sum == 0) {
				sum = wei[i];
			}
			else {
				if (sum != 1 && key2 == -1) {
					sum = 0;
					break;
				}
				else
					key2 = 1;
				if (sum >= wei[i]) {
					sum += wei[i];
				}
				else {
					sum += 1;
					if (sum != wei[i]) {
						key = -1;
						break;
					}
					else {
						sum += wei[i];
						sum--;
					}
				}
			}
		}
		if (key == 1)
			sum++;
	}
	printf("%d", sum);
	


	
	return 0;
}



void swap(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void quick_sort_re(int t[], int left, int right) {

	int Lidx, Ridx;
	int pivot;

	Lidx = left;
	Ridx = right - 1;

	pivot = t[right];

	while (1) {

		while (t[Lidx] >= pivot && Lidx < right) {
			Lidx++;
		}
		while (t[Ridx] < pivot) {
			Ridx--;
		}

		if (Lidx >= Ridx) {
			break;
		}
		swap(&t[Lidx], &t[Ridx]);
	}

	swap(&t[Lidx], &t[right]);

	if (left < (Lidx - 1))
		quick_sort_re(t, left, (Lidx - 1));

	if ((Lidx + 1) < right)
		quick_sort_re(t, (Lidx + 1), right);

}

void quick_sort(int t[], int left, int right) {

	int Lidx, Ridx;
	int pivot;

	Lidx = left;
	Ridx = right - 1;

	pivot = t[right];

	while (1) {

		while (t[Lidx] <= pivot && Lidx < right) {
			Lidx++;
		}
		while (t[Ridx] > pivot) {
			Ridx--;
		}
		
		if (Lidx >= Ridx) {
			break;
		}
		swap(&t[Lidx], &t[Ridx]);
		
	}
	
	swap(&t[Lidx], &t[right]);

	
	if (left < (Lidx - 1))
		quick_sort(t, left, (Lidx - 1));

	if ((Lidx + 1) < right)
		quick_sort(t, (Lidx + 1), right);

}