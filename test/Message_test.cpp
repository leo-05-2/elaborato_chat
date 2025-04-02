//
// Created by leoke on 03/01/2025.
#include "gtest/gtest.h"
#include "../Chat.h"
class Message_test : public ::testing::Test {
protected:
    void setUp()  {

    }
    std::string text;
    std::string sender_id;
    std::string receiver_id;
    std::time_t time;
    bool read;
};
TEST_F(Message_test, constructor) {
    Message message("test message","sender","receiver");
    ASSERT_TRUE(message.get_text() == "test message");
    ASSERT_TRUE(message.get_sender_id() == "sender");
    ASSERT_TRUE(message.get_receiver_id() == "receiver");
}
TEST_F(Message_test, comparison_operator) {
    Message message1("test message","sender","receiver");
    Message message2("test message","sender","receiver");
    ASSERT_TRUE(message1 == message2);
}


//
