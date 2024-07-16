

int main() {
    int a[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int i = 0, j;

    while (i < 3) {
        j = 0;
        while (j < 4) {
            printf("%d ", a[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    return 0;
}