class Solution {
public:
    double angleClock(int hours, int minute) {
        if(hours == 12){
            hours = 0;
        }
        double minutes = minute;
        double hour = hours * 5;
        hour += minutes / 12;
        double currHourAngle = 6 * hour;
        double currMinAngle = 6 * minutes;
        double ans = abs(currHourAngle - currMinAngle);
        return min(ans, 360 - ans); 
    }
};