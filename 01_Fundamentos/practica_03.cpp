#include<iostream>

using namespace std;
int main(){
	int numero;
	cout<<"digite un numero entre 1-5";
	cin>> numero;
	switch(numero){
		case 1: cout<<"es el numero 1";
		case 2: cout<<"es el numero 2";
		case 3: cout<<"es el numero 3";
		case 4: cout<<"es el numero 4";
		case 5: cout<<"es el numero 5";
		default: cout<<"no esta en el rango de 1-5"; break;
	}
	return 0;
}
