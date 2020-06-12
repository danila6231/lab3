#pragma once

#include "test_framework.h"

void TestKLP() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    AssertEqual(bt.klp_tree(), correct_result, "Error");
}

void TestKPL() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {8, 10, 14, 13, 3, 6, 7, 4, 1};
    AssertEqual(bt.kpl_tree(), correct_result, "Error");
}

void TestLPK() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {1, 4, 7, 6, 3, 13, 14, 10, 8};
    AssertEqual(bt.lpk_tree(), correct_result, "Error");
}

void TestLKP() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    AssertEqual(bt.lkp_tree(), correct_result, "Error");
}

void TestPLK() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {13, 14, 10, 7, 4, 6, 1, 3, 8};
    AssertEqual(bt.plk_tree(), correct_result, "Error");
}

void TestPKL() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {14, 13, 10, 8, 7, 6, 4, 3, 1};
    AssertEqual(bt.pkl_tree(), correct_result, "Error");
}

void TestAddElement() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {8, 3, 1, 6, 4, 7, 10, 9, 14, 13};
    bt.AddElement(9);
    AssertEqual(bt.klp_tree(), correct_result, "Error");
}

void TestSearchElement() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    bool res1 = bt.SearchElement(7);
    bool res2 = bt.SearchElement(15);
    AssertEqual(res1, true, "Error");
    AssertEqual(res2, false, "Error");
}

void TestDeleteElement() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    bt.DeleteElement(10);
    vector<int> correct_result = {8, 3, 1, 6, 4, 7, 14, 13};
    AssertEqual(bt.klp_tree(), correct_result, "Error");
}

void TestMap() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    bt.Map(decrement);
    vector<int> correct_result = {7, 2, 0, 5, 3, 6, 9, 13, 12};
    AssertEqual(bt.klp_tree(), correct_result, "Error");
}

void TestWhere() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    bt.Where(more_then_three);
    vector<int> correct_result = {8, 6, 4, 7, 10, 14, 13};
    AssertEqual(bt.klp_tree(), correct_result, "Error");
}

void TestReduce() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    int result = bt.Reduce(multiply_items, 2);
    int correct_result = 14'676'480;
    AssertEqual(result, correct_result, "Error");
}

void TestSubTree() {
    binary_tree<int> bt({8, 3, 10, 1, 6, 14, 4, 7, 13});
    vector<int> correct_result = {6, 4, 7};
    AssertEqual((*bt.SubTree(6)).klp_tree(), correct_result, "Error");
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestKLP, "Test KLP");
    tr.RunTest(TestKPL, "Test KPL");
    tr.RunTest(TestLPK, "Test LPK");
    tr.RunTest(TestLKP, "Test LKP");
    tr.RunTest(TestPLK, "Test PLK");
    tr.RunTest(TestPKL, "Test PKL");
    tr.RunTest(TestAddElement, "Test Add Element");
    tr.RunTest(TestSearchElement, "Test Search Element");
    tr.RunTest(TestDeleteElement, "Test Delete Element");
    tr.RunTest(TestMap, "Test Map");
    tr.RunTest(TestWhere, "Test Where");
    tr.RunTest(TestReduce, "Test Reduce");
    tr.RunTest(TestSubTree, "Test SubTree");
}