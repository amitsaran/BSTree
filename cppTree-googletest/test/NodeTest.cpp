#include "gtest/gtest.h"
#include "Node.h"

TEST(Node, createNewNode)
{
    int data = 4;
    Node* ptr = new Node(data);
    ASSERT_NE(nullptr, ptr);
}

