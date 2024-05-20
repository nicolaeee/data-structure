#include <iostream>
#include <vector>
 
using namespace std;
 
int x[20], a[20];
int n;
 
void printPartition() {
    vector<vector<int>> partitions(n + 1);
    for (int i = 1; i <= n; i++) {
        partitions[x[i]].push_back(a[i]);
    }
 
    for (int i = 1; i <= n; i++) {
        if (!partitions[i].empty()) {
            cout << "{ ";
            for (int j : partitions[i]) {
                cout << j << " ";
            }
            cout << "} ";
        }
    }
    cout << endl;
}
 
void generatePartitions(int k) {
    int v, max;
    while (k > 0) {
        v = 0;
        while (x[k] + 1 <= k && v == 0) {
            x[k]++;
            max = x[1];
            for (int i = 2; i <= k - 1; i++) {
                if (max < x[i]) {
                    max = x[i];
                }
            }
            if (x[k] <= max + 1) {
                v = 1;
            }
            else {
                v = 0;
            }
        }
 
        if (v == 0) {
            k--;
        }
        else if (k < n) {
            k++;
            x[k] = 0;
        }
        else {
            printPartition();
        }
    }
}
 
int main() {
    cout << "Introduceti n: ";
    cin >> n;
 
    cout << "Introduceti elementele multimii A:\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
 
    x[1] = 0;
    generatePartitions(1);
 
    return 0;
}