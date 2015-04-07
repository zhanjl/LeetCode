bool compare(Interval val1, Interval val2)
{
    return val1.start < val2.start;
}

vector<Interval> merge(vector<Interval> &intervals) 
{
    vector<Interval> result;
    int start, end;
    if (intervals.size() == 0) {
        return result;
    }
    //先按start从小到大排序
    sort(intervals.begin(), intervals.end(), compare);
    start = intervals[0].start;
    end = intervals[0].end;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start > end) {
            result.push_back(Interval(start, end));
            start = intervals[i].start;
            end = intervals[i].end;
        } else if (intervals[i].end > end) {
            end = intervals[i].end;
        }
    }
    
    result.push_back(Interval(start, end));
    return result;
}
