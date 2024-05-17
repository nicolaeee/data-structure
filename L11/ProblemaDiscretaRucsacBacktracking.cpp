#include <iostream>
#include <vector>

using namespace std;

// Structura pentru a reprezenta un obiect cu valoare si greutate
struct Obiect {
    int valoare, greutate;
};

// Functie pentru calcularea profitului maxim utilizand backtracking
int rucsac_backtracking(int capacitate, vector<Obiect>& obiecte, int index) {
    // Daca am parcurs toate obiectele sau capacitatea este 0, returnam 0
    if (index < 0 || capacitate == 0) {
        return 0;
    }
    // Daca greutatea obiectului este mai mare decat capacitatea, il sarim
    if (obiecte[index].greutate > capacitate) {
        return rucsac_backtracking(capacitate, obiecte, index - 1);
    }
    // Verificam daca includem obiectul sau nu
    int profit_inclus = obiecte[index].valoare + rucsac_backtracking(capacitate - obiecte[index].greutate, obiecte, index - 1);
    int profit_exclus = rucsac_backtracking(capacitate, obiecte, index - 1);
    // Returnam profitul maxim dintre cele doua cazuri
    return max(profit_inclus, profit_exclus);
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

    // Afisam profitul maxim utilizand metoda backtracking
    cout << "Profit maxim: " << rucsac_backtracking(capacitate, obiecte, numar_obiecte - 1) << endl;

    return 0;
}

/*
Cum funcționează metoda Backtracking:
Construirea soluției: Se construiește incremental o soluție pas cu pas, alegând la fiecare pas una dintre mai multele opțiuni disponibile.

Testarea soluției parțiale: La fiecare pas, se testează dacă soluția parțială curentă este o soluție validă.

Explorarea posibilităților: Dacă soluția parțială este validă, se explorează mai departe toate posibilitățile de extindere a acelei soluții.

Renunțarea la soluții nevalide: Dacă soluția parțială nu poate fi extinsă pentru a forma o soluție validă, se renunță la acea ramură și se revine la stadiul anterior pentru a explora alte opțiuni.

Finalizarea soluției: Procesul continuă până când toate posibilitățile au fost explore și toate soluțiile valide au fost găsite.

Avantaje ale metodei Backtracking:
Simplitate: Este o metodă simplă și ușor de înțeles, care poate fi implementată fără nevoia de structuri de date complexe sau algoritmi avansați.

Universalitate: Poate fi aplicată la o varietate largă de probleme combinatoriale, inclusiv problema rucsacului, problema reginelor, căutarea cuvintelor, etc.

Găsirea tuturor soluțiilor: Deoarece explorează toate posibilitățile, poate găsi toate soluțiile valide pentru o problemă dată, dacă există.

Dezavantaje ale metodei Backtracking:
Eficiență redusă: Este adesea ineficientă pentru probleme mari, deoarece explorează toate posibilitățile, chiar și cele care nu conduc la soluții valide. Acest lucru poate duce la o complexitate exponentială a timpului de execuție.

Repetarea calculelor: Poate repeta calculele pentru aceleași subprobleme de mai multe ori, ceea ce poate fi ineficient pentru probleme cu suprapunere mare între subprobleme.

De ce este util să folosim metoda Backtracking:
Simplu de implementat și de înțeles: Este o metodă intuitivă și simplă, care poate fi implementată fără a fi necesară o expertiză avansată în algoritmi.

Potrivit pentru probleme mici: Pentru probleme mici sau când se dorește găsirea tuturor soluțiilor valide, backtracking-ul poate fi o alegere potrivită.

Flexibilitate: Poate fi adaptat și modificat ușor pentru a se potrivi unei game variate de probleme combinatoriale.


////////////să comparăm metoda Backtracking cu metoda Branch and Bound://////////////////////

Similarități:
Explorarea spațiului de soluții: Ambele metode explorează spațiul de soluții pentru a găsi soluția optimă sau soluțiile valide.

Metode complete: Atât Backtracking, cât și Branch and Bound, sunt metode complete, ceea ce înseamnă că garantează găsirea soluției optime (dacă există).

Diferențe:
Eficiență:

Backtracking: Explorează toate posibilitățile, chiar și cele care sunt știut că nu duc la soluții valide. Acest lucru poate duce la o complexitate exponentială a timpului de execuție și poate fi ineficient pentru probleme mari.
Branch and Bound: Folosește limitarea spațiului de căutare, eliminând ramurile care nu pot conduce la soluții mai bune decât cea deja găsită. Acest lucru poate face ca metoda să fie mai eficientă decât backtracking-ul pentru probleme mari.
Optimizare:

Backtracking: Este o tehnică brută care explorează complet spațiul de soluții, fără a lua în considerare nicio informație heuristică despre problemele parțiale.
Branch and Bound: Folosește limite superioare și alte informații pentru a optimiza explorarea spațiului de soluții, eliminând ramurile care nu pot duce la soluții optime.
Complexitatea problemelor:

Backtracking: Este mai potrivit pentru probleme mici sau pentru cazurile în care trebuie găsite toate soluțiile valide.
Branch and Bound: Este mai potrivit pentru probleme mari, deoarece folosește tehnici de reducere a spațiului de căutare și poate găsi soluția optimă mai eficient.
Concluzie:
Backtracking: Este o metodă simplă și intuitivă, potrivită pentru probleme mici și pentru cazurile în care este necesar să găsim toate soluțiile valide. Totuși, poate fi ineficient pentru probleme mari din cauza complexității timpului de execuție.

Branch and Bound: Este mai eficient pentru probleme mari, deoarece utilizează tehnici de optimizare a spațiului de căutare. Este capabil să găsească soluții optime mai rapid și poate gestiona mai eficient problemele cu dimensiuni mari.


*/
