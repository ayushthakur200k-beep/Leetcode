class Solution {
public:
    string below1000(int n) {
        vector<string> ones = {
            "", "One", "Two", "Three", "Four", "Five",
            "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen",
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };

        vector<string> tens = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty",
            "Sixty", "Seventy", "Eighty", "Ninety"
        };

        string ans;

        if (n >= 100) {
            ans += ones[n / 100] + " Hundred";
            n %= 100;

            if (n)
                ans += " ";
        }

        if (n >= 20) {
            ans += tens[n / 10];
            n %= 10;

            if (n)
                ans += " " + ones[n];
        }
        else if (n > 0) {
            ans += ones[n];
        }

        return ans;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        vector<int> value = {
            1000000000,
            1000000,
            1000,
            1
        };

        vector<string> name = {
            "Billion",
            "Million",
            "Thousand",
            ""
        };

        string ans;

        for (int i = 0; i < 4; i++) {
            if (num >= value[i]) {
                int part = num / value[i];
                num %= value[i];

                if (!ans.empty())
                    ans += " ";

                ans += below1000(part);

                if (!name[i].empty())
                    ans += " " + name[i];
            }
        }

        return ans;
    }
};