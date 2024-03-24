#ifndef EX1_H
#define EX1_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Group;

class User{
public:
    User(std::string n_userid, std::string n_username, std::string n_addinf = ""){
        userid = n_userid;
        username = n_username;
        addinf = n_addinf;
    }

    std::string get_id(){
        return userid;
    }

    std::string get_name(){
        return username;
    }

    std::string get_addinf(){
        return addinf;
    }

    void set_group(Group* n_group){
        usergroup = n_group;
    }

    Group* get_group(){
        return usergroup;
    }

private:
    std::string userid = "";
    std::string username = "";
    std::string addinf = "";
    Group* usergroup = nullptr;
};


class Group{
public:
    Group(std::string n_groupid){
        groupid = n_groupid;
    }

    std::string get_id(){
        return groupid;
    }

    auto get_users(){
        return groupusers;
    }

    void set_user(User* n_user){
        groupusers[n_user->get_id()] = n_user;
        n_user->set_group(this);
    }

    void clear_user(std::string n_userid){
        groupusers.erase(n_userid);
    }

private:
    std::string groupid = "";
    std::unordered_map<std::string, User*> groupusers;
};


#endif // EX1_H
