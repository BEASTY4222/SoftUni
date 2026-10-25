#include <string>
#include <stack>
#include <cmath>
#include <vector>

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
        
            static int findMax(std::vector<int> nums) {
                int max = nums[0];
                for(int i = 0;i < nums.size();i++)
                    if(nums[i] > max) max = nums[i];

                return max;
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

            static bool isPrime(int n) {
                if(n <= 1) return false;
                if(n % 2 == 0) return true;
                // terrible wrong works only on very small prime numbers numbers above 150-ish would fail
                for(int i{3};i < 13;i++)
                    if(n % i == 0 && i != n) return false;
                
                // correct way
                // since d divides n, so does n / d both cannot be larger than √n
                for (long long d = 3; d * d <= n; d += 2) 
                    if (n % d == 0) 
                        return false;
                    
                return true;
            }
        };

        class DynamicProgramming{
            public:
            static int fib(int n){
                if (n < 2) return n;

                unsigned int a = 0;
                unsigned int b = 1;
                unsigned int c = 0;

                while(n > 1){
                    
                    c = a + b;
                    a = b;
                    b = c;
                    n--;
                }

                return c;
            }
        };
        
    };
}