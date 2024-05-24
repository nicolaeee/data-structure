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

/*

Acest program generează Codul Gray pentru un număr n de biți. Iată cum funcționează pas cu pas:

Declarații și Inițializări:

a[40][10] este o matrice folosită pentru a stoca Codul Gray.
a[1][1] = 0 și a[2][1] = 1 inițializează Codul Gray pentru un bit.
Generarea Codului Gray:

Bucla exterioară for (int k = 2; k <= n; k++) extinde Codul Gray pentru k biți, pornind de la secvența generată pentru k-1 biți.
k1 = pow(2, k - 1) calculează numărul de elemente din Codul Gray pentru k-1 biți.
Bucla interioară for (int i = 1; i <= k1; i++) parcurge elementele Codului Gray generate pentru k-1 biți.
În interiorul acestei bucle:
a[2 * k1 - i + 1][j] = a[i][j] copiază elementele Codului Gray anterior inversând ordinea.
a[i][k] = 0 adaugă un 0 la sfârșitul fiecărui element din prima jumătate a Codului Gray extins.
a[2 * k1 - i + 1][k] = 1 adaugă un 1 la sfârșitul fiecărui element din a doua jumătate a Codului Gray extins.
Afișarea Codului Gray:

Bucla for (int i = 1; i <= pow(2, n); i++) parcurge toate elementele Codului Gray pentru n biți.
Bucla interioară for (int j = 1; j <= n; j++) afișează fiecare bit al fiecărui element din Codul Gray.
Explicația Detaliată a Algoritmului
Inițializare pentru 1 Bit:

Se începe cu Codul Gray pentru un singur bit: 0 și 1.
Extinderea Codului Gray:

Pentru fiecare extindere la k biți, se ia Codul Gray pentru k-1 biți, se dublează lungimea și se inversează ordinea pentru a crea a doua jumătate.
Prima jumătate păstrează valorile anterioare cu 0 adăugat la sfârșit.
A doua jumătate păstrează valorile inversate cu 1 adăugat la sfârșit.
Exemplu de Funcționare:

Pentru n = 2:
Inițial: 0, 1.
Extins: 00, 01 (prima jumătate), 11, 10 (a doua jumătate inversată și cu 1 adăugat).
Rezultat: 00, 01, 11, 10.
Pentru n = 3:
Inițial: 00, 01, 11, 10.
Extins: 000, 001, 011, 010 (prima jumătate), 110, 111, 101, 100 (a doua jumătate inversată și cu 1 adăugat).
Rezultat: 000, 001, 011, 010, 110, 111, 101, 100.
Cum Lucrează Programul
Citește numărul de biți n.
Inițializează matricea a cu Codul Gray pentru 1 bit.
Extinde Codul Gray pentru fiecare bit suplimentar până la n.
Afișează Codul Gray rezultat pentru n biți.

*/
