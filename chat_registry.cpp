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

void chat_registry::remove_chat( const Chat &chat) {
    auto u1=chat.get_sender();
    auto u2=chat.get_receiver();
    auto u1_m=u1.get_messages();
    auto u2_m=u2.get_messages();
    for(auto it=u1_m.begin();it!=u1_m.end();){
        if(it->get_sender_id()==u2.get_user_id()){
            u1_m.erase(it);
        }
        else{
            it++;
        }
    }
    for(auto it=u2_m.begin();it!=u2_m.end();){
        if(it->get_sender_id()==u1.get_user_id()){
            u2_m.erase(it);
        }
        else{
            it++;
        }
    }
    u1.set_messages(u1_m);
    u2.set_messages(u2_m);
    chats.remove(chat);
}
Chat& chat_registry::get_chat(user &sender, user &receiver) {
    Chat chat(sender,receiver);
    auto ite=std::find(chats.begin() ,chats.end(),chat);
    if (ite==chats.end()){
        cout<<"Chat not found. adding chat"<<endl;
        add_chat(chat);
        ite=std::find(chats.begin(),chats.end(),chat);
    }
    for(auto it=ite->get_messages().begin();it!=ite->get_messages().end();it++){
        if (it->get_sender_id()==receiver.get_user_id()){
            it->set_read();
        }
    }
    return *ite;




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
void  chat_registry::print_chats_list() const {
    int count=0;
    for(auto it=chats.begin();it!=chats.end();it++){
        cout<<"Chat between " ;
        cout<<count<<")"<<it->get_sender().get_user_name()<<""<<it->get_sender().get_user_surname()
        <<" and "<<it->get_receiver().get_user_name()<<""<<it->get_receiver().get_user_surname()<<endl;
    }
}
void chat_registry::add_chat(user &sender,user receiver ) {
    bool found=false;
    Chat new_chat(sender,receiver);
    auto iter=chats.begin();
    for(auto it=chats.begin();it!=chats.end();it++){
        if(it->get_sender()==sender&&it->get_receiver()==receiver||
           it->get_sender()==receiver&&it->get_receiver()==sender){
            found=true;
            iter=it;
        }
    }
    if(!found){
        chats.push_back(new_chat);
    }
    else {
        cout<<"Chat already exists"<<endl;
        chats.erase(iter);
        chats.push_back(new_chat);

    }


}
