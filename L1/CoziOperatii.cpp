#include <iostream>

using namespace std;

struct nod {
    int inf;
    nod* leg;
};

nod* enqueue(int n, nod*& front, nod*& rear) {
    nod* p = new nod();
    p->inf = n;
    p->leg = nullptr;

    if (rear == nullptr) {
        front = rear = p;
    }
    else {
        rear->leg = p;
        rear = p;
    }

    return rear;
}


nod* dequeue(nod*& front, nod*& rear) {
    if (front == nullptr) {
        cout << "Coada este goala." << endl;
        return nullptr;
    }

    nod* p = front;
    front = front->leg;

    if (front == nullptr) {
        rear = nullptr; 
    }

    delete p;
    return front;
}

void list(nod* front) {
    nod* temp = front;
    while (temp) {
        cout << temp->inf << " ";
        temp = temp->leg;
    }
    cout << endl;
}

int main() {
    nod* front;
    nod* rear;
    front = rear = nullptr;
    char comanda;

    do {
        cout << "Introduceti comanda (I: intrare locomotiva, E: iesire, L: listare, S: sfarsit): ";
        cin >> comanda;

        switch (comanda) {
        case 'I':
            int numarLocomotiva;
            cout << "Introduceti numarul locomotivei: ";
            cin >> numarLocomotiva;
            enqueue(numarLocomotiva, front, rear);
            break;
        case 'E':
            dequeue(front, rear);
            break;
        case 'L':
            cout << "Locomotivele curente: ";
            list(front);
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
Această problemă implementează operațiile fundamentale pe o coadă folosind liste înlănțuite. În cadrul acestei implementări, coada este reprezentată printr-o structură de date nod, care conține un câmp pentru informație (inf) și un pointer către următorul nod (leg). Operațiile principale pe coadă sunt implementate astfel:

Enqueue (înșiruire): Această operație adaugă un element nou la sfârșitul cozii. Funcția enqueue primește ca parametri valoarea de adăugat n, precum și referințele către variabilele front și rear, care reprezintă adresa primului și, respectiv, ultimul nod din coadă. Dacă coada este goală (rear == nullptr), atunci se creează un nou nod și atât front cât și rear sunt actualizate să indice către acesta. În caz contrar, nodul nou creat este adăugat la sfârșitul cozii prin actualizarea pointerului rear pentru nodul anterior și setarea pointerului leg al noului nod către nullptr. Funcția returnează adresa ultimului nod (rear) după actualizare.

Dequeue (ștergere): Această operație elimină primul element din coadă. Funcția dequeue primește ca parametri referințele către variabilele front și rear. În primul rând, se verifică dacă coada este goală (front == nullptr). Dacă este, se afișează un mesaj corespunzător și se returnează nullptr. În caz contrar, se elimină primul nod din coadă prin actualizarea pointerului front pentru a indica către al doilea nod. Dacă eliminarea nodului face ca coada să devină goală, atunci și pointerul rear este actualizat să fie nullptr. Memoria alocată pentru nodul eliminat este eliberată, iar funcția returnează adresa noului prim nod din coadă (front).

List (listare): Această operație afișează elementele din coadă. Funcția list primește ca parametru adresa primului nod din coadă. Se parcurge lista înlănțuită pornind de la primul nod și afișând elementele succesive, până când se ajunge la sfârșitul listei. După fiecare afișare, pointerul temp este actualizat pentru a indica următorul nod. La final, este afișat un rând nou.

Funcția main conține un buclu do-while care permite utilizatorului să introducă comenzi pentru a interacționa cu coada. Utilizatorul poate introduce următoarele comenzi:

I pentru a adăuga o locomotivă în coadă.
E pentru a elimina o locomotivă din coadă.
L pentru a lista locomotivele curente din coadă.
S pentru a încheia programul.
În funcție de comanda introdusă de utilizator, se apelează operațiile corespunzătoare. Dacă comanda introdusă este invalidă, utilizatorul este avertizat și se cere introducerea unei comenzi valide. Programul continuă să ruleze până când este introdusă comanda pentru încheierea programului (S).

*/