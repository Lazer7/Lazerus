#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <SHA/sha2.h>
class FileManager
{
public:
    template <typename data> static void write(std::string filename, data o){
        std::string dataString((char*) &o); // Convert data object into string
        std::string identifier = Sha2::hash256_hex_string(dataString); // Hash the object string
        size_t identifierSize  = identifier.length(); // Get length of hash
        std::ofstream out(filename,std::ios::binary); // Make file
        out.write((char*) &identifierSize,sizeof(size_t)); // Write size of hash
        out.write(identifier.c_str(),identifierSize); // Write hash
        out.write((char*) &o, sizeof(o)); // Write object data
        out.close(); // Close the file
    };

    template <typename data> static data read(std::string filename){
        data result; // Create default object
        std::ifstream in(filename,std::ios::binary); // Get files
        if(in.is_open()){ // Check if file is open
            size_t identifierSize; // Get size
            in.read((char*)&identifierSize,sizeof(size_t));
            char* identifier = new char[identifierSize+1];
            in.read(identifier, identifierSize);
            in.read((char*) &result, sizeof(result));
            identifier[identifierSize] ='\0';
            std::string identifier1(identifier);
            std::string dataString((char*) &result);
            std::string identifier2 = Sha2::hash256_hex_string(dataString);
            in.close();
            if(identifier1.compare(identifier2)==0){
                return result;
            }
        }
        throw "Corrupted File Found";
    };

};
#endif // FILEMANAGER_H
