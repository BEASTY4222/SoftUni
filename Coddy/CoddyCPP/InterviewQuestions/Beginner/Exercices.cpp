#include <string>
#include <stack>

namespace exercices{
    class BeginnerExercices{
        public:
        class ReversingThings{
            public:
            static std::string reverseString(std::string s) {
                std::string reversed = "";

                for(int i = s.length()-1;i >= 0;i--){
                    reversed.push_back(s[i]);
                }

                return reversed;    
            }
        };

        class CountingThings{
            public:
            static int countVowels(std::string s){
                unsigned int count = 0;
                std::string vowels = "aeiou";

                for(int i = 0; i < s.length();i++)
                    for(int j = 0; j < vowels.length();j++)
                        if(std::tolower(s[i]) == vowels[j]) count++;
                    
                return count;
            }
        };

        
        
    };
}