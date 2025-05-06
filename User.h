//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_USER_H
#define ELABORATO_CHAT_USER_H

#include <vector>
#include "Message.h"


class User {
public:
    User(const std::string &user_id, const  std::string &user_name , const std::string &user_surname):
    user_id(user_id), user_name(user_name), user_surname(user_surname){}


    User(const std::string &user_name, const std::string &user_surname): user_id(user_name + user_surname),
                                                                         user_name(user_name), user_surname(user_surname){};

    User(): user_id("default id"), user_name("default"), user_surname("default"){};


    const std::string & get_user_id()const{
        return user_id;
    };
    const std::string &get_user_name()const{
        return user_name;
    };
    const std::string &get_user_surname()const{
        return user_surname;
    };

    bool operator==(const User &rs) const {
        return user_id == rs.user_id&& user_name==rs.user_name&&user_surname==rs.user_surname;
    }

private:
    std::string user_id;
    std::string user_name;
    std::string user_surname;



};


#endif //ELABORATO_CHAT_USER_H
