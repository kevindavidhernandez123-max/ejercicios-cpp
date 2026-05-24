#include<iostream>
#include<string>
using namespace std;

bool palindromo(string frase){
string c;

for(int x=0; x<frase.size(); x++){
	if(frase[x]>='A'&& frase[x]<='Z' || frase[x]>='a' && frase[x]<='z'){
	c+=tolower(frase[x]);
	}
}
int x=0, j=c.size()-1;
while(x<j){
	if(c[x]!=c[j]){
		return false;
	}
	x++;
	j--;
}
return true;
}

int main(){
	string frase;
	cout<<"ingrese una frase "<<endl;
	getline(cin, frase);
	
	palindromo(frase);
	
	if(palindromo(frase)==true){
		
		cout<<"\nes un palindromo";
	}
	else{
		
		cout<<"\nno es un palindromo ";
	}
	
	return 0;
}
