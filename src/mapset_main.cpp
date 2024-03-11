#include <algorithm>
#include <fstream>
#include <iterator>
#include <ranges>

#include "map_array.hpp"
#include "set_list.hpp"

using namespace std;

string to_lowercase(const string& str) {
    auto lower_view = views::transform(str, ::tolower);
    return {lower_view.begin(), lower_view.end()};
}

SetList<string> load_stopwords(istream& stopwords) {
    return SetList<string>{ranges::istream_view<string>(stopwords)
                            | views::transform(to_lowercase)};
}
int main() {
    ifstream stopwords_file{"stopwords.txt"};
    ifstream document{"sample_doc.txt"};
    ofstream output{"frequency.txt"};

    auto stopwords = load_stopwords(stopwords_file);
}