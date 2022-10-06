#include <iostream>
using namespace std;
#include <ctime>
// this function computes (a^N) modulus mod efficiently using base 2

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

// This function just checks if the fermats little theorem fails for a ie a^(N-1) modulus N is not 1

bool fermats_little_theorem(long long N, int a)
{
    return (exponentiation_with_modulus(a, N - 1, N) == 1);
}

// if n-1 is of the form 2^(k)*m we can say that 2^(n-1/2) should be 1 modulus N or N-1 modulus N
// if it is one we just apply this again with (n-1)/2 instead of n-1 else

bool square_modulus_is_one(long long N, int a)
{
    long long power_now = (N - 1) / 2;
    while (true)
    {
        if (exponentiation_with_modulus(a, power_now, N) == 1)
        {
            if (power_now % 2 == 0)
            {
                power_now /= 2;
                continue;
            }
            else
                return true;
        }
        if (exponentiation_with_modulus(a, power_now, N) == N - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// this checks if the gcd of N and a is one

bool gcd_is_one(long long N, int a)
{
    if (N % a == 0)
    {
        if (a == 1)
            return true;
        else
            return false;
    }
    else
    {
        return gcd_is_one(a, N % a);
    }
}

// This is a function which runs the miller rabin test with a and N

bool is_prime(long long N)
{
    int a = 2 + rand() % (N - 2);

    // cout << a << endl;
    if (!gcd_is_one(N, a))
    {
        // cout << "GCD OF " << N << " AND " << a << " IS NOT ONE " << endl;
        return false;
    }
    if (!fermats_little_theorem(N, a))
    {
        // cout << "FERMATS LITTLE THEOREM FAILS FOR " << a << endl;
        return false;
    }
    if (!square_modulus_is_one(N, a))
    {
        // cout << "SQUARE MODULUS ARGUMENT FAILS FOR " << a << endl;
        return false;
    }
    return true;
}

// This is the function to be called it generally works for 10 digit numbers

bool miller_rabin(long long N, int accuracy_factor)
{
    bool prime = true;
    for (int i = 0; i < accuracy_factor; i++)
    {
        if (!is_prime(N))
        {
            prime = false;
            break;
        }
    }
    return prime;
}
int main()
{
    srand(time(0));

    int count = 1;
    for (int i = 3; i < 100000; i++)
    {
        if (miller_rabin(i, 10))
        {
            count++;
            cout << i << endl;
        }
    }
    cout << "\n" << count << "\n";
}