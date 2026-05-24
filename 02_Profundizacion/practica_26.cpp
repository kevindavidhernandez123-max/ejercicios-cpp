
int cont=1;

int incremento(){
	cont++;
	return cont ;
}
 
 int segundo(){
    cont+=2;
    return cont;
 }


#include<iostream>
using namespace std;
int main(){
	cout<<"el valor inicial de la variable es "<<cont<<endl;
	cout<<"en el primer incremento es de "<<incremento()<<endl;
	cout<<"en el segundo incremento es de "<<segundo()<<endl;
	
	return 0;
}
