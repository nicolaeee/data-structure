#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int capacities[10][10];
int flowPassed[10][10];
vector<int>graph[10];
int parentsList[10];
int currentPathCapacity[10];
int bfs(int startNode, int endNode)
{
    memset(parentsList, -1, sizeof(parentsList));     // Initializarea listei de părinți cu -1
    memset(currentPathCapacity, 0, sizeof(currentPathCapacity));     // Initializarea capacității curente a drumului cu 0
    queue<int> q;     // Declarație coadă pentru BFS
    q.push(startNode);     // Adăugare nodul de start în coadă
    parentsList[startNode] = -2;     // Setare părinte pentru nodul de start ca fiind -2
    currentPathCapacity[startNode] = 999;     // Capacitatea drumului curent este inițializată cu o valoare mare
    while (!q.empty())     // Cat timp coada nu este goală
    {
        int currentNode = q.front();     // Se extrage primul nod din coadă
        q.pop();     // Se elimină nodul din coadă
        for (int i = 0; i < graph[currentNode].size(); i++)     // Parcurgere vecinii nodului curent
        {
            int to = graph[currentNode][i];     // Extrage un vecin al nodului curent
            if (parentsList[to] == -1)     // Dacă vecinul nu are părinte
            {
                if (capacities[currentNode][to] - flowPassed[currentNode][to] > 0)     // Dacă există spațiu liber pe muchia către vecin
                {
                    parentsList[to] = currentNode;     // Se setează părintele vecinului
                    currentPathCapacity[to] = min(currentPathCapacity[currentNode],
                        capacities[currentNode][to] - flowPassed[currentNode][to]);     // Se calculează capacitatea minimă a drumului până la vecin
                    if (to == endNode)     // Dacă vecinul este nodul final
                    {
                        return currentPathCapacity[endNode];     // Se returnează capacitatea drumului până la nodul final
                    }
                    q.push(to);     // Se adaugă vecinul în coadă pentru a fi explorat mai departe
                }
            }
        }
    }
    return 0;     // Se returnează 0 dacă nu s-a găsit niciun drum de la sursă la destinație
}
int edmondsKarp(int startNode, int endNode)
{
    int maxFlow = 0;     // Inițializare flux maxim la 0
    while (true)     // Cat timp
    {
        int flow = bfs(startNode, endNode);     // Se găsește capacitatea unui drum de la sursă la destinație folosind BFS
        if (flow == 0)     // Dacă nu mai există drumuri disponibile
        {
            break;     // Se iese din buclă
        }
        maxFlow += flow;     // Se adaugă capacitatea drumului la fluxul maxim
        int currentNode = endNode;     // Se inițializează nodul curent cu nodul final
        while (currentNode != startNode)     // Cat timp nodul curent nu este nodul de start
        {
            int previousNode = parentsList[currentNode];     // Se extrage părintele nodului curent
            flowPassed[previousNode][currentNode] += flow;     // Se adaugă fluxul pe muchia dintre părinte și nodul curent
            flowPassed[currentNode][previousNode] -= flow;     // Se scade fluxul pe muchia dintre nodul curent și părinte
            currentNode = previousNode;     // Se actualizează nodul curent cu părintele său
        }
    }
    return maxFlow;     // Se returnează fluxul maxim
}
int main()
{
    int nodesCount, edgesCount;
    cout << "Nr de noduri si arce\n";     // Se cere numărul de noduri și muchii
    cin >> nodesCount >> edgesCount;     // Se citește numărul de noduri și muchii
    int source, sink;
    cout << "sursa si iesirea\n";     // Se cere sursa și destinația
    cin >> source >> sink;     // Se citește sursa și destinația
    for (int edge = 0; edge < edgesCount; edge++)     // Pentru fiecare muchie
    {
        cout << "Nod start, nod final si capacitate\n";     // Se cere nodul de start, nodul final și capacitatea muchiei
        int from, to, capacity;
        cin >> from >> to >> capacity;     // Se citesc nodul de start, nodul final și capacitatea muchiei
        capacities[from][to] = capacity;     // Se setează capacitatea muchiei
        graph[from].push_back(to);     // Se adaugă nodul final în lista de adiacență a nodului de start
        graph[to].push_back(from);     // Se adaugă nodul de start în lista de adiacență a nodului final
    }
    int maxFlow = edmondsKarp(source, sink);     // Se calculează fluxul maxim folosind algoritmul Edmonds-Karp
    cout << endl << endl << "Max Flow este:" << maxFlow << endl;     // Se afișează fluxul maxim
}
/*
Inițializare: Se inițializează variabilele și structurile de date necesare, cum ar fi matricea de capacități (capacities), matricea fluxului trecut (flowPassed), lista de adiacență a grafului (graph), lista de părinți (parentsList) și capacitatea curentă a drumului (currentPathCapacity).

BFS (Breadth-First Search): Algoritmul folosește o căutare BFS pentru a găsi un drum de la sursă la destinație în rețea. În timpul acestei căutări, se actualizează lista de părinți pentru fiecare nod și se calculează capacitatea drumului curent.

Actualizarea fluxului: După ce s-a găsit un drum de la sursă la destinație, algoritmul actualizează fluxul trecut pe fiecare muchie din acest drum. Capacitatea fluxului este determinată de capacitatea minimă a muchiilor din drumul găsit.

Repetarea până la epuizare: Se repetă etapele 2 și 3 până când nu mai există drumuri de la sursă la destinație sau până când nu se mai poate crește fluxul.

Calcularea fluxului maxim: Fluxul maxim este suma tuturor fluxurilor trecute pe muchii care pleacă din nodul sursă.
*/