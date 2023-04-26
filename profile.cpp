//task A; "social" from genady's lab 11

#include <iostream>
#include "profile.h"

std:: string Profile:: getUsername(){ //"Profile:: " refers to the private class vars
  return username; //returns username
}

std:: string Profile:: getFullName(){
  return displayname; //returns name in the format: "displayname (@username)"
}

void Profile:: setDisplayName(std:: string dspn){ //change display name
  displayname = dspn; //set current display name to whatever is asked for in main
}

//constructor values for access to the private member vars above
Profile:: Profile(std:: string usrn, std:: string dspn){
  username = usrn;
  displayname = dspn;
}
Profile:: Profile(){
  username = "";
  displayname = "";
}

