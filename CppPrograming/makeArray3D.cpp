#include <iostream>

using namespace std;

int ***makeArry3D(int *sz) {
    int ***array = new int **[sz[0]];
    for(int i = 0; i < sz[0]; i++) {
        array[i] = new int *[sz[1]];
        for(int j = 0; j < sz[1]; j++)
            array[i][j] = new int[sz[2]];
    }
    return array;
}
void destroyArray3D(int ***arr, int *sz) {
    for(int i = 0; i < sz[0]; i++) {
        for(int j = 0; j < sz[1]; j++)
            delete[] arr[i][j];
        delete[] arr[i];
    }
    delete[] arr;
    return;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "usage: ./str 1d 2d 3d ... nd \n";
        return -1;
    }

    int i, dim = argc - 1;
    int *size = new int[dim];

    for(i = 1; i < argc; i++)
        size[i -1] = atoi(argv[i]);

    int ***arr3d = NULL;

    arr3d = makeArry3D(size);
    for(int i = 0; i < size[0]; i++)
        for(int j = 0; j < size[1]; j++)
            for(int k = 0; k < size[2]; k++)
                arr3d[i][j][k] = (i * size[1] + j) * size[2] + k;
    
    for(int i = 0; i < size[0]; i++) {
        cout << "i: " << i << endl;
        for(int j = 0; j < size[1]; j++) {
            for(int k = 0; k < size[2]; k++)
                cout << arr3d[i][j][k] << ' ';
            cout << endl;
        }
        cout << endl;
    }
    destroyArray3D(arr3d, size);
    return 0;
}