#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
// Funcția pentru a calcula numărul minim de monede necesare pentru a obține suma dată
int minCoins(vector<int>& coins, int sum) {
    int n = coins.size(); // Numărul de monezi disponibile
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, sum + 1)); // Matrice pentru programarea dinamică, inițializată cu sum + 1
 
    // Inițializarea pentru suma 0, numărul minim de monede este 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
 
    // Iterăm prin toate monedele
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= sum; ++j) {
            if (coins[i - 1] > j) {
                // Dacă valoarea monedei este mai mare decât suma curentă, nu o putem folosi, deci numărul minim de monede este cel de pe linia anterioară
                dp[i][j] = dp[i - 1][j];
            }
            else {
                // Altfel, alegem între a folosi moneda curentă sau nu, alegând numărul minim de monede necesare
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }
 
    // Returnăm rezultatul, -1 dacă suma nu poate fi obținută cu monedele date
    return dp[n][sum] > sum ? -1 : dp[n][sum];
}
 
int main() {
    // Definim monedele și suma de bani
    vector<int> coins1 = { 1, 5, 6, 9 };
    int sum1 = 11;
 
    vector<int> coins2 = { 4, 10, 25 };
    int sum2 = 41;
 
    // Calculăm numărul minim de monezi pentru fiecare sumă
    int minCoins1 = minCoins(coins1, sum1);
    int minCoins2 = minCoins(coins2, sum2);
 
    // Afișăm rezultatele
    cout << "Pentru monedele {1, 5, 6, 9} și suma 11, numărul minim de monede este: " << minCoins1 << endl;
    cout << "Pentru monedele {4, 10, 25} și suma 41, numărul minim de monede este: " << minCoins2 << endl;
 
    return 0;
}

/*
În această implementare, programarea dinamică este folosită pentru a rezolva problema numărului minim de monede necesare pentru a obține o anumită sumă. Iată cum este utilizată programarea dinamică în acest context:

Inițializarea matricei: Se inițializează o matrice bidimensională dp, în care fiecare element dp[i][j] reprezintă numărul minim de monede necesare pentru a obține suma j folosind primele i monede. Matricea este inițializată cu valoarea sum + 1 pentru a asigura o evaluare corectă a valorii minime mai târziu.
Calculul numărului minim de monede: Se parcurge matricea dp pe baza următoarelor reguli:
Dacă valoarea monedei curente (coins[i - 1]) este mai mare decât suma curentă (j), atunci nu o putem folosi pentru a obține suma j. În acest caz, numărul minim de monede este același ca și pentru primele i - 1 monede.
Altfel, avem două opțiuni:
Să nu folosim moneda curentă și să ne bazăm pe numărul minim de monede pentru a obține suma j cu primele i - 1 monede (dp[i - 1][j]).
Să folosim moneda curentă și să adăugăm 1 la numărul minim de monede pentru a obține suma j - coins[i - 1] cu primele i monede (1 + dp[i][j - coins[i - 1]]).
Se alege minimul dintre cele două opțiuni și se actualizează valoarea corespunzătoare în matricea dp.
Returnarea rezultatului: După ce s-a parcurs întreaga matrice, rezultatul final este stocat în dp[n][sum], unde n este numărul total de monede. Dacă acest rezultat este mai mare decât suma (sum), înseamnă că suma nu poate fi obținută cu monedele date și returnăm -1. În caz contrar, returnăm valoarea din matrice, care reprezintă numărul minim de monede necesare pentru a obține suma dată.
*/