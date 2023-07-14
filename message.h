//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_MESSAGE_H
#define ELABORATO_CHAT_MESSAGE_H


#include <string>
#include <iostream>

class Message {
public:
    Message(const std::string &text, const std::string &sender_id, const  std::string &receiver_id):
    text(text), sender_id(sender_id), receiver_id(receiver_id){};


private:
    std::string text;
    std::string sender_id;
    std::string receiver_id;





};


#endif //ELABORATO_CHAT_MESSAGE_H
