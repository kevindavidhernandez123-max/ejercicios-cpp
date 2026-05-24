#include<iostream>
using namespace std;

//Cree una estructura Direccion con los campos: calle y barrio. Agréguela dentro de
//Persona y solicite todos los datos.


struct Direccion{
	
	string calle;
	string barrio;

};
struct Persona{
	int edad;
	string nombre;
	Direccion ubica;
	
};
int main(){
	
	Persona regis;
	
	cout<<"ingrese su nombre: ";
	getline(cin, regis.nombre);
	
	cout<<"ingrese su edad: ";
	cin>>regis.edad;
	cin.ignore();
	cout<<"ingrese su calle: ";
	getline(cin,regis.ubica.calle);
	
	cout<<"ingrese su barrio: ";
	getline(cin,regis.ubica.barrio);
	
	cout<<"sus datos son: "<<endl;
	
	cout<<"Nombre "<<regis.nombre<<endl;
	
	cout<<"Edad: "<<regis.edad<<endl;
	cout<<"Calle: "<<regis.ubica.calle<<endl;
	cout<<"Barrio: "<<regis.ubica.barrio<<endl;
	
	
	
	
	return 0;
}
