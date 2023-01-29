#include<stdio.h>

int main(int argc, char** argv) {
    int r, c;
    char map[50][50], input;
    int q1[2500][2], q2[2500][2];
    bool visit[50][50];
    int len1 = 0, len2 = 0, index1 = 0, index2 = 0, temp;
    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            while(1) {
                scanf("%c", &input);
                if(input == '.' || input == '*' || input == 'X' || input == 'D' || input == 'S') {
                    break;
                }
            }
            map[i][j] = input;
            visit[i][j] = 0;
            if(input == 'S') {
                q1[len1][0] = i;
                q1[len1][1] = j;
                visit[i][j] = 1;
                len1++;
            } else if(input == '*') {
                q2[len2][0] = i;
                q2[len2][1] = j;
                len2++;
            }
        }
    }

    int ans = 0;
    while(1) {
        if(len1 == index1) {
            printf("KAKTUS");
            return 0;
        }
        temp = len1;
        for(index1; index1 < temp; index1++) {
            if(map[q1[index1][0]][q1[index1][1]] == '*') {
                continue;
            }
            for(int i = 0; i < 4; i++) {
                int curX = q1[index1][0] + move[i][0];
                int curY = q1[index1][1] + move[i][1];
                if(!visit[curX][curY] && curX >= 0 && curX < r && curY >= 0 && curY < c) { 
                    visit[curX][curY] = 1;
                    if(map[curX][curY] == 'D') {
                        printf("%d", ans + 1);
                        return 0;
                    } else if(map[curX][curY] == '.') {
                        q1[len1][0] = curX;
                        q1[len1][1] = curY;
                        len1++;
                    }
                }
            }
        }
        ans++;
        temp = len2;
        for(index2; index2 < temp; index2++) {
            for(int i = 0; i < 4; i++) {
                int curX = q2[index2][0] + move[i][0];
                int curY = q2[index2][1] + move[i][1];
                if(curX >= 0 && curX < r && curY >= 0 && curY < c) { 
                    if(map[curX][curY] == '.') {
                        q2[len2][0] = curX;
                        q2[len2][1] = curY;
                        map[curX][curY] = '*';
                        len2++;
                    }
                }
            }
        }
    }
    return 0;
}
/*
문제
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다. 

입력
첫째 줄에 50보다 작거나 같은 자연수 R과 C가 주어진다.

다음 R개 줄에는 티떱숲의 지도가 주어지며, 문제에서 설명한 문자만 주어진다. 'D'와 'S'는 하나씩만 주어진다.

출력
첫째 줄에 고슴도치가 비버의 굴로 이동할 수 있는 가장 빠른 시간을 출력한다. 만약, 안전하게 비버의 굴로 이동할 수 없다면, "KAKTUS"를 출력한다.
*/