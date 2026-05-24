#include<iostream>
using namespace std;
 void suma(int &numero){
 	int cop,dig;
 	int suma=0;
 	cop=numero;
 	
 	for(; cop>0;){
 		
 		dig=cop%10;
 		suma+=dig;
 		cop/=10;
 		
	 }
	 
	 
	 if(suma>=10){
	 	cop=suma;
	 suma=0;
	
	 
	 for(;cop>0; ){
	 	dig=cop%10;
	 	suma+=dig;
	 	cop/=10;
	 	
	 }
 	 
	 
	 }
 	cout<<"el numero es "<<numero<<" la suma de sus digitos es "<<suma;
 }


int main(){
	int numero;
	
	cout<<"ingrese un numero ";
	cin>>numero;
	suma(numero);
	
}
