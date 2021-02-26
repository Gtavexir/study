#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        bool alpha[26] = {false};
        bool check = false;
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++) {
            if(alpha[str[j] - 'a'] == false)
                alpha[str[j] - 'a'] = true;
            else {
                if(str[j] == str[j - 1])
                    continue;
                else {
                    check = true;
                    break;
                }
            }
        }
        if(!check)
            answer++;
    }
    cout << answer << endl;
}