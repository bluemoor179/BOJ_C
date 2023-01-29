#include <stdio.h>

int find(int level, int k, int last, bool *word, bool *selected, int n) {
    if(level == k) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(; j < 26; j++) {
                if(word[i * 26 + j] == 1 && selected[j] == 0) {
                    break;
                }
            }
            if(j == 26) {
                count++;
            }
        }
        return count;
    }
    int max = 0;
    int ret;
    for(int i = last + 1; i < 26; i++) {
        if(selected[i] == 0) {
            selected[i] = 1;

            ret = find(level + 1, k, i, word, selected, n);
            if(ret > max) {
                max = ret;
            }

            selected[i] = 0;
        }
    }
    return max;
}

int main(int argc, char** argv) {
    int n, k;
    bool word[1300], selected[26];
    char c;
    int temp;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        temp = i * 26;
        for(int j = 0; j < 26; j++) {
            word[temp + j] = 0;
        }
        while(1) {
            scanf("%c", &c);
            if(c >= 'a' && c <= 'z') {
                break;
            }
        }
        while(1) {
            word[temp + c - 'a'] = 1;
            scanf("%c", &c);
            if(c < 'a' || c > 'z') {
                break;
            }

        }
    }
    int ans = 0;
    if(k >= 5) {
        for(int i = 0; i < 26; i++) {
            selected[i] = 0;
        }
        selected['a' - 'a'] = 1;
        selected['n' - 'a'] = 1;
        selected['t' - 'a'] = 1;
        selected['c' - 'a'] = 1;
        selected['i' - 'a'] = 1;

        ans = find(5, k, 0, word, selected, n);
    }
    printf("%d", ans);
    return 0;   
}

/*
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB (하단 참고)	38355	10458	6160	25.106%
문제
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

출력
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.
*/