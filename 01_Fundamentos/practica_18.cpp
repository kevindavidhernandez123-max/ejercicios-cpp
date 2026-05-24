//verificar si un numero es narcisista o no


#include<iostream>
using namespace std;
int main(){
	int N,digito,suma=0;
	int exp=0;
	int cop,pot=1;
	cout<<"bienvenido a su programa"<<endl;
	cout<<"ingrese un numero "<<endl;
	cin>>N;
	
	cop=N;
	do{
		
		exp++;
		N/=10;
	}while(N>0);
	
	
	N=cop;
	for(; N>0;){
		digito=N%10;

		
		pot=1;
		for(int i=1; i<=exp; i++)
		{
			pot=pot*digito;
		}
		suma+=pot;
		N=N/10;
		
		
	}
	N=cop;
	if(suma==N){
		
		cout<<"es un numero narcisista";
	}
	else{
		cout<<"no es un numero narcisista";
	}
	
	
	return 0;
}
