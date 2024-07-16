class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;
        int currentTank = 0;
        int startingIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            int temp = gas[i] - cost[i];
            totalTank += temp;
            currentTank += temp;
            
            if (currentTank < 0) {
                currentTank = 0;
                startingIndex = i + 1;
            }
        }
        if (totalTank < 0) {
            return -1;
        }
        return startingIndex;
    }
};