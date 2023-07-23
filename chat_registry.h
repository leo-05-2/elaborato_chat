//
// Created by leoke on 21/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_REGISTRY_H
#define ELABORATO_CHAT_CHAT_REGISTRY_H


#include <list>
#include "chat.h"

class chat_registry {
public:
    void add_chat(Chat &chat);
    void remove_chat(Chat &chat);
    std::list<Chat> &get_chats(){
        return chats;
    }
    Chat &get_chat(user &sender, user &receiver);
    Chat &get_chat(Chat &chat);
    void print_chats();



private:
    std::list<Chat> chats;

};


#endif //ELABORATO_CHAT_CHAT_REGISTRY_H
