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
Sheet 5 12
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
L UC3173AQP U9
U 1 1 5B67EDA9
P 5750 3450
F 0 "U9" H 5250 4150 60  0000 C CNN
F 1 "UC3173AQP" H 5750 3450 60  0000 C CNN
F 2 "" H 5750 3450 60  0000 C CNN
F 3 "" H 5750 3450 60  0000 C CNN
	1    5750 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5C093537
P 5450 4500
F 0 "#PWR?" H 5450 4250 50  0001 C CNN
F 1 "GND" H 5450 4350 50  0000 C CNN
F 2 "" H 5450 4500 50  0001 C CNN
F 3 "" H 5450 4500 50  0001 C CNN
	1    5450 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 4300 5450 4500
Wire Wire Line
	5450 4400 6050 4400
Wire Wire Line
	6050 4400 6050 4300
Connection ~ 5450 4400
Wire Wire Line
	5950 4300 5950 4400
Connection ~ 5950 4400
Wire Wire Line
	5850 4300 5850 4400
Connection ~ 5850 4400
Wire Wire Line
	5750 4300 5750 4400
Connection ~ 5750 4400
Wire Wire Line
	5650 4300 5650 4400
Connection ~ 5650 4400
Wire Wire Line
	5550 4300 5550 4400
Connection ~ 5550 4400
Text GLabel 4150 3550 0    60   Input ~ 0
VOUTA
$Comp
L R R71
U 1 1 5C0B6DFB
P 4400 3550
F 0 "R71" V 4480 3550 50  0000 C CNN
F 1 "R" V 4400 3550 50  0000 C CNN
F 2 "" V 4330 3550 50  0001 C CNN
F 3 "" H 4400 3550 50  0001 C CNN
	1    4400 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 3550 4550 3550
Wire Wire Line
	4250 3550 4150 3550
$Comp
L R R?
U 1 1 5C0B7164
P 7250 3550
F 0 "R?" V 7330 3550 50  0000 C CNN
F 1 "R" V 7250 3550 50  0000 C CNN
F 2 "" V 7180 3550 50  0001 C CNN
F 3 "" H 7250 3550 50  0001 C CNN
	1    7250 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	7100 3550 6550 3550
Text GLabel 3550 3750 0    60   Input ~ 0
J1-1
Wire Wire Line
	4950 3750 3550 3750
Text GLabel 7650 3750 2    60   Input ~ 0
J1-2
Wire Wire Line
	7650 3750 6550 3750
Text GLabel 5450 2100 1    60   Input ~ 0
PARK
Wire Wire Line
	5450 2600 5450 2100
$EndSCHEMATC
