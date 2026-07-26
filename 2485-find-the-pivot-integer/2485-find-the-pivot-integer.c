int pivotInteger(int n) {
    int sum = n * (n + 1) / 2;
    int root = (int)sqrt(sum);

    if (root * root == sum)
        return root;

    return -1;
}