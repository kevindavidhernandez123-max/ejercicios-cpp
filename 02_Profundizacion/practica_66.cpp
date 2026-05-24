#include<iostream>
#include<vector>
using namespace std;

int main(){

int N;
cin>>N;

vector<int> jefes(N+1);
for(int i=1; i<=N; i++){
    cin>>jefes[i];
    
}

int cont=0;

for(int i=1; i<=N; i++)    {
int cont2=1;
int aux=i;

while(jefes[aux]!=-1){
aux=jefes[aux];
cont2++;
}

if(cont2>cont){
    cont=cont2;
}


}
    
    cout<<cont<<endl;
    
    
}
