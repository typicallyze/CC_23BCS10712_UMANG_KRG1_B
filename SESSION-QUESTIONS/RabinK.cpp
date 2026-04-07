#include<bits/stdc++.h>
using namespace std;
int dd(string s){
    int sum=0;
    int m=s.size()-1;
    for(int i=0;i<s.size();i++){
        sum+=(s[i]-'a'+1)*pow(26,m);
        m--;
    }
}
int main(){
     string s;
     string ptr;
     cin>>s>>ptr;
    int hash1=dd(ptr);
    int hash2=dd(s.substr(0,ptr.size()));
    for(int i=ptr.size();i<s.size();i++){
        if(hash1==hash2){
            bool flag=true;
            for(int j=0;j<ptr.size();j++){
                if(s[i-ptr.size()+j]!=ptr[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)
            cout<<"Pattern found at index "<<i-ptr.size()<<endl;
        }else{
            hash2=hash2-(s[i-ptr.size()]-'a')*pow(26,ptr.size()-1);
            hash2=hash2*26+(s[i]-'a');
        }
    }

}