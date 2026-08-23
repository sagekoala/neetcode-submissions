class Solution {
public:

    string encode(vector<string>& strs) {
        std::string encodedStr;
        for (std::string str : strs) {
            std::string len = std::to_string(str.size());
            encodedStr += (len + "#" + str);
        }
        std::cout << encodedStr << std::endl;
        return encodedStr;
    }

    vector<string> decode(string s) {
        int i = 0;
        std::vector<string> result;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            std::string tmp;
            for (int k = j + 1; k < j + len + 1; k++) tmp += s[k];
            result.push_back(tmp);
            i = j + 1 + len;
        }
        return result;
    }
};
