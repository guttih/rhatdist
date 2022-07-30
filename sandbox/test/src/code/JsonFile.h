#ifndef JsonFile_H
#define JsonFile_H
#include <iostream>

template< typename T >
class JsonFile : public T
{
private:
    std::string _filename;

public:
    JsonFile()
    {
    };

    void setFilename( std::string filename )
    {
        _filename = filename;
    };

    std::string getFilename()
    {
        return _filename;
    }

    bool save( const char *filename = NULL )
    {
        std::string fName=filename ? filename : this->getFilename();
        FILE * fp;
        fp = fopen(  fName.c_str(), "w" );
        if( !fp )
            return false;
        int cnt = fprintf( fp, "%s ", this->toJsonString().c_str() );
        fclose( fp );
        return cnt > 0;
    }

    std::string fileToString( const char *fileName )
    {
        ifstream inFile;
        inFile.open( fileName ); //open the input file

        stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        return strStream.str();
    }

    bool load( const char *filename = NULL )
    {
        std::string fName=filename ? filename : this->getFilename();
        return this->setFromJson( this->fileToString( fName.c_str() ).c_str() );
    }

};

#endif
