#include <iostream>
// #include "miller-rabin.cpp"
using namespace std;

typedef long long ll;
#include "miller-rabin.cpp"

ll p = 17257;
ll q = 32413;



ll get_prime(ll bottom, ll head)
{
    if (bottom >= head)
        return 0;
    if (miller_rabin(bottom, 10))
    {
        return bottom;
    }
    if (miller_rabin(head, 10))
    {
        return head;
    }
    return get_prime(bottom + 1, head - 1);
}


ll gcdExtended(ll a, ll b, ll *x , ll *y )
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1; 
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
ll gcd(ll a,ll b){
    if(a==0){
        return b;
    }
    return (gcd(b%a,a));
}

ll get_a(ll p)
{  
    int x=rand()%p;
    int y=rand()%x;
    for (ll i = p*y/x; i <p; i++)
    {
        if (gcd(i,p)==1)
        {
            return i;
        }
    }
    return get_a(p);
}

ll get_inverse(ll a, ll phi){
    ll x,y;
    if(gcdExtended(a,phi,&x,&y)!=1){
        return 0;
    }
    else{
        ll res=((x%phi)+phi)%phi;
        return res;
    }
}


int main()
{
    // cout<<get_inverse(3,14)<<endl;
    cout << " \n---------- B's Side ---------- \n\nselect two large prime numbers \nGive range you want primes to be present in" << endl;
    ll p1, p2, q1, q2;
    cout << "Range of first prime" << endl;
    cin >> p1 >> p2;
    cout << "Range of second prime" << endl;
    cin >> q1 >> q2;
    ll p = get_prime(min(p1, p2), max(p1, p2)), q = get_prime(min(q1, q2), max(q1, q2));
    // ll p,q;
    
    if (p == 0 || q == 0)
    {
        cout << "no primes found try again" << endl;
        return 0;
    }
    ll n=p*q;
    ll phi=(p - 1) * (q - 1);
    cout<<"p "<<p<<" q "<<q<<endl<<"phi(n) "<<phi<<endl;
    ll a = get_a(phi);
    cout<<"\n---------- General side ---------- (Visible to everyone)\n"<<endl;
    cout << "n is p*q which is " << n << "\na is a number coprime to phi which is " << a << endl;
    cout << " \n---------- A's Side ----------\n \n Enter the number you want to send to B" << endl;
    ll x;
    cin >> x;
    ll k=exponentiation_with_modulus(x, a, p * q);

    cout<<"\n---------- General side ---------- (Visible to everyone)\n"<<endl;
    cout << "Now we will give x^a mod(n) to B "<< k<<endl;
    cout << "\n---------- B's side ---------- \n\nnow we will find a^(-1) mod(phi(n)) and then get x \n";
    ll a_1 = get_inverse(a, phi);
    cout<<"This inverse in "<<a_1<<endl;
    cout<<"The number encrypted is "<<exponentiation_with_modulus(k,a_1,n)<<endl<<endl;
}