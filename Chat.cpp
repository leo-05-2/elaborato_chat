//
// Created by leoke on 14/07/2023.
//

#include "Chat.h"


Chat::Chat(User & u1, User &u2): sender(u1), utente2(u2){
   create_chat(u1,u2);

}

std::vector<Message> &Chat::get_messages() {
    return chat_m;
}
void Chat::print_chat() {
    for(auto it=chat_m.begin();it!=chat_m.end();it++){
        cout<<it->get_text()<<" "<<"sender:"<<it->get_sender_id()<<" "<<endl;
        cout<<endl;

        if(it->is_read()){
            cout<<"read"<<endl;
        }
        else{
            cout<<"not read"<<endl;
        }
        cout<<"time:";
        it->get_time();
    }
}


