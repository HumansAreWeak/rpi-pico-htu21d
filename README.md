# RPi Pico HTU21D C library

This project contains a stand-alone library for the Raspberry Pi Pico SDK, written in C. The library is made for the HTU21D sensor from Texas Instruments. You have to download and setup the library to have it work properly.

![HTU21D](https://www.gmelectronic.com/data/product/1024_1024/pctdetail.772-267.1.jpg)

# Repository Contents

-   **/src** - Source files of the library
-   **/include/haw** - Header files of the library
-   **/example** - Example program of how this library might be implemented
-   **CMakeLists.txt** - CMake file for automated linking

# Beginner's Guide | How to install

For this library CMake is used for linking. If you don't know how to implement this library to your project, use these steps as a helping guide:

1.  Create a new folder in your Pico project called (for example) **_vendors_**
2.  Update your top level **CMakeLists.txt** file by adding the following line

        # Adds a CMakeLists.txt file from a subdirectory
        add_subdirectory(vendors)

    Write it below the **pico_sdk_init()** line.

3.  Download this repository and paste it into the **_vendors_** folder
4.  Create a new **CMakeLists.txt** file inside the **_vendors_** folder
5.  Edit the **CMakeLists.txt**. Add the following lines:

        cmake_minimum_required(VERSION 3.12)

        # Adds a CMakeLists.txt file from a subdirectory
        add_subdirectory(rpi-pico-bmp180-master)

6.  Include this project into your project by adding a new target link library. Open your top level **CMakeLists.txt** file and add:

        target_link_libraries(${PROJECT_NAME}
            /* ... other libs */
            haw_htu21d
        )

    After these steps you can go ahead and recompile CMake. Everything should be linking automatically.

# How to use

You can use this library simply by including the header located at "haw/HTU21D.h".

For examples take a look at the **./example** folder

# Contributions

Every help is appreciated, feel free to fork my project and make pull requests.

# Version history

v1.0 - Initial release

# License

MIT License
