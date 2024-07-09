int main ()
{
    char c = "c";
    int x = 0;
    char coletado = "";

    while(coletado == "c" && x == 7){
        scanf("%c%d", &coletado, &x);

        if(coletado != "c" || x != 7){
            printf("tente novamente\n");
        }
    }

    return 0;
}