#include<iostream>
using namespace std;
int main(){
	int venta,total_p;
	cout<<"ingrese el numero de ventas realizadas ";
	cin>>venta;
	
	if(venta>10){
		venta=venta*450+(venta-10)*250;
	}
	else{
		venta*=450;
	}
cout<<"\nel total a pagar para el vendedor es de "<<venta;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
