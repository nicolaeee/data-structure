#include <iostream>

using namespace std;

// Declarații ale unor constante
int nmax = 20; 
int inf = 100000;

// Matricea de adiacență pentru duratele activităților
float la[20][20];

// Vectori pentru timpii minimi și maximi pentru evenimente
float t[20], tb[20];

// Variabilele globale pentru iterații
int i, j, n;

// Funcția pentru citirea datelor de intrare
void citire()
{
    int i, m, x, y;  
    float c;
    
    cout << "Dati numarul de activitati: "; 
    cin >> m;
    
    // Citim arcele asociate activităților și duratele acestora
    for (i = 1; i <= m; i++) {
        cout << "Dati arcul asociat activitatii " << i << " si durata acesteia: ";
        cin >> x >> y >> c; 
        la[x][y] = c;
    }
}

// Funcția pentru calculul timpilor minimi pentru fiecare eveniment
void calct(int i)
{
    int j; 
    float max;
    
    // Dacă suntem pe primul eveniment, timpul minim este 0
    if (i < 2) 
        t[1] = 0;
    else {
        max = 0;
        
        // Iterăm prin toate evenimentele precedente și calculăm timpul minim pentru evenimentul curent
        for (j = 1; j <= n; j++) 
            if (la[j][i] >= 0) {
                if (t[j] < 0) 
                    calct(j);
                if (max < la[j][i] + t[j]) 
                    max = la[j][i] + t[j];
            }
        
        t[i] = max;
    }
}

// Funcția pentru calculul timpilor maximi pentru fiecare eveniment
int calctb(int i)
{
    int j;
    float min;
    
    // Dacă suntem pe ultimul eveniment, timpul maxim este timpul minim
    if (i == n) 
        tb[i] = t[i];
    else {
        min = inf;
        
        // Iterăm prin toate evenimentele următoare și calculăm timpul maxim pentru evenimentul curent
        for (j = 1; j <= n; j++) 
            if (la[i][j] >= 0) {
                if (tb[j] < 0) 
                    calctb(j);
                if (min > tb[j] - la[i][j]) 
                    min = tb[j] - la[i][j];
            }
        
        tb[i] = min;
    }
    
    return 0; // Adăugăm o instrucțiune de return pentru a evita eroarea C4716
}

int main()
{
    // Citim numărul de evenimente
    cout << "Dati numarul de evenimente ale lucrarii: ";
    cin >> n;
    
    // Inițializăm vectorii și matricea cu -1 (valoare semnificând lipsa unei relații)
    for (i = 1; i <= n; i++) {
        t[i] = -1; 
        tb[i] = -1;
        for (j = 1; j <= n; j++) 
            la[i][j] = -1;
    }
    
    // Citim datele de intrare
    citire();
    
    // Calculăm timpii minimi pentru fiecare eveniment
    calct(n);
    
    // Calculăm timpii maximi pentru fiecare eveniment
    calctb(1);
    
    // Afișăm evenimentele critice (cu timpii minimi egali cu timpii maximi)
    cout << "EVENIMENTELE CRITICE SUNT: " << endl;
    for (i = 1; i <= n; i++)
        if (t[i] == tb[i]) 
            cout << "Evenimentul " << i << endl;
    
    // Afișăm activitățile critice (cu timpii minimi și maximi egali și cu durata activității adăugată la timpul minim)
    cout << "ACTIVITATILE CRITICE SUNT: ";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if ((t[i] == tb[i]) && (t[j] == tb[j]) && (t[j] == t[i] + la[i][j])) 
                cout << "Activitatea reprezentata de arcul: " << i << j << endl;

    return 0;
}
