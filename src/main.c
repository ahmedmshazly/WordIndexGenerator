/*
* Project Title: Word Index Generator
 * Description: This program reads text from stdin, parses it to find unique words, and indexes them by
 *              frequency and line number. It's particularly useful in text analysis tools and educational
 *              software for tracking word usage.
 * Author: AHMED MOHAMED (amohame2)
 * Date Created: September 19, 2024,
 * Last Modified: September 21, 2024,
 *
 * Notes:
 * - This is case-sensitive; it treats 'Word' and 'word' differently. Make sure your input is consistent.
 * - Adjustments may be needed for non-English text input.
 */


#include "../test/common_words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for storing words, counts, line nums
typedef struct {
    char word[21];  // Space for null-terminator
    int count;
    int lines[20];  // Store up to 20 line nums
} WordIndex;

#define MAX_WORDS 1200
WordIndex wordIndex[MAX_WORDS];
int wordCount = 0;

// static const int common_words_count = 95;
// Func declarations
void parseInput();
int isCommonWord(const char* word);
void addWordToIndex(const char* word, int line);
void sortIndex();
void printIndex();

/**
 * Validates character eligibility in a word.
 * Checks if a character is alphabetic, a hyphen, or an apostrophe.
 *
 * @param c Char to check.
 * @return true if it's a valid character for words, false otherwise.
 */
// Check if char is valid in a word
int isValidChar(char c) {
    return isalpha(c) || c == '\'' || c == '-';
}

/**
 * Processes stdin line by line to extract and index words.
 * Each line is checked for words, which are indexed if they're not common words.
 *
 * @note Uses fgets to read lines; make sure input does not exceed buffer size.
 */
// Read and process input
void parseInput() {
    char line[255]; // Holds input line
    int line_number = 1;

    // Read till EOF
    while (fgets(line, sizeof(line), stdin)) {
        int start = 0, end = 0;

        // Find words in line
        while (line[end] != '\0') {
            if (isValidChar(line[end])) {
                start = end;
                // Find end of word
                while (isValidChar(line[end]) && line[end] != '\0') end++;
                // Copy word to temp buffer
                char word[21];
                strncpy(word, line + start, end - start);
                word[end - start] = '\0'; // Null-term

                // Lowercase for case insensitivity
                for (int i = 0; word[i]; i++) {
                    word[i] = tolower(word[i]);
                }

                // Add word if not common
                if (!isCommonWord(word)) {
                    addWordToIndex(word, line_number);
                }
            } else {
                end++; // Skip invalid chars
            }
        }
        line_number++; // Next line
    }
}

/**
 * Determines if a word is a commonly used word.
 * Common words are skipped in the indexing to focus on relevant vocabulary.
 *
 * @param word Word to check.
 * @return true if the word is common, false otherwise.
 */
// Check if word is common
int isCommonWord(const char* word) {
    for (int i = 0; common_words[i] != NULL; i++) {
        if (strcmp(word, common_words[i]) == 0) {
            // printf("Common word found: %s\n", word); // Debugging
            return 1;  // True: It is a common word
        }
    }
    return 0;  // False: It is not a common word
}


/**
 * Adds a new word or updates an existing word's data in the index.
 * Stores words with their occurrence lines up to a specified limit.
 *
 * @param word Word to add or update in the index.
 * @param line Line number where the word was found.
 */
// Add word to index
void addWordToIndex(const char* word, int line) {
    // Check if word is already indexed
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordIndex[i].word, word) == 0) {
            // Add line num if not maxed
            if (wordIndex[i].count < 20) {
                wordIndex[i].lines[wordIndex[i].count] = line;
                wordIndex[i].count++;
            }
            return;
        }
    }

    // Add new word to index
    if (wordCount < MAX_WORDS) {
        strcpy(wordIndex[wordCount].word, word);
        wordIndex[wordCount].lines[0] = line;
        wordIndex[wordCount].count = 1;
        wordCount++;
    }
}

/**
 * Compares two WordIndex structs for sorting.
 * Used by qsort to order words by frequency and alphabetically.
 *
 * @param a First word index to compare.
 * @param b Second word index to compare.
 * @return int Difference for sorting.
 */
// Compare for qsort
int compareWords(const void *a, const void *b) {
    const WordIndex *wordA = (const WordIndex *)a;
    const WordIndex *wordB = (const WordIndex *)b;

    // Sort by count desc, then word asc
    if (wordA->count != wordB->count) {
        return wordB->count - wordA->count;
    }

    return strcmp(wordA->word, wordB->word);
}

/**
 * Sorts the indexed words by frequency and alphabetically.
 * Utilizes the standard qsort function with a custom comparator.
 */
// Sort words in index
void sortIndex() {
    qsort(wordIndex, wordCount, sizeof(WordIndex), compareWords);
}

/**
 * Outputs the indexed words with their frequencies and line numbers.
 * Formats the output in a readable manner, showing the count and line positions.
 */
// Print the sorted index
void printIndex() {
    for (int i = 0; i < wordCount; i++) {
        printf("%s           [%d]:", wordIndex[i].word, wordIndex[i].count);
        for (int j = 0; j < wordIndex[i].count; j++) {
            printf(" %d", wordIndex[i].lines[j]);
            if (j < wordIndex[i].count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

/**
 * Main execution point of the program.
 * Initiates the parsing, sorting, and printing of the indexed words.
 * Returns the status code based on the execution success.
 *
 * @return int Program exit status.
 */
int main() {
    // if (isCommonWord("you")) {
    //     printf("The word 'you' is correctly identified as common.\n");
    // } else {
    //     printf("Error: 'you' is not identified as common.\n");
    // }

    parseInput();
    sortIndex();
    printIndex();
    return 0;
}

