#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Persona{
	
	string materia_1;
	string materia_2;
	
};

int main(){
	
	Persona p;
	
	ifstream variable_archivo("copia.txt");
	
	if(!variable_archivo.is_open()){
		cout<<"Error\n";
		return 1;
	}
	
	getline(variable_archivo,p.materia_1);
	getline(variable_archivo, p.materia_2);
	
	cout<<p.materia_1<<endl;
	cout<<p.materia_2<<endl;
	
	return 0;
	
}
