//Conteo de caracteres:
//Escriba un programa que lea una frase y cuente el número total de caracteres (sin
//contar espacios).


#include<iostream>
#include<string>
using namespace std;
int main(){
	
	string frase;
	int cont=0;
	cout<<"ingrese una frase"<<endl;
	getline(cin,frase);
	
	for(int x=0; x<frase.size(); x++){
		
		if(frase[x]!=' '){
			
			cont++;
		}
		
	}
	
	cout<<"\nel numero total de caracteres sin contar espacios es de "<<cont;
	return 0;
	
}
