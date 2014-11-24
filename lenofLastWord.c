int lengthOfLastWord(const char *s)
{
    if (s == NULL)
        return 0;
    
    int blank, result;
    char *lastword;
    
    lastword = NULL;
    blank = 1;
    while (*s)
    {
        if (*s != ' ')
        {
            if (blank == 1)
                lastword = s;
            blank = 0;
        }
        else
        {
            blank = 1;
        }
        s++;
    }

    if (lastword == NULL)
        return 0;

    result = 0;
    while (*lastword != ' ' && *lastword != '\0')
    {
        result++;
        lastword++;
    }

    return result;
}

