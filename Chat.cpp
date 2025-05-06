//
// Created by leoke on 14/07/2023.
//

#include "Chat.h"


Chat::Chat(User & u1, User &u2): user1(u1), user2(u2){


}


void Chat::modify_message(const std::string &text,Message &message,User & user1) {
    if (user1.get_user_id() == message.get_sender_id()) {
        message.set_modified();
        message.set_text(text);
    }
}
void Chat::get_last_recived_message( const User &sender) const{
    for (auto it = chat_m.end()--; it->is_read(); it--) {
        if (it->get_receiver_id() == sender.get_user_id() ) {
            std::cout << "messaggio trovato" << std::endl;
            std::cout << it->get_text() << std::endl;
        }
    }

}
const Message*  Chat::find_message( const std::string &text) const {
    const Message *message = nullptr;

    for (auto it = chat_m.begin(); it != chat_m.end(); it++) {
        if (it->get_text() == text) {
            std::cout << "messaggio trovato" << std::endl;
            message = &(*it);
            return message ;
        }
    }
    std::cout << "messaggio non trovato" << std::endl;
    return message;
}
int Chat::count_unread_messages(const  User &sender) const{ // messaggi ancora da leggere ricevuti
    int count = 0;
    for (auto it = chat_m.rbegin(); it != chat_m.rend(); ++it) {
        if (it->get_sender_id() == sender.get_user_id() && !(it->is_read())) {
            count++;
        }
        if (it->get_sender_id() == sender.get_user_id() && it->is_read()) {
            break;
        }

    }

    return count;
}

void Chat::send_message(const std::string &message_text, User &receiver, User &sender) {
    if (sender.get_user_id() != receiver.get_user_id()
        &&((sender.get_user_id() == user1.get_user_id() && receiver.get_user_id()== user2.get_user_id())
            || (sender.get_user_id() == user2.get_user_id() && receiver.get_user_id()== user1.get_user_id()))) {


        Message message(message_text, sender.get_user_id(), receiver.get_user_id());
        chat_m.push_back(message);
        }
}


