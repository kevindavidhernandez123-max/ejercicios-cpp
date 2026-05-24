#include<iostream>
using namespace std;
int main(){
	
	long long N;
	int c=0;
	int suma=0;
	long long maximo=0,minimo=9999999999;
	do{
	
	cout<<"ingrese numeros enteros positivos "<<endl;
	cin>>N;
	
	if(N>0){
		c++;
	
	suma+=N;
	
	if(N>maximo){
		maximo=N;
	}
	if(N<minimo){
		minimo=N;
	}
	
	}
	

	}	while(N>0);
	
	cout<<"la cantidad de total de numeros ingresados fue de: "<<c<<endl;
	cout<<"la suma de todos los numeros ingresados fue de: "<<suma<<endl;
	
	cout<<"el valor maximo ingresado de un numero fue: "<<maximo<<endl;

	cout<<"el valor minimo ingresado de un numero fue: "<<minimo;
	
	return 0;
}
