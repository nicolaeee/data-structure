#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAX_N = 100;
 
int main() {
    int n;
    int T[MAX_N][MAX_N], C[MAX_N][MAX_N], drum[MAX_N][MAX_N];
 
    // Citirea valorilor triunghiului
    cout << "Introduceti numarul de linii: ";
    cin >> n;
    cout << "Introduceti elementele triunghiului:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> T[i][j];
        }
    }
 
    // Initializarea matricei auxiliare cu ultima linie a triunghiului
    for (int j = 0; j <= n; ++j) {
        C[n - 1][j] = T[n - 1][j];
    }
 
    // Calculul sumei maxime
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            if (C[i + 1][j] < C[i + 1][j + 1]) {
                C[i][j] = T[i][j] + C[i + 1][j + 1];
                drum[i][j] = j + 1;
            }
            else {
                C[i][j] = T[i][j] + C[i + 1][j];
                drum[i][j] = j;
            }
        }
    }
 
    // Afișarea sumei maxime și a elementelor care o alcătuiesc
    cout << "Suma maxima care se poate forma: " << C[0][0] << endl;
    cout << "Numerele care o alcătuiesc: ";
    int i = 0, j = 0;
    while (i < n) {
        cout << T[i][j] << " ";
        j = drum[i][j];
        ++i;
    }
 
    return 0;
}

/*
În această implementare, programarea dinamică este folosită pentru a găsi suma maximă care se poate forma într-un triunghi dat și pentru a urmări numerele care alcătuiesc această sumă maximă. Iată cum se folosește programarea dinamică în acest caz:

Inițializarea matricei auxiliare: Matricea auxiliară C este inițializată cu valorile ultimei linii a triunghiului T. Acest lucru reprezintă cazul de bază pentru algoritmul de programare dinamică.
Calculul sumei maxime: Pentru fiecare linie a triunghiului (cu excepția ultimei), se calculează suma maximă care se poate forma începând cu fiecare element de pe linia respectivă. Aceasta se face în două pași:
Pentru fiecare element dintr-o linie dată, se alege valoarea maximă între suma elementului curent și suma maximă a doi succesori posibili:
Unul situat sub elementul curent (C[i + 1][j]).
Celălalt situat sub elementul curent și la dreapta lui (C[i + 1][j + 1]).
Se actualizează matricea auxiliară C cu aceste sume maxime calculate.
Urmărirea drumului cu suma maximă: După ce s-au calculat toate sumele maxime posibile, se urmărește drumul care duce la suma maximă. Acest lucru se face pornind de la elementul de pe prima linie și prima coloană și alegând mereu cel mai mare dintre cei doi succesori posibili. Astfel, se ajunge la numerele care alcătuiesc suma maximă.
Această abordare folosește conceptul de programare dinamică pentru a evita recalcularea sumelor intermediare și pentru a găsi suma maximă cu o complexitate eficientă.

*/