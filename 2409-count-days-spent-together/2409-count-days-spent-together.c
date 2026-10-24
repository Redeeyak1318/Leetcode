int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

    int m = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
    a1 = (arriveAlice[3] - '0') * 10 + (arriveAlice[4] - '0');
    for (int i = 0; i < m - 1; i++)
        a1 += days[i];

    m = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
    a2 = (leaveAlice[3] - '0') * 10 + (leaveAlice[4] - '0');
    for (int i = 0; i < m - 1; i++)
        a2 += days[i];

    m = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
    b1 = (arriveBob[3] - '0') * 10 + (arriveBob[4] - '0');
    for (int i = 0; i < m - 1; i++)
        b1 += days[i];

    m = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
    b2 = (leaveBob[3] - '0') * 10 + (leaveBob[4] - '0');
    for (int i = 0; i < m - 1; i++)
        b2 += days[i];

    int start = (a1 > b1) ? a1 : b1;
    int end = (a2 < b2) ? a2 : b2;

    if (start > end)
        return 0;

    return end - start + 1;
}