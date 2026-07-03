#define OFFSET 1000
#define SIZE 2001

bool checkIfExist(int* arr, int arrSize) {
    bool seen[SIZE];
    memset(seen, 0, sizeof(seen));

    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];

        if (2 * x >= -1000 && 2 * x <= 1000 &&
            seen[2 * x + OFFSET])
            return true;

        if (x % 2 == 0 &&
            seen[x / 2 + OFFSET])
            return true;

        seen[x + OFFSET] = true;
    }

    return false;
}