#include <iostream>
#include "ex1.h"


void console_utility(){
    std::string command_name;
    std::unordered_map<std::string, User*> users;
    std::unordered_map<std::string, Group*> groups;

    while (true){
        std::cout << "Input command: " << std::endl;
        std::cin >> command_name;

        if (command_name == "setGroup"){
            std::string n_userid;
            std::string n_groupid;
            std::cin >> n_userid;
            std::cin >> n_groupid;

            for (auto i : users){
                if (i.first == n_userid)
                    for (auto j : groups)
                        if (j.first == n_groupid)
                            j.second->set_user(i.second);
            }
        }

        else if (command_name == "createUser"){
            std::string n_userid;
            std::string n_username;
            std::string n_addinf;
            std::cin >> n_userid;
            std::cin >> n_username;
            std::getline(std::cin, n_addinf, '\n');
            if (!n_addinf.empty())
                n_addinf.erase(0,1); //удаляю пробел в начале строки n_addinf

            User* user = new User(n_userid, n_username, n_addinf);
            users.insert({n_userid, user});
        }

        else if (command_name == "deleteUser"){
            std::string n_userid;
            std::cin >> n_userid;

            for (auto i : users){
                if (i.first == n_userid){
                    delete i.second;
                    users.erase(n_userid);
                    break;
                }
            }

        }

        else if (command_name == "allUsers"){
            for (auto i : users)
                std::cout << i.second->get_id() << ' ' << i.second->get_name() << ' ' << i.second->get_addinf() << std::endl;
        }

        else if (command_name == "getUser"){
            std::string n_userid;
            std::cin >> n_userid;
            for (auto i : users){
                if (i.first == n_userid)
                    std::cout << i.second->get_id() << ' ' << i.second->get_name() << ' ' << i.second->get_addinf() << std::endl;
            }
        }

        else if (command_name == "createGroup"){
            std::string n_groupid;
            std::cin >> n_groupid;
            Group* group = new Group(n_groupid);
            groups.insert({n_groupid, group});
        }

        else if (command_name == "deleteGroup"){
            std::string n_groupid;
            std::cin >> n_groupid;

            for (auto i : groups){
                if (i.first == n_groupid){
                    delete i.second;
                    groups.erase(n_groupid);
                    break;
                }
            }

        }

        else if (command_name == "allGroups"){
            for (auto i : groups){
                std::cout << "Group_id: " << i.second->get_id() << " Group_users:" << std::endl;
                auto n_groupusers = i.second->get_users();
                for (auto j : n_groupusers)
                    std::cout << j.second->get_id() << ' ' << j.second->get_name() << ' ' << j.second->get_addinf() << std::endl;
            }
        }

        else if (command_name == "getGroup"){
            std::string n_groupid;
            std::cin >> n_groupid;

            for (auto i : groups){
                if (i.second->get_id() == n_groupid){
                    std::cout << "Group_id: " << i.second->get_id() << " Group_users:" << std::endl;
                    auto n_groupusers = i.second->get_users();
                    for (auto j : n_groupusers)
                        std::cout << j.second->get_id() << ' ' << j.second->get_name() << ' ' << j.second->get_addinf() << std::endl;
                }
            }
        }

        else{
            std::cout << "process finished with 0" << std::endl;
            break;
        }
    }

}

int main()
{
    console_utility();
    return 0;
}
