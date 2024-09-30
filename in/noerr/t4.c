int main ()
{
    char c = "c";
    int x = 7;
    char coletado = 'c';
    while((coletado=='c') || (x==7)){
        printf("Digite um numero:");
        scanf(x);
        if(x==4){
            printf("Digite uma letra:");
            scanf(coletado);
            printf(coletado);
            printf("\n");
        }
    }

    return 0;
}