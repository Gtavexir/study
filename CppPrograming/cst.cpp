#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) { cout << "one command line argument needed\n"; return -1; }
    int n = strlen(argv[1]);
    char *a = new char[n * 2 + 3];
    if(!a) { cout << "allocation failed.\n"; return -1; }
    a[0] = '!';
    int cnt = 1;
    for(int i = 0; i < n; i++) {
        if(argv[1][i] == 'e') {
            a[cnt++] = 'e';
            a[cnt++] = 'e';
        }
        else
            a[cnt++] = argv[1][i];
    }
    a[cnt++] = '.';
    cout << a << endl;

    string s = "!";
    s += argv[1];
    s += ".";
    int pos = 0;
    while(1) {
        pos = s.find("e", pos);
        if(pos > s.size()) break;
        s.insert(pos, "e");
        pos+=2;
    }
    cout << s << endl;

    return 0;
}