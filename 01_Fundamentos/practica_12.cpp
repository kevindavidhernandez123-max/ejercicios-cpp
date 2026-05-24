#include<iostream>
using namespace std;
int main(){
	

	int cant,pu;
	long total_compra, desc;
	int genero, cantante;
	setlocale(LC_ALL, "spanish");
	cout<<"DISCOS ABC";
	cout<<"1.Musica Ranchera"<<endl;
	cout<<"2.musica Norteña"<<endl;
	cout<<"3.balada "<<endl;
	cout<<"4.Salida "<<endl;
	cout<<"Selecciona el genero musical ";
	cin>>genero;
	if(genero <1 || genero>4){
		cout<<"Genero seleccionado es incorrecto, no esta definido en el menu"<<endl;
		
	}
	
	
	switch(genero){
		
		case 1: cout<<"Cantantes del Genero de Musica Ranchera"<<endl;
		        cout<<"Cantante               precio CD"<<endl;
		        cout<<"1. V Fernandez           $200"<<endl;
		        cout<<"2. A. Fernandez          $180"<<endl;
		        cout<<"3. Pedro Fernandez       $150"<<endl;
		        cout<<"seleccione un cantante: ";
		        cin>>cantante;
		        if(cantante <1 || cantante >3){
		        	cout<<"Cantante Seleccionado no esta disponible"<<endl;
		        	
				}
				else{
					
					switch(cantante){
						case 1: pu=200; break;
						case 2: pu=180; break;
						case 3: pu=150; break;
					}
				}
		break;
		case 2: //norteña
		cout<<"Cantantes del Genero de Musica Norteña"<<endl;
		        cout<<"Cantante               precio CD"<<endl;
		        cout<<"1. tigres del Norte      $190"<<endl;
		        cout<<"2. Tucanes del T          $195"<<endl;
		        cout<<"3. tiranos del norte      $140"<<endl;
		        cout<<"seleccione un cantante: ";
		        cin>>cantante;
		        if(cantante <1 || cantante >3){
		        	cout<<"Cantante Seleccionado no esta disponible"<<endl;
		        	
				}
				else{
					
					switch(cantante){
						case 1: pu=190; break;
						case 2: pu=195; break;
						case 3: pu=140; break;
					}
				}
		
		
		break;
		case 3: 
		cout<<"Cantantes del Genero de Musica Norteña"<<endl;
		        cout<<"Cantante               precio CD"<<endl;
		        cout<<"1. tigres del Norte      $220"<<endl;
		        cout<<"2. Tucanes del T          $170"<<endl;
		        cout<<"3. tiranos del norte      $185"<<endl;
		        cout<<"seleccione un cantante: ";
		        cin>>cantante;
		        if(cantante <1 || cantante >3){
		        	cout<<"Cantante Seleccionado no esta disponible"<<endl;
		        	
				}
				else{
					
					switch(cantante){
						case 1: pu=220; break;
						case 2: pu=170; break;
						case 3: pu=185; break;
					}
				}
		
		
		break;
		
		
	}
	
	cout<<"Cantidad de Cd's a comprar: ";
	cin>>cant;
	
	total_compra=cant*pu;
	if(cant<5){
		desc=0;
		}
	else if(cant>=5 && cant<15){
		desc=total_compra*0.10;
		}
		else if(cant<=30){
		desc = total_compra*0.2;
		} 
		else{
		desc=total_compra*0.3;
	}		
	
	cout<<"Total de la compra: $"<<total_compra<<endl;
	cout<<"descuento aplicado: $"<<desc<<endl;
	cout<<"Total a pagar: $"<<total_compra-desc<<endl;
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
