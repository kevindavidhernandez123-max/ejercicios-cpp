#include<iostream>
#include<string>
using namespace std;

int main(){
	
string H;
long long D=0;
int docena;
	
	do{
	
	cout<<"";
     cin>>H;
	 if(H=="*")	{
	 	break;
	 }
    
			D=0;
		for(int x=0; x<H.size(); x++ ){
			
		    D=D*2 +(H[x]-'0');
			
		}
	
		docena=D%12;
		
		cout<<docena<<endl;
		
	}while(true);
	
	
	return 0;
}

