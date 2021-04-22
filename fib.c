//
// Created by Nikita on 19.04.2021.
//
int fib(int k) {
    if (k<=0) return 0;
    else if (k<=2) return 1;
    int first = 1;
    int last = 1;
    int ans = 0;
    for (int i = 2; i<k; i++) {
        ans = first + last;
        first = last;
        last = ans;
    }
    return ans;
}


