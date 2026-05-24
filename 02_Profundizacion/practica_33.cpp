#include<iostream>
using namespace std;
 void sum(int numero){
 	int cop, dig=0;
 	int suma;
 	cop=numero;
 	for(; cop>0){
 		dig=cop%10;
 		suma+=dig;
 		cop/10;
	 }
 	
 	cout<<"el numero es "<<numero<<"la suma de sus digitos es "<<suma;
 }


int main(){
	int numero;
	
	cout<<"ingrese un numero ";
	cin>>numero;
	sum(numero);
	
}
