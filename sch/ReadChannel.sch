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
Sheet 2 12
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
L SSI32P4904 U4
U 1 1 5B67ECD7
P 5100 3500
F 0 "U4" H 3450 4900 60  0000 C CNN
F 1 "SSI32P4904" H 5150 3500 60  0000 C CNN
F 2 "" H 3750 3950 60  0000 C CNN
F 3 "" H 3750 3950 60  0000 C CNN
	1    5100 3500
	-1   0    0    1   
$EndComp
Text GLabel 7500 4350 2    60   Input ~ 0
DB0
Wire Wire Line
	7000 4350 7500 4350
Text GLabel 7500 4250 2    60   Input ~ 0
DB1
Wire Wire Line
	7500 4250 7000 4250
Text GLabel 4950 5300 3    60   Input ~ 0
SDEN_RWCH
Wire Wire Line
	4950 5300 4950 5000
$EndSCHEMATC
