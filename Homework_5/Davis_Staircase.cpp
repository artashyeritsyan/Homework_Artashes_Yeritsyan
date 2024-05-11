int stepPerms(int n) {
    
    switch (n)
    {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 4;
    case 4:
        return 7;
    case 5:
        return 13;
    }
    return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
}