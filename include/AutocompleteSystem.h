#ifndef AUTOCOMPLETESYSTEM_H
#define AUTOCOMPLETESYSTEM_H

#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

class AutocompleteSystem
{
public:
    AutocompleteSystem();
    AutocompleteSystem(const std::vector<std::string>& sentences,const std::vector<int>& times);
    std::vector<std::string> input(char c);
private:
    std::string search(std::vector<std::string>& sentences);
    void update(const std::string& sentence);

private:
    std::vector<std::string> m_sentences;
    std::vector<int> m_times;
    size_t search_index;
    std::string word;
    size_t word_count = 0;
    std::unordered_map<std::string,std::pair<int,int>> hashmap;
    size_t itration_count = 0;
    std::vector<std::pair<std::string,int>> _sentence;
};

#endif // AUTOCOMPLETESYSTEM_H
