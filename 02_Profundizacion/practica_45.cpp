#include<iostream>
#include<string>
using namespace std;

struct ciudad{
	   string nombre;
	   int edad;
	   string ciudades;
	
};

void filtrar(ciudad filtro[],string &lugar ,int &N){
	bool encontrar=false;
	for(int x=0; x<N; x++){
		if(lugar==filtro[x].ciudades){
			cout<<"persona N°"<<x+1<<endl;
			cout<<"ciudad: "<<filtro[x].ciudades<<endl;
			cout<<"su nombre es: "<<filtro[x].nombre<<endl;
			cout<<"su edad es: "<<filtro[x].edad<<endl;
			encontrar=true;
		}
		
	}
	
	if(encontrar==false){
		cout<<"\nno se encontraron personas en esta ciudad";
	}
	
}
int main(){
	int N;
	string lugar;
	cout<<"ingrese la cantidad de personas ";
	cin>>N;
	setlocale(LC_ALL,"spanish");
	ciudad filtro[N];
	cin.ignore();
	for(int x=0; x<N; x++){
		
		cout<<"persona N°"<<x+1<<endl;
		
		cout<<"ingrese su nombre ";
		getline(cin,filtro[x].nombre);
		
		cout<<"ingrese su edad ";
		cin>>filtro[x].edad;
		cin.ignore();
		cout<<"ingrese el nombre de su ciudad ";
		getline(cin, filtro[x].ciudades);
	}
	
	
	cout<<"ingrese el nombre de la ciudad a buscar ";
	getline(cin, lugar);
	filtrar(filtro,lugar,N);
	
	
	return 0;
}

