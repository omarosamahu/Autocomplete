#include <AutocompleteSystem.h>


int main(int argc, char *argv[])
{
    std::vector<std::pair<std::string,int>> data = {{"i love you",5},{"island",3},{"island",2},{"i love leetcode",2}};

    std::vector<std::string> sentences = {"irland","i love you","island","ironman","i love leetcode"};
    std::vector<int> times = {6, 5, 2, 2, 2};

    AutocompleteSystem sys(sentences,times);
    auto output1 = sys.input('i');
    auto output2 = sys.input('r');
    auto output3 = sys.input('o');
//    auto output4 = sys.input('n');
//    auto output5 = sys.input('m');
//    auto output6 = sys.input('a');
//    auto output7 = sys.input('n');
//    auto output8 = sys.input('#');
//    auto output5 = sys.input('i');
//    auto output6 = sys.input(' ');
//    auto output7 = sys.input('x');

    // qDebug() << "First Time";
    // for(const auto& sentence : output1){
    //     qDebug() << QString::fromStdString(sentence);
    // }
    // qDebug() << "Second Time";
    // for(const auto& sentence : output2){
    //     qDebug() << QString::fromStdString(sentence);
    // }
    // qDebug() << "Third Time";
    // for(const auto& sentence : output3){
    //     qDebug() << QString::fromStdString(sentence);
    // }
    return 0;
}
