#include<iostream>
using namespace std;

int main(void) {
    int n;
    int arr[24] = {0,};
    arr[1] = 1;

    cin >> n;
    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    printf("%d\n", arr[n]);
    return 0;
}