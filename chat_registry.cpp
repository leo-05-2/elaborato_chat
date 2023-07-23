//
// Created by leoke on 21/07/2023.
//

#include "chat_registry.h"
#include "algorithm"
void chat_registry::add_chat(Chat &chat) {
    bool found=false;
    for(auto it=chats.begin();it!=chats.end();it++){
        if(*it==chat){
            found=true;
        }
    }
    if(!found){
        chats.push_back(chat);
    }
    else {
        cout<<"Chat already exists"<<endl;
    }
}

void chat_registry::remove_chat(Chat &chat) {
    chats.remove(chat);
}
Chat &chat_registry::get_chat(user &sender, user &receiver) {
    for(auto it=chats.begin();it!=chats.end();it++){
        if(it->get_sender()==sender&&it->get_receiver()==receiver){
            return *it;
        }
    }
    cout << "Chat not found. adding chat" << endl;
    Chat new_chat(sender, receiver);
    add_chat(new_chat);
    auto it = std::find(chats.begin(), chats.end(), new_chat);
    return *it;

}
Chat &chat_registry::get_chat(Chat &chat) {
    if(std::find(chats.begin() ,chats.end(),chat)!=chats.end()){
        return chat;
    }
    else{
        cout<<"Chat not found. adding chat"<<endl;
        add_chat(chat);
        auto it=std::find(chats.begin(),chats.end(),chat);
        return *it;
    }
}
void chat_registry::print_chats() {
    for(auto it=chats.begin();it!=chats.end();it++){
        it->print_chat();
    }
}
