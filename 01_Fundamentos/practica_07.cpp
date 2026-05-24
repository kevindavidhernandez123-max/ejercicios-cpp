#include<iostream>
using namespace std;

int main(){
	
	int valor,vuelto,saldo,opc,precio,mil;
	
	cout<<"ingrese el valor del dinero en monedas:"<<endl;
	cin>>valor;
	if((valor>=200) && (valor<=3000))  
	{
	if(valor% 100==0 ){
	
	cout<<"bienvenido al dispensador de comida el puente"<<endl;
	cout<<"1. papas fritas $1200 "<<endl;
	cout<<"2. sandwich combinado $2500 "<<endl;
	cout<<"3. pescadito $1800 "<<endl;
	cout<<"4. empanadas $1700 "<<endl;
	cout<<"5. arepa $2000 "<<endl;
	cout<<"6. gaseosa $1600"<<endl;
	cout<<"7. vaso de Te $1000 "<<endl;
	cout<<"8. dulce $200 "<<endl;
	cout<<"9. salir"<<endl;
    cout<<"ingrese su opcion con un numero"<<endl;
    cin>>opc;
    
	}
    
	
	
	switch(opc){
		case 1: precio=1200;break;
		case 2: precio= 2500;break;
		case 3: precio= 1800;break;
		case 4: precio= 1700;break;
        case 5: precio= 2000;break;	
		case 6: precio= 1600;break;
		case 7: precio= 1000;break;
		case 8: precio= 200;break;
		case 9: cout<<"vuelve pronto";break;
	}
	
	if(opc!=9){
	

	if(valor>=precio){
		cout<<"!Producto Entregado!"<<endl;
	vuelto=valor-precio;
	cout<<"VUELTO PARA RETIRAR:"<<endl;

if (vuelto >= 1000) {
	cout<<(vuelto/1000)<<"moneda de $1000"<<endl;
	vuelto%=1000;
	
	}
	if (vuelto >= 500) {
	cout<<(vuelto/500)<<"moneda de $500"<<endl;
	vuelto%=500;
	
	}
     if (vuelto >= 200) {
	cout<<(vuelto/200)<<"moneda de $200"<<endl;
	vuelto%=200;
	
	}
	if (vuelto >= 100) {
	cout<<(vuelto/100)<<"moneda de $100"<<endl;
	vuelto%=100;
	
	}
	
	}
	
	else{
		cout<<"saldo insuficiente";
	}
	
	
	}
	
	}
	return 0;
}



