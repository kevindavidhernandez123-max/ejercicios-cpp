#include <iostream>
#include <string>
#include <fstream> //BIBLIOTECA NECESARIA
using namespace std;

 int main(){
 	
 	fstream out;
 	
 	out.open("fstream explicar.txt", ios::out |ios::trunc);
 	if(!out.is_open()){
 		
 		cout<<"Error\n";
 		return 1;
 		
	 }
	 out<<"Nuevo ejemplo\n probaremos hacerlo solo usando fstream\nlinea de relleno";
	 out.close();
	 
	 
	 fstream in;
	 in.open("fstream explicar.txt", ios:: in);
	 if(!in.is_open()){
	 	
	 	cout<<"Error\n";
	 	return 1;
	 }
	 
	 string leido;
	 cout<<"LEIDO:\N";
	 while(getline(in, leido)){
	 	cout<<leido<<endl;
	 }
 	in.close();
 	
 	return 0;
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	
 }
