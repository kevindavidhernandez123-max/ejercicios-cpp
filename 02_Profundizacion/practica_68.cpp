#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

struct personas {
    int edad;
    string nombre;
    string direccion;
};

void registrar(vector<personas>& per) {
    personas nuevapersona;
    cin.ignore();  
    cout <<"Ingrese su nombre: "; 
    getline(cin, nuevapersona.nombre);  
    cout <<"Ingrese su edad: ";
    cin >> nuevapersona.edad;
    cin.ignore();  
    cout <<"Ingrese su direccion: ";
    getline(cin, nuevapersona.direccion);  

    per.push_back(nuevapersona);
    cout <<"Persona registrada." << endl;
}

void buscar(vector<personas>& per) {
    string busqueda;
    bool encontrado=false;
    cout <<"Ingrese el nombre de la persona a buscar: ";
    cin.ignore(); 
    getline(cin, busqueda);  
    
    for(int x = 0; x < per.size(); x++) {
        if(busqueda == per[x].nombre) {
            cout<<"Persona encontrada:"<<endl;
            cout<<"Nombre: " <<per[x].nombre <<endl;
            cout<<"Edad: " <<per[x].edad <<endl;
            cout<<"Dirección: " << per[x].direccion <<endl;
            encontrado=true;
            break;  
        }
    }

    if(encontrado==false) {
        cout<<"\nNo se encontró a la persona." << endl;
    }
}

void mostrar(const vector<personas>& per) {
    if (per.size() == 0) {  
        cout<<"No hay personas registradas."<< endl;
        return;
    }
    cout<<"\nListado de personas registradas:\n";
    cout<<"------------------------------------------------------\n";
    cout<<left <<setw(20) << "Nombre"
         <<setw(10)<<"Edad" 
         <<setw(30)<<"Dirección" << endl;
    cout<< "------------------------------------------------------\n";

    for (int i=0; i<per.size(); i++) {
        cout<< left << setw(20) << per[i].nombre 
             << setw(10) << per[i].edad 
             << setw(30) << per[i].direccion << endl;
    }
    cout<<"------------------------------------------------------\n";
}

int main() {
	setlocale(LC_ALL,"spanish");
    vector<personas> per;  
    int opc;

    do {
        cout<<"Menú de gestión de personas:" << endl;
        cout<<"1. Registrar una nueva persona" << endl;
        cout<<"2. Buscar persona por nombre" << endl;
        cout<<"3. Mostrar todas las personas registradas" << endl;
        cout<<"4. Salir del programa" << endl;
        cin >> opc;

        switch (opc) {
            case 1: {
                registrar(per);  
                break;
            }
            case 2: {
                buscar(per);  
                break;
            }
            case 3: {
            	mostrar(per);
                 
                break;
            }
            case 4: {
                cout << "Hasta pronto..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
            }
        }
    } while (opc != 4);  

    return 0;
}

