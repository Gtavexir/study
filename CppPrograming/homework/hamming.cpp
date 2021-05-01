#include <iostream>
#include <set>

using namespace std;

int main() {
    set<long long> hamming;
    hamming.insert(1);
    int k ;
    cin >> k;
    
    set<long long>::iterator iter;
    for(iter = hamming.begin(); iter != hamming.end(); iter++) {
        hamming.insert(*iter * 2);
        hamming.insert(*iter * 3);
        hamming.insert(*iter * 5);
        if(hamming.size() > k * 2)
            break;
    }

    int cnt = 0;
    for(iter = hamming.begin(); iter != hamming.end(); iter++) {
        if(cnt + 1 == k)
            cout << *iter << endl;
        cnt++;
    }

    return 0;
}