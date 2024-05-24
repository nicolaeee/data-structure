#include <iostream>
using namespace std;

int p[20], n;

// Functie pentru afisarea permutarii curente
void scrie() {
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " ";
    }
}

// Functie recursiva pentru generarea permutarilor
void permuta(int k) {
    int aux;
    // Daca am ajuns la permutarea completa, o afisam
    if (k == n + 1) {
        scrie();
    }
    else {
        // Parcurgem toate pozitiile de la k la 1
        for (int i = k; i >= 1; i--) {
            // Interschimbam elementele pentru a genera o noua permutare
            aux = p[i];
            p[i] = p[k];
            p[k] = aux;

            // Apelam recursiv pentru a genera permutarile urmatoare
            permuta(k + 1);

            // Restauram ordinea initiala pentru urmatoarea iteratie
            aux = p[i];
            p[i] = p[k];
            p[k] = aux;
        }
    }
}

int main() {
    // Citim numarul de elemente din multime
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    // Initializam vectorul p cu valorile 1, 2, ..., n
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }

    // Generam permutarile incepand de la pozitia 1
    permuta(1);

    return 0;
}

/*

Ce este o Permutare?
O permutare a unei mulțimi de elemente este o rearanjare a acestor elemente în toate ordinea posibile. De exemplu, pentru o mulțime de 3 elemente 
{
1
,
2
,
3
}
{1,2,3}, permutările sunt:

(
1
,
2
,
3
)
(1,2,3)
(
1
,
3
,
2
)
(1,3,2)
(
2
,
1
,
3
)
(2,1,3)
(
2
,
3
,
1
)
(2,3,1)
(
3
,
1
,
2
)
(3,1,2)
(
3
,
2
,
1
)
(3,2,1)
Pentru o mulțime cu 
�
n elemente, există 
�
!
n! (n factorial) permutări posibile.

Ce este Backtracking-ul?
Backtracking-ul este o tehnică de căutare folosită pentru a rezolva probleme care implică explorarea tuturor posibilităților într-un mod organizat. Este adesea utilizat pentru probleme de combinatorică, cum ar fi generarea permutărilor, combinațiilor și aranjamentelor.

Cum Funcționează Algoritmul de Generare a Permutărilor?
Inițializare: Se începe cu o mulțime de elemente și se inițializează un vector care va conține permutările. De exemplu, pentru 
�
n elemente, vectorul este inițializat cu valorile 
[
1
,
2
,
.
.
.
,
�
]
[1,2,...,n].

Generare Recursivă: Algoritmul utilizează o funcție recursivă pentru a genera permutările. La fiecare pas, se încearcă toate pozițiile posibile pentru elementul curent și se construiește permutarea pas cu pas.

Se interschimbă elementele pentru a genera o nouă permutare.
Se face un apel recursiv pentru a continua construcția permutării cu elementele rămase.
După ce se termină explorarea unei ramuri, se restaurează ordinea inițială pentru a putea explora alte posibilități.
Condiția de Oprire: Recursia se oprește atunci când permutarea este completă, adică atunci când toate pozițiile din vector au fost ocupate. Permutarea completă este apoi afișată sau stocată.

Explicația Procesului Pas cu Pas
Citirea și Inițializarea:

Se citește numărul de elemente 
�
n.
Vectorul de permutări este inițializat cu valorile de la 1 la 
�
n.
Apelul Inițial:

Se apelează funcția recursivă de generare a permutărilor începând de la prima poziție.
Generarea și Explorarea:

La fiecare apel recursiv, se explorează toate pozițiile posibile pentru elementul curent.
Se interschimbă elementele pentru a genera o nouă permutare și se face apel recursiv pentru poziția următoare.
După ce se termină explorarea pentru o poziție, se restaurează ordinea inițială pentru a putea explora alte permutări.
Afișarea Permutărilor:

Când o permutare este completă (toate pozițiile au fost ocupate), aceasta este afișată.
Exemple
Exemple de Funcționare:
Pentru mulțimea 
{
1
,
2
,
3
}
{1,2,3}, algoritmul va genera și afișa permutările în următoarea ordine:
(
1
,
2
,
3
)
(1,2,3)
(
1
,
3
,
2
)
(1,3,2)
(
2
,
1
,
3
)
(2,1,3)
(
2
,
3
,
1
)
(2,3,1)
(
3
,
1
,
2
)
(3,1,2)
(
3
,
2
,
1
)
(3,2,1)
Metoda de Explorare:
Algoritmul începe cu prima poziție și încearcă fiecare element posibil.
După ce fixează un element la o poziție, continuă cu poziția următoare, explorând toate posibilitățile pentru aceasta.
Odată ce toate pozițiile sunt completate, se obține o permutare completă, care este afișată.
Algoritmul apoi revine la poziția anterioară (backtracks), restaurează ordinea inițială și încearcă următoarea posibilitate.
Concluzie
Algoritmul de generare a permutărilor prin backtracking explorează toate rearanjamentele posibile ale unei mulțimi date. Prin interschimbarea elementelor și utilizarea recursivității, algoritmul asigură că fiecare permutare este generată și afișată. Backtracking-ul permite restaurarea stării inițiale după fiecare ramură explorată, garantând astfel că toate permutările sunt corect generate.
*/