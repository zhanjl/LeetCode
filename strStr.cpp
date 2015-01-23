void makenext(char *partten, int *next)
{
    int size;
    size = strlen(partten);
    next[0] = -1;
    if (size == 1)
        return;
    next[1] = 0;
    int i, k;

    for (i = 2; i < size; i++)
    {
        k = next[i-1];

        while (k >= 0 && partten[k] != partten[i-1])
            k = next[k];
        k++;
        next[i] = k;
    }

    return;
}

int strStr(char *haystack, char *needle)
{
    if (haystack == NULL || strlen(haystack) < strlen(needle))
        return -1;
    if (needle == NULL)
        return 0;

     int hayLen, needleLen;
     int i, j, res;
     hayLen = strlen(haystack);
     needleLen = strlen(needle);
     if (needleLen == 0)
         return 0;
     int next[needleLen];
     makenext(needle, next);
     res = -1;
     i = 0, j = 0;
     while (i < hayLen)
     {
        while (j < needleLen)
        {
            if (haystack[i] != needle[j])
                break;
            i++;
            j++;
        }
        if (j == needleLen)
        {
            res = i - needleLen;
            break;
        }
        j = next[j];
        if (j == -1)
        {
            i++;
            j = 0;
        }
    }
    return res; 
}
