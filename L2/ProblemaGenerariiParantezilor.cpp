#include <iostream>
#include <string>

using namespace std;

void Back(int k, int n, int dif, string x) {
    if (k == n + 1) {
        cout << x << endl;
    }
    else {
        if (dif < n - k + 1) {
            Back(k + 1, n, dif + 1, x + "(");
        }
        if (dif > 0) {
            Back(k + 1, n, dif - 1, x + ")");
        }
    }
}

int main() {
    int n;
    cout << "Introduceti lungimea sirului de paranteze: ";
    cin >> n;

    if (n % 2 == 0) {
        Back(1, n, 0, "");
    }
    else {
        cout << "Lungimea sirului de paranteze trebuie sa fie un numar par." << endl;
    }

    return 0;
}

/*
Acest program generează toate combinațiile corecte de paranteze deschise și închise pentru o secvență de paranteze de lungime dată. Este cunoscută și sub numele de "Problema generării parantezelor bine formate".

Pentru a realiza aceasta, programul utilizează o abordare de tip backtracking. În funcția Back, programul explorează recursiv toate posibilitățile de a forma o secvență de paranteze de lungime n într-un mod valid.

k reprezintă poziția curentă în secvența de paranteze.
n este lungimea totală a secvenței de paranteze.
dif este diferența dintre numărul de paranteze deschise și numărul de paranteze închise.
x este șirul de paranteze construit până în momentul curent.
Funcția Back generează recursiv toate combinațiile posibile de paranteze, respectând următoarele reguli:

La fiecare pas, se adaugă o paranteză deschisă la șirul x dacă diferența dif este mai mică decât lungimea rămasă a șirului de paranteze.
La fiecare pas, se adaugă o paranteză închisă la șirul x dacă diferența dif este mai mare decât zero.
Aceste reguli garantează că secvența de paranteze generată în mod recursiv este corectă. Programul se oprește atunci când s-a generat o secvență completă de paranteze, moment în care aceasta este afișată pe ecran.

În funcția main, utilizatorul introduce lungimea dorită a secvenței de paranteze. Dacă lungimea este un număr par, programul inițializează procesul de generare a parantezelor bine formate prin apelul funcției Back. În caz contrar, se afișează un mesaj de eroare indicând că lungimea trebuie să fie un număr par.
*/