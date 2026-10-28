#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

void Push(int);
void display();
int POP();
int peep();
int Count();

int top = -1, stack[MAX], len = 0;

int main(void)
{
    int ch, val;

    while (1)
    {
        printf("\n\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. DISPLAY\n");
        printf("5. COUNT\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &val);
                Push(val);
                break;
            case 2:
                val = POP();
                if (val != -1)
                    printf("\nPopped element: %d", val);
                break;
            case 3:
                val = peep();
                if (val != -1)
                    printf("\nTop element: %d", val);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nTotal elements: %d", Count());
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}

void Push(int val)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        top++;
        stack[top] = val;
        len++;
    }
}

int POP()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
        return -1;
    }
    else
    {
        int val = stack[top];
        top--;
        len--;
        return val;
    }
}

int peep()
{
    if (top == -1)
    {
        printf("\nStack is empty!");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    if (top == -1)
    {
        printf("\nStack is empty!");
    }
    else
    {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int Count()
{
    return len;
}