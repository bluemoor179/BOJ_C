#include <stdio.h>

int main(int argc, char* args[]) {
    int n, m;
    int arr[10000];
    int count = 0, sum = 0, front = 0;
    scanf("%d %d", &n, &m);
    
    scanf("%d", arr);
    sum = arr[0];
    if(m == sum) {
        count++;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d", arr + i);
        sum += arr[i];
        if(m == sum) {
            count++;
        } else {
            while(sum > m) {
                sum -= arr[front++];
            }
            if(m == sum) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
/*
문제
N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터 j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 10,000), M(1 ≤ M ≤ 300,000,000)이 주어진다. 다음 줄에는 A[1], A[2], …, A[N]이 공백으로 분리되어 주어진다. 각각의 A[x]는 30,000을 넘지 않는 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다.
*/