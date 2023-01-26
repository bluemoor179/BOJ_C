#include<stdio.h>

int find(int x, int y, int *map, bool* remain) {
    if(x == 8 && y == 8) {
        if(map[x * 9 + y] > 0) {
            return 1;
        }
        for(int i = 1; i <= 9; i++) {
            if(remain[x * 10 + i] && remain[90 + y * 10 + i] && remain[180 + ((x / 3) * 3 + y / 3) * 10 + i]) {
                map[x * 9 + y] = i;
                return 1;
            }
        }
        return 0;
    }
    int nextX = x;
    int nextY = y + 1;
    if(nextY == 9) {
        nextY = 0;
        nextX++;
    }

    if(map[x * 9 + y] > 0) {
        return find(nextX, nextY, map, remain);
    }

    for(int i = 1; i <= 9; i++) {
        if(remain[x * 10 + i] && remain[90 + y * 10 + i] && remain[180 + ((x / 3) * 3 + y / 3) * 10 + i]) {
            map[x * 9 + y] = i;
            remain[x * 10 + i] = 0;
            remain[90 + y * 10 + i] = 0;
            remain[180 + ((x / 3) * 3 + y / 3) * 10 + i]= 0;
            if(find(nextX, nextY, map, remain) == 1) {
                return 1;
            }
            map[x * 9 + y] = 0;
            remain[x * 10 + i] = 1;
            remain[90 + y * 10 + i] = 1;
            remain[180 + ((x / 3) * 3 + y / 3) * 10 + i]= 1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int map[81]; // 9 * 9
    bool remain[270]; // 3 * 9 * 10

    for(int i = 0; i < 9; i++) {
        for(int j = 1; j <= 9; j++) {
            remain[i * 10 + j] = true;
            remain[90 + i * 10 + j] = true;
            remain[180 + i * 10 + j] = true;
        }
    }
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            scanf("%d", &map[i * 9 + j]);
            remain[i * 10 + map[i * 9 + j]] = false;
            remain[90 + j * 10 + map[i * 9 + j]] = false;
            remain[180 + ((i / 3) * 3 + j / 3) * 10 + map[i * 9 + j]] = false;
        }
    }

    find(0, 0, map, remain);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(j != 8) {
                printf("%d ", map[i * 9 + j]);
            } else {
                printf("%d\n", map[i * 9 + j]);
            }
        }
    }
    return 0;
}

/*
문제
스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.



나머지 빈 칸을 채우는 방식은 다음과 같다.

각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.



또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.



이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.



게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

입력
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

출력
모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.

스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

제한
12095번 문제에 있는 소스로 풀 수 있는 입력만 주어진다.
C++14: 80ms
Java: 292ms
PyPy3: 1172ms
*/