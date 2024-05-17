#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structura pentru a reprezenta un obiect cu valoare și greutate
struct Obiect {
    int valoare, greutate;
};

// Functie pentru calcularea profitului maxim utilizand metoda Greedy
int rucsac_greedy(vector<Obiect>& obiecte, int capacitate) {
    int profit_maxim = 0;

    // Sortam obiectele dupa raportul valoare/greutate in ordine descrescatoare
    sort(obiecte.begin(), obiecte.end(), [](const Obiect& a, const Obiect& b) {
        return (double)a.valoare / a.greutate > (double)b.valoare / b.greutate;
    });

    // Parcurgem obiectele sortate si adaugam cat mai multe in rucsac
    for (const Obiect& obiect : obiecte) {
        if (obiect.greutate <= capacitate) {
            profit_maxim += obiect.valoare;
            capacitate -= obiect.greutate;
        } else {
            // Daca nu mai incapem complet obiectul, il adaugam partial
            profit_maxim += obiect.valoare * ((double)capacitate / obiect.greutate);
            break;
        }
    }

    return profit_maxim;
}

int main() {
    int numar_obiecte, capacitate;

    cout << "Introdu numarul de obiecte: ";
    cin >> numar_obiecte;

    cout << "Introdu capacitatea rucsacului: ";
    cin >> capacitate;

    vector<Obiect> obiecte(numar_obiecte);

    cout << "Introdu valorile si greutatile obiectelor:" << endl;
    for (int i = 0; i < numar_obiecte; ++i) {
        cout << "Valoare obiect " << i + 1 << ": ";
        cin >> obiecte[i].valoare;
        cout << "Greutate obiect " << i + 1 << ": ";
        cin >> obiecte[i].greutate;
    }

    // Afisam profitul maxim utilizand metoda Greedy
    cout << "Profit maxim: " << rucsac_greedy(obiecte, capacitate) << endl;

    return 0;
}

/*
Diferențele dintre metodele Greedy, Upper Bound (metoda folosită în Branch and Bound) și Backtracking sunt semnificative și vizează modul în care acestea iau decizii și explorează spațiul soluțiilor:

Greedy:
Alegerea optimă locală: Greedy alege întotdeauna cea mai bună opțiune locală în fiecare pas, fără a lua în considerare consecințele pe termen lung. Este o metodă euristică care poate oferi soluții rapide, dar nu garantează întotdeauna soluția optimă globală.

Eficiență: Este o metodă eficientă, deoarece necesită doar o singură parcurgere a datelor și are o complexitate de timp mai mică decât alte metode.

Upper Bound (metoda din Branch and Bound):
Limitarea spațiului de căutare: Utilizează o limită superioară pentru a tăia ramurile arborelui de căutare care nu pot conduce la o soluție mai bună decât cea deja găsită. Această limită superioară este calculată pe baza unor informații disponibile la momentul respectiv și poate fi folosită pentru a ghida procesul de căutare.

Explorare ordonată: Explorează nodurile arborelui de căutare într-o manieră ordonată, utilizând informații despre limitele superioare pentru a decide care noduri să fie expandate și care să fie abandonate.

Backtracking:
Explorare exhaustivă: Explorează complet spațiul soluțiilor, trecând prin toate posibilitățile și utilizând o abordare recursivă pentru a construi și a testa soluțiile parțiale.

Întoarcerea în urmă: Dacă o soluție parțială nu poate fi extinsă pentru a forma o soluție validă, backtracking-ul se întoarce la starea anterioară și încearcă o altă opțiune.

Potrivit pentru probleme combinatoriale: Este utilizat în special pentru probleme combinatoriale în care este necesar să găsim toate soluțiile valide sau soluția optimă.

În concluzie, Greedy alege întotdeauna cea mai bună opțiune locală, Upper Bound limitează spațiul de căutare pentru a găsi soluția optimă, iar Backtracking explorează exhaustiv toate posibilitățile pentru a găsi soluția optimă sau soluțiile valide. Alegerea metodei potrivite depinde de natura problemei și de obiectivele specifice ale acesteia.


Alegerea celei mai bune metode pentru rezolvarea problemei rucsacului depinde de mai mulți factori, inclusiv de dimensiunea problemei, de caracteristicile obiectelor și de obiectivele specifice ale algoritmului. Să examinăm circumstanțele în care fiecare metodă ar fi cea mai potrivită:

Greedy:

Este ideală atunci când se dorește o soluție rapidă și simplă, iar timpul de execuție este critic.
Funcționează bine pentru probleme mici sau pentru cazurile în care se acceptă o soluție suboptimală.
Nu garantează întotdeauna găsirea soluției optime.
Branch and Bound cu Upper Bound:

Este mai potrivită pentru probleme de dimensiuni medii spre mari, unde explorarea exhaustivă a spațiului de soluții poate fi costisitoare.
Furnizează o soluție optimă atunci când se utilizează eficient limitele superioare pentru a tăia ramurile inutile ale arborelui de căutare.
Poate fi adaptată pentru a găsi toate soluțiile valide sau pentru a identifica cea mai bună soluție, în funcție de necesități.
Backtracking:

Este potrivită pentru problemele în care se dorește găsirea tuturor soluțiilor valide sau a soluției optime, iar spațiul de căutare este moderat.
Poate fi eficientă pentru probleme mai mici, dar poate deveni costisitoare pentru probleme cu dimensiuni mari, din cauza explorării exhaustive a spațiului de soluții.

*/