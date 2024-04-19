
#include <iostream>
#include <vector>

using namespace std;

// Functie pentru schimbarea a doua elemente
void schimba(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Functie pentru alegerea pivotului
int alegePivot(const vector<int>& lista, int inceput, int sfarsit) {
    // Alegem pivotul să fie primul element
    return lista[inceput];
}

// Functie pentru partajarea listei
int partajare(vector<int>& lista, int inceput, int sfarsit) {
    // Alegem pivotul
    int pivot = alegePivot(lista, inceput, sfarsit);
    int i = inceput - 1;

    // Parcurgem lista
    for (int j = inceput; j <= sfarsit; j++) {
        // Daca gasim un element mai mic decat pivotul
        if (lista[j] <= pivot) {
            // Incrementam indicele i si interschimbam elementele
            i++;
            schimba(lista[i], lista[j]);
        }
    }
    // Mutam pivotul la pozitia sa corecta
    schimba(lista[i + 1], lista[sfarsit]);
    // Returnam indicele pivotului
    return i + 1;
}

// Functie de sortare Quicksort
void quicksort(vector<int>& lista, int inceput, int sfarsit) {
    if (inceput < sfarsit) {
        // Partajam lista si obtinem pivotul
        int pivotIndex = partajare(lista, inceput, sfarsit);

        // Aplicam Quicksort recursiv pe subliste
        quicksort(lista, inceput, pivotIndex - 1);
        quicksort(lista, pivotIndex + 1, sfarsit);
    }
}

int main() {
    // Initializam lista de numere
    vector<int> lista = {5, 3, 8, 1, 2, 7, 4, 6};
    int lungime = lista.size();

    // Afisam lista initiala
    cout << "Lista initiala: ";
    for (int numar : lista) {
        cout << numar << " ";
    }
    cout << endl;

    // Aplicam Quicksort pe lista
    quicksort(lista, 0, lungime - 1);

    // Afisam lista sortata
    cout << "Lista sortata: ";
    for (int numar : lista) {
        cout << numar << " ";
    }
    cout << endl;

    return 0;
}

/*
Pasul 1: Alegerea pivotului
Primul pas în algoritmul Quicksort este alegerea pivotului. Pivotul poate fi ales în diverse moduri, dar de obicei este selectat primul element al listei. În acest exemplu, vom alege primul element ca pivot.

Pasul 2: Partiționarea listei
După ce am ales pivotul, următorul pas este să partiționăm lista în două subliste: una care conține elementele mai mici decât pivotul și alta care conține elementele mai mari decât pivotul.

Pentru aceasta, folosim o metodă de partajare. În mod tradițional, folosim o buclă pentru a parcurge lista și pentru a muta elementele mai mici decât pivotul în partea stângă și elementele mai mari decât pivotul în partea dreaptă.

După partajare, pivotul se află la poziția sa finală în listă, iar toate elementele mai mici decât pivotul sunt plasate înaintea acestuia, iar cele mai mari în urma sa.

Pasul 3: Apelul recursiv
După partajare, avem două subliste: una cu elementele mai mici decât pivotul și una cu cele mai mari. Aplicăm apoi recursiv algoritmul Quicksort pentru fiecare dintre aceste subliste. Acest proces continuă până când fiecare sublistă conține un singur element sau niciunul (adică lista este sortată).

Pasul 4: Combinarea soluțiilor parțiale
Nu există o etapă de combinare explicită în Quicksort, deoarece sublistele sunt sortate în mod implicit prin apeluri recursive și modificările efectuate în timpul partajării.

Exemplu:
Pentru a exemplifica, să considerăm lista inițială [5, 3, 8, 1, 2, 7, 4, 6].

Pivotul este ales să fie primul element, 5.
Lista este partiționată astfel încât să avem subliste [3, 1, 2, 4] (elemente mai mici decât pivotul) și [8, 7, 6] (elemente mai mari decât pivotul).
Aplicăm recursiv Quicksort pe ambele subliste.
Procesul continuă până când fiecare sublistă conține un singur element sau niciunul.
La final, lista sortată este [1, 2, 3, 4, 5, 6, 7, 8].
Aceasta este o ilustrare generală a modului în care algoritmul Quicksort lucrează pas cu pas pentru a sorta o listă de elemente.

Pseudocode:

Quicksort(lista, inceput, sfarsit)
    dacă inceput < sfarsit
        // Partajam lista si obtinem indicele pivotului
        pivotIndex <- Partajare(lista, inceput, sfarsit)

        // Aplicam Quicksort recursiv pe subliste
        Quicksort(lista, inceput, pivotIndex - 1)
        Quicksort(lista, pivotIndex + 1, sfarsit)

Partajare(lista, inceput, sfarsit)
    // Alegem pivotul
    pivot <- AlegePivot(lista, inceput, sfarsit)
    i <- inceput - 1

    // Parcurgem lista
    pentru fiecare element lista[j] de la inceput la sfarsit
        dacă lista[j] <= pivot
            // Incrementam indicele i si interschimbam elementele
            i <- i + 1
            Schimba(lista[i], lista[j])
    
    // Mutam pivotul la pozitia sa corecta
    Schimba(lista[i + 1], lista[sfarsit])
    // Returnam indicele pivotului
    return i + 1

AlegePivot(lista, inceput, sfarsit)
    // Alegem pivotul, de exemplu primul element
    return lista[inceput]

Schimba(a, b)
    // Functie auxiliara pentru schimbarea a doua elemente
    temp <- a
    a <- b
    b <- temp

*/