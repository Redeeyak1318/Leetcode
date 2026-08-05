char* getPermutation(int n, int k) {
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';

    int numbers[9];
    int factorials[9];
    factorials[0] = 1;
    
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
        if (i > 0) {
            factorials[i] = factorials[i - 1] * i;
        }
    }

    k--;

    for (int i = 0; i < n; i++) {
        int remaining = n - 1 - i;
        int group_size = factorials[remaining];
        int index = k / group_size;
        
        result[i] = numbers[index] + '0';

        for (int j = index; j < n - 1 - i; j++) {
            numbers[j] = numbers[j + 1];
        }

        k %= group_size;
    }

    return result;
}
