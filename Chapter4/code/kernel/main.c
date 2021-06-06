void kmain()
{
    char *screen = 0xb8000;
    int offset = 0;
    char *str = "Hello world";
    for(int i = 0;i < 22;i += 2)
    {
        screen[i] = str[i / 2];
        screen[i + 1] = 0x04;
    }
    return;
}