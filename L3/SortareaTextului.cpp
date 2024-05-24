#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Text {
    int index;
    int lungime;

    Text(int i, int len) : index(i), lungime(len) {}
};

bool compareTexts(const Text& a, const Text& b) {
    return a.lungime < b.lungime;
}

int main() {
    int n;
    cout << "Numarul de texte (n): ";
    cin >> n;

    vector<Text> texts;
    for (int i = 0; i < n; ++i) {
        int length;
        cout << "Lungimea textului " << i + 1 << ": ";
        cin >> length;
        texts.push_back(Text(i + 1, length));
    }

    sort(texts.begin(), texts.end(), compareTexts);

    cout << "Permutarea optima este: ";
    for (int i = 0; i < n; ++i) {
        cout << texts[i].index << " ";
    }

    return 0;
}

/*

Acest program rezolvă o problemă de optimizare a permutării textelor. Scopul este de a aranja textele într-o ordine care să minimizeze timpul total de citire, sortând textele în ordinea crescătoare a lungimii lor.

Structura Text reține informații despre fiecare text: index - indică poziția sa inițială în listă și lungime - lungimea textului.
Funcția compareTexts este folosită pentru a compara două obiecte Text în cadrul funcției sort. Ea returnează true dacă lungimea primului text este mai mică decât a celui de-al doilea text, în caz contrar returnează false.
În funcția main, se citește numărul de texte (n). Apoi, pentru fiecare text, se citește lungimea și se adaugă un obiect Text în vectorul texts.
Vectorul texts este sortat folosind funcția sort, astfel încât textele să fie aranjate în ordinea crescătoare a lungimilor lor.
Se afișează permutarea optimă, adică ordinea în care textele trebuie citite pentru a minimiza timpul total de citire. Aceasta se obține afișând indicii textelor din vectorul sortat texts.

*/