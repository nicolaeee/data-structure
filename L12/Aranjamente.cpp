#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<bool> disp;
int n, m;

void scrie() {
    for (int i = 1; i <= m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void aranj(int i) {
    if (i == m + 1) {
        scrie();
    }
    else {
        for (int j = 1; j <= n; j++) {
            if (disp[j]) {
                a[i] = j;
                disp[j] = false;
                aranj(i + 1);
                disp[j] = true;
            }
        }
    }
}

int main() {
    cout << "n si m: ";
    cin >> n >> m;

    a.resize(n + 1);
    disp.resize(n + 1, true);

    aranj(1);

    return 0;
}
