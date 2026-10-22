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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        int i =0 , j = 1 , cnt= 0, ans= 0;
        
        vector<pair<int, char>>vp;
        for(auto i : intervals){
            vp.push_back({i.end,'e'});
            vp.push_back({i.start,'s'});
        }
        sort(vp.begin(), vp.end());
        for(auto i : vp){
            if(i.second == 's') ++cnt;
            else --cnt;
            ans = max(cnt, ans);
        }
        return ans;
    }
};
