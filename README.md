# spellBee
This C program processes a list of words, checking whether each word can form a "pangram" by determining if it contains exactly 7 unique letters. Here's an overview of its functionality:

Input Handling: The program reads the number of words and the words themselves as input.

Unique Character Sorting: For each word, it extracts and sorts the unique characters, storing them in a new string.

Pangram Check: It checks if the sorted unique character string contains exactly 7 letters, qualifying it as a pangram.

Word Formation: For pangrams, it counts how many words from the input list can be formed using only the letters of the pangram.

Memory Management: Dynamic memory allocation is used for storing words, which is freed at the end.

The program outputs the original word, the sorted unique characters that make up the pangram, and the number of words that can be formed from those characters.
