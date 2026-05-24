/* 
Diseñar un algoritmo que permita crear un archivo agenda de direcciones
cuyos registros constan de los siguientes campos:
- nombre
- direccion
- ciudad
- codigo postal
- telefono
- edad
*/

#include <iostream>
#include <fstream>
using namespace std;

struct agenda {
    char nombre[50];
    char direccion[50];
    char ciudad[50];
    int codigoPostal;
    int telefono;
    int edad;
};

int main() {
    agenda e;
    ofstream archivo("agenda.dat", ios::binary); 

    if (!archivo) {
        cout << "Error al crear el archivo." << endl;
        return 1;
    }

    char opc;

    do {
        cout << "Ingrese nombre: ";
        cin>>e.nombre;          
        cout<<"Ingrese direccion: ";
        cin>>e.direccion;
        cout<<"Ingrese ciudad: ";
        cin>>e.ciudad;
        cout<<"Ingrese telefono: ";
        cin>>e.telefono;
        cout<<"Ingrese codigo postal: ";
        cin>>e.codigoPostal;
        cout<<"Ingrese edad: ";
        cin>>e.edad;


        archivo.write(reinterpret_cast<char*>(&e), sizeof(agenda));
        cout<<"¿Desea ingresar otro registro? (s/n): ";
        cin>>opc;

    } while (opc=='s'|| opc == 'S');

    archivo.close();

    return 0;
}







