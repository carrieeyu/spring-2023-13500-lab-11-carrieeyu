#include <iostream>
#include "profile.h"
#include "network.h"

int main() {

  //--------------------------TASK A--------------------------------
  std:: cout << "(Task A)" << std:: endl;
  
  Profile p1("marco", "Marco");    
  std:: cout << p1.getUsername() << std:: endl; // marco
  std:: cout << p1.getFullName() << "\n" << std:: endl; // Marco (@marco)

  Profile p2("tarma1", "Tarma Roving");    
  std:: cout << p2.getUsername() << std:: endl; // tarma1
  std:: cout << p2.getFullName() << "\n" << std:: endl; // Tarma Roving (@tarma1)

  p1.setDisplayName("Marco Rossi"); 
  std:: cout << p1.getUsername() << std:: endl; // marco
  std:: cout << p1.getFullName() << std:: endl; // Marco Rossi (@marco)

  //--------------------------TASK B--------------------------------
  std:: cout << "---------------------------------------------------" << std:: endl;
  
  std:: cout << "(Task B)" << std:: endl;
  
  Network nw;

  std:: cout << nw.addUser("mario", "Mario") << std:: endl;     // true (1)
  std:: cout << nw.addUser("luigi", "Luigi") << std:: endl;     // true (1)

  std:: cout << nw.addUser("mario", "Mario2") << std:: endl;    // false (0)
  std:: cout << nw.addUser("mario 2", "Mario2") << std:: endl;  // false (0)
  std:: cout << nw.addUser("mario-2", "Mario2") << std:: endl;  // false (0)

  std:: cout << "---" << std:: endl;
  
  for(int i = 2; i < 20; i++)
      std:: cout << nw.addUser("mario" + std:: to_string(i), 
                 "Mario" + std:: to_string(i)) << std:: endl;   // true (1)

  std:: cout << "---" << std:: endl;

  std:: cout << nw.addUser("yoshi", "Yoshi") << std:: endl;     // false (0)
  
  //--------------------------TASK C--------------------------------
    std:: cout << "---------------------------------------------------" << std:: endl;
  
  std:: cout << "(Task C)" << std:: endl;
  
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario"); //add a user who does not follow others
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std:: string usrn = "mario" + std:: to_string(i);
        std:: string dspn = "Mario " + std:: to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    
    nw.follow("mario2", "luigi"); //additionally, make @mario2 follow @luigi

    nw.printDot();
  
}

