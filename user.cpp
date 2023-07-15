//
// Created by leoke on 14/07/2023.
//

#include "user.h"
#include "message.h"
void user::send_message(const std::string &message_text, user &receiver) {
    Message message(message_text,get_user_id(), receiver.get_user_id());


}
