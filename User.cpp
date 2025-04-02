//
// Created by leoke on 14/07/2023.
//

#include "User.h"
#include "Message.h"
bool User::send_message(const std::string &message_text, User &receiver) {
    if(receiver==*this||message_text.empty()) {
        return false;
    }
    else{
        Message message(message_text, this->user_id, receiver.get_user_id());
        receiver.add_message(message);
        return true;
    }
}
bool User::send_message(const std::string &message_text, User &receiver, std::time_t time) {
    if(receiver==*this||message_text.empty()) {
        return false;
    }
    else{
        Message message(message_text, this->user_id, receiver.get_user_id(), time);
        receiver.add_message(message);
        return true;
    }
}
bool User::send_message(Message &message, User &receiver) {
    if(receiver==*this||message.get_text().empty()) {

        return false;
    }
    else{
        receiver.add_message(message);
        return true;
    }
}
