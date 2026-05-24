#include <iostream>
using namespace std;
int main(){
	float articulo,pagar,descuento;
	cout<< "escribir el precio del producto: ";
	cin>>articulo;
	if (articulo<2000)
	{
		descuento= 0;
			cout<<"no obtiene descuento"<<endl;}
	
	 else if(articulo<=10000)
	{cout<<"obtuvo un descuento del 10% ";
	descuento= 0.10;  }
	else if(articulo<=25000)
	{cout<<"obtuvo un descuento del 20% ";
	descuento= 0.20;
	}
	
	else if(articulo<=40000)
	{ descuento= 0.30;
	cout<<"obtuvo un descuento del 30% ";}
	else if(articulo<=55000)
	{
	cout<<"obtuvo un descuento del 40% ";
	descuento= 0.40; }
	else
  {descuento= 0.50;
	cout<<"obtuvo un  descuento del 50% "; 
	}
	pagar=articulo-(articulo*descuento);
	cout<<"el precio del producto es "<<pagar;
	
	
	
	
	
	
	
	
	
    
		
	
	
	return 0;
}


