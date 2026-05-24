#include<iostream>
using namespace std;
/*Diseñar un algoritmo para calcular el máximo común
divisor de cuatro números basado en un subalgorit-
mo función mcd (máximo común divisor de dos nú-
meros).*/

int maximo(int N, int N2){
	int r;
	while(N2!=0){
		r=N%N2;
		N=N2;
		N2=r;
		
	}
	return N;
	}
int main(){
	int v[4],result;
	
	for(int x=0; x<4; x++)
	{
		cout<<"ingrese el numero "<<x+1<<endl;
		cin>>v[x];
	}
	result=v[0];
	for(int i=1; i<4; i++){
		
		result=maximo(result, v[i]);
	}
	cout<<"el MCD de los 4 numeros es "<<result;

	
	
	return 0;
}
