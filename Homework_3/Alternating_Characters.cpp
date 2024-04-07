int alternatingCharacters(std::string s) {
    int count = 0;
    
    for (int i = 0; i < s.length() - 1; ++i) {
        if(s[i] == s[i + 1]) {
            ++count;
            continue;
        }
    }
    
    return count;
}