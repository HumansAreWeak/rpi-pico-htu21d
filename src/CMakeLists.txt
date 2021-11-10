# Include source file(s) to project
add_library(haw_htu21d STATIC
    HTU21D.c
)

# Links all required dependencies
target_link_libraries(haw_htu21d 
    pico_stdlib
    hardware_i2c 
)

# Link include directory / Path to header file
target_include_directories(haw_htu21d PUBLIC ../include)