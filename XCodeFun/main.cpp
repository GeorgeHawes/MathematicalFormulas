//
//  main.cpp
//  XCodeFun
//
//  Created by George Hawes on 31/07/2023.
//

#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 0;
}

// Function to perform modular exponentiation (base^exp % mod)
int modPow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

void choicesOfE(int totient){
    cout << "Choices: ";
    for(int i = 1; i < totient; i++){
        if(gcd(i, totient) == 1){
            cout << i << ",";
        }
    }
}

int main() {
    // Step 1: Choose two prime numbers
    int p = 3;
    int q = 11;

    // Step 2: Calculate n and phi(n)
    int n = p * q;
    int totient = (p - 1) * (q - 1);

    // Help find choices for the Public Key!
    //choicesOfE(totient);
    
    // Step 3: Choose an integer publicKey (public exponent) such that 1 < publicKey < totient and gcd(publicKey, totient) = 1
    unsigned long publicKey = 7;
    
    // Have to choose suitable Private Key!
    // Solve PrivateKey = (publicKey - 1) % (totient)
    
    unsigned long privateKey = 3;
    
    unsigned long message = 29;
    
    // Key Generation
    cout << "Public Key: (" << publicKey << ", " << n << ")" << endl;
    cout << "Private Key: (" << privateKey << ", " << n << ")" << endl;
    
    cout << "Original Message: " << message << endl;
    unsigned long testCipherText = pow(message, publicKey);
    unsigned long encryptedMessage = fmod(testCipherText,n);
    cout << "Encrypted Message: " << encryptedMessage << endl;
    
    unsigned long decryptedMessage = pow(encryptedMessage, privateKey);
    unsigned long decryptedMessage2 = fmod(decryptedMessage,n);
    cout << "Decrypted message: " << decryptedMessage2 << endl;
    
    // Verify that e and totient are coprime
    if (gcd(publicKey, totient) != 1) {
        cout << "Invalid choice of 'e'.";
        return 1;
    }

    return 0;
}
