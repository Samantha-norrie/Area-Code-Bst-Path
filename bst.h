#ifndef _BST_H_
#define _BST_H_


#define MAXLEN_NAME 50
typedef struct bst_node{
    char area_code[3];
    char p_or_t[MAXLEN_NAME];
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

bst_node* new_bst_node(char *);
void print_bst_node(bst_node *to_print);
bst_node* add_in(bst_node *root, bst_node *to_add);
void search_for(bst_node* root, int area_code);
int compare(int num_current, int num_looking);
void free_bst(bst_node *current_node);
void print_spaces(int amount);
void print_bst_node(bst_node *to_print);

#endif
