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
Sheet 4 12
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
L AD7775 U6
U 1 1 5B67ED54
P 5700 3050
F 0 "U6" H 5100 3800 60  0000 C CNN
F 1 "AD7775" H 5650 3050 60  0000 C CNN
F 2 "" H 5950 3750 60  0000 C CNN
F 3 "" H 5950 3750 60  0000 C CNN
	1    5700 3050
	1    0    0    -1  
$EndComp
Text GLabel 7000 2650 2    60   Input ~ 0
CS4#
Wire Wire Line
	7000 2650 6500 2650
Text GLabel 7000 2550 2    60   Input ~ 0
WR#
Wire Wire Line
	7000 2550 6500 2550
Text GLabel 7000 2450 2    60   Input ~ 0
RD#
Wire Wire Line
	7000 2450 6500 2450
Text GLabel 4400 2550 0    60   Input ~ 0
ALE
Wire Wire Line
	4850 2550 4400 2550
Text GLabel 4400 2750 0    60   Input ~ 0
MD0
Text GLabel 4400 2850 0    60   Input ~ 0
MD1
Text GLabel 4400 2950 0    60   Input ~ 0
MD2
Text GLabel 4400 3050 0    60   Input ~ 0
MD3
$Comp
L GNDD #PWR?
U 1 1 5C092CCB
P 3650 3250
F 0 "#PWR?" H 3650 3000 50  0001 C CNN
F 1 "GNDD" H 3650 3125 50  0000 C CNN
F 2 "" H 3650 3250 50  0001 C CNN
F 3 "" H 3650 3250 50  0001 C CNN
	1    3650 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 3250 3650 3250
Text GLabel 4400 3150 0    60   Input ~ 0
MD4
Wire Wire Line
	4400 2750 4850 2750
Wire Wire Line
	4850 2850 4400 2850
Wire Wire Line
	4400 2950 4850 2950
Wire Wire Line
	4850 3050 4400 3050
Wire Wire Line
	4400 3150 4850 3150
Text GLabel 4400 3350 0    60   Input ~ 0
MD5
Text GLabel 4400 3450 0    60   Input ~ 0
MD6
Text GLabel 4400 3550 0    60   Input ~ 0
MD7
Text GLabel 4400 3650 0    60   Input ~ 0
MD8
Text GLabel 4400 3750 0    60   Input ~ 0
MD9
Wire Wire Line
	4400 3350 4850 3350
Wire Wire Line
	4850 3450 4400 3450
Wire Wire Line
	4400 3550 4850 3550
Wire Wire Line
	4850 3650 4400 3650
Wire Wire Line
	4400 3750 4850 3750
$Comp
L +5V #PWR?
U 1 1 5C093B74
P 7700 2450
F 0 "#PWR?" H 7700 2300 50  0001 C CNN
F 1 "+5V" H 7700 2590 50  0000 C CNN
F 2 "" H 7700 2450 50  0001 C CNN
F 3 "" H 7700 2450 50  0001 C CNN
	1    7700 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 2750 7700 2750
Wire Wire Line
	7700 2750 7700 2450
Text GLabel 7200 3750 2    60   Input ~ 0
VOUTA
Wire Wire Line
	7200 3750 6500 3750
$EndSCHEMATC
