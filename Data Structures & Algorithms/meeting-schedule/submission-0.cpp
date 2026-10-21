/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a, Interval &b){
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size() , i = 0 , j=1 , cnt = 0 ;
        while(j < n ){
            int cs = intervals[i].start, ce = intervals[i].end;
            int ns = intervals[j].start, ne = intervals[j].end;

            if(ns >= ce){
                i =j; ++j;
            }else{
                if(ce >= ne){
                    i=j;++j; ++cnt;
                }else{
                    ++j; ++cnt;
                }
            }
        }
        return cnt == 0;
    }
};
