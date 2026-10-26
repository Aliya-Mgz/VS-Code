#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct trie_node
{
 struct trie_node *children[ALPHABET_SIZE];
 bool is_end_of_word;
}trie_node;

trie_node *create_node() {
    trie_node *node = malloc(sizeof(trie_node));
    if (node == NULL) {
        return NULL;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trie_insert(trie_node *root, const char *word) {
    trie_node *current = root;

for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_node();
        }
        current = current->children[index];
    }
    current->is_end_of_word = true;
}

bool trie_search(trie_node *root, const char *word) {
    trie_node *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->is_end_of_word;
}

int main(void) {
    trie_node *root = create_node();

    trie_insert(root, "cat");
    trie_insert(root, "can");

    printf("%d\n", trie_search(root, "cat"));
    printf("%d\n", trie_search(root, "car")); 
}
