#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//Lea los datos de 3 personas usando la estructura Persona y muestre sus nombres
//en mayúsculas.
struct Persona{
	int edad;
	string nombre;
	string color;
};

string transformacion(string nombre){
	
	for(int x=0; x<nombre.size(); x++){
		
		nombre[x]=toupper(nombre[x]);
	}
	return nombre;
}

int main(){
setlocale(LC_ALL,"spanish");
	Persona persona[3];
	
	for(int x=0; x<3; x++){
		cout<<"persona N°"<<x+1<<endl;
		cout<<"ingrese su nombre: ";
		getline(cin, persona[x].nombre);
		
	    cout<<"ingrese su edad: ";
		cin>>persona[x].edad;
		cin.ignore();
		cout<<"ingrese su color favorito: ";
		getline(cin,persona[x].color);	
	}
	
	for(int x=0; x<3; x++){
		
		cout<<"persona N°"<<x+1<<" "<<transformacion(persona[x].nombre)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
