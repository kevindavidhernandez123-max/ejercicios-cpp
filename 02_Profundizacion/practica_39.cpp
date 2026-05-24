#include<iostream>
#include<string>
using namespace std;


int main(){
	string aux;
	string frase;
	string cop;
	
	
	cout<<"ingrese una frase: ";
	getline(cin,frase);
	cop=frase;
	
	for(int x=0; x<frase.size(); x++){
		
		for(int i=1; i<frase.size();i++){
			
		
		if(cop[x]>cop[i]){
			aux=cop[x];
			cop[x]=cop[i];
			cop[i]=aux;
		}
		
		
		}
		
	}
	
	if(cop==frase){
		cout<<"\nes una frase palindroma por que se escribe asi"<<frase;
		cout<<" y al reves es asi "<<cop;  
	}
	
	
	
	
	
	
	return 0;
}
