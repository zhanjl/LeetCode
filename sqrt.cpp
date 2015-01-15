//使用牛顿迭代法求平方根
//平方根的迭代公式是Xn+1 = (Xn + a/Xn) / 2
//只记住这个结论没有用，要理解牛顿法的原理
double abs(double num)
{
    if (num < 0)
        return -num;
    return num;
}
int sqrt(int x)
{
    double x1, x2;
    x1 = (double) x / 2;
    x2 = (x1 + x/x1) / 2;
    while (abs(x2 - x1) >= 1)
    {
        x1 = x2;
        x2 = (x1 + x/x1) / 2;
    }
    
    return (int)x2;
}
