int main() {
    int x = 5;  // Suponha que x seja 5
    int y = 3;  // Suponha que y seja 3
    int z = 2;  // Suponha que z seja 2

    // Cálculo 1
    int result1 = x + z;  // result1 = x + z (equivalente ao 'add $t1, $t0, $t2' no MIPS)

    // Cálculo 2
    x = y + result1;  // x é sobrescrito com y + result1 (equivalente ao 'add $t0, $t9, $t1')
    printf(x);
    return 0;
}