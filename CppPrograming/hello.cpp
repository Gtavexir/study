/*My first program */
#include <iostream>

using namespace std;
char a[10] = "012345678";

int main() {
    cout << "Hello World!\n"; // write output on screen
    char *p[10];
    for(int i = 0; i < 10; i++) p[i] = &a[i];

    cout << *(p + 1) << endl;
    cout << *(p[1]) << endl;
    
    return 0;
}