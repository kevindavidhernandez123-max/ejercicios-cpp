#include<iostream>
#include<string>
using namespace std;

//.Ordenar por nombre:
//Ordene alfabéticamente las personas según su nombre (usando comparación de
//cadenas
struct ordeno{
	string nombre;
};

void ordenamiento(ordeno nom[], int &N){
	string cop;
	for(int x=0; x<N-1; x++){
		
		for(int j=x+1; j<N; j++){
			
			if(nom[x].nombre>nom[j].nombre){
				cop=nom[x].nombre;
				nom[x].nombre=nom[j].nombre;
				nom[j].nombre=cop;
			}
		}
	}
	cout<<"los nombres ordenados alfabeticamente son ";
	for(int x=0; x<N; x++){
		cout<<"\n"<<nom[x].nombre;
	}
	
}
int main(){
	int N;
	setlocale(LC_ALL,"spanish");
	cout<<"ingrese la cantidad de personas: ";
	cin>>N;
    cin.ignore();
	ordeno nom[N];
	for(int x=0; x<N; x++){
		
		cout<<"persona N°"<<x+1<<endl;
		cout<<"ingrese su nombre: ";
		getline(cin,nom[x].nombre);
		
	}
	
	ordenamiento(nom,N);
	return 0;
}
