#include<stdio.h>

int find(int level, int *n, int* check1, int* check2, int* check3) {
    int res = 0;
    for(int i = 0; i < *n; i++) {
        if(check1[i] && check2[level + i] && check3[level + *n - 1 - i]) {
            if(level == *n - 1) {
                res++;
            } else {
                check1[i] = false;
                check2[level + i] = false;
                check3[level + *n - 1 - i] = false;

                res += find(level + 1, n, check1, check2, check3);

                check1[i] = true;
                check2[level + i] = true;
                check3[level + *n - 1 - i] = true;
            }
        }
    }
    return res;
}

int main(int argc, char** argv) {
    int n;
    int check1[15], check2[29], check3[29];
    scanf("%d", &n);
    for(int i = n -1; i >= 0; i--) {
        check1[i] = true;
    }
    for(int i = 2 * n - 1; i >= 0; i--) {
        check2[i] = check3[i] = true;
    }

    int ans = find(0, &n, check1, check2, check3);

    printf("%d", ans);
    return 0;
}

/*
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/