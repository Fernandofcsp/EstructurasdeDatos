 #ifndef SONGSLIST_H_INCLUDED
 #define SONGSLIST_H_INCLUDED

 #include "songs.h"

 class SongsCollection {
 private:
 Songs AllSongs[50];
 Songs DeletedSongs[50];
 int Last;
 int Deleted;
 public:

 class Exception : public std::exception {
 private:
 std::string msg;
 public:
 explicit Exception(const char* message) : msg(message) { }

 explicit Exception(const std::string& message) : msg(message) { }

 virtual ~Exception() throw () { }

 virtual const char* what() const throw() {
 return msg.c_str();
 }
 };
 int getlast();
 SongsCollection();
 bool isFull();
 bool isEmpty();
 bool isValidPos(const int&);
 void insertSong(const std::string&,const std::string&,const std::string&);
 void deleteSong(const int&);
 std::string recoverSong(std::string&);
 std::string firstSong();
 std::string lastSong();
 std::string prevSong(const int&);
 std::string nextSong(const int&);
 std::string seeAllSongs(const int&);
 void deleteAll();
 void firstprintf();
 };

 #endif // SONGSLIST_H_INCLUDED
