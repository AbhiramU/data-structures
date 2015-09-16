#include "assert.h"
#include "bst.h"

void test_bst_with_one_key()
{
	BST tree = bst_new();
    Result res = 0;

    bst_add(&tree, 10, &res);
    assert(res == 1);

    bst_add(&tree, 10, &res);
    assert(res == 0);
}

void test_bst_with_three_keys()
{
	BST tree = bst_new();
    Result res = 0;

    bst_add(&tree, 100, &res);
    assert(res == 1);
    assert(bst_mass(&tree) == 1);
    bst_add(&tree, 300, &res);
    assert(res == 1);
    assert(bst_mass(&tree) == 2);
    bst_add(&tree, 50, &res);
    assert(res == 1);
    assert(bst_mass(&tree) == 3);

    bst_add(&tree, 100, &res);
    assert(res == 0);
    assert(bst_mass(&tree) == 3);
    bst_add(&tree, 300, &res);
    assert(res == 0);
    assert(bst_mass(&tree) == 3);
    bst_add(&tree, 50, &res);
    assert(res == 0);
    assert(bst_mass(&tree) == 3);
}

int main()
{
	test_bst_with_one_key();
    test_bst_with_three_keys();
    
    return 0;
}