#include <iostream>

using namespace std;

void procesarCuenta(int N) {
    int d = 0, w = 0, r = 0;
    int dep = 0, ret = 0;
    int transaccion;

 
    cin>>transaccion;
    if (transaccion>0){
	 d = transaccion;}
    if (transaccion<0) {
	w = transaccion; }

   
    for (int i = 1; i < N; i++) {
        cin>>transaccion;

        
        if (transaccion>0) {
            if (transaccion>d)d=transaccion;
        }

  
        if (transaccion < 0) {
            if (transaccion < w) w = transaccion;
        }
    }

   
    for (int i = 0; i < N; i++) {
        int dep = 0, ret = 0;
        for (int j = i; j < N; j++) {
            cin >> transaccion;
            if (transaccion > 0) dep++;
            else if (transaccion < 0) ret++;

        
            if (dep == ret) {
                r = max(r, j - i + 1);
            }
        }
    }

   
    cout << d << " " << w << " " << r << endl;
}

int main() {
    int N;
    while (cin >> N, N != 0) {
        procesarCuenta(N);
    }

    return 0;
}

