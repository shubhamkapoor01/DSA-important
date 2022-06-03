class UndergroundSystem {
private:
    map<pair<string, string>, pair<int, double>> averageTime;
    map<int, pair<string, int>> ongoing;
    
public:
    void checkIn(int id, string startStation, int timeIn) {
        if (ongoing.find(id) != ongoing.end()) {
            return;
        }
        ongoing[id] = {startStation, timeIn};
    }
    
    void checkOut(int id, string endStation, int timeOut) {
        if (ongoing.find(id) == ongoing.end()) {
            return;
        }
        
        string startStation = ongoing[id].first;
        double timeTaken = timeOut - ongoing[id].second;
        ongoing.erase(id);
        
        if (averageTime.find({startStation, endStation}) == averageTime.end()) {
            averageTime[{startStation, endStation}] = {1, timeTaken};
            return;
        }
        
        double entries = averageTime[{startStation, endStation}].first;
        double oldAverage = averageTime[{startStation, endStation}].second;
        double newAverage = (entries * oldAverage + timeTaken) / (entries + 1);
        
        averageTime[{startStation, endStation}] = {entries + 1, newAverage};
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return averageTime[{startStation, endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */