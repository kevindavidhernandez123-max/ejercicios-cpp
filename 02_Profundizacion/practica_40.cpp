#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool palindromo(string cade){
	string c;
	
	for(int z=0; z<cade.size(); z++){
		if(cade[z]>='A'&& cade[z]<='Z'|| cade[z]>='a'&& cade[z]<='z'){
		c+=tolower(cade[z]);
		
		}	
	}
	int i=0,x=c.size()-1;
	while(i<x){
		if(c[i]!=c[x])
		{
			return false;
		}
		i++;
		x--;  
	}
	 return true;
	
}

int main(){
	
	string cadena;
	do{
	cout<<"ingrese una frase"<<endl;
	getline(cin, cadena);
	
	if(cadena=="*"){
		break;
	}
	if(palindromo(cadena)==true){
		cout<<"Y"<<endl;
		
		}
		else{
			cout<<"N"<<endl;
		}
	}while(true);
	
}
