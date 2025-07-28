#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // queue deceleartion
          queue<pair<string,int>>q;
          // push the beginning word and step
          q.push({beginWord,1});
          // push list elemnt to unordered set for 
          unordered_set<string>st(wordList.begin(),wordList.end());

          while(!q.empty()){
            // store the queue string word
            string word=q.front().first;
            // store the steps 
            int steps=q.front().second;
            // if we reach the last word by any chance
            // pop the element
            q.pop();
            if(word==endWord) return steps;

            for(int i=0;i<word.size();i++){
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,steps+1});

                    }
                }
                   word[i]=orignal;

            }
          }
          return 0;
   
   
    }    
};




int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Shortest transformation sequence length: " << result << endl;

    return 0;
}
