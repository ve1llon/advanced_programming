#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>
#include <iomanip>

class Log{
public:

    enum Importance_level{
        LOG_NORMAL,
        LOG_REMARK,
        LOG_ERROR
    };


    static Log* Instance(){
        if (!instance)
            instance = new Log();
        return instance;
    }

    void message(Importance_level lvl, std::string msg){
        auto timestamp = std::chrono::system_clock::now();
        events.push_back({timestamp, {lvl, msg}});
    }

    std::string lvl_to_str(Importance_level lvl){
        switch (lvl){
            case LOG_NORMAL:
                return "LOG_NORMAL";
            case LOG_REMARK:
                return "LOG_REMARK";
            case LOG_ERROR:
                return "LOG_ERROR";
        }
    }

    void print(){
        size_t finish_index = events.size() >= N ? events.size() - N : 0;

        for (size_t i = events.size(); i > finish_index; --i){
            std::time_t time_c = std::chrono::system_clock::to_time_t(events[i-1].first);
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(events[i-1].first.time_since_epoch()) % 1000;

            std::cout << std::ctime(&time_c) << ms.count() << "ms " << std::endl;
            std::cout<< lvl_to_str(events[i-1].second.first) << ": " << events[i-1].second.second << std::endl;
            std::cout << std::endl;
        }
    }


    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

private:
    Log(){}

    size_t N = 10;
    static Log* instance;
    std::vector<std::pair<std::chrono::system_clock::time_point, std::pair<Importance_level, std::string>>> events;
};

Log* Log::instance = nullptr;

#endif // LOG_H
