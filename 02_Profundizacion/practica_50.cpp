#include<iostream>
#include<string>
using namespace std;

struct persona {
    string nombre;
};

void reemplazarLetras(persona filtro[], int N) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<filtro[i].nombre.length(); j++) {
            if (filtro[i].nombre[j] =='a' || filtro[i].nombre[j]=='A') {
                filtro[i].nombre[j] ='@';  
            }
        }
    }
   
    cout<<"Nombres con 'a' reemplazados por '@':\n";
    for (int x = 0; x < N; x++) {
        cout<<"Nombre: " << filtro[x].nombre << endl;
    }
}

int main() {
    int N;
    setlocale(LC_ALL,"spanish");
    cout << "Ingrese la cantidad de personas: ";
    cin>>N;
    cin.ignore();  

    persona filtro[N];
    
    for (int x=0; x<N; x++) {
        cout<< "Ingrese el nombre de la persona N°" << x+1 << ": ";
        getline(cin, filtro[x].nombre);  
    }

    reemplazarLetras(filtro,N);

    return 0;
}

