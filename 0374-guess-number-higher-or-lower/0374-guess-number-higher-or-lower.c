/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);
 

int guessNumber(int n){
	long long low=0;
    long long high=n;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        int result = guess((int)mid);
        if(result==0)
            return mid;
        else if(result==-1)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}