//O problema do troco consiste na quantia em dinheiro para retornar usando o número mínimo de moedas 

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int makeChange(int n, vector<int>& V) {
    vector<int> f;
    //inclui o valor 0 ao vetor f (memória), que recebe os resultados do troco de acordo com os valores de n
    f.push_back(0);
    //for que percorre o vetor, n  vai indicar a posição no vetor do valor das moedas
    for (int i = 1; i < n+1; i++) {
    //variável temp com um valor temporário, servindo para armazenar o menor valor de f 
        int temp = INT_MAX;
    //variável  que percorre o for iniciando na posição 0
        int j = 0;
    //analisa se o valor de N é menor que o valor do vetor D, mais o valor da menor diferença
        while (j < V.size() && i >= V[j]) {
            int position = i - V[j];            
            temp = (f[position] < temp) ? f[position] : temp;
            j++;
        }
        
        f.push_back( temp + 1 );
        
    }
    return f[n];
}

int main()
{
    //n é o valor que quer dar em troco 
    int n = 6;
    std::vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);
    V.push_back(4);
    cout<<V.at(0);
    cout << makeChange(n, V) << endl;
}s