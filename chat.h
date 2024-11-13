//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_H
#define ELABORATO_CHAT_CHAT_H


#include <vector>
#include "user.h"

class Chat {
public:
    Chat( user &sender, user &receiver);
    Chat create_chat(const user & sender,const user& receiver);
    std::vector<Message> &get_messages();
    const user &get_sender() const {
        return sender;
    }
    const user &get_receiver() const {
        return receiver;
    }
    void print_chat();
    bool operator==(const Chat &rs) const {
        return sender==rs.sender&&receiver==rs.receiver;
    }







private:
    user sender;
    user receiver;
    std::vector<Message> chat_m;




};


#endif //ELABORATO_CHAT_CHAT_H
