#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

// my BRUTEFORCE solution
vector<string> topKFrequent(vector<string>& words, int k) {
  unordered_map<string, int> words_count;
  for(const auto& word : words) {
    ++words_count[word];
  }

  map<int, set<string>> freq_to_words;
  for(const auto& [word , counter] : words_count) {
    freq_to_words[counter].insert(word);
  }

  vector<string> result;
  for(auto it = freq_to_words.rbegin(); it != freq_to_words.rend(); ++it) {
    if(result.size() >= k) {
      break;
    }

    copy(it->second.begin(), it->second.end(), back_inserter(result));
  }

  return vector(make_move_iterator(result.begin()), make_move_iterator(result.begin() + k));
}


// another solution from leetcode
vector<string> topKFrequent2(vector<string>& words, int k) {
  unordered_map<string, int> count;
  for (const auto& word : words) {
    count[word]++;
  }

  vector<pair<int, string>> freqList;
  for (const auto& entry : count) {
    freqList.push_back({entry.second, entry.first});
  }

  sort(freqList.begin(), freqList.end(), [](const auto& a, const auto& b) {
    return a.first == b.first ? a.second < b.second : a.first > b.first;
  });

  vector<string> result;
  for (int i = 0; i < k; i++) {
    result.push_back(freqList[i].second);
  }

  return result;
}

int main() {
  vector<string> words{"i","love","leetcode","i","love","coding"};
  int k = 2;
  
  vector<string> words2{"the","day","is","sunny","the","the","the","sunny","is","is"};
  int k2 = 4;
  
  cout << "top k frequent words: ";
  for(const auto& str : topKFrequent(words2, k2)) {
    cout << str << ", ";
  }
  cout << endl;

  return 0;
}
