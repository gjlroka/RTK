/*
 * File automatically generated by
 * gengen 1.2 by Lorenzo Bettini
 * http://www.gnu.org/software/gengen
 */

#include "free_string.h"

void
free_string_gen_class::generate_free_string(ostream &stream, unsigned int indent)
{
  string indent_str (indent, ' ');
  indent = 0;

  if (has_string_type)
    {
      stream << "free_string_field (&(";
      generate_string (structure, stream, indent + indent_str.length ());
      stream << "->";
      generate_string (opt_var, stream, indent + indent_str.length ());
      stream << "_arg));";
      stream << "\n";
      stream << indent_str;
    }
  stream << "free_string_field (&(";
  generate_string (structure, stream, indent + indent_str.length ());
  stream << "->";
  generate_string (opt_var, stream, indent + indent_str.length ());
  stream << "_orig));";
  stream << "\n";
  stream << indent_str;
}
