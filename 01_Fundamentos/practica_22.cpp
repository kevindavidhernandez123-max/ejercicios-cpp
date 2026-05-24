/*. Cuando la suma de los dígitos alternos de un número son iguales, ese número es exactamente divisible por once. Por ejemplo 5841 :
5 + 4  = 8 + 1
Por lo tanto el número 5841 es divisible por once.
2. Un número se dice automórfico si su cuadrado termina en los mismos dígitos que el número original, por ejemplo 76^2 = 5776. 
Un número se dice trimórfico si su cubo termina en los mismos dígitos que el número original, por ejemplo 49^3 = 117649. 

Escriba un programa en C que determine los números automórficos y trimórficos menores que 1000.

3. Generar todos los números divisibles por 11 en hasta un valor dado por el usuario. Tenga en cuanta que antes de 11 ningún número es divisible por 11

*/
#include<iostream>
using namespace std;
int main(){
	
   int N;
   int cop,cop2;
   int sumapar=0,sumaim=0;
   int dig,posicion;
   cout<<"ingrese hasta que cantidad se desea comprobar que un numero es divisible por 11"<<endl;
   cin>>N;
   
   
   
   for(int i=11; i<=N; i++){
   	cop=i;
   	cop2=i;
   	  posicion=1;
   	  sumapar=0;
   	  sumaim=0;
   	  for(;cop>0;){
   	  	
   	  	  
   	  	dig=cop%10;
   	  	
   	  	if(posicion%2==0){
   	  		
   	  		sumapar+=dig;
			 }
			 
   	  	else{
   	  		sumaim+=dig;
			 }
   	  	
   	  	
   	  	cop=cop/10;
   	  	posicion++;
		 }
   	
   		if(sumapar==sumaim){
   		
   		cout<<" el numero "<<i<<" es divisible por 11"<<endl;
   		 
	   }
	   
	}
   	
   	
   	return 0;
   }
   
   
   
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	

