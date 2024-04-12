
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

#include <iostream>

#include<catch2/catch_session.hpp>
#include"list.cpp"

//подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>


unsigned long m_size;

bool Empty() { return m_size == 0; }

TEST_CASE("Empty are computed", "[Empty]") 
{
    REQUIRE(Empty() == 1);
    
}


unsigned long Size() { return m_size; }

TEST_CASE("Size are computed", "[Size]")
{
    REQUIRE(Size() == 1);
    REQUIRE(Size() == 2);
    REQUIRE(Size() == 3);
    REQUIRE(Size() == 4);
    REQUIRE(Size() == 5);
}





