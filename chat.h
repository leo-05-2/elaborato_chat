//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_H
#define ELABORATO_CHAT_CHAT_H


#include <vector>
#include "user.h"

class Chat {
public:
    Chat();
    std::vector<Message> &get_messages();



private:
    user sender;
    user receiver;
    std::vector<Message> messages;




};


#endif //ELABORATO_CHAT_CHAT_H
