//
// Created by leoke on 14/07/2023.
//

#ifndef ELABORATO_CHAT_MESSAGE_H
#define ELABORATO_CHAT_MESSAGE_H


#include <string>
#include <iostream>
#include "ctime"
#include "chrono"
using namespace std;

class Message {
public:
    Message(const std::string &text , const std::string &sender_id, const  std::string &receiver_id):
    text(text), sender_id(sender_id), receiver_id(receiver_id),read(false), modified(false)  {
        set_time();
    };
    Message(const std::string &text , const std::string &sender_id, const  std::string &receiver_id, const int &time):
    text(text), sender_id(sender_id), receiver_id(receiver_id), time(time), read(false),modified(false)  {
    };


    const std ::string& get_text()const{
        return text;
    };
    const std::string& get_sender_id()const{
        return sender_id;
    };
    const std::string& get_receiver_id()const{
        return receiver_id;
    };
    const  char* get_time()const{
        return ctime(&time);
    };
    void set_time(){
        time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    };

    bool is_read()const{
        return read;
    };
    void set_read(){
        read = true;
    };
    void set_read( bool read){
        this->read = read;
    };

    bool operator==(const Message &rs) const {
        return text == rs.text && sender_id == rs.sender_id && receiver_id == rs.receiver_id && time == rs.time;
    }
    void set_modified( bool set_modified) {
        modified = set_modified;
    }
    void set_modified() {
        modified = true;
    }
    bool is_modified() const {
        return modified;
    }
    void set_text(const std::string &text_modified) {
        text = text_modified;

    }
private:
    std::string text;
    std::string sender_id;
    std::string receiver_id;
    std::time_t time;
    bool read;
    bool modified;
};


#endif //ELABORATO_CHAT_MESSAGE_H
