#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> split(string splitString){
    istringstream iss(splitString);
    string tokens;
    vector<int> result;
    while(getline(iss, tokens, ':')){
        if(!tokens.empty()) result.push_back(std::stoi(tokens));
    }
    return result;
}

int toSeconds(const vector<int>& t) {
    return t[0] * 60 + t[1];
}

vector<int> fromSeconds(int s) {
    return {s / 60, s % 60};
}

int skipOpening(int& pos_i, int& op_start_i, int& op_end_i){
    if (pos_i >= op_start_i && pos_i <= op_end_i) pos_i = op_end_i;
    return pos_i;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_i = toSeconds(split(video_len));
    int pos_i = toSeconds(split(pos));
    int op_start_i = toSeconds(split(op_start));
    int op_end_i = toSeconds(split(op_end));
    
    skipOpening(pos_i, op_start_i, op_end_i);
    
    for (auto& command : commands) {
        if (command == "next") {
            pos_i = min(pos_i + 10, video_i);
        } else if (command == "prev") {
            pos_i = max(pos_i - 10, 0);
        }
        skipOpening(pos_i, op_start_i, op_end_i);
    }
    
    vector<int> result = fromSeconds(pos_i);
    
    ostringstream oss;
    oss << (result[0] < 10 ? "0" : "") << result[0] << ":" 
        << (result[1] < 10 ? "0" : "") << result[1]; 
    return oss.str();
}