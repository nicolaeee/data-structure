#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Algoritmul lui Dijkstra
vector<int> dijkstra(const vector<vector<pair<int, int>>>& graf, int start) {
    int numar_noduri = graf.size();
    vector<int> distanta(numar_noduri, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    distanta[start] = 0;
    minHeap.push({0, start});

    while (!minHeap.empty()) {
        int nod_curent = minHeap.top().second;
        minHeap.pop();

        for (const auto& vecin : graf[nod_curent]) {
            int nod_adiacent = vecin.first;
            int cost_arista = vecin.second;
            int distanta_noua = distanta[nod_curent] + cost_arista;

            if (distanta_noua < distanta[nod_adiacent]) {
                distanta[nod_adiacent] = distanta_noua;
                minHeap.push({distanta_noua, nod_adiacent});
            }
        }
    }

    return distanta;
}

int main() {
    // Exemplu pentru algoritmul lui Dijkstra
    int numar_noduri = 5;
    vector<vector<pair<int, int>>> graf(numar_noduri);

    graf[0].push_back({1, 10});
    graf[0].push_back({2, 5});
    graf[1].push_back({3, 1});
    graf[1].push_back({2, 2});
    graf[2].push_back({1, 3});
    graf[2].push_back({3, 9});
    graf[2].push_back({4, 2});
    graf[3].push_back({4, 4});
    graf[4].push_back({3, 6});

    vector<int> distanta = dijkstra(graf, 0);

    cout << "Distantele minime de la nodul 0 catre toate celelalte noduri:\n";
    for (int i = 0; i < numar_noduri; ++i) {
        cout << "Nodul " << i << ": " << distanta[i] << endl;
    }

    return 0;
}

/*
Algoritmul lui Dijkstra:
Explicație:
Inițializare: Inițializăm un set de noduri nevizitate, setăm distanța de la nodul de start la fiecare alt nod ca fiind infinit și distanța de la nodul de start la el însuși ca fiind 0.
Selectare nod: Alegem nodul cu cea mai mică distanță nevizitată și îl marcam ca vizitat.
Actualizare distanțe: Pentru fiecare nod adiacent nevizitat al nodului selectat, actualizăm distanțele dacă găsim o cale mai scurtă prin nodul curent.
Repetare: Reiterăm pașii 2 și 3 până când toate nodurile sunt vizitate sau nu mai există noduri cu distanțe minime nevizitate.
Pseudocod:
scss
Copy code
Dijkstra(graf, start)
    initializare(distanta, vizitat)
    distanta[start] <- 0
    pentru fiecare nod în graf
        dacă nod != start
            distanta[nod] <- infinit
        adaugare(nod, distanta[nod]) în vizitat
    cât timp vizitat nu este gol
        nod_curent <- nod cu cea mai mică distanță în vizitat
        eliminare(nod_curent, vizitat)
        pentru fiecare nod adiacent al nodului curent
            dacă nodul adiacent nu este în vizitat
                continuare
            distanta_noua <- distanta[nod_curent] + cost(nod_curent, nod_adiacent)
            dacă distanta_noua < distanta[nod_adiacent]
                actualizare(distanta[nod_adiacent], distanta_noua)
                actualizare(vizitat, nod_adiacent, distanta_noua)
    return distanta

*/