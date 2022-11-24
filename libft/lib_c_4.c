#include<stdlib.h>

char *ft_strchr(const char *str, int c)
{
    int i;
    char *cp;

    i = -1;
    cp = (char *)str;
    while(str[++i])
    {
        if(str[i] == c)
            return (cp + i);
    }
    return NULL;
}

char *ft_strrchr(const char *str, int c)
{
    int i;
    char *cp;
    char *tcp;

    i = -1;
    cp = (char *)str;
    tcp = cp;
    while(cp[++i])
    {
        if(cp[i] == c)
            tcp = cp+i;
    }
    return (tcp);
}
 
#include<stdio.h>
int main()
{
    char name[20] = "JooSoonhyeong";
    printf("%s\n", (ft_strchr(name, 'o')));
    printf("%s", (ft_strrchr(name, 'o')));

}