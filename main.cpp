// here will use the code already implemented in the Assignment1-FailureFunction
// Which can be found at https://github.com/The-G-Man-Half-Life/Assignment1-FailureFunction/blob/main/main.cpp

#include "main.h"

int main()
{
    std::string text = "abababaab";
    std::string word = "ababaa";

    if (KMP(text, word)) std::cout << "FOUND\n";
    else std::cout << "NOT FOUND\n";
}

bool KMP(const std::string& text, const std::string& word)
{
	// we define the failure sopts values, so that we can just find (or not) the word faster
	std::vector<int> failure = findFailureSpotsKMP(word);

	// We keep a counter for where we are currently in the word, in other words, "we have currently matched s characters of the word".
	int s = 0;

    // we start looping thought the entire text, looking for the word
	for (int i = 1; i < text.size(); i++)
	{
        // when we find a match but the next character fails, we go to the back index marked as "the next possible match".
		while (s > 0 && text.at(i) != word.at(s)) s = failure.at(s);

        // each time we find a match for the target word, we increase the counter by 1
		if (text.at(i) == word.at(s)) s++;

        // when we finally find the entire word (meaning the counter is the same size as the word) we return we DID found the word
		if (s == word.size()) return true;
	}
    // if we finish looping through the text, and did not reach a complemte tach for the word, it means we DID NOT found it and we return it.
	return false;
}


// Same implementation just shortened and withou comments bc that's not the main point here.
std::vector<int> findFailureSpotsKMP(const std::string& input)
{
    int n = input.size();
    std::vector<int> failurePlaces(n, 0);
    
    int len = 0;

    for (int i = 1; i < n; i++) {
        if (input[i] == input[len]) {
            len++;
            failurePlaces[i] = len;
        } 
        else {
            if (len != 0) len = failurePlaces[len - 1]; 
            else failurePlaces[i] = 0;
        }
    }
    return failurePlaces;
}