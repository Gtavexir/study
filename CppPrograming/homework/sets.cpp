#include <iostream>
#include <vector>

using namespace std;

bool set_a[101], set_b[101];

int main() {
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        set_a[m] = true;
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        set_b[m] = true;
    }

    vector<int> a, b, c;
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        if(set_a[i] && set_b[i]) 
            a.push_back(i);
        if(set_a[i] || set_b[i])
            b.push_back(i);
        if(set_a[i] && !set_b[i])
            c.push_back(i);
    }
    
    cout << a.size() << ' ';
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    
    cout << b.size() << ' ';
    for(int i = 0; i < b.size(); i++)
        cout << b[i] << ' ';
    cout << endl;        
        
    cout << c.size() << ' ';
    for(int i = 0; i < c.size(); i++)
        cout << c[i] << ' ';
    cout << endl;

    return 0;
}