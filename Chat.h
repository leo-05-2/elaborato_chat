//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_H
#define ELABORATO_CHAT_CHAT_H


#include <vector>
#include "User.h"

class Chat {
public:
    Chat(User &sender, User &receiver);

    void send_message(const std::string &message_text, User &receiver) {
        Message message(message_text, sender.get_user_id(), receiver.get_user_id());
        chat_m.push_back(message);
    }
    void count_unread_messages( User sender) { // messaggi ancora da leggere ricevuti
        int count = 0;
        for (auto it = chat_m.begin(); it != chat_m.end(); it++) {
            if (it->get_receiver_id() == sender.get_user_id() && !it->is_read()) {
                count++;
            }
        }
        std::cout << "messaggi non letti: " << count << std::endl;
    }

    Message find_message(const std::string &text) {
        for (auto it = chat_m.begin(); it != chat_m.end(); it++) {
            if (it->get_text() == text) {
                std::cout << "messaggio trovato" << std::endl;
                return *it ;
            }
        }
        std::cout << "messaggio non trovato" << std::endl;
    }
    Message get_last_recived_message( User sender) {
        auto it = chat_m.end();
        for (auto it = chat_m.end(); it->is_read(); it--) {
            if (it->get_receiver_id() == sender.get_user_id() && !it->is_read()) {
                std::cout << "messaggio trovato" << std::endl;
                return *it;
            }


        }
    }
    std::vector<Message> &get_messages();
    const User &get_sender() const {
        return sender;
    }
    const User &get_receiver() const {
        return utente2;
    }
    void print_chat();
    bool operator==(const Chat &rs) const {
        return sender==rs.sender&&utente2==rs.utente2;
    }








private:
    User sender;
    User utente2;
    std::vector<Message> chat_m;






};


#endif //ELABORATO_CHAT_CHAT_H
