#include <iostream>
using namespace std;

long long exponentiation_with_modulus(int a, long long N, long long mod)
{
    // to compute a^N
    bool bit_value;

    long long Temp = a, power = N;
    long long final = 1;
    while (power != 0)
    {
        bit_value = power % 2;
        power = power / 2;
        if (bit_value)
        {
            final = ((final % mod) * (Temp % mod)) % mod;
        }
        Temp = ((Temp % mod) * (Temp % mod)) % mod;
    }
    return final;
}

long long int P, G;

int main()
{
    P = 191;    // A prime number
    G = 2;      // It's generator
    cout<<"\n------- A's side -------\n\n";
    cout<<"Enter a Number"<<endl;
    long long a;
    cin>>a;
    cout<<"Private key for A is "<<a<<endl;
    cout<<"\n------- B's side ------- \n\n";
    cout<<"Enter a Number\n";
    long long b;
    cin>>b;
    cout<<"Private key for B is "<<b<<endl;
    long long k_a=exponentiation_with_modulus(G,a,P),k_b=exponentiation_with_modulus(G,b,P);
    cout<<"\n------- Public side ------- \n\n";
    cout<<"value sent by A "<<k_a<<endl;
    cout<<"value sent by B "<<k_a<<endl;

    cout<<"\n------- A's side ------- \n"<<endl;
    cout<<"The value decided is "<<exponentiation_with_modulus(k_b,a,P)<<endl;
    cout<<"\n------- B's side ------- \n"<<endl;
    cout<<"The value decided is "<<exponentiation_with_modulus(k_a,b,P)<<endl;
}