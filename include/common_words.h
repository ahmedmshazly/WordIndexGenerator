/*
* common_words.h
*
* Header for common English words to be ignored in the indexing process.
* These are words that usually don't add much value to text analysis due
* to their frequency and lack of specificity.
*/

#ifndef _COMMON_WORDS_H_
#define _COMMON_WORDS_H_
#include <stddef.h>

// Array of common words
const char *common_words[] = {"a", "about", "after", "all", "also", "an",
 "and", "any", "are", "as", "at", "back", "be", "because", "but", "by",
 "can", "come", "could", "day", "do", "even", "first", "for", "from", "get",
 "give", "go", "good", "have", "he", "he", "her", "him", "his", "how", "i",
 "if", "in", "into", "is", "it", "its", "it's", "just", "know", "like",
 "look", "make", "me", "most", "my", "new", "no", "not", "now", "of", "on",
 "one", "only", "or", "other", "our", "out", "over", "people", "say", "see",
 "she", "so", "some", "take", "than", "that", "the", "their", "them", "then",
 "there", "these", "they", "think", "this", "time", "to", "two", "up", "us",
 "use", "want", "way", "we", "well", "we'll", "what", "when", "which", "who",
 "will", "with", "work", "would", "year", "you", "your", NULL};

//static const int common_words_count = 95; // Count of words in the array

#endif
