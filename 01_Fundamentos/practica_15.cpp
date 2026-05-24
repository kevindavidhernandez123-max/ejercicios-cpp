#include<iostream>
using namespace std;
int main(){
 
 int N,exp=0,digito,cop2;
 int cop,pot=1;
 long suma=0;
   cout<<"ingrese el rango maximo que desea abarcar";
   cin>>N;
   
   
   for(int i=1; i<=N; i++){
   	suma=0;
   	cop=i;
   	exp=0;
   	cop2=i;
   	do{
	   
   	   exp++;
   	    cop/=10;
	   }while(cop>0);
         cop=cop2;
   		for(; cop>0;){
		   
   		pot=1;
   		digito=cop%10;
   		for(int x=1; x<=exp; x++)
   	{
	   
   		pot*=digito;
   	    
		   }
		   suma+=pot;
		   cop/=10;
		   } 
		   cop=cop2;
		   if(suma==cop){
		   	cout<<cop2<<" es un numero narcisista"<<endl;
		   }
		   
		   
		   
   }

   
   return 0;
   }
