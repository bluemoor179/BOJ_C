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