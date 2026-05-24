#include<iostream>
using namespace std;

int main(){
    int N,x, sumatoria = 0;

    cout <<"Ingrese la cantidad de elementos que tendra el vector: ";
    cin >> N;

    int v[N];  

    
    for(x=0; x<N; x++){
        cout << "Ingrese el elemento " << x+1 << ": ";
        cin >>v[x];
        sumatoria += v[x];
    }

  
    cout << "El vector generado es: ";
    for(x=0; x<N; x++){
        cout << "[" << v[x] << "] ";
    }
    cout <<endl;

 
    cout <<"La sumatoria de los valores fue: "<< sumatoria << endl;

    return 0;
}


