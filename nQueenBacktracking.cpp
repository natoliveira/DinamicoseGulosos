//bactraking se refere como uma busca exaustiva.
//se apresenta como uma estratégia de resolução de problemas.
//nesse modelo analisa-se cada passo

//programa para resolver o problema de n rainhas
//grid[][] representa o array 2-d com valor(0 e 1) para grid[i][j]=1 significa que a rainha i é colocada na coluna j.
//podemos pegar qualquer número de damas , desta vez pegamos no máximo 10 damas (grid[10][10]).
#include<iostream>
using namespace std;
int grid[10][10];
//solução impressa
//row é fileira
void print(int n) {
    for (int i = 0;i <= n-1; i++) {
        for (int j = 0;j <= n-1; j++) {
            
                cout <<grid[i][j]<< " ";
            
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}
//função para verificar se a posição é segura ou não
//linha é indica a rainha no. e col representa as posições possíveis
bool isSafe(int col, int row, int n) {
//verifique a mesma coluna
//row é fileira
//grid é rede
    for (int i = 0; i < row; i++) {
        if (grid[i][col]) {
            return false;
        }
    }
    //verificação da diagonal superior esquerda
    for (int i = row,j = col;i >= 0 && j >= 0; i--,j--) {
        if (grid[i][j]) {
            return false;
        }
    }
    //diagonal superior direita
    for (int i = row, j = col; i >= 0 && j < n; j++, i--) {
        if (grid[i][j]) {
            return false;
        }
    }
    return true;
}
//função para encontrar a posição de cada rainha
//linha é indica a rainha no. e col representa as posições possíveis
bool solve (int n, int row) {
    if (n == row) {
        print(n);
        return true;
    }
//variável res é usado para possível retrocesso
    bool res = false;
    for (int i = 0;i <=n-1;i++) {
        if (isSafe(i, row, n)) {
            grid[row][i] = 1;
            //chamada recursiva solve(n, linha+1) para a próxima rainha (linha+1)
            res = solve(n, row+1) || res;//if res == false o processo irá ocorrer 
            //atribuindo a grade[row][i] = 0
            
            grid[row][i] = 0;
        }
    }
    return res;
}
int main()
{
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int n;
        cout<<"Digite o número da rainha"<<endl;
        cin >> n;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                grid[i][j] = 0;
            }
        }
        bool res = solve(n, 0);
        if(res == false) {
            cout << -1 << endl; //se não houver solução possível
        } else {
            cout << endl;
        }
  return 0;
}
 

