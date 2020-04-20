#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

#define ROOT_PLACE_PICTURE_START 20

/*Function to make new BST node*/
bst_node* new_bst_node(char *info) {
    assert(info != NULL);
    bst_node* new = (bst_node*)malloc(sizeof(bst_node));
    assert(new != NULL);

    char* section_of_info;
    section_of_info = strtok(info, ": ");
    int info_section_at = 0;
    while(section_of_info){
        if(info_section_at == 0){
            strncpy(new->area_code, section_of_info, (strlen(section_of_info))+1);

        }else if(info_section_at == 1){
            strncpy(new->p_or_t, section_of_info, (strlen(section_of_info))+1);

        }
        info_section_at = info_section_at + 1;
        section_of_info = strtok(NULL, "\n");
    }
    new->left = NULL;
    new->right = NULL;
    return new;
}

/*Function to add in new BST node into tree*/
bst_node* add_in(bst_node *root, bst_node *to_add){

    //If no nodes have been added, the new node becomes the root
    if(root == NULL){
        return to_add;
    }
    int num_to_add = atoi(to_add->area_code);
    bst_node *current_node = root;
    int added = 0;

    //Traverse through tree to find appropriate spot to add
    while(current_node != NULL && added != 1){
        int num_current = atoi(current_node->area_code);

        //If to_add is greater than current_node
        if(compare(num_current, num_to_add) == 1){
            bst_node *temp_copy = current_node;
            current_node = current_node ->right;
            if(current_node == NULL){
                temp_copy->right = to_add;
                added = 1;
            }
        }
        //If to_add is lesser than current_node
        else if(compare(num_current, num_to_add) == -1){
            bst_node *temp_copy = current_node;
            current_node = current_node->left;
            if(current_node == NULL){
                temp_copy->left = to_add;
                added = 1;
            }
        }
    }
    return root;
}

/*Function to search for desired area code. Info
 * will be printed as to which province/territory
 * the area code are from, or will print that the
 * area code cannot be found
 */
void search_for(bst_node* root, int num_area_code){

    char *not_found = "\nArea code not found.\n\n";

    //If invalid number given
    if(num_area_code > 999 || num_area_code < 100){
        printf("%s", not_found);
    }
    int photo_placement = ROOT_PLACE_PICTURE_START;
    print_spaces(photo_placement/2);
    printf("\nBinary Search Tree Path to Area Code:\n\n");
    if(root != NULL){
        print_spaces(photo_placement);
        printf("@\n");
    }
    bst_node *current_node = root;

    //Start of traversing BST
    while(current_node != NULL){
        int num_current = atoi(current_node->area_code);

        //If area code matches area code of current node
        if(compare(num_current, num_area_code)== 0){
            printf("%s%s%s","\nArea code from: ", current_node->p_or_t, "\n\n");
            return;
        }

        //If area code is greater than that of current node
        else if(compare(num_current, num_area_code) == 1){
            current_node = current_node->right;
            print_spaces(photo_placement);
            printf("&\n");
            photo_placement = photo_placement+1;
            print_spaces(photo_placement);
            printf("\\\n");
        }
        //If area code is smaller than that of current node
        else{
            current_node = current_node->left;
            print_spaces(photo_placement);
            printf("&\n");
            photo_placement = photo_placement-1;
            print_spaces(photo_placement);
            printf("/\n");
        }
    }
    printf("%s", not_found);
}

/*Function to compare two area codes and determine
 * whether the area code being searched for is
 * greate than (1 is returned) or is less than
 *(-1 is returned)
 */
int compare(int num_current, int num_looking){

    if(num_current < num_looking){
        return 1;
    }else if(num_current > num_looking){
        return -1;
    }
    return 0;
}

/*Function to recursively free up dynamically
 * allocated bst_node s in BST
 */
void free_bst(bst_node *current_node){
    if(current_node == NULL){
        return;
    }
    free_bst(current_node->left);
    free_bst(current_node->right);
    free(current_node);

}
/*Function to print spaces required for printing
 *out branch of BST traversed to search for
 *desired area code
 */
void print_spaces(int amount){
    for(int i = 0; i < amount; i++){
        printf(" ");
    }
}

/*Function to print out info of BST node */
void print_bst_node(bst_node *to_print){
    printf("%s%s%s%s%s", "Area Code:", to_print->area_code, " Province/Territory:",
    to_print->p_or_t, "\n");
}
