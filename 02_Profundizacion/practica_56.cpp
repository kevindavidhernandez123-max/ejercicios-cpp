#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Persona{
	
	
	string materia_1="matematica discretas";
	string materia_2="programacion";
	
};



int main(){
	
	Persona p;
	
	
	ofstream variable_archivo("copia.txt");
	if(!variable_archivo.is_open()){
		
		cout<<"Error\n";
		
		return 1;
	}
	
	variable_archivo<<p.materia_1<<endl;
	variable_archivo<<p.materia_2<<endl;
	
	variable_archivo.close();
	
	cout<<"Guardado exitosamente";
	return 0;
	
	
	
	
	
	
	
}
