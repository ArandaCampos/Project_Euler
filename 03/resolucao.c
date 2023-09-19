#include <stdlib.h>
#include <stdio.h>

unsigned long get_next_prime(unsigned long, unsigned long);
unsigned long largest_prime_factor(unsigned long);
int is_prime(unsigned long);

int main(){
    printf("%lu\n", largest_prime_factor(600851475143));
    return 0;
}

int is_prime(unsigned long n){
    int limit = (n - (n % 2)) / 2;

    if (n <= 1) return 0;

    for (int i = 2; i <= limit; i++){
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

unsigned long get_next_prime(unsigned long n, unsigned long max){
    if (n <= 1) return 2;
    while (n <= max){
        n++;
        if (is_prime(n)) return n;
    }
    return 0;
}

unsigned long largest_prime_factor(unsigned long x){

    unsigned long prime = 0, largest = 0;
    while (prime < x){
        prime = get_next_prime(prime, x);
        if (x % prime == 0) {
            x = x / prime;
            largest = prime;
        }
    }
    return largest;
}
