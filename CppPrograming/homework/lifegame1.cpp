#include <iostream>

using namespace std;

int main() {
    int cell[51], tmp[51] = {}, n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> cell[i];
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            int neighbor;
            if(j == 0) 
                neighbor = cell[j + 1];
            else if(j == n - 1)
                neighbor = cell[j - 1];
            else
                neighbor = cell[j - 1] + cell[j + 1];
            
            if(neighbor < 3)
                tmp[j] = cell[j] == 0 ? cell[j] : cell[j] - 1;
            else if(neighbor > 7)
                tmp[j] = cell[j] == 0 ? cell[j] : cell[j] - 1;
            else if(neighbor == 3)
                tmp[j] = cell[j];
            else
                tmp[j] = cell[j] > 8 ? cell[j] : cell[j] + 1;
        }
        for(int j = 0; j < n; j++)
            cell[j] = tmp[j];
    }

    for(int i = 0; i < n; i++)
        cout << cell[i] << ' ';

    return 0;
}