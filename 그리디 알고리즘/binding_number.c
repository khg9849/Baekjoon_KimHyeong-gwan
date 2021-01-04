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

	int N;//������ ����
	int *num_pls;
	int* num_mns;
	int count_pls = 0, count_mns = 0;
	int temp;
	int i;
	int ans = 0;

	scanf("%d", &N);
	MALLOC(num_pls, N * sizeof(int));
	MALLOC(num_mns, N * sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp > 0)
			num_pls[count_pls++] = temp;//��� ���� ����
		else
			num_mns[count_mns++] = temp;//0, ���� ���� ����
	}

	quick_sort(num_mns, 0, count_mns - 1);//�������� ����
	quick_sort_re(num_pls, 0, count_pls - 1);//�������� ����

	if (count_mns % 2 == 0) {//���� ������ ¦����
		for (i = 0; i < count_mns; i += 2) {
			ans += num_mns[i] * num_mns[i + 1];//���ؼ� ����� �����ֱ�
		}
	}
	else {//Ȧ����
		for (i = 0; i < count_mns-1; i += 2) {
			ans += num_mns[i] * num_mns[i + 1];//���ؼ� ����� �����ְ�
		}
		ans += num_mns[count_mns-1];//������ �ϳ��� �׳� ����
	}

	if (count_pls % 2 == 0) {//��� ������ ¦����
		for (i = 0; i < count_pls; i+=2) {
			if (num_pls[i] == 1 || num_pls[i + 1] == 1) {//1�� �������ʰ� ����
				ans += num_pls[i];
				ans += num_pls[i + 1];
			}
			else {//1�� ������ ���ؼ� ������
				ans += num_pls[i] * num_pls[i + 1];
			}		
		}
	}
	else {//Ȧ����
		for (i = 0; i < count_pls-1; i += 2) {
			if (num_pls[i] == 1 || num_pls[i + 1] == 1) {//1�� �������ʰ� ����
				ans += num_pls[i];
				ans += num_pls[i + 1];
			}
			else//1�� ������ ���ؼ� �����ְ�
				ans += num_pls[i] * num_pls[i + 1];
		}
		ans += num_pls[count_pls - 1];//������ ���� �ϳ� ������
	}

	printf("%d", ans);//���
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