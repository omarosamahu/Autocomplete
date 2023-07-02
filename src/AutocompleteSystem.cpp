#include <AutocompleteSystem.h>

AutocompleteSystem::AutocompleteSystem() {}

AutocompleteSystem::AutocompleteSystem(const std::vector<std::string> &sentences,
                                       const std::vector<int> &times)
    : m_sentences(sentences), m_times(times),search_index{0} {
    for(size_t i = 0;i<m_sentences.size();++i){
        hashmap[m_sentences[i]] = {m_times[i],i};
    }
}

std::vector<std::string> AutocompleteSystem::input(char c) {
    itration_count++;
    if(c == '#'){
        return {};
    }
    word += c;

    for(size_t i=0;i<m_sentences.size();++i){
        if(m_sentences[i][search_index] == c){
            auto itr = std::find(_sentence.begin(),_sentence.end(),std::make_pair(m_sentences[i],m_times[i]));
            if(itr != _sentence.end()){
                continue;
            }
            _sentence.emplace_back(std::make_pair(m_sentences[i],m_times[i]));
            if(i > 0 && _sentence[i].second == _sentence[i-1].second && (search_index+1) <= _sentence[i].first.length()
                    && (search_index+1) <= _sentence[i-1].first.length()){
                if(_sentence[i].first[(search_index)] < _sentence[i-1].first[(search_index)]
                        ){
                    std::swap(_sentence[i],_sentence[i-1]);
                }
                if(_sentence[i].first[(search_index)] == _sentence[i-1].first[(search_index)] && _sentence[i].first[(search_index+1)] < _sentence[i-1].first[(search_index+1)]){
                    std::swap(_sentence[i],_sentence[i-1]);
                }
            }
        }
        else{
              update(word);
        }
    }
    if(!_sentence.empty()){
        for(size_t i =0;i<_sentence.size();++i){
            if(_sentence[i].first.find(word) == std::string::npos){
                _sentence.erase(_sentence.begin() + i);
                --i;
            }
        }
    }
//    for(size_t i=0;i<m_sentences.size();++i){
//        if(word == m_sentences[i]){
//           update(word);
//        }
//    }

    search_index++;
    if(_sentence.size() == 1 && itration_count == m_sentences.size()){
        return {_sentence[0].first,_sentence[1].first,_sentence[2].first};
    }
    if(_sentence.size() == 2){
        return {_sentence[0].first,_sentence[1].first};
    }
    if(_sentence.empty()){
        update(word);
        return {};
    }

    return {_sentence[0].first,_sentence[1].first,_sentence[2].first};
}

void AutocompleteSystem::update(const std::string &word) {
 // Update the sentences vector with number of search times and sort
    if(hashmap.find(word) != hashmap.end()){
        auto index = hashmap[word].second;
        ++m_times[index];
        while(m_times[index] > m_times[index-1] && index > 0){
               std::swap(m_times[index],m_times[index-1]);
               std::swap(m_sentences[index],m_sentences[index-1]);
        }
    }
    else{
        m_sentences.push_back(word);
        ++hashmap[word].first;
        m_times.push_back(hashmap[word].first);
    }
//    qDebug() << "Sentence Vector: ";
//    for(const auto& sentence : m_sentences){
//        qDebug() << QString::fromStdString(sentence);
//    }
//    qDebug() << "Sentence Vector: " << m_times;
}
