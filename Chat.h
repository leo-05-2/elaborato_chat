//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_CHAT_H
#define ELABORATO_CHAT_CHAT_H


#include <vector>
#include "User.h"

class Chat {
public:
    Chat(User &sender, User &receiver);
    Chat(std::vector<Message> &message, User &sender, User &receiver):
    chat_m(message), user1(sender), user2(receiver){};
    Chat():user1(),user2("default2","default2"){};

    void send_message(const std::string &message_text, User &receiver, User &sender);
    int count_unread_messages(const  User &sender) const;

    const Message*  find_message( const std::string &text) const ;
    void get_last_recived_message( const User &sender) const;

    int get_tot_message_number() const {
        return chat_m.size();
    }


    void modify_message(const std::string &text,Message &message,User & user1);

    std::vector<Message> & get_messages() {
        return chat_m;
    }
    const User &get_user1() const {
        return user1;
    }
    const User &get_user2() const {
        return user2;
    }
    void print_chat();
    bool operator==(const Chat &rs) const {
        return user1==rs.user1&&user2==rs.user2;
    }
    void set_message(std::vector<Message> &message) {
        chat_m=message;

    }







private:
    User user1;
    User user2;
    std::vector<Message> chat_m;






};


#endif //ELABORATO_CHAT_CHAT_H
