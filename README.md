# Number-Theory-Algorithms

## How To Run

1) Download the folder of the algorithm you want to check. Go into that folder.
2) For miller-rabin you can remove the main and check for any prime upto 7 digits. The default main just counts all prime numbers between 1 and 100000 and prints them, you can use this also.
3) For RSA enter the range of the first prime number and then for the second number second prime number. Then just enter the number you want to send.
4) For encryption using RSA just download RSAEncryption and then compile RSAe.cpp then execute a.out. After this provide the name of the file you want encrypted as an argument file.txt is present for this purpose you can write file.txt then it will display the coded and the decoded files.
5) For Diffie-Helman the prime and the generator is hardcoded. Just enter two numbers (A's side and B's ide) then you would get the final key decided at the terminal.
6) Preferably keep the numbers less than 6 digits as exponentiation is involved.

## Basics

### Miller-Rabin-

Miller Rabin is a fast approach to test primality of the large numbers. This algorithm is called a Rabin-miller primality test and this algorithm decides whether number is prime which is same to other tests including Fermat primality Test and Solovay- Strassen primality test.

This test is based on equality or group of equalities that hold the true for prime values, thus checks whether they hold for the number, that it is required to test for primality.

This algorithm is most useful known primality testing algorithm and can be used in different software libraries that based on RSA encryption and best instance is OpenSSL.

Miller Rabin validate that the number is composite. So this is called compositeness test rather than primality test. The miller Rabin test identify all composites. For each composite number n, there can be at least 3/4 (Miller Rabin) of numbers a are witnesses of compositeness of n.

Miller Rabin is associatively simple extension of Fermats little Theorem that enable us to test for primality with a much larger probability than Fermats little theorem.

### RSA-

RSA algorithm is asymmetric cryptography algorithm. Asymmetric actually means that it works on two different keys i.e. Public Key and Private Key. As the name describes that the Public Key is given to everyone and Private key is kept private.

An example of asymmetric cryptography :

A client (for example browser) sends its public key to the server and requests for some data.
The server encrypts the data using client’s public key and sends the encrypted data.
Client receives this data and decrypts it.
Since this is asymmetric, nobody else except browser can decrypt the data even if a third party has public key of browser.

The idea! The idea of RSA is based on the fact that it is difficult to factorize a large integer. The public key consists of two numbers where one number is multiplication of two large prime numbers. And private key is also derived from the same two prime numbers. So if somebody can factorize the large number, the private key is compromised. Therefore encryption strength totally lies on the key size and if we double or triple the key size, the strength of encryption increases exponentially. RSA keys can be typically 1024 or 2048 bits long, but experts believe that 1024 bit keys could be broken in the near future. But till now it seems to be an infeasible task.

### Diffie-Hellman-

The Diffie-Hellman algorithm is being used to establish a shared secret that can be used for secret communications while exchanging data over a public network using the elliptic curve to generate points and get the secret key using the parameters.  It is based on simple modular arithmetic.

## References-

https://www.geeksforgeeks.org/implementation-diffie-hellman-algorithm/

https://www.geeksforgeeks.org/rsa-algorithm-cryptography/

https://www.geeksforgeeks.org/primality-test-set-3-miller-rabin/
