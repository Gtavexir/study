#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int arr[3] = {0};;
    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    
    sort(arr, arr+3);

    if(arr[2] >= arr[0] + arr[1])
        cout << 0 << endl;
    else if(arr[0] == arr[1] && arr[1] == arr[2])
        cout << 1 << endl;
    else if(arr[2] * arr[2] == arr[1] * arr[1] + arr[0] * arr[0])
        cout << 2 << endl;
    else if(arr[1] == arr[0])
        cout << 3 << endl;
    else
        cout << 4 << endl;
    return 0;
}