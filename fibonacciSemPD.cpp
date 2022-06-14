//fazer fib dinâmico e sem dinâmico.
//sem programação dinâmica
#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n)

if (n <= 1){
    
    return n;
    
    else 
    
    fibonacci(n-1) + fibonacci(n-2)
    
}

int main(){
    cout << "qual posição?" << endl;
    cin >> n;
    cout << fibonacci (n) << endl;
}
