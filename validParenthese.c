//其实就是栈操作

#define MAXSIZE 100

char stack[MAXSIZE];
int top = 0;

void push(char c)
{
    stack[top++] = top;
}

char pop()
{
    top--;
    return stack[top];
}

bool isValid(char *s)
{
    int i;
    char temp;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(s[i]);
            continue;
        }
        
        if (top == 0)
            return false;

        temp = pop();

        if (s[i] == ')')
        {
            if (temp == '(')
                continue;
        }

        if (s[i] == ']')
        {
            if (temp == '[')
                continue;
        }

        if (s[i] == '}')
        {
            if (temp == '{')
                continue;
        }

        return false;
    }

    if (top != 0)
        return false;

    return true;
}
