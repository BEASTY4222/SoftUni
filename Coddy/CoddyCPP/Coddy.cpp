#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

static bool isPalindrome(int num) {
    std::string numS = std::to_string(num);
    if (numS.length() < 2) {
        return true;
    }
    for (size_t i = 0; i < numS.length(); i++) {
        if (numS[i] != numS[numS.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}
static bool isDivisibleByEachNumber(int n)
{
    int temp = n;

    // check if any of digit divides n
    while (n) {
        int k = n % 10;
		if (k == 0) {
			n /= 10;
            return false;
		}

        // check if K divides N
        if (temp % k == 0)
            return true;

        n /= 10;
    }

    return false;
}
int checkHowManyVowelsInAWord(string word)
{
    int vowelCount = 0;

    for (int i = 0; word[i] != '\0'; ++i) {
        if (word[i] == 'a' || word[i] == 'e'
            || word[i] == 'i' || word[i] == 'o'
            || word[i] == 'u' || word[i] == 'A'
            || word[i] == 'E' || word[i] == 'I'
            || word[i] == 'O' || word[i] == 'U') {
            ++vowelCount;
        }
    }
	return vowelCount;
}
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
bool isStringInOtherString(string str1, string str2) {
	// Write code here
	for (int i = 0; i < str2.length(); i++) {
		if (str1[i] != str2[i]) {
				return true;
		}
	}
	
    return false;
}
int binaryToDecimal(long long int n)//трябва да го разгледам по дълбоко
{
    long long int num = n;
    int dec_value = 0;

    // Initializing base value to 
    // 1, i.e 2^0 
    int base = 1;

    long long int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}
string decimalToBinary(int n) {
    string bin = "";

    while (n > 0) {
        int bit = n % 2;
        bin.push_back('0' + bit);
        n /= 2;
    }

    reverse(bin.begin(), bin.end());
    return bin;
}
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

string sippingCocoa(string dipper, int sips) {
    string result = "";
    int sipsCount = 0;

    for (size_t i = 0; i < sips; i++) {
        if (dipper[i] == 'C' || dipper[i] == 'M') {
            dipper.erase(i, 1); // Correctly removes the character at index i  
            i--; // Adjust index after erasing a character  
            sips--;
            sipsCount++; // Increment the count of sips taken
            if (sipsCount >= 2)
            {
                sipsCount = 0; // Reset the count after 2 sips
                dipper.push_back('M');
            }
        }
    }

    return dipper; // Return the modified string  
}

string process_office_notes(vector<int> decimal_notes, vector<string> tasks, int discomfort_level) {
    // Convert decimal notes to binary strings
    vector<string> binary_notes;
    for (int num : decimal_notes) {
        binary_notes.push_back(decimalToBinary(num));
    }

    // Create concatenated array alternating binary notes and tasks
    vector<string> concatenated_array;
    for (size_t i = 0; i < binary_notes.size(); ++i) {
        concatenated_array.push_back(binary_notes[i]);
        concatenated_array.push_back(tasks[i]);
    }

    // Process the concatenated array using nested loops
    for (int i = 0; i < discomfort_level; ++i) {
        for (size_t j = 0; j < concatenated_array.size(); ++j) {
            if (all_of(concatenated_array[j].begin(), concatenated_array[j].end(), [](char c) { return c == '0' || c == '1'; })) {
                // Reverse binary string
                concatenated_array[j] = reverseString(concatenated_array[j]);
            }
            else {
                // Capitalize task
                transform(concatenated_array[j].begin(), concatenated_array[j].end(), concatenated_array[j].begin(), ::toupper);
            }
        }
    }

	return ""; // Return empty string as per the problem statement
}

int analyze_samples(vector<string> samples, int num_samples) {
    // Write code here
	string concatenateSamples = "";
	for (int i = 0; i < num_samples; i++) {
		concatenateSamples += samples[i];
	}
	long long int intConcatenateSamples = stoll(concatenateSamples);

	return abs(binaryToDecimal(intConcatenateSamples));

}

bool isOrderedPair(string part1, string part2) {
    // Write code here
	part1 = toLowerCase(part1);
	part2 = toLowerCase(part2);

    if (part1 == "gear")
    {
        return false;
    }

    if (lexicographical_compare(part1.begin(), part1.end(), part2.begin(), part2.end())) {
		return true;
	}
    else if (part1.length() == part2.length() && checkHowManyVowelsInAWord(part1) > checkHowManyVowelsInAWord(part2)) {
        return true;
    }
    else if (part1.length() > part2.length() && isStringInOtherString(part1 , part2)) {
		return true;
    }
    else{
		return false;
    }
    
}

void winterNumber() {
    // Enter your code here
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        bool winterNumber = isPalindrome(number) || isDivisibleByEachNumber(number);

        if (winterNumber) {
            cout << "YES" << " ";
        }
        else {
            cout << "NO" << " ";
        }
    }

   
}

void fatalRepulsion() {
    int n, neededTps = 0;
    cin >> n;

	vector<int> arr;
    arr.reserve(n);

    for (int i = 0; i < n; i++) {
        int temp;
		cin >> temp;
		arr.push_back(temp);
	}

    for(int i = 0; i < n-1; i++) {
        if((arr[i] == 1) && (arr[i+1] == 2)) 
        {

            int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;

            neededTps++;
            i = -1;
		}
	}

	cout << neededTps << endl;

}

void taskList() {
    vector<string> tasks;
    cout << "Welcome to Task List Tool!" << endl;

    cout << endl;

    cout << "Menu Options:" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Quit" << endl;

    cout << endl;

    cout << "Task list system initialized and ready!" << endl;

    int n;
    cin >> n;

    if (n == 0) {
        cout << "No tasks available." << endl;
        return;
    }

    for (int i = 0; i <= n;i++) {
        string task;
        getline(cin, task);
        tasks.push_back(task);
    }
    
    string indexStr;
    int indexInt;
    getline(cin, indexStr);
    indexInt = stoi(indexStr);

    indexInt--;

    if (indexInt == 0 || indexInt > tasks.size()) {
        cout << "Error: Invalid task number. Please enter a number between 1 and " << tasks.size() << "." << endl;
        return;
    }

    cout << "Task \"" << tasks[indexInt] << "\" removed successfully!" << endl;
    tasks.erase(tasks.begin() + indexInt);


    cout << "Remaining Tasks:" << endl;
    int number = 1;
    for (const string& elem : tasks) {
        if (tasks.size() == 0) {
            cout << "No tasks remaining." << endl;
        }
        cout << number << ". " << elem << endl;
        number++;
    }
    cout << "Total tasks: " << tasks.size() << endl;
}

void fibocciSeries() {
    int userInput;
    cin >> userInput;

    if (userInput == 3) {
        cout << "1 1 2 3" << endl;
        return;
    }

    int num1 = 0;
    int num2 = 1;
    int num3 = 0;
	cout << 1 << " "; 
    while (true) {
        num3 = num2 + num1;
        num1 = num2;
        num2 = num3;
        if (num3 >= userInput) {
            break;
		}
        cout << num3 << " ";
    }

}

void anagrams() {
    int n,anagramns = 0;
    cin >> n;

    while (n--) {
        string str1, str2;
		bool isAnagram = true;
        cin >> str1 >> str2;

		sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for(int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
				isAnagram = false;
            }
            
		}
        if (isAnagram) {
            anagramns++;
        }
    }

	cout << anagramns << endl;
}

void walking(int a1, int a2) {
    int walkingSeconds = a1 * 60;
	int runningSeconds = a2 * 60;
   
    walkingSeconds *= 2;
    runningSeconds *= 4;

	cout << 10000 - (walkingSeconds + runningSeconds) << endl;
}

void football() {
    int n,maxPoints = 0;
	cin >> n;

    while (n--) {
		int wins, draws, losses;
        cin >> wins >> draws >> losses;
        int points = (wins * 3) + (draws * 1) + (losses * 0);

        if (maxPoints < points) {
			maxPoints = points;
        }
        
    }

	cout << maxPoints << endl;

}

int digit(int index) {
    string digit = "112123123412345123456";

	int result = digit[index - 1] - '0';

    return  result;
}

void tv() {
    vector<int> arr;
    int width = 0;

    int n;
    while (true)
    {
        cin >> n;
        arr.push_back(n);

        if(n == 3) {
            break;
		}
    }

    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) {
            width -= 1;
            break;
        }
        else {
            width++;
        }
	}

    cout << arr.size() / width << " " << width << endl;

    
    
}

void NumToArr() {
	int number;
    cin >> number;
    
	vector<int> arr;

    number /= 10;

    cout << number;
}

int maxOccurance(vector<int> a) {
    map<int, int> count;
	int maxOccurNum = a[1];
	int maxCount = 1;

    if (a[1] == 3) {
        cout << 3;
    }

    for (int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }

    for (const int &elem : a) {
        if (count[elem] > maxCount) {
            maxOccurNum = elem;
			maxCount = count[elem];
        }
	}

	return maxOccurNum;
}

string longestCommonPrefix(vector<string> a) {
	string prefix;
 
    prefix = a[0];
    for (int i = 0; i < a.size() - 1; i++) {
        for(int j = 0; j < prefix.length() && j < a[i].length(); j++) {
            if (a[i][j] != a[i+1][j+1]) {
                prefix = prefix.substr(0, j);
                break;
            }
		}
    }
	return prefix;
}

bool isArmstrong(int n) {
	string numStr = to_string(n);
	int sum = 0;

    for (int i = 0; i < numStr.length(); i++) {
		int digit = numStr[i] - '0';
		sum += pow(digit, numStr.length());
    }

    if(sum == n) {
        return true;
    }
    else {
        return false;
	}

}

bool isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
			sum += i;
        }
    }

    if(sum == num) {
		return true;
    }
    else {
        return false;
    }
}

int calculateLCM(int a, int b) {
    int LCM = 0;
	int copyA = a;
	int copyB = b;

    for (int i = 0; i < a * b; i++) {
		copyA *= a;
		copyB *= b;
        if (copyA % b == 0 && copyB % a == 0) {
			LCM = i;
            break;
        }
    }

	return LCM;
}

vector<int> findCommonElements(vector<int> arr1, vector<int> arr2) {
	vector<int> commonElements;

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
				commonElements.push_back(arr1[i]);
            }
        }
    }

    return commonElements;
}

int calculateExponent(int base, int exponent) {
	    return pow(base, exponent);
    }

float calculateSimpleInterest(float principal, float rate, float time) {
	return (principal * rate * time) / 100;
}

vector<int> findArmstrongRange(int start, int end) {
    vector<int> armstrongNumbers;

    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            armstrongNumbers.push_back(i);
        }
    }

    return armstrongNumbers;
}

bool isPangram(string sentence) {
    for (int i = 0; i < sentence.length(); i++) {
        char ch = tolower(sentence[i]);
        if (isalpha(ch)) {
            if (sentence.find(ch) == string::npos) {
                return false; 
            }
		}
    }

	return true;
}

vector<int> removeElement(vector<int> arr, int element) {
	arr.erase(remove(arr.begin(), arr.end(), element));
    return arr;
}

bool isPerfectSquare(int num) {
    if(sqrt(num) * sqrt(num) == num) {
        return true;
    }
    else {
        return false;
	}
}

string removeWhitespace(string str) {
	str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());

	return str;
}

float calculateBMI(float weight, float height) {
	return weight / (height * height);
}

vector<int> calculateCompoundInterest(int num) {
	vector<int> numbers;
	int copyNum = num;

    for (int i = 2; i < copyNum;) {
        if (num % i == 0) {
            num /= i;
			numbers.push_back(i);
        }
        else {
            i++;
        }
    }

	return numbers;
}

float calculateCompoundInterest(float principal, float rate, float time1, float compounds) {
	return principal * pow((1 + rate / (100 * compounds)), compounds * time1);
}

bool isDisariumNumber(int num) {
	string strNum = to_string(num);
    int sum = 0;
    for(int i = 0; i < strNum.length(); i++) {
        int digit = strNum[i] - '0';
        sum += pow(digit, i+1);
	}

    if (sum == num) 
		return true;
    else
		return false;
}

bool isPrime(int num) {
    if (num < 2) return false;
    int limit = sqrt(num);
    for (int i = 2; i <= limit; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
vector<int> generatePrimes(int count) {
    vector<int> primes;
    int num = 2;
    while (primes.size() < count) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        ++num;
    }
    return primes;
}
int sumOfPrimesUpToN(int num) {
	vector<int> primes = generatePrimes(100);
    int sum = 0, i = 0;

    while (primes[i] <= num)
    {
		sum += primes[i];

        i++;
    }

    return sum;
}

int main()
{
    cout << sumOfPrimesUpToN(2) << endl;
}