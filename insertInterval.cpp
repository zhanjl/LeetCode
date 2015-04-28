
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval>    result;
    
    int start, end;
    
    int i;
    bool findstart = false; 
    //寻找start
    for (i = 0; i < intervals.size(); i++) {
        if (newInterval.start <= intervals[i].start) {
            start = newInterval.start;
            findstart = true;
            break;
        } else if (newInterval.start <= intervals[i].end) {
            start = intervals[i].start;
            findstart = true;
            break;
        } else {
            result.push_back(intervals[i]);
        }
    }
    
    if (!findstart) {
        result.push_back(newInterval);
        return result;
    }
    
    bool findend = false; 
    //寻找end
    while (i < intervals.size()) {
        if (newInterval.end < intervals[i].start) {
            end = newInterval.end;
            findend = true;
            break;
        } else if (newInterval.end < intervals[i].end) {
            end = intervals[i].end;
            findend = true;
            i++;
            break;
        }
        i++;
    }
    
    if (!findend) {
        result.push_back(Interval(start, newInterval.end));
        return result;
    }
     
    result.push_back(Interval(start, end));
    while (i < intervals.size()) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

