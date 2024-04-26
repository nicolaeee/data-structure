#include <iostream>
#include <vector>
using namespace std;
 
void longestIncreasingSubsequence(vector<int>& v) {
    int n = v.size();
    vector<int> l(n, 1); // Inițializează vectorul l cu 1 (pentru că un subsir de un singur element are lungimea 1)
 
    // Calcularea lungimii celui mai lung subsir crescător care se termină cu fiecare element al vectorului
    for (int k = n - 2; k >= 0; k--) {
        int max_len = 0;
        for (int i = k + 1; i < n; i++) {
            if (v[i] >= v[k] && l[i] > max_len) {
                max_len = l[i];
            }
        }
        l[k] = max_len + 1;
    }
 
    // Găsirea lungimii maxime din vectorul l
    int max_len = l[0];
    int t = 0;
    for (int k = 1; k < n; k++) {
        if (l[k] > max_len) {
            max_len = l[k];
            t = k;
        }
    }
 
    // Afișarea lungimii maxime și a subsirului corespunzător
    cout << "Lungimea maxima: " << max_len << endl;
    cout << v[t];
    for (int i = t + 1; i < n; i++) {
        if (v[i] >= v[t] && l[i] == max_len - 1) {
            cout << " " << v[i];
            max_len--;
        }
    }
}
 
int main() {
    int n;
    cout << "Introduceti numarul de elemente din vector: ";
    cin >> n;
 
    vector<int> v(n);
    cout << "Introduceti elementele vectorului: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
 
    longestIncreasingSubsequence(v);
 
    return 0;
}