#include<iostream>
#include<fstream>
#include<string>
//crea un archivo de texto llamado"materias.txt" 
//donde ingreses las materias que te toca
 //ver los dias miercoles
 //(una por cada linea y
 // luego revisa el archivo de texto que se creo
 using namespace std;
 
 void llamado(){
 	ofstream archivo;
 	string texto;
 	archivo.open("materias.txt");
 	
 if	(archivo.fail()){
 		exit(1);
	 }
	  cout<<"ingrese las materias que te tocan el dia miercoles"<<endl;
	  cout<<"escriba salir si no desea procesar mas materias"<<endl;
	 while(true){
	
	 cout<<"materia: ";
	 getline(cin,texto);
	
	 if(texto=="salir"){
	 	
	 	break;
	 }
	 archivo<<texto<<endl;
	 }
	  archivo.close();	
 }
 
 int main(){
 	
 	llamado();
 	
 	return 0;
 }
