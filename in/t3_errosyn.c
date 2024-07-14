int RetornaDiferenca(int x, int y){
    if(x>y) return 1;
    else if(x<y) return -1;
    return 0;
}

int main ()
{
    int x = 2;
    int y = 2;
    
    if(RetornaDiferenca(x,y) == 0)
    {
        printf("X igual Y")
        //esquecendo ";"
    }
    else
    {
        printf("X diferente Y");
    }

    return 0;
}