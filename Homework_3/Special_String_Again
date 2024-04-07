long substrCount(int n, string s) {
    long count = 0;
    vector<pair<char, long>> ps;
long i = 0;
    while(i < n){
        long j = i + 1;
        while (j < n && s[j] == s[i]){
                j++;
        }
            ps.push_back(make_pair(s[i], j - i));
            i = j;
    }

    for (auto p : ps){
        count += (p.second * (p.second + 1)) / 2;
    }

    for (long i = 1; i < ps.size() - 1; i++){
        if (ps[i - 1].first == ps[i + 1].first && ps[i].second == 1)
            count += min(ps[i - 1].second, ps[i + 1].second);
    }

    return count;
}
