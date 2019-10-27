#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <algorithm>

#define PRINT(a) fprintf(stderr, "\033[33m%s\033[0m \033[32m%s\033[0m\n", a, "Passed")

#include "../bpt.h"
using bpt::bptree;

int main(int argc, char *argv[])
{
    const int size = 128;

    {
    bptree tree("test.db", true);
    assert(tree._order == 4);
    assert(tree._value_size == sizeof(bpt::value_type));
    assert(tree._key_size == sizeof(bpt::key_type));
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 1);
    assert(tree._height == 1);
    PRINT("EmptyTree");
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._value_size == sizeof(bpt::value_type));
    assert(tree._key_size == sizeof(bpt::key_type));
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 1);
    assert(tree._height == 1);
    PRINT("ReReadEmptyTree");

    assert(tree.insert("t2", 2) == 0);
    assert(tree.insert("t4", 4) == 0);
    assert(tree.insert("t1", 1) == 0);
    assert(tree.insert("t3", 3) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._value_size == sizeof(bpt::value_type));
    assert(tree._key_size == sizeof(bpt::key_type));
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 1);
    assert(tree._height == 1);

    bpt::__leaf_node_t leaf;
    tree.__map(&leaf, tree.__search_leaf("t1"));
    assert(leaf.n == 4);
    assert(bpt::__key_compare(leaf.children[0].key, "t1") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "t2") == 0);
    assert(bpt::__key_compare(leaf.children[2].key, "t3") == 0);
    assert(bpt::__key_compare(leaf.children[3].key, "t4") == 0);
    bpt::value_type value;
    assert(tree.search("t1", &value) == 0);
    assert(value == 1);
    assert(tree.search("t2", &value) == 0);
    assert(value == 2);
    assert(tree.search("t3", &value) == 0);
    assert(value == 3);
    assert(tree.search("t4", &value) == 0);
    assert(value == 4);
    assert(tree.insert("t1", 4) == 1);
    assert(tree.insert("t2", 4) == 1);
    assert(tree.insert("t3", 4) == 1);
    assert(tree.insert("t4", 4) == 1);
    PRINT("Insert4Elements");

    assert(tree.insert("t5", 5) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._value_size == sizeof(bpt::value_type));
    assert(tree._key_size == sizeof(bpt::key_type));
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 2);
    assert(tree._height == 1);

    bpt::__internal_bnode_t index;
    off_t index_off = tree.__search_index("t1");
    tree.__map(&index, index_off);
    assert(index.n == 2);
    assert(index.parent == 0);
    assert(bpt::__key_compare(index.children[0].key, "t4") == 0);

    bpt::__leaf_node_t leaf1, leaf2;
    off_t leaf1_off = tree.__search_leaf("t1");
    assert(leaf1_off == index.children[0].child);
    tree.__map(&leaf1, leaf1_off);
    assert(leaf1.n == 3);
    assert(bpt::__key_compare(leaf1.children[0].key, "t1") == 0);
    assert(bpt::__key_compare(leaf1.children[1].key, "t2") == 0);
    assert(bpt::__key_compare(leaf1.children[2].key, "t3") == 0);

    off_t leaf2_off = tree.__search_leaf("t4");
    assert(leaf1.next == leaf2_off);
    assert(leaf2_off == index.children[1].child);
    tree.__map(&leaf2, leaf2_off);
    assert(leaf2.n == 2);
    assert(bpt::__key_compare(leaf2.children[0].key, "t4") == 0);
    assert(bpt::__key_compare(leaf2.children[1].key, "t5") == 0);

    PRINT("SplitLeafBy2");
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree.insert("t1", 4) == 1);
    assert(tree.insert("t2", 4) == 1);
    assert(tree.insert("t3", 4) == 1);
    assert(tree.insert("t4", 4) == 1);
    assert(tree.insert("t5", 4) == 1);
    bpt::value_type value;
    assert(tree.search("t1", &value) == 0);
    assert(value == 1);
    assert(tree.search("t2", &value) == 0);
    assert(value == 2);
    assert(tree.search("t3", &value) == 0);
    assert(value == 3);
    assert(tree.search("t4", &value) == 0);
    assert(value == 4);
    assert(tree.search("t5", &value) == 0);
    assert(value == 5);
    PRINT("Search2Leaf");

    assert(tree.insert("t6", 6) == 0);
    assert(tree.insert("t7", 7) == 0);
    assert(tree.insert("t8", 8) == 0);
    assert(tree.insert("t9", 9) == 0);
    assert(tree.insert("ta", 10) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 3);
    assert(tree._height == 1);

    bpt::__internal_bnode_t index;
    off_t index_off = tree.__search_index("t8");
    tree.__map(&index, index_off);
    assert(index.n == 3);
    assert(index.parent == 0);
    assert(bpt::__key_compare(index.children[0].key, "t4") == 0);
    assert(bpt::__key_compare(index.children[1].key, "t7") == 0);

    bpt::__leaf_node_t leaf1, leaf2, leaf3;
    off_t leaf1_off = tree.__search_leaf("t3");
    off_t leaf2_off = tree.__search_leaf("t5");
    off_t leaf3_off = tree.__search_leaf("ta");
    tree.__map(&leaf1, leaf1_off);
    tree.__map(&leaf2, leaf2_off);
    tree.__map(&leaf3, leaf3_off);
    assert(index.children[0].child == leaf1_off);
    assert(index.children[1].child == leaf2_off);
    assert(index.children[2].child == leaf3_off);
    assert(leaf1.next == leaf2_off);
    assert(leaf2.next == leaf3_off);
    assert(leaf3.next == 0);
    PRINT("SplitLeafBy3");
    }

    {
    bptree tree("test.db", true);
    assert(tree._order == 4);
    assert(tree.insert("t00", 0) == 0);
    assert(tree.insert("t01", 1) == 0);
    assert(tree.insert("t02", 2) == 0);
    assert(tree.insert("t03", 3) == 0);
    assert(tree.insert("t04", 4) == 0);
    assert(tree.insert("t05", 5) == 0);
    assert(tree.insert("t06", 6) == 0);
    assert(tree.insert("t07", 7) == 0);
    assert(tree.insert("t08", 8) == 0);
    assert(tree.insert("t09", 9) == 0);
    assert(tree.insert("t10", 10) == 0);
    assert(tree.insert("t11", 11) == 0);
    assert(tree.insert("t12", 12) == 0);
    assert(tree.insert("t13", 13) == 0);
    assert(tree.insert("t14", 14) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 3);
    assert(tree._leaf_cnt == 5);
    assert(tree._height == 2);

    bpt::__internal_bnode_t node1, node2, root;
    tree.__map(&root, tree._root_offset);
    off_t node1_off = tree.__search_index("t03");
    off_t node2_off = tree.__search_index("t14");
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    assert(root.n == 2);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(bpt::__key_compare(root.children[0].key, "t09") == 0);
    assert(node1.n == 3);
    assert(bpt::__key_compare(node1.children[0].key, "t03") == 0);
    assert(bpt::__key_compare(node1.children[1].key, "t06") == 0);
    assert(node2.n == 2);
    assert(bpt::__key_compare(node2.children[0].key, "t12") == 0);

    bpt::value_type value;
    for (int i = 0; i < 10; i++) {
        char key[8] = { 0 };
        sprintf(key, "t0%d", i);
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    for (int i = 10; i < 14; i++) {
        char key[8] = { 0 };
        sprintf(key, "t%d", i);
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }

    PRINT("CreateNewRoot");
    }

    {
    bptree tree("test.db", true);
    assert(tree._order == 4);
    for (int i = 0; i < 12; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 4);
    assert(tree._height == 1);

    bpt::__internal_bnode_t node;
    tree.__map(&node, tree._root_offset);
    assert(node.n == 4);
    assert(bpt::__key_compare(node.children[0].key, "11") == 0);
    assert(bpt::__key_compare(node.children[1].key, "3") == 0);
    assert(bpt::__key_compare(node.children[2].key, "6") == 0);

    off_t off1 = tree.__search_leaf("0");
    off_t off2 = tree.__search_leaf("11");
    off_t off3 = tree.__search_leaf("5");
    off_t off4 = tree.__search_leaf("6");
    assert(node.children[0].child == off1);
    assert(node.children[1].child == off2);
    assert(node.children[2].child == off3);
    assert(node.children[3].child == off4);
    bpt::__leaf_node_t node1, node2, node3, node4;
    tree.__map(&node1, off1);
    tree.__map(&node2, off2);
    tree.__map(&node3, off3);
    tree.__map(&node4, off4);
    assert(node1.n == 3);
    assert(node2.n == 2);
    assert(node3.n == 3);
    assert(node4.n == 4);

    for (int i = 0; i < 12; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    PRINT("SplitInTheBeginning");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 10; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    assert(tree.insert("51", 51) == 0);
    assert(tree.insert("52", 52) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 4);
    assert(tree._height == 1);

    bpt::__internal_bnode_t node;
    tree.__map(&node, tree._root_offset);
    assert(node.n == 4);
    assert(bpt::__key_compare(node.children[0].key, "3") == 0);
    assert(bpt::__key_compare(node.children[1].key, "51") == 0);
    assert(bpt::__key_compare(node.children[2].key, "6") == 0);

    off_t off1 = tree.__search_leaf("0");
    off_t off2 = tree.__search_leaf("3");
    off_t off3 = tree.__search_leaf("51");
    off_t off4 = tree.__search_leaf("6");
    assert(node.children[0].child == off1);
    assert(node.children[1].child == off2);
    assert(node.children[2].child == off3);
    assert(node.children[3].child == off4);
    bpt::__leaf_node_t node1, node2, node3, node4;
    tree.__map(&node1, off1);
    tree.__map(&node2, off2);
    tree.__map(&node3, off3);
    tree.__map(&node4, off4);
    assert(node1.n == 3);
    assert(node2.n == 3);
    assert(node3.n == 2);
    assert(node4.n == 4);
    for (int i = 0; i < 10; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    assert(tree.insert("51", 51) == 1);
    assert(tree.insert("52", 52) == 1);
    PRINT("SplitInTheMiddle");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 15; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 3);
    assert(tree._leaf_cnt == 5);
    assert(tree._height == 2);

    bpt::__internal_bnode_t node1, node2, root;
    tree.__map(&root, tree._root_offset);
    off_t node1_off = tree.__search_index("0");
    off_t node2_off = tree.__search_index("6");
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    assert(root.n == 2);
    assert(bpt::__key_compare(root.children[0].key, "3") == 0);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(node1.n == 3);
    assert(bpt::__key_compare(node1.children[0].key, "11") == 0);
    assert(bpt::__key_compare(node1.children[1].key, "14") == 0);
    assert(node2.n == 2);
    assert(bpt::__key_compare(node2.children[0].key, "6") == 0);
    for (int i = 0; i < 15; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    PRINT("CreateNewRootInMiddle");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 30; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    bptree tree("test.db");
    assert(tree._internal_cnt == 5);
    assert(tree._leaf_cnt == 10);
    assert(tree._height == 2);

    bpt::__internal_bnode_t node1, node2, node3, node4, root;
    tree.__map(&root, tree._root_offset);
    off_t node1_off = tree.__search_index("11");
    off_t node2_off = tree.__search_index("22");
    off_t node3_off = tree.__search_index("28");
    off_t node4_off = tree.__search_index("6");
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    tree.__map(&node3, node3_off);
    tree.__map(&node4, node4_off);
    assert(root.prev == 0);
    assert(root.next == 0);
    assert(node1.prev == 0);
    assert(node1.next == node2_off);
    assert(node2.prev == node1_off);
    assert(node2.next == node3_off);
    assert(node3.prev == node2_off);
    assert(node3.next == node4_off);
    assert(node4.prev == node3_off);
    assert(node4.next == 0);
    assert(root.n == 4);
    assert(bpt::__key_compare(root.children[0].key, "17") == 0);
    assert(bpt::__key_compare(root.children[1].key, "25") == 0);
    assert(bpt::__key_compare(root.children[2].key, "3") == 0);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(root.children[2].child == node3_off);
    assert(root.children[3].child == node4_off);
    assert(node1.n == 3);
    assert(bpt::__key_compare(node1.children[0].key, "11") == 0);
    assert(bpt::__key_compare(node1.children[1].key, "14") == 0);
    assert(node2.n == 3);
    assert(bpt::__key_compare(node2.children[0].key, "2") == 0);
    assert(bpt::__key_compare(node2.children[1].key, "22") == 0);
    assert(node3.n == 2);
    assert(bpt::__key_compare(node3.children[0].key, "28") == 0);
    assert(node4.n == 2);
    assert(bpt::__key_compare(node4.children[0].key, "6") == 0);

    for (int i = 0; i < 30; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    PRINT("SplitAfterNewRoot");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 49; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    bptree tree("test.db");
    assert(tree._internal_cnt == 9);
    assert(tree._leaf_cnt == 17);
    assert(tree._height == 3);

    bpt::__internal_bnode_t root;
    tree.__map(&root, tree._root_offset);
    assert(root.n == 2);
    assert(bpt::__key_compare(root.children[0].key, "3") == 0);

    bpt::__internal_bnode_t node1, node2;
    tree.__map(&node1, root.children[0].child);
    tree.__map(&node2, root.children[1].child);
    assert(node1.n == 3);
    assert(bpt::__key_compare(node1.children[0].key, "17") == 0);
    assert(bpt::__key_compare(node1.children[1].key, "25") == 0);
    assert(node2.n == 3);
    assert(bpt::__key_compare(node2.children[0].key, "4") == 0);
    assert(bpt::__key_compare(node2.children[1].key, "45") == 0);

    bpt::__internal_bnode_t node3, node4, node5;
    tree.__map(&node3, node2.children[0].child);
    assert(node3.n == 4);
    assert(bpt::__key_compare(node3.children[0].key, "32") == 0);
    assert(bpt::__key_compare(node3.children[1].key, "35") == 0);
    assert(bpt::__key_compare(node3.children[2].key, "38") == 0);
    tree.__map(&node4, node2.children[1].child);
    assert(node4.n == 2);
    assert(bpt::__key_compare(node4.children[0].key, "42") == 0);
    tree.__map(&node5, node2.children[2].child);
    assert(node5.n == 3);
    assert(bpt::__key_compare(node5.children[0].key, "48") == 0);
    assert(bpt::__key_compare(node5.children[1].key, "6") == 0);

    for (int i = 0; i < 49; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    PRINT("DanglingMiddleKey");
    }

    int numbers[size];
    for (int i = 0; i < size; i++)
        numbers[i] = i;

    {
    bptree tree("test.db", true);
    for (int i = 0; i < size; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.insert(key, numbers[i]) == 0);
    }
    }

    {
    bptree tree("test.db");
    for (int i = 0; i < size; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == numbers[i]);
    }
    PRINT("InsertManyKeys");
    }

    std::reverse(numbers, numbers + size);
    {
    bptree tree("test.db", true);
    for (int i = 0; i < size; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.insert(key, numbers[i]) == 0);
    }
    }

    {
    bptree tree("test.db");
    for (int i = 0; i < size; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == numbers[i]);
    }
    PRINT("InsertManyKeysReverse");
    }

    for (int i = 0; i < 10; i++) {
        std::random_shuffle(numbers, numbers + size);
        {
        bptree tree("test.db", true);
        for (int i = 0; i < size; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[i]);
            assert(tree.insert(key, numbers[i]) == 0);
        }
        }

        {
        bptree tree("test.db");
        for (int i = 0; i < size; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[i]);
            bpt::value_type value;
            assert(tree.search(key, &value) == 0);
            assert(value == numbers[i]);
        }
        }
    }

    PRINT("InsertManyKeysRandom");

    {
    for (int i = 0; i < size; i++)
        numbers[i] = i;

    bptree tree("test.db", true);
    for (int i = 0; i < size; i++) {
        char key[8] = { 0 };
        sprintf(key, "%04d", numbers[i]);
        assert(tree.insert(key, numbers[i]) == 0);
    }
    }

    {
    bptree tree("test.db");
    int start = rand() % (size - 20);
    int end = rand() % (size - start) + start;
    char bufkey1[8] = { 0 };
    char bufkey2[8] = { 0 };
    sprintf(bufkey1, "%04d", start);
    sprintf(bufkey2, "%04d", end);
    bpt::key_type key1(bufkey1), key2(bufkey2);
    bpt::value_type values[end - start + 1];
    assert(tree.search_range(&key1, key2, values, end - start + 1) == end - start + 1);

    for (int i = start; i <= end; i++) {
        char key[8] = { 0 };
        sprintf(key, "%04d", i);
        assert(i == values[i - start]);
    }

    bool next;
    assert(tree.search_range(&key1, key2, values, end - start + 100) == end - start + 1);
    assert(tree.search_range(&key1, key2, values, end - start + 100, &next) == end - start + 1);
    assert(next == false);

    PRINT("SearchRangeSuccess");

    assert(tree.search_range(&key1, key1, values, end - start + 1) == 1);
    assert(tree.search_range(&key1, key1, values, end - start + 1, &next) == 1);
    assert(next == false);
    assert(tree.search_range(&key2, key2, values, end - start + 1) == 1);
    assert(tree.search_range(&key2, key2, values, end - start + 1, &next) == 1);
    assert(next == false);
    PRINT("SearchRangeSameKey");

    assert(tree.search_range(&key2, key1, values, end - start + 1) == -1);
    assert(tree.search_range(&key1, key2, values, end - start) == end - start);
    assert(tree.search_range(&key1, key2, values, end - start, &next) == end - start);
    assert(next == true);

    PRINT("SearchRangeFailed");
    }

    for (int i = 0; i < 2; i++) {
        std::random_shuffle(numbers, numbers + size);
        {
        bptree tree("test.db", true);
        for (int i = 0; i < size; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[i]);
            assert(tree.insert(key, numbers[i]) == 0);
        }
        }

        {
        bptree tree("test.db");
        std::random_shuffle(numbers, numbers + size);
        for (int i = 0; i < size; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[i]);
            assert(tree.update(key, numbers[i] + 1) == 0);
        }
        }

        {
        bptree tree("test.db");
        for (int i = 0; i < size; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[i]);
            bpt::value_type value;
            assert(tree.search(key, &value) == 0);
            assert(value == numbers[i] + 1);
        }

        for (int i = size; i < size * 2; i++) {
            char key[8] = { 0 };
            sprintf(key, "%d", i);
            bpt::value_type value;
            assert(tree.search(key, &value) != 0);
            assert(tree.update(key, i) != 0);
        }
        }
    }

    PRINT("UpdateManyKeysRandom");

    {
    bptree tree("test.db");
    bpt::__leaf_node_t leaf;
    off_t offset = tree._leaf_offset;
    off_t last = 0;
    size_t counter = 0;
    while (offset != 0) {
        tree.__map(&leaf, offset);
        ++counter;
        assert(last == leaf.prev);
        last = offset;
        offset = leaf.next;
    }
    assert(counter == tree._leaf_cnt);

    PRINT("LeafsList");
    }

    {
    bptree tree("test.db", true);
    assert(tree.insert("t2", 2) == 0);
    assert(tree.insert("t4", 4) == 0);
    assert(tree.insert("t1", 1) == 0);
    assert(tree.insert("t3", 3) == 0);
    }

    {
    bptree tree("test.db");
    assert(tree.remove("t9") != 0);
    assert(tree.remove("t3") == 0);
    assert(tree.remove("t3") != 0);

    bpt::__leaf_node_t leaf;
    tree.__map(&leaf, tree._leaf_offset);
    assert(leaf.n == 3);
    assert(bpt::__key_compare(leaf.children[0].key, "t1") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "t2") == 0);
    assert(bpt::__key_compare(leaf.children[2].key, "t4") == 0);
    assert(tree.remove("t1") == 0);
    tree.__map(&leaf, tree._leaf_offset);
    assert(leaf.n == 2);
    assert(bpt::__key_compare(leaf.children[0].key, "t2") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "t4") == 0);
    assert(tree.remove("t2") == 0);
    tree.__map(&leaf, tree._leaf_offset);
    assert(leaf.n == 1);
    assert(bpt::__key_compare(leaf.children[0].key, "t4") == 0);
    assert(tree.remove("t4") == 0);
    tree.__map(&leaf, tree._leaf_offset);
    assert(leaf.n == 0);
    assert(tree.remove("t4") != 0);

    PRINT("RemoveInRootLeaf");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 10; i++) {
        char key[8] = { 0 };
        sprintf(key, "%02d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    bptree tree("test.db");
    bpt::__leaf_node_t leaf;
    bpt::__internal_bnode_t node;
    assert(tree._leaf_cnt == 3);
    assert(tree._internal_cnt == 1);

    // | 3 6  |
    // | 0 1 2 | 3 4 5 | 6 7 8 9 |
    tree.__map(&node, tree._root_offset);
    assert(bpt::__key_compare(node.children[0].key, "03") == 0);
    assert(bpt::__key_compare(node.children[1].key, "06") == 0);
    assert(tree.remove("03") == 0);
    assert(tree.remove("04") == 0);
    // | 2 6  |
    // | 0 1 | 2 5 | 6 7 8 9 |
    tree.__map(&node, tree._root_offset);
    assert(bpt::__key_compare(node.children[0].key, "02") == 0);
    assert(bpt::__key_compare(node.children[1].key, "06") == 0);
    tree.__map(&leaf, tree.__search_leaf("00"));
    assert(leaf.parent == tree._root_offset);
    assert(leaf.n == 2);
    assert(bpt::__key_compare(leaf.children[0].key, "00") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "01") == 0);
    tree.__map(&leaf, tree.__search_leaf("05"));
    assert(leaf.parent == tree._root_offset);
    assert(leaf.n == 2);
    assert(bpt::__key_compare(leaf.children[0].key, "02") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "05") == 0);
    assert(tree.remove("05") == 0);
    // | 2 7  |
    // | 0 1 | 2 6 | 7 8 9 |
    tree.__map(&node, tree._root_offset);
    assert(node.n == 3);
    assert(bpt::__key_compare(node.children[0].key, "02") == 0);
    assert(bpt::__key_compare(node.children[1].key, "07") == 0);
    tree.__map(&leaf, tree.__search_leaf("04"));
    assert(leaf.parent == tree._root_offset);
    assert(leaf.n == 2);
    assert(bpt::__key_compare(leaf.children[0].key, "02") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "06") == 0);
    tree.__map(&leaf, tree.__search_leaf("07"));
    assert(leaf.parent == tree._root_offset);
    assert(leaf.n == 3);
    assert(bpt::__key_compare(leaf.children[0].key, "07") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "08") == 0);
    assert(bpt::__key_compare(leaf.children[2].key, "09") == 0);

    bpt::value_type value;
    assert(tree.search("00", &value) == 0);
    assert(value == 0);
    assert(tree.search("01", &value) == 0);
    assert(value == 1);
    assert(tree.search("02", &value) == 0);
    assert(value == 2);
    assert(tree.search("03", &value) != 0);
    assert(tree.search("04", &value) != 0);
    assert(tree.search("05", &value) != 0);
    assert(tree.search("06", &value) == 0);
    assert(value == 6);
    assert(tree.search("07", &value) == 0);
    assert(value == 7);
    assert(tree.search("08", &value) == 0);
    assert(value == 8);
    assert(tree.search("09", &value) == 0);
    assert(value == 9);

    PRINT("RemoveWithBorrow");
    }

    {
    bptree tree("test.db");
    bpt::__internal_bnode_t node;
    assert(tree._leaf_cnt == 3);
    assert(tree._internal_cnt == 1);

    // | 2 7  |
    // | 0 1 | 2 6 | 7 8 9 |
    assert(tree.remove("00") == 0);
    // | 7  |
    // | 1 2 6 | 7 8 9 |
    assert(tree._leaf_cnt == 2);
    assert(tree._internal_cnt == 1);
    tree.__map(&node, tree._root_offset);
    assert(node.n == 2);
    assert(bpt::__key_compare(node.children[0].key, "07") == 0);
    off_t leaf1_off, leaf2_off;
    leaf1_off = tree.__search_leaf("01");
    leaf2_off = tree.__search_leaf("07");
    assert(leaf1_off == node.children[0].child);
    assert(leaf2_off == node.children[1].child);
    bpt::__leaf_node_t leaf1, leaf2;
    tree.__map(&leaf1, leaf1_off);
    tree.__map(&leaf2, leaf2_off);
    assert(leaf1.n == 3);
    assert(leaf1.next == leaf2_off);
    assert(bpt::__key_compare(leaf1.children[0].key, "01") == 0);
    assert(bpt::__key_compare(leaf1.children[1].key, "02") == 0);
    assert(bpt::__key_compare(leaf1.children[2].key, "06") == 0);
    assert(leaf2.n == 3);
    assert(leaf2.next == 0);
    assert(tree.remove("09") == 0);
    tree.__map(&leaf2, leaf2_off);
    assert(leaf2.n == 2);
    assert(leaf2.next == 0);
    assert(bpt::__key_compare(leaf2.children[0].key, "07") == 0);
    assert(bpt::__key_compare(leaf2.children[1].key, "08") == 0);
    assert(tree.remove("01") == 0);
    assert(tree.remove("08") == 0);
    // |  |
    // | 2 6 7 |
    assert(tree._leaf_cnt == 1);
    assert(tree._internal_cnt == 1);
    tree.__map(&node, tree._root_offset);
    assert(node.n == 1);
    off_t offset;
    offset = tree.__search_leaf("02");
    assert(offset == node.children[0].child);
    bpt::__leaf_node_t leaf;
    tree.__map(&leaf, offset);
    assert(leaf.n == 3);
    assert(leaf.next == 0);
    assert(leaf.prev == 0);
    assert(bpt::__key_compare(leaf.children[0].key, "02") == 0);
    assert(bpt::__key_compare(leaf.children[1].key, "06") == 0);
    assert(bpt::__key_compare(leaf.children[2].key, "07") == 0);

    PRINT("RemoveWithMerge");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 15; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    // | 3  |
    // | 11 14  | 6  |
    // | 0 1 10 | 11 12 13 | 14 2 | 3 4 5 | 6 7 8 9 |
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 3);
    assert(tree._leaf_cnt == 5);
    assert(tree._height == 2);
    assert(tree.remove("6") == 0);
    assert(tree.remove("7") == 0);
    assert(tree.remove("8") == 0);
    assert(tree.remove("9") == 0);
    // | 14  |
    // | 11  | 3  |
    // | 0 1 10 | 11 12 13 | 14 2 | 3 4 5 |
    assert(tree._internal_cnt == 3);
    assert(tree._leaf_cnt == 4);
    assert(tree._height == 2);

    bpt::__internal_bnode_t node1, node2, root;
    tree.__map(&root, tree._root_offset);
    off_t node1_off = tree.__search_index("0");
    off_t node2_off = tree.__search_index("6");
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    assert(root.n == 2);
    assert(bpt::__key_compare(root.children[0].key, "14") == 0);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(node1.n == 2);
    assert(bpt::__key_compare(node1.children[0].key, "11") == 0);
    assert(node2.n == 2);
    assert(bpt::__key_compare(node2.children[0].key, "3") == 0);
    for (int i = 0; i < 6; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }
    for (int i = 6; i < 10; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) != 0);
    }
    for (int i = 10; i < 15; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        bpt::value_type value;
        assert(tree.search(key, &value) == 0);
        assert(value == i);
    }

    PRINT("RemoveWithBorrowInParentLeft");
    }

    {
    bptree tree("test.db");
    assert(tree._order == 4);
    assert(tree._internal_cnt == 3);
    assert(tree._leaf_cnt == 4);
    assert(tree._height == 2);
    assert(tree.remove("0") == 0);
    assert(tree.remove("11") == 0);
    bpt::__internal_bnode_t node1, node2, root;
    tree.__map(&root, tree._root_offset);
    off_t node1_off = tree.__search_index("0");
    off_t node2_off = tree.__search_index("6");
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    assert(root.n == 2);
    assert(bpt::__key_compare(root.children[0].key, "14") == 0);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(node1.n == 2);
    assert(bpt::__key_compare(node1.children[0].key, "11") == 0);
    assert(node2.n == 2);
    assert(bpt::__key_compare(node2.children[0].key, "3") == 0);
    // | 14  |
    // | 11  | 3  |
    // | 1 10 | 12 13 | 14 2 | 3 4 5 |
    assert(tree.remove("10") == 0);
    }

    {
    bptree tree("test.db");
    // | 14  3  |
    // | 1 12 13 | 14 2 | 3 4 5 |
    assert(tree._order == 4);
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 3);
    assert(tree._height == 1);
    bpt::__internal_bnode_t root;
    tree.__map(&root, tree._root_offset);
    assert(root.n == 3);
    assert(bpt::__key_compare(root.children[0].key, "14") == 0);
    assert(bpt::__key_compare(root.children[1].key, "3") == 0);
    assert(tree.insert("1", 0) != 0);
    assert(tree.insert("2", 0) != 0);
    assert(tree.insert("3", 0) != 0);
    assert(tree.insert("4", 0) != 0);
    assert(tree.insert("5", 0) != 0);
    assert(tree.insert("12", 0) != 0);
    assert(tree.insert("13", 0) != 0);
    assert(tree.insert("14", 0) != 0);

    PRINT("RemoveWithHeightDecrease");
    }

    {
    bptree tree("test.db", true);
    for (int i = 0; i < 30; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", i);
        assert(tree.insert(key, i) == 0);
    }
    }

    {
    // | 17 25 3  |
    // | 11 14  | 2 22  | 28  | 6  |
    // | 0 1 10 | 11 12 13 | 14 15 16 | 17 18 19 | 2 20 21 | 22 23 24 | 25 26 27 | 28 29 | 3 4 5 | 6 7 8 9 |
    bptree tree("test.db");
    bpt::__internal_bnode_t node1, node2, node3, node4, root;
    off_t node1_off, node2_off, node3_off, node4_off;
    assert(tree._order == 4);
    assert(tree._internal_cnt == 5);
    assert(tree._leaf_cnt == 10);
    assert(tree._height == 2);
    assert(tree.remove("0") == 0);
    assert(tree.remove("11") == 0);
    assert(tree.remove("10") == 0);
    assert(tree.remove("13") == 0);
    assert(tree.remove("12") == 0);
    // | 17 25 3  |
    // | 15  | 2 22  | 28  | 6  |
    // | 1 14 | 15 16 | 17 18 19 | 2 20 21 | 22 23 24 | 25 26 27 | 28 29 | 3 4 5 | 6 7 8 9 |
    assert(tree.remove("14") == 0);
    // | 2 25 3  |
    // | 17  | 22  | 28  | 6  |
    // | 1 15 16 | 17 18 19 | 2 20 21 | 22 23 24 | 25 26 27 | 28 29 | 3 4 5 | 6 7 8 9 |
    assert(tree._internal_cnt == 5);
    assert(tree._leaf_cnt == 8);
    assert(tree._height == 2);

    node1_off = tree.__search_index("11");
    node2_off = tree.__search_index("22");
    node3_off = tree.__search_index("28");
    node4_off = tree.__search_index("6");
    tree.__map(&root, tree._root_offset);
    tree.__map(&node1, node1_off);
    tree.__map(&node2, node2_off);
    tree.__map(&node3, node3_off);
    tree.__map(&node4, node4_off);
    assert(root.prev == 0);
    assert(root.next == 0);
    assert(node1.prev == 0);
    assert(node1.next == node2_off);
    assert(node2.prev == node1_off);
    assert(node2.next == node3_off);
    assert(node3.prev == node2_off);
    assert(node3.next == node4_off);
    assert(node4.prev == node3_off);
    assert(node4.next == 0);
    assert(root.n == 4);
    assert(bpt::__key_compare(root.children[0].key, "2") == 0);
    assert(bpt::__key_compare(root.children[1].key, "25") == 0);
    assert(bpt::__key_compare(root.children[2].key, "3") == 0);
    assert(root.children[0].child == node1_off);
    assert(root.children[1].child == node2_off);
    assert(root.children[2].child == node3_off);
    assert(root.children[3].child == node4_off);
    assert(node1.n == 2);
    assert(bpt::__key_compare(node1.children[0].key, "17") == 0);
    assert(node2.n == 2);
    assert(bpt::__key_compare(node2.children[0].key, "22") == 0);
    assert(node3.n == 2);
    assert(bpt::__key_compare(node3.children[0].key, "28") == 0);
    assert(node4.n == 2);
    assert(bpt::__key_compare(node4.children[0].key, "6") == 0);

    PRINT("RemoveWithBorrowInParentRight");
    }

    const int size2 = 119;
    for (int i = 0; i < size2; i++)
        numbers[i] = i;

    {
    bptree tree("test.db", true);
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.insert(key, numbers[i]) == 0);
    }
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.remove(key) == 0);
        for (int j = i + 1; j < size2; j++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[j]);
            bpt::value_type value;
            assert(tree.search(key, &value) == 0);
        }
    }
    }

    {
    bptree tree("test.db");
    assert(tree._internal_cnt == 1);
    assert(tree._leaf_cnt == 1);
    assert(tree._height == 1);
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        bpt::value_type value;
        assert(tree.search(key, &value) != 0);
    }
    PRINT("RemoveManyKeys");
    }

    std::reverse(numbers, numbers + size2);
    {
    bptree tree("test.db", true);
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.insert(key, numbers[i]) == 0);
    }
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        assert(tree.remove(key) == 0);
        for (int j = i + 1; j < size2; j++) {
            char key[8] = { 0 };
            sprintf(key, "%d", numbers[j]);
            bpt::value_type value;
            assert(tree.search(key, &value) == 0);
        }
    }
    }

    {
    bptree tree("test.db");
    for (int i = 0; i < size2; i++) {
        char key[8] = { 0 };
        sprintf(key, "%d", numbers[i]);
        bpt::value_type value;
        assert(tree.search(key, &value) != 0);
    }

    PRINT("RemoveManyKeysReverse");
    }

    unlink("test.db");

    return 0;
}
