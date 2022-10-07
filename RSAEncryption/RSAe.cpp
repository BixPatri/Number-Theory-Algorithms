#include<iostream>
using namespace std;
typedef long long ll;
#include "headers.h"
#include<fstream>
#include<sstream>

ll n;
ll a;

// ll de_RSA(ll p,ll q,)
ll encrypt(string file1,string file2){
    ll prime1=17359,prime2=64591;
    ifstream fin(file1);
    ofstream fout(file2);
    string st;
    ostringstream ss;
    ss << fin.rdbuf();
    st = ss.str();
    // cout<<st<<endl;
    ll phi=(prime1-1)*(prime2-1);
    a=get_a(phi);
    ll key=get_inverse(a,phi);
    n=prime1*prime2;
    for(int i=0;i<st.length();i++){
        fout<<exponentiation_with_modulus(int(st[i]),a,n)<<" ";
        // cout<<RSA(prime1,prime2,int(st[i]));
    }
    return key;
}

void decrypt(string file1,string file2,ll key){
    ifstream fin(file1);
    ofstream fout(file2);
    string st;
    while(fin>>st){
        fout<<char(exponentiation_with_modulus(stoi(st),key,n));
    }
}

int main(){
    string s;
    cin>>s;
    ll key= encrypt(s,"coded.txt");
    decrypt("coded.txt","decoded.txt",key);
}