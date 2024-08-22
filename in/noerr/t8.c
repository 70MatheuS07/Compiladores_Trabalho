
void printf(){
    
}
// Função sem argumentos
void greet() {
    //printf("Hello, World!\n");
}

// Função com argumentos
int add(int a, int b) {
    return a + b;
}

int main() {
    // Chamada de função sem argumentos
    greet();
    
    // Chamada de função com argumentos
    int result = add(10, 20);
    //printf("The sum is: %d\n", result);
    
    return 0;
}