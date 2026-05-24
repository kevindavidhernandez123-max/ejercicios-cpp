#include <iostream>
using namespace std;
int main()
{long nhoras,vhora,basico,transp=162000, minimo=1300000, salud, pension, fsp=0, reten=0, neto;
cout<<"# horas trabajadas:" ;
cin>> nhoras;
cout<<" valor de la hora: ";
cin>> vhora;
basico= nhoras* vhora;
if (basico>2*minimo)
{transp= 0;}
salud= basico*0.04;
pension=basico*0.04;
if(basico> 4*minimo)
{fsp= basico*0.01;}
if(basico> 6 *minimo)
{reten= basico* 0.1;}
neto=basico+transp-salud-pension-fsp-reten;
cout<<"INGRESOS:"<<endl;
cout<<"sueldo basico: "<<basico<<endl;
if(transp>0)cout<<"subsidio transporte: "<<transp<<endl;
cout<<"\n DESCUENTOS:\n\n";
cout<<"Aporte Eps:"<<salud<<endl;
cout<<"aporte pension:"<<pension<<endl;
if (fsp>0) cout<<"fsp: "<<fsp<<endl;
if(reten>0) cout<<"Retefuente:"<<reten<<endl;
cout<<"\n NETO A PAGAR: "<<neto<<endl;
return 0;
}

