vector<int> spiralOrder(vector<vector<int> > &matrix)
{
    vector<int> result;
    if (matrix.size() == 0)
        return result;
    
    int row, col;
    row = matrix.size();
    col = matrix[0].size();
  
    if (row == 1)
        return matrix[0];

    if (col == 1) {
        for (int k = 0; k < row; k++)
            result.push_back(matrix[k][0]);
        return result;
    } 
    //一圈一圈的处理
    //(i,j)是左上角的起始元素
    int i, j;
    i = j = 0;
    
    while (i < row / 2 && j < col / 2) {
        //把(i,j)为左上角的矩形四周元素放入result中
        //该矩形的宽为col - 2 * j，高为row - 2 * i
        int row_index, col_index;

        col_index = j;
        for (int k = 1; k < col - 2 * j; k++) {
            result.push_back(matrix[i][col_index]);
            col_index++; 
        }

        row_index = i;
        for (int k = 1; k < row - 2 * i; k++) {
            result.push_back(matrix[row_index][col - j - 1]);
            row_index++;
        }

        col_index = col - j - 1;
        for (int k = 1; k < col - 2 * j; k++) {
            result.push_back(matrix[row - i - 1][col_index]);
            col_index--;
        }

        row_index = row - i - 1;
        for (int k = 1; k < row -2 * i; k++) {
            result.push_back(matrix[row_index][j]);
            row_index--;
        }
        i++;
        j++;
    }

    //如果行为奇数，那么最后会剩下一行，该行的元素个数为col - j
    if (row % 2 != 0) {
        for (int k = j; k < col - j; k++)
            result.push_back(matrix[i][k]);
    } else if (col % 2 != 0) {      //如果列为奇数，那么最后会剩下一列
        for (int k = i; k < row - i; k++)
            result.push_back(matrix[k][j]);
    }
    return result;
}
