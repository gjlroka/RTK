/*
 * File automatically generated by
 * gengen 1.2 by Lorenzo Bettini
 * http://www.gnu.org/software/gengen
 */

#ifndef FREE_LIST_GEN_CLASS_H
#define FREE_LIST_GEN_CLASS_H

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class free_list_gen_class
{
 protected:
  string list_name;
  bool string_list;

 public:
  free_list_gen_class() :
    string_list (false)
  {
  }

  free_list_gen_class(const string &_list_name, bool _string_list) :
    list_name (_list_name), string_list (_string_list)
  {
  }

  static void
  generate_string(const string &s, ostream &stream, unsigned int indent)
  {
    if (!indent || s.find('\n') == string::npos)
      {
        stream << s;
        return;
      }

    string::size_type pos;
    string::size_type start = 0;
    string ind (indent, ' ');
    while ( (pos=s.find('\n', start)) != string::npos)
      {
        stream << s.substr (start, (pos+1)-start);
        start = pos+1;
        if (start+1 <= s.size ())
          stream << ind;
      }
    if (start+1 <= s.size ())
      stream << s.substr (start);
  }

  void set_list_name(const string &_list_name)
  {
    list_name = _list_name;
  }

  void set_string_list(bool _string_list)
  {
    string_list = _string_list;
  }

  void generate_free_list(ostream &stream, unsigned int indent = 0);

};

#endif // FREE_LIST_GEN_CLASS_H
