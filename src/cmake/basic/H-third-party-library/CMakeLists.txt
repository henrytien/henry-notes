cmake_minimum_required(VERSION 3.5)

# Set the project name
project(third_party_include)

# Find a boos install with the liararies filesystem and system
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)

# Check if boost was found
if(Boost_FOUND)
    message("boost found")
else()
    message(FATAL_ERROR "Cannot find Boost")
endif()

# Add an executable
add_executable(third_party_include main.cpp)

# Link against the boost libraries
target_link_libraries(third_party_include
    PRIVATE
	   Boost::filesystem
)
