bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
    return lhs.second <= rhs.first;
}

class MyCalendar {
public:
    MyCalendar() : bookings(cmp) {}

    bool book(int start, int end) {
        return bookings.emplace(start, end).second;
    }

private:
    set<pair<int, int>, decltype(cmp)*> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */