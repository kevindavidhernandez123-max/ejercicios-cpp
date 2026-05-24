/*Un par de números m y n son llamados par amigable, si la suma de todos los divisores de m (excluyendo m ) es igual al número n 
y la suma de todos los divisores del número n (excluyendo n) es igual a m (m ¹n).
Por ejemplo, los numeros 220 y 284 son un par amigable porque los únicos números
que dividen de forma excacta a 220 son 1,2,4,5,10,11,20,22,44,55 y 110, y 1+ 2 + 4 + 10 + 11 + 20 + 22 + 44 + 55 + 110 =  284

Los números que dividen a 284 son 1,2,4,71 y 142, y   1+ 2 + 4 + 71 + 142 = 220
Por lo tanto 220 y 284 son un par amigable.
Escriba un programa en C que ingrese m y n , asegure que m es distinto de n  y determine si dichos  números son par amigable.*/
#include<iostream>
using namespace std;
int main(){
	
	int M,N;
	int power;
	int divi,cop,cop2;
	long suma=0,suma2=0;
	do{
	
	cout<<"ingrese el valor de m: ";
	cin>>M;
	cout<<"\ningrese el valor de n: ";
	cin>>N;
	if(M==N){
		cout<<"\nerror no puede ingresar 2 numeros iguales "<<endl;
	}
	}while(M==N);
	
	for(int i=1;i<M; i++)
	{
		cop=0;
		if(M%i==0){
			cop=i;
			
		}
		
		suma=suma+cop;
		
		
	}
	
	
	for(int x=1;x<N; x++)
	{
		cop2=0;
		if(N%x==0){
			cop2=x;
		
		}
		
		suma2+=cop2;
	
		
	}
	
	if(suma==N && suma2==M ){
		
		cout<<M<<" Y "<<N<<" SON UN PAR AMIGABLE";
		
		
	}
	
	else{
			cout<<M<<" Y "<<N<<" NO SON UN PAR AMIGABLE";	}
	
	
	
	
	
	return 0;
}
