/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    int* ans = malloc(spellsSize * sizeof(*ans));
    *returnSize = spellsSize;
    for(int i=0; i<spellsSize; i++)
    {
        ans[i] = 0;
    }
    
    qsort(potions, potionsSize, sizeof(int), compare);

    for(int i=0; i<spellsSize; i++)
    {  
        int low = 0;
        int high = potionsSize - 1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if((long long)spells[i] * potions[mid] >= success)
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            int count = potionsSize - low;
            ans[i] = count;
        }
    }
    return ans;

}