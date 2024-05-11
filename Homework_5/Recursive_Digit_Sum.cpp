int superDigitRecursion(string str) {
    if (str.length() == 1) {
        return stoi(str);
    }
    long long sum = 0;
    for (int i = 0; i < str.length(); ++i) {
        sum += str[i] - '0';
    }
    return superDigitRecursion(to_string(sum));
}

int superDigit(string n, int k) {
    long long sum = 0;
    for (int i = 0; i < n.length(); ++i) {
        sum += n[i] - '0';
    }
    return superDigitRecursion(to_string(sum * k));
}