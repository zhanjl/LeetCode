int findPeakElement(const vector<int> &num) {
        int left, right, mid;
        if (num.size() == 1)
            return 0;
        left = 0;
        right = num.size() - 1;
        
        while (left <= right) {
            mid = (left + right) / 2;
            
            if (mid == 0) {
                if (num[mid] > num[mid+1])
                    break;
                left = mid + 1;
                continue;
            } else if (mid == num.size() - 1) {
                if (num[mid] > num[mid-1])
                    break;
                right = mid - 1;
                continue;
            }
            
            if ((num[mid] > num[mid-1]) && (num[mid] > num[mid+1]))
                break;
            
            if (num[mid] > num[mid-1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return mid;
    }
