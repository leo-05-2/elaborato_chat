//
// Created by leoke on 03/01/2025.
#include "gtest/gtest.h"
#include "../Chat.h"
#include "../User.h"

class Chat_test : public ::testing::Test {
protected:

    void SetUp() override {
        sender = User ("sender", "sender");
        receiver = User ("receiver", "receiver");
        chat_m= {Message("messaggio 1",sender.get_user_id(),receiver.get_user_id(),1),Message("messaggio 2",
                 receiver.get_user_id(),sender.get_user_id(),2),Message("messaggio 3",sender.get_user_id(),receiver.get_user_id(),3),
        Message("messaggio 4",receiver.get_user_id(),sender.get_user_id(),4)};
        for (int i = 0; i < chat_m.size(); i++) {
            if (i % 2 == 0) {
                ASSERT_TRUE(sender.send_message(chat_m[i].get_text(), receiver, chat_m[i].get_time()));
            }
            else {
                ASSERT_TRUE(receiver.send_message(chat_m[i].get_text(), sender, chat_m[i].get_time()));
            }
        }

    }
    void TearDown() override {
        sender.get_messages().clear();
        receiver.get_messages().clear();
    }

    User sender;
    User receiver;
    std::vector<Message> chat_m;
};

TEST_F(Chat_test, create_chat) {
    Chat chat(sender,receiver);
    auto chat_e=chat.get_messages();
    EXPECT_EQ(chat_e.size(),chat_m.size());
    for (int i = 0; i < chat_e.size(); i++) {
        EXPECT_EQ(chat_e[i].get_text(), chat_m[i].get_text());
    }
}
TEST_F(Chat_test, create_chat_empty) {
    sender.get_messages().clear();
    receiver.get_messages().clear();
    Chat chat(sender,receiver);
    auto chat_e=chat.get_messages();
    EXPECT_EQ(chat_e.size(),0);
}

//
