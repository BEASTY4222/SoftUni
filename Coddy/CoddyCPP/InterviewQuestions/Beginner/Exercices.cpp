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
        
    };
}