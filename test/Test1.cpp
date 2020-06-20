#include <iostream>
#include "gtest/gtest.h"
#include "../Controlador.h"
#include "../Decoder.h"
#include "../Interfaz.h"
#include "../Terminal.h"
#include <utility>
#include <vector>
//Controlador.h Decoder.h Interfaz.h List.h Terminal.h
// TEST(TestPrueba, prueba){
//     EXPECT_EQ(true, true);
// }

class CrearLista : public ::testing::Test {
 protected:
  void SetUp() override {
    //reversar memoria para las listas y para los decoders
    c = new Controlador<int>(1);
    d1 = new Decoder(1);
    d2 = new Decoder(2);
    d3 = new Decoder(3);
    d4 = new Decoder(4);
    list = d1->stringToList<int>("((3 5)(6 1))", "lista1");
    list2 = d1->stringToList<int>("((5)(6 1))", "lista2");
    list3 = d1->stringToList<int>("", "lista3");
    list4 = d2->stringToList<char>("((a b)(c d)","lista3");
    list5 = d2->stringToList<char>("(  a ( d  1)) ","list4");
    list6 = d4->stringToList2("((hola adios)(patata mango))","list6");
  }

   void TearDown() override {
       //liberar memoria
        delete list;
        delete list2;
        delete list3;
        delete list4;
        delete list5;
        delete list6;
        delete d1;
        delete d2;
        delete d3;
        delete d4;
        delete c;
   }

    List<int> *list;
    List<int> *list2;
    List<int> *list3;
    List<char> *list4;
    List<char> *list5;
    List<std::string> *list6;
    Decoder *d1;
    Decoder *d2;
    Decoder *d3;
    Decoder *d4;
    Controlador<int>*c;
};

TEST_F(CrearLista, EsAtomico){
    EXPECT_EQ(list->getHead()->getHead()->isAtomicList(), true);
}
TEST_F(CrearLista, NoEsAtomico){
    EXPECT_EQ(list->getTail()->isAtomicList(), false);
}
TEST_F(CrearLista, mostrarLista){
    EXPECT_EQ(list->toString(),"((3 5)(6 1))");
}
TEST_F(CrearLista, mostrarLista2){
    EXPECT_EQ(list2->toString(),"((5)(6 1))");
}
TEST_F(CrearLista, integerCases3){
    ASSERT_TRUE(list3->getHead()==nullptr && list3->getTail()==nullptr);
}
TEST_F(CrearLista, parantesisFaltantes){
    ASSERT_TRUE(list4->getHead()==nullptr && list4->getTail()==nullptr);
}
TEST_F(CrearLista, espaciosDeMas){
    ASSERT_TRUE(list5->getHead()==nullptr && list5->getTail()==nullptr);
}
TEST_F(CrearLista, buscarEnListaValorExistente){
    EXPECT_EQ(list->find(3),true);
}
TEST_F(CrearLista, buscarValorNoExistente){
    ASSERT_FALSE(list5->find('z')==true);
}
TEST_F(CrearLista, acceder_a_la_cabeza){
    EXPECT_EQ(list6->getHead()->toString(),"(hola adios)");
}
TEST_F(CrearLista, acceder_a_la_cola){
    EXPECT_EQ(list6->getTail()->toString(),"(patata mango)");
}
TEST_F(CrearLista, acceder_a_la_cabeza_de_la_cola){
    EXPECT_EQ(list6->getTail()->getHead()->toString(),"patata");
}

TEST(Decoder, dataTypeConverter){
    Decoder c = Decoder(2);
    EXPECT_EQ('a',c.dataTypeConverter<char>("a"));
}
TEST(Decoder, esInputValido){
    Decoder c = Decoder(2);
    bool inputValido = c.esInputValido("( (a b)(c d");
    ASSERT_FALSE(inputValido == true);
}

int main(){
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
} 