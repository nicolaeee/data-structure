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

/*
Acest program generează toate particiile unei mulțimi date 

A. O partiție a unei mulțimi este o împărțire a sa în submulțimi nevide, numite blocuri, astfel încât fiecare element al mulțimii să aparțină exact unui bloc.

Funcția generatePartitions este responsabilă pentru generarea tuturor partițiilor. Ea folosește un algoritm iterativ pentru a calcula toate partițiile.
În funcția printPartition, vectorul partitions este utilizat pentru a stoca blocurile din fiecare partiție. Inițializăm acest vector cu n + 1 vectori vid.
Pentru fiecare element din mulțimea 

A, determinăm în ce bloc trebuie plasat. Aceasta este realizată folosind vectorul x, care stochează numărul blocului pentru fiecare element.
În funcția generatePartitions, folosim un buclu while pentru a itera prin toate elementele și pentru a le așeza corect în blocuri. Acest algoritm are la bază regulile de generare a particiilor.
Atunci când generăm toate posibilitățile, apelăm printPartition pentru a afișa partițiile.
Această abordare ne oferă toate particiile posibile ale mulțimii date.
*/