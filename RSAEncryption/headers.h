


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


