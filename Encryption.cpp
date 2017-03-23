
#include <iostream>

#include "Message.h"

using namespace std;

int main()
 {
	// create a message object with the content of Encrypted.txt
  Message m ("Encrypted.txt");

  if (m.isEmpty())
  {
	  std::cout << "Could not read message";
	  return EXIT_FAILURE;
  }
  std::cout << "Original message: " << std::endl;
  m.dump();
  std::cout << std::endl << std::endl;
  m.decode();
  m.fixCapitalization();
  std::cout << "Decoded message: " << std::endl;
  m.dump();
 std::cout << std::endl << std::endl;

  return EXIT_SUCCESS;
 }
