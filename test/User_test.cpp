//
// Created by leoke on 14/03/2025.
#include "gtest/gtest.h"
#include "../User.h"
#include <list>
class User_test : public ::testing::Test {
    protected:
    virtual void SetUp() override {
         user1 = User("user1", "user1", "user1");
         user2 = User("user2", "user2", "user2");
    }
    virtual void TearDown() override {
        user1.get_messages().clear();
        user2.get_messages().clear();
    }

    User user1;
    User user2;
};


TEST_F(User_test, send_message) {
    ASSERT_TRUE(user1.send_message("messaggio 1", user2));
    ASSERT_EQ(user1.get_messages().size(), 0);
    ASSERT_EQ(user2.get_messages().size(), 1);
    ASSERT_EQ(user2.get_messages().begin()->get_text(), "messaggio 1");
}
TEST_F(User_test, send_message_empty) {
    ASSERT_FALSE(user1.send_message("", user2));
    ASSERT_EQ(user1.get_messages().size(), 0);
    ASSERT_EQ(user2.get_messages().size(), 0);
}
TEST_F(User_test, send_message_same_user) {
    ASSERT_FALSE(user1.send_message("messaggio 1", user1));
    ASSERT_EQ(user1.get_messages().size(), 0);
    ASSERT_EQ(user1.get_messages().size(), 0);
}

//
