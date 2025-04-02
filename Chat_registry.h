//
// Created by leoke on 21/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_REGISTRY_H
#define ELABORATO_CHAT_CHAT_REGISTRY_H


#include <list>
#include "Chat.h"

class Chat_registry {
public:
    Chat_registry(){}
    Chat_registry(std::list<Chat> &chats): chats(chats){}
    void add_chat(Chat &chat);
    void remove_chat( Chat &chat, User &sender, User &receiver);
    std::list<Chat> &get_chats(){
        return chats;
    }
    Chat& get_chat(User &sender, User &receiver);
    Chat &get_chat(Chat &chat);
    void print_chats_list() const;
    void add_chat(User &sender, User receiver );

private:
    std::list<Chat> chats;

};


#endif //ELABORATO_CHAT_CHAT_REGISTRY_H
