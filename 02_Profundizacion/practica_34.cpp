#include<iostream>
using namespace std;
void suma(int &digito){
	int cop,cop2;
	int cua,cub,cubo;
	int cont=0;
	int suma=0,suma2=0,suma3=0;
	int cuadrado;
	int cop_cua;
	int cop_cub;
	cop=digito;
	cop2=digito;
	for(; cop2>0;){
	cop=cop2%10;
	suma+=cop;
	cop2/=10;
	}
	cuadrado=digito*digito;
cop_cua=cuadrado;
cua=cuadrado;
int cop3;
	for(; cuadrado>0;){
	
	cop3=cuadrado%10;
	suma2+=cop3;
	cuadrado/=10;
	}
	int cop4=0;
	cubo=digito*digito*digito;
	cub=cubo;
	for(; cubo>0;){
	cop4=cubo%10;
	suma3+=cop4;
	cubo/=10;
	}
	cout<<"\nel numero es "<<digito<<" y su cuadrado es "<<cua<<" su cubo es "<<cub<<endl;
	if(suma==suma2 && suma==suma3){
		cout<<"la suma de los digitos del numero es "<<suma<<endl<<"la suma de los digitos del cuadrado "<<suma2<<endl<<" y la suma de los digitos del cubo es "<<suma3;
		cout<<"\n siendo el mismo valor para los 3";
			
	}
	else{
		cout<<"la suma de los digitos del numero es "<<suma<<endl<<"la suma de los digitos del cuadrado "<<suma2<<endl<<"y la suma de los digitos del cubo es "<<suma3;
		cout<<"\nno es el mismo valor para los 3";
	}
}

int main(){
	int digito;
	
	cout<<"ingrese el digito "<<endl;
	cin>>digito;
	
	suma(digito);
	
	
	
}
