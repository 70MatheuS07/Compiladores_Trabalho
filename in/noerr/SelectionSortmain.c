int main() {
    int n = 5;
    int arr[5] = {64, 25, 12, 22, 11};
    int i = 0, j, min_idx, temp;

    // Selection Sort usando while
    while (i < (n - 1)) {
        min_idx = i;
        j = i + 1;
        while (j < n) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
            j++;
        }
        // Troca o elemento mínimo com o primeiro elemento não ordenado
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        i++;
    }

    // Imprime o vetor ordenado
    printf("Selection Sort - Vetor ordenado:\n");
    i = 0;
    int r;
    while (i < n) {
        r=arr[i];
        printf(r);
        printf("\n");
        i++;
    }
    printf("\n");
    return 0;
}