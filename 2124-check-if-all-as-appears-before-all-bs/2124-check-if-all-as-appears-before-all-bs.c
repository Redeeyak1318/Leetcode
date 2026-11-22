bool checkString(char* s) {
    int b = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == 'b') {
            b = 1;
        }

        if(s[i] == 'a' && b == 1) {
            return false;
        }
    }

    return true;
}