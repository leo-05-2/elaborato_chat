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
         chat= Chat(chat_m, sender, receiver);

    }
    void TearDown() override {
        for (auto ite= chat.get_messages().begin(); ite != chat.get_messages().end(); ite++) {
            ite->set_read( false);
            ite->set_modified(false);
            chat.set_message(chat_m);
        }

       ;
    }

    User sender;
    User receiver;
    std::vector<Message> chat_m;
    Chat chat;
};

TEST_F(Chat_test, send_message) {
    Message message("messaggio 1", sender.get_user_id(), receiver.get_user_id(), 5);
    chat.send_message(message.get_text(), receiver,sender);
    ASSERT_EQ(chat.get_messages().back().get_sender_id(), message.get_sender_id());
    ASSERT_EQ(chat.get_messages().back().get_receiver_id(), message.get_receiver_id());
    ASSERT_EQ(chat.get_messages().back().get_text(), message.get_text());
    ASSERT_EQ(chat.get_messages().back().is_read(), message.is_read());
    ASSERT_EQ(chat.get_messages().back().is_modified(), message.is_modified());

    EXPECT_EQ(chat.get_messages().back().get_text(), message.get_text());
    ASSERT_EQ(chat.get_messages().size(), 5);
    chat.send_message(message.get_text(), sender, sender);
    ASSERT_EQ(chat.get_messages().size(), 5);
    User user3= User("user3", "user3");
    chat.send_message(message.get_text(), user3, sender);
    ASSERT_EQ(chat.get_messages().size(), 5);


}
TEST_F(Chat_test, count_unread_messages) { // messaggi ancora da leggere ricevuti
    ASSERT_EQ(chat.count_unread_messages(sender),2);
    chat.get_messages()[0].set_read();
    ASSERT_EQ(chat.count_unread_messages(sender),1);
    ASSERT_EQ(chat.count_unread_messages(receiver),2);
}
TEST_F(Chat_test, find_message) {
    std::string text = "messaggio 1";
    const Message *message = chat.find_message(text);
    ASSERT_EQ(message->get_text(), "messaggio 1");
    ASSERT_EQ(message->get_sender_id(), sender.get_user_id());
    ASSERT_EQ(message->get_receiver_id(), receiver.get_user_id());

    ASSERT_EQ(message->is_read(), false);
    ASSERT_EQ(message->is_modified(), false);
    auto message2 = chat.find_message("ciao");
    ASSERT_EQ(message2, nullptr);
}
TEST_F (Chat_test, get_last_recived_message) {
    chat.get_last_recived_message(sender);
    ASSERT_EQ(chat.get_messages().back().get_text(), "messaggio 4");

}
TEST_F (Chat_test, get_tot_message_number) {
    ASSERT_EQ(chat.get_tot_message_number(), 4);
}
TEST_F(Chat_test, modify_message) {
    auto message = &chat.get_messages()[0];
    chat.modify_message("messaggio modificato", *message, sender);
    ASSERT_EQ(chat.get_messages()[0].get_text(), "messaggio modificato");
    ASSERT_EQ(chat.get_messages()[0].is_modified(), true);
    auto message2 = chat.get_messages()[1];
    chat.modify_message("messaggio modificato", message2, sender);
    ASSERT_EQ(chat.get_messages()[1].get_text(), "messaggio 2");
    ASSERT_EQ(chat.get_messages()[1].is_modified(), false);


}


//
