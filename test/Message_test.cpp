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



//
