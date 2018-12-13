EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:HDDChipset
LIBS:WD21000_top-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 9 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L WD61C13A-WM U11
U 1 1 5B67EE97
P 5550 3600
F 0 "U11" H 4650 4600 60  0000 C CNN
F 1 "WD61C13A-WM" H 5500 3600 60  0000 C CNN
F 2 "" H 5550 3600 60  0000 C CNN
F 3 "" H 5550 3600 60  0000 C CNN
	1    5550 3600
	1    0    0    -1  
$EndComp
Text GLabel 6050 2150 1    60   Input ~ 0
CS3#
Wire Wire Line
	6050 2150 6050 2450
Text GLabel 5050 5200 3    60   Input ~ 0
MD0
Text GLabel 3900 4100 0    60   Input ~ 0
MD1
Wire Wire Line
	5050 4750 5050 5200
Wire Wire Line
	4400 4100 3900 4100
Text GLabel 3900 4000 0    60   Input ~ 0
MD2
Text GLabel 3900 3900 0    60   Input ~ 0
MD3
Text GLabel 3900 3800 0    60   Input ~ 0
MD4
Text GLabel 3900 3700 0    60   Input ~ 0
MD5
Text GLabel 3900 3500 0    60   Input ~ 0
MD6
Text GLabel 3900 3400 0    60   Input ~ 0
MD7
Wire Wire Line
	3900 4000 4400 4000
Wire Wire Line
	4400 3900 3900 3900
Wire Wire Line
	3900 3800 4400 3800
Wire Wire Line
	4400 3700 3900 3700
Wire Wire Line
	3900 3500 4400 3500
Wire Wire Line
	4400 3400 3900 3400
$EndSCHEMATC
