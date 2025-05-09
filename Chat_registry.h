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
    explicit Chat_registry(std::vector<Chat> &chats): chats(chats){}
    void remove_chat( Chat &chat, User &user);
    std::vector<Chat> &get_chats(){
        return chats;
    }
    Chat* get_chat( const User &sender, const User &receiver);
    void print_chats_list(const User &user) const;
    void print_chat_message( Chat &chat) const;
    void add_chat( const User &sender, const User &receiver );
    void set_chat_list(std::vector<Chat> &chats){
        this->chats=chats;
    }
    void see_chat(User &user1, User &user2);
private:
    std::vector<Chat> chats;
};


#endif //ELABORATO_CHAT_CHAT_REGISTRY_H
