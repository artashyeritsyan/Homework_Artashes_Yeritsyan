int minimumSwaps(std::vector<int> arr) {
    int swapCount = 0;
    
    for(int i = 0; i < arr.size(); ++i) {
        if(arr[i] != i+1) {
            auto it = find(arr.begin(), arr.end(), i+1);
            int index = std::distance(arr.begin(), it);
            
            int tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
            
            ++swapCount;
        }
    }
    
    return swapCount;
}