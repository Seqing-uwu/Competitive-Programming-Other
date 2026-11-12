class Solution {
public:
    string addStrings(string num1, string num2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        
        string result = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        result.reserve(max(i, j) + 1);

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += num1[i] - '0';
                i -= 1;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j -= 1;
            }

            carry = sum/10;
            result += sum % 10 + '0';
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
