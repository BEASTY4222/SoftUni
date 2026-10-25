#include <string>
#include <stack>
#include <cmath>

namespace exercices{
    class BeginnerExercices{
        public:
        class ArraysAndStrings{
            public:
            static std::string reverseString(std::string s) {
                std::string reversed = "";

                for(int i = s.length()-1;i >= 0;i--){
                    reversed.push_back(s[i]);
                }

                return reversed;    
            }

            static int countVowels(std::string s){
                unsigned int count = 0;
                std::string vowels = "aeiou";

                for(int i = 0; i < s.length();i++)
                    for(int j = 0; j < vowels.length();j++)
                        if(std::tolower(s[i]) == vowels[j]) count++;
                    
                return count;
            }
        };

        class Math{
            public:
            static bool isArmstrong(int n){
                unsigned int sum = 0;
                
                std::string stringN = std::to_string(n);
                unsigned int stringNLenght = stringN.length(); 
                for(int i = 0;i < stringNLenght;i++){
                    sum += std::pow(stringN[i] - '0', stringNLenght);
                }

                return n == sum;
            }

            static int sumOfDigits(int n){
                std::string stringN = std::to_string(n);
                unsigned int sum = 0;

                for(int i = 0;i < stringN.length();i++){
                    sum += stringN[i] - '0';
                }

                return sum;
            }

            static int factorial(int n) {
                if(n == 0) return 1;
                unsigned int factorial = 1;

                while(n > 0){
                    factorial *= n;
                    n--;
                }

                return factorial;
            }
        };
        
    };
}