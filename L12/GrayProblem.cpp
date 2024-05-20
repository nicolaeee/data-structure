#include <iostream>
#include <cmath>

using namespace std;

void generateGrayCode(int n) {
    int a[40][10]; 

    a[1][1] = 0;
    a[2][1] = 1;

    for (int k = 2; k <= n; k++) {
        int k1 = pow(2, k - 1); 
        for (int i = 1; i <= k1; i++) {
            for (int j = 1; j <= k; j++) {
                a[2 * k1 - i + 1][j] = a[i][j];
            }
            a[i][k] = 0;        
            a[2 * k1 - i + 1][k] = 1;
        }
    }
    cout << "Codul Gray pentru " << n << " este:\n";
    for (int i = 1; i <= pow(2, n); i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Introduceti n: ";
    cin >> n;

    generateGrayCode(n);
}