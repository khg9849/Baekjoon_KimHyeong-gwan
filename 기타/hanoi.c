#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void print_Hanoi(int level, int target, int base);

//target은 목표하는 번호(1,2,3), base는 원판이 현재 있는 번호(1,2,3)

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
	int temp;//타겟과 베이스가 아닌 다른 한 번호
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
	if (level == 1) {//가장 낮은 단계면 그냥 출력
		printf("%d %d\n", base, target);//출력
	}
	else {
		print_Hanoi(level - 1, temp, base);//바로 아래 단계를 타겟과 베이스가 아닌 곳에 옮겨둠(3이 타겟이면 2에 옮겨둠)
		printf("%d %d\n", base, target);//현재 단계를 타겟에 옮김(3이 타겟이면 3으로)
		print_Hanoi(level - 1, target, temp);//다른 빈 공간에 옮겨둔 바로 아래 단계를 타겟으로 옮김
	}
}
