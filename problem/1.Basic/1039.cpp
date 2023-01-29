#include<stdio.h>
#include<string.h>

#define MAX 10000000

bool res[100000001];

int swap(int level, int current, int k, int m, char* n, int* digit) {
    int next, ret;
    char temp;
    int max = 0;
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            if(i == 0 && n[j] == 0) {
                continue;
            }
            next = current + digit[i] * (n[j] - n[i]) + digit[j] * (n[i] - n[j]);
            if(res[level * MAX + next]) {
                continue;
            } else {
                res[level * MAX + next] = 1;
                if(level + 1 == k) {
                    if(next > max) {
                        max = next;
                    }
                } else {
                    temp = n[j];
                    n[j] = n[i];
                    n[i] = temp;
                    ret = swap(level + 1, next, k, m, n, digit);
                    if(ret > max) {
                        max = ret;
                    }
                    temp = n[j];
                    n[j] = n[i];
                    n[i] = temp;
                }
            }
        }
    }
    return max;
}

int main(int argc, char* args[]) {
    char n[1000001];
    int k, m, current, temp;
    int digit[7];
    for(int i = 0; i < 100000001; i++) {
        res[i] = 0;
    }

    scanf("%s %d", n, &k);
    m = strlen(n);

    int ans = 0;
    if(m == 1 || (m == 2 && n[1] == '0')) {
        ans = -1;
    } else {
        current = 0, temp = 1;
        for(int i = m - 1; i >= 0; i--) {
            n[i] -= '0';
            current += n[i] * temp;
            digit[i] = temp;
            temp *= 10;
        }

        ans = swap(0, current, k, m, n, digit);
    }

    printf("%d", ans);
    return 0;
}


/*
문제
0으로 시작하지 않는 정수 N이 주어진다. 이때, M을 정수 N의 자릿수라고 했을 때, 다음과 같은 연산을 K번 수행한다.

1 ≤ i < j ≤ M인 i와 j를 고른다. 그 다음, i번 위치의 숫자와 j번 위치의 숫자를 바꾼다. 이때, 바꾼 수가 0으로 시작하면 안 된다.

위의 연산을 K번 했을 때, 나올 수 있는 수의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N과 K가 주어진다. N은 1,000,000보다 작거나 같은 자연수이고, K는 10보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제에 주어진 연산을 K번 했을 때, 만들 수 있는 가장 큰 수를 출력한다. 만약 연산을 K번 할 수 없으면 -1을 출력한다.
*/