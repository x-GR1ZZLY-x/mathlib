#pragma once
#include <limits.h>

static int add(long long a, long long b, long long *result){
    if(b > 0 && a > LLONG_MAX - b){
        return 0;
    }

    if(b < 0 && a < LLONG_MIN - b){
        return 0;
    }
    
    *result = a + b;

    return 1;
}

static int sub(long long a, long long b, long long *result){
    if(b > 0 && a < LLONG_MIN + b){
        return 0;
    }

    if(b < 0 && a > LLONG_MAX + b){
        return 0;
    }

    *result = a - b;

    return 1;
}

static int mul(long long a, long long b, long long *result){
    if(a == LLONG_MIN && b == -1){
        return 0;
    }
    if(b == LLONG_MIN && a == -1){
        return 0;
    }
    if(a > 0){
        if(b > 0){
            if(a > LLONG_MAX / b){
                return 0;
            }
        }else{
            if(b < LLONG_MIN / a){
                return 0;
            }
        }
    }else{
        if(b > 0){
            if(a < LLONG_MIN / b){
                return 0;
            }
        }else{
            if(a != 0 && b < LLONG_MAX / a){
                return 0;
            }
        }
    }

    *result = a * b;

    return 1;
}

static int div(long long a, long long b, long long *result){
    if(b == 0){
        return 0;
    }
    if(a == LLONG_MIN && b == -1){
        return 0;
    }

    *result = a / b;
    
    return 1;
}

static int pow(long long base, long long exp, long long *result){
    long long cur = 1;
    
    for(long long i = 0; i < exp; ++i){
        if(cur > 0){
            if(base > 0){
                if(cur > LLONG_MAX / base){
                    return 0;
                }
            }else{
                if(base < LLONG_MIN / cur){
                    return 0;
                }
            }
        }else{
            if(base > 0){
                if(cur < LLONG_MIN / base){
                    return 0;
                }
            }else{
                if(cur != 0 && base < LLONG_MAX / cur){
                    return 0;
                }
            }
        }
        cur *= base;
    }

    *result = cur;

    return 1;
}

static int fact(long long n, long long *result){
    if(n < 0){
        return 0;
    }
    if(n <= 1) {
        *result = 1;
        return 1;
    }

    long long prev = 0;

    if(!fact(n - 1, &prev)){
        return 0;
    }

    if(prev > LLONG_MAX / n) return 0;
    
    *result = n * prev;

    return 1;
}