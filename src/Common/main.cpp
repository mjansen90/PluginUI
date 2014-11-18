
#include "ptree_export.h"

#include <boost/property_tree/ptree.hpp>
#include <iostream>

void main(int argc, char **argv)
{
   std::cout << "Hey" << std::endl;


   boost::property_tree::ptree tree;

   tree.put("StringKey", "StringValue");
   tree.put("IntKey", 1337);
   tree.put("BoolKey", true);
   tree.put("DoubleKey", 343.117);

   assert(tree.get("StringKey", "") == "StringValue");
   assert(tree.get("IntKey", -1) == 1337);
   assert(tree.get("BoolKey", false));
   assert(tree.get("DoubleKey", 0.0) == 343.117);

   std::cout << TempClass().GetString(tree);

   bool breakHere = true;

   system("pause");
}