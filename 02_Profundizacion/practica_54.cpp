#include<iostream>
#include<string>
#include<vector>
using namespace std;

int c = 0;

struct registro {
    int vendedores;
    int sucursales;
    int ciudades;
    int cate_A;
    int cate_B;
};

void ingresarDatosVentas(vector<registro>& vec) {
    registro p;
    c++;
    cout<<"Ingrese la cantidad de ciudades: ";
    cin>>p.ciudades;

    for (int x=0; x<p.ciudades; x++) {
        cout <<"Ingrese la cantidad de sucursales en la ciudad " <<x+1<< ": ";
        cin>>p.sucursales;

        for (int z=0; z<p.sucursales; z++) {
            cout<< "Ingrese la cantidad de vendedores en la sucursal " <<z+1 << ": ";
            cin>>p.vendedores;

            for (int j = 0; j < p.vendedores; j++) {
                cout<< "Ingrese la cantidad de productos vendidos por el vendedor " <<j+1<<" en cada categoria: "<< endl;
                cout<< "CATEGORIA A: ";
                cin>>p.cate_A;
                cout<< "CATEGORIA B: ";
                cin>>p.cate_B;
            }
        }
    }
    vec.push_back(p);  
}
void mostrar(vector<registro>& vec){
for(int x=0; x<)	
	
}

int main() {
    vector<registro> vec;
    int opc;

    do {
        cout<< "Bienvenido a su menu de ventas " << endl;
        cout<< "1. Registrar datos de ventas" << endl;
        cout<< "2. Mostrar ventas totales" << endl;
        cout<< "3. Mostrar porcentajes de ventas por tipo" << endl;
        cout<< "4. Mayor venta individual" << endl;
        cout<< "5. Promedio de ventas por vendedor" << endl;
        cout<< "6. Salir del sistema" << endl;
        cout<< "Ingrese su opcion: ";
        cin>>opc;

        switch (opc) {
            case 1: {
                ingresarDatosVentas(vec);
                break;
            }
            case 2: {
                
                break;
            }
            case 3: {
                
                break;
            }
            case 4: {
                
                break;
            }
            case 5: {
                
                break;
            }
            case 6: {
                cout<<"Saliendo" << endl;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
            }
        }
    } while(opc!=6);

    return 0;
}


