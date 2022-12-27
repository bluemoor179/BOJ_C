#include<stdio.h>
#include<string.h>

int main(int argc, char* args[]) {
    char n[1000001];
    int k, m;
    int count[10];

    scanf("%s %d", n, &k);

    for(int i = 0; i < 10; i++) {
        count[i] = 0;
    }
    m = strlen(n);
    for(int i = 0; i < m; i++) {
        count[n[i] - '0']++;
    }

    int p = 0;
    for(int i = 0; i < k; i++) {
    }

    printf("%s %d %d\n", n, m, k);
    return 0;
}


// 1. compare current n and max n without k.
// 1.1 if current n is max n without k, calc max n with k (if k is even, no change, if k is odd, minimize diff.)