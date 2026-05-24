#include <iostream>
using namespace std;

int main() {
    const int MAX = 10;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int filasA, columnasA, filasB, columnasB;

    
    cout << "Ingrese el numero de filas de la matriz A: ";
    cin >> filasA;
    cout << "Ingrese el numero de columnas de la matriz A: ";
    cin >> columnasA;

    cout << "Ingrese el numero de filas de la matriz B: ";
    cin >> filasB;
    cout << "Ingrese el numero de columnas de la matriz B: ";
    cin >> columnasB;

 
    if (columnasA != filasB) {
        cout << "Error: No se pueden multiplicar las matrices. (columnas de A ? filas de B)" << endl;
        return 1;
    }

    
    cout << "\nIngrese los elementos de la matriz A:" << endl;
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    
    cout << "\nIngrese los elementos de la matriz B:" << endl;
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> B[i][j];
        }
    }

    
    cout << "\nMatriz A por Matriz B:\n" << endl;
    int filasMax = (filasA > filasB) ? filasA : filasB;

    for (int i = 0; i < filasMax; i++) {
        
        if (i < filasA) {
            cout << "[ ";
            for (int j = 0; j < columnasA; j++) {
                cout << A[i][j] << " ";
            }
            cout << "]";
        } else {
            cout << "  ";
            for (int j = 0; j < columnasA + 2; j++) cout << "   ";
        }

        
        if (i == filasMax / 2)
            cout << "  x  ";
        else
            cout << "     ";

        
        if (i < filasB) {
            cout << "[ ";
            for (int j = 0; j < columnasB; j++) {
                cout << B[i][j] << " ";
            }
            cout << "]";
        }

        cout << endl;
    }

    
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            C[i][j] = 0;
        }
    }

    
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    cout << "\nResultado (Matriz C = A x B):\n" << endl;
    for (int i = 0; i < filasA; i++) {
        cout << "[ ";
        for (int j = 0; j < columnasB; j++) {
            cout << C[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

