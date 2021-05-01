#include <iostream>

using namespace std;

#define P 2147483648

int main() {
    int n;
    long long answer;
    int cnt = 0;

    cin >> n;
    answer = n;

    while(n != 0) {
        if(n % 2 == 1)
            cnt++;
        n /= 2;
    }

    if(cnt % 2 == 1)
        answer += P;

    cout << answer << endl;

    return 0;
}