#include <iostream>

using namespace std;

int main() {
    string st;
    int top = 0;
    cin >> st;
    for(int i = 0; i < st.size(); i++) {
        if(st[i] == '(')
            top++;
        else {
            if(top == 0) {
                cout << 0 << '\n';
                return 0;
            }
            top--;
        }
    }
    cout << (top == 0 ? 1 : 0) << '\n';
    return 0;
}