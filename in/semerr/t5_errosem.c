int RetornaDiferenca(int x, int y){
    if(x>y) return 1;
    else if(x<y) return -1;
    return 0;
}
int printf(){

}
int main ()
{
    int x = 2;
    int y = 2;
    
    if(RetornaDiferenca(x) == 0)
    {
        printf();
    }
    else
    {
        //printf("X diferente Y");
    }

    return 0;
}