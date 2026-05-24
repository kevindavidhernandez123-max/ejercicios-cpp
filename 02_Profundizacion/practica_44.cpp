#include<iostream>
#include<string>
using namespace std;
//Buscar persona por nombre:
//Permita al usuario buscar una persona en el arreglo escribiendo su nombre. Si
//existe, muestre toda su información.
struct personas{
	string nombre;
	string numero;
	int edad;
	string titulo;
};

void busqueda(personas perso[],int &N,string &nombre){
	bool encontre=false;
	for(int x=0; x<N; x++){
		
		if(nombre==perso[x].nombre){
			cout<<"su nombre es: "<<perso[x].nombre<<endl;
			cout<<"su edad es: "<<perso[x].edad<<endl;
			cout<<"su numero es: "<<perso[x].numero<<endl;
			cout<<"su titulo es "<<perso[x].titulo<<endl;
			encontre=true;
			break;
		}	
	}
	if(encontre==false){
		cout<<"la persona no se encuentra en la base de datos";
	}
	
	
}

int main(){
	int N,cop;
	string nombre;
	setlocale(LC_ALL,"spanish");
	cout<<"ingrese la cantidad de personas ";
	cin>>N;
	cin.ignore();
	personas perso[N];
	
	for(int x=0; x<N; x++){
		
		cout<<"persona N°"<<x+1<<endl;
		
		cout<<"ingrese su nombre: ";
		getline(cin, perso[x].nombre);
		
		cout<<"ingrese su edad: ";
		cin>>perso[x].edad;
		
		cin.ignore();
		
		cout<<"ingrese su profesion: ";
		
		getline(cin,perso[x].titulo);
		
		cout<<"ingrese su numero telefonico: ";
		getline(cin,perso[x].numero);
		
	
	}
	
	
	cout<<"ingrese el nombre a buscar: ";
	getline(cin,nombre);
	
	
		
	busqueda(perso,N,nombre);
	
	
	return 0;
}
