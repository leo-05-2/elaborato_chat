//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_MESSAGE_H
#define ELABORATO_CHAT_MESSAGE_H


#include <string>
#include <iostream>
#include "ctime"
#include "chrono"

class Message {
public:
    Message(const std::string &text , const std::string &sender_id, const  std::string &receiver_id):
    text(text), sender_id(sender_id), receiver_id(receiver_id), time(std::time(nullptr)),read(false)  {};


     const std ::string& get_text()const{
        return text;
    };
    const std::string& get_sender_id()const{
        return sender_id;
    };
    const std::string& get_receiver_id()const{
        return receiver_id;
    };
    const std::time_t& get_time()const{
        return time;
    };
    void set_time(){
        time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    };
    bool get_read()const{
        return read;
    };
    void set_read(){
        read = true;
    };

private:
    std::string text;
    std::string sender_id;
    std::string receiver_id;
    std::time_t time;
    bool read;





};


#endif //ELABORATO_CHAT_MESSAGE_H
