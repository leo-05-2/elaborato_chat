//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_USER_H
#define ELABORATO_CHAT_USER_H

#include <vector>
#include "message.h"


class user {
public:
    user(std::string &user_id, std::string &user_name, std::string &user_surname):
    user_id(user_id), user_name(user_name), user_surname(user_surname){};
    user( std::string &user_name, std::string &user_surname):user_id(user_name+user_surname),
    user_name(user_name), user_surname(user_surname){};

    explicit user(const std::string &id):user_id(id),user_name("default name"), user_surname("default cognome" ){};

    bool send_message(const std::string &message_text, user &receiver);
    const std::string & get_user_id()const{
        return user_id;
    };
    const std::string &get_user_name()const{
        return user_name;
    };
    const std::string &get_user_surname()const{
        return user_surname;
    };
    std::vector<Message> &get_messages(){
        return messages;
    }
    void add_message(Message &message){
        messages.push_back(message);
    }

    bool operator==(const user &rs) const {
        return user_id == rs.user_id&& user_name==rs.user_name&&user_surname==rs.user_surname;
    }
    void set_messages(const std::vector<Message> &mess){
        user::messages = mess;
    };
private:
    std::string user_id;
    std::string user_name;
    std::string user_surname;
    std::vector<Message> messages;



};


#endif //ELABORATO_CHAT_USER_H
