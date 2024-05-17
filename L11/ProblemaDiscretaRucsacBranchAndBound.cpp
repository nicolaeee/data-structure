#include <iostream>  // Biblioteca pentru intrare si iesire
#include <vector>    // Biblioteca pentru vectori
#include <queue>     // Biblioteca pentru cozi
#include <algorithm> // Biblioteca pentru functii de algoritmi

using namespace std; // Folosim spatiul de nume standard

// Structura pentru a reprezenta un obiect cu valoare, greutate si raport valoare/greutate
struct Obiect {
    int valoare, greutate;
    double valoare_pe_greutate;
};

// Structura pentru a reprezenta un nod in arborele de cautare
struct Nod {
    int nivel, profit, greutate;
    double limita_superioara;
};

// Functie de comparare pentru sortarea obiectelor dupa raportul valoare/greutate
bool compara(Obiect a, Obiect b) {
    return a.valoare_pe_greutate > b.valoare_pe_greutate;
}

// Functie pentru calcularea limitei superioare (UB = T - N)
double calculeaza_limita(Nod nod, int n, int capacitate, const vector<Obiect>& obiecte) {
    // Daca greutatea nodului depaseste capacitatea, limita este 0
    if (nod.greutate >= capacitate) {
        return 0;
    }

    // Calculam suma valorilor tuturor obiectelor (T)
    int T = 0;
    for (const auto& obiect : obiecte) {
        T += obiect.valoare;
    }

    // Calculam suma valorilor obiectelor care nu au fost luate (N)
    int N = 0;
    int greutate_acumulata = nod.greutate;
    for (int i = nod.nivel; i < n; ++i) {
        if (greutate_acumulata + obiecte[i].greutate <= capacitate) {
            greutate_acumulata += obiecte[i].greutate;
        } else {
            N += obiecte[i].valoare;
        }
    }

    // Limita superioara (UB) este T - N
    double UB = T - N;
    return UB;
}

// Functie pentru rezolvarea problemei rucsacului folosind Branch and Bound
int rucsac_branch_and_bound(vector<int> valori, vector<int> greutati, int capacitate) {
    int n = valori.size(); // Numarul de obiecte
    vector<Obiect> obiecte(n);

    // Cream vectorul de obiecte cu valorile si greutatile date
    for (int i = 0; i < n; ++i) {
        obiecte[i] = { valori[i], greutati[i], (double)valori[i] / greutati[i] };
    }

    // Sortam obiectele dupa raportul valoare/greutate
    sort(obiecte.begin(), obiecte.end(), compara);

    // Coada pentru nodurile din arborele de cautare
    queue<Nod> coada;
    Nod radacina = { 0, 0, 0, 0.0 };
    radacina.limita_superioara = calculeaza_limita(radacina, n, capacitate, obiecte);
    coada.push(radacina);

    int profit_maxim = 0;

    // Cautarea in arbore folosind Branch and Bound
    while (!coada.empty()) {
        Nod nod = coada.front();
        coada.pop();

        if (nod.nivel < n) {
            // Nod cu obiectul inclus
            Nod cu_obiect = { nod.nivel + 1, nod.profit + obiecte[nod.nivel].valoare,
                             nod.greutate + obiecte[nod.nivel].greutate, 0.0 };

            if (cu_obiect.greutate <= capacitate && cu_obiect.profit > profit_maxim) {
                profit_maxim = cu_obiect.profit;
            }

            cu_obiect.limita_superioara = calculeaza_limita(cu_obiect, n, capacitate, obiecte);
            if (cu_obiect.limita_superioara > profit_maxim) {
                coada.push(cu_obiect);
            }

            // Nod fara obiectul inclus
            Nod fara_obiect = { nod.nivel + 1, nod.profit, nod.greutate, 0.0 };
            fara_obiect.limita_superioara = calculeaza_limita(fara_obiect, n, capacitate, obiecte);
            if (fara_obiect.limita_superioara > profit_maxim) {
                coada.push(fara_obiect);
            }
        }
    }

    return profit_maxim; // Returnam profitul maxim obtinut
}

int main() {
    int numar_obiecte, capacitate;

    // Cerem utilizatorului sa introduca numarul de obiecte
    cout << "Introdu numarul de obiecte: ";
    cin >> numar_obiecte;

    // Cerem utilizatorului sa introduca capacitatea rucsacului
    cout << "Introdu capacitatea rucsacului: ";
    cin >> capacitate;

    vector<int> valori(numar_obiecte);
    vector<int> greutati(numar_obiecte);

    // Cerem utilizatorului sa introduca valorile si greutatile obiectelor
    cout << "Introdu valorile si greutatile obiectelor:" << endl;
    for (int i = 0; i < numar_obiecte; ++i) {
        cout << "Valoare obiect " << i + 1 << ": ";
        cin >> valori[i];
        cout << "Greutate obiect " << i + 1 << ": ";
        cin >> greutati[i];
    }

    // Calculam si afisam profitul maxim folosind Branch and Bound
    cout << "Profit maxim: " << rucsac_branch_and_bound(valori, greutati, capacitate) << endl;
    return 0;
}

/*
Metoda Branch and Bound (ramuri si limite) este o tehnica de optimizare care se foloseste pentru a rezolva probleme de decizie combinatoriale, cum ar fi problema rucsacului. Aceasta metoda exploreaza toate solutiile posibile intr-un mod sistematic, reducand insa numarul total de solutii de examinat prin folosirea unor limite care ajuta la excluderea unor ramuri intregi ale spatiului de solutii.

Cum functioneaza metoda Branch and Bound
Structura arborelui de decizie:

Problema este reprezentata ca un arbore de decizie. Fiecare nod din arbore reprezinta o subproblema, iar fiecare ramura corespunde unei decizii de a include sau exclude un anumit obiect in rucsac.
Radacina arborelui reprezinta starea initiala, fara niciun obiect inclus in rucsac.
Explorarea nodurilor:

Se incepe de la radacina si se exploreaza nodurile in ordine.
La fiecare nod, se genereaza doi copii: unul in care obiectul curent este inclus in rucsac si unul in care nu este inclus.
Calcularea limitelor superioare:

Pentru fiecare nod, se calculeaza o limita superioara a profitului maxim care poate fi obtinut pornind din acel nod.
Daca limita superioara a unui nod este mai mica decat profitul maxim cunoscut pana in acel moment, nodul respectiv si toate subnodurile sale sunt ignorate (taiate).
Actualizarea profitului maxim:

Daca se gaseste o solutie valida cu un profit mai mare decat cel curent, aceasta devine noul profit maxim.
Continuarea procesului:

Procesul continua pana cand toate nodurile au fost fie explorate, fie taiate.
Avantajele metodei Branch and Bound
Eficienta prin reducerea spatiului de cautare:

Prin utilizarea limitelor superioare, multe ramuri ale arborelui de decizie pot fi eliminate fara a fi necesar sa fie complet explorate. Acest lucru reduce semnificativ numarul total de solutii de examinat, facand metoda mult mai eficienta decat o cautare exaustiva (brute force).
Flexibilitate:

Metoda poate fi aplicata la o varietate de probleme combinatoriale, nu doar la problema rucsacului. Orice problema care poate fi formulata in termeni de decizii secventiale poate beneficia de aceasta abordare.
Garantie pentru solutii optime:

Spre deosebire de unele metode euristice care pot gasi solutii rapide, dar nu neaparat optime, Branch and Bound garanteaza gasirea solutiei optime prin explorarea completa a spatiului de solutii, dar intr-un mod eficient.
De ce sa folosim Branch and Bound pentru problema rucsacului
Problema rucsacului presupune alegerea unui subset de obiecte astfel incat sa se maximizeze valoarea totala, fara a depasi o anumita capacitate. O abordare bruteforce ar necesita verificarea tuturor subseturilor posibile, ceea ce devine impracticabil pentru un numar mare de obiecte (deoarece numarul de subseturi creste exponential).

Metoda Branch and Bound este benefica pentru problema rucsacului deoarece:

Reduce numarul de subprobleme de examinat prin taierea ramurilor care nu pot duce la o solutie mai buna decat cea cunoscuta.
Foloseste limite superioare realiste pentru a evalua rapid potentialul fiecarui nod, evitand explorarea inutila a unor solutii nepromitatoare.
Asigura gasirea solutiei optime fara a verifica exhaustiv toate posibilitatile, ceea ce economiseste timp si resurse de calcul.
*/
