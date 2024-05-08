#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
	unsigned long long a;
    	while (1){
	a++;
        if (is_prime(a)) {
            printf("%lld is prime\n", a);
        }
    }

    printf("Prime number calculation completed.\n");

    return 0;
}

