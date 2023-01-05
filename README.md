# What is this project?
This project is a simple demonstration to show how to write an application using only registers with CMSIS drivers.

# What is the MCU?
This project has been written for the STM32F446RE MCU. The main function works on a STM32F446 nucleo board with :
	* PA5 : LED
	* PC13 : Push Button
	* PA2 - PA3 : USART2

# How to use it?
1. On STM32CubeIDE, create a new empty project: File > New > STM32 project > MCU Selector > STM32F446RET6 > Empty project.
2. Delete all files from Inc/ and Src/ folder.
3. Clone this repository on your Hard Disk.
4. Add all Inc/ and Src/ files in the corresponding folder of your application.
5. Add Drivers folder in your project.

For the compilation process:
1. Add the following folder to your include Path (right click > "Add to include Path"). Otherwise, the compiler won't find the header files. So for the following folders, you need to :
	* Drivers/CMSIS/ST/STM32F4xx/Include
	* Drivers/CMSIS/Include
	* Inc
2. The folder Src/ is by default "exclude from build". We need to include it to the compilation process. Right clic on the folder > C/C++ build > Uncheck the box "Exclude from buid".

Your project is ready. You can now compile and flash your MCU.
 
