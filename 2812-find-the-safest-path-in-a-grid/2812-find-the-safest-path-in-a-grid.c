typedef struct {
    int d, x, y;
} Cell;

int parent[160000];
int rank_[160000];

int cmp(const void *a, const void *b) {
    return ((Cell *)b)->d - ((Cell *)a)->d;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (rank_[a] < rank_[b])
        parent[a] = b;
    else if (rank_[a] > rank_[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank_[a]++;
    }
}

int maximumSafenessFactor(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int total = n * n;

    int *dist = (int *)malloc(total * sizeof(int));
    bool *active = (bool *)calloc(total, sizeof(bool));

    for (int i = 0; i < total; i++)
        dist[i] = -1;

    int *queue = (int *)malloc(total * sizeof(int));
    int front = 0, rear = 0;

    // Multi-source BFS
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                int id = i * n + j;
                dist[id] = 0;
                queue[rear++] = id;
            }
        }
    }

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (front < rear) {
        int id = queue[front++];
        int x = id / n;
        int y = id % n;

        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int nid = nx * n + ny;
                if (dist[nid] == -1) {
                    dist[nid] = dist[id] + 1;
                    queue[rear++] = nid;
                }
            }
        }
    }

    Cell *cells = (Cell *)malloc(total * sizeof(Cell));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cells[idx++] = (Cell){dist[i * n + j], i, j};
        }
    }

    qsort(cells, total, sizeof(Cell), cmp);

    for (int i = 0; i < total; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }

    int start = 0;
    int end = total - 1;

    for (int i = 0; i < total; i++) {
        int x = cells[i].x;
        int y = cells[i].y;
        int id = x * n + y;

        active[id] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int nid = nx * n + ny;
                if (active[nid])
                    unite(id, nid);
            }
        }

        if (active[start] && active[end] && find(start) == find(end)) {
            int ans = cells[i].d;
            free(dist);
            free(active);
            free(queue);
            free(cells);
            return ans;
        }
    }

    free(dist);
    free(active);
    free(queue);
    free(cells);
    return 0;
}