#include <iostream>

using namespace std;

struct nod {
    int inf;
    nod* leg;
};

nod* pop(nod*& varf) {
    nod* p = varf;
    varf = varf->leg;
    delete p;
    return varf;
}

nod* push(int n, nod*& varf) {
    nod* p = new nod();
    p->inf = n;
    p->leg = varf;
    varf = p;
    return varf;
}

void list(nod* varf) {
    while (varf) {
        cout << varf->inf << " ";
        varf = varf->leg;
    }
    cout << endl;
}

int main() {
    nod* varf;
    varf = NULL;
    char comanda;

    do {
        cout << "Introduceti comanda (I: intrare locomotiva, E: iesire, L: listare, S: sfarsit): ";
        cin >> comanda;

        switch (comanda) {
        case 'I':
            int numarLocomotiva;
            cout << "Introduceti numarul locomotivei: ";
            cin >> numarLocomotiva;
            push(numarLocomotiva, varf);
            break;
        case 'E':
            pop(varf);
            break;
        case 'L':
            cout << "Locomotivele curente: ";
            list(varf);
            break;
        case 'S':
            cout << "Iesire din program." << endl;
            break;
        default:
            cout << "Comanda invalida. Va rugam introduceti o comanda valida." << endl;
        }
        
    } while (comanda != 'S');

    return 0;
}

/*
Acest program implementează o structură de stivă folosind o listă simplu înlănțuită. Stiva este un tip de structură de date în care elementele sunt accesate în ordinea LIFO (Last In, First Out), adică ultimul element introdus este primul element scos. Programul permite utilizatorului să introducă, să scoată și să listeze locomotivele (reprezentate prin numere întregi) utilizând comenzi specifice.

Structura nod
cpp
Copy code
struct nod {
    int inf;
    nod* leg;
};
Structura nod reprezintă un nod din lista simplu înlănțuită și conține două componente:

inf: un întreg care stochează informația (numărul locomotivei).
leg: un pointer către următorul nod din listă.
Funcțiile principale
1. Funcția pop
cpp
Copy code
nod* pop(nod*& varf) {
    nod* p = varf;
    varf = varf->leg;
    delete p;
    return varf;
}
Scop: Scoate (șterge) elementul din vârful stivei.
Parametri: Referință la pointerul varf, care reprezintă vârful stivei.
Funcționare:
Salvează vârful stivei într-un pointer temporar p.
Actualizează vârful stivei la elementul următor.
Șterge elementul anterior vârfului și eliberează memoria.
Returnează noul vârf al stivei.
2. Funcția push
cpp
Copy code
nod* push(int n, nod*& varf) {
    nod* p = new nod();
    p->inf = n;
    p->leg = varf;
    varf = p;
    return varf;
}
Scop: Adaugă un element nou în vârful stivei.
Parametri:
n: numărul locomotivei care trebuie adăugat.
Referință la pointerul varf.
Funcționare:
Creează un nou nod.
Setează informația nodului la n.
Setează pointerul leg al noului nod pentru a indica nodul curent din vârful stivei.
Actualizează vârful stivei pentru a fi noul nod.
Returnează noul vârf al stivei.
3. Funcția list
cpp
Copy code
void list(nod* varf) {
    while (varf) {
        cout << varf->inf << " ";
        varf = varf->leg;
    }
    cout << endl;
}
Scop: Listează toate elementele din stivă.
Parametri: Pointerul varf.
Funcționare:
Parcurge lista înlănțuită de la vârful stivei până la capăt.
Afișează informația fiecărui nod.
Se oprește când ajunge la finalul listei (când varf devine NULL).
Funcția main
cpp
Copy code
int main() {
    nod* varf;
    varf = NULL;
    char comanda;

    do {
        cout << "Introduceti comanda (I: intrare locomotiva, E: iesire, L: listare, S: sfarsit): ";
        cin >> comanda;

        switch (comanda) {
        case 'I':
            int numarLocomotiva;
            cout << "Introduceti numarul locomotivei: ";
            cin >> numarLocomotiva;
            push(numarLocomotiva, varf);
            break;
        case 'E':
            pop(varf);
            break;
        case 'L':
            cout << "Locomotivele curente: ";
            list(varf);
            break;
        case 'S':
            cout << "Iesire din program." << endl;
            break;
        default:
            cout << "Comanda invalida. Va rugam introduceti o comanda valida." << endl;
        }
        
    } while (comanda != 'S');

    return 0;
}
Scop: Permite utilizatorului să gestioneze stiva de locomotive prin intermediul unei interfețe de comandă.
Funcționare:
Inițializează vârful stivei (varf) la NULL.
Citește comenzile de la utilizator într-un buclă do-while.
În funcție de comanda introdusă (I, E, L, S):
I: Adaugă o nouă locomotivă în stivă.
E: Scoate locomotiva din vârful stivei.
L: Listează toate locomotivele curente din stivă.
S: Termină programul.
Default: Afișează un mesaj pentru comanda invalidă.
Bucla se oprește atunci când utilizatorul introduce comanda S.
Concluzie
Acest program utilizează structura de date "stivă" pentru a gestiona o listă de locomotive. Prin funcțiile push, pop și list, programul permite adăugarea, eliminarea și listarea elementelor din stivă, oferind o interfață simplă pentru gestionarea acestei structuri de date.

*/