int main(){
    char nome[40] = {'a', 'b', 'c', 'd'};
    int vet[4] = {0, 2, 3, 4};
    float vet_float[4] = {0.1, 2.2, 3.3, 4.4};

    char c = nome[4];
    int i = vet[4];
    float f = vet_float[4];

    printf(c);
    printf(i);
    printf(f);

    return 0;
}