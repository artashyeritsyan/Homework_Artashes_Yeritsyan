long arrayManipulation(int n, std::vector<std::vector<int>> queries) {
    std::vector<long> arr(n + 1);
    long max = 0;
    long sum = 0;
    
    for(int i = 0; i < queries.size(); ++i) {        
        arr[queries[i][0] - 1] += queries[i][2];
        arr[queries[i][1]] -= queries[i][2];
    }    
    
    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if(sum > max) {
            max = sum;
        }
    }

    return max;
}