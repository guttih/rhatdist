#include "appsettings.h"

AppSettings::AppSettings(std::string pathToJsonFile)
{
    _pathToFile = pathToJsonFile;

}

std::string AppSettings::getFilePath()
{
    return this->_pathToFile;
}
