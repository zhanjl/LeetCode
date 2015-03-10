#include <vector>
using namespace std;
int findMin(vector<int> &num)
{
    int size = num.size();
    int low, high, mid;

    low = 0, high = size - 1;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (low == mid) {   //还剩两个元素
            if (num[low] > num[high]) {
                low++;
            }
            break;
        }
        if (num[low] < num[high]) {     //元素完全有序
            break;
        } else if (num[mid] < num[low]) {
            high = mid;
        } else if (num[mid] > num[low]) {
            low = mid + 1;
        } else if (num[mid] == num[low]) { //判断[low,mid]或者[mid+1,high]是直线
            bool first = true;
            for (int i = low; i < mid; i++) {
               if (num[i] != num[i+1]) {
                   first = false;
                   break;
               }
            }

            if (first) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    }
    return num[low];
}

int main()
{

    return 0;
}
