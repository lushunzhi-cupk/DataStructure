# Install script for directory: C:/Users/lushunzhi/source/repos/DataStructure

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/lushunzhi/source/repos/DataStructure/out/install/x64-Debug")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/01_Introduction/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/02_LinearList/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/03_Stack_Queue/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/04_String/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/05_Array_GList/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/06_Tree_BinaryTree/cmake_install.cmake")
  include("C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/07_Graph/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/lushunzhi/source/repos/DataStructure/out/build/x64-Debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
