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
        user4=User("user4", "user4", "user4");
        chat_list = {
            Chat(user1, user2),
            Chat(user1, user3),
        };
        chats= Chat_registry(chat_list);




    }
    virtual void TearDown() override {
        chats.get_chats().clear();
        chats.set_chat_list(chat_list);

    }

    User user1;
    User user2;
    User user3;
    User user4;
    Chat_registry chats;
    std::vector<Chat> chat_list;
};

TEST_F(Chat_registry_test,remove_chat) {
   auto chat = chats.get_chats()[0];
    chats.remove_chat(chat,user4);
    ASSERT_EQ(chat, chats.get_chats()[0]);
    chats.remove_chat(chat,user2);
    ASSERT_NE(chat, chats.get_chats()[0]);

}
TEST_F(Chat_registry_test,add_chat) {
    ASSERT_EQ(chats.get_chats().size(), 2);
    chats.add_chat(user2, user1);
    ASSERT_EQ(chats.get_chats().size(), 2);
    chats.add_chat(user1, user4);
    ASSERT_EQ(chats.get_chats().size(), 3);
    ASSERT_EQ(chats.get_chats()[2].get_user1().get_user_id(), user1.get_user_id());
    ASSERT_EQ(chats.get_chats()[2].get_user2().get_user_id(), user4.get_user_id());

}

TEST_F(Chat_registry_test, get_chat) {
    ASSERT_EQ(chats.get_chats().size(), 2);
    chats.add_chat(user2, user1);
    ASSERT_EQ(chats.get_chats().size(), 2);

}

TEST_F(Chat_registry_test, see_chat) {

    auto chat = chats.get_chat(user1, user2);
    ASSERT_EQ(chat->get_messages().size(), 0);
    chat->send_message("messaggio 1", user1, user2);
    chats.see_chat(user2, user1); // in questo chaso u2 chiede di vedere la chat con u1
    ASSERT_EQ(chat->get_messages().size(), 1);
    ASSERT_EQ(chat->get_messages()[0].get_text(), "messaggio 1");
    ASSERT_EQ(chat->get_messages()[0].is_read(),false);
    ASSERT_EQ(chat->get_messages()[0].is_modified(),false);
    chat->send_message("messaggio 2", user2, user1);
    chats.see_chat(user1, user2);
    ASSERT_EQ(chat->get_messages()[0].is_read(), true);
    ASSERT_EQ(chat->get_messages()[1].is_read(), false);
    ASSERT_EQ(chat->get_messages()[0].is_modified(), false);
    ASSERT_EQ(chat->get_messages()[1].is_modified(), false);
    chats.see_chat(user2, user1);
    ASSERT_EQ(chat->get_messages()[0].is_read(), true);
    ASSERT_EQ(chat->get_messages()[1].is_read(), true);
    ASSERT_EQ(chat->get_messages()[0].is_modified(), false);
    ASSERT_EQ(chat->get_messages()[1].is_modified(), false);
    chat->modify_message("messaggio modificato", chat->get_messages()[0], user1); // user 1 non può modificare un messaggio non suo
    ASSERT_EQ(chat->get_messages()[0].is_read(), true);
    ASSERT_EQ(chat->get_messages()[0].is_modified(), false);
    chat->modify_message("messaggio modificato", chat->get_messages()[0], user2);
    ASSERT_EQ(chat->get_messages()[0].is_read(), true);
    ASSERT_EQ(chat->get_messages()[0].is_modified(), true);





}



