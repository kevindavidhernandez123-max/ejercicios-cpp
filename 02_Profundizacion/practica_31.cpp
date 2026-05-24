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
system("cls");
	cout<<"ingrese su nombre"<<endl;
	cin.ignore();
	getline(cin,nombre);
	do{
	
	cout<<"ingrese su sueldo"<<endl;
	cin>>sueldo;
	if(sueldo<=0){
		cout<<" ERROR INGRESE UN SUELDO MAYOR A 0"<<endl;
	}
	}while(sueldo<=0);
	sueldo_total+=sueldo;
	if(sueldo>sueldo_mayor){
		sueldo_mayor=sueldo;
		nombre_mayor=nombre;
	}
	if(acu==0){
	
	sueldo_menor=sueldo;

}
	if(sueldo<sueldo_menor){
		sueldo_menor=sueldo;
		nombre_menor=nombre;
	}
	
	acu++;
}

void total(){
	system("cls");
	cout<<"el total de sueldos pagados es de"<<sueldo_total<<endl;
	
}
void mejores(){
	system("cls");
	cout<<"el sueldo mayor es "<<sueldo_mayor;
	cout<<" y su sueldo es de "<<nombre_mayor;
	cout<<"\nel sueldo menor es "<<sueldo_menor;
	cout<<" y su nombre es "<<nombre_menor<<endl;
}
void promedio(){
	system("cls");
	float prom;
	prom=sueldo_total/acu;
	cout<<"el promedio de sueldos pagados es "<<prom<<endl;
	
	
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
			
			sueldos(sueldo, nombre);
				
			break;
			
		}
			
		case 2:{
			if(acu==0){
				cout<<"ERROR NO HAY SUELDOS REGISTRADOS"<<endl;
			}
			else{
			
			total();
			
			}
			break;
		}
		case 3:{
			if(acu==0){
				cout<<"ERROR NO HAY SUELDOS REGISTRADOS"<<endl;
			}
			else{
			
			mejores();
			
			}
			break;
		}
		case 4:{
			if(acu==0){
				cout<<"ERROR NO HAY SUELDOS REGISTRADOS"<<endl;
			}else{
			
			promedio(); }
			break;
		}
		case 5:{
			
			break;
		}
	}
	
	
	
}while(opc!=5);
	
}
