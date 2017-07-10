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
LIBS:switches
LIBS:lader keypad-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L R R1
U 1 1 59308C00
P 5550 2100
F 0 "R1" V 5630 2100 50  0000 C CNN
F 1 "2.2K" V 5550 2100 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 2100 50  0001 C CNN
F 3 "" H 5550 2100 50  0001 C CNN
	1    5550 2100
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 59308D62
P 5550 2600
F 0 "R2" V 5630 2600 50  0000 C CNN
F 1 "330R" V 5550 2600 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 2600 50  0001 C CNN
F 3 "" H 5550 2600 50  0001 C CNN
	1    5550 2600
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 59308E0D
P 5550 3050
F 0 "R3" V 5630 3050 50  0000 C CNN
F 1 "620R" V 5550 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 3050 50  0001 C CNN
F 3 "" H 5550 3050 50  0001 C CNN
	1    5550 3050
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 59308E6B
P 5550 3500
F 0 "R4" V 5630 3500 50  0000 C CNN
F 1 "1K" V 5550 3500 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 3500 50  0001 C CNN
F 3 "" H 5550 3500 50  0001 C CNN
	1    5550 3500
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 59308EC0
P 5550 3950
F 0 "R5" V 5630 3950 50  0000 C CNN
F 1 "3.3K" V 5550 3950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5480 3950 50  0001 C CNN
F 3 "" H 5550 3950 50  0001 C CNN
	1    5550 3950
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW1
U 1 1 59309634
P 5050 2350
F 0 "SW1" H 5100 2450 50  0000 L CNN
F 1 "Down" H 5050 2290 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5050 2550 50  0001 C CNN
F 3 "" H 5050 2550 50  0001 C CNN
	1    5050 2350
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW2
U 1 1 59309709
P 5050 2800
F 0 "SW2" H 5100 2900 50  0000 L CNN
F 1 "Left" H 5050 2740 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5050 3000 50  0001 C CNN
F 3 "" H 5050 3000 50  0001 C CNN
	1    5050 2800
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW3
U 1 1 5930974A
P 5050 3250
F 0 "SW3" H 5100 3350 50  0000 L CNN
F 1 "Select" H 5050 3190 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5050 3450 50  0001 C CNN
F 3 "" H 5050 3450 50  0001 C CNN
	1    5050 3250
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW4
U 1 1 593097C3
P 5050 3700
F 0 "SW4" H 5100 3800 50  0000 L CNN
F 1 "Up" H 5050 3640 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5050 3900 50  0001 C CNN
F 3 "" H 5050 3900 50  0001 C CNN
	1    5050 3700
	1    0    0    -1  
$EndComp
$Comp
L SW_Push SW5
U 1 1 59309828
P 5050 4150
F 0 "SW5" H 5100 4250 50  0000 L CNN
F 1 "Right" H 5050 4090 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH_6mm" H 5050 4350 50  0001 C CNN
F 3 "" H 5050 4350 50  0001 C CNN
	1    5050 4150
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 59309AF0
P 6100 2550
F 0 "C1" H 6125 2650 50  0000 L CNN
F 1 "100nF" H 6125 2450 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6.0mm_W2.5mm_P5.00mm" H 6138 2400 50  0001 C CNN
F 3 "" H 6100 2550 50  0001 C CNN
	1    6100 2550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR01
U 1 1 5930A294
P 4650 4350
F 0 "#PWR01" H 4650 4100 50  0001 C CNN
F 1 "GND" H 4650 4200 50  0000 C CNN
F 2 "" H 4650 4350 50  0001 C CNN
F 3 "" H 4650 4350 50  0001 C CNN
	1    4650 4350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 J1
U 1 1 5930A42E
P 7400 2350
F 0 "J1" H 7400 2550 50  0000 C CNN
F 1 "CONNECTOR" V 7500 2350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7400 2350 50  0001 C CNN
F 3 "" H 7400 2350 50  0001 C CNN
	1    7400 2350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 5930ABF0
P 7100 2550
F 0 "#PWR02" H 7100 2300 50  0001 C CNN
F 1 "GND" H 7100 2400 50  0000 C CNN
F 2 "" H 7100 2550 50  0001 C CNN
F 3 "" H 7100 2550 50  0001 C CNN
	1    7100 2550
	1    0    0    -1  
$EndComp
Text GLabel 5550 1650 1    60   Input ~ 0
+5V
Text GLabel 6150 2150 2    60   Input ~ 0
Output
Wire Wire Line
	5550 1650 5550 1950
Wire Wire Line
	5550 2250 5550 2450
Connection ~ 5550 2350
Wire Wire Line
	5550 2750 5550 2900
Wire Wire Line
	5550 3200 5550 3350
Wire Wire Line
	5550 3650 5550 3800
Wire Wire Line
	5550 4100 5550 4150
Wire Wire Line
	5550 4150 5250 4150
Wire Wire Line
	5250 2800 5550 2800
Connection ~ 5550 2800
Wire Wire Line
	5250 3250 5550 3250
Connection ~ 5550 3250
Wire Wire Line
	5250 3700 5550 3700
Connection ~ 5550 3700
Wire Wire Line
	4850 2350 4650 2350
Wire Wire Line
	4650 2350 4650 4350
Wire Wire Line
	4850 2800 4650 2800
Connection ~ 4650 2800
Wire Wire Line
	4850 3250 4650 3250
Connection ~ 4650 3250
Wire Wire Line
	4850 3700 4650 3700
Connection ~ 4650 3700
Wire Wire Line
	4850 4150 4650 4150
Connection ~ 4650 4150
Wire Wire Line
	7200 2450 7100 2450
Wire Wire Line
	7100 2450 7100 2550
Wire Wire Line
	5550 1900 6600 1900
Connection ~ 5550 1900
Connection ~ 6100 2350
$Comp
L GND #PWR03
U 1 1 59638407
P 6100 2700
F 0 "#PWR03" H 6100 2450 50  0001 C CNN
F 1 "GND" H 6100 2550 50  0000 C CNN
F 2 "" H 6100 2700 50  0001 C CNN
F 3 "" H 6100 2700 50  0001 C CNN
	1    6100 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2350 7200 2350
Wire Wire Line
	7200 2250 6600 2250
Wire Wire Line
	6600 2250 6600 1900
Wire Wire Line
	6150 2150 6100 2150
Wire Wire Line
	6100 2150 6100 2400
$EndSCHEMATC
