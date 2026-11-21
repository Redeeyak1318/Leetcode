/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */

int* findSubtreeSizes(int* parent, int parentSize,
                       char* s, int* returnSize) {

    int n = parentSize;

    *returnSize = n;

    int* newParent = malloc(n * sizeof(int));
    int* ans = malloc(n * sizeof(int));

    int* head = malloc(n * sizeof(int));
    int* to = malloc((n - 1) * sizeof(int));
    int* next = malloc((n - 1) * sizeof(int));

    int* stack = malloc(2 * n * sizeof(int));
    int* prev = malloc(n * sizeof(int));

    int* order = malloc(n * sizeof(int));


    for(int i = 0; i < n; i++) {
        head[i] = -1;
        newParent[i] = parent[i];
        ans[i] = 1;
    }


    int edge = 0;

    for(int i = 1; i < n; i++) {

        int p = parent[i];

        to[edge] = i;
        next[edge] = head[p];

        head[p] = edge;

        edge++;
    }


    int last[26];

    for(int i = 0; i < 26; i++) {
        last[i] = -1;
    }


    int top = 0;

    stack[top++] = 0;

    while(top > 0) {

        int node = stack[--top];


        if(node < 0) {

            node = -node - 1;

            int ch = s[node] - 'a';

            last[ch] = prev[node];

            continue;
        }


        int ch = s[node] - 'a';


        prev[node] = last[ch];


        if(last[ch] != -1) {

            newParent[node] = last[ch];
        }


        last[ch] = node;

       
        stack[top++] = -(node + 1);

        
        for(int e = head[node]; e != -1; e = next[e]) {

            stack[top++] = to[e];
        }
    }

    
    for(int i = 0; i < n; i++) {
        head[i] = -1;
    }

    edge = 0;

    for(int i = 1; i < n; i++) {

        int p = newParent[i];

        to[edge] = i;
        next[edge] = head[p];

        head[p] = edge;

        edge++;
    }

    
    int count = 0;
    top = 0;

    stack[top++] = 0;

    while(top > 0) {

        int node = stack[--top];

        order[count++] = node;

        for(int e = head[node]; e != -1; e = next[e]) {

            stack[top++] = to[e];
        }
    }

    for(int i = count - 1; i > 0; i--) {

        int node = order[i];

        int p = newParent[node];

        ans[p] += ans[node];
    }

    
    free(newParent);
    free(head);
    free(to);
    free(next);
    free(stack);
    free(prev);
    free(order);

    return ans;
}