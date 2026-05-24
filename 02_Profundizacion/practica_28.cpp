#include<iostream>
using namespace std;
/*Diseñar la función FACTORIAL que calcule el factorial
de un número entero en el rango 100 a 1.000.000.*/

long long factorial(long long facto){
	long long  facto2=1;
	
	for(int x=1; x<=facto; x++){
		facto2*=x;
	}
	return facto2;
}



int main(){
	
	long long N;
	
	do{
	cout<<"ingrese un numero entero "<<endl;
	cin>>N;
	
	if(N<100){
		cout<<" ERROR ingrese un numero entre el rango de 100 a 1000000 "<<endl;
	}
	
	}while(N<100);
	
	cout<<" el factorial es "<<factorial(N);
	
	return 0;
}
