#include <iostream>
#include "user.h"
#include "message.h"
#include "chat.h"
#include "chat_registry.h"


int main() {
    std::vector<user> users;
    user *selected_user = nullptr;
    chat_registry *cr = new chat_registry();

    int iter = 1;

    while (iter != 0) {
        cout << "1 aggiungi utente,2 manda un messaggio, 3 seleziona utente  ,4 mostra chat,"
                "5 cancella chat e messaggi,6 elenco chat,7 esci  " << endl;
        cin >> iter;

        switch (iter) {
            case 1: {
                string name;
                string surname;
                cout << "inserisci il nome dell'utente" << endl;
                cin >> name;
                cout << "inserisci il cognome dell'utente" << endl;
                cin >> surname;
                user u1(name + surname, name, surname);
                auto ite = find(users.begin(), users.end(), u1);
                if (ite != users.end()) {
                    cout << "utente già presente" << endl;

                } else {
                    users.push_back(u1);
                }
                break;

            }
            case 2: {
                if (selected_user == nullptr) {
                    cout << "nessun utente selezionato" << endl;
                    break;
                } else {
                    if (users.size() < 2) {
                        cout << "non ci sono abbastanza utenti" << endl;
                        break;
                    } else {
                        string text;
                        string name;
                        string surname;
                        cout << "utenti:" << endl;
                        for (int i = 0; i < users.size(); i++) {
                            cout << i << ") " << users[i].get_user_name() << " " << users[i].get_user_surname() << endl;
                        }
                        int count;
                        cout << "inserisci l'indice dell'utente a cui vuoi mandare un messaggio" << endl;
                        cin >> count;
                        if (count < users.size() && count >= 0) {
                            selected_user = &users[count];
                            cout << "utente selezionato" << endl;
                            cout << selected_user->get_user_name() << endl;
                            cout<< "  ";
                            cout << selected_user->get_user_surname() << endl;
                            cout << "inserisci il testo del messaggio" << endl;
                            cin.ignore();
                            getline(cin, text);
                            cout << "messaggio:" << text << endl;
                            auto it = find(users.begin(), users.end(),
                                           user(name + surname, name, surname));
                            if (it != users.end() && *it != *selected_user) {

                                bool a = selected_user->send_message(text, *it);
                                if (a) {
                                    cout << "messaggio inviato" << endl;


                                } else
                                    cout << "messaggio non inviato" << endl;
                                break;
                            } else {
                                if (*it == *selected_user) {
                                    cout << "non puoi mandare un messaggio a te stesso" << endl;

                                } else {
                                    cout << "utente non trovato" << endl;

                                }
                            }
                        }
                        /* cout << "inserisci il nome dell'utente a cui vuoi mandare il messaggio" << endl;
                        cin >> name;
                        cout << "inserisci il cognome dell'utente a cui vuoi mandare il messaggio" << endl;
                        cin >> surname; */


                    }
                    case 3: {
                        if (users.empty()) {
                            cout << "non ci sono utenti" << endl;
                            break;
                        } else {
                            cout << "utenti:" << endl;
                            for (int i = 0; i < users.size(); i++) {
                                cout << i << ") " << users[i].get_user_name() << " " << users[i].get_user_surname()
                                     << endl;
                            }
                            int count;
                            cout << "inserisci l'indice dell'utente che vuoi selezionare" << endl;
                            cin >> count;
                            if (count < users.size() && count >= 0) {
                                selected_user = &users[count];
                                cout << "utente selezionato" << endl;
                                cout << selected_user->get_user_name() << endl;

                            } else {
                                cout << "utente non trovato" << endl;
                            }
                            break;
                        }
                    }
                    case 4: {
                        if (selected_user == nullptr) {
                            cout << "nessun utente selezionato" << endl;
                            break;
                        }
                        cout << endl;
                        if (users.size() < 2) {
                            cout << "non ci sono abbastanza utenti" << endl;
                            break;
                        } else {
                            string name;
                            string surname;
                            cout << "inserisci il nome dell'utente di cui vuoi visualizzare la chat" << endl;
                            cin >> name;
                            cout << "inserisci il cognome dell'utente di cui vuoi visualizzare la chat" << endl;
                            cin >> surname;
                            if (name == selected_user->get_user_name() &&
                                surname == selected_user->get_user_surname()) {
                                cout << "non puoi selezionare te stesso" << endl;
                                break;
                            }
                            auto it = find(users.begin(), users.end(),
                                           user(name + surname, name, surname));
                            if (it != users.end()) {
                                cr->get_chat(*selected_user, *it).print_chat();
                            } else {
                                cout << "utente non trovato" << endl;
                            }

                            break;
                        }
                    }
                    case 5: {
                        if (selected_user == nullptr) {
                            cout << "nessun utente selezionato" << endl;
                            break;
                        } else {
                            if (users.size() < 2) {
                                cout << "non ci sono abbastanza utenti" << endl;
                                break;
                            } else {
                                string name;
                                string surname;
                                cout << "inserisci il nome dell'utente di cui vuoi cancellare la chat" << endl;
                                cin >> name;
                                cout << "inserisci il cognome dell'utente di cui vuoi cancellare la chat" << endl;
                                cin >> surname;
                                //list of chat to choose
                                auto it = find(users.begin(), users.end(),
                                               user(name + surname, name, surname));
                                if (it != users.end()) {

                                    auto ite = find(cr->get_chats().begin(), cr->get_chats().end(),
                                                    Chat(*selected_user, *it));
                                    if (ite == cr->get_chats().end()) {
                                        cout << "chat non presente" << endl;
                                    } else {
                                        cr->remove_chat(*ite);
                                        cout << "chat rimossa" << endl;
                                    }
                                }
                            }
                        }


                    }

                    case 6: {
                        if (cr->get_chats().empty())
                            cout << "non ci sono chat" << endl;
                        else
                            cr->print_chats_list();
                        break;
                    }
                    case 7: {
                        iter = 0;
                        break;
                    }
                    default: {
                        cout << "comando non valido" << endl;
                        break;
                    }


                }
            }
                delete cr;
                delete selected_user;


                return 0;
        }
    }
}