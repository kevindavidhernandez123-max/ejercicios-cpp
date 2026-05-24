#include<iostream>
using namespace std;

//Defina una estructura Persona con los campos: nombre, edad y ciudad. Solicite los
//datos e imprímalos en pantalla.
struct Persona{
	string nombre;
	int edad;
	string ciudad;
};




int main(){
	Persona e;
	cout<<"ingrese su nombre "<<endl;
	getline(cin, e.nombre);
	
	cout<<"ingrese su edad"<<endl;
	cin>>e.edad;
	cout<<"ingrese su ciudad"<<endl;
	cin>>e.ciudad;
	
	cout<<"su nombre es: "<<e.nombre<<endl;
	cout<<"su edad es de: "<<e.edad<<endl;
	cout<<"su ciudad es: "<<e.ciudad;
	
	
	
	
	
	
	return 0;
}
