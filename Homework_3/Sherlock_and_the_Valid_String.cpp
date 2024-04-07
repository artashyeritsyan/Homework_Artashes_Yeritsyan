string isValid(string s) {
    unordered_map<char, int> char_map;
    unordered_map<int, int> integer_map;
    
    for (auto const i : s) {
        char_map[i]++;
    }
    
    for (auto const i : char_map) {
        integer_map[i.second]++;
    }
    
    std::string result = "NO";
    if (integer_map.size() == 1) {
        result = "YES";
    }
    else if (integer_map.size() == 2) {
        auto const first_iter = integer_map.begin();
        auto second_iter = integer_map.begin();
        second_iter++;
        
        if(abs(first_iter->first - second_iter->first) == 1
        && (first_iter->second == 1 || second_iter->second == 1)) {
            result = "YES";
        }
        else if((first_iter->first == 1 && first_iter->second == 1) 
        || (second_iter->first == 1 && second_iter->second == 1)) {
            result = "YES";

        }
    }
    
    return result;
}