//Contar vocales en un nombre:
//Solicite al usuario su nombre completo y determine cuántas vocales contiene.
#include<iostream>
using namespace std;
int main(){
	
	string nombre;
	int cont=0;
	cout<<"ingrese su nombre completo:"<<endl;
	getline(cin,nombre);
	
	
	for(int x=0; x<nombre.size(); x++){
		
		switch(tolower(nombre[x])){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			
			cont++;
			break;
			
		}
		
	}
	
	
	cout<<"su nombre contiene la cantidad de vocales de "<<cont;
	
	
	
	
	
	
	return 0;
}
