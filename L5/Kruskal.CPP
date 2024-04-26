#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 20; // Numărul maxim de noduri
const int MAX_M = 20; // Numărul maxim de muchii

struct Edge {
    int u, v, w; // Nodurile sursă și destinație și ponderea muchiei
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w; // Funcția de comparare pentru sortarea muchiilor
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

void kruskalMST(Edge edges[], int n, int m) {
    sort(edges, edges + m, compareEdges); // Sortează muchiile în ordine crescătoare a ponderilor

    Edge result[n - 1]; // Arborescența de acoperire minimă (MST) va avea n - 1 muchii
    int parent[n], rank[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i; // Inițializează fiecare nod ca fiind propriul său reprezentant
        rank[i] = 0;   // Inițializează rangul fiecărui nod cu 0
    }

    int e = 0; // Contor pentru muchiile adăugate la MST
    int i = 0; // Contor pentru muchiile parcurse
    while (e < n - 1 && i < m) {
        Edge nextEdge = edges[i++];
        int u = nextEdge.u;
        int v = nextEdge.v;
        int setU = find(parent, u);
        int setV = find(parent, v);

        if (setU != setV) { // Verifică dacă adăugarea muchiei formează un ciclu
            result[e++] = nextEdge; // Adaugă muchia la MST
            unionSet(parent, rank, setU, setV); // Unește cele două seturi
        }
    }

    cout << "Muchiile arborelui de acoperire minimă sunt:\n";
    for (int i = 0; i < e; ++i)
        cout << result[i].u << " - " << result[i].v << " : " << result[i].w << "\n";
}

int main() {
    int n = 5, m = 7;
    Edge edges[MAX_M] = {
        {1, 4, 2}, {5, 4, 2}, {1, 2, 2}, {1, 5, 3}, {4, 3, 4}, {5, 2, 5}, {2, 3, 5}
    };
    kruskalMST(edges, n, m);
    return 0
}


/*

Algoritmul lui Kruskal este un algoritm eficient pentru găsirea arborelui de acoperire minim (MST) într-un graf ponderat conex. Iată o explicație a acestui algoritm:

Sortarea muchiilor: Se sortează toate muchiile grafului în ordine crescătoare a ponderilor lor.
Inițializare: Se inițializează un arbore vid și un tablou pentru a urmări reprezentanții fiecărui vârf.
Parcurgerea muchiilor: Se parcurg muchiile grafului în ordinea sortării. Pentru fiecare muchie, se verifică dacă nodurile sale sunt deja conectate. Dacă nu sunt conectate, muchia este adăugată la arborele de acoperire și reprezentanții nodurilor sunt actualizați.
Verificarea ciclurilor: Pentru a evita formarea ciclurilor în arborele de acoperire, se verifică dacă cele două noduri ale unei muchii aparțin aceluiași arbore. Dacă aparțin aceluiași arbore, adăugarea muchiei ar crea un ciclu și aceasta este ignorată.
Terminare: Algoritmul se oprește atunci când toate nodurile sunt conectate în arbore sau când toate muchiile au fost parcurse.
*/