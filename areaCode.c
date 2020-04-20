
#define _GNU_SOURCE

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include "bst.h"
bst_node* file_to_bst(char *file_name){
    FILE *open_file = NULL;
    open_file = fopen(file_name, "r");
    char *current_line = NULL, *temp_line = NULL;
    bst_node *root = NULL, *temp = NULL;
    size_t len = 0;
    ssize_t line_size;
    if(open_file == NULL){
        return root;
    }
    while((line_size = getline(&current_line, &len, open_file)) != -1){
        temp_line = (char*)malloc((strlen(current_line) + 1)*sizeof(char));
        assert(temp_line != NULL);
        strncpy(temp_line, current_line, strlen(current_line)+1);
        temp = new_bst_node(temp_line);
        root = add_in(root, temp);
        free(temp_line);

    }
    fclose(open_file);
    return root;
}

int main(int argc, char *argv[]){
    char *area_code_file = NULL;
    bst_node *area_code_root = NULL;
    int area_code = 0;
    if(argc != 3){
        exit(0);
    }else{
        area_code_file = argv[1];
        area_code = atoi(argv[2]);
    }

    area_code_root = file_to_bst(area_code_file);
    search_for(area_code_root, area_code);
    free_bst(area_code_root);
    exit(0);
}    
    
