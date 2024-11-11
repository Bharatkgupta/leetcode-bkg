class Solution {
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string toWords(int num) {
        int one = num%10;
        int ten = (num/10)%10;
        int hundred = num/100;
        
        string words;
        
        if(ten == 1) {
            words += ones[ten*10+one];
        } else {
            if(one && ten) {
                words += tens[ten] + " " + ones[one];
            } else if(one) {
                words += ones[one];
            } else if(ten) {
                words += tens[ten];
            }
        }
        
        if(hundred) {
            if(words == "") {
                words += ones[hundred] + " Hundred";
            } else {
                words = ones[hundred] + " Hundred " + words;
            }
        }
        
        return words;
    }
public:
    string numberToWords(int num) {
        string ans = "";
        
        if(num == 0) {
            return "Zero";
        }
        
        if(num%1000) {
            ans += toWords(num%1000);
        }
        num /= 1000;
        
        if(num%1000) {
            if(ans == "") {
                ans += toWords(num%1000)+" Thousand";
            } else {
                ans = toWords(num%1000)+" Thousand "+ans;
            }
        }
        num /= 1000;
        
        if(num%1000) {
            if(ans == "") {
                ans = toWords(num%1000)+" Million";
            } else {
                ans = toWords(num%1000)+" Million "+ans;
            }
        }
        num /= 1000;
        
        if(num%1000) {
            if(ans == "") {
                ans = toWords(num%1000)+" Billion";
            } else {
                ans = toWords(num%1000)+" Billion "+ans;
            }
        }
        
        return ans;
    }
};