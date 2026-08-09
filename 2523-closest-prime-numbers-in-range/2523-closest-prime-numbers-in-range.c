/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestPrimes(int left, int right, int* returnSize) {
    *returnSize = 2;
    int* ans = (int*)malloc(2 * sizeof(int));
    ans[0] = -1;
    ans[1] = -1;

    bool* isPrime = (bool*)malloc((right + 1) * sizeof(bool));
    for (int i = 0; i <= right; i++) {
        isPrime[i] = true;
    }
    if (right >= 0) isPrime[0] = false;
    if (right >= 1) isPrime[1] = false;

    for (int i = 2; i * i <= right; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= right; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int* primes = (int*)malloc((right - left + 1) * sizeof(int));
    int primeCount = 0;
    for (int i = left; i <= right; ++i) {
        if (isPrime[i]) {
            primes[primeCount++] = i;
        }
    }

    if (primeCount < 2) {
        free(isPrime);
        free(primes);
        return ans;
    }

    int minGap = INT_MAX;
    for (int i = 1; i < primeCount; ++i) {
        int gap = primes[i] - primes[i - 1];
        if (gap < minGap) {
            minGap = gap;
            ans[0] = primes[i - 1];
            ans[1] = primes[i];
        }
        if (minGap == 2 || minGap == 1) {
            break;
        }
    }

    free(isPrime);
    free(primes);
    return ans;
}