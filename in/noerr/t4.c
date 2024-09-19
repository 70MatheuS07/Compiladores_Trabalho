int main ()
{
    char c = "c";
    int x = 7;
    char coletado = 'c';

    while(coletado == 'c' && x == 7){
        //scanf("%c%d", &coletado, &x);

        if(c != "a" || x != 7){
            coletado = 'a';
            x = 0;
        }
    }

    return 0;
}