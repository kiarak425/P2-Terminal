#include "utility.h"

std::vector<char *> castArgs(const std::vector<std::string> &cmd)
{
    //Used a format from the lecture slides
    std::vector<char*> char_vector;
    for (const std::string value : cmd) {
        char_vector.push_back(const_cast<char*>(value.c_str()));
    }
    char_vector.push_back(nullptr); // null-terminate
    return char_vector;
}

std::vector<std::string> cmd2vec(const std::string &command, char delimiter)
{
    std::vector<std::string> string_vector;
    std::string temp;
    for (const char& value : command) {
        if(value == delimiter){
            string_vector.push_back(temp);
            temp = "";
        }
        else{
        temp = temp + value;
        }
    }
    string_vector.push_back(temp); 
    return string_vector;
}
