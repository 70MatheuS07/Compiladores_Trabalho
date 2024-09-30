
int main() {
    // Inicializa o vetor de inteiros
    int n = 7;
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    
    // Bubble Sort usando while
    int i = 0;
    while (i < (n-1)) {
        int j = 0;
        while (j < (n - i - 1)) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            j++;
        }
        i++;
    }

    int r;
    // Imprime o vetor ordenado
    printf("Vetor ordenado\n");
    
    i = 0;
    while (i < n) {
        r = arr[i];
        printf(r);  
        printf("\n");
        i++;
    }

    return 0;
}
