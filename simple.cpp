/* A simple compile test with some C++11 features */

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

int main( int argc, const char *argv[] ) {
  shared_ptr<stringstream> buf( new stringstream() );
  stringstream buf2;
  auto str = make_shared<string>( string( "Hello" ) );
  vector<string> words;
  words.push_back( str->c_str() );
  words.push_back( "from" );
  words.push_back( "a" );
  words.push_back( "simple" );
  words.push_back( "world." );
  for ( const auto& word: words ) {
    ( *buf ) << word << " ";
    buf2 << word << " ";
  }
  cout << buf->str() << endl;
  cout << buf2.str() << endl;
  return 0;
}
