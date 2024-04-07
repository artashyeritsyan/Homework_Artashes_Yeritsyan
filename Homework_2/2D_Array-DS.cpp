int sumOfHourglass (std::vector<vector<int>> ar, int indexI, int indexJ) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += ar[indexI][indexJ + i];  
        sum += ar[indexI + 2][indexJ + i];
    }
    sum += ar[indexI + 1][indexJ + 1];
    
    return sum;
}

int hourglassSum(std::vector<vector<int>> arr) {
    int size = arr.size();
    int max = sumOfHourglass(arr, 0, 0);
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            const int currentSum = sumOfHourglass(arr, i, j);
            
            max = max < currentSum ? currentSum : max;
        }        
    }
    
    return max;
}