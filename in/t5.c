int main() {
    int x = 10;
    int y = 20;
    int resultado;

    resultado = (x == y);

    printf("x == y: %d\n", resultado);

    resultado = !(x == y);

    printf("!(x == y): %d\n", resultado);

    return 0;
}
