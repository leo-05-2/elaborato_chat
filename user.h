//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_USER_H
#define ELABORATO_CHAT_USER_H
#include "message.h"


class user {
public:
    user(std::string &user_id, std::string &user_name, std::string &user_surname):
    user_id(user_id), user_name(user_name), user_surname(user_surname){};

    void send_message(std::string &message_text, user &receiver);
    const std::string get_user_id()const{
        return user_id;
    };
    std::string get_user_name(){
        return user_name;
    };
    std::string get_user_surname(){
        return user_surname;
    };
private:
    std::string user_id;
    std::string user_name;
    std::string user_surname;



};


#endif //ELABORATO_CHAT_USER_H
