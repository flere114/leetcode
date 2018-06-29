class Solution {
private:
    void maskEmail(string &s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        size_t posAt = s.find('@');
        string preAt = s.substr(0, posAt);
        string postAt = s.substr(posAt);
        
        s = string("") + preAt.front() + "*****" + preAt.back() + postAt;
    }
    void maskPhone(string &s) {
        vector <char> digit;
        
        for (const auto &ch : s) {
            if (ch >='0' && ch <='9') {
                digit.push_back(ch);
            }
        }
        
        s = "***-***-";
        for (int i = digit.size()-4; i < digit.size(); ++i) {
            s += digit[i];
        }
        
        int country_code_size = digit.size() - 10;
        
        if (country_code_size > 0) {
            string country_code = "+";
            for (int i = 0; i < country_code_size; ++i) {
                country_code += "*";
            }
            country_code += "-";
            s = country_code + s;
        }
    }
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            maskEmail(s);
        } else {
            maskPhone(s);
        }
        
        return s;
    }
};
