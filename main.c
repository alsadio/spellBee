
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 30

static char* getSortedUnique(const char*);
static bool isPanagram(const char*);
static int countWordsFormed(char** words, const char* panagram, int wordNum);
static bool canFormWord(const char*, const char*);

int main() {
    int wordNum;
    scanf("%d", &wordNum);

    char* words[wordNum];
    for (int i = 0; i < wordNum; i++) {
        words[i] = malloc(MAX_WORD_LEN);
        scanf("%s", words[i]);
    }

    for (int i = 0; i < wordNum; i++) {
        char* sortedUnique = getSortedUnique(words[i]);
        if (isPanagram(sortedUnique)) {
            printf("%s : ", words[i]);
            for (int j = 0; j < 7; j++) {
                printf("%c ", sortedUnique[j]);
            }
            printf("; %d\n", countWordsFormed(words, sortedUnique, wordNum));
        }
        free(sortedUnique);
    }

    // Free memory
    for (int i = 0; i < wordNum; i++) {
        free(words[i]);
    }

    return 0;
}

static char* getSortedUnique(const char* word) {
    char temp[MAX_WORD_LEN] = {0};
    int idx = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (!strchr(temp, word[i])) {
            temp[idx++] = word[i];
        }
    }
    int n = strlen(temp);
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (temp[j] > temp[j+1]) {
                char swap = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = swap;
            }
        }
    }
    return strdup(temp);
}

static bool isPanagram(const char* word) {
    return strlen(word) == 7;
}

static int countWordsFormed(char** wordList, const char* panagram, int wordNum) {
    int count = 0;
    for (int i = 0; i < wordNum; i++) {
        if (canFormWord(panagram, wordList[i])) {
            count++;
        }
    }
    return count;
}

static bool canFormWord(const char* panagram, const char* word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!strchr(panagram, word[i])) {
            return false;
        }
    }
    return true;
}