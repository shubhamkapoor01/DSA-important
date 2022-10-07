class MyCalendarThree {
    map<int, int> bookings;
    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        bookings[start] ++;
        bookings[end] --;
        
        int currBookings = 0;
        int maxBookings = 0;
        
        for (auto i: bookings) {
            currBookings += i.second;
            maxBookings = max(maxBookings, currBookings);
        }
        
        return maxBookings;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */