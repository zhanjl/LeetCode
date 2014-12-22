
double pow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n == -1)
        return 1.0/x;
    double temp;

    temp = pow(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    return temp * temp * pow(x, n % 2);
}
