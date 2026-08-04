int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int uniqueXorTriplets(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), compare);

    
    int uniqueSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[uniqueSize++] = nums[i];
        }
    }

   
    bool* possible_pairs = (bool*)calloc(2048, sizeof(bool));
    bool* triplets = (bool*)calloc(2048, sizeof(bool));

    
    for (int i = 0; i < uniqueSize; i++) {
        for (int j = i; j < uniqueSize; j++) {
            int pair_xor = nums[i] ^ nums[j];
            possible_pairs[pair_xor] = true;
        }
    }

    
    for (int pair_xor = 0; pair_xor < 2048; pair_xor++) {
        if (possible_pairs[pair_xor]) {
            for (int i = 0; i < uniqueSize; i++) {
                triplets[pair_xor ^ nums[i]] = true;
            }
        }
    }

    
    int unique_triplet_count = 0;
    for (int i = 0; i < 2048; i++) {
        if (triplets[i]) {
            unique_triplet_count++;
        }
    }

    
    free(possible_pairs);
    free(triplets);

    return unique_triplet_count;
}