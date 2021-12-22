#include <stdio.h>

int top = -1;

char stack[100][100];

void push(char str[], int length)
{
    top++;
    int j;
    for (j = 0; j < length; j++)
    {
        stack[top][j] = str[j];
    }
}

void pop()
{

    for (int i = 0; stack[top][i] != '\0'; i++)
    {
        printf("%c", stack[top][i]);
    }
    printf(" ");
    top--;
}

int main()
{
    int n, length = 0;
    printf("Enter total no. of words: ");
    scanf("%d", &n);
    char str[100];
    printf("Enter String: ");
    for (int i = 0; i < n; i++)
    {
        length = 0;
        scanf("%s", str);
        for (int j = 0; str[j] != '\0'; j++)
        {
            length++;
        }

        push(str, length);
    }
    printf("Reverse String: ");
    for (int i = 0; i < n; i++)
    {
        pop();
    }

    return 0;
}