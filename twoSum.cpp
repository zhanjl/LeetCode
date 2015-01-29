vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> num(numbers);
    vector<int> result;
    sort(num.begin(), num.end());
    int num1, num2, len;
    int i, j;
    len = num.size();
    i = 0, j = len - 1;

    while (i <= j) {
        if ((num[i] + num[j] == target)) {
            num1 = num[i];
            num2 = num[j];
            break;
        } else if ((num[i] + num[j]) < target) {
            i++;
        } else {
            j--;
        }
    }
    
    for (i = 0; i < len; i++) {
        if (numbers[i] == num1)
            break;
    }

    for (j = 0; j < len; j++) {
        if (numbers[j] == num2 && j != i)
            break;
    }
    
    i++;
    j++; 
    if (i < j) {
        result.push_back(i);
        result.push_back(j);
    } else {
        result.push_back(j);
        result.push_back(i);
    }
    return result;
}


vector<int> twoSum(vector<int> &numbers, int target) {
    hash_set<int> num;
    vector<int> result, temp;
    for (int i = 0; i < number.size(); i++)
        num.insert(numbers[i]);
    
    for (int i = 0; i < numbers.size(); i++) {
        if (num.count(target - numbers[i]))
            break;
    }
    temp = target - numbers[i];
    result.push_back(i+1);
    
    while (i < numbers.size())
    {
        if (numbers[i] == temp)
           break; 
        i++;
    }
    result.push_back(i+1);

    return result;
}

vector<int> twoSum(vector<int> &numbers, int target) {
    unordered_map<int, int> hash;
    unordered_map<int, int>::iterator it;
    vector<int> result;
    int size;
    size = numbers.size();
    for (int i = size - 1; i >= 0; i--) {
        if ((it = hash.find(target - numbers[i])) != hash.end()) {
            result.push_back(i+1);
            result.push_back(*it.second + 1);
            break;
        }
        hash.insert(make_pair(numbers[i], i));
    }
    return result;
}
