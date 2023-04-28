#pragma once
#include <iostream>
#include "profile.h"

class Network {

//(1)-------------------------------------------------------------------
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array (ACCESSED FROM PROFILE CLASS): mapping integer ID -> Profile; "we cannot sign up more than this number of users(20)"

// Returns user ID (index in the 'profiles' array) by their username; otherwise returns -1 if username is not found
int findID (std:: string usrn);

bool following[MAX_USERS][MAX_USERS];  // friendship matrix: following[id1][id2] == true when id1 is following id2

//(2)-------------------------------------------------------------------
public:
  Network(); // Constructor, makes an empty network (numUsers = 0)

  bool addUser(std:: string usrn, std:: string dspn);/* adds new user with username and displayname ONLY IF 
(1)the new username usrn is a non-empty alphanumeric string, 
(2)there are no other users in the network with the same username, and
(3)the array profiles is not full

***RETURN TRUE: if the above conditions are met, the new user should be added to the array profiles 
***RETURN FALSE: don’t add the user becaus the operation failed.
*/

// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
 // return true if success (if both usernames exist), otherwise return false
 bool follow(std:: string usrn1, std::string usrn2);

// Print Dot file (graphical representation of the network)

 void printDot();

};

