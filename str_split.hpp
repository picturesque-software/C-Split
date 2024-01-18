#ifndef __STR_SPLIT__
#define __STR_SPLIT__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, const char delim) {
    std::vector<std::string> ans;
    std::istringstream iss(s);
    std::string token;
    while (std::getline(iss, token, delim)) {
        ans.push_back(token);
    }
    return ans;
}

std::vector<std::string> split(const std::string &s, 
                               const std::string &delim) {
    std::vector<std::string> ans;
	int begin = 0, end = std::string::npos;
	do {
		end = s.find(delim, begin);
		if (end == std::string::npos) {
			ans.push_back(s.substr(begin));
		} else {
			ans.push_back(s.substr(begin, end - begin));
			begin = end + delim.length();
		}
	} while (end != std::string::npos);
	return ans;
}

std::vector<std::string> split2(const std::string &s, 
                                const std::string &delim) {
    std::vector<std::string> ans;
	int begin = 0;
	while (begin < s.length()) {
		int end = s.find(delim, begin);
		if (end == std::string::npos) {
			ans.push_back(s.substr(begin));
			break;
		} else {
			if (begin == end) {
				begin = end + 1;
			} else {
				ans.push_back(s.substr(begin, end - begin));
				begin = end + delim.length();
			}
		}
	}
	return ans;
}

#endif // __STR_SPLIT__
