//o algoritmo guloso é baseado em recursão e subestrutura ótima.
//aborda o conceito de árvore geradora mínima : a soma das arestas resulta na menor soma possível
//árvore com n vértices vai ter n-1 arestas
//busca caminho de menor custo possível?
//faz as escolhas dos caminhos do gráfico conforme o menor valor sem fechar um circuito
#include <iostream>
#include <vector>

using namespace std;

vector<int> Prim(vector<vector<int>>& v, int n) {
    vector<bool> seen(v.size(),false);
    vector<pair<int, int>> fringe;
    vector <int> result;
    
    if (n > v.size()) {
        cout << "valor de n superior ao tamanho do vetor";
    }
    result.push_back(n);
    while (!seen[n]) {
        int valor = INT_MAX;
        int pos;
        for (int j = 0; j < v[n].size(); j++) {
            if (v[n][j] != 0 && v[n][j] < valor && !seen[j]) {
                valor = v[n][j];
                pos = j;
            }
        }        
        result.push_back(pos);
        seen[n] = true;
        n = pos;
    }

    result.pop_back();
    return result;
}

char trocaLetra(int n) {
    char letra = 'a' + n;
    return letra;
}

int main()
{
    vector<vector<int>> graph = {
        {0,3,0,0,6,5},
        {3,0,1,0,8,5},
        {0,1,0,6,0,4},
        {0,0,6,0,8,5},
        {6,0,0,8,0,2},
        {5,4,4,5,2,0} };

    vector<int> result = Prim(graph, 1);

    for (int i = 0; i < result.size(); i++) {
        cout << trocaLetra(result[i]) << " ";
    }
}