/*5. Desarrollar un programa muestre el listado o menú de categorías de peliculas para que el usuario seleccione el tipo de película a alquilar.
 Calcular  y mostrar el total a pagar por el cliente
Para calcular el total a pagar se debe sumar el precio alquiler de la película más el valor del recargo multiplicado por el número de días de atraso 
en la devolución de la película.
CODIGO          CATEGORIA                PRECIO           RECARGO/DIA DE ATRASO
1                      FAVORITOS                 $2500               $500
2                      NUEVOS                      $3000               $750
3                      ESTRENOS                  $3500               $1000
4                      SUPER ESTRENOS     $4000               $1500

Se solicita adicionalmente los siguientes datos:
Indicar la cantidad de clientes de cada categoría que alquilaron película·        
Total recaudado y total de clientes·        
Porcentaje de clientes que solicitaron películas de súper entrenos·        
Cuál es la cantidad de días de atraso mayor y menor para la devolución de películas, indicando el nombre del cliente?
Total recaudado por días de atraso en la entrega de la película*/
#include<iostream>
#include<string>
using namespace std;
int main(){
	int opc,atraso,cliente=0;
	int cont=0,cont1=0,cont2=0;
	float cont3=0;
	int torre=1;
	long long max=0, min=99999999;
	long recar,suma=0,suma_2=0;
	string nombre,nombre2,nombre3;
	long total_p=0,valor;
	setlocale(LC_ALL, "spanish");
	do{
	       cout<<"        bienvenido a su menu de peliculas   "<<endl;
	       
	    
	       cout<<"ingrese su nombre "<<endl;
	       cin.ignore(); 
	        getline(cin,nombre);
	cout<<"codigo "<<"categoria "<<" PRECIO "<<" Dia de atraso";
	cout<<"\n1 "<<"     FAVORITOS"<<"  $2500"<<"    $500";
	cout<<"\n2 "<<"       NUEVOS"<<"  $3000"<<"    $750";
	cout<<"\n3 "<<"      ESTRENOS"<<"  $3500"<<"    $1000";
	cout<<"\n4 "<<"   SUPER ESTRENOS"<<"  $4000"<<"    $1500";
	cout<<"\ningrese su opcion ";
	cin>>opc;
	
	system("cls");
	cliente++;
	switch(opc){
		
		
		case 1:  
		cout<<"\ncuantos dias de atraso para cancelar la pelicula?";
		cin>>atraso;
		 valor=2500;
		 recar=atraso*500;
		 cont++;
		break;
		case 2:
			cout<<"\ncuantos dias de atraso para cancelar la pelicula?";
		cin>>atraso;
			valor=3000;
			recar=atraso*750;
			cont1++;
			break;
			
		case 3:
		cout<<"\ncuantos dias de atraso para cancelar la pelicula?";
		cin>>atraso; valor=3500;
		recar=atraso*1000;
		cont2++;
		break;
		
		case 4: 
		cout<<"\ncuantos dias de atraso para cancelar la pelicula?";
		cin>>atraso;
		valor=4000;
		recar=atraso*1500;
		cont3++;
		break;
		
	}
	
	
	if(atraso>max){
		max=atraso;
		nombre2=nombre;
	}
	if(atraso<min){
		
		min=atraso;
		nombre3=nombre;
	}
	total_p=valor+recar;
		if(atraso>0){
		suma_2+=total_p;
		
			}
	suma+=total_p;
	cout<<"\nel total a pagar es de"<<total_p;
	cout<<"\ndesea procesar otro cliente?";
	cout<<"\n1 para si ";
	cout<<"\n2 para no ";
	cin>>torre;
	}while(torre==1);
	cout<<"la cantidad de clientes que ingresaron para favoritos fue de "<<cont<<endl;
	cout<<"la cantidad de clientes que ingresaron para nuevos fue de "<<cont1<<endl;
	cout<<"la cantidad de clientes que ingresaron para estrenos fue de "<<cont2<<endl;
	cout<<"la cantidad de clientes que ingresaron para super estrenos fue de "<<cont3<<endl;
	cout<<"el total recaudado fue de "<<suma<<endl;
	cout<<"total clientes fue de: "<<cliente<<endl;
	cout<<"porcentaje de clientes que ingresaron a peliculas de super estreno fue de "<<cont3/cliente*100<<"%"<<endl;
	cout<<"la cantidad de dias de atraso mayor registrado por un cliente es de "<<max<<" y su nombre es "<<nombre2<<endl;
	cout<<"la cantidad de dias de atraso menor registrado por un cliente es de "<<min<<" y su nombre es "<<nombre3<<endl;
	cout<<"el total recaudado por dias de atraso de la pelicula fue de "<<suma_2;
	
	return 0;
}
