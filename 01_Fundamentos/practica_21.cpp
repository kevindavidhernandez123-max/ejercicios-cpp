//. Cuando la suma de los dígitos alternos de un número son iguales, 
//ese número es exactamente divisible por once. Por ejemplo 5841 :
//5 + 4  = 8 + 1
//Por lo tanto el número 5841 es divisible por once.
//3564 = 3+6 = 5+4 
//Por lo tanto el número 3564 es divisible por once.
#include<iostream>
using namespace std;
int main(){
	
	int N,cop,x=0,copia,copia2; 
	int par,dig,dig2=0,dig3=0;
	long suma=0, suma2=0;
	cout<<"ingrese un numero ";
	cin>>N;
	
		cop=N;
		cout<<"los digitos alternos son: "<<endl;
	for(int i=1; i<=N; i++){
	
		
		for(; cop>0;){
			suma2=suma;
			
			suma=0;
			dig=cop/=10;
			if(dig%2==0){
				dig2=dig;
			
			}
			
			else{
				dig3=dig;
				
					
			}
	         if(dig2>0 && dig3>0)
				{
					
				suma=dig2+dig3;
			
			
			}
		
				cop/=N;
		
			
	}
				
		
		}
	
		
		if(suma==suma2){
		
	cout<<"\npor lo tanto es divisible entre 11";
		}
		else{
				cout<<"\npor lo tanto no es divisible entre 11";
			
		}
		
	
	
	
	
	
	
	
	
	
	return 0;
}
