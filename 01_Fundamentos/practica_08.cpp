#include<iostream>
using namespace std;
int main(){
	char nombre[50];
	int telefono, cant,tarifap,valorp;
	cout<<"introduzca su nombre";
	cin>>nombre;
	cout<<"escriba su numero de telefono";
	cin>>telefono;
	cout<<"ingrese la cantidad de pulsaciones";
	cin>>cant;
	cout<<"ingrese la tarifa por pulsaciones";
	cin>>tarifap;
	valorp= cant*tarifap;
	cout<<" su nombre es"<<nombre<<endl;
	cout<<"su numero de telefono es"<<telefono<<endl;
	cout<<"la cantidad de pulsaciones es "<<cant<<endl;
	cout<<"la tarifa por pulsacion es de "<<tarifap<<endl;
	cout<<"el valor a pagar es "<<valorp;
	cout<<"muchas gracias por usar el servicio darko tel";
	return 0;
}
