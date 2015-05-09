string mulAdd(string num1, string num2, int offset)
{
    string result;
    int index, remainder, mul;
    for (int i = 0; i < offset; i++)
        result.push_back(num1[i]);
    remainder = 0;
    for (index = offset; index < num1.size(); index++) {
        mul = (num1[index] - '0') + (num2[index-offset] - '0') + remainder;
        result.push_back(mul%10 + '0');
        remainder = mul / 10;
    } 

    while ((index - offset) < num2.size()) {
        mul = (num2[index-offset] - '0') + remainder;
        result.push_back(mul%10 + '0');
        remainder = mul / 10;
        index++;
    }
    if (remainder != 0) {
        result.push_back(remainder + '0');
    } return result;
}

string multiply(string num1, string num2)
{
    string result, temp;
    int remainder, mul;
    if (!num1.size() || !num2.size())
       return result;
    //特殊情况，有一个数字为0,则结果为0
    if (num1[0] == '0' || num2[0] == '0')
        return string("0");    
    if (num1.size() < num2.size()) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < num2.size(); i++) {
        remainder = 0;
        string cur;
        for (int j = 0; j < num1.size(); j++) {
            mul = (num2[i] - '0') * (num1[j] - '0') + remainder;
            cur.push_back(mul%10 + '0');
            remainder = mul / 10;
        }
        if (remainder != 0)
            cur.push_back(remainder + '0');

        if (result.size() == 0) {
            result = cur;
        } else {
            //cout << result << endl;
            int offset = i;
           // while (offset--)
           //     cout<<"0";
          //  cout << cur << endl;
            result = mulAdd(result, cur, i);
          //  cout << result << endl;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

