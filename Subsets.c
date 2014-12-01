//循环递归
void nEleSet(int A[], int n, int set[], int k, int index, int beg)
{
    int i;
    if (k == 0)
    {
        for (i = 0; i < index; i++)
            printf("%d ", set[i]);
        printf("\n");
        return;
    }

    for (i = beg; (i + k) <= n; i++)
    {
        set[index] = A[i];
        nEleSet(A, n, set, k - 1, index + 1, i + 1);
    }
    return;
}

void subsets(int A[], int n)
{
    int set[n];
    int i;
    for (i = 1; i <= n; i++)
        nEleSet(A, n, set, i, 0, 0);
    return;
}

//C++迭代方法，该解法的思考角度很有意思
//vector<vector<int> > subsets(vector<int> S)
//{
//  vector<vector<int> > result;
//  vector<int> empty;
//  result.push_back(empty);
//  int i, j;
//  for (i = 0; i < S.size(); i++)
//  {
//     vector<vector<int> > temp = result;
//     for (j = 0; j < result.size(); j++)
//     {
//          result[j].push_back(S[i]);
//          temp.push_back(result[j]);
//     }
//     result = temp; 
//  }
//
//  return result;
//}
