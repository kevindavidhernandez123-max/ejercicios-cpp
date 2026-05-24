#include<iostream>
using namespace std;

int main() {
    int num, dig, dig2, result;
long long max=0, min=9999999999;
float N,cont=0;
    cout << "escriba la cantidad de numeros: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "\nIngresa el numero " << i << ": ";
        cin >> num;

        dig = num % 10;        
        dig2 = num / 10;       
        result = dig2 - (2*dig);

        
        if (result % 7 == 0){
		
            cout << " El numero es divisible por 7" << endl;
            cont++;
            
            if(num>max){
            max=num;	
            	
				}
				if(num<min){
					min=num;
				}
			 	
			}
        else{
		
            cout << "No es divisible por 7" << endl;
    }

  
}

cout<<"la cantidad de numeros divisibles por 7 es de "<<cont<<endl;
cout<<"el porcentaje de numeros divisibles por es de " <<cont/N*100<<"%"<<endl;
cout<<"el numero divisible por 7 menor ingresado es "<<min<<endl;
cout<<"el numero divisible por 7 menor ingresado es  "<<max;
return 0;
}

