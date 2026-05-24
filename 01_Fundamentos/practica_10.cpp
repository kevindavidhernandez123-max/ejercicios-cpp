 //Tres personas deciden invertir su dinero para formar una empresa.
  //Cada una de ellas invierte una cantidad distinta. 
  //Hacer un programa que imprima el porcentaje que cada quien invierte con respecto al total de la inversión
  #include<iostream>
  using namespace std;
  int main(){
  	
  	float cantidad_1,cantidad_2,cantidad_3,total;
  	
  	cout<<"ingrese la cantidad de dinero que va a invertir(persona 1): ";
  	cin>>cantidad_1;
  	cout<<"ingrese la cantidad de dinero que va a invertir(persona 2): ";
  	cin>>cantidad_2;
  	cout<<"ingrese la cantidad de dinero que va invertir(persona3): ";
  	cin>>cantidad_3;
total=cantidad_1+cantidad_2+cantidad_3;
cout<<"\n la persona 1 invierte: "<<cantidad_1/total*100;
cout<<"\n la persona 2 invierte "<<cantidad_2/total*100;
cout<<"\n la persona 3 invierte "<<cantidad_3/total*100;
return 0;
  }
