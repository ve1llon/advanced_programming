#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <ios>

struct CheckpointName{
    std::string name;
};

struct CheckpointCoord{
    double latitude; //в диапазоне -90.0 … 90.0
    double longitude; //в диапазоне -180.0 … 180.0
};

struct CheckpointFine{
    float fine;
};

class Checkpoint{
public:
    CheckpointName name;
    CheckpointCoord coords;
    CheckpointFine fine;

    Checkpoint(CheckpointName mname, CheckpointCoord mcoords, CheckpointFine mfine = {-1.0}){
        name = mname;
        coords = mcoords;
        fine = mfine;
    }
};

class CheckpointsBuilder{
public:
    CheckpointsBuilder(){}

    virtual void AddCheckpoint(CheckpointName mname, CheckpointCoord mcoords, CheckpointFine mfine = {-1.0}) = 0;

    virtual void Print() = 0;

};

class Director{
public:

    Director(CheckpointsBuilder* mbuilder){
        builder = mbuilder;
    }

    void Add(std::vector<std::tuple<CheckpointName, CheckpointCoord, CheckpointFine>> data){
        for (auto i : data)
            builder->AddCheckpoint(std::get<0>(i), normal_coors(std::get<1>(i)), std::get<2>(i));
    }
    void Print(){
        builder->Print();
    }


private:
    CheckpointCoord normal_coors(CheckpointCoord coords){
        float latitude = coords.latitude;
        float longitude = coords.longitude;

        latitude = fmod(latitude + 180.0, 360.0) - 180.0; //прив широту к диапазону от -180 до 180
        longitude = fmod(longitude + 180.0, 360.0) - 180.0; //прив долготу к диапазону от -180 до 180
        latitude = std::max(-90.0f, std::min(90.0f, latitude));//огран широту к диапазону от -90 до 90
        return {latitude, longitude};
    }

    CheckpointsBuilder* builder = nullptr;
};

class TextPrint: public CheckpointsBuilder{
public:
    void AddCheckpoint(CheckpointName mname, CheckpointCoord mcoords, CheckpointFine mfine = {-1.0}) override {
        cps.push_back(Checkpoint(mname, mcoords, mfine));
    }

    void Print() override {
        for (size_t i = 0; i < cps.size(); i++){
            if (cps[i].fine.fine != -1)
                std::cout << i << ": '" << cps[i].name.name << "' ("
                          << cps[i].coords.latitude << "; " << cps[i].coords.longitude << ") " << cps[i].fine.fine << std::endl;
            else
                std::cout << i << ": '" << cps[i].name.name << "' ("
                          << cps[i].coords.latitude << "; " << cps[i].coords.longitude << ") " << "non-accounting_CU" << std::endl;
        }
    }

private:
    std::vector<Checkpoint> cps;
};

class CalculationPrint: public CheckpointsBuilder{
public:
    void AddCheckpoint(CheckpointName mname, CheckpointCoord mcoords, CheckpointFine mfine = {-1.0}) override {
        if (mfine.fine != -1.0) //примерно равно
            full_fine += mfine.fine;
    }

    void Print() override {
        std::cout << "full_fine = " << full_fine << std::endl;
    }

private:
    float full_fine = 0.0;
};

class TablePrint : public CheckpointsBuilder {
public:
    void AddCheckpoint(CheckpointName mname, CheckpointCoord mcoords, CheckpointFine mfine = {-1.0}) override {
        cps.push_back(Checkpoint(mname, mcoords, mfine));
    }

    void Print() override {
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "ID | Name       | Latitude   | Longitude  | Fine\n";
        std::cout << "-------------------------------------------------------------\n";
        for (size_t i = 0; i < cps.size(); i++) {
            std::cout << i << "  | " << std::setw(10) << cps[i].name.name << " | "
                      << std::setw(10) << cps[i].coords.latitude << " | "
                      << std::setw(10) << cps[i].coords.longitude << " | ";
            if (cps[i].fine.fine != -1)
                std::cout << std::setw(10) << cps[i].fine.fine << "\n";
            else
                std::cout << std::setw(10) << "non-accounting_CU" << "\n";
        }
        std::cout << "-------------------------------------------------------------\n";
    }

private:
    std::vector<Checkpoint> cps;
};

#endif // BUILDER_H
