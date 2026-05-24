#include<iostream>
#include<string>
#include<vector>
using namespace std;





int main(){
	
	int t;
	cin>>t;
	bool posible=true;
	
	while(t--){
		
		int n;
	
		cin>>n;
		
		vector<long long> lista(n);
	

	for(int x=0; x<n; x++)
	{
		cin>>lista[x];
		
	};
	
	
	int pos=0;

int copia;
	for(int i=0; i<n; i++){
		copia=lista[i];
		if(copia%2==0){
			posible=true;
		}
		else{
			posible=false;
		}
		
	}
	
	}
	if(posible==true){
		cout<<"YES\n";
		
	}
	else{
		cout<<"NO\n";
	}


		
	return 0;
}
