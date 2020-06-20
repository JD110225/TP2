#include <iostream>
#include "gtest/gtest.h"
#include "../Controlador.h"
#include "../Decoder.h"
#include "../Interfaz.h"
#include "../Terminal.h"
//Controlador.h Decoder.h Interfaz.h List.h Terminal.h
TEST(TestPrueba, prueba){
    EXPECT_EQ(true, true);
}

class ListClass : public ::testing::Test {
 protected:
  void SetUp() override {
    list = new List<int>(3);
  }

   void TearDown() override {
       delete list;
   }

    List<int> *list;
};

TEST_F(ListClass, integerCases){
    std::cout<<list->toString()<<std::endl;
    ASSERT_TRUE(list->getValue() == 3);
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
} 