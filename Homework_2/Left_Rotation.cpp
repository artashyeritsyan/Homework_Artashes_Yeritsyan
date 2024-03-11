std::vector<int> rotLeft(std::vector<int> a, int d) {
    std::vector<int> tmp_vec = a;
    int i = 0;
    
    while (i + d < a.size()) {
        tmp_vec[i] = a[i + d];
        ++i;
    }
    
    for (int j = 0; j < d; ++j) {
        tmp_vec[i] = a[j];
        ++i;
    }
    
    return tmp_vec;
}