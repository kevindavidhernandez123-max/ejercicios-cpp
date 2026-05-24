//Un número se dice automórfico si su cuadrado termina en los mismos dígitos que el número original, 
//por ejemplo 762 = 5776. Un número se dice trimórfico si su cubo termina en los mismos dígitos que el número original, por ejmplo 493 = 117649. 
//Escriba un programa en C que determine los números automórficos y trimórficos menores que 1000.
#include<iostream>
using namespace std;
int main(){
	
	int N,cop,digc=0,cop2,dig2,dig;
	long cuadrado,ax;
	
	for(int i=1; i<1000; i++){
		cop=i;
		cop2=i;
		cuadrado=cop*cop;
		digc=0;
		do {
			
			digc++;
			cop/=10;
			
		}while(cop>0);
		
		cop2=1;
		ax=digc;
		while(ax>0){
			
			cop2*=10;
			ax--;
		}
		
	    dig2=cuadrado%cop2;
		
		
		
		
		if(dig2==i){
			
			cout<<" el numero" <<i<<"es automorfico"<<endl;
			
		}
		
		
	}
	
	
	
	return 0;
}
