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
Sheet 12 12
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
L AT27C516 U12
U 1 1 5B67F07B
P 5800 3600
F 0 "U12" H 5100 4400 60  0000 C CNN
F 1 "AT27C516" H 5800 3550 60  0000 C CNN
F 2 "" H 6050 3600 60  0000 C CNN
F 3 "" H 6050 3600 60  0000 C CNN
	1    5800 3600
	1    0    0    -1  
$EndComp
Text GLabel 5900 4900 3    60   Input ~ 0
A1
Wire Wire Line
	5900 4900 5900 4550
Text GLabel 6000 4900 3    60   Input ~ 0
A2
Wire Wire Line
	6000 4550 6000 4900
Text GLabel 6100 4900 3    60   Input ~ 0
A3
Text GLabel 6200 4900 3    60   Input ~ 0
A4
Text GLabel 6300 4900 3    60   Input ~ 0
A5
Text GLabel 7050 4100 2    60   Input ~ 0
A6
Text GLabel 7050 4000 2    60   Input ~ 0
A7
Text GLabel 7050 3900 2    60   Input ~ 0
A8
Text GLabel 7050 3800 2    60   Input ~ 0
A9
Text GLabel 7050 3500 2    60   Input ~ 0
A10
Text GLabel 7050 3400 2    60   Input ~ 0
A11
Text GLabel 7050 3300 2    60   Input ~ 0
A12
Text GLabel 7050 3200 2    60   Input ~ 0
A13
Text GLabel 7050 3100 2    60   Input ~ 0
A14
Wire Wire Line
	6750 4100 7050 4100
Wire Wire Line
	7050 4000 6750 4000
Wire Wire Line
	6750 3900 7050 3900
Wire Wire Line
	7050 3800 6750 3800
Wire Wire Line
	6750 3500 7050 3500
Wire Wire Line
	7050 3400 6750 3400
Wire Wire Line
	6750 3300 7050 3300
Wire Wire Line
	7050 3200 6750 3200
Wire Wire Line
	6750 3100 7050 3100
Wire Wire Line
	6300 4550 6300 4900
Wire Wire Line
	6200 4900 6200 4550
Wire Wire Line
	6100 4550 6100 4900
Text GLabel 5700 4900 3    60   Input ~ 0
RD#
Wire Wire Line
	5700 4900 5700 4550
Text GLabel 5600 4900 3    60   Input ~ 0
MD0
Text GLabel 5500 4900 3    60   Input ~ 0
MD1
Text GLabel 5400 4900 3    60   Input ~ 0
MD2
Text GLabel 5300 4900 3    60   Input ~ 0
MD3
Text GLabel 4450 4100 0    60   Input ~ 0
MD4
Text GLabel 4450 4000 0    60   Input ~ 0
MD5
Text GLabel 4450 3900 0    60   Input ~ 0
MD6
Text GLabel 4450 3800 0    60   Input ~ 0
MD7
Wire Wire Line
	5600 4900 5600 4550
Wire Wire Line
	5500 4550 5500 4900
Wire Wire Line
	5400 4900 5400 4550
Wire Wire Line
	5300 4550 5300 4900
Wire Wire Line
	4450 4100 4850 4100
Wire Wire Line
	4850 4000 4450 4000
Wire Wire Line
	4450 3900 4850 3900
Wire Wire Line
	4850 3800 4450 3800
Text GLabel 5600 2350 1    60   Input ~ 0
CS0#
Wire Wire Line
	5600 2350 5600 2650
Text GLabel 4450 3500 0    60   Input ~ 0
MD8
Wire Wire Line
	4850 3500 4450 3500
$Comp
L GNDD #PWR?
U 1 1 5C09196E
P 3850 3650
F 0 "#PWR?" H 3850 3400 50  0001 C CNN
F 1 "GNDD" H 3850 3525 50  0000 C CNN
F 2 "" H 3850 3650 50  0001 C CNN
F 3 "" H 3850 3650 50  0001 C CNN
	1    3850 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3600 3850 3600
Wire Wire Line
	3850 3600 3850 3650
NoConn ~ 4850 3700
NoConn ~ 6750 3700
NoConn ~ 5800 4550
NoConn ~ 5800 2650
Text GLabel 4450 3400 0    60   Input ~ 0
MD9
Text GLabel 4450 3300 0    60   Input ~ 0
MD10
Text GLabel 4450 3200 0    60   Input ~ 0
MD11
Text GLabel 4450 3100 0    60   Input ~ 0
MD12
Text GLabel 5300 2350 1    60   Input ~ 0
MD13
Text GLabel 5400 2350 1    60   Input ~ 0
MD14
Text GLabel 5500 2350 1    60   Input ~ 0
MD15
Wire Wire Line
	5500 2650 5500 2350
Wire Wire Line
	5400 2650 5400 2350
Wire Wire Line
	5300 2350 5300 2650
Wire Wire Line
	4450 3100 4850 3100
Wire Wire Line
	4850 3200 4450 3200
Wire Wire Line
	4450 3300 4850 3300
Wire Wire Line
	4850 3400 4450 3400
$EndSCHEMATC
