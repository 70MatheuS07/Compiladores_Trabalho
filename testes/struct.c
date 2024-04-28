struct Geral
{
    int x;
    float y;
    char z[10];
};


typedef struct Geral 
{
    int x;
    float y;
    char z[10];
} tGeral;


int main()
{
    tGeral geral;

    geral.x = 7.0;
    geral.y = 9.0;
    geral.z[0] = "t";

    return 0;
}