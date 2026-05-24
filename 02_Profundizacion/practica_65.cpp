#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;


struct tienda{
	string nombre;
	long precio;
	int cant;
};
void registrar() {
	tienda e;
ofstream archivo;
archivo.open("productos.txt");

if(archivo.fail()){
	cout<<"no se encontro el archivo";
	exit(1);
}

for(int x=0; x<5; x++){
	cin.ignore();
cout<<"ingrese el nombre del producto"<<endl;
getline(cin, e.nombre);
cout<<"ingrese el precio"<<endl;
cin>>e.precio;
cout<<"ingrese la cantidad del producto "<<x+1<<": ";
cin>>e.cant;
archivo<<e.nombre<<", "<<e.precio<<" , "<<e.cant<<endl;
}
archivo.close();
ifstream archivo2;
string lineas;

archivo2.open("productos.txt");

while(getline(archivo2,lineas)){
	cout<<setw(30)<<lineas<<endl;
	
}
archivo2.close();
}

void contar(){
	
	ifstream archivo3;
	archivo3.open("texto.txt");
	if(archivo3.fail()){
		cout<<"archivo con errores";
		return;
	}
	string linea;
	int cont=0;
	int cont2=0;
while (getline(archivo3, linea)){ 
    bool palabra=false;
   cont++;
    for(int i = 0; i < linea.length(); i++) { 
        
        if (linea[i] != ' ') { 
        
        if(palabra==false){
        	cont2++;
        	palabra=true;
		}
             // Aquí va la lógica del bool y el contador
        }
        else{
		
        palabra=false;
        
		}
	}

}
	cout<<"la cantidad de lineas es de"<<cont<<endl;
	cout<<"la cantidad de palabras es de"<<cont2<<endl;
	
	archivo3.close();
}

struct persona{
	string nombre;
	int edad;
	float promedio;
};

void capturar(){
	persona d;
	ofstream archivo4;
	archivo4.open("document.csv");
	
	if(archivo4.fail()){
		cout<<"el archivo tuvo errores";
		return;
	}
	
	for(int i=0; i<3; i++){
		cin.ignore();
		cout<<"ingrese su nombre"<<endl;
		getline(cin,d.nombre);
		cout<<"ingrese su edad"<<endl;
		cin>>d.edad;
		cout<<"ingrese su promedio"<<endl;
		cin>>d.promedio;
		archivo4<<d.nombre<<";"<<d.edad<<";"<<d.promedio<<endl;
	}
	
	archivo4.close();
}
int main(){
	int opc;
	do{
	
	cout<<"MENU PRINCIPAL"<<endl;
	cout<<"1. Registrar y leer productos de una tienda(archivo)"<<endl;
	cout<<"2. Contar lineas y palabras de un archivo de texto"<<endl;
	cout<<"3. Registro de estudiantes y exportacion a CSV"<<endl;
	cout<<"4. salir"<<endl;
	cout<<"seleccione una opcion: ";
	cin>>opc;
	
	switch(opc){
		
		case 1:{
			registrar();
			break;
		}
		
		case 2:{
			contar();
			break;
		}
		case 3:{
			capturar();
			break;
		}
		case 4:{
			break;
		}

	}
	
	}while(opc!=4);
	return 0;
}
