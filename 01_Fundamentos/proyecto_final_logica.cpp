#include <iostream>
#include <iomanip>
#include <locale.h>
using namespace std;

const int MAX_CALLS = 100; //Constante que indica el número máximo de llamadas que se pueden registrar

int main()
{
    setlocale(LC_ALL, "spanish"); //Configura la salida en español para poder mostrar tildes y caracteres especiales

    int op, op2, n; //opciones de los menús y cantidad de llamadas a registrar

    string nombre_funcionario[MAX_CALLS]; //vector para almacenar el nombre de cada funcionario
    int oficina[MAX_CALLS]; //vector para almacenar la oficina a la que pertenece cada funcionario
    int minutos[MAX_CALLS]; //vector para almacenar la cantidad de minutos que duró cada llamada
    int tipo_llamada[MAX_CALLS]; //vector para almacenar el tipo de llamada realizada por cada funcionario
    int total_llamadas = 0; //contador para registrar cuántas llamadas se han ingresado en total

    string nombres_oficina[3] = {"Logística", "RH", "Financiero"}; //vector con los nombres de las oficinas
    int tarifas[3] = {80, 800, 1500}; //vector con las tarifas por minuto de cada tipo de llamada: local, celular e internacional
    
    
        system("color 1F"); 
        
cout << "==============================================================\n";
cout << setw(40) << "ASIGNATURA: ALGORITMOS Y PROGRAMACIÓN" << endl;
cout << "--------------------------------------------------------------\n";
cout << setw(34) << "PROYECTO FINAL" << endl;
cout << setw(50) << "SISTEMA DE CONTROL DE LLAMADAS - IM&EX S.A." << endl;
cout << "--------------------------------------------------------------\n";
cout << "Este programa permite registrar, consultar y generar\n";
cout << "estadísticas de las llamadas realizadas por los funcionarios\n";
cout << "de las oficinas de la empresa IM&EX S.A., según tipo, oficina\n";
cout << "y duración. Utiliza únicamente arreglos unidimensionales y\n";
cout << "bidimensionales como estructura de almacenamiento.\n";
cout << "--------------------------------------------------------------\n";

system("pause");       
system("color 07");    
system("cls");         

    cout << endl;          


    do //inicio del ciclo principal del programa
    {
        //Menú principal de opciones
        do
        {
        	cout<<"\tIM&EX S.A. "<<endl; 
			cout<<"CONTROL DE LLAMADAS – CENTRO DE COMUNICACIONES"<<endl;
	        cout<<"1. Registro de llamadas"<<endl;
	        cout<<"2. Reportes"<<endl;
	        cout<<"3. Estadísticas"<<endl;
	        cout<<"4. Salir"<<endl;
	        cout<<"Seleccione una opción: ";
	        cin>>op;
	        if(op > 4 || op < 1)
	        {
				cout<<"\nERROR: OPCION INVALIDA\n\n";
			}
		}while(op > 4 || op < 1);

        system("cls"); 
        switch (op) //evaluar la opción seleccionada
        {
	        case 1: //opción para registrar llamadas
	        {
	            cout<<"\n¿Cuántas llamadas desea registrar?: ";
	            cin>>n; //cantidad de llamadas a registrar
	            cin.ignore(); //limpiar buffer
	            system("cls"); 
	            for (int i=0; i<n; i++) //ciclo para registrar cada llamada
	            {
	                cout<<"Registro llamada #"<<i + 1<<endl;
	                string nombre;
	                int encontre;
	            	cout<<"Nombre del funcionario: ";
					getline(cin, nombre_funcionario[total_llamadas + i]); //guardar el nombre nuevo
	
	                do //validar que la oficina esté entre 1 y 3
	                {
	                    cout<<"Oficina (1: Logística, 2: Recursos Humanos, 3: Financiero): ";
	                    cin>>oficina[total_llamadas + i];
	                    if(oficina[total_llamadas + i] > 3 || oficina[total_llamadas + i] < 1)
	                    {
							cout<<"\nERROR: OFICINA INVALIDA\n\n";
						}
	                }while(oficina[total_llamadas + i] > 3 || oficina[total_llamadas + i] < 1);
	
	                do //validar el tipo de llamada
	                {
	                    cout<<"Tipo de llamada (1: Local, 2: Celular, 3: Internacional): ";
	                    cin>>tipo_llamada[total_llamadas + i];
	                    if(tipo_llamada[total_llamadas + i] > 3 || tipo_llamada[total_llamadas + i] < 1)
	                    {
	                        cout<<"\nERROR: TIPO DE LLAMADA INVALIDA\n\n";
	                    }
	                }while(tipo_llamada[total_llamadas + i] > 3 || tipo_llamada[total_llamadas + i] < 1);
	                
	                do //validar que los minutos no superen el máximo permitido
	                {
	                    cout<<"Cantidad de minutos de la llamada (máx 30 minutos): ";
	                    cin>>minutos[total_llamadas + i];
	                    if (minutos[total_llamadas + i] > 30)
	                    {
	                        cout<<"\nERROR: SUPERÓ EL LÍMITE DE MINUTOS\n\n";
	                    }
	                }while(minutos[total_llamadas + i] > 30);
	
	
	                cin.ignore(); //limpiar buffer
	            }
	
	            total_llamadas += n; //actualizamos el contador total de llamadas
	        }
	        break;
	
	        case 2: //menú de reportes
	        {
	            do //validar que la opción seleccionada esté entre 1 y 4
	            {
	                cout<<"\n--- MENÚ DE REPORTES ---\n";
	                cout<<"1. Consulta por oficina"<<endl;
	                cout<<"2. Consulta por tipo de llamada"<<endl;
	                cout<<"3. Consulta por funcionario"<<endl;
	                cout<<"4. Reporte detallado"<<endl;
	                cout<<"Seleccione una opción: ";
	                cin>>op2;
	                if(op2 > 4 || op2 < 1)
	                {
	                    cout<<"\nERROR: OPCION INVALIDA\n\n";
	                }
	            }while(op2 > 4 || op2 < 1);
	
	            //Aquí se ejecutan los distintos tipos de reporte según la opción ingresada
	            if(op2==1) //Reporte por oficina
	            {
	                int cod_oficina;
	                do //validar código
	                {
	                    cout<<"\nIngrese código de oficina (1-Logística, 2-RH, 3-Financiero): ";
	                    cin>>cod_oficina;
	                    if (cod_oficina < 1 || cod_oficina > 3)
	                    {
							cout<<"ERROR: CÓDIGO INVÁLIDO\n";
						}
	                }while(cod_oficina < 1 || cod_oficina > 3);
	
	                int total = 0, monto = 0; //acumuladores de llamadas y monto
	                cout<<setw(25)<<"Funcionario"<<setw(10)<<"Minutos"<<setw(10)<<"Tipo"<<endl;
	                for (int i=0; i <total_llamadas; i++)
	                {
	                    if (oficina[i] == cod_oficina) //si pertenece a la oficina seleccionada
	                    {
	                        cout<<setw(25)<<nombre_funcionario[i]<<setw(10)<<minutos[i]<<setw(10)<<tipo_llamada[i]<<endl;
	                        monto += minutos[i] * tarifas[tipo_llamada[i] - 1]; //sumar el monto
	                        total++; //incrementar el contador
	                    }
	                }
	                cout<<"\nTotal llamadas: "<<total<<" Monto total a pagar: $"<<monto<<endl;
	            }
	
	            if(op2==2) //Reporte por tipo de llamada
	            {
	                int tipo;
	                do
	                {
	                    cout<<"\nIngrese tipo de llamada (1-Local, 2-Celular, 3-Internacional): ";
	                    cin>>tipo;
	                    if (tipo < 1 || tipo > 3)
	                    {
	                        cout<<"ERROR: TIPO INCORRECTO\n";
	                    }
	                } while(tipo < 1 || tipo > 3);
	
	                int llamadas[3]={0}, minutos_total[3]={0}, monto_total[3]={0}; //vectores acumuladores por oficina
	                cout<<setw(25)<<"Funcionario"<<setw(15)<<"Dependencia"<<setw(10)<<"Minutos"<<endl;
	                for (int i=0; i<total_llamadas; i++)
	                {
	                    if (tipo_llamada[i] == tipo)
	                    {
	                        int dep = oficina[i] - 1;
	                        cout<<setw(25)<<nombre_funcionario[i]<<setw(15)<<nombres_oficina[dep]<<setw(10)<<minutos[i]<<endl;
	                        llamadas[dep]++;
	                        minutos_total[dep] += minutos[i];
	                        monto_total[dep] += minutos[i] * tarifas[tipo - 1];
	                    }
	                }
	                cout<<"\nResumen por oficina:\n";
	                for (int i=0; i<3; i++)
	                {
	                    cout<<nombres_oficina[i]<<": "<<llamadas[i]<<" llamadas, "<<minutos_total[i]<<" minutos, $"<<monto_total[i]<<" a pagar"<<endl;
	                }
	            }
	
	            if (op2==3) //Consulta por funcionario
	            {
	                string buscar;
	                cout<<"Ingrese el nombre del funcionario: ";
	                cin.ignore();
	                getline(cin, buscar);
	                int total=0, monto=0; //acumuladores
	                cout<<setw(10)<<"Tipo"<<setw(10)<<"Minutos"<<setw(15)<<"Monto"<<endl;
	                for (int i=0; i<total_llamadas; i++)
	                {
	                    if (nombre_funcionario[i] == buscar)
	                    {
	                        int valor = minutos[i] * tarifas[tipo_llamada[i] - 1];
	                        cout<<setw(10)<<tipo_llamada[i]<<setw(10)<<minutos[i]<<setw(15)<<valor<<endl;
	                        monto += valor;
	                        total++;
	                    }
	                }
	                if (total==0)
	                {
	                    cout<<"No se encontraron llamadas para el funcionario indicado."<<endl;
	                }
	                else
	                {
	                	cout<<"Total llamadas: "<<total<<", Total a pagar: $"<<monto<<endl;
					}
	            }
	
	            if (op2==4) //Reporte detallado por oficina y tipo
	            {
	                int min_oficina[3][3] = {0}, monto_oficina[3] = {0};
	                cout<<setw(15)<<"Oficina"<<setw(25)<<"Funcionario"<<setw(10)<<"Tipo"<<setw(10)<<"Minutos"<<endl;
	                for (int i=0; i<total_llamadas; i++)
	                {
	                    int dep=oficina[i]-1;
	                    cout<<setw(15)<<nombres_oficina[dep]<<setw(25)<<nombre_funcionario[i]<<setw(10)<<tipo_llamada[i]<<setw(10)<<minutos[i]<<endl;
	                    min_oficina[dep][tipo_llamada[i] - 1] += minutos[i];
	                    monto_oficina[dep] += minutos[i] * tarifas[tipo_llamada[i] - 1];
	                }
	                cout<<"\nResumen por oficina: "<<endl;
	                for (int i=0; i<3; i++)
	                {
	                    cout<<nombres_oficina[i]<<": "<<"Local="<<min_oficina[i][0]<<"min, "<<"Celular="<<min_oficina[i][1]<<"min, "<<"Internacional="<<min_oficina[i][2]<<"min, "<<"Total=$"<<monto_oficina[i]<<endl;
	                }
	            }
	        }
	        break;
	
	        case 3: //estadísticas generales
	        {
	            int llamadas_tipo[3] = {0}, minutos_tipo[3] = {0}, monto_tipo[3] = {0}; //vectores para contar la cantidad de llamadas, sumar los minutos y acumular el monto total por cada tipo de llamada (local, celular, internacional)
				int llamadas_oficina_tipo[3][3] = {0}; //matriz para contar la cantidad de llamadas por oficina (filas) y tipo (columnas)
				int llamadas_funcionario[MAX_CALLS] = {0}; //vector para contar cuántas llamadas hizo cada funcionario
				int mayor_llamadas = 0, pos_mayor_funcionario = -1; //variables para guardar la mayor cantidad de llamadas realizadas por un funcionario y su posición en el vector
				int mayor_duracion = 0, pos_mayor_duracion = -1; //variables para registrar la duración de la llamada más larga y la posición de dicha llamada
	
	            //procesamiento de todos los registros
	            for (int i=0; i<total_llamadas; i++)
	            {
	                int tipo = tipo_llamada[i] - 1;
	                int ofi = oficina[i] - 1;
	                llamadas_tipo[tipo]++;
	                minutos_tipo[tipo] += minutos[i];
	                monto_tipo[tipo] += minutos[i] * tarifas[tipo];
	                llamadas_oficina_tipo[ofi][tipo]++;
	                llamadas_funcionario[i]++;
	                if (minutos[i] > mayor_duracion)
	                {
	                    mayor_duracion = minutos[i];
	                    pos_mayor_duracion = i;
	                }
	            }
	
	            for (int i=0; i<total_llamadas; i++)
	            {
	                int cantidad = 0;
	                for (int j=0; j<total_llamadas; j++)
	                {
	                    if (nombre_funcionario[i] == nombre_funcionario[j])
	                    {
	                    	cantidad++;
						}   
	                }
	                
	                if (cantidad > mayor_llamadas)
	                {
	                    mayor_llamadas = cantidad;
	                    pos_mayor_funcionario = i;
	                }
	            }
	
	            //mostrar la oficina con más llamadas por tipo
	            cout<<"\nDEPENDENCIA CON MÁS LLAMADAS POR TIPO:"<<endl;
	            for (int tipo=0; tipo<3; tipo++)
	            {
	                int max_llamadas = 0, dep = 0;
	                for (int ofi = 0; ofi < 3; ofi++)
	                {
	                    if (llamadas_oficina_tipo[ofi][tipo] > max_llamadas)
	                    {
	                        max_llamadas = llamadas_oficina_tipo[ofi][tipo];
	                        dep = ofi;
	                    }
	                }
	                cout<<"Tipo "<<tipo + 1<<": "<<nombres_oficina[dep]<<" con "<<max_llamadas<<" llamadas "<<endl;
	            }
	
	            //mostrar llamada de mayor duración
	            cout<<"\nLLAMADA DE MAYOR DURACIÓN: "<<endl;
	            if (pos_mayor_duracion != -1)
	            {
	                cout<<"Funcionario: "<<nombre_funcionario[pos_mayor_duracion]<<endl;
	                cout<<"Dependencia: "<<nombres_oficina[oficina[pos_mayor_duracion] - 1]<<endl;
	                cout<<"Tipo: "<<tipo_llamada[pos_mayor_duracion]<<endl;
	                cout<<"Duración: "<<minutos[pos_mayor_duracion]<<" minutos\n";
	            }
	
	            //mostrar monto y promedio por tipo
	            cout<<"\nMONTO TOTAL Y PROMEDIO POR TIPO DE LLAMADA: "<<endl;
	            for (int tipo=0; tipo<3; tipo++)
	            {
	                cout<<"Tipo "<<tipo + 1<<": $"<<monto_tipo[tipo]<<", Tiempo promedio: ";
	                if (llamadas_tipo[tipo] > 0)
	                {
	                	cout<<minutos_tipo[tipo] / llamadas_tipo[tipo]<<" minutos"<<endl;
					}
	                else
	                    cout<<"0 minutos"<<endl;
	            }
	
	            //funcionario con más llamadas
	            cout<<"\nFUNCIONARIO CON MÁS LLAMADAS:"<<endl;
	            if (pos_mayor_funcionario != -1)
	            {
	                cout<<"Nombre: "<<nombre_funcionario[pos_mayor_funcionario]<<endl;
	                cout<<"Oficina: "<<nombres_oficina[oficina[pos_mayor_funcionario] - 1]<<endl;
	                cout<<"Cantidad de llamadas: "<<mayor_llamadas<<endl;
	            }
	        }
	        break;

        } //fin del switch
    }while(op != 4); //el ciclo se repite hasta que el usuario elija salir

	cout<<"saliendo..."<<endl;
    return 0;
}
