#include<iostream>
using namespace std;
int main()
{
    int K, T;
    cin >> K >> T;
    int A[T];
    for (int i = 0; i < T; i++) {
        cin >> A[i];
    }
    int pre = 101;
    int result = 0;
    for (int i = 0; i < K; i++) {
        int max = 0;
        int cur = pre;
        for (int j = 0; j < T; j++) {
            if (A[j] > max && pre != j) {
                max = A[j];
                cur = j;
            }
        }
        if (pre == cur) {
            result++;
        }
        A[cur]--;
        pre = cur;
    }

    cout << result << endl;
    return 0;
}