int main ()
{
    char c = "c";
    int long x = 0;
    char coletado = "";

    while(1){
        scanf("%c%d", &coletado, &x);

        if(coletado != "c" || x != 7){
            printf("tente novamente\n");
        }

        if(coletado == "c" && x == 7){
            break;
        }
    }



    return 0;
}