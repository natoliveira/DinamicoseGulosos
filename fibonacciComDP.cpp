//fibonacci com programação dinâmica
#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n){
    
    int memoria1 = 1;
    int memoria0 = 0;
    int numeaux = 0;
    
    for(int i = 0; i < n -1; i++){
        numeaux = memoria1;
        numeaux = memoria0;
        memoria1 = memoria1 + memoria0;
    }
    
    return memoria1;
}

int main(){
    int f;
    cout << "qual posição?"<< endl;
    cin >> f;
    cout << fibonacci << endl;
}