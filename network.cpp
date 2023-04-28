//tasks B and C; "social2" and "social3" from genady's lab 11

#include <iostream>
#include "profile.h"
#include "network.h"

int Network:: findID (std:: string usrn){

  for(int i = 0; i < MAX_USERS; i++){ //MAX_USERS is the limit of users that can sign up
    if(usrn == profiles[i].getUsername()){ //if current username matches the one that's from the profiles array
      return i; //returning the user ID that matches the username, from profiles array(0, 1, 2...)
    }
  }
  return -1; //loop stops if username isn't found
}



/* adds new user with username and displayname ONLY IF:
//(1) usrn has to be a non-empty alphanumeric string
//(2) no other usernames are the same; use findID
//(3) array profiles cannot be full

***RETURN TRUE: if the above conditions are met, the new user should be added to the array profiles 
***RETURN FALSE: don’t add the user because the operation failed.
  */
bool Network:: addUser(std:: string usrn, std:: string dspn){

  //(1)if the string is not alphanumeric, return false
  for(int i = 0 ; i < usrn.length(); i++){
    if(!isalnum(usrn[i])){
      return false;
    }
  }
  
  //(2)-1 means that the user was not found
  //if the user was found, then return false because it already exists
  if(findID(usrn) != -1){
    return false;
  }

  //(3)if the array profiles is full, then return false
  bool successfullyAdded;
  if(numUsers >= MAX_USERS){
    successfullyAdded = false;
  }
  else{
    profiles[numUsers] = Profile(usrn, dspn); //add the user to the profiles array
  numUsers++; //for each new user added, add 1
    successfullyAdded = true;
  }
  return successfullyAdded;


}

//task C
// Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
// return true if success (if both usernames exist), otherwise return false
bool Network:: follow(std:: string usrn1, std::string usrn2){

  int usrn1_ID = findID(usrn1); //index(ID num) from profiles array for usrn1
  int usrn2_ID = findID(usrn2); //index(ID num) from profiles array for usrn2

  if(usrn1_ID != -1 && usrn2_ID != -1){ //if both usernames exist,
    following[usrn1_ID][usrn2_ID] = true; // then find the id # of both usernames and make usrn1 follow usrn2
    return true;
  }
  return false;

}

//task C
// Print Dot file (graphical representation of the network)
void Network:: printDot(){
  std:: cout << "digraph {" << std:: endl;

  //prints all usernames that were added in @username format
  for(int i = 0; i < numUsers; i++){
    std:: cout << "\t@" << profiles[i].getUsername() << std:: endl; 
  }

  /*
  for(int i = 0; i < numUsers; i++){
    for(int j = 0; j < numUsers; j++){
      if(follow(profiles[i].getUsername(), profiles[j].getUsername()) == true){
        std:: cout << "\t@" << profiles[i].getUsername() << " -> " << "@" << profiles[j].getUsername() << std:: endl;
      }
    }
  }
  */
  
  //prints the users that are following other users in @username format
  for(int i = 0; i < numUsers; i++){
    for(int j = 0; j < numUsers; j++){
      if(following[i][j] == true)
        std:: cout << "\t@" << profiles[i].getUsername() << " -> " << "@" << profiles[j].getUsername() << std:: endl;
    }
  }
  std:: cout << "}" << std:: endl;

}


// Constructor, makes an empty network (numUsers = 0)
Network:: Network(){
  numUsers = 0;

  //add for task C
  //The constructor Network() should be modified, setting all elements of the matrix following to false, so in empty network no one is following anyone.
  for(int i = 0; i < MAX_USERS; i++){
    for(int j = 0; j < MAX_USERS; j++){
      following[i][j] = false; 
    }
  }

}
