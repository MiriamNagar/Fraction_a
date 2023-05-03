
#include "doctest.h"
#include <stdexcept>
#include <iostream>
using namespace std;


#include "sources/Fraction.hpp"
using namespace ariel;


TEST_CASE("Incorrect values for Fraction constructor") {
    Fraction(1,0);
}

TEST_CASE("addition") {
    Fraction f1(1,4);
    Fraction f2(1,2);
    Fraction f3(0,1);
    Fraction f4(-1,4);

    CHECK(f1+f1 == f2); //1/4 + 1/4 = 1/2
    CHECK(f1+f3 == f1); //1/4 + 0 = 1/4
    CHECK(f2+f4 == f1); //1/2 + (-1/4) = 1/4

    //
    float f5 = 0.5;
    float f6 = 0;
    float f7 = 0.25;

    CHECK(f1+f7 == f2); //1/4 + 0.25 = 1/2
    CHECK(f1+f6 == f1); //1/4 + 0 = 1/4
    CHECK(f5+f4 == f1); //0.5 + (-1/4) = 1/4
}

TEST_CASE("subtraction") {
    Fraction f1(1,4);
    Fraction f2(1,2);
    Fraction f3(0,1);
    Fraction f4(-1,4);

    CHECK(f2-f1 == f1); //1/2 - 1/4 = 1/4
    CHECK(f1-f2 == f2); //1/4 - (-1/4) = 1/2
    CHECK(f2-f3 == f2); //1/2 - 0 = 1/2

    float f5= 0.5;
    float f6= -0.25;

    CHECK(f5-f1 == f1); //0.5 - 1/4 = 1/4
    CHECK(f1-f6 == f2); //1/4 - (-0.25) = 1/2
    CHECK(f5-f3 == f2); //0.5 - 0 = 1/2
}

TEST_CASE("multiplication") {
    Fraction f1(1,4);
    Fraction f2(1,2);
    Fraction f3(0,1);
    Fraction f4(-1,3);
    Fraction f5(1,8);
    Fraction f6(-1,12);
    Fraction f7(1,9);

    CHECK(f1*f2 == f5); //1/4 * 1/2 = 1/8
    CHECK(f1*f3 == f3); //1/4 * 0 = 0
    CHECK(f1*f4 == f6); //1/4 * -1/3 = -1/12
    CHECK(f4*f4 == f7); //-1/3 * (-1/3) = 1/9

    float f8 = 0.5;
    float f9 = 0.25;
    float f11 = -0.25;
    Fraction f10(1, 16);
    Fraction f12(-1,4);

    CHECK(f1*f8 == f5); //1/4 * 0.5 = 1/8
    CHECK(f9*f3 == f3); //0.25 * 0 = 0
    CHECK(f9*f4 == f6); //0.25 * -1/3 = -1/12
    CHECK(f12*f11 == f10); //-1/4 * (-0.25) = 1/16

}

TEST_CASE("division") {
    Fraction f1(1,4);
    Fraction f2(1,2);
    Fraction f3(0,1);
    Fraction f4(-1,3);
    Fraction f5(1,8);
    Fraction f6(-3,4);
    Fraction f7(1,1);

    CHECK(f1/f2 == f2); //1/4 / 1/2 = 1/2
    CHECK_THROWS(f1/f3); //1/4 / 0 -> exception
    CHECK(f1/f4 == f6); //1/4 / -1/3 = -1/12
    CHECK(f4/f4 == f7); //-1/3 / (-1/3) = 1

    float f8 = 0.5;
    float f9 = -0.25;
    float f10 = 0.25;
    Fraction f11(-1,4);

    CHECK(f1/f8 == f2); //1/4 / 0.5 = 1/2
    CHECK_THROWS(f10/f3); //0.25 / 0 -> exception
    CHECK(f10/f4 == f6); //0.25 / -1/3 = -1/12
    CHECK(f9/f11 == f7); //-0.25 / (-1/4) = 1
}

TEST_CASE("== operator") {
    Fraction f1(2,4);
    Fraction f2(1,2);
    Fraction f3(0,1);

    CHECK(f1 == f2); //2/4 == 1/2 -> true
    CHECK(!(f1 == f3)); // 2/4 == 0 -> false

    float f4 = 0.5;

    CHECK(f1 == f4); //2/4 == 0.5 -> true
    CHECK(!(f4 == f3)); // 0.5 == 0 -> false
}

TEST_CASE(">, <, >=, <= operators") {
    Fraction f1(1,4);
    Fraction f2(1,2);
    Fraction f3(2,4);
    Fraction f4(-1,3);
    Fraction f5(-1,10);
    // Fraction f6(-3,4);
    // Fraction f7(1,1);

    CHECK(f1<f2); //1/4 < 1/2 -> true
    CHECK(!(f1<f4)); //1/4 < -1/3 -> flase
    CHECK(!(f2<f3)); //1/2 < 2/4 ->false
    CHECK(f4<f5); //-1/3 < (-1/10) ->true

    CHECK(!(f1>f2)); //1/4 > 1/2 -> false
    CHECK(f1>f4); //1/4 > -1/3 -> true
    CHECK(!(f2>f3)); //1/2 > 2/4 ->false
    CHECK(!(f4>f5)); //-1/3 > (-1/10) ->false

    CHECK(f1<=f2); //1/4 <= 1/2 -> true
    CHECK(f2<=f3); //1/2 <= 2/4 ->true
    CHECK(!(f3<=f1)); //2/4 <= 1/4 ->false

    CHECK(!(f1>=f2)); //1/4 >= 1/2 -> false
    CHECK(f2>=f3); //1/2 >= 2/4 ->true

    float f6 = 0.25;
    float f7 = 0.5;
    float f8 = -0.1;
    Fraction f9(-1,2);
    
    CHECK(f6<f2); //0.25 < 1/2 -> true
    CHECK(!(f6<f4)); //0.25 < -1/3 -> flase
    CHECK(!(f2<f7)); //1/2 < 0.5 ->false
    CHECK(f9<f8); //-1/2 < (-0.1) ->true

    CHECK(!(f6>f2)); //0.25 > 1/2 -> false
    CHECK(f6>f4); //0.25 > -1/3 -> true
    CHECK(f2>f7); //1/2 > 0.5 ->true
    CHECK(!(f9>f8)); //-1/2 > -0.1 -> false

    CHECK(f6<=f2); //0.25 <= 1/2 -> true
    CHECK(f2<=f7); //1/2 <= 0.5 ->true

    CHECK(!(f6>=f2)); //0.25 >= 1/2 -> false
    CHECK(f2>=f7); //1/2 >= 0.5 ->true
}

TEST_CASE("prefix & postfix addition operators") {
    Fraction f1(1,2);
    Fraction f2(-1,3);
    Fraction f3(3,2);
    Fraction f4(2,3);

    CHECK((f1++) == f1); // 1/2++ = 1/2
    CHECK((f2++) == f2); // -1/3++ = 1/3
    CHECK((++f1) == f3); // ++1/2 = 3/2
    CHECK((++f2) == f4); // ++(-1/3) == 2/3
}

TEST_CASE("prefix & postfix subtraction operators") {
    Fraction f1(1,2);
    Fraction f2(-1,3);
    Fraction f3(-1,2);
    Fraction f4(-4,3);

    CHECK((f1--) == f1); // 1/2-- = 1/2
    
    CHECK((f2--) == f2); // -1/3-- = 1/3
    CHECK((--f1) == f3); // --1/2 = -1/2
    CHECK((--f2) == f4); // --(-1/3) == -4/3
}


// TEST_CASE("<<, >> operators") {
//     Fraction f1(1,2);
//     Fraction f2(-1,3);
//     Fraction f3(-1,2);
//     Fraction f4(-4,3);

//     CHECK(f1 << f2); // 1/2-- = 1/2
//     CHECK((f2--) == f2); // -1/3-- = 1/3
//     CHECK((--f1) == f3); // --1/2 = -1/2
//     CHECK((--f2) == f4); // --(-1/3) == -4/3
// }

// TEST_CASE("<= operator") {

// }
