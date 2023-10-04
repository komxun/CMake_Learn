cmake_minimum_required(VERSION 2.8)
project(komsunmath2_project)
add_library(komsunmath2 multiplier.cpp)
set_target_properties(komsunmath2 PROPERTIES PUBLIC_HEADER multiplier.h)
install(TARGETS komsunmath2 LIBRARY DESTINATION lib 
PUBLIC_HEADER DESTINATION include)