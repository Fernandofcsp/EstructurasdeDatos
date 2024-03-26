 #ifndef SONGS_H_INCLUDED
 #define SONGS_H_INCLUDED

 #include <string>

 class Songs {
 private:
 std::string SongName;
 std::string SongAutor;
 std::string Ranking;
 public:
 Songs();
 std::string getSongName();
 std::string getSongAutor();
 std::string getRanking();
 void setSongName(const std::string&);
 void setSongAutor(const std::string&);
 void setRanking(const std::string&);;
 std::string toString();
 };

 #endif // SONGS_H_INCLUDED
