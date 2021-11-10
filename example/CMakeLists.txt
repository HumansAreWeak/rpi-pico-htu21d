# Create an executable
add_executable(htu21d_temperature_humidity_read 
    htu21d_temperature_humidity_read.c
)

# Link all required libraries
target_link_libraries(htu21d_temperature_humidity_read 
    pico_stdlib
    hardware_i2c 
    haw_htu21d
)

# Enable printf output for USB communication
pico_enable_stdio_usb(htu21d_temperature_humidity_read 1)
pico_enable_stdio_uart(htu21d_temperature_humidity_read 0)

# Add the .uf2 output to the build directory
pico_add_extra_outputs(htu21d_temperature_humidity_read)