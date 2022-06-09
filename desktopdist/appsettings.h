#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <iostream>

class AppSettings
{
private:
    std::string _pathToFile;
public:
    AppSettings(std::string pathToJsonFile);
    AppSettings();
    std::string getFilePath();
};

#endif // APPSETTINGS_H
