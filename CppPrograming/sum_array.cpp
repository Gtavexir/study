#include <iostream>
#include <ctime>
using namespace std;

int* init_array(int* a, int n) {
    srand(20203159);
    for(int i = 0; i < n ; i++)
        a[i] = rand() % 101;
    return a;
}

int sum_array1(int* a, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void sum_array2(int* a, int n, int *s) {
    *s = 0;
    for(int i = 0; i < n; i++)
        *s += a[i];
}

void sum_array3(int* a, int n, int &sum) {
    sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        cout << "one command line argument needed\n";
        return -1;
    }
    int n = atoi(argv[1]);
    n = (n < 1) ? 1 : n;
    n = (n > 10) ? 10 : n;

    int *a = new int[n];
    if(!a) {
        cout << "allocation failed.\n";
        return -1;
    }
    int s;

    init_array(a, n);
    for(int i = 0; i < n; i++) cout << a[i] << ' ';

    s = sum_array1(a, n);
    cout << endl << s << endl;

    sum_array2(a, n, &s);
    cout << s << endl;

    sum_array3(a, n, s);
    cout << s << endl;

    return 0;
}