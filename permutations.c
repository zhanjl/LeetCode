//这一类回朔问题都是用循环递归来解
//要想明白这种思维方法：
//只需考虑排序后某一个位置的元素，因为其他位置的求值方法都一样
//对这个位置，采用循环，把所有没放入其他位置的元素都放到此位置。
void geneper(int data[], int n, int item[], int index, int bl[])
{
    if (index == n)
    {
        int i;
        for (i = 0; i < index; i++)
            printf("%d ", item[i]);
        printf("\n");
        return;
    }

    int i, j, k;    //如果有重复元素，把注释的部分加上
    //int prev[n];
    //int flag;
    //k = 0;
    for (i = 0; i < n; i++)
    {
        if (!bl[i])
        {
            //判断data[i]的值是否在此位置出现过
            //flag = 0;
            //for (j = 0; j < k; j++)
            //{
            //    if (prev[j] == data[i])
            //    {
            //        flag = 1;
            //        break;
            //    }
            //}
            //if (flag == 1)
            //    continue;
            //prev[k++] = data[i];
            bl[i] = 1;
            item[index++] = data[i];
            geneper(data, n, item, index, bl);
            bl[i] = 0;
            index--;
        }
    }
}
void permute(int data[], int n)
{
    int bl[n], item[n];
    int i;
    for (i = 0; i < n; i++)
        bl[i] = 0;
    geneper(data, n, item, 0, bl);
}

//对于无重复元素的迭代解法
//使用C++来求解比较方便
//有重复元素的迭代解法比较复杂
vector<vector<int> > permute(vector<int> data)
{
  vector<vector<int> > res;
  vector<int> first;
  if (data.size() == 0)
      return res;
  first.push_back(data[0])
  res.push_back(first);
  int i, j, k;
  for (i = 1; i < data.size(); i++)
  {
      vector<vector<int> > temp;
      for (j = 0; j < res.size(); j++)
      {
          for (vector<int>::iterator it = item.begin();
                                     it != item.end()+1; it++)
          {
              vector<int> item;
              item = res[j];
              item.insert(it, data[i]);
              temp.push_back(item);
          }
          res = temp;
      }
  }
  return tes;
}
