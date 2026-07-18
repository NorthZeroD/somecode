// https://zh.wikipedia.org/wiki/%E5%8D%A1%E5%B8%83%E5%88%97%E5%85%8B%E5%B8%B8%E6%95%B8
// https://www.bbc.com/zhongwen/simp/science-50601155

#include <stdio.h>

void sort4asc(int arr[4]) {
    int t;
    if (arr[0] > arr[1]) { t = arr[0]; arr[0] = arr[1]; arr[1] = t; }
    if (arr[2] > arr[3]) { t = arr[2]; arr[2] = arr[3]; arr[3] = t; }
    if (arr[0] > arr[2]) { t = arr[0]; arr[0] = arr[2]; arr[2] = t; }
    if (arr[1] > arr[3]) { t = arr[1]; arr[1] = arr[3]; arr[3] = t; }
    if (arr[1] > arr[2]) { t = arr[1]; arr[1] = arr[2]; arr[2] = t; }
}

void sort4desc(int arr[4]) {
    int t;
    if (arr[0] < arr[1]) { t = arr[0]; arr[0] = arr[1]; arr[1] = t; }
    if (arr[2] < arr[3]) { t = arr[2]; arr[2] = arr[3]; arr[3] = t; }
    if (arr[0] < arr[2]) { t = arr[0]; arr[0] = arr[2]; arr[2] = t; }
    if (arr[1] < arr[3]) { t = arr[1]; arr[1] = arr[3]; arr[3] = t; }
    if (arr[1] < arr[2]) { t = arr[1]; arr[1] = arr[2]; arr[2] = t; }
}

void n2dgt4(int n, int arr[4]) {
    for (int i = 0; i < 4; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
}

int dgt2n4(int arr[4]) {
    return arr[3] + arr[2] * 10 + arr[1] * 100 + arr[0] * 1000;
}

int n2asc(int n) {
    int a[4] = {0};
    n2dgt4(n, a);
    sort4asc(a);
    return dgt2n4(a);
}

int n2desc(int n) {
    int a[4] = {0};
    n2dgt4(n, a);
    sort4desc(a);
    return dgt2n4(a);
}

int main() {
    for (int i = 1000; i <= 9999; ++i) {
        if (i % 1111 == 0) continue;
        printf("%d", i);
        int steps = 0;
        int diff = i;
        while (1) {
            int lastdiff = diff;
            int big = n2desc(diff);
            int sml = n2asc(diff);
            diff = big - sml;
            if (lastdiff == diff) break;
            printf(" => %d", diff);
            ++steps;
        }
        printf(" | %d\n", steps);
    }
    return 0;
}
