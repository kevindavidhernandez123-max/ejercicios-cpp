/*Una empresa necesita llevar el control de los sueldos de sus empleados.
Haz un programa en C++ con el siguiente menú:

Registrar sueldo de un empleado.
Consultar el total de sueldos pagados.
Mostrar el sueldo más alto y el más bajo.
Calcular el promedio de sueldos.
Salir.
? Requisitos:
Usa funciones con parámetros por referencia.
No se aceptan sueldos negativos ni iguales a cero.
Usa acumuladores, máximos, mínimos y contadores.
*/
#include<iostream>
using namespace std;
long sueldo_total=0;
long sueldo_mayor=0;
string nombre_mayor;
string nombre_menor;
long sueldo_menor;
int acu=0;
void sueldos(int &sueldo, string &nombre){
	
	cout<<"ingrese su nombre"<<endl;
	getline(cin, nombre);
	cin.ignore();
	cout<<"ingrese su sueldo"<<endl;
	cin>>sueldo;
	sueldo_total+=sueldo;
	if(sueldo>sueldo_mayor){
		sueldo_mayor=sueldo;
		nombre_mayor=nombre;
	}
	sueldo_menor=sueldo;

	if(sueldo<=sueldo_menor){
		sueldo_menor=sueldo;
		nombre_menor=nombre;
	}
	else{ 
	sueldo_menor=sueldo;
	}
	acu++;
}

void total(){
	cout<<"el total de sueldos pagados es de"<<sueldo_total<<endl;
	
}
void mejores(){
	cout<<"el sueldo mayor es "<<sueldo_mayor;
	cout<<" y su sueldo es de "<<nombre_mayor;
	cout<<"\nel sueldo menor es "<<sueldo_menor;
	cout<<" y su nombre es "<<nombre_menor;
}
void promedio(){
	float prom;
	prom=sueldo_total/acu;
	cout<<"el promedio de sueldos pagados es"<<prom;
	
	
}

int main(){
	int sueldo=0;
	string nombre;
	int opc;
	
do{
	cout<<"BIENVENIDO A SU MENU VIRTUAL"<<endl;
	cout<<"1. ingresar sueldo "<<endl;
	cout<<"2. consultar el total de empleados pagados"<<endl;
	cout<<"3. sueldo mas alto y sueldo mas bajo"<<endl;
	cout<<"4. consultar promedio de los sueldos"<<endl;
	cout<<"5. salir"<<endl;
	cout<<"ingrese una opcion"<<endl;
	cin>>opc;
	
	switch(opc){
		
		case 1:{
			sueldos(sueldo,nombre);
			break;
		}
			
		case 2:{
			total();
			break;
		}
		case 3:{
			mejores();
			break;
		}
		case 4:{
			promedio();
			break;
		}
		case 5:{
			
			break;
		}
	}
	
	
	
}while(opc!=5);
	
	
	
}
