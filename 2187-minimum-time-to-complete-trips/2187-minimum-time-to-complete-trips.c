bool canTime(int* time, int timeSize, long long currTime, int totalTrips)
{
    long long trips = 0;
    for(int i=0; i<timeSize; i++)
    {
        trips += currTime/time[i];

        if(trips>=totalTrips)
                return true;
    }
    return false;    
}

long long minimumTime(int* time, int timeSize, int totalTrips) {
    long long low = time[0];
    for(int i=1; i<timeSize; i++)
    {
        if(time[i]<low)
            low = time[i];
    }
    long long high = low * totalTrips;

    while(low < high)
    {
        long long mid = low + (high - low)/2;
        if(canTime(time, timeSize, mid, totalTrips))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}