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
Sheet 11 12
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
L KM62256C U13
U 1 1 5B67EFDC
P 5550 3350
F 0 "U13" H 5100 4150 60  0000 C CNN
F 1 "KM62256C" H 5550 3350 60  0000 C CNN
F 2 "" H 5550 3350 60  0000 C CNN
F 3 "" H 5550 3350 60  0000 C CNN
	1    5550 3350
	1    0    0    -1  
$EndComp
Text GLabel 4500 3600 0    60   Input ~ 0
A0
Wire Wire Line
	4850 3600 4500 3600
Text GLabel 4500 3500 0    60   Input ~ 0
A1
Wire Wire Line
	4850 3500 4500 3500
Text GLabel 4500 3400 0    60   Input ~ 0
A2
Wire Wire Line
	4850 3400 4500 3400
Text GLabel 4500 3300 0    60   Input ~ 0
A3
Text GLabel 4500 3200 0    60   Input ~ 0
A4
Text GLabel 4500 3100 0    60   Input ~ 0
A5
$Comp
L GNDD #PWR?
U 1 1 5BCE32EE
P 4800 4150
F 0 "#PWR?" H 4800 3900 50  0001 C CNN
F 1 "GNDD" H 4800 4025 50  0000 C CNN
F 2 "" H 4800 4150 50  0001 C CNN
F 3 "" H 4800 4150 50  0001 C CNN
	1    4800 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4000 4800 4000
Wire Wire Line
	4800 4000 4800 4150
$Comp
L +5V #PWR?
U 1 1 5BCE330B
P 6400 2450
F 0 "#PWR?" H 6400 2300 50  0001 C CNN
F 1 "+5V" H 6400 2590 50  0000 C CNN
F 2 "" H 6400 2450 50  0001 C CNN
F 3 "" H 6400 2450 50  0001 C CNN
	1    6400 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2700 6400 2700
Wire Wire Line
	6400 2700 6400 2450
$Comp
L C C70
U 1 1 5BCE332A
P 6650 2550
F 0 "C70" H 6675 2650 50  0000 L CNN
F 1 "C" H 6675 2450 50  0000 L CNN
F 2 "" H 6688 2400 50  0001 C CNN
F 3 "" H 6650 2550 50  0001 C CNN
	1    6650 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 2550 6400 2550
Connection ~ 6400 2550
$Comp
L GNDD #PWR?
U 1 1 5BCE33BF
P 6900 2550
F 0 "#PWR?" H 6900 2300 50  0001 C CNN
F 1 "GNDD" H 6900 2425 50  0000 C CNN
F 2 "" H 6900 2550 50  0001 C CNN
F 3 "" H 6900 2550 50  0001 C CNN
	1    6900 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 2550 6800 2550
Wire Wire Line
	4500 3300 4850 3300
Wire Wire Line
	4850 3200 4500 3200
Wire Wire Line
	4500 3100 4850 3100
Text GLabel 4500 3000 0    60   Input ~ 0
A6
Text GLabel 4500 2900 0    60   Input ~ 0
A7
Text GLabel 4550 2800 0    60   Input ~ 0
A12
Text GLabel 4550 2700 0    60   Input ~ 0
A14
Wire Wire Line
	4500 3000 4850 3000
Wire Wire Line
	4850 2900 4500 2900
Wire Wire Line
	4550 2800 4850 2800
Wire Wire Line
	4850 2700 4550 2700
Text GLabel 6650 3000 2    60   Input ~ 0
A8
Text GLabel 6650 3100 2    60   Input ~ 0
A9
Text GLabel 6650 3400 2    60   Input ~ 0
A10
Text GLabel 6650 3200 2    60   Input ~ 0
A11
Text GLabel 6650 2900 2    60   Input ~ 0
A13
Wire Wire Line
	6250 2900 6650 2900
Wire Wire Line
	6650 3000 6250 3000
Wire Wire Line
	6250 3100 6650 3100
Wire Wire Line
	6650 3200 6250 3200
Wire Wire Line
	6250 3400 6650 3400
Text GLabel 4500 3700 0    60   Input ~ 0
MD0
Text GLabel 4500 3800 0    60   Input ~ 0
MD1
Text GLabel 4500 3900 0    60   Input ~ 0
MD2
Text GLabel 6650 4000 2    60   Input ~ 0
MD3
Text GLabel 6650 3900 2    60   Input ~ 0
MD4
Text GLabel 6650 3800 2    60   Input ~ 0
MD5
Text GLabel 6650 3700 2    60   Input ~ 0
MD6
Text GLabel 6650 3600 2    60   Input ~ 0
MD7
Wire Wire Line
	6250 3600 6650 3600
Wire Wire Line
	6650 3700 6250 3700
Wire Wire Line
	6250 3800 6650 3800
Wire Wire Line
	6650 3900 6250 3900
Wire Wire Line
	6250 4000 6650 4000
Wire Wire Line
	4850 3900 4500 3900
Wire Wire Line
	4500 3800 4850 3800
Wire Wire Line
	4850 3700 4500 3700
Text GLabel 6650 2800 2    60   Input ~ 0
WR#
Wire Wire Line
	6650 2800 6250 2800
Text GLabel 6650 3300 2    60   Input ~ 0
RD#
Text GLabel 6650 3500 2    60   Input ~ 0
CS1#
Wire Wire Line
	6650 3300 6250 3300
Wire Wire Line
	6250 3500 6650 3500
$EndSCHEMATC
