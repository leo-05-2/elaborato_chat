//
// Created by leoke on 14/07/2023.
//

#include "user.h"
#include "message.h"
bool user::send_message(const std::string &message_text, user &receiver) {
    if(receiver==*this||message_text.empty()) {
        return false;
    }
    else{
        Message message(message_text, this->user_id, receiver.get_user_id());
        receiver.add_message(message);
        return true;
    }
}

