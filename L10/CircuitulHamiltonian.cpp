#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
const int MAX = 15; // Numarul maxim de orase
 
// Functia pentru a calcula costul minim al circuitului hamiltonian
int tsp(int current, int mask, vector<vector<int>>& graph, vector<vector<int>>& dp, vector<vector<int>>& path) {
    // Verificam daca toate orasele au fost vizitate
    if (mask == (1 << graph.size()) - 1) {
        path[current][mask] = 0; // Ne intoarcem la orasul initial
        return graph[current][0]; // Returnam costul de la ultimul nod la primul
    }
 
    // Verificam daca am calculat deja aceasta stare
    if (dp[current][mask] != -1) {
        return dp[current][mask];
    }
 
    int ans = INT_MAX;
 
    // Facem o iteratie prin toate orasele posibile
    for (int i = 0; i < graph.size(); i++) {
        // Verificam dacă orasul i nu a fost vizitat inca
        if (!(mask & (1 << i))) {
            // Calculam costul minim pentru a vizita orasul i
            int new_cost = graph[current][i] + tsp(i, mask | (1 << i), graph, dp, path);
            // Actualizam costul minim
            if (new_cost < ans) {
                ans = new_cost;
                path[current][mask] = i; // Memoram urmatorul nod in cale
            }
        }
    }
 
    // Se memorează rezultatul
    return dp[current][mask] = ans;
}
 
int main() {
    int n = 4; // 4 orase
 
    // Matricea de adiacenta 
    vector<vector<int>> graph = {
        {0, 16, 11, 6},
        {8, 0, 13, 16},
        {4, 7, 0, 9},
        {5, 12, 2, 0}
    };
 
    // Afiam matricea de adiacență
    cout << "Matricea de adiacenta este:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
 
    vector<vector<int>> dp(MAX, vector<int>(1 << MAX, -1)); // Matrice pentru a memora valorile deja calculate
    vector<vector<int>> path(MAX, vector<int>(1 << MAX, -1)); // Matrice pentru a memora calea minimă
 
    // Calculam costul minim al circuitului hamiltonian si memorăm calea minima
    int min_cost = tsp(0, 1, graph, dp, path); // 1 << 0 reprezintă orasul initial (0)
 
    // Afisam calea minima
    cout << "\nCalea minima este: ";
    int current = 0;
    int mask = 1;
    while (true) {
        cout << char('A' + current) << " -> ";
        if (mask == (1 << n) - 1) break; // Daca toate orasele au fost vizitate, ne oprim
        int next = path[current][mask];
        mask |= (1 << next); // Actualizăm masca pentru următorul nod
        current = next;
    }
    cout << "A\n"; // Ne întoarcem la orasul initial
 
    // Afisam costul minim al circuitului hamiltonian
    cout << "Costul minim al circuitului hamiltonian este: " << min_cost << endl;
 
    return 0;
}