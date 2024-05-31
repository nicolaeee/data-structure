O coadă (sau "queue" în engleză) este o structură de date abstractă care operează pe principiul FIFO (First In, First Out), ceea ce înseamnă că primul element introdus în coadă este primul care va fi eliminat.

Caracteristicile unei cozi:
FIFO: Primul element introdus este primul care este scos.
Operații de bază:
enqueue (sau push): Adăugarea unui element la sfârșitul cozii.
dequeue (sau pop): Eliminarea elementului din începutul cozii.
front: Accesarea elementului din începutul cozii fără a-l elimina.
isEmpty: Verifică dacă coada este goală.
size: Returnează numărul de elemente din coadă.
Utilizări comune ale cozilor:
Sisteme de așteptare: Modelează linii de așteptare, cum ar fi coada la un magazin sau coada de procese într-un sistem de operare.
Buffering: În comunicarea între două procese sau în streaming, cozile sunt folosite pentru a păstra datele temporar.
Algoritmi de traversare a grafurilor: Algoritmul BFS (Breadth-First Search) utilizează o coadă pentru a parcurge nivelurile unui graf.
Planificarea sarcinilor: Sistemele de operare folosesc cozi pentru a gestiona planificarea proceselor.
Exemplu simplu de utilizare a unei cozi:
Iată un exemplu simplu în C++ care demonstrează operațiile de bază ale unei cozi:

#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> coada;

    // Adăugăm elemente în coadă
    coada.push(10);
    coada.push(20);
    coada.push(30);

    // Accesăm elementul din începutul cozii
    cout << "Elementul din începutul cozii: " << coada.front() << endl;

    // Eliminăm elementele din coadă
    coada.pop();
    cout << "Elementul din începutul cozii după pop: " << coada.front() << endl;

    // Verificăm dacă coada este goală
    if (coada.empty()) {
        cout << "Coada este goală." << endl;
    } else {
        cout << "Coada nu este goală." << endl;
    }

    return 0;
}

Stivă (LIFO): Ultimul element introdus este primul care este scos. Util pentru probleme de backtracking și apeluri recursive.
Coadă (FIFO): Primul element introdus este primul care este scos. Util pentru gestionarea liniilor de așteptare și traversarea nivelurilor într-un graf.