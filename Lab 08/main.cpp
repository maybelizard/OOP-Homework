#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

ifstream fin("data.txt");

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	string s;
	getline(fin, s);

	int word_pos = -1;
	map<string, int> words;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == ',' || s[i] == '?' || s[i] == '!' || s[i] == '.') {
			if (word_pos < i - 1) {
				string word = s.substr(word_pos + 1, i - word_pos - 1);
				for (int j = 0; j < word.length(); j++)
					if (word[j] >= 'A' && word[j] <= 'Z')
						word[j] -= 'A' - 'a';
				auto it = words.find(word);
				if (it != words.end()) 
					it->second++;
				else
					words[word] = 1;
			}
			word_pos = i;
		}
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(&comp)> words_pq(&comp);

	for (const auto& pair : words)
		words_pq.push(pair);

	while (!words_pq.empty()) {
		cout << words_pq.top().first << " => " << words_pq.top().second << endl;
		words_pq.pop();
	}
}