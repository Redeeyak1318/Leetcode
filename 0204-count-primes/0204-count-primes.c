int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }

    char *isPrime = (char *)calloc(n, sizeof(char));
    if (isPrime == NULL) return 0;

    for (int i = 2; i * i < n; i++) {
        if (isPrime[i] == 0) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i] == 0) {
            count++;
        }
    }

    free(isPrime);
    return count;
}