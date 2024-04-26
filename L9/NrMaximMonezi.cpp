#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& coins, int sum) {
    int numarMonede = coins.size(); // Numărul de tipuri de monede disponibile

    // Inițializăm o matrice pentru a stoca rezultatele parțiale
    vector<vector<int>> dp(numarMonede + 1, vector<int>(sum + 1, 0));

    // Pentru suma 0, numărul maxim de monede este 1 (nu folosim nicio monedă)
    for (int i = 0; i <= numarMonede; ++i) {
        dp[i][0] = 1;
    }

    // Parcurgem toate tipurile de monede
    for (int i = 1; i <= numarMonede; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (coins[i - 1] > j) {
                // Dacă valoarea monedei este mai mare decât suma curentă, nu o putem folosi, deci copiem valoarea de pe rândul de mai sus
                dp[i][j] = dp[i - 1][j];
            } else {
                // Altfel, avem trei opțiuni:
                // 1. Să excludem moneda curentă și să ne bazăm pe numărul maxim de monede pentru a obține suma j cu primele i - 1 monede
                // 2. Să includem moneda curentă și să adăugăm 1 la numărul maxim de monede pentru a obține suma j - coins[i - 1] cu primele i monede
                // 3. Să adunăm opțiunile 1 și 2
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
    }

    // Returnăm rezultatul final, numărul maxim de monede necesare pentru a obține suma dată
    return dp[numarMonede][sum];
}

int main() {
    vector<int> coins = {2, 3, 5, 10}; // Definim monezile disponibile
    int sum = 15; // Suma de bani pe care vrem să o obținem

    // Calculăm numărul maxim de monede pentru suma dată
    int maximMonezi = maxCoins(coins, sum);

    // Afișăm rezultatul
    cout << "Numarul maxim de monede pentru suma " << sum << " este: " << maximMonezi << endl;

    return 0;
}
