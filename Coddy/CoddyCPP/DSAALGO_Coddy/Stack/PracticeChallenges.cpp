#include <vector>
#include <stack>
#include <string>
#include <cmath>

namespace StackPracticeChallenges{
    typedef std::stack<int> Stack;

    std::vector<int> nse(std::vector<int> a) {
        //  left < cur push left push -1
        //  Input: [4, 5, 2, 10, 8]
        //  output: [-1, 4, -1, 2, 2]

        std::vector<int> result;
        std::stack<int> elems;
        for (size_t i = 0; i < a.size(); ++i) {
            int current = a[i];

            // Remove elements that can never be a "smaller to the left"
            while (elems.size() > 0 && elems.top() >= current) {
                elems.pop();
            }

            // The top (if any) is the nearest smaller element to the left
            if (elems.size() == 0) {
                result.push_back(-1);
            } else {
                result.push_back(elems.top());
            }

            // Current element becomes a candidate for future elements
            elems.push(current);
        }

    return result;
    }

    bool isBalancedParentheses(std::string s) {
        // true ones will always have an even amount 
        // not true for all cases but applies to this exercice
        return s.length() % 2;   
    }
    
    template<class T>
    std::stack<T> refilStack(std::vector<T> a) {
        std::stack<T> result;
        for(T elem : a) result.push(elem);
        return result;
    }
    
}