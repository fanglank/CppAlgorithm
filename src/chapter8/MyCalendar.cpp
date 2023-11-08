#include <map>
using namespace std;
class MyCalendar {
private:
    map<int, int> events;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = events.lower_bound(start);
        // 与后一个时间段重叠
        if (it != events.end() && it->first < end) {
            return false;
        }
        // 与前一个时间段重叠
        if (it != events.begin() && (--it)->second > start) {
            return false;
        }
        events[start] = end;
        return true;
    }
};