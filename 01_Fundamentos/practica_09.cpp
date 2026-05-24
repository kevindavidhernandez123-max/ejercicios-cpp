#include<iostream>
using namespace std;
int main(){
//1.     Todos los lunes, miércoles y viernes, una persona corre la misma ruta y cronometra los tiempos obtenidos.
// Desarrollar un programa que permita calcular el tiempo promedio que la persona tarda en recorrer la ruta en una semana cualquiera.
float lunes,miercoles,viernes,prom;

cout<<"ingrese el tiempo obtenido para el lunes: ";
cin>>lunes;

cout<<"ingrese el tiempo obtenido para el miercoles: ";
cin>>miercoles;
cout<<"ingrese el tiempo obtenido para el viernes: ";
cin>>viernes;
prom=(lunes+miercoles+viernes)/3;
cout<<"el tiempo promedio que demoraste en recorrer la ruta de la semana fue: "<<endl<<prom;


return 0;
}
