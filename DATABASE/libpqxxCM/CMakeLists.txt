cmake_minimum_required(VERSION 3.20)

project(libpqxxCM)

set(PostgresSQL_ADDITIONAL_VERSIONS "12")

add_subdirectory("C:\\projects\\DATABASE\\libpqxx-7.9.0" libpqxx-dir)

add_executable(libpqxxCM main.cpp)

target_compile_features(libpqxxCM PRIVATE cxx_std_17)

target_link_libraries(libpqxxCM PRIVATE pqxx)