
#define MAX_INT ((unsigned)(-1) >> 1)
#define MIN_INT (MAX_INT + 1)

int divide(int dividend, int divisor)
{
    if (divisor == 1)
       return dividend;

    if (dividend == MIN_INT && divisor == -1)
        return MAX_INT;

    unsigned end, sor;

    end = abs(dividend);
    sor = abs(divisor);

    unsigned res = 0;
    unsigned pow, temp;
    while (end >= sor) {
        pow = 1;
        temp = sor;
        while ((temp << 1) <= end) {
            pow = pow << 1;
            temp = temp << 1;
        }

        res += pow;
        end -= temp;
    }
    int sign;
    if ((dividend >= 0) ^ (divisor > 0))
       sign = -1;
    else
       sign = 1; 

    if (sign == 1)
        return res;
    else
        return -res;
}

