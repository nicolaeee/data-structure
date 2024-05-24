#include<iostream>
using namespace std;

int b[2][10], a[10], n, i, h1, m1, h2, m2, ora;

void sortare()
{
    int gata, m, i;
    do
    {
        gata = 1;
        for (i = 1; i <= n - 1; i++)
            if (b[1][a[i]] > b[1][a[i + 1]])
            {
                m = a[i];
                a[i] = a[i + 1];
                a[i + 1] = m;
                gata = 0;
            }
    } while (!gata);
}

int main()
{
    cout << "n=";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        a[i] = i;
        cout << "ora de inceput " << i<<" :";
        cin >> h1 >> m1;
        b[0][i] = h1 * 60 + m1;
        cout << "ora de sfarsit " << i << " :";
        cin >> h2 >> m2;
        b[1][i] = h2 * 60 + m2;
    }

    sortare();
    cout << "ordine: " << endl
        << a[1] << endl;
    ora = b[1][a[1]];

    for (i = 2; i <= n; i++)
        if (b[0][a[i]] >= ora)
        {
            cout << a[i] << endl;
            ora = b[1][a[i]];
        }
}

/*
Acest program își propune să ordoneze un set de intervale de timp și să afișeze ordinea în care acestea pot fi programate fără suprapunere.

Utilizatorul este întâmpinat să introducă numărul de intervale de timp, n.
Pentru fiecare interval, utilizatorul introduce ora de început și ora de sfârșit.
Intervalele sunt reprezentate ca perechi de ore și minute, convertite la minute pentru a simplifica comparațiile și sortarea.
După introducerea tuturor intervalelor, acestea sunt sortate crescător în funcție de ora de început.
Primul interval din ordinea sortată este afișat inițial.
Se stabilește o variabilă ora pentru a ține evidența orei de sfârșit a ultimului interval afișat.
Se parcurg celelalte intervale sortate și se afișează acele intervale ale căror ore de început sunt după ora de sfârșit a intervalului anterior. Aceasta asigură că intervalele nu se suprapun.
Programul se bazează pe sortarea intervalelor de timp după ora de început și pe verificarea dacă ora de început a unui interval este după ora de sfârșit a intervalului anterior pentru a evita suprapunerile.

*/