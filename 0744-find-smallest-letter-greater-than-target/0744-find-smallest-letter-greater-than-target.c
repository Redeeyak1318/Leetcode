char nextGreatestLetter(char* letters, int lettersSize, char target) {
    if(target<letters[0])
        return letters[0];
    if(target>=letters[lettersSize-1])
        return letters[0];
    int low=0;
    int high=lettersSize-1;
    while(low<high)
    {
        int mid = low + (high - low)/2;
        if(target<letters[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return letters[low];
}