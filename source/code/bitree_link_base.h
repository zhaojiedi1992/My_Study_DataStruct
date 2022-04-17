// bitree_link_base.h
#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
typedef struct  TreeNode *BsTree ;
struct  TreeNode{
    ElementType Data ;
    BsTree  Left;
    BsTree  Right;
};
