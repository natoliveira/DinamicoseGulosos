* C++ program for solution of Hamiltonian
Cycle problem using backtracking */
#include <bits/stdc++.h>
using namespace std;
 
//numero de vertices no gráfico
#define V 5
 
void printSolution(int path[]);
 
/* Uma função utilitária para verificar se
o vértice v pode ser adicionado no índice 'pos'
no Ciclo Hamiltoniano construído
até agora (armazenado em 'path[]') */
bool isSafe(int v, bool graph[V][V],
            int path[], int pos)
{
    /* Verifica se este vértice é adjacente
    vértice do vértice adicionado anteriormente. */
    if (graph [path[pos - 1]][ v ] == 0)
        return false;
 
    /* Verifica se o vértice já foi incluído.
    Esta etapa pode ser otimizada criando
    uma matriz de tamanho V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}
 
/* Uma função utilitária recursiva
para resolver o problema do ciclo hamiltoniano */
bool hamCycleUtil(bool graph[V][V],
                  int path[], int pos)
{
    /* caso base: Se todos os vértices forem
    incluído no Ciclo Hamiltoniano */
    if (pos == V)
    {
        // E se houver uma aresta do
        // último vértice incluído no primeiro vértice
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
 
    // Tenta diferentes vértices como próximo candidato
    // em Ciclo Hamiltoniano. Nós não tentamos para 0 como
    // incluímos 0 como ponto de partida em hamCycle()
    for (int v = 1; v < V; v++)
    {
        /* Verifica se este vértice pode ser adicionado
        // para ciclo hamiltoniano */
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
 
            /* recorrente para construir o resto do caminho */
            if (hamCycleUtil (graph, path, pos + 1) == true)
                return true;
 
            /* Se adicionar o vértice v não levar a uma solução,
            então remova-o */
            path[pos] = -1;
        }
    }
 
    /* Se nenhum vértice pode ser adicionado a
    Ciclo Hamiltoniano construído até agora,
    então retorne falso */
    return false;
}
 
/* Esta função resolve o problema do Ciclo Hamiltoniano
usando o Retrocesso. Ele usa principalmente hamCycleUtil() para
resolva o problema. Retorna falso se não houver
Ciclo Hamiltoniano possível, caso contrário, retorne true
e imprime o caminho. Observe que pode haver
mais de uma solução, esta função imprime uma
das soluções viáveis. */
bool hamCycle(bool graph[V][V])
{
    int *path = new int[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
 
    /* Vamos colocar o vértice 0 como o primeiro vértice do caminho.
    Se houver um ciclo hamiltoniano, então o caminho pode ser
    iniciado a partir de qualquer ponto do ciclo, pois o gráfico não é direcionado */
    path[0] = 0;
    if (hamCycleUtil(graph, path, 1) == false )
    {
        cout << "\nSolution does not exist";
        return false;
    }
 
    printSolution(path);
    return true;
}
 
/* Uma função utilitária para imprimir a solução */
void printSolution(int path[])
{
    cout << "Solution Exists:"
            " Following is one Hamiltonian Cycle \n";
    for (int i = 0; i < V; i++)
        cout << path[i] << " ";
 
    // Vamos imprimir o primeiro vértice novamente
    // para mostrar o ciclo completo
    cout << path[0] << " ";
    cout << endl;
}
 
int main()
{
    /* Let us create the following graph
        (0)--(1)--(2)
        | / \ |
        | / \ |
        | / \ |
        (3)-------(4) */
    bool graph1[V][V] = {{0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}};
     
    // Printar a solução:
    hamCycle(graph1);
     
    /* Vamos criar o seguinte gráfico
    (0)--(1)--(2)
    | / \ |
    | / \ |
    | / \ |
    (3) (4) */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                         {1, 0, 1, 1, 1},
                         {0, 1, 0, 0, 1},
                         {1, 1, 0, 0, 0},
                         {0, 1, 1, 0, 0}};
     //solucao printada
     hamCycle(graph2);
 
    return 0;
}
 
