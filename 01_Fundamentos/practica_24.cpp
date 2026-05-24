/*13.Leer N números enteros (positivos y negativos) distintos de cero. Mostrar el vector tal como
fue ingresado y luego mostrar los positivos ordenados en forma decreciente y por último
mostrar los negativos ordenados en forma creciente.*/
#include<iostream>
using namespace std;
int main(){
	int N;
	
	int aux;
	
	cout<<"ingrese la cantidad de numeros enteros ";
	cin>>N;
	int v[N];
	for(int x=0; x<N; x++){
		
		cout<<"ingrese el numero "<<x+1<<endl; 
		cin>>v[x];
		
	}
	cout<<"el vector es"<<endl;
		for(int x=0; x<N; x++){
		
		cout<<"[ "<<v[x]<<"]"<<endl; 
		
		
		}
		
		
	
		for(int c=0; c<N-1; c++){
			
			for(int z=c+1; z<N; z++){
				
				if(v[z]>v[c]){
					aux=v[c];
					v[c]=v[z];
					v[z]=aux;
				
					
				}
			}
		}
		
		
		
		
	
	
		
	cout<<"\ny con los numeros positivos en orden descendente"<<endl;
	for(int x=0; x<N; x++){
	if(v[x]>0){
	
cout<<v[x]<<endl;
	
	}
	}
	for(int c=0; c<N-1; c++){
			
			for(int z=c+1; z<N; z++){
				
				if(v[z]<v[c]){
					aux=v[c];
					v[c]=v[z];
					v[z]=aux;
				
					
				}
			}
		}
		cout<<"y los negativos de manera ascendente"<<endl;
	for(int x=0; x<N; x++){
	if(v[x]<0){
	
cout<<v[x]<<endl;
	
	}
	}
		
	
	
	
	return 0;
}
