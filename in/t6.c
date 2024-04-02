typedef struct
{
    float x;
    float y;
} tPonto;

enum semana {
    DOMINGO,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main(){
    tPonto ponto;

    ponto.x = 10.50;
    ponto.y = 20.50;

    printf("Área: %.2fx%.2f\n", ponto.x, ponto.y);

    return 0;
}