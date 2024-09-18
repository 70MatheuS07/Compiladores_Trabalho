int main ()
{
    int x = 1;
    int y = 1;
    x++;
    printf(x);
    int novo= y + x;
    printf(novo);
    y -= x;
    printf(y);
    y /= x;
    printf(y);
    y *= x;
    printf(y);
    y %= x;
    printf(y);

    return 0;
}