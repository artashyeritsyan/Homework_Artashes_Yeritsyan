#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

long repeatedString(string s, long n) {
    long count = 0;
    int remainder = n % s.length();
    
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') {
            ++count;
        }
    }
    count *= n / s.length();
    
    for(int i = 0; i < remainder; ++i) {
        if (s[i] == 'a') {
            ++count;
        }
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
