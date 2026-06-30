int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int numberOfSubstrings(char *s) {
    int last[3] = {-1, -1, -1};
    int ans = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        last[s[i] - 'a'] = i;

        int m = min(last[0], last[1], last[2]);

        if (m != -1)
            ans += m + 1;
    }

    return ans;
}