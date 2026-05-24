#include<iostream>
#include<string>
using namespace std;

struct registro{
	int edad;
};

void calculo(registro edades[],int  &N){
	float prom=0;
	for(int x=0; x<N; x++){
		prom+=edades[x].edad;
	}
	prom=prom/N;
	cout<<"el promedio de edad de todas las personas registradas es de "<<prom;
}

int main(){
      setlocale(LC_ALL,"spanish");
	  int N;
	  
	cout<<"ingrese el numero de personas"<<endl;
	cin>>N;
	registro edades[N];
	
	for(int x=0; x<N; x++){
		
		cout<<"persona N°"<<x+1<<endl;
	    cout<<"ingrese su edad ";
		cin>>edades[x].edad;
	}
	calculo(edades,N);
	
	return 0;
}
