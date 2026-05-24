//Contar caracteres de cada nombre:
//Usando el arreglo de Persona, muestre el número de caracteres que tiene el
//nombre de cada persona.
#include<iostream>
#include<string>
using namespace std;

struct persona {
	string nombre;
	
};

void contar(persona nom){
	int cont=0;
	for(int x=0; x<nom.nombre.size(); x++){
		cont++;
	}
	
	cout<<" su numero de caracteres es de "<<cont;

}
int main(){
	setlocale(LC_ALL,"spanish");
	
	int N;
	
	cout<<"ingrese la cantidad de personas"<<endl;
	cin>>N;
cin.ignore();

	persona nom[N];

	for(int x=0; x<N; x++){
		cout<<"persona N°"<<x+1<<endl;
		cout<<"ingrese su nombre: ";
		getline(cin,nom[x].nombre);
	     
	
	}
	
	for(int x=0; x<N; x++){
		cout<<"\npersona N°"<<x+1<<endl<<nom[x].nombre;
		contar(nom[x]);
	}
	
	
	return 0;
	
}
