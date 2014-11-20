#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int count(int V[100][100],int in,int jn){
    int cnt=1,i,j;
    for(i=0;i<100;i++){
        if(V[in][i]==1 && i!=jn){
            cnt = cnt + count(V,i,in);
        }
    }
    //cout<<in<<" "<<jn<<" "<<cnt<<endl;
    return cnt;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int M,N,N2,x,ans=0,cnt=0,i,j,a,b;
    int time,V[100][100];
    cin>>M>>N;
    N2=N;
    for(i=0;i<100;i++){for(j=0;j<100;j++){V[i][j]=0;}}
    while(N2--){
        cin>>a>>b;
        V[a-1][b-1]=1;
        V[b-1][a-1]=1;
        //cout<<V[i][j]<<endl;
    }
    //cout<<V[9][7]<<endl;
         for(i=0;i<N;i++){
             for(j=i;j<N;j++){
                 //cout<<V[i][j];
                 if(V[i][j]==1){
                     //cout<<"inside"<<endl;
                     cnt = count(V,i,j);
                     if(cnt%2==0 ){ans++;}
                     //cout<<"cnt"<<i<<" "<<j<<" "<<cnt<<endl;
                 }
                 //cout<<cnt;
                 
                 //ans=ans+cnt;
             }
         }
                       cout<<ans;
   
    return 0;
}
