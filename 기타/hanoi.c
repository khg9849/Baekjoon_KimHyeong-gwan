#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print_Hanoi(int level, int target, int base);

//target�� ��ǥ�ϴ� ��ȣ(1,2,3), base�� ������ ���� �ִ� ��ȣ(1,2,3)

int main() {

	int N = 0;
	int i = 0;
	int totalNum = 1;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		totalNum *= 2;
	}
	
	totalNum--;
	printf("%d\n", totalNum);
	print_Hanoi(N, 3, 1);
	
	return 0;
}

void print_Hanoi(int level, int target, int base) {
	int temp;//Ÿ�ٰ� ���̽��� �ƴ� �ٸ� �� ��ȣ
	switch (target + base) {
	case 3:
		temp = 3;
		break;
	case 4:
		temp = 2;
		break;
	case 5:
		temp = 1;
	}
	if (level == 1) {//���� ���� �ܰ�� �׳� ���
		printf("%d %d\n", base, target);//���
	}
	else {
		print_Hanoi(level - 1, temp, base);//�ٷ� �Ʒ� �ܰ踦 Ÿ�ٰ� ���̽��� �ƴ� ���� �Űܵ�(3�� Ÿ���̸� 2�� �Űܵ�)
		printf("%d %d\n", base, target);//���� �ܰ踦 Ÿ�ٿ� �ű�(3�� Ÿ���̸� 3����)
		print_Hanoi(level - 1, target, temp);//�ٸ� �� ������ �Űܵ� �ٷ� �Ʒ� �ܰ踦 Ÿ������ �ű�
	}
}
