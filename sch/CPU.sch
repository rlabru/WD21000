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
Sheet 10 12
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
L S80C196NU U5
U 1 1 5B67EF69
P 5150 3550
F 0 "U5" H 3600 5600 60  0000 C CNN
F 1 "S80C196NU" H 5150 3550 60  0000 C CNN
F 2 "" H 3650 5650 60  0000 C CNN
F 3 "" H 3650 5650 60  0000 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
Text GLabel 3050 2650 0    60   Input ~ 0
A0
Wire Wire Line
	3350 2650 3050 2650
Text GLabel 3050 2750 0    60   Input ~ 0
A1
Wire Wire Line
	3350 2750 3050 2750
Text GLabel 3050 3050 0    60   Input ~ 0
A2
Wire Wire Line
	3350 3050 3050 3050
Text GLabel 3050 3150 0    60   Input ~ 0
A3
Text GLabel 3050 3250 0    60   Input ~ 0
A4
Text GLabel 3050 3350 0    60   Input ~ 0
A5
Text GLabel 3050 3450 0    60   Input ~ 0
A6
Text GLabel 3050 3550 0    60   Input ~ 0
A7
Text GLabel 7250 3550 2    60   Input ~ 0
A8
Text GLabel 7250 3650 2    60   Input ~ 0
A9
Text GLabel 7250 3750 2    60   Input ~ 0
A10
Text GLabel 7250 3850 2    60   Input ~ 0
A11
Text GLabel 7250 3950 2    60   Input ~ 0
A12
Text GLabel 7250 4050 2    60   Input ~ 0
A13
Text GLabel 7250 4150 2    60   Input ~ 0
A14
Wire Wire Line
	7250 3550 6850 3550
Wire Wire Line
	6850 3650 7250 3650
Wire Wire Line
	7250 3750 6850 3750
Wire Wire Line
	6850 3850 7250 3850
Wire Wire Line
	7250 3950 6850 3950
Wire Wire Line
	6850 4050 7250 4050
Wire Wire Line
	7250 4150 6850 4150
Wire Wire Line
	3050 3550 3350 3550
Wire Wire Line
	3350 3450 3050 3450
Wire Wire Line
	3050 3350 3350 3350
Wire Wire Line
	3350 3250 3050 3250
Wire Wire Line
	3050 3150 3350 3150
Text GLabel 3050 2150 0    60   Input ~ 0
MD0
Text GLabel 4150 1050 1    60   Input ~ 0
MD1
Text GLabel 4250 1050 1    60   Input ~ 0
MD2
Text GLabel 4350 1050 1    60   Input ~ 0
MD3
Text GLabel 4450 1050 1    60   Input ~ 0
MD4
Text GLabel 4550 1050 1    60   Input ~ 0
MD5
Text GLabel 4650 1050 1    60   Input ~ 0
MD6
Text GLabel 4750 1050 1    60   Input ~ 0
MD7
Wire Wire Line
	3050 2150 3350 2150
Wire Wire Line
	4150 1350 4150 1050
Wire Wire Line
	4250 1050 4250 1350
Wire Wire Line
	4350 1350 4350 1050
Wire Wire Line
	4450 1050 4450 1350
Wire Wire Line
	4550 1350 4550 1050
Wire Wire Line
	4650 1050 4650 1350
Wire Wire Line
	4750 1350 4750 1050
Text GLabel 7250 2450 2    60   Input ~ 0
WR#
Text GLabel 7250 2550 2    60   Input ~ 0
RD#
Text GLabel 3050 4050 0    60   Input ~ 0
CS1#
Wire Wire Line
	3350 4050 3050 4050
Wire Wire Line
	6850 2450 7250 2450
Wire Wire Line
	7250 2550 6850 2550
Text GLabel 3050 3950 0    60   Input ~ 0
CS0#
Wire Wire Line
	3350 3950 3050 3950
Text GLabel 3050 4150 0    60   Input ~ 0
CS2#
Wire Wire Line
	3050 4150 3350 4150
Text GLabel 3050 4250 0    60   Input ~ 0
CS3#
Wire Wire Line
	3350 4250 3050 4250
Text GLabel 3050 4450 0    60   Input ~ 0
CS4#
Wire Wire Line
	3050 4450 3350 4450
$Comp
L GNDD #PWR?
U 1 1 5BE07442
P 2600 4350
F 0 "#PWR?" H 2600 4100 50  0001 C CNN
F 1 "GNDD" H 2600 4225 50  0000 C CNN
F 2 "" H 2600 4350 50  0001 C CNN
F 3 "" H 2600 4350 50  0001 C CNN
	1    2600 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	2600 4350 3350 4350
NoConn ~ 3350 4550
Text GLabel 4950 1050 1    60   Input ~ 0
MD8
Wire Wire Line
	4950 1350 4950 1050
Text GLabel 5150 1050 1    60   Input ~ 0
MD9
Wire Wire Line
	5150 1050 5150 1350
Text GLabel 5250 1100 1    60   Input ~ 0
MD10
Text GLabel 5350 1100 1    60   Input ~ 0
MD11
Text GLabel 5450 1100 1    60   Input ~ 0
MD12
Text GLabel 5550 1100 1    60   Input ~ 0
MD13
Text GLabel 5650 1100 1    60   Input ~ 0
MD14
Text GLabel 5750 1100 1    60   Input ~ 0
MD15
Wire Wire Line
	5250 1100 5250 1350
Wire Wire Line
	5350 1350 5350 1100
Wire Wire Line
	5450 1100 5450 1350
Wire Wire Line
	5550 1350 5550 1100
Wire Wire Line
	5650 1100 5650 1350
Wire Wire Line
	5750 1350 5750 1100
Text GLabel 7250 2750 2    60   Input ~ 0
ALE
Wire Wire Line
	7250 2750 6850 2750
Text GLabel 7250 2350 2    60   Input ~ 0
PARK
Wire Wire Line
	6850 2350 7250 2350
Text GLabel 7250 2250 2    60   Input ~ 0
SDEN_RWCH
Wire Wire Line
	6850 2250 7250 2250
$EndSCHEMATC
