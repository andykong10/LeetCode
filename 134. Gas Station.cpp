// ***
//
// There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station
// (i+1). You begin the journey with an empty tank at one of the gas stations.
//
// Return the starting gas station's index if you can travel around the circuit once in the clockwise direction,
// otherwise return -1.
//
// Note:
// - If there exists a solution, it is guaranteed to be unique.
// - Both input arrays are non-empty and have the same length.
// - Each element in the input arrays is a non-negative integer.
//
// Example 1:
//
// Input:
// station = [0,1,2,3,4]
// gas     = [1,2,3,4,5]
// cost    = [3,4,5,1,2]
//
// Output: 3
//
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.
//
// Example 2:
//
// Input:
// station = [0,1,2]
// gas     = [2,3,4]
// cost    = [3,4,3]
//
// Output: -1
//
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.
//
// ***
//
// If we want to travel around the circuit, then it must be the case that netGasLeft = sum(gas) - sum(cost) >= 0.
// currentGas is what we have left in our gas tank when we *leave* each city, if this number is less than or equal to
// 0, this means we cannot *leave* city i. So we set the next start to city i + 1. There is no need to test start from
// cities between old start and city i + 1 because we have traveled through them with positive tank (every time we leave
// city, we must have non negative gas left in our gas tank; if we test that city again, we will be initilized with 0
// initial gas, which will not perform any better)
//
// Note that gas[i] is how much gas you can fill when you *leave* city i;
// cost[i] is how much it costs when you *leave* city i.

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int netGasLeft = 0;  // Remaining gas after travel through all the cities.
    int currentGas = 0;  // How much gas we have in the tank when you *leave* each city.
    int startCityCandidate = 0;

    for (int i = 0; i < gas.size(); ++i) {
        netGasLeft += gas[i] - cost[i];
        currentGas += gas[i] - cost[i];
        if (currentGas < 0) {
            startCityCandidate = i + 1;
            currentGas = 0;
        }
    }

    return netGasLeft < 0 ? -1 : startCityCandidate;
}
