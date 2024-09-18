int main ()
{
    char c = 'c';
    int x = 0;
    char coletado = 'd';

   while(coletado == 'c' && x == 7){
        scanf(c);
        scanf(x);

        if(coletado != 'd' || x != 7){
            //printf("tente novamente\n");
        }
    }

    return 0;
}