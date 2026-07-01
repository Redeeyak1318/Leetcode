#define MAX_N 400
#define MAX_CELLS (MAX_N * MAX_N)
#define NUM_DIRS 4

static const int DIRECTIONS[NUM_DIRS][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

static int safeness[MAX_N][MAX_N];
static bool visited[MAX_N][MAX_N];

static int queue_row[MAX_CELLS];
static int queue_col[MAX_CELLS];

static int heap_safe[MAX_CELLS];
static int heap_row[MAX_CELLS];
static int heap_col[MAX_CELLS];
static int heap_size;

static void heap_swap(int idx_a, int idx_b) {
    int tmp_safe = heap_safe[idx_a];
    int tmp_row = heap_row[idx_a];
    int tmp_col = heap_col[idx_a];
    heap_safe[idx_a] = heap_safe[idx_b];
    heap_row[idx_a] = heap_row[idx_b];
    heap_col[idx_a] = heap_col[idx_b];
    heap_safe[idx_b] = tmp_safe;
    heap_row[idx_b] = tmp_row;
    heap_col[idx_b] = tmp_col;
}

static void heap_push(int safe_val, int row, int col) {
    int idx = heap_size++;
    heap_safe[idx] = safe_val;
    heap_row[idx] = row;
    heap_col[idx] = col;

    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap_safe[parent] >= heap_safe[idx]) {
            break;
        }
        heap_swap(parent, idx);
        idx = parent;
    }
}

static void heap_pop(int* safe_val, int* row, int* col) {
    *safe_val = heap_safe[0];
    *row = heap_row[0];
    *col = heap_col[0];

    heap_size--;
    if (heap_size == 0) {
        return;
    }

    heap_safe[0] = heap_safe[heap_size];
    heap_row[0] = heap_row[heap_size];
    heap_col[0] = heap_col[heap_size];

    int idx = 0;
    while (true) {
        int largest = idx;
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;

        if (left < heap_size && heap_safe[left] > heap_safe[largest]) {
            largest = left;
        }
        if (right < heap_size && heap_safe[right] > heap_safe[largest]) {
            largest = right;
        }
        if (largest == idx) {
            break;
        }
        heap_swap(idx, largest);
        idx = largest;
    }
}

static bool is_valid(int row, int col, int size) {
    return row >= 0 && row < size && col >= 0 && col < size;
}

static void compute_safeness(int** grid, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            safeness[row][col] = -1;
            visited[row][col] = false;
        }
    }

    int head = 0;
    int tail = 0;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (grid[row][col] == 1) {
                safeness[row][col] = 0;
                queue_row[head] = row;
                queue_col[head] = col;
                head++;
            }
        }
    }

    while (tail < head) {
        int row = queue_row[tail];
        int col = queue_col[tail];
        tail++;

        for (int d = 0; d < NUM_DIRS; d++) {
            int new_row = row + DIRECTIONS[d][0];
            int new_col = col + DIRECTIONS[d][1];

            if (is_valid(new_row, new_col, size) &&
                safeness[new_row][new_col] == -1) {
                safeness[new_row][new_col] = safeness[row][col] + 1;
                queue_row[head] = new_row;
                queue_col[head] = new_col;
                head++;
            }
        }
    }
}

static int find_max_safeness_path(int size) {
    heap_size = 0;
    heap_push(safeness[0][0], 0, 0);
    visited[0][0] = true;

    while (heap_size > 0) {
        int path_safeness;
        int row;
        int col;
        heap_pop(&path_safeness, &row, &col);

        if (row == size - 1 && col == size - 1) {
            return path_safeness;
        }

        for (int d = 0; d < NUM_DIRS; d++) {
            int new_row = row + DIRECTIONS[d][0];
            int new_col = col + DIRECTIONS[d][1];

            if (is_valid(new_row, new_col, size) &&
                !visited[new_row][new_col]) {
                visited[new_row][new_col] = true;
                int new_safeness = safeness[new_row][new_col];
                if (new_safeness > path_safeness) {
                    new_safeness = path_safeness;
                }
                heap_push(new_safeness, new_row, new_col);
            }
        }
    }

    return 0;
}

int maximumSafenessFactor(int** grid, int grid_size, int* grid_col_size) {
    (void)grid_col_size;

    if (grid[0][0] == 1 || grid[grid_size - 1][grid_size - 1] == 1) {
        return 0;
    }

    compute_safeness(grid, grid_size);
    return find_max_safeness_path(grid_size);
}
