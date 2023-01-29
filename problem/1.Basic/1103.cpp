#include <stdio.h>

#define MAX 9999

int search(int x, int y, char *board, int *n, int *m, bool *flag, int* res, int count) {
    int current = x * *m + y;
    if(board[current] == 'H') {
        return count;
    }
    if(flag[current]) {
        return MAX;
    }
    if(res[current] > -1) {
        if(res[current] == MAX) {
            return MAX;
        } else {
            return count + res[current];
        }
    }
    flag[current] = true;

    int num = board[current] - '0', ret = count + 1, temp;

    if(x + num < *n) {
        temp = search(x + num, y, board, n, m, flag, res, count + 1);
        if(temp > ret)
            ret = temp;
    }
    if(x - num >= 0) {
        temp = search(x - num, y, board, n, m, flag, res, count + 1);
        if(temp > ret)
            ret = temp;
    }
    if(y + num < *m) {
        temp = search(x, y + num, board, n, m, flag, res, count + 1);
        if(temp > ret)
            ret = temp;
    }
    if(y - num >= 0) {
        temp = search(x, y - num, board, n, m, flag, res, count + 1);
        if(temp > ret)
            ret = temp;
    }

    flag[current] = false;
    res[current] = ret - count;
    if(ret == MAX) {
        res[current] = MAX;
    }
    return ret;
}

int main(int argc, char* args[]) {
    int n, m, index = 0;
    char board[2500];
    bool flag[2500];
    int res[2500];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%c", board + index);
            if(board[index] != 'H' && (board[index] < '0' || board[index] >'9')) {
                scanf("%c", board + index);
            }
            res[index] = -1;
            flag[index++] = false;
        }
    }
    int ans = search(0, 0, board, &n, &m, flag, res, 0);
    if(ans == MAX) {
        ans = -1;
    }
    printf("%d", ans);
    return 0;
}
/*
문제
형택이는 1부터 9까지의 숫자와, 구멍이 있는 직사각형 보드에서 재밌는 게임을 한다.

일단 보드의 가장 왼쪽 위에 동전을 하나 올려놓는다. 그다음에 다음과 같이 동전을 움직인다.

동전이 있는 곳에 쓰여 있는 숫자 X를 본다.
위, 아래, 왼쪽, 오른쪽 방향 중에 한가지를 고른다.
동전을 위에서 고른 방향으로 X만큼 움직인다. 이때, 중간에 있는 구멍은 무시한다.
만약 동전이 구멍에 빠지거나, 보드의 바깥으로 나간다면 게임은 종료된다. 형택이는 이 재밌는 게임을 되도록이면 오래 하고 싶다.

보드의 상태가 주어졌을 때, 형택이가 최대 몇 번 동전을 움직일 수 있는지 구하는 프로그램을 작성하시오.

입력
줄에 보드의 세로 크기 N과 가로 크기 M이 주어진다. 이 값은 모두 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 보드의 상태가 주어진다. 쓰여 있는 숫자는 1부터 9까지의 자연수 또는 H이다. 가장 왼쪽 위칸은 H가 아니다. H는 구멍이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 형택이가 동전을 무한번 움직일 수 있다면 -1을 출력한다.

1
3 7
3942178
1234567
9123532
*/