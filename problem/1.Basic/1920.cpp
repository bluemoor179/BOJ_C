#include<stdio.h>

void sort(int left, int right, int *arr, int *temp) {
    if(left + 1 == right)
        return;
    int mid = (left + right) / 2;
    sort(left, mid, arr, temp);
    sort(mid, right, arr, temp);

    int p1 = left, p2 = mid;
    for(int i = left; i < right; i++) {
        if(p1 == mid) {
            temp[i] = arr[p2++];
        } else if(p2 == right) {
            temp[i] = arr[p1++];
        } else {
            if(arr[p2] > arr[p1]) {
                temp[i] = arr[p2++];
            } else {
                temp[i] = arr[p1++];
            }
        }
    }
    for(int i = left; i < right; i++) {
        arr[i] = temp[i];
    }
}

int find(int left, int right, int target, int *arr) {
    if(left + 1 == right) {
        return arr[left] == target;
    }
    int res = 0;
    int mid = (left + right) / 2;
    if(arr[mid] == target) {
        return 1;
    } else if(arr[mid] < target) {
        res = res | find(left, mid, target, arr);
    } else {
        res = res | find(mid, right, target, arr);
    }
    return res;
}

int main(int agrc, char**argv) {
    int n, m;
    int arr[100000], temp[100000];
    int target, res;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    sort(0, n, arr, temp);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        res = 0;
        scanf("%d", &target);

        res = find(0, n, target, arr);

        if(i != 0) {
            printf("\n");
        }
        printf("%d", res);
    }
    return 0;
}
/*
문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
*/