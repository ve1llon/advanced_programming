#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Log {
public:

    enum Importance_level{
        LOG_NORMAL,
        LOG_REMARK,
        LOG_ERROR
    };


    static Log* Instance() {
        if (!instance)
            instance = new Log();
        return instance;
    }

    void message(Importance_level lvl, std::string msg) {
        std::time_t timestamp = std::time(nullptr);
        events.push_back({timestamp, {lvl, msg}});
    }

    std::string lvl_to_str(Importance_level lvl) {
        switch (lvl){
            case LOG_NORMAL:
                return "LOG_NORMAL";
            case LOG_REMARK:
                return "LOG_REMARK";
            case LOG_ERROR:
                return "LOG_ERROR";
        }
    }

    void print() {
        if (events.size() >= N)
            for (size_t i = 0; i < N; ++i){

                auto event = events.back();

                char time[90];
                std::tm* timeinfo = localtime(&event.first);
                strftime(time, sizeof(time), "%H:%M:%S", timeinfo);

                std::cout << time << " " << lvl_to_str(event.second.first) << ": " << event.second.second << std::endl;

                events.pop_back();
            }
    }

    Log(const Log&) = delete;
    Log& operator=(const Log&) = delete;

private:
    Log(){}

    size_t N = 10;
    static Log* instance;
    std::vector<std::pair<time_t, std::pair<Importance_level, std::string>>> events;
};

Log* Log::instance = nullptr;



#endif // LOG_H
