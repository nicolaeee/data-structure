#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Harta {
public:
    Harta(int n) : n(n), colors(n, 0), vecini(n) {}

    void adaugaVecin(int tara1, int tara2) {
        vecini[tara1].push_back(tara2);
        vecini[tara2].push_back(tara1);
    }

    bool coloreazaHarta() {
        return coloreazaTara(0);
    }

    void afiseazaColorele() {
        cout << "Culorile pentru fiecare tara sunt:\n";
        for (int tara = 0; tara < n; ++tara) {
            cout << "Tara " << tara + 1 << ": Culoare " << colors[tara] << "\n";
        }
    }

private:
    int n;
    vector<int> colors;
    vector<vector<int>> vecini;

    bool esteValid(int tara, int culoare) {
        for (int vecin : vecini[tara]) {
            if (colors[vecin] == culoare) {
                return false;
            }
        }
        return true;
    }

    bool coloreazaTara(int tara) {
        if (tara == n) {
            return true; // am colorat toate tarile cu succes
        }

        for (int culoare = 1; culoare <= 4; ++culoare) {
            if (esteValid(tara, culoare)) {
                colors[tara] = culoare;

                if (coloreazaTara(tara + 1)) {
                    return true; // colorare cu succes
                }

                colors[tara] = 0; // revenim la starea anterioara
            }
        }

        return false; // nu exista o colorare valida pentru aceasta ?ara
    }
};

int main() {
    int n; // numarul de tari
    cout << "Introduceti numarul de tari: ";
    cin >> n;

    Harta harta(n);

    int m; // numarul de conexiuni intre tari
    cout << "Introduceti numarul de conexiuni intre tari: ";
    cin >> m;

    cout << "Introduceti perechile de tari vecine:\n";
    for (int i = 0; i < m; ++i) {
        int tara1, tara2;
        cout << "Perechea " << i + 1 << ": ";
        cin >> tara1 >> tara2;
        harta.adaugaVecin(tara1 - 1, tara2 - 1); // scadem 1 pentru a incepe de la index 0
    }

    if (harta.coloreazaHarta()) {
        harta.afiseazaColorele();
    }
    else {
        cout << "Nu exista o solutie de colorare cu 4 culori.\n";
    }

    return 0;
}

/*
Această problemă se referă la colorarea unei hărți cu țări folosind un număr minim de culori, astfel încât două țări vecine să nu aibă aceeași culoare. Este cunoscută sub numele de "Problemă de colorare a hărții".

Codul începe prin citirea numărului de țări și numărul de conexiuni (vecinătăți) între acestea. Apoi, pentru fiecare conexiune, se adaugă vecinii corespunzători în structura de date a hărții.

În clasa Harta, fiecare țară este reprezentată de un nod cu o anumită culoare. Metoda coloreazaHarta() este utilizată pentru a colora harta, iar metoda afiseazaColorele() afișează culorile pentru fiecare țară.

Colorarea se realizează recursiv prin metoda coloreazaTara(int tara), care începe cu prima țară și încercă să coloreze fiecare țară în parte. Pentru fiecare țară, se încercă colorarea cu o culoare și se verifică dacă aceasta este validă (adică nu există conflicte cu vecinii). Dacă colorarea cu o anumită culoare este validă pentru toate vecinii, se continuă cu colorarea celorlalte țări. Dacă se ajunge la o colorare cu succes pentru toate țările, se returnează true, altfel se revine la o stare anterioară și se încearcă o altă culoare.

În main(), se instanțiază o hartă și se apelează metodele corespunzătoare pentru citirea datelor și colorarea hărții. Dacă există o soluție de colorare cu cel mult 4 culori, atunci se afișează culorile pentru fiecare țară; în caz contrar, se afișează un mesaj corespunzător.

*/