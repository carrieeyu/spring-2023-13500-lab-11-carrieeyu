#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

Profile p1("marco", "Marco");  
Profile p2("tarma1", "Tarma Roving");

Network nw;
Network nw2;

//task A
TEST_CASE("Profile 1"){
  CHECK(p1.getUsername() == "marco");
  CHECK(p1.getFullName() == "Marco (@marco)");
}

TEST_CASE("Profile 2"){
  CHECK(p2.getUsername() == "tarma1");
  CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("set display"){
  p1.setDisplayName("Marco Rossi"); //change p1's current Marco to Marco Rossi
  CHECK(p1.getFullName() == "Marco Rossi (@marco)");
}



//task B
TEST_CASE("adding users"){
  
  CHECK(nw.addUser("mario", "Mario") == 1);
  CHECK(nw.addUser("luigi", "Luigi") == 1);
  CHECK(nw.addUser("mario", "Mario2") == 0);
  CHECK(nw.addUser("mario 2", "Mario2") == 0);
  CHECK(nw.addUser("mario-2", "Mario2") == 0);

    for(int i = 2; i < 20; i++){
  CHECK(nw.addUser("mario" + std:: to_string(i), "Mario" + std:: to_string(i)) == 1);
    }

  CHECK(nw.addUser("yoshi", "Yoshi") == 0);
  
}



//task C; new class Network nw2
TEST_CASE("following users"){
  
  nw2.addUser("mario", "Mario");
  nw2.addUser("luigi", "Luigi");
  nw2.addUser("yoshi", "Yoshi");

  CHECK(nw2.follow("mario", "luigi") == 1); 
  CHECK(nw2.follow("mario", "yoshi") == 1); 
  CHECK(nw2.follow("luigi", "mario") == 1); 
  CHECK(nw2.follow("luigi", "yoshi") == 1); 
  CHECK(nw2.follow("yoshi", "mario") == 1); 
  CHECK(nw2.follow("yoshi", "luigi") == 1); 

  nw2.addUser("wario", "Wario");

  for(int i = 2; i < 6; i++) {
        std:: string usrn = "mario" + std:: to_string(i);
        std:: string dspn = "Mario " + std:: to_string(i);
        nw2.addUser(usrn, dspn);
        CHECK(nw2.follow(usrn, "mario") == 1);
    }

  CHECK(nw2.follow("mario2", "luigi") == 1);
  
}
