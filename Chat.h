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
    Chat create_chat(const User & sender, const User& receiver);
    std::vector<Message> &get_messages();
    const User &get_sender() const {
        return sender;
    }
    const User &get_receiver() const {
        return receiver;
    }
    void print_chat();
    bool operator==(const Chat &rs) const {
        return sender==rs.sender&&receiver==rs.receiver;
    }







private:
    User sender;
    User receiver;
    std::vector<Message> chat_m;




};


#endif //ELABORATO_CHAT_CHAT_H
