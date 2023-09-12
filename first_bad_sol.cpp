// Given n = 5, and version = 4 is the first bad version.
// divide and conquer algorithm

// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true

// Then 4 is the first bad version. 

//time complexity :: O(log n)
//space complexity :: O(1)

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class solution {
    int l;
public:
    solution(int m) {
        l = m;
    }

    bool isBadVersion(int version) {
        if (version >= l) {
            return true;
        } else {
            return false;
        }
    }

    int firstBadVersion(int n) {
        long long int beg, last, mid;
        beg = 1, last = n;
        long int pos = n + 1; // Initialize pos to a value larger than n

        while (beg <= last) {
            // Ensure you calculate mid values this way, otherwise, it could cause overflow
            mid = beg + (last - beg) / 2;
            bool x = isBadVersion(mid);

            if (x == true) {
                pos = mid;
                last = mid - 1;
            } else {
                beg = mid + 1;
            }
        }

        // Return the first index of a faulty product, or -1 if all versions are good
        return (pos <= n) ? pos : -1;
    }
};

int main() {
    solution s(7);
    int result = s.firstBadVersion(30);
    if (result != -1) {
        cout << "The first bad version is: " << result << endl;
    } else {
        cout << "No bad versions found." << endl;
    }
}
