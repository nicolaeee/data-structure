O stivă (sau "stack" în engleză) este o structură de date abstractă care operează pe principiul LIFO (Last In, First Out), ceea ce înseamnă că ultimul element adăugat în stivă este primul care va fi eliminat.

Caracteristicile unei stive:
LIFO: Ultimul element introdus este primul care este scos.
Operații de bază:
push: Adăugarea unui element în partea de sus a stivei.
pop: Eliminarea elementului din partea de sus a stivei.
top (sau peek): Accesarea elementului din partea de sus a stivei fără a-l elimina.
isEmpty: Verifică dacă stiva este goală.
size: Returnează numărul de elemente din stivă.
Utilizări comune ale stivelor:
Evaluarea expresiilor matematice: Stivele sunt folosite pentru a evalua expresii în notație postfixată (RPN - Reverse Polish Notation) și pentru a converti expresii din notația infixată în cea postfixată.
Parantezarea corectă: Verificarea parantezării corecte în expresii matematice sau cod sursă.
Backtracking: Algoritmi care necesită revenirea la un punct anterior, cum ar fi rezolvarea problemelor labirinturilor sau generarea combinărilor.
Apeluri recursive: Stiva de apeluri (call stack) din majoritatea limbajelor de programare gestionează apelurile funcțiilor recursiv.
Exemplu simplu de utilizare a unei stive:
Iată un exemplu simplu în C++ care demonstrează operațiile de bază ale unei stive:


#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> stiva;

    // Adăugăm elemente în stivă
    stiva.push(10);
    stiva.push(20);
    stiva.push(30);

    // Accesăm elementul din vârful stivei
    cout << "Elementul din vârful stivei: " << stiva.top() << endl;

    // Eliminăm elementele din stivă
    stiva.pop();
    cout << "Elementul din vârful stivei după pop: " << stiva.top() << endl;

    // Verificăm dacă stiva este goală
    if (stiva.empty()) {
        cout << "Stiva este goală." << endl;
    } else {
        cout << "Stiva nu este goală." << endl;
    }

    return 0;
}
