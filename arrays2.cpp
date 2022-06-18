#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n;
    cin >> q;
    // https://stackoverflow.com/questions/1946830/multidimensional-variable-size-array-in-c
    int** ndarray = new int*[n]; // each element is a pointer to an array
    // loop arrays
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        ndarray[i] = new int[k];
        for (int j = 0; j < k; j++) {
            cin >> ndarray[i][j];
        }
    }
    // loop queries
    for (int a = 0; a < q; a++) {
        int i, j;
        cin >> i;
        cin >> j;
        cout << ndarray[i][j] << endl;
    }
    return 0;
}