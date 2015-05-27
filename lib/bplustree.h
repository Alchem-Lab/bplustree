/*
 * Copyright (C) 2015, Leo Ma <begeekmyfriend@gmail.com>
 */

#ifndef _BPLUS_TREE_H
#define _BPLUS_TREE_H

#define MAX_ORDER        1024
#define MAX_ENTRIES      4096
#define MAX_LEVEL        10

struct bplus_node {
        int type;
        struct bplus_non_leaf *parent;
};

struct bplus_non_leaf {
        int type;
        struct bplus_non_leaf *parent;
        struct bplus_non_leaf *next;
        int children;
        int key[MAX_ORDER - 1];
        struct bplus_node *sub_ptr[MAX_ORDER];
};

struct bplus_leaf {
        int type;
        struct bplus_non_leaf *parent;
        struct bplus_leaf *next;
        int entries;
        int key[MAX_ENTRIES];
        int data[MAX_ENTRIES];
};

struct bplus_tree {
        int order;
        int entries;
        int level;
        struct bplus_node *root;
        struct bplus_node *head[MAX_LEVEL];
};

void bplus_tree_dump(struct bplus_tree *tree);
int bplus_tree_get(struct bplus_tree *tree, int key);
void bplus_tree_put(struct bplus_tree *tree, int key, int data);
struct bplus_tree *bplus_tree_init(int level, int order, int entries);

#endif  /* _BPLUS_TREE_H */