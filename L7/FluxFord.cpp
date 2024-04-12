#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_NODES = 10;
const int INF = 1e9;

int capacities[MAX_NODES][MAX_NODES];
int flowPassed[MAX_NODES][MAX_NODES];
vector<int> graph[MAX_NODES];
int parentsList[MAX_NODES];

int bfs(int startNode, int endNode, int limit) {
    memset(parentsList, -1, sizeof(parentsList));
    queue<int> q;
    q.push(startNode);
    parentsList[startNode] = -2;
    
    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        
        for (int nextNode : graph[currentNode]) {
            if (parentsList[nextNode] == -1 && capacities[currentNode][nextNode] - flowPassed[currentNode][nextNode] >= limit) {
                q.push(nextNode);
                parentsList[nextNode] = currentNode;
                
                if (nextNode == endNode) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int fordFulkerson(int startNode, int endNode) {
    int maxFlow = 0;
    int limit = 1 << 30; // Initializam limita de scalare cu o valoare mare
    
    while (limit > 0) {
        while (bfs(startNode, endNode, limit)) {
            int flow = INF;
            int currentNode = endNode;
            
            while (currentNode != startNode) {
                int previousNode = parentsList[currentNode];
                flow = min(flow, capacities[previousNode][currentNode] - flowPassed[previousNode][currentNode]);
                currentNode = previousNode;
            }
            
            maxFlow += flow;
            currentNode = endNode;
            
            while (currentNode != startNode) {
                int previousNode = parentsList[currentNode];
                flowPassed[previousNode][currentNode] += flow;
                flowPassed[currentNode][previousNode] -= flow;
                currentNode = previousNode;
            }
        }
        
        limit >>= 1; // Reducem limita de scalare la jumătate pentru următoarea iterație
    }
    
    return maxFlow;
}

int main() {
    int nodesCount, edgesCount;
    cout << "Numarul de noduri si arce: ";
    cin >> nodesCount >> edgesCount;
    int source, sink;
    cout << "Sursa si destinatia: ";
    cin >> source >> sink;
    
    for (int edge = 0; edge < edgesCount; edge++) {
        cout << "Nod start, nod final si capacitate: ";
        int from, to, capacity;
        cin >> from >> to >> capacity;
        capacities[from][to] += capacity; // Adăugăm capacitatea pentru nodul de la from la to
        graph[from].push_back(to);
        capacities[to][from] += capacity; // Adăugăm capacitatea pentru nodul de la to la from
        graph[to].push_back(from); // Considerând că graful este neorientat
    }
    
    int maxFlow = fordFulkerson(source, sink);
    cout << "Fluxul maxim este: " << maxFlow << endl;
    
    return 0;
}
