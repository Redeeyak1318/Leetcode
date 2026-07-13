int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int maxDistance(int* position, int positionSize, int m) {
    qsort(position, positionSize, sizeof(int), compare);
    int low = 1;
    int high = position[positionSize - 1] - position[0];

    while(low <= high)
    {
        int mid = low + (high - low)/2;
        int balls = 1;
        int lastPlaced = position[0];

        for(int i=0; i<positionSize; i++)
        {
            if(position[i] - lastPlaced >= mid)
            {
                balls++;
                lastPlaced = position[i];
            }
        }

        if(balls >= m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}