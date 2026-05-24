#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> 

using namespace std;

void copia(){
    
    
    ofstream archivo_destino;
    archivo_destino.open("copia.txt");
    
   
    ifstream archivo_origen;
    archivo_origen.open("materias.txt");
    
    
    if(archivo_destino.fail() || archivo_origen.fail()){
        cout << "Error: No se pudo abrir alguno de los archivos." << endl;
        exit(1);
    }
    
  
    string transporte; 
    
  
    while(getline(archivo_origen, transporte)){
        
        archivo_destino << transporte << endl;
    }
    
    
    archivo_origen.close();
    archivo_destino.close();
    
    cout << "Copia realizada con exito." << endl;
}

int main(){
    
    copia();
    
    return 0;
}
