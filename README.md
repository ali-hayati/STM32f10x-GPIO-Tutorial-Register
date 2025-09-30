# STM32 GPIO and PLL Register-Level Tutorial

Bare-metal configuration of GPIO pins and PLL on STM32F103C8T6
without using HAL or LL libraries.

## Features
- Configure GPIO pins (set, reset, toggle)
- Configure PLL to achieve 72MHz system clock
- Support for multiple pins and ports
-PLLconfig.c and GPIOconfig.c contain the PLL and GPIO functions, while main.c provides an example of how to use them.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/ali-hayati/STM32-GPIO-Register-Level.git

### Parts and software Required	
I am going to use Keil IDE for the STM32 Register programming. I am also using STM32F103C8 series MCU for these projects.

-Keil MDK-ARM
-STM32F103C8 Development board
-ST-Link V2 Programmer
- Proteuse V.8 (this Project simulink with Proteuse

###Create the Project in Keil IDE
	Let’s begin by creating a project in Keil and selecting the 	appropriate microcontroller.
	

![Select Devise for Target](Images/Keil_IDE1.jpg)

Next, we need to include some essential files in the project. Select the CMSIS core and the Device Startup files, as shown below.

![Manage Run-TimeEnvirmment](Images/Keil_IDE2.jpg)


Then, add the main file to the project. Along with it, I have also included RccConfig.h and RccConfig.c and GPIOconfig.c and GPIOconfig.h. These files will contain the code for the clock setup and function related to GPIO.


![Project Target1](Images/Keil_IDE3.png)






