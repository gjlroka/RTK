/*
 * File automatically generated by
 * gengen 1.2 by Lorenzo Bettini
 * http://www.gnu.org/software/gengen
 */

#include "file_save.h"

void
file_save_gen_class::generate_file_save(ostream &stream, unsigned int indent)
{
  string indent_str (indent, ' ');
  indent = 0;

  stream << "if (args_info->";
  generate_string (given, stream, indent + indent_str.length ());
  stream << ")";
  stream << "\n";
  stream << indent_str;
  stream << "  write_into_file(outfile, \"";
  generate_string (opt_name, stream, indent + indent_str.length ());
  stream << "\", ";
  if (( arg == "" ))
    {
      stream << "0, 0 ";
    }
  else
    {
      stream << "args_info->";
      generate_string (arg, stream, indent + indent_str.length ());
      stream << ", ";
      generate_string (values, stream, indent + indent_str.length ());
    }
  stream << ");";
  stream << "\n";
  stream << indent_str;
}
