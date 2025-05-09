//
// Created by leoke on 21/07/2023.
//

#include "Chat_registry.h"
#include "algorithm"
#include <iostream>

void Chat_registry::remove_chat( Chat &chat, User &user) {
    if (chat.get_user1()==user || chat.get_user2()==user) {
        auto it = find(chats.begin(), chats.end(), chat);
        if (it != chats.end()) {
            chats.erase(it);
            cout << "Chat removed" << endl;
        } else {
            cout << "Chat not found" << endl;
        }
    }
}
void Chat_registry::see_chat(User &user1, User &user2) {// user1 vuole vedere la chat con user 2
    auto ite = get_chat(user1, user2);
   if (ite!=nullptr) {
       for(auto it=ite->get_messages().begin();it!=ite->get_messages().end();it++){
           if (it->get_sender_id()==user2.get_user_id()){
               it->set_read();
           }
       }
       //print_chat_message(*ite);
   }
}
Chat *Chat_registry::get_chat( const User &user1, const User &user2) {
    Chat *ite=nullptr;
    for (auto it=chats.begin(); it!=chats.end(); it++) {
        if (it->get_user1()==user1 && it->get_user2()==user2 ||
            it->get_user1()==user2 && it->get_user2()==user1) {
            ite = &(*it);
            break;;
            }
    }
    return ite;
}


void  Chat_registry::print_chats_list( const User& user1) const {
    int count=0;
    for(auto it=chats.begin();it!=chats.end();it++){
        cout<<"Chat with " ;

        if (it->get_user1()==user1) {
            cout<<it->get_user2().get_user_name()<<""<<it->get_user2().get_user_surname()<<endl;
            it->get_last_recived_message(it->get_user2());
            cout<<endl;
            cout<<"Da leggere: "<<it->count_unread_messages(it->get_user2());
            cout<<endl;
            count++;
        }
        if (it->get_user2()==user1) {
            cout<<it->get_user1().get_user_name()<<""<<it->get_user1().get_user_surname()<<endl;
            it->get_last_recived_message(it->get_user1());
            cout<<endl;
            cout<<"Da leggere: "<<it->count_unread_messages(it->get_user1());
            cout<<endl;

            count++;
        }
    }
}
void Chat_registry::add_chat(const User &sender,const  User & receiver ) {
    auto it = get_chat(sender, receiver);
    if (it==nullptr) {
        cout << "adding chat" << endl;
        Chat new_chat (sender,receiver);
        chats.push_back(new_chat);
        cout << "Chat added" << endl;
    } else {
        cout << "Chat already exists" << endl;
    }
}
void Chat_registry::print_chat_message( Chat &chat) const {
    for (auto it = chat.get_messages().begin(); it != chat.get_messages().end(); it++) {
        cout << "Sender: " << it->get_sender_id() << endl;
        cout << "Receiver: " << it->get_receiver_id() << endl;
        cout << "Text: " << it->get_text() << endl;
        cout << "Time: " << it->get_time() << endl;
        cout << "Read: " << it->is_read() << endl;
        if (it->is_modified()) {
            cout << "Modified" << endl;
        }
    }
}


