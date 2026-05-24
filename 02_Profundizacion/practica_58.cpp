#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


void filtrar_estudiantes(const string& archivo_entrada, const string& archivo_salida) {
    ifstream archivo_csv(archivo_entrada.c_str());
    if (!archivo_csv.is_open()) {
        cerr << "Error: No se pudo abrir el archivo de entrada " << archivo_entrada << endl;
        return;
    }

    
    ofstream archivo_aprobados(archivo_salida.c_str());
    if (!archivo_aprobados.is_open()) {
        cerr << "Error: No se pudo crear el archivo de salida " << archivo_salida << endl;
        archivo_csv.close();
        return;
    }

    string linea;
    int total_estudiantes = 0;
    int estudiantes_aprobados = 0;

    while (getline(archivo_csv, linea)) {
        if (linea.empty()) continue; // saltar líneas vacías

        total_estudiantes++;

        stringstream ss(linea);
        string nombre, apellido, nota_str;

        if (getline(ss, nombre, ',') &&
            getline(ss, apellido, ',') &&
            getline(ss, nota_str)) {

            
            float nota;
            stringstream ssnota(nota_str);
            if (!(ssnota >> nota)) {
                cerr << "Advertencia: Error de formato en la nota de la línea: " << linea << endl;
                continue;
            }

           
            if (nota >= 3.0f) {
                archivo_aprobados << linea << endl;
                estudiantes_aprobados++;
            }
        } else {
            cerr << "Advertencia: La línea no tiene el formato esperado: " << linea << endl;
        }
    }

    archivo_csv.close();
    archivo_aprobados.close();

    cout << "\n--- Resumen del proceso ---" << endl;
    cout << "Total de estudiantes procesados: " << total_estudiantes << endl;
    cout << "Estudiantes aprobados (nota >= 3.0): " << estudiantes_aprobados << endl;
    cout << "Datos guardados en: " << archivo_salida << endl;
}

int main() {

    ofstream ofs("estudiantes.csv");
    if (!ofs.is_open()) {
        cerr << "Error: No se pudo crear estudiantes.csv" << endl;
        return 1;
    }

    ofs << "Luis,Perez,3.5" << endl;  
    ofs << "Ana,Gomez,4.7" << endl;   
    ofs << "Carlos,Ruiz,2.8" << endl; 
    ofs << "Maria,Lopez,5.0" << endl; 
    ofs << "Javier,Diaz,1.9" << endl; 
    ofs.close();

    
    filtrar_estudiantes("estudiantes.csv", "aprobados.csv");

    return 0;
}

