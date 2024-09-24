

int main() {
    int a[5] ={0, 1, 11};
    int i = 0, j;
    
    int y = a[2];

    // Está dando erro aqui
    a[2] = 3;

    // Necessário bubblesort

    printf(y);

    while (i < 3) {
        j = 0;
        while (j < 4) {
            //printf("%d ", a[i][j]);
            j++;
        }
        //printf("\n");
        i++;
    }

    return 0;
}