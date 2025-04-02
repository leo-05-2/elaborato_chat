//
// Created by leoke on 03/01/2025.
#include "gtest/gtest.h"
#include "../Chat.h"
#include "../Chat_registry.h"
#include <list>

class Chat_registry_test : public ::testing::Test {
protected:
    virtual void SetUp() override {
        user1=User("user1", "user1", "user1");
        user2=User("user2", "user2", "user2");
        user3=User("user3", "user3" , "user3");


    }
    virtual void TearDown() override {
        chats.clear();
        user1.get_messages().clear();
        user2.get_messages().clear();
        user3.get_messages().clear();
    }

    std::list<Chat> chats;
    User user1;
    User user2;
    User user3;
};

TEST_F(Chat_registry_test,remove_chat) {
    ASSERT_TRUE(user1.send_message("messaggio 1", user2,1));
    ASSERT_TRUE(user1.send_message("messaggio 2", user3,2));
    ASSERT_TRUE(user2.send_message("messaggio 3", user1,3));
    ASSERT_TRUE(user3.send_message("messaggio 4", user1,4));
    Chat chat1(user1, user2);
    Chat chat2(user1, user3);
    chats.push_back(chat1);
    chats.push_back(chat2);
    Chat_registry chatR(chats);
    chatR.remove_chat(chat2, user1, user3);
    EXPECT_EQ(chatR.get_chats().size(), 1);
    EXPECT_EQ( chatR.get_chats().begin()->get_messages(), Chat(user1,user2).get_messages());
    EXPECT_EQ(user1.get_messages().size(), 1)<<user1.get_messages().begin()->get_text(),
                                                         user1.get_messages().end()->get_text();
    EXPECT_EQ(user3.get_messages().size(), 0)<<user3.get_messages().begin()->get_text(),
                                                         user3.get_messages().end()->get_text();

}
TEST_F(Chat_registry_test,add_chat) {
    ASSERT_TRUE(user1.send_message("messaggio 1", user2));
    ASSERT_TRUE(user1.send_message("messaggio 2", user3));
    ASSERT_TRUE(user2.send_message("messaggio 3", user1));
    ASSERT_TRUE(user3.send_message("messaggio 4", user1));
    ASSERT_TRUE(user2.send_message("messaggio 5", user3));
    Chat chat1(user1, user2);
    Chat chat2(user1, user3);
    chats.push_back(chat1);
    chats.push_back(chat2);
    Chat_registry chatR(chats);
    Chat chat3(user2, user3);
    chatR.add_chat(chat3);
    EXPECT_EQ(chatR.get_chats().size(), 3);
    EXPECT_EQ( chatR.get_chats().back().get_messages(), chat3.get_messages());

}

TEST_F(Chat_registry_test, get_chat) {
    Message message1("messaggio 1", user1.get_user_id(), user2.get_user_id(), 1);
    Message message2("messaggio 2", user2.get_user_id(), user1.get_user_id(), 2);
    Message message3("messaggio 3", user1.get_user_id(), user2.get_user_id(), 3);
    user1.send_message(message1, user2);
    user2.send_message(message2, user1);
    user1.send_message(message3, user2);
    Chat chat1(user1, user2);
    chats.push_back(chat1);

    Chat_registry chatR = Chat_registry(chats);
    ASSERT_EQ(chatR.get_chat(user1, user2).get_messages().size(), 3);
    // faccio in modo di testare il funzionamento avendo selezionato user2
    Chat c = chatR.get_chat(user2, user1);
    auto it = c.get_messages().begin();
    ASSERT_EQ((it++)->get_read(), true);
    ASSERT_EQ((it++)->get_read(), false);
    chatR.get_chat(user1, user2);
    ASSERT_EQ(it->get_read(), true);


}

TEST_F(Chat_registry_test, get_chat_given_chat){
    Message message1("messaggio 1", user1.get_user_id(), user2.get_user_id(), 1);
    Message message2("messaggio 2", user2.get_user_id(), user1.get_user_id(), 2);
    Message message3("messaggio 3", user1.get_user_id(), user2.get_user_id(), 3);
    user1.send_message(message1, user2);
    user2.send_message(message2, user1);
    user1.send_message(message3, user2);
    Chat chat1(user1, user2);
    chats.push_back(chat1);
    Chat_registry chatR = Chat_registry(chats);
    ASSERT_EQ(chatR.get_chat(chat1).get_messages().size(), 3);
    ASSERT_TRUE(chatR.get_chat(chat1)==chat1);



}



