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

/*
Pași Detaliați
Citirea Inputului:

Programul citește două valori: n și m.
n reprezintă numărul total de elemente disponibile.
m reprezintă numărul de elemente care vor fi aranjate.
Inițializarea Vectorilor:

Vectorul a este folosit pentru a stoca aranjamentele curente.
Vectorul disp (prescurtare de la "disponibil") este folosit pentru a marca elementele care sunt disponibile pentru a fi incluse în aranjament.
Generarea Aranjamentelor:

Procesul începe cu apelul funcției aranj de la poziția 1.
Funcția aranj este o funcție recursivă care încearcă să construiască aranjamente pas cu pas.
Funcționarea Recursivității:

La fiecare pas al recursiei, funcția încearcă să adauge un nou element la aranjamentul curent.
Aceasta se face prin iterarea prin toate elementele posibile (de la 1 la n).
Pentru fiecare element, dacă este disponibil (disp[j] este true), acesta este adăugat la aranjament și marcat ca utilizat.
Backtracking:

După ce un element este adăugat la aranjament, funcția aranj este apelată recursiv pentru poziția următoare.
Dacă poziția curentă ajunge la m + 1, înseamnă că aranjamentul curent este complet și este afișat.
După afișarea unui aranjament complet sau după ce toate posibilitățile au fost explorate pentru poziția curentă, elementul adăugat este marcat din nou ca disponibil (disp[j] este resetat la true). Aceasta permite explorarea altor aranjamente posibile (backtracking).
Proces Detaliat
Exemplu de Inițializare:

Dacă n = 3 și m = 2, vectorul a va avea dimensiunea 4 (indices de la 0 la 3) și disp va avea dimensiunea 4 inițializat cu true.
Primul Apel Recursiv:

aranj(1) începe la prima poziție. Programul va încerca să adauge fiecare element de la 1 la n la prima poziție din aranjament.
Construcția și Afișarea Aranjamentelor:

Dacă adaugă 1 la prima poziție, atunci apelul recursiv aranj(2) va încerca să adauge elemente la a doua poziție.
Dacă la a doua poziție adaugă 2, obținem aranjamentul 1 2.
După afișare, va încerca alte combinații, cum ar fi 1 3, și continuă acest proces până când toate combinațiile posibile sunt explorate.
Resetarea Stării (Backtracking):

După fiecare apel recursiv, programul resetează elementul curent ca disponibil pentru a explora alte aranjamente care nu au fost încă generate.
*/
