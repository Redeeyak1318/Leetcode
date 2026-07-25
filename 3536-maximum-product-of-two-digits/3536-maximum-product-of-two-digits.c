int maxProduct(int n) {
    int a[10];
    int i = 0;
    while( n!= 0)
    {
        a[i] = n % 10;
        i++;
        n /= 10;
    }
    int maxProduct = INT_MIN;
    int size = sizeof(a) / sizeof(a[0]);
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(a[i] * a[j] > maxProduct)
                maxProduct = a[i] * a[j];
        }
    }
    return maxProduct;
}