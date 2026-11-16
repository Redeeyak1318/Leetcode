char* digitSum(char* s, int k) {
    while (strlen(s) > k) {
        char temp[1000];
        int index = 0;

        for (int i = 0; i < strlen(s); i += k) {
            int sum = 0;

            for (int j = i; j < i + k && s[j] != '\0'; j++) {
                sum += s[j] - '0';
            }

            char buffer[20];
            sprintf(buffer, "%d", sum);

            for (int j = 0; buffer[j] != '\0'; j++) {
                temp[index++] = buffer[j];
            }
        }

        temp[index] = '\0';
        strcpy(s, temp);
    }

    return s;
}