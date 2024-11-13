//
// Created by leoke on 14/07/2023.
//

#include "chat.h"


Chat::Chat(user & u1, user &u2):sender(u1), receiver(u2){
  Chat:: create_chat(get_sender(),get_receiver());
}
Chat Chat::create_chat(const user & u1,const  user & u2) {
    auto u1_m=sender.get_messages();
    auto u2_m=receiver.get_messages();
    vector<Message> u1_chat;
    vector<Message> u2_chat;
    for(auto it=u1_m.begin();it!=u1_m.end();it++){
        if(it->get_sender_id()==u2.get_user_id()){
            u1_chat.push_back(*it);
        }
    }
    for(auto it=u2_m.begin();it!=u2_m.end();it++){
        if(it->get_sender_id()==u1.get_user_id()){
            u2_chat.push_back(*it);
        }
    }
    auto u1_it=u1_chat.begin();
    auto u2_it=u2_chat.begin();

    while(u1_it!= u1_chat.end()&&u2_it!=u2_chat.end()){

        if(u1_it->get_time()<u2_it->get_time()){
            chat_m.push_back(*u1_it);
            u1_it++;
        }
        else{
            chat_m.push_back(*u2_it);
            u2_it++;
        }
    }

    while(u2_it!=u2_chat.end()){
        chat_m.push_back(*u2_it);
        u2_it++;
    }


    while(u1_it!=u1_chat.end()) {
        chat_m.push_back(*u1_it);
        u1_it++;
    }

}

std::vector<Message> &Chat::get_messages() {
    return chat_m;
}
void Chat::print_chat() {
    for(auto it=chat_m.begin();it!=chat_m.end();it++){
        std::cout<<it->get_text()<<" "<<"sender:"<<it->get_sender_id()<<" "<<endl;
        cout<<endl;
        if(it->get_read()){
            cout<<"read"<<endl;
        }
        else{
            cout<<"not read"<<endl;
        }
    }
}


