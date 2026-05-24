#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numeroUsuario;

    // --- PASO 1: EL USUARIO DECIDE QUÉ GUARDAR ---
    cout << "Escribe un numero secreto para guardar en el disco: ";
    cin >> numeroUsuario;

    // Abrimos archivo para ESCRIBIR (Output) en Binario
    ofstream salida("secreto.bin", ios::binary);
    
    if(salida) {
        // Escribimos el bloque de memoria exacto (4 bytes)
        salida.write(reinterpret_cast<char*>(&numeroUsuario), sizeof(int));
        salida.close();
        cout << "-> Datos guardados en 'secreto.bin'." << endl;
    }

    cout << "\n... Simulando que cerramos y abrimos el programa ...\n" << endl;

    // --- PASO 2: RECUPERAR EL DATO DEL DISCO ---
    int datoRecuperado = 0; // Variable vacía

    // Abrimos archivo para LEER (Input) en Binario
    ifstream entrada("secreto.bin", ios::binary);

    if(entrada) {
        // Leemos los bytes del disco y llenamos la variable
        entrada.read(reinterpret_cast<char*>(&datoRecuperado), sizeof(int));
        entrada.close();
        
        cout << "-> ¡Magia! El numero recuperado del archivo es: " << datoRecuperado << endl;
    }

    return 0;
}
