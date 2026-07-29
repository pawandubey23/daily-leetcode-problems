class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // 1. Negative numbers are not palindromes (e.g., -121 reads as 121-).
        // 2. Numbers ending in 0 are not palindromes, except for 0 itself.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        
        // Keep reversing the last digits until we reach the middle of the number.
        // We know we crossed the middle when the remaining 'x' becomes <= 'reversedHalf'.
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even-length numbers, x should equal reversedHalf (e.g., 12 == 12).
        // For odd-length numbers, we get rid of the middle digit using reversedHalf / 10 (e.g., 12321 -> x = 12, reversedHalf = 123 -> 123/10 = 12).
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
