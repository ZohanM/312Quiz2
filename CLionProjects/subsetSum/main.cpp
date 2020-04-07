
#include <assert.h>

bool SubsetSum(int x[], int n, int k, int  v) {
    if (v == 0 && k == 0) {
        return true;
    }
    if(v != 0 && k == 0){
        return false;
    }
    if(n == 0){
        return false;
    }
    int res1 = 0;
    if(v >= x[0]){
        res1 = SubsetSum(x + 1, n - 1, k - 1, v - x[0]);
    }
    int res2 = SubsetSum(x + 1, n - 1, k, v);
    return res1 + res2 > 0;
}

int main() {
    int universal[100];
    for (int i = 0; i < 100; i++)
        universal[i] = i + 1;
    assert(!SubsetSum(universal, 100, 2, 0));
    assert(!SubsetSum(universal, 100, 1, 0));
    assert(SubsetSum(universal, 100, 2, 5));
    assert(SubsetSum(universal, 100, 2, 99));
    assert(SubsetSum(universal, 100, 2, 80));
    assert(!SubsetSum(universal, 100, 2, 2));
    assert(!SubsetSum(universal, 0, 5, 2));
    assert(!SubsetSum(universal, 100, 2, 1));
}
