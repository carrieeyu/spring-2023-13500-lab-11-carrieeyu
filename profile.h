#pragma once
#include <iostream>

class Profile {

//can be used only internally by the class itself; cannot be directly modified or accessed from outside
private:
    std:: string username;
    std:: string displayname;

//can be called by other classes
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(std:: string usrn, std:: string dspn);

    // Default Profile constructor (username="", displayname="")
    Profile();

    //functions
    std:: string getUsername(); //Return username
    std:: string getFullName(); // Return name in the format: "displayname (@username)"
    void setDisplayName(std:: string dspn); //Change display name

};
