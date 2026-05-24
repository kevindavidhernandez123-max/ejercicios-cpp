#include<iostream>
#include<cstdlib>
#include<ctime>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "spanish");
    int opcion=0, numeroAdivinar=0, numeroUsuario=0, vidas=0, maximo=0, intentosUsados=0, i=2, esPrimo=1, divisor=1;
    //estadisticas
    int totalNumeros=0, totalAciertos=0, totalPrimos=0, totalCompuestos=0, totalCompuestosPares=0, totalCompuestosImpares=0, sumaCompuestos=0, primosWagstaff=0, primosSophie=0, primosMersenne=0, maxGenerado=0, minGenerado=0, potencia=1;
	int j=2, primoW=1, wag, menu, sg, primoSG=1, p, mp, primoMS=1, cantidadDivisores=0, primero=1, n, factor, primerFactor;
	
    system("color 1E");
	cout<<"\tJUEGO DE NUMEROS PRIMOS";
	cout<<"\nEste es un juego educativo enfocado en el aprendizaje" << endl;
    cout<<"de los numeros primos y compuestos " << endl;
    cout<<"el usuario debe adivinar un numero aleatorio, y el programa" << endl;
    cout<<"evalua si es primo o compuesto. En caso de ser primo, se clasifica" << endl;
    cout<<"segun su tipo: Mersenne, Sophie Germain o Wagstaff." << endl;
	cout<<"asignatura: Algoritmo y Programación"<<endl;
	system("pause");
	
	system("color 0F");
	
	system("cls");
	while(opcion!=3)
	{// Menú principal
        cout<<"\n\033[0mGAMES PRIME NUMBERS"<<endl;
        cout<<"1. INICIAR JUEGO"<<endl;
        cout<<"2. MOSTRAR ESTADISTICAS DEL JUEGO"<<endl;
        cout<<"3. SALIR"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        if(opcion==1)
		{//Configuración del juego
            cout<<"\nIngrese el valor maximo para el numero secreto: ";
            cin>>maximo;
            cout<<"Ingrese la cantidad de vidas o intentos: ";
            cin>>vidas;

            srand(time(0));// Inicializa la semilla aleatoria
            numeroAdivinar=1+rand()%maximo;

            if(totalNumeros==0)
			{//Registro del número mayor y menor generado
                maxGenerado=numeroAdivinar;
                minGenerado=numeroAdivinar;
            }
			else
			{
                if(numeroAdivinar > maxGenerado)
                {
                	maxGenerado = numeroAdivinar;
				}
				
                if(numeroAdivinar < minGenerado)
                {
                	minGenerado = numeroAdivinar;
                	
				}
            }

            totalNumeros=totalNumeros+1;
            intentosUsados=0;
            numeroUsuario=0;
            
			 // Bucle de intentos
            while(numeroUsuario!=numeroAdivinar&&vidas>0)
			{//aqui se valida el numero q se coloca, y si falla se quita una vida
                cout<<"\nIntento " <<(intentosUsados + 1) << ". Ingrese su numero: ";
                cin>>numeroUsuario;
                cout<<"\a";

                if(numeroUsuario<numeroAdivinar)
				{//si es mayor la respuesta
                    cout<<"\033[33mEl numero secreto es mayor.\033[0m"<<endl;
                }else if(numeroUsuario>numeroAdivinar)
				{//si es menor la respuesta
                    cout<<"\033[33mEl numero secreto es menor.\033[0m"<<endl;
                }

                vidas=vidas-1;
                intentosUsados=intentosUsados+1;

                if(numeroUsuario!=numeroAdivinar)
				{//mensaje para decir cuantas vidas quedan
                    cout<<"\033[31mLe quedan "<<vidas<<" intentos.\033[0m"<<endl;
                }
            }

            if(numeroUsuario==numeroAdivinar)
			{//si adivina el numero o se le acaban las vidas
                cout<<"\n\033[32m¡Felicidades! Adivino el numero en "<< intentosUsados<<" intentos.\033[0m"<<endl;
                totalAciertos = totalAciertos + 1;
        
            }
			else
			{
                cout<<"\n\033[31mLo siento, ha perdido. El numero era: "<<numeroAdivinar<<"\033[0m"<<endl;
            }

            esPrimo = 1;
            i = 2;
            
            while(i<numeroAdivinar)
			{//si el numero es mayor a 2, se saca mod para saber si es primo o no
                if(numeroAdivinar%i==0)
				{
                    esPrimo=0;
                }
                i=i+1;
            }
            if(numeroAdivinar==1)
			{
                esPrimo=0;
            }

            if(esPrimo==1)
            
			{
                cout<<"\nEl numero "<<numeroAdivinar<<" es PRIMO."<<endl;
                menu = 0;
    			primoW = 1;
    			primoSG = 1;
    			primoMS = 1;
    			j = 2;  
                cout<<"Un numero primo solo tiene dos divisores: el 1 y el mismo."<<endl;
                cout<<"Por ejemplo, "<<numeroAdivinar<<" solo se puede dividir entre 1 y "<<numeroAdivinar<<"."<<endl;
                totalPrimos++;

                while (menu != 4)
				{
                    cout<<"\nLOS SUPERPRIMOS"<<endl;
                    cout<<"1. Primos de Wagstaff"<<endl;
                    cout<<"2. Primos de Sophie Germain"<<endl;
                    cout<<"3. Primos de Mersenne"<<endl;
                    cout<<"4. Salir"<<endl;
                    cout<<"Seleccione una opcion: ";
                    cin>>menu;
                    if(menu==1)
					{
                        if((2*numeroAdivinar+1)%3==0)
						{//se comprueba que sea un primo wagstaff
                            wag=(2*numeroAdivinar+1)/3;
                            
                            while(j<wag)
							{
                                if(wag%j==0)primoW=0;
                                j++;
                            }
                            if(primoW==1)
							{
                                cout<<numeroAdivinar<<" es un Primo de Wagstaff porque (2*"<<numeroAdivinar<<"+1)/3 = "<<wag<<" es primo."<<endl;
                                primosWagstaff++;
                            }
							else
							{
                                cout<<numeroAdivinar<<" NO es Primo de Wagstaff."<<endl;
                            }
                        }
						else
						{
                            cout<<numeroAdivinar<<" NO cumple la forma (2p+1)/3."<<endl;
                        }
                    }
                    
					else if(menu==2)
					{//se comprube que sea primo sophie
                        sg=2*numeroAdivinar+1;
                        j=2;
                        
                        while(j<sg)
						{
                            if(sg%j==0) 
							primoSG=0;
                            j++;
                        }
                        
                        if(primoSG==1)
						{
                            cout<<numeroAdivinar<<" es un Primo de Sophie Germain porque 2*"<<numeroAdivinar<<"+1 = "<<sg<<" es primo."<<endl;
                            primosSophie++;
                        }
						else
						{
                            cout<<numeroAdivinar<<" NO es Primo de Sophie Germain."<<endl;
                        }
                    }
					else if(menu==3)
					{//primo mersene
                        potencia=1;
                        p=numeroAdivinar;
                        i=1;
                        
                        while(i<=p)
						{
                            potencia=potencia*2;
                            i++;
                        }
                        mp=potencia-1;
                        j=2;
                        
                        while(j<mp)
						{
                            if(mp%j==0)
							primoMS=0;
                            j++;
                        }
                        
                        if(primoMS==1)
						{
                            cout<<numeroAdivinar<<" es un Primo de Mersenne porque 2^"<<numeroAdivinar<<" - 1 = "<<mp<<" es primo."<<endl;
                            primosMersenne++;
                        }
						else
						{
                            cout<<numeroAdivinar<<" NO es Primo de Mersenne."<<endl;
                        }
                    }
                }

            }
			else
			{// lo que va a salir si el numero es compuesto
                cout<<"\nEl numero "<<numeroAdivinar<<" es COMPUESTO."<<endl;
                cout<<"Divisores: ";
                divisor=1;
                cantidadDivisores=0;
                while(divisor<=numeroAdivinar)
				{ 
                    if(numeroAdivinar%divisor==0)
					{
                        if(primero==0)
						cout<<", ";
                        cout<<divisor;
                        primero=0;
                        cantidadDivisores++;
                    }
                    divisor++;
                }
                cout<<"\nTiene "<<cantidadDivisores<<" divisores, por eso es compuesto."<<endl;
                totalCompuestos++;
                sumaCompuestos+=numeroAdivinar;
                
                if(numeroAdivinar%2==0)
                {
                	totalCompuestosPares++;
				}
				else 
				{
					totalCompuestosImpares++;
				}
				
                cout<<numeroAdivinar<<" = ";
                n=numeroAdivinar;
                factor=2;
                primerFactor=1;
                
                
                while(n>1)
				{
                    if(n%factor==0)
					{
                        if(primerFactor==0)
						cout<<" x ";
                        cout<<factor;
                        n=n/factor;
                        primerFactor=0;
                    } 
					else 
					{
                        factor++;
                    }
                }
                cout<<endl;
            }

        } 
		else if(opcion==2)
		{//Mostrar estadísticas del juego
            cout<<"\n===== ESTADISTICAS DEL JUEGO ====="<<endl;
            cout<<"Total de numeros generados: "<<totalNumeros<<endl;
            cout<<"Porcentaje de aciertos: ";
            if(totalNumeros > 0)
            {
            	cout<<(totalAciertos*100)/totalNumeros<<"%\n";
			}
			else
			{
				cout<<"0%\n";
            	cout<<"Valor maximo generado: "<<maxGenerado<<endl;
            	cout<<"Valor minimo generado: "<<minGenerado<<endl;
            	cout<<"\n--- Primos ---"<<endl;
            	cout<<"Cantidad de primos: "<<totalPrimos<<endl;
			}
			
            if(totalNumeros>0)
            {
            	cout<<"Porcentaje de primos: "<<(totalPrimos*100)/totalNumeros<<"%\n";
			}
            if(totalPrimos>0)
			{
                cout<<"Wagstaff: "<<primosWagstaff<<" ("<<(primosWagstaff*100)/totalPrimos<<"%)\n";
                cout<<"Sophie Germain: "<<primosSophie<<" ("<<(primosSophie*100)/totalPrimos<<"%)\n";
                cout<<"Mersenne: "<<primosMersenne<<" ("<<(primosMersenne*100)/totalPrimos<<"%)\n";
            }
            cout<<"\n--- Compuestos ---"<<endl;
            cout<<"Cantidad de compuestos: "<<totalCompuestos<<endl;
            
            if(totalCompuestos>0)
			{
                cout<<"Promedio: "<<sumaCompuestos/totalCompuestos<<endl;
                cout<<"Porcentaje pares: "<<(totalCompuestosPares*100)/totalCompuestos<<"%\n";
                cout<<"Porcentaje impares: "<<(totalCompuestosImpares*100)/totalCompuestos<<"%\n";
            }
        }
		else if(opcion==3)
		{
            cout<<"\nSaliendo del programa"<<endl;
        }
		else
		{
            cout<<"\nOpcion invalida. Intente de nuevo."<<endl;
        }
    }
    return 0;
}


