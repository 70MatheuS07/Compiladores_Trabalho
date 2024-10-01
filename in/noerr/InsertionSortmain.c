int main() {
    int n=5;
    int arr[5] = {12, 11, 13, 5, 6};
    int i = 1, j, key;

    // Insertion Sort usando while
    while (i < n) {
        key = arr[i];
        j = i - 1;

        // Move elementos do arr[0..i-1] que são maiores que o key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }

    // Imprime o vetor ordenado
    printf("Insertion Sort - Vetor ordenado:\n");
    i = 0;
    int r=0;
    while (i < n) {
        r=arr[i];
        printf(r);
        printf("\n");
        i++;
    }
    printf("\n");
    return 0;
}
