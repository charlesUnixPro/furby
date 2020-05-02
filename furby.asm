;;; Missing labels

TI_reset equ fe00h
Name_table equ fe10h
Word_group0 equ fe11h
Word_group1 equ fe12h
Word_group2 equ fe13h
Say_active equ   14h
Word_active equ   15h
Clr_word_end equ fe16h
Set_end equ fe17h
Spch_more equ fe18h


;;; cac I am not sure how Furby 27 gets included. XXX

  Include Furby27.inc

;Voice_table equ ff00h
;Name_table equ ff01h



;
; Table of contents
;
; pg   3-4       Voice EQUs
; pg   4         Motor EQUs
; pg   5-7       I/O port EQUs
; pg   7-9       Timer EQUs
; pg   9-10      DAC EQUs
; pg  10         Sensor EQUs
; pg  10-14      Run EQUs
; pg  14-19      Variables, stack
; pg  19-25      RESET handler
; pg  26-        Idle handler
; 
; pg  98-99      EEPROM write
; pg  99         Sleep code
; pg  99-105     Interupt handlers
;
; pg 105-108     TI sound chip communication
;
;;; page 000 start complete; cover page 
;         TITLE PAGE
;
;       INTERACTIVE TOY
;   (FURBY.ASM - Version 25)
;
;    INVENTOR: Dave Hamptom
;
;
; Attorney Docket No. 64799
; FITCH, EVEN, TABIN & FLANNERY
; Suite 900
; 135 South LaaSalle Street
; Chicago, Illinois  60603-4277
; Telephone (312) 372-7842
;;; page 000 end
;;; page 001 start complete
;*******************************************************************************
;
;	SPC81A Source Code   (Version 25)
;
;
;	Written by: Dave Hampton / W???? Schulz
;
;	Date:       July 30, 1998
;
;	Copyright  (C) 1996,1997,1998 by Sounds Amazing!
;
;	All rights reserved
;
;*******************************************************************************
;
;
;*******************************************************************************

;  remember    SBC   if there is a borrow carray is CLEARED
;  also SBC    if the two numbers are equal you still get a negative result

;
;
;*******************************************************************************
;   MODIFICATION LIST
;

; Furby29/30/31/32
;     Final testing for shipment of code on 8/2/98.
;     Tables updated, Motor speed updated, wake up/name fix.
;     sequential tables never getting first entry fixed.
;     New diag5.asm, Light3.asm (if light osc stalls it wont harg system).
;
; Furby33
;     In motor brake routne, turn motoros off before turning reverse
;     braking pulse on to save transistors.
;
; Furby34
;     Cleanup start code and wake routines.
;     Light sensor goes max dark and stats there to reff time, then
;     call sleep macro and shut down.
;
; Furby35
;    Adds four new easter eggs,BURP ATTACK, SAY NAME, TWINKLE SONG,
;    and ROOSTER LOVES YOU. Also add new names.
;
;*******************************************************************************
;;; page 001 end
;;; page 002 start complete
; Release 3

;; File "testR3a"

; 1. Light sensor has a hysteresis point of continually triggering sensor.
; 2. Light sensor decrements two instead of one on hungry counter
; 3. Diagnos??????de for light sensor wont trigger very easily.
; 4. When a furby receives the I.R. sleep command he sends the same command
;    out before going to sleep.
;
; 5. When hungry is low enough to trigger sick counter, each sensor
;    deducts two instead of one for each hit.
;
; 6. When diagnostics complete clear memory, reset hungry & sick to FF
;    randomly choose new name and voice, then write EEPROM before
;    going to sleep. Also extend EEPROM diagnostic to test all locations
;    for pass/fail of device.
;
; 7. Add new light routine

; 8. Change hide and seek egg to light, light, light, tummy.

; 9. Change sick/hungry counter so that it can only get so sick and
;    not continue down to zero. (MAX_SICK)

;10. In diagnostics, motor position test ,,,, first goes forward continously
;    until the front switch is pressed, then goes reverse continuosly
;    until the front swtich is pressed again, and then does normal position
;    calibration stopping at the calibration switch.

;11. On power up we still use tilt and invert to generate startup random
;    numbers, but if feed switch is pressed for cold boot, we use it to
;    generate random numbers, because it is controlled by the user where
;    the tilt and invert are more flaky.

;12. No matter what age, 25% of time he randomly pulls speech from age
;    to generate more Furbish at older ages.

;13. Twinkle song egg
;    When song is complete, if both front and back switches are pressed
;    we goto deep sleep. That means only the invert can wake us up, not 
;    the tilt switch.

;
;**************************************************************************
;**************************************************************************
;**************************************************************************
;**************************************************************************
;**************************************************************************
;**************************************************************************
;;; page 002 end
;;; page 003 start complete
; Actual numeric value for TI pitch control

;  bit 7 set = subtract value from current course value
;        clr = add value to current course value
;  bit 6 set = select music pitch table
;        clr = select normal speech pitch table
;  bit 0-5 value to change course value (no change = 0)
;

; A math routine in 'say_0' converts the value for + or -
; if <80 then subtracts from 80 to get the minus version of 00
; ie, if number is 70 then TI gets sent 10 (which is -10)
; If number is 80 or > 80 then get sent literal as positive.

; NOTE: MAX POSITIVE IS 8F (+16 from normal voice of 00)
;       MAX NEGATIVE is 2F (-47 from normal voice of 00)

;This is a difference of 80h - 2Fh or 51h


; 8Fh is hi voice  (8f is very squeeeeeke)
; 2Fh lo voice ( very low)


; The math routine in 'Say_0' allows a +-decimal number in the speech table.
; A value of 80 = no change or 00 sent to TI
; 81 = +1
; 8f = +16
;
; A value of 7F = -1 from normal voice
; 70 = -16

; The voice selection should take into consideration that the hi voice
; selection plus an aditional offset is never greater than 8f
; Or a low voice minus offset never less than 2f.

Voice1		EQU	83h	;(+3) high voice
Voice2		EQU	7Ah	;(-6) mid voice
Voice3		EQU	71h	;(-15) low voice


;;;; we converted to a random selection table, but since all voice tables
;    use the equates plus some offset, we read the change in the SAY_0
;    routine. We always assign voice 3 which is the lowest, and based on
;    the random power up pitch selection, the ram location 'Rvoice' holds
;    the number to add to the voice+offset received from the macro table.


Voice	EQU	Voice3		;pitch (choose Voice1, Voice2, VOice3) (voice2=norm)

; Select Voice3 since it is the lowest and then add the difference to get
; Voice2 or Voice3. Here we assign that difference to an equate to be
; used in the voice table that is randomly selected on power up.

S_voice1	EQU	18	;Voice3 + 10d = Voice1
S_voice2	EQU	09	;Voice3 + 09d = Voice2
;;; page 003 end
;;; page 004 start complete
S_voice3	EQU	0	;Voice3 + 00d = Voice3


;********************************************************************

; Motor speed pulse width :
; Motor_on = power to motor, Motor_off is none.


Mpulse_on	EQU	16	;
Mpulse_off	EQU	16	;

Cal_pos_fwd	EQU	134	;calibration switch forward direction
Cal_pos_rev	EQU	134	;calibration switch forward direction

;********************************************************************
;********************************************************************
;********************************************************************
;********************************************************************
;********************************************************************
;
;+------------------------------------------------------------------+
;|                       PORTS                                      |
;| SPC40A has : 16 I/O pins                                         |
;| PORT_A 4 I/O pins  0-3                                           |
;| PORT_C 4 I/O pins  0-3                                           |
;| PORT_D 8 I/O pins  0-7                                           |
;|                                                                  |
;|                         RAM                                      |
;|                                                                  |
;| SPC40A has : 128 bytes of RAM                                    |
;| from $80 - $FF                                                   |
;|                                                                  |
;|                         ROM                                      |
;| SPC40A has :                                                     |
;| BANK0 user ROM from $0600 - $7FFF                                |
;| BANK1 user ROM from $8000 - $FFF9                                |
;|                                                                  |
;|                                                                  |
;|                        VECTORS                                   |
;| NMI   vector  $7FFA / $7FFB                                      |
;| RESET vector  $7FFC / $7FFD                                      |
;| IRQ   vector  $7FFE / $7FFF                                      |
;+------------------------------------------------------------------+
;+------------------------------------------------------------------+
;|                             PORTS                                |
;| SPC120A has : 17 I/O pins                                        |
;| PORT_A 4 I/O pins  0-3                                           |
;| PORT_B 4 I/O pins  0,1,2,4,5                                     |
;| PORT_C 4 I/O pins  0-3 input only                                |
;| PORT_D 8 I/O pins  0-7                                           |
;|                                                                  |
;|                              RAM                                 |
;| SPC120A has : 128 bytes of RAM                                   |
;| from $80 - $FF                                                   |
;|                                                                  |
;|                              ROM                                 |
;| SPC120A has :                                                    |
;;; page 004 end
;;; page 005 start complete
;| BANK0 user ROM from $0600 - $7FFA                                |
;| BANK1 user ROM from $8000 - $FFFF                                |
;| BANK2 user ROM from $10000 - $17FFF                              |
;| BANK3 user ROM from $1A000 - $1FFFF                              |
;|                                                                  |
;|                                                                  |
;|                              VECTORS                             |
;| NMI   vector  $7FFA / $7FFB                                      |
;| RESET vector  $7FFC / $7FFD                                      |
;| IRQ   vector  $7FFE / $7FFF                                      |
;+------------------------------------------------------------------+


; unusable areas in rom

;SPC40A:   8000H --  DEFFH should be skiped (Dummy area)
;  bank 0 = 600-7FFA
;  bank 1 = 8000 - DFFF reserved , start @ E000 - FFFA

;SPC80A:   10000H --  13FFFH should be skiped (Dummy area)
;  bank 0 = 600 - 7FFA
;  bank 1 = 8000 - FFFA
;  bank 2 = 10000-13FFF reserved , start at 14000 - 17FFF

;SPC120A: ;SCP120A  18000H --  19FFFH should be skiped (Dummy area)
;  bank 0 = 600-7FFA
;  bank 1 = 8000 - FFFA
;  bank 2 = 10000-17FFF
;  bank 3 = 18000-19FFF reserved , start at 1A000 - 1FFFA

;SPC256A:  ;SPC256A: Non dummy area

;SPC512A:  ;SPC512A: Non dummy area

;*************************************************************************************

.CODE
.SYNTAX 6502
.LINKLIST
.SYMBOLS


;----------------- PORT DIRECTION CONTROL REGISTER -----------------------------
Ports_dir	EQU	00	; (write only)
;
; (4 I/O pins) controlled with each bit of this register
; you can't control each pin separately, only as a nibble
; 0 = input / 1 = output
;
; 7      6      5      4      3      2      1     0      (REGISTER BITS)
; D      D      C      C      B      B      A     A      (PORT)
; 7654   4310   7654   3210   7654   3210   7654  3210   (PORT BITS)
;-------------------------------------------------------------------------------

;----------------- PORT CONFIGURATION CONTROL REGISTER -------------------------
;;; page 005 end
;;; page 006 start complete

;             based on of the port pin is input or output
Ports_con	EQU	01	; (write only)
;
; (4 I/O pins) controlled with each bit of this register
; 7      6      5      4      3      2      1     0      (REGISTER BITS)
; D      D      C      C      B      B      A     A      (PORT)
; 7654   3210   7654   3210   7654   3210   7654  3210   (PORT BITS)

; port_a INPUTS can be either:
; 0 = float  1 = pulled high

; port_a OUTPUTS can be either:
; 0 = buffer 1 = upper (4) bits Open drain Pmos (source)
;                lower (4) bits Open drain Nmos (sink)

; port_b INPUTS can be either:
; 0 = float  1 = pulled low

; port_b OUTPUTS can be either:
; 0 = buffer 1 = upper (4) bits Open drain Nmos (sink)
;                lower (4) bits Open drain Nmos (sink)
;
; port_c INPUTS can be either:
; 0 = float  1 = pulled high
; port_c OUTPUTS can be either:
; 0 = buffer 1 = upper (4) bits Open drain Pmos (source)
;                lower (4) bits Open drain Nmos (sink)
;
; port_d INPUTS can be either:
; 0 = float  1 = pulled low
; port_d OUTPUTS can be either:
; 0 = buffer 1 = Open drain Pmos (source)

;-------------------------------------------------------------------------------

;----------------- I/O PORTS ---------------------------------------------------

Port_A		EQU	02H 	; (read/write) for TI & speech recgn CPU's
Data_D0		EQU	01H	; bit 0 data nible port
Data_D1		EQU	02H	;
Data_D2		EQU	04H	;
Data_D3		EQU	08H	;

Port_B		EQU	03H	;b0/b1 = I/O b4/b5 = inp only
TI_init		EQU	01H	;B0 - TI reset control
TI_CTS		EQU	02H	;B1 - hand shake to TI
IR_IN		EQU	10H	;B4 - I.R. Recv data
TI_RTS		EQU	20H	;B5 - TI wants data

Port_C		EQU	04H	;(read/write)
Motor_cal	EQU	01H	;C0 - lo when motor crosses switch
Pos_sen		EQU	02H	;C1 - motor ????ical sensor (intt C1)
Touch_back	EQU	04H	;C2 - back touch
Touch_frnt	EQU	08H	;C3 - front touch
;;; page 006 end
;;; page 007 start complete
Port_D		EQU	05H	;(read/write)
Ball_side	EQU	01H	;D0 - hi when on any side (TILT)
Ball_invert	EQU	02H	;D1 - hi when inverted
Light_in	EQU	04H	;D2 - hi when bright light hits sensor
Mic_in		EQU	08H	;D3 - hi pulse microphone input
Power_on	EQU	10H	;D4 - power to rest of circuit
Motor_led	EQU	20H	;D5 - motor I.R. led driver
Motor_lt	EQU	40H	;D6 - motor drive left (forward)
Motor_rt	EQU	80H	;D7 - motor drive right (reverse)

;-------------------------------------------------------------------------------

;----------------- DATA LATCH PORT_D -------------------------------------------

Latch_D		EQU	06H	; (read)
; read to latch data from port_d, used for wake-up on pin change

;-------------------------------------------------------------------------------

;----------------- BANK SELECTION REGISTER -------------------------------------
Bank		EQU	07H	; (read/write) x x x x x x x b
; 0 = bank 0, 1 = bank 1	;              7 6 5 4 3 2 1 0
; only two banks in SPC40a
;-------------------------------------------------------------------------------

;----------------- WAKE UP -----------------------------------------------------
Wake_up		EQU	08H	; (read/write) x x x x x x x w
;                                              7 6 5 4 3 2 1 0

; w=(0=disable, 1=enable wake-upon port_d change)
; read to see if wake-up, or normal reset
; this is the only source for a wake-up
; Always reset stack on wake up.
;-------------------------------------------------------------------------------


;----------------- SLEEP -------------------------------------------------------
Sleep		EQU	09H	; (write)      x x x x x x x s
;				;              7 6 5 4 3 2 1 0
; s =(0=don't care, 1=sleep)
; writting 1 to bit0, forces sleep
;-------------------------------------------------------------------------------

;----------------- TIMER A CONTROL REGISTER ------------------------------------
; this needs more work to understand DMH
TMA_CON		EQU	0BH	; (write)
;
;
;            7 6 5 4 3 2 1 0
;            m x x x
;
;            m= Timer one mode (0=Timer,1=Counter)
;;; page 007 end
;;; page 008 start complete
;            Bit3: IE1 | IE1= 0: Counter clock= external clock from IOC2
;            Bit2: T1  |    = 1, T1= 0: counter clock= CPUCLK/8192
;            Bit1: IE0 |         T1= 1: counter clock= CPUCLK/65536
;            Bit0: T0  | IE0= 0: Counter clocks external clock from IOC2
;                           = 1, T0= 0: counter clock= CPUCLK/4
;                                T0= 1: counter clock= CPUCLK/64
;
;-------------------------------------------------------------------------------


;----------------- INTERRUPTS --------------------------------------------------
Interrupts	EQU	0DH	; (read/write)
;
;        7 6 5 4 3 2 1 0
;        w m a b 3 2 1 e
;
;        w = (0=watch dog ON, power-on default) (1=watch dog OFF)
;        m = (0=Timer A generates NMI INT, 1=Timer A generates IRQ INT)
;        a = (0=Timer A interrupt off, 1=Timer A interrupt on)
;        b = (0=Timer B interrupt off, 1=Timer B interrupt on)
;        3 = (0=CPU CLK/1024 interrupt off,  1=CPU CLK/1024 interrupt on)
;        2 = (0=CPU CLK/8192 interrupt off,  1=CPU CLK/8192 interrupt on)
;        1 = (0=CPU CLK/65536 interrupt off,  1=CPU CLK/65536 interrupt on)
;        e = (0=external interrupt off, 1=external interrupt on)
;             rising edge, from port_c bit 1
;-------------------------------------------------------------------------------

;----------------- TIMERS ------------------------------------------------------
; There are two 12bits timers.
; Timer A can be either a timer or a counter. (as set by TIMER_CON)
; Timer B can only be used as a timer.
;
; Timers count-up and on overflow from 0FFF to 0000, this carry bit will
; create an interrupt if the corresponding bit is set in INTERRUPTS register.
; The timer will be auto reloaded with the user setup value, and start,,,
; count-up again.
;
; Counter will reset by user loading #00 into register TMA_LSB and TMA_MSB.
; Counter registers can be read on-the-fly, this will not affect register,,,
; values, or reset them.
;

;-------------------------------------------------------------------------------

;----------------- TIMER A (low byte) ------------------------------------------
TMA_LSB		EQU	10H	; (read/write)
;
; all 8bits valid (lower 8bits of 12bit timer)
;;; page 008 end
;;; page 009 start complete
;-------------------------------------------------------------------------------

;----------------- TIMER A (high byte) -----------------------------------------
TMA_MSB		EQU	11H	; (read/write)
; read        x  x  x  x  11 10 9  8    timer upper 4 bits
;             7  6  5  4  3  2  1  0
;
; write       x  x  t  c  11 10 9  8    timer upper 4 bits
;             7  6  5  4  3  2  1  0    register bit
;
;             t=(0=speech mode, 1=Tone mode)
;             this connects the AUDA pin to either
;             the DAC1, or Timer generated square wave
;
;             c=(0=CPU clock,  1=CPU clock/4)
;-------------------------------------------------------------------------------

;----------------- TIMER B (low byte) ------------------------------------------
TMB_LSB		EQU	12H
;
; all 8 bits valid (lower 8 bits of 12bit timer)
;-------------------------------------------------------------------------------

;----------------- TIMER B (high byte) -----------------------------------------
TMB_MSB		EQU	13H
; read        x  x  x  x  11 10 9  8    timer upper 4 bits
;             7  6  5  4  3  2  1  0
;
; write       x  x  t  c  11 10 9  8    timer upper 4 bits
;             7  6  5  4  3  2  1  0    register bit

;             t=(0=speech mode, 1=Tone mode)
;             this connects the AUDB pin to either
;             the DAC2, or Timer generated square wave
;
;             c=(0=CPU clock,  1=CPU clock/4)
;-------------------------------------------------------------------------------


;----------------- D/A CONVERTERS ----------------------------------------------
DAC1		EQU	14H	; (write)
DAC2		EQU	15H	; (write)
;-------------------------------------------------------------------------------

;----------------- D/A CONVERTERS ----------------------------------------------
; this needs more work to understand DMH
;    16H    ADCoutputPort16H:

DAC_ctrl	EQU	16H


;
;;; page 009 end
;;; page 010 start complete
;               Bit7: 0: Diable ADC; 1: Enable ADC
;               Bit6: I/O
;               Bit5: I/O
;               Bit4: I/O
;               Bit3: I/O
;               Bit2: I/O
;               Bit1: I/O
;               Bit0: I/O
;-------------------------------------------------------------------------------

;-----------------------------------------------------
; Operating equate definition
;-----------------------------------------------------
;EQdef

;to calculate sampl?
; CPU clk/sample rate ???????
; Hi & Lo timer reg co?????  = FFF
; FFF - divisor = valu?????? hi & lo reg.

;ex: 6mHz clk = 166nSEC

;******** start Tracker


;/* hire is some definition chge of timer interrupt constant */Tracker

;SystemClock	EQU	6000000	;Select 6000000Hz it will be the sma
				;as before
SystemClock	EQU	3579545	;Select 3579545Hz while we ???? use that
				;crystal

TimeA_low	EQU	<(4096-(SystemClock/5859))	;put constant definition
TimeA_hi	EQU	>(4096-(SystemClock/5859))

TimeB_low	EQU	<(4096-(SystemClock/1465))
TimeB_hi	EQU	>(4096-(SystemClock/1465))

;******** end Tracker

Port_def	EQU	A7H	;D hi-out,D lo=in  / C hi=out,C lo=inp
				;B hi=inp,B lo=out / A hi=out,A lo=out

Con_def		EQU	50H	;D hi=out buffer, D lo=in pull lo
;				;C hi=out buffer, C lo=in pull hi
;				;B hi=in hi-Z   , B lo=out buffer
;				;A hi=out buffer, A lo=out buffer

Intt_dflt	EQU	D0H	;sets interrupt reg = no watchdoc, irq
				; timer B  and Ext port C bit 1 = off

;**** run EQUs

;*******************************************************************************
;;; page 010 end
;;; page 011 start complete
; Send a breaking pulse ot stop motor drift, and this EQU is a decimal number
; that determines how many time through the 2.9 mSec loop (how many loops)
; the brake pulse is on. If attempting to make single count jumps, the
; brakes pulse is on. If attempting to make single count jumps, the
; brake pulse needs to be between 26 and 30. For any jump great than 10
; braking between 22 and 80 is acceptable. ( Long jumps are not critical
; but short jump will bgin to oscillate if braking is too great.)


; 60 lond & 20 short work at 3.6v and no pulse width


Dritf_long	EQU	60	;number times thru intr before clearing pulse
Drift_short	EQU	25	;

;*******************************************************************************

; set this with a number from 0 - 255 to determine timeout of all sensors
; for the sequential increments. If it times out the table pointer
; goes back to the start, else each trigger increments through the table.

; NOTE: this time includes the motor/speech execution time !!!


Global_time	EQU	16

;*******************************************************************************
; This determines how long FIrby waits with no sensor activity, then
; calls the Bored_table for a random speech selection.
; Use a number between 1 & 255. Should probably not be less than 10.

; SHOULD BE > 10 SEC TO ALLOT TIME FOR TRAINING OF SENSORS

Bored_reld	EQU	40	; 1- 742 mSEC ;; 255 = 189.3 seconds

;*******************************************************************************
;
; Each sensor has a sequential random sp??? which must equal 16.
; Each sensor has a different assignment.
; The tables are formatted with the first X assignments random
; and the ramaining as sequential.

Seq_front	EQU	8
Ran_front	EQU	8

Seq_back	EQU	9
Ran_back	EQU	7

Seq_tilt	EQU	10
Ran_tilt	EQU	6

Seq_invert	EQU	11
Ran_invert	EQU	5

Seq_sound	EQU	0
Ran_sound	EQU	16
;;; page 011 end
;;; page 012 start complete
Seq_light	EQU	0
Ran_light	EQU	16

Seq_feed	EQU	8
Ran_feed	EQU	8

Seq_wake	EQU	0
Ran_wake	EQU	16

Seq_bored	EQU	7
Ran_bored	EQU	9

Seq_hunger	EQU	5
Ran_hunger	EQU	11

Seq_sick	EQU	4
Ran_sick	EQU	12



; rev  furb11ja

; Each sensor also determines how often it is random or sequential
; as in 50/50 or 60/40 etc.
; These entries are subtracted from the random number generated
; and determine the split. (the larger here, the more likely sequential pick)

Tilt_split	EQU	80h	;
Invert_split	EQU	80h	;
Front_split	EQU	80h	;
Back_split	EQU	80h	;
Feed_split	EQU	80h	;
Sound_split	EQU	80h	;
Light_split	EQU	80h	;
Bored_split	EQU	80h	;
Hunger_split	EQU	80h	;
Sick_split	EQU	80h	;

;***************************************************************************

Random_age	EQU	30h	;at any age, below this number when a
;				random number is picked will cause him
;				to pull from the age 1 table. More Furbish.

;****************************************************************************

Learn_chg	EQU	31	;amount to inc or dec training of words
;------------------------------------
Food		EQU	20h	;amount to increase 'Hungry' for each feeding
Need_food	EQU	80h	;below this starts complaining about hunger
Sick_reff	EQU	60h	;below this starts complaining about sickness
Really_sick	EQU	C0h	;below this only complains about sickness
Max_sick	EQU	80h	;cant go below this when really sick

Hungry_dec	EQU	01	;subtract X amount for each sensor trigger
Sick_dec	EQU	01	;subtract X amount for each sensor trigger
;------------------------------------
Nt_word		EQU	FEH	;turn speech word active off
Nt_last		EQU	FBH	;bit 2 off - last word sent to TI
;;; page 012 end
;;; page 013 start complete
Nt_term		EQU	F7h	;bit 3 off -terminator to speech TI
Clr_spch	EQU	FCH	;clears spch_activ & word_activ
CTS_lo		EQU	FDH	;makes TI_CTS go lo
;--------
Motor_rev	EQU	FDH	;clears motor fwd bit
Motor_inactv	EQU	FEh	;kill motor activ bit
Motor_ntseek	EQU	FBh	;kill motor seek bit
Motor_off	EQU	C0h	;turns both motor lines off (hi)
Motor_revs	EQU	7FH	;bit 7 lo
Motor_fwds	EQU	BFh	;bit 6 lo
Ntmot_on	EQU	DFh	;clears motor pulse on req
Nt_IRQdn	EQU	F7h	;clear IRQ stat
Nt_Motor_led	EQU	DFh	;motor opto lef off
Motor_led_rst	EQU	100	;X * 2.9 millSec for shut off time

Nt_Init_motor	EQU	FBh	;cks motor speed only on wake up
Nt_Init_Mspeed	EQU	F7H	;clears 2nd part of motor speed test

Opto_spd_reld	EQU	80	;number of IRQ to count opto pulse speed
Speed_reff	EQU	30	;value to adject speed to

Nt_macro_actv	EQU	7Fh	;clears request

Not_bside	EQU	F7h	;clear ball side done flag
Not_binvert	EQU	EFh	;clear ball invert done flag
Not_tch_bk	EQU	BFh	;clear touch back sense done flag
Not_tch_ft	EQU	DFh	;clear touch back sendse done flat
Not_feed	EQU	FDh	;clear feed sense done flag
Sound_reload	EQU	05	;X & 742 milisec time between trigger
Snd_cycle_rled	EQU	02	;sound sense referrence cycle timer
;--------
Light_reload	EQU	07	;X * 742 millsec until new reff level set
;--------
Nt_Slot_dn	EQU	FEh	;clr IR slot low detected

Nt_lt_reff	EQU	EFh	;turns reff off
Nt_lght_stat	EQU	FEh	;clears light-bright status to dim status

;;; Bright & Dim equates have been moved to the light include file/

;;;Bright	EQU	05	;light sensor trigger > reff level
;;;Dim		EQU	05	;Light sensor trigger < reff level

;--------
;Qik_snd_reload	EQU	01	;
;Nt_end_reff	EQU	DFh	;kill sound reff level bit
Nt_do_snd	EQU	FEh	;clears sound state change req
Nt_snd_stat	EQU	FBh	;clears Sound_stat
;--------
Nt_fortune	EQU	FEh	;kills fortune telller mode
Nt_Rap		EQU	FDh	;kills Rap mode
Nt_hideseek	EQU	FBh	;kills Hide & seek game mode
Nt_simon	EQU	F7h	;kills simon say game mode
;--------
Nt_do_tummy	EQU	F7h	;clears sensor change req
Nt_do_back	EQU	EFh	;clears sensor change req
Nt_do_feed	EQU	DFh	;clears sensor change req
Nt_do_tilt	EQU	BFh	;clears sensor change req
Nt_do_invert	EQU	7Fh	;clears sensor change req
Nt_do_lt_brt	EQU	FDh	;clears sensor change req
;;; page 013 end
;;; page 014 start complete
Nt_do_lt_dim	EQU	FBh	;clears sensor change req
;--------
Nt_temp_gam1	EQU	FEh	;clears game mode bits
Nt_half_age	EQU	BFh	;clears req for 2 table instead of 4
Nt_randm	EQU	7Fh	;clears random/sequential status

GameT_reload	EQU	24	; 1= 752 mSEC ;; 266 = 189.3 seconds

;+-------------------------------------------------+
;| Variable definition       (Ram = $80 to $FF)
;+-------------------------------------------------+
;Rdef

;***** DO NOT CHANGE RAM ASSIGNMENTS (X pointer used as offset)

;************* The next group of RAM locations can be used by any
;              sensor routine byt cannot be used to save data.
;              TEMP ONLY!
;***************** koball
TEMP0		EQU	80h
TEMP1		EQU	81h
TEMP2		EQU	82h
TEMP3		EQU	83h
TEMP4		EQU	84h
IN_DAT		EQU	85h
;****************** end koball
;* END TEMP TAM ************


Task_ptr	EQU	86h	;what function is in process
Port_A_image	EQU	87h	;
Port_B_Image	EQU	88h	;output port image
Port_D_Image	EQU	89h	;outout port image
;-------
Word_lo		EQU	8Ah	;speech word lo adrs
Word_hi		EQU	8Bh	;  "     "   hi "
Saysent_lo	EQU	8Ch	;saysent word pointer
Saysent_hi	EQU	8Dh	;
Bank_ptr	EQU	8Eh	;which bank words are in
Which_word	EQU	8Fh	;which word or saysent to call
Sgroup		EQU	90h	;which setsent grouyp table
Tx_data		EQU	91h	;
;-------
Which_motor	EQU	92h	;holds table number of motor position
Mgroup		EQU	93h	;which motor group table
Motor_lo	EQU	94h	;
Motptr_lo	EQU	95h	;table ponter to get motor position
Motptr_hi	EQU	96h	;
Which_delay	EQU	97h	;how much time between motor calls
Intt_Temp	EQU	98h	;
Drift_fwd	EQU	99h	;time motor reverses to stop drift
Drift_rev	EQU	9Ah	;
Pot_timeL	EQU	9Bh	;motor uses to compare against current position

; moved to hi ram that is not cleared on power up
;Pot_timeL2

Moff_len	EQU	9Ch	;holds motor power off pulse time
Mon_len		EQU	9Dh	;holds motor power on pulse time
Motor_pulse1	EQU	9Eh	;motor pulse timer
Slot_vote	EQU	9Fh	;need majority cnt to declaare a valid slot
;;; page 014 end
;;; page 015 start complete; more low ram A0-C7
Motor_led_timer	EQU	A0h	;how long after motion done led on for IR
Mot_speen_cnt	EQU	A1h	;motor speed test
Mot_opto_cnt	EQU	A2h	; "
Cal_switch_cnt	EQU	A3h	;used to eliminate noisy reds
motorstoped	equ	A4h	;times wheel count when stopping
Drift_counter	EQU	A5h	;decides how mich braking pulse to apply
;--------
Mili_sec		EQU	A6h	;used in cacl pot position by timer
Cycle_timer	EQU	A7h	;bypasses intt port c updates to motor
Sensor_timer	EQU	A8h	;times between sensor trigger
Bored_timer	EQU	A9h	;time with no activity to random speech
;--------
Invert_count	EQU	AAh	;which speech/motor call is next
Tilt_count	EQU	ABh	;which speech/motor call is next
Tchfrnt_count	EQU	ACh	;which speech/motor call is next
Tchbck_count	EQU	ADh	;which speech/motor call is next
Feed_count	EQU	AEh	;which speech/motor call is next
;--------
Last_IR		EQU	AFh	;last IR sample data to compare to next
Wait_time		EQU	B0h	;used in IRQ to create 2.8 mSec timers
;--------
Light_timer	EQU	B1h	;Light sensor routines
Light_count	EQU	B2h	;which speech/motor call is next
Light_reff	EQU	B3h	;holds previoys sample
;---------------
Sound_timer	EQU	B4h	;time to set new reff level
Sound_count	EQU	B5h	;which speech motor/call is next
;---------------
Milisec_flag	EQU	B6h	;set every 742 miliseconds
Macro_Lo		EQU	B7h	;table pointer
Macro_Hi		EQU	B8h	;  "     "
Egg_cnt		EQU	B9h	;easter egg table count pointer

;*************************** Koball code rev B

HCEL_LO		EQU	BAh	;
HCEL_HI		EQU	BBh	;
BIT_CT		EQU	B9h	;

;*************************** end Koball

Light_shift	EQU	BDh	;(was TMA_INT ) used for threshold change

;***************************

Prev_random	EQU	BEh	;prevents rnadom number twice in a row
Bored_count	EQU	BFh	;sequential selection for bored table
TEMP5		EQU	C0h	;general use also used for wake up

Temp_ID2		EQU	C1h	;used in sensor training routine
Temp_ID		EQU	C2h	;used in sensor training routine
Learn_temp	EQU	C3h	;used in sensor training routine

Req_macro_lo	EQU	C4h	;holds last call to see if sleep of IR req
Req_macro_hi	EQU	C5h	;

Sickr_count	EQU	C6h	;sequential counter for sick speech table
Hungr_count	EQU	C7h	;sequential counter for hunger speech table
;;; page 015 end
;;; page 016 start complete; more low ram C8-CD
Motor_pulse2	EQU	C8h	;motor pulse timer

;***** DO NOT CHANGE BIT ORDER *****

Stat_0		EQU	C9h	;system status
Want_name		EQU	01H	;bit 0 =set forces system to say Furby's name
Lt_prev_dn	EQU	02H	;bit 0 = done flat for quick light changes
Init_motor	EQU	04h	;bit 1 = on wakeup do motor speed/batt test
Init_Mspeed	EQU	08h	;bit 3 = 2nd part of motor speed test
Train_Bk_prev	EQU	10H	;bit 4 = set when 2 back sw hit in a row
Say_new_name	EQU	20H	;bit 5 = only happens of cold boot
REQ_dark_sleep	EQU	40H	;bit 6 = set -dark level sends to sleep
Dark_sleep_prev	EQU	80H	;bit 7 = if set on wake up thendont gotosleep
;
Stat_1		EQU	CAH	;system status
Word_activ	EQU	01H	;bit 0 = set during any speech
Say_activ		EQU	02H	;bit 1 = when saysent is in process
Word_end		EQU	04H	;bit 2 = set when sending FF word end to TI
Word_term		EQU	08H	;bit 3 = set to send 3 #ffh to end speech
Up_light		EQU	10H	;bit 4 =set when shigt in incrmntg
Snd_reff		EQU	20H	;bit 5 = set for new referrenc cycle
Half_age		EQU	40H	;bit 6 = set for 2 tables of age instead of 4.
Randm_sel		EQU	80H	;bit 7 =decides random/sequential for tables

Stat_2		EQU	CBH	;system status more
Motor_actv	EQU	01H	;bit 0 = set = motor in motion
Motor_fwd		EQU	02H	;bit 1 = set=rwd clr=rev
Motor_seek	EQU	04H	;bit 2 = seeking to next position
Bside_dn		EQU	08H	;bit 3 = ste = previously flaged
Binvrt_dn		EQU	10H	;bit 4 = set- prev done
Tchft_dn		EQU	20H	;bit 5 =  "    "
Tchbk_dn		EQU	40H	;bit 6 =  "    "
Macro_actv	EQU	80H	;bit 7 =set when macro in process

Stat_3		EQU	CCH	;system status
Lght_stat		EQU	01H	;bit 0 = set=bright clr = dim
Feed_dn		EQU	02H	;bit 1 = set- prev done
Sound_stat	EQU	04H	;bit 2 =  "    "
IRQ_dn		EQU	08H	;bit 3 = set when IRQ occurs by IRQ
Lt_reff		EQU	10H	;bit 4 =set for light sense reff cycle
Motor_on		EQU	20H	;bit 5 = set=motor pulse power on
M_forward		EQU	40H	;bit 6 =clr = move motor forward
M_reverse		EQU	80H	;bit 7 =clr = move motor reverse

Stat_4		EQU	CDH	;system task request state
Do_snd		EQU	01H	;bit 0 = set when source > prev reff level
Do_lght_brt	EQU	02H	;bit 1 = set when light > prev reff level
Do_lght_dim	EQU	04H	;bit 2 = set when light < prev reff level
Do_tummy		EQU	08H	;bit 3 = set when front touch triggered
Do_back		EQU	10H	;bit 4 = set when back touch triggered
;;; page 016 end
;;; page 017 start complete; more low ram CE-D9
Do_feed		EQU	20H	;bit 5 = set when feed sensor triggered
Do_tilt		EQU	40H	;bit 6 = set when tilt sensor triggered
Do_invert		EQU	80H	;bit 7 = set when inverted sensor triggered

Stat_5		EQU	CEH	;game statue
temp_gam1		EQU	01H	;bit 0 =used in game play
temp_gam2		EQU	02H	;bit 1 = "   "      "    "
temp_gam3		EQU	05H	;bit 2 =
temp_gam4		EQU	08H	;bit 3 =
temp_gam5		EQU	10H	;bit 4 =
temp_gam6		EQU	20H	;bit 5 =
temp_gam7		EQU	40H	;bit 6 =
temp_gam8		EQU	80H	;bit 7 =

Game_1		EQU	CFh	;system game status
Fortune_mode	EQU	01H	;bit 0 =set = furby in fortune teller mode
Rap_mode		EQU	02H	;bit 0 =set = furby in RAP SONG mode
Hideseek_mode	EQU	04H	;bit 1 =set = furby in hide & seek game
Simonsay_mode	EQU	08H	;bit 3 =set = furby in simon says game mode
Burp_mode		EQU	10H	;bit 4 =set = mode
Name_mode		EQU	20H	;bit 5 =
Twinkle_mode	EQU	40H	;bit 6 =
Rooster_mode	EQU	80H	;bit 7 =

Qualify1:		EQU	D0h	;easter egg disqualified when clear
DQ_fortune	EQU	01h	;bit 0 = fortune teller
DQ_rap		EQU	02h	;bit 1 = rap song
DQ_hide		EQU	04h	;bit 2 = hide and seek
DQ_simon		EQU	08h	;bit 3 = simon says
DQ_burp		EQU	10h	;bit 4 = burp attacj
DQ_name		EQU	20h	;bit 5 = says his name
DQ_twinkle	EQU	40h	;bit 6 = sings sond
DQ_rooster	EQU	80h	;bit 7 = rooster loves you
;

; ********** THIS GROUP OF RAM IS SAVED IN EEPROM



; Need to read these from EEPROM and do test for false data

; "age" uses bit 7 to extend the "age_counter" to 9 bits, and this
; is saved in EEPROM also.

; "AGA" MUST BE IN D1h BECAUSE EEPROM READ & WRITE USE THE EQU FOR START RAM.

Age		EQU	D1h	;age = 0-3 (4 total)
Age_counter	EQU	D2h	;inc on motor action,rollos over & inc age

Name		EQU	D3h	;holds 1-6 pointer to firby's name
Rvoice		EQU	D4h	;which one of three voices
Pot_timeL2	EQU	D5h	;counter from wheel I.R. sensor
Hungry_counter	EQU	D6H	;holds hungrey/full counter
Sick_counter	EQU	D7h	;healthy/sick counter
Seed_1		EQU	D8h	;only seed 1 & seed 2 are saved
Seed_2		EQU	D9h	; "    "    "

; There are used for training each sensor. There is a word number which
;;; page 017 end
;;; page 018 start complete; more low ram DA-F0h; stack EA-FF
; is 1-16 for the sesnor table macro list and a ram for count which
; determines how often to call the learned word.

; ** DO NOT CHANGE ORGER----- RAM adrs by Xreg offset

Tilt_learned	EQU	DAh	;which word trained                 1
Tilt_lrn_cnt	EQU	DBh	;count determines how often called  2

Feed_learned	EQU	DCh	;which word trained                 3
Feed_lrn_cnt	EQU	DDh	;count determines how often called  4

Light_learned	EQU	DEh	;which word trained                 5
Light_lrn_cnt	EQU	DFh	;count determines how often called  6

Dark_learned	EQU	E0h	;which word trained                 7
Dark_lrn_cnt	EQU	E1h	;count determines how often called  8

Front_learned	EQU	E2h	;which word trained                 9
Front_lrn_cnt	EQU	E3h	;count determines how often called  10

Sound_learned	EQU	E4h	;which word trained                 11
Sound_lrn_cnt	EQU	E5h	;count determines how often called  12

Wake_learned	EQU	E6h	;which word trained                 13
Wake_lrn_cnt	EQU	E7h	;count determines how often called  14

Invert_learned	EQU	E8h	;which word trained                 15
Invert_lrn_cnt	EQU	E9h	;count determines how often called  16

; next is equates defining which ram to use for each sensor
; according to the sensor ram defined aboive. (compare to numbers above)

Tint_ID		EQU	00	;defines what offset for above ram definitions
Feed_ID		EQU	02	; "
Light_ID		EQU	04	; "
Dark_ID		EQU	06	; "
Front_ID		EQU	08	; "
Sound_ID		EQU	10	; "
Wake_ID		EQU	12	; "
Inver_ID		EQU	14	; "
Back_ID		EQU	EEh	;special value triggers learn mode

;*******************************************************************************
; For power on test, WE only clear ram to E9h and use EAh for a
; messanger to the warm boot routine. We always clear ram and initialize
; registers on power up, but if it is a warm boot then read EEPROM
; and setup ram locations. Location EAH is set of cleared during power up
; and then the stack can use it during normal run.


Warm_cold		EQU	EDh	;
Spc1_seed1	EQU	EEh	;
Spc1_seed2	EQU	EFh	;
Deep_sleep	EQU	F0h	;0-no deep sleep 11h is. (tilt wont wakeup)

;*************** Need to allow stack growth down (EAh- FFH ) ******************
;;; page 018 end
;;; page 019 start complete
Stacktop	EQU	FFH	;Stack Top


;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************


	ORG	00H
	BLKW	300H, 00H	; Fill 0000 --- 05FFH = 00

;+---------------------------------------------------------+
;|                                                         |
;|     P R O G R A M    S T A R T S   H E R E              |
;|                                                         |
;+---------------------------------------------------------+

	ORG	0600H

RESET:

    Include Wake2.asm


;******* end Tracker



; For power on test, WE only clear ram to E9H and use EAh for a
; messenger to the warm boot routine. We always clear ram and initialize
; registers on power up, but if it is a warm boot then read EEPROM 
; and setup ram locations. Location EAH is set of cleared durinbg power up
; and the the stack can use it during normal run.

; Clear RAM to 00H
; ------------------------------------------------------------------------------

	LDA	#00H		; data for fill
	LDX	#E9H		; start ar ram location

RAMClear:
	STA	00,X		; base 00, offset x
	DEX			; next ram location
	CPX	#7FH		; check for end
	BNE	RAMClear	; branch, not finished
				; fill done
;;; page 019 end
;;; page 020 start complete
Main:

InitIO:
	LDA	#01		; turn DAC on
	STA	DAC_ctrl	; DAC control

	LDA	#Port_def	;set direction contol
	STA	Ports_dir	;load reg

	LDA	#Con_def	;set configuration
	STA	Ports_con	;load reg

	LDA	#00		;set for bank 0
	STA	Bank		;set it
	LDA	#00H		;disable wakeup control
	STA	Wake_up
	LDA	#00h		;disable sleep control
	STA	Sleep		;set dont care

	LDA	#Intt_dflt	;Initiaze timer, etc.
	STA	Interrupts	;load req

	LDA	#00H		;set timer mode
	STA	TMA_CON		;set req
	LDA	#TimeA_low	;get preset timer for interrupts
	STA	TMA_LSB		;load

	LDA	#TimeA_hi	;get hi byte for preset
	STA	TMA_MSB		;load it

	LDA	#TimeB_low	;get preset timer for interrupts
	STA	TMB_LSB		;load

	LDA	#TimeB_hi	;get hi byte for preset
	STA	TMB_MSB		; load it

	LDA	#C0h		;preset status for motors off
	STA	Stat_3

	LDA	#00H		;init ports
	STA	Port_A		;output

	LDA	#33H		;init ports
	STA	Port_B_Image	;ram image
	STA	Port_B		;output

	LDA	#0FH		;init ports
	STA	Port_C		;output

	LDA	#D0H		;init ports
	STA	Port_D_Image	;ram image
	STA	Port_D		;output

	LDA	#FFh		;millisec fimer reload value
	STA	Mili_sec	;also preset IRQ timer

	CLI			;Enable IRQ
;;; page 020 end
;;; page 021 start complete
	JSR	Kick_IRQ		;wait for interrupt to restart

	JSR	TI_reset		;go init TI (uses 'Cycle_timer')

; Preset motor speed, assuming mid battery life, we set the pulse witdh
; so that the motor wont be running at 6 volts and burn out. We then
; predict what the pulse width should be for any voltage.

;	LDA	#Mpulse_on	;preset motor speed
	LDA	#11
	STA	Mon_len		;set motor on pulse timing

	LDA	#05		;
	STA	Moff_len		;ste motor off pulse timing

;-------------------------------------------------------------------------------
;| Diagnostics and calibration Routine
;-------------------------------------------------------------------------------


   Include Diag7.asm


; ****** Only called by diagnostic speech routines ********

; Be sure to set 'MACRO_HI' and all calls are in the 128 byte block.

Diag_macro:
	STA	Macro_Lo		;save lo byte of Macro table entry
	  LDA	     $0b8h	;max offset to adrs 400 added to diag call
	CLC
	ADC	Macro_Lo		;add in offset
	STA	Macro_Lo		;update
	LDA	#01		;get hi byte adrs 400 = 190h
	STA	Macro_Hi		;save hi byte of Macro table entry
	JSR	Get_macro		;get start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor
	RTS			;yo !


; Enter with Areg holding how may 30 mili second delay cycles

Half_delay:
	STA	TEMP1		;save timer
Half_d2:
	LDA	#19		;set 1/2 sec   (y * 2.9 mSec)
	STA	Cycle_timer	;set it
Half_d3:
	LDA	Cycle_timer	;ck if done
	BNE	Half_d3		;loop
	DEC	TEMP1		;
	BNE	Half_d2		;loop
	RTS			; done
;;; page 021 end
;;; page 022 start complete
Test_byp:		;We assume diagnostic only run on coldboot


;*******************************************************************************

	LDA	#FFh		;Initialize word training variables
	STA	Temp_ID		;

	LDA	#FFh		;
	STA	Hungry_counter	;preset funby's health
	STA	Sick_counter

;*******************************************************************************

; We set here and wait for tilt to go away, and just keep incrementing
; count until it does, This becomes the new random generator seed.

Init_rnd:
	INC	TEMP1		;random counter
	LDA	Port_D		;get switches
	AND	#03		;check tile & invert sw
	BNE	Init_rnd		;loop tol gone
	LDA	TEMP1		;get new seed
	STA	Spc1_seed1	;stuff it
	STA	Seed_1		;also load for cold boot

;*******************************************************************************

; Use feed sw to generate a better random number

	JSR	Get_feed		;go test sensor
	LDA	Stat_4		;get system
	AND	#Do_feed		;ck sw
	BNE	Feed_rnd		;if feed sw then cold boot
	JMP	End_coldinit	;else do warm boot
Feed_rnd:
	INC	TEMP1		;random counter
	LDA	Stat_4		;system
	AND	#DFh		;clear any prev feed sw sense
	STA	Stat_4		;update
	JSR	Get_feed		;go teet sensor
	LDA	Stat_4		;get system
	AND	#Do_feed		;ck sw
	BNE	Feed_rnd		;wait for feed to go away
	LDA	TEMP1		;get new seed
	STA	Spc1_seed1	;stuff it
	STA	Seed_1		;also load for cold boot

;*******************************************************************************

;; IF this is a coold boot , reset command then clear EEPROM and
;  chose a new name and voice/

Do_cold_boot:

	LDA	#00
	STA	Warm_cold		;flag cold boot
;;; page 022 end
;;; page 023 start complete
	LDA	Stat_0		;system
	ORA	#Say_new_name	;make system say new name
	STA	Stat_0		;

;******  NOTE ::::::
;
;  VOICE AND NAME SLECTION MUST HAPPEN BEFORE EEPROM WRITE OR
;  THEY WILL ALWAYS COME UP  00    because ram just got cleared!!!!!!

; Random voice selection here

	LDA	#80h		;get random/sequential shift
	STA	IN_DAT		;save for random routine

	LDX	#00		;make sure only gives random
	LDA	#10h		;get number of random selection
	JSR	Ran_seq		;go get random selection

	TAX
	LDA	Voice_table,X	;get new voice
	STA	Rvoice		;set new voice pitch

;*******************************************************************************



; On power up or reset. Furby must go select a new name ,,, ahw how cute

	JSR	Random
	AND	#1Fh		;get 32 possible
	STA	Name		;set new name pointer
	JSR	Do_EE_write	;write the EEPROM

End_coldinit:


;-------------------------------------------------------------------------------
;|  Special initialization prior to normal run mode
;|  Jump to Warm_boot when portD wakes us up
;-------------------------------------------------------------------------------

Warm_boot:	;normal stat when Port_D wakes us up.

	JSR	S_EEPROM_READ	;read data to ram

;Eprom_read_byp:

;******************************************************************************* ; If lighjt osc fails, or too dark and sends us to sleep, we
; set 'Dark_sleep_prev' and save it in EEPROM in 'Seed_2',
; when the sleep routine executes, (00 01 based on this but)
; When we wake up we recover this bit and it becomes the previous done
; flag back in 'Stat_0', so that if the osc is
;;; page 023 end
;;; page 024 start complete
; still dark or failed, Furby wont go back to sleep.

	LDA	Seed_2		;from EEPROM
	BEQ	No_prevsleep	;jump if none
	LDA	Stat_0
	ORA	#Dark_sleep_prev	;prev done
	STA	Stat_0		;update

No_prevsleep:

;*******************************************************************************


	LDA	Spc1_seed1	;revover start up random number
	STA	Seed_1		;set generator

;*******************************************************************************


; Pot_timeL2 is save in ram throught sleep mode and then reloaded
; Pot_timeL which is teh working register for the motor postion
; This allows startup routines to clear ram without forgetting the
; last motor position.

	LDA	Pot_timeL2	;get current count
	STA	Pot_timeL		;save in motor routine counter

;***********************

; Get age and make sure it is not greater them 3 (age 4)

	LDA	Age		;get current age
	AND	#83h		;preserve bit 7 which is 9th age counter er bit
;;;;                                     and insure age not >3

	STA	Age		;set system

;***********************

	LDA	#Bored_reld	;reset timer
	STA	Bored_timer	;


	LDA	#03		;set timer
	STA	Last_IR		;timer stops IR from hearing own IR_xmit


	JSR	Get_light		;go get light level sample
	LDA	TEMP1		;get new count
	STA	Light_reff	;update system

;*******************************************************************************

	LDA	Warm_cold		;decide if warm or cold boot
	CMP	#11h		;ck for warm boot
	BEQ	No_zero		;jump if is
;;; page 024 end
;;; page 025 start complete
	LDA	#00		;point to macro 9 (SENDS TO SLEEP POSITION)
	STA	Macro_Lo
	STA	Macro_Hi
	JSR	Get_macro		;go start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor

No_zero:

	LDA	#11		;preset motor speed
	STA	Mon_len		;set motor on pulse timing

	LDA	#05		;set motor to 3/4 speed for speed test
	STA	Moff_len		;set motor off pulse timing
;
;
	LDA	#00		;clear all system sensor requests
	STA	Stat_4		;update


;  Currently uses 4 tables, one for each age.

	LDA	Stat_0		;system
	ORA	#Init_motor	;flag motor to do speed test
	ORA	#Init_Mspeed	;2nd part of test
	STA	Stat_0		;update

;*******************************************************************************

; Do wake up routine

	lda	#Global_time	;reset timer to trigger sensor learning
	STA	Sensor_timer	;

	LDA	#80h		;get random/sequential split
	STA	IN_DAT		;save for random routine

	LDX	#00h		;make sure only gives random
	LDA	#10h		;get number of random selections
	JSR	Ran_seq		;go get random selection
	LDA	TEMP1		;get decision

	STA	IN_DAT		;save decision
	LDA	#Wake_ID		;which ram location for learned word count (offset)
	JSR	Start_learn	;go record training info
	LDA	IN_DAT		;get back word to speak

	JSR	Decid_age		;do age calculation for table entry
	LDX	TEMP0		;age offset
	LDA	Wakeup_S1,X	;get new sound/word
	STA	Macro_Lo		;more lo byte of Macro table entty
	INX
	LDA	Wakeup_S1,X	;get new sound/word
	STA	Macro_Hi		;more hi byte of Macro table enttyi
	JMP	Start_macro	;go start search

;*******************************************************************************
;;; page 025 end
;;; page 026 start complete
;-------------------------------------------------------------------------------
;| IDLE Routine
;-------------------------------------------------------------------------------

Idle:

; Idle routine is the time slace task master (TSTM) ugh!
; We must call each routine and interleave wait a call to speech
; tp insure we never miss a TI request for data.

	JSR	Notrdy	;Do / get  status for speech and motor


;*******************************************************************************
; THis bit is set when light sensor is darker then 'Dark_sleep'

	LDA	Stat_0		;system
	AND	#REQ_dark_sleep	;ck for req
	BEQ	No_dark_req	;if not

	LDA	Stat_0		;system
	AND	#BFh		;kill req
	STA	Stat_0		;update

	LDA	#A6h		;sleep macro
	STA	Macro_Lo
	LDA	#00h		;sleep macro
	Sta	Macro_Hi		;
	JMP	Start_macro	;got say it



No_dark_req:

;*******************************************************************************

; When any sensor or timer calls the "start_macro" routine, the
; Macro_Lo & Macro_Hi are saved. Everyone jumps back to Idle and when
; speech/motor routines are finished, this routine will look at the
; macros that were used and execute another function if a match is found.
;
; Checks for his name first, then any IR to send, and finally, the sleep
; commands. TH e temp macro buffers are cleared before


;
Spc1_Name1:
	LDX	#00		;offset
Spc1_Name2:
	LDA	Ck_Name_table,X	;ck lo byte
	CMP	#FFh		;ck for end of talbe (note 255 cant execute
	BEQ	Spc1_IR1		;done if is
	CMP	Req_macro_lo	;ck against last speech request
	BNE	Not_Name2		;jump of not
	INX			;to hi byte
	LDA	Ck_Name_table,X	;ok hi byte
	CMP	Req_macro_hi	;ck against last speech request
;;; page 026 end
;;; page 027 start complete
	BNE	Not_Name3		;jump if not
	JMP	Say_Sname		;speak it
Not_Name2:
	INX			;
Not_Name3:	
	INX			;
	JMP	Spc1_Name2	;loop til done

Say_Sname:
	LDA	Stat_0
	AND	#DFh		;kill req for startup new name
	STA	Stat_0		;update

	LDA	Name		;current setting for table offset
	CLC
	ROL	A		;2's comp
	TAX
	LDA	Name_table,X	;got lo byte
	STA	Macro_Lo		;save lo byte of Macro table entry
	INX
	LDA	Name_table,X	;got hi byte
	STA	Macro_Hi		;save hi byte of Macro table entryi
	JSR	Get_macro		;go start notor/speech
	JSR	Notrdy		;Do / get  status for speech and motor
;
Spc1_IR1:
	LDX	#00		;offset
Spc1_IR2:
	LDA	IRxmit_table,X	;ck lo byte
	CMP	#FFh		;ck for end of table (note 255 cant execute)
	BEQ	Spc1_IR_dn	;done if is
	CMP	Req_macro_lo	;ck against last speech request
	BNE	Not_IRxmit2	;jump if not
	INX			;to hi byte
	LDA	IRxmit_table,X	;ck hi byte
	CMP	Req_macro_hi	;ck against last speech request
	BNE	Not_IRxmit3	;jump if not
	INX			;point to IR table
	LDA	IRxmit_table,X	;
	STA	TEMP2		;xmit temp ram
	LDA	#FDh		;TI command for IR xmit
	STA	TEMP1
	JSR	Xmit_TI		;go send it

	LDA	#Bored_reld	;reset bored timer
	STA	Bored_timer	;

	LDA	#03		;set timer
	STA	Last_IR		;timer stops OR from hearing its own IR xmit

	JMP	Spc1_IR_dn	;done - ole ........
Not_IRxmit2:
	INX			;lo byte
Not_IRxmit3:
	INX			;hi byte
	INX			;xmit pointer
	JMP	Spc1_IR2		;loop to done
Spc1_IR_dn:
;
;;; page 027 end
;;; page 028 start complete
;
Spc1_macro1:
	LDX	#00		;offset
Spc1_sleep1:
	LDA	Sleepy_table,X	;ck lo byte
	CMP	#FFh		;ck for end of table (note 255 cant execute)
	BEQ	Ck_macro_dn	;done if is
	CMP	Req_macro_lo	;ck againist last speech request
	BNE	Not_sleepy2	;jump it not
	LDA	#00		;clear macro pointers for wake up
	STA	Req_macro_lo
	STA	Req_macro_hi

;mod F-rels2 :
;    Before going to sleep send sleep cmnd to all others.

	LDA	#15		;
	STA	TEMP2		;xmit temp ram
	LDA	#FDh		;TI command for IR xmit
	STA	TEMP1		;
	JSR	Xmit_TI		;go send it

;need to wait >600 milisec before going to sleep because we arent using
;busy flags from TT and need fo make sure is is done transmittng the
;I.R. code, the sleep routine kills the TI and it would never send the cmnd.

	LDA	#15		;how many 30 milisec cycles to call
	JSR	Half_delay	;do 30milisec delay cycles

;end mod

	JMP	GoToSleep	;nity-night

Not_sleepy2:
	INX			;
Not_sleepy3:
	INX			;
	JMP	Spc1_sleep1	;loop til done
;
Ck_macro_dn:
	LDA	#00		;clear macro pointers for wake up
	STA	Req_macro_lo
	STA	Req_macro_hi
	JMP	Test_new_name	;on to task master
;

;;;;;;;; SLEEP TABLE & IR table ..... MOVE TO INCLUDE FILE LATER

Sleepy_table:
	DW	91	;hangout

	DW	166	;wake up
	DW	167	;wake up
	DW	168	;wake up
	DW	169	;wake up
;;; page 028 end
;;; page 029 start complete
	DW	258	;Back sw
	DW	259	;Back sw
	DW	260	;Back sw

	DW	403	;IR
	DW	413	;IR
	DW	429	;IR

	DB	FFh,FFh	;FF FF is table terminator

IRxmit_table:
	DW		;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	13	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	17	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	19	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	26	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	29	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	33	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	34	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	44	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	45	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	48	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	50	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	55	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	60	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	149	;from rooster wake up
	DB	00	;


	DW	352	;trigger macro
	DB	01	;which IR command to call (0 - 0f)
	DW	363	;trigger macro
	DB	01	;which IR command to call (0 - 0f)
	DW	393	;trigger macro
	DB	01	;which IR command to call (0 - 0f)

	DW	248	;trigger macro
	DB	02	;which IR command to call (0 - 0f)
	DW	313	;trigger macro
	DB	02	;which IR command to call (0 - 0f)

	DW	86	;trigger macro
	DB	03	;which IR command to call (0 - 0f)
	DW	93	;trigger macro
	DB	03	;which IR command to call (0 - 0f)
	DW	339	;trigger macro
	DB	00	;which IR command to call (0 - 0f)
	DW	60	;trigger macro
;;; page 029 end
;;; page 030 start complete
	DB	03	;which IR command to call (0 - 0f)
	DW	344	;trigger macro
	DB	03	;which IR command to call (0 - 0f)
	DW	351	;trigger macro
	DB	03	;which IR command to call (0 - 0f)

	DW	404	;trigger macro
	DB	04	;which IR command to call (0 - 0f)
	DW	405	;trigger macro
	DB	04	;which IR command to call (0 - 0f)

	DW	293	;trigger macro
	DB	05	;which IR command to call (0 - 0f)
	DW	394	;trigger macro
	DB	05	;which IR command to call (0 - 0f)
	DW	406	;trigger macro
	DB	05	;which IR command to call (0 - 0f)
	DW	414	;trigger macro
	DB	05	;which IR command to call (0 - 0f)
	DW	422	;trigger macro
	DB	05	;which IR command to call (0 - 0f)

	DW	395	;trigger macro
	DB	06	;which IR command to call (0 - 0f)
	DW	421	;trigger macro
	DB	06	;which IR command to call (0 - 0f)
	DW	423	;trigger macro
	DB	06	;which IR command to call (0 - 0f)

	DW	296	;trigger macro
	DB	07	;which IR command to call (0 - 0f)
	DW	415	;trigger macro
	DB	06	;which IR command to call (0 - 0f)
	DW	416	;trigger macro
	DB	07	;which IR command to call (0 - 0f)

	DW	288	;trigger macro
	DB	08	;which IR command to call (0 - 0f)

	DW	11	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	12	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	27	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	42	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	57	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	235	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	237	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	238	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	261	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	262	;trigger macro
;;; page 030 end
;;; page 031 start complete
	DB	09	;which IR command to call (0 - 0f)
	DW	396	;trigger macro
	DB	09	;which IR command to call (0 - 0f)
	DW	409	;trigger macro
	DB	09	;which IR command to call (0 - 0f)


	DW	399	;trigger macro
	DB	10	;which IR command to call (0 - 0f)
	DW	407	;trigger macro
	DB	10	;which IR command to call (0 - 0f)
	DW	408	;trigger macro
	DB	10	;which IR command to call (0 - 0f)

	DW	272	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	273	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	274	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	275	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	400	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	418	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	425	;trigger macro
	DB	11	;which IR command to call (0 - 0f)
	DW	426	;trigger macro
	DB	11	;which IR command to call (0 - 0f)

	DW	336	;trigger macro
	DB	12	;which IR command to call (0 - 0f)
	DW	342	;trigger macro
	DB	12	;which IR command to call (0 - 0f)
	DW	401	;trigger macro
	DB	12	;which IR command to call (0 - 0f)


	DW	92	;trigger macro
	DB	13	;which IR command to call (0 - 0f)
	DW	411	;trigger macro
	DB	13	;which IR command to call (0 - 0f)
	DW	419	;trigger macro
	DB	13	;which IR command to call (0 - 0f)
	DW	427	;trigger macro
	DB	13	;which IR command to call (0 - 0f)

	DW	291	;trigger macro
	DB	14	;which IR command to call (0 - 0f)
	DW	402	;trigger macro
	DB	14	;which IR command to call (0 - 0f)
	DW	412	;trigger macro
	DB	14	;which IR command to call (0 - 0f)
	DW	428	;trigger macro
	DB	14	;which IR command to call (0 - 0f)

	DW	256	;trigger macro
	DB	15	;which IR command to call (0 - 0f)
	DW	257	;trigger macro
	DB	15	;which IR command to call (0 - 0f)
	DW	420	;trigger macro
;;; page 031 end
;;; page 032 start complete
	DB	15	;which IR command to call (0 - 0f)

;mod F-rels2 ; send sleep if recv sleep on IR

	DW	403	;trigger macro
	DB	15	;which IR command to call (0 - 0f)
	DW	213	;trigger macro
	DB	15	;which IR command to call (0 - 0f)
; end mod

	DB	FFH,FFH	;FF FF   is table terminator


Ck_Name_table:
	DW	97
	DW	248
	DW	393
	DW	414
	DW	149
	DW	305
	DW	404
	DW	421

	DB	FFH,FFH	;FF FF   is table terminator


;*******************************************************************************

; Say name

Test_new_name:

	LDA	Stat_0		;system
	AND	#Say_new_name	;make system say new name
	BEQ	Nosayname	;bypass if clear
	LDA	Stat_0
	AND	#FDh		;kill req for startup new name
	STA	Stat_0		;update

	LDA	Name		;current setting for table offset
	CLC
	ROL	A		;2's comp
	TAX
	LDA	Name_table,X	;get lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	INX
	LDA	Name_table,X	;get hi byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JSR	Get_macro
	JSR	Notrdy		;Do / get status for speech and motor

Nosayname:

;*******************************************************************************
;
;
; ***** below routines run at 742 mSec loops
; TImer B sets 'Milisec_flag each 742 miliseconds
;;; page 032 end
;;; page 033 start complete
Updt_timer:
	LDA	Milisec_flag	;if >0 then 742 mili seconds have passed
	BEQ	TimerL_dn	;bypass if 0
	LDA	#00		;clear it
	STA	Milisec_flag	;reset

	LDA	Sensor_timer	;get current timer * 742mSec sec
	BEQ	TimerL1		;do nothing if 0
	DEC	Sensor_timer	;-1
TimerL1:
	LDA	Light_timer	;get current timer *742mSec sec
	BEQ	TimerL2		;do nothing if 0
	DEC	Light_timer	;-1
TimerL2:
	LDA	Sound_timer	;get current timer *742mSec sec
	BEQ	TimerL3		;do nothing if 0
	DEC	Sound_timer	;-1
TimerL3:
	LDA	Bored_timer	;get current timer *742mSec sec
	BEQ	TimerL4		;do nothing if 0
	DEC	Bored_timer	;-1
TimerL4:
	LDA	Last_IR		;get current timer *742mSec sec
	BEQ	TimerL5		;do nothing if 0
	DEC	Last_IR		;-1
TimerL5:

TimerL_dn:

	INC	Task_ptr	;+1
	LDA	Task_ptr	;get it
	CLC
	SBC	#08		;chk if odd end
	BCC	Ck_tsk_A	;jump if <9
	LDA	#01		;reset pointer
	STA	Task_ptr	;

Ck_tsk_A:

; If too sick then no game play...

	CLC	
	LDA	Sick_counter	;how sick is he
	SBC	#Really_sick	;
	BCS	Ck_task_egg	;do egg it not
	JMP	Ck_bored	;bypass if too sick

; Scan all game mode pointers to determine if ant are active.
; Continue to execute the first active game found, and that game always
; allow the task list to be scaned for sensor input. If no games are
; active, then check task 0 to determine if the correct sensore sequence
; is occuring which will initiate the next game.

Ck_task_egg:

	LDA	Game_1		;get game active bits
	ROR	A		;move bit 0 to carry
	BCC	Ck_g2		;check next if not activ
;;; page 033 end
;;; page 034 start complete
	JMP	Game_fortune	;jump if active
Ck_g2:
	ROR	A		;bit 1
	BCC	Ck_g3		;check next if not activ
	JMP	Game_Rap	;jump if active
Ck_g3:
	ROR	A		;bit 1
	BCC	Ck_g4		;check next if not activ
	JMP	Game_hideseek	;jump if active
Ck_g4:
	ROR	A		;bit 1
	BCC	Ck_g5		;check next if not activ
	JMP	Game_simon	;jump if active
Ck_g5:
	ROR	A		;bit 1
	BCC	Ck_g6		;check next if not activ
	JMP	Game_Burp	;jump if active
Ck_g6:
	ROR	A		;bit 1
	BCC	Ck_g7		;check next if not activ
	JMP	Game_name	;jump if active
Ck_g7:
	ROR	A		;bit 1
	BCC	Ck_g8		;check next if not activ
	JMP	Game_twinkle	;jump if active
Ck_g8:
	ROR	A		;bit 1
	BCC	Ck_g9		;check next if not activ
	JMP	Game_rooster	;jump if active

Ck_g9:

;  none active
;
;;***************************


; Task 9 : scans all active requests from sensors looking for a trigger.
; If are are set then scan throigh the gamse slect tables for each game
; looking for a match, and increment the counter each time a successive
; match is found. If one is not in sequence, the tath counter is rest to
; zero. Since all counters are independent, then the first one to completion
; wins and all others are zeroed.
;
; All sensor triggers are in one status byte so we can create a number
; based on who has been triggerd (we ignore the I.R. sensor).
; The following but are in Stat_4 and are set when they are triggered
; by the indiviual sensor routines:

; 00 = none
; 01 = Loud sound
; 02 = Light change brighter
; 04 = Light change darker
; 08 = Front tummy switch
; 10 = Back switch
; 20 = Feed switch
; 40 = TIlt switch
;;; page 034 end
;;; page 035 start complete
; 8- Invert switch

; We assign a sibgle bit per game or egg scenario. Each time a
; sensor is triggered, we increment the counter and test all eggs for
; a match. If a particular sensor doesn't match, then set its disqualified
; bit and move on. If at any time all bits are ste, then clear counter ot
; zero and start over. WHen a table gets an FF then that egg is executed.
; Each time a sensor is trigger, the system timer is reset. This timer
; called 'Sensor_timer' is reset with 'Global_time' equate. This timer is also
; used for the random sequential selection of sensor responses. If this
; timer goes to zero before an egg is complete, ie. Furby has not been played
; with, then clear all disqualified bits and counters.

; Currently there are 24 possible eggs. (3 bytes)

;Qualify1:
;QO_fortune	EQU	01	;bit 0 = fortune teller
;DQ_rap		EQU	02	;bit 1 = rap song
;DQ_hide		EQU	04	;bit 2 = hide and seek
;DQ_simon		EQU	08	;bit 3 = simon says
;DQ_burp		EQU	10	;bit 4 = burp attack
;DQ_name		EQU	20	;bit 5 = say name
;DQ_twinkle	EQU	40	;bit 6 = sing song
;DQ_rooster	EQU	80	;bit 7 = rooster-love you

;Qualify2:	;;;;removed due to lack of RAM
;	bit  0 =
;	bit  1 =
;	bit  2 =
;	bit  3 =
;	bit  4 =
;	bit  5 =
;	bit  6 =
;	bit  7 =


; Test triggers here

Ck_game:
;	LDA	Sensor_timer	;ck if no action for a while
	LDA	Bored_timer	;ck if on action for a while
	BNE	Ck_gamactv	;jump if system active
	JSR	Clear_games	;go reset all other triggers and game pointers
Ck_gamactv:
	LDA	Qualify1		;test if all are disqualified
	CMP	#FFh		;compare activ bits only
	BNE	Ck_anysens	;jump if some or all still active
;	LDA	Qualify2		;test if all are disqualified
;	CMP	#00h		;compare activ bits only
;	BNE	Ck_anysens	;jump of some of all still active
	JSR	Clear_games	;go reset all ofther triggers and game pointers
Ck_anysens:
	LDA	Stat_4		;ck if any sensor is triggered
	BNE	Ck_gam1		;go ck games if any set
	JMP	Ck_bored		;bypass if none
;;; page 035 end
;;; page 036 start complete
;
Ck_gam1:	;fortune teller
	LDX	Egg_cnt		;get current count
	LDA	Qualify1	;update game qualification
	AND	#DQ_fortune	;check if dis-qualified but
	BNE	Ck_gam2		;bail out if is
	LDA	Fortune_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam1a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_fortune	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam2		;check next egg
Ck_gam1a:
	LDA	Fortune_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam2		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Fortune_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam2:	; Rap mode
	LDA	Qualify1	;update game qualification
	AND	#DQ_rap		;check if dis-qualified but
	BNE	Ck_gam3		;bail out if is
	LDA	Rap_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam2a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_rap		;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam3		;check next egg
Ck_gam2a:
	LDA	Rap_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam3		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Rap_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam3:
	LDA	Qualify1	;update game qualification
	AND	#DQ_hide	;check if dis-qualified but
	BNE	Ck_gam4		;bail out if is
	LDA	Hseek_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam3a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_hide	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam4		;check next egg
Ck_gam3a:
	LDA	Hseek_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam4		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
;;; page 036 end
;;; page 037 start complete
	LDA	Game_1		;get system
	ORA	#Hideseek_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam4:
	LDA	Qualify1	;update game qualification
	AND	#DQ_simon	;check if dis-qualified but
	BNE	Ck_gam5		;bail out if is
	LDA	Simon_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam4a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_simon	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam5		;check next egg
Ck_gam4a:
	LDA	Simon_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam5		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Simonsay_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam5:
	LDA	Qualify1	;update game qualification
	AND	#DQ_burp	;check if dis-qualified but
	BNE	Ck_gam6		;bail out if is
	LDA	Burp_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam5a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_burp	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam6		;check next egg
Ck_gam5a:
	LDA	Burp_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam6		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Burp_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam6:
	LDA	Qualify1	;update game qualification
	AND	#DQ_name	;check if dis-qualified but
	BNE	Ck_gam7		;bail out if is
	LDA	Name_table,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam6a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_name	;set dis-qualified bit
;;; page 037 end
;;; page 038 start complete
	STA	Qualify1	;update system
	JMP	Ck_gam7		;check next egg
Ck_gam6a:
	LDA	Name_table+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam7		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Name_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam7:
	LDA	Qualify1	;update game qualification
	AND	#DQ_twinkle	;check if dis-qualified but
	BNE	Ck_gam8		;bail out if is
	LDA	Twinkle_egg,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam7a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_twinkle	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam8		;check next egg
Ck_gam7a:
	LDA	Twinkle_egg+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam8		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Twinkle_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;
Ck_gam8:
	LDA	Qualify1	;update game qualification
	AND	#DQ_rooster	;check if dis-qualified but
	BNE	Ck_gam9		;bail out if is
	LDA	Rooster_egg,X	;get current data
	AND	Stat_4		;compare against sensor trigger
	BNE	Ck_gam8a	;if set then good compare
	LDA	Qualify1	;update game qualification
	ORA	#DQ_rooster	;set dis-qualified bit
	STA	Qualify1	;update system
	JMP	Ck_gam9		;check next egg
Ck_gam8a:
	LDA	Rooster_egg+1,X	;get current+1 to see if end of egg
	CMP	#FFh		;test if end of table and start of game
	BNE	Ck_gam9		;jump if not at end
	JSR	Clear_games	;go reset all other triggers and game pointers
	LDA	Game_1		;get system
	ORA	#Rooster_mode	;start game mode
	STA	Game_1		;update
	JMP	Idle		;gone
;;; page 038 end
;;; page 039 start complete
Ck_gam9:

Ck_gamend:
	INC	Egg_cnt		;incs on any sensor trigger
	LDA	Egg_cnt		;get
	CLC
	SBC	#10		;limit max to 10 for error checking
	BCC	Cge2		;continue if less
	JSR	Clear_games	;reset all
Cge2:
	LDA	#00		;clear all sensor triggers this pass
	STA	Stat_4		;ready for next pass of sensor triggers
	JMP	Ck_bored	;done with easter egg test

;**************************

Clear_all_gam:
	LDA	#00		;clear all game enabled bits
	STA	Game_1		;
;	STA	Game_2		;


Clear_games:
	LDA	#00		;clear counter
	STA	Egg_cnt		;
	STA	Stat_4		;clear game status
	STA	Stat_5		;clear game status
	STA	Qualify1	;clear all dis-qualify bits
;	STA	Qualify2	;clear all dis-qualify bits
	RTS			;done

;*************************

; 00 = none
; 01 = Load sound
; 02 = Light change brighter
; 04 = Light change darker
; 10 = Back switch
; 20 = Feed switch
; 40 = Tilt switch
; 80 = Invert switch

; These loop up tables provide the sequence of sensor triggers required
; to enter that specific game mode. FFh is always the last byte)

Fortune_table:
	DB	04h,04h,10h,FFH		;lght,lght,back

Rap_table:
	DB	01h,01h,01h,01h,FFh	;snd,snd,snd,snd

Hseek_table:
	DB	04h,04h,04h,08h,FFh	;light,light,light,frnt

Simon_table:
	DB	08h,10h,01h,04h,FFh	;frnt,back,snd,lght

Burp_table:
;;; page 039 end
;;; page 040 start complete
	DB	20h,20h,20h,10h,FFh	;feed,feed,feed,back

Name_egg:
	DB	08h,08h,08h,10h,FFh	;frnt,frnt,frnt,back

Twinkle_egg:
	DB	01h,01h,01h,10h,FFh	;snd,snd,snd,back

Rooster_egg:
	DB	04h,04h,04h,10h,FFh	;light,light,light,back


;*******************************
;
;
; Normal task scan of sensors and timers
;
Ck_bored:
	LDA	Bored_timer	;ck if bored ... =0
	BNE	Ck_tsk1		;jump if not bored

;  Currently uses 4 tables, one for each age.

	LDA	#Bored_split	;get random/sequential splut
	STA	IN_DAT		;save for random routine

	LDX	#Seq_bored	;get number of sequential selections
	LDA	#Ran_bored	;get number of randoms
	JSR	Ran_seq		;go decide random/sequential
	BCS	Bored_ran		;Random mode when carry SET

	LDX	Bored_count	;save current
	INC	Bored_count	;if not then next table entry
	LDA	Bored_count	;get
	CLC
	SBC	#Seq_bored-1	;ck if > assignment
	BCC	Bored_side	;jump if <
	LDA	#00		;reset to 1st entry of sequential
	STA	Bored_count	;
Bored_side:
	TXA			;current count

Bored_ran:
	JSR	Decid_age		;do age calculation for table entry
	LDX	TEMP0		;age offset
	LDA	Bored_S1,X	;get new sound/word
	STA	Macro_Lo		;save lo byte of Macro table entry
	INX			;
	LDA	Bored_S1,X	;get new sound/word
	STA	Macro_Hi		;save hi byte of Macro table entry
	JMP	Start_macro	;go set group/table pointer for motor
;
Ck_tsk1:
	LDA	Task_ptr		;
	CMP	#01		;decide which
	BNE	Ck_tsk4		;jump if not
	JMP	Ck_tilt		;Ck ball switch side sense
Ck_tsk4:
	CMP	#02		;decide which
	BNE	Ck_tsk5		;jump if not
;;; page 040 end
;;; page 041 start complete
	JMP	Ck_invert	;Ck ball switch inverted sense
Ck_tsk5:
	CMP	#03		;decide which
	BNE	Ck_tsk6		;jump if not
	JMP	Ck_back		;Ck Touch switch back sensor
Ck_tsk6:
	CMP	#04		;decide which
	BNE	Ck_tsk7		;jump if not
	JMP	Ck_IR		;Ck IR input
Ck_tsk7:
	CMP	#05		;decide which
	BNE	Ck_tsk8		;jump if not
	JMP	Ck_feed		;Ck Feed sensor
Ck_tsk8:
	CMP	#06		;decide which
	BNE	Ck_tsk9		;jump if not
	JMP	Ck_light	;Ck Light sensor
Ck_tsk9:
	CMP	#07		;decide which
	BNE	Ck_tsk10	;jump if not
	JMP	Ck_front	;Ck Front touch switch
Ck_tsk10:
	CMP	#08		;decide which
	BNE	Ck_tskend	;jump if not
	JMP	Ck_sound	;Ck Mic input
Ck_tskend:
	JMP	Idle		;no task

;**********************************************************************
;**********************************************************************
;**********************************************************************


; This rtn test for motor and speech activity and only services them
; to allow each requect to finish, and then return to task routine.
; As long as motor is active, we continually reload the motor led time
; to keep the optical counter active and when all activity is complete,
; the IRQ will turn led off when timer goes to 00.

Notrdy:
	JSR	Task_1		;go do speech
	JSR	Task_1		;go do motor

	LDA	Stat_1		;get system
	AND	#Word_activ	;Test for spch word active
	BNE	Notrdy2		;jump if not done
	LDA	Stat_1		;update
	AND	#Say_activ	;ck for saysent active
	BNE	Notrdy2

	LDA	Stat_2		;get system
	AND	#Motor_seek	;ck motor request
	BNE	Notrdy2		;jump if set
	LDA	Stat_2		;get system
	AND	#Motor_actv	;ck motor in motion
	BNE	Notrdy2

	LDA	Drift_fwd	;motor drift counter 0 when done
	BNE	Notrdy2
;;; page 041 end
;;; page 042 start complete
	LDA	Drift_rev	;
	BNE	Notrd2		;

	LDA	Stat_2		;system
	AND	#Macro_actv	;ck for flag request
	BEQ	Notrdy_dn	;bail if none
	JSR	Ck_Macro	;decide if more chaining in process
	JMP	Notrdy2		;continue
Notrdy_dn:
	RTS			;only leave when everybody done

Notrdy2:
	LDA	#Motor_led_rst	;get led timer reload
	STA	Motor_led_timer	;how long the motor stays on
	JMP	Notrdy		;loop

;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************



Task_1:
	LDA	Stat_1		;get system
	AND	#Word_activ	;Test for spch word active
	BNE	W_activ		;jump if not done
;More_spch:
	LDA	Stat_1		;update
	AND	#Say_active	;ck for saysent active
	BEQ	EndTask_1	;nothing going on; ck next task
	JSR	Do_nextset	;continue on iwth saysent
	JMP	EndTask_1	;if no speech then ck motor
W_activ:
	LDA	Port_B		;get TI req/busy line
	AND	#TI_RYS		;get bit
	BNE	EndTask_1	;if no speech then ck motor
	JSR	Do_spch		;go send next byte to TI
EndTask_1:
	RTS
;
;
Task_2:

;*********  Motor Routines **********
;
; get next motor data

Ck_motor:
	LDA	Stat_2		;get system
	AND	#Motor_actv	;ck motor in motion
	BEQ	Ck_mot2		;done
	JMP	Do_motor	;not done so check position
Ck_mot2:
	LDA	Stat_2		;get system
	AND	#Motor_seek	;ck motor request
	BEQ	NMM_out		;jmp if none

Next_motor:
;	LDA	Drift_fwd	;motor drift counter 0 when done
;;; page 042 end
;;; page 043 start XXX
Motor_done:

Motor_pause:

Ck_Macro:
;;; page 043 end
;;; page 044 start XXX
End_macro:

No_macro:

Next_macro:

Mac_dat2:

Got_macro:

More_motor:

Mcalc_lo:
;;; page 044 end
;;; page 045 start XXX
Test_fwdmore:

Go_fwd:

Go_fwd2:

Go_rev:

Go_rev2:

End_rev:

Do_motor:
;;; page 045 end
;;; page 046 start XXX
Byp_motorsS2:

Byp_motorsS3:

FCalc_lo:
;;; page 046 end
;;; page 047 start XXX
Motor_dec:

Motor_killfwd:

M_killf2:

M_killf3:

Motor_killrev:

M_killr2:

M_killr3:

Motor_killend:

Drift_table:
;;; page 047 end
;;; page 048 start XXX
Motor_speed:

Decide_motor:

Dec_mot1:

Dec_mot2:
;;; page 048 end
;;; page 049 start XXX

Dec_mot3:

Dec_mot4:

Dec_mot_end:

More_multi_m:

Motor_data:

Mot_dat2:

Endmotor:
;;; page 049 end
;;; page 050 start XXX
Endtask_2:

; Start motor/speech from macro table

Start_macro:

Get_macro:
;;; page 050 end
;;; page 051 start XXX
Roll_age:

Same_age:

Dec_macro1:

Dec_macro2:

Dec_macro3:
;;; page 051 end
;;; page 052 start XXX
Dec_macro4:

Dec_macro_end:

Otomah_lo:
Otomah_hi:

Fortdelay_lo	EQU	#66h
Fortdelay_hi	EQU	#00h

Game_fortune:

Gam_fort2:
;;; page 052 end
;;; page 053 start XXX
Gam_fort2a:

Gam_fort3:

Gam_fort4:


Fort_Name2:
;;; page 053 end
;;; page 054 start XXX
Not_Fort2:

Not_Fort3:

Say_Fortname:

Fort_Name_dn:

Ck_Fort_name:

Game_Rap:

Grap_2:

Rap_over:
;;; page 054 end
;;; page 055 start XXX
Do_rap:

Rapsong:

HidePeek_lo	EQU	#DBh
HidePeek_hi	EQU	#01h

Hidsklost_lo	EQU	#D8H
Hidsklost_hi	EQU	#01H

Hidskwon_lo	EQU	#B7H
Hidskwon_hi	EQU	#01H


Game_hideseek:
;;; page 055 end
;;; page 056 start XXX
Gam_hide2:

Gam_hide2a:

Gam_hide4:

Gam_hide5:
;;; page 056 end
;;; page 057 start XXX
Gam_hide8:

Gam_hide9:

Gam_hide9a:

HideS_timer:

HideS_t2:

HideS_tdn:

Hide_time:
;;; page 057 end
;;; page 058 start XXX
Hide_seek:

; Furby - Says

Simondelay_lo	EQU	#66h
Simondelay_hi	EQU	#00

Listen_me_lo	EQU	DAh
Listen_me_hi	EQU	01h

Simon_frnt_lo	EQU	#AEh
Simon_frnt_hi	EQU	#01h

Simon_back_lo	EQU	#AFh
Simon_back_hi	EQU	#01h
;;; page 058 end
;;; page 059 start complete
Simon_and_lo	EQU	#B0h	;using macro 432 for simon chooses "sound
Simon_and_hi	EQU	#00h	;hi byte adrs 432 = 1B0h

Simon_lght_lo	EQU	#B1h	;using macro 433 for simon chooses "light
Simon_lght_hi	EQU	#01h	;hi hbyte adrs 433 - 1B1h

Skeyfrnt_lo	EQU	#0Fh	;using macro 15 for user feed back
Skeyfrnt_hi	EQU	#00h	;use for "front"

Skeybck_lo	EQU	#B2h	;using macro 434 for user feed back
Skeybck_hi	EQU	#01h	;use for "back"

Skeylght_lo	EQU	#B3h	;using macro 435 for user feed back
Skeylght_hi	EQU	#01h	;use for "light"

Skeysnd_lo	EQU	#B4h	;using macro 436 for user feed back
Skeysnd_hi	EQU	#01h	;use for "sound"

Simonlost_lo	EQU	#D8h	; lost game is macro 472
Simonlost_hi	EQU	#01h

; Available ram not in use during this game

;HCEL_LO	Couter of which sensor were on

;HCEL_HI	Random play ram 1
;BIT_CT		Ramdom play ram 2
;Task_ptr	Random play ram 3
;Bored_count	Random play ram 4

;TEMP5		Random save ram 1 ( was TMA_INT ) TEMP5 used in RAN_SEQ
;Temp_ID2	Ramdom save ram 2
;Temp_ID	Ramdom save ram 3
;Learn_temp	Ramdom save ram 4


Game_simon:
; do delay before start of game

	LDA	#Simondelay_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Simondelay_hi	;get macro lo byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JSR	Get_macro	;go start motor/speech

	LDA	Name		;current setting for table offset
	CLC
	ROL	A		;2's comp
	TAX
	LDA	Name_table,X	;get lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	INX
	LDA	Name_table,X	;get hi byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JSR	Get_macro	;go start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor
;;; page 059 end
;;; page 060 start complete
	LDA	#Listen_me_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Listen_me_hi	;get macro hi byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JSR	Get_macro	;go start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor

	LDA	#Simondelay_lo
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Simondelay_hi	;get macro hi byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JSR	Get_macro	;go start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor

	LDA	#04		;number of sensors in 1st game
GS_rentr:
	STA	HCEL_LO		;load counter
	STA	IN_DAT		;save for later use
	JSR	Simon_random	;go load 2 grps of 4 ram locations
Simon1:
	LDA	HCEL_HI		;get  1st ram location
	JSR	Simon_sensor	;go to speech
	JSR	Rotate_play	;get next 2 bits for sensor choice
	DEC	IN_DAT		;-1 (number of senors played this game)
	BNE	Simon1		;loop til all speech done

	JSR	Recover_play	;reset random rams
	LDA	#GameT_reload	;reset timer
	STA	Bored_timer	;set
	LDA	#00
	STA	Stat_4		;clear all sensors
	LDA	HCEL_LO		;get counter
	STA	IN_DAT		;reset it
Simon2:
	JSR	Test_all_sens	;go check all sensors
	LDA	Stat_4		;get em
	BNE	Simon3		;jump if any triggered
	JSR	Simon_timer	;go check for timeout
	LDA	Bored_timer	;
	BNE	Simon2		;loop if not
	JMP	Simon_over	;bailout if 0
Simon3:
; do to lack of time I resort to brute force ... YUK....
	LDA	Stat_4		;get which sensor
	CMP	#08h		;front sw
	BNE	Simon3a		;jump if not
	LDA	#Skeyfrnt_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Skeyfrnt_hi	;get macro hi byte
	JMP	Simon3dn	;go speak it
Simon3a:
	CMP	#10h		;back sw
	BNE	Simon3b		;jump if not
	LDA	#Skeybck_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Skeybck_hi	;get macro hi byte
	JMP	Simon3dn	;go speak it
Simon3b:
	CMP	#04h		;light
;;; page 060 end
;;; page 061 start complete
	BNE	Simon3c		;jump if not
	LDA	#Skeylght_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Skeylght_hi	;get macro hi byte
	JMP	Simon3dn	;go speak it
Simon3c:
	CMP	#01h		;sound
	BNE	Simon3d		;jump if not
	LDA	#Skeysnd_lo	;get macro lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	LDA	#Skeysnd_hi	;get macro hi byte
	JMP	Simon3dn	;go speak it
Simon3d:
	CMP	#Do_invert	:?
	BEQ	Simon3e		;jump if is invert
	LDA	#00		;
	STA	Stat_4		;clear sensor flags
	JMP	Simon2		;ignore all other sensors loop up
Simon3e:
	JMP	Simon_over	;bail out if is

Simon3dn:
	STA	Macro_Hi	;save for macro call
	JSR	Get_macro	;go start motor/speech
	JSR	Notrdy		;Do / get status for speech and motor

	LDA	HCEL_HI		;get  1st ram location
	AND	#03		;bit 0 & 1
	TAX			;point to interpret table entry
	LDA	Simon_convert,X	;translat game to sensors
	CMP	Stat_4		;ck for correct sensor
	BNE	Simon_lost	;done if wrong
	LDA	#00
	STA	Stat_4		;clear all sensors
	JSR	Rotate_play	;get next 2 bits for sensor choice
	DEC	IN_DAT		;=1 (number of sensors played this game)
	BNE	Simon2		;loop til all sensors bone
	JSR	Simon_won	;game won
	JSR	Recover_play	;reset random rams
	INC	HCEL_LO		;increase number of sensors in next game
	CLC
	LDA	HCEL_LO		;get current
	STA	IN_DAT		;reset game sensor counter
	SBC	#16		;ck if max number of sensors
	BCS	Simon4		;
	JMP	Simon1		;loop uo
Simon4:
	LDA	#16		;set to max
	JMP	GS_rentr	;start next round

;;;;;; Simon subroutines

Simon_lost:
;	LDA	Stat_4		;ck for invert sw to end game
;	CMP	#Do_invert	:?
;	BEQ	Simon_over	;bail out if is
	LDA	#Simonlost_lo	;get macro lo byte
;;; page 061 end
;;; page 062 start complete
Simon_won:

Rotate_play:

Recover_play:

Simon_over:

Simon_sensor:
;;; page 062 end
;;; page 063 start XXX
Simon_delay:

Simon_random:

Simon_timer:

Simon_tdn:

Psimon_table:

Simon_convert:

Simon_won_tbl:
;;; page 063 end
;;; page 064 start XXX
End_allGames:

Saygamdn_lo	EQU	#D9h
Saygamdn_hi	EQU	#01h

Burpsnd_lo	EQU	#D6h
Bursnd_hi	EQU	#01h

Game_Burp:

Game_name:
;;; page 064 end
;;; page 065 start XXX
Twinllsnd_lo	EQU	#D5h
Twinklsnd_hi	EQU	#01h

Sleep_lo	EQU	#A6h
Sleep_hi	EQU	#00h

Game_twinkle:

Gtwnk:
;;; page 065 end
;;; page 066 start XXX
Start_sleep:

Roostersnd_lo	EQU	#D4h
Roostersnd_hi	EQU	#01h

Game_rooster:

Test_all_sens:
;;; page 066 end
;;; page 067 start XXX
Ck_tilt:

Get_tilt:

Side_out:

Do_bside:

Normal_tilt:

More_tilt:
;;; page 067 end
;;; page 068 start XXX
Tilt_reset:

Tile_side:

Tilt_ran:

Ck_invert:

Get_invert:
;;; page 068 end
;;; page 069 start XXX
Invrt_out

Do_binvrt

Normal_invert

More_invert:
;;; page 069 end
;;; page 070 start XXX
Invrt_reset:

Invrt_set:

Invrt_rnd:

Ck_back:

Get_back:

Tch1_out:

Do_tch_bk:
;;; page 070 end
;;; page 0571 start XXX
Normal_back:

More_back:

Back_reset:

Back_set:

Back_rnd:
;;; page 071 end
;;; page 072 start XXX
Ck_IR:

CKIR_S:

IR_req:

Got_IR:
;;; page 072 end
;;; page 073 start XXX
Got_IR2:

New_IT

D_IR_test:

Normal_IR:

No_sneeze:

Get_IR_rnd:

NormIR_2:
;;; page 073 end
;;; page 074 start XXX
NormIR_3:

NormIR_4:

Got_normIR:

   Include IR2.Asm   

Ck_front:

Get_front:

Touch_end:

Do_tch_ft:
;;; page 074 end
;;; page 075 start XXX
Normal_front:

More_front:

Front_reset:

Front_set

Front_rnd:
;;; page 075 end
;;; page 076 start complete
	LDA	#Front_ID	;which rom location for learned word count (offset)
	JSR	Start_learn	;go record training info
	LDA	IN_DAT		;get back word to speak
	JSR	Decid_age	;do age calculation for table entry
	LDX	TEMP0		;age offset
	LDA	Tfrnt_S1,X	;get lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	INX
	LDA	Tfrnt_S1,X	;get hi byte
	STA	Macro_Hi	;save hi byte of Macro table entry
	JMP	Start_macro	;go set group/table pointer for motor & spch

;
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;
;
;
Ck_feed:		;foo sensor
;
	JSR	Get_feed	;go ck for sensor trigger
	BCS	Normal_feed	;go gini normal spch/motor table

	JMP	Idle		;go request

Get_feed		;this is the subroutine entry point

; Each trigger increments the health status at a greater rate

; Special enable routine to share port pin D1 with invert switch.
; Feed switch is pulled hi by the DAC1 (aud-a) output only after
; we test the invert line. If invert is not hi, then turn on
; DAC1 and ck feed line on same port D1.

	LDA	Port_D		;get I/O
	AND	#Ball_invert	;ck if we are inverted
	BEQ	St_feed		;jump if not inverted (lo = not inverted)
	CLC			;indicates no request
	RTS			;if inverted then bypass
St_feed:
	LDA	#FFh		;turn DAC2 on to enable feed switch
	STA	DAC2		;out
	LDA	Port_D		;get I/O
	AND	#Ball_invert	;ck if feed switch closed
	BNE	Start_feed	;jmp if hi
	LDA	#00
	STA	DAC2		;clear feed sw enable
	LDA	Stat_3		;Get system
	AND	#Not_feed	;clear previously inverted flag
	STA	Stat_3		;update
Feed_out:
	CLC			;clear indicates no request
	RTS			;go test next

Start_feed:
	LDA	#00
;;; page 076 end
;;; page 077 start complete
	STA	DAC2		;clear feed sw enable

;	LDA	Stat_3		;get system
;	AND	#Feed_nd	;ck if prev done.
;	BNE	Feed_out	;jump if was
;	LDA	Stat_3		;get system
;	ORA	#Feed_dn	;flag set ,only execute once
;	STA	Stat_3		;update system

	LDA	Stat_4		;game mode status
	ORA	#Do_feed	;flag sensor is active
	STA	Stat_4		;update
	SEC			;set when sensor is triggered
	RTS			;

Normal_feed:			;enter here to complete speech/motor

;*******************************************************************************

;  health table calls here and decision for which speech pattern

	LDA	#Food		;each feeding increment hunger counter
	CLC
	ADC	Hungry_counter	;feed him!
	BCC	Feeding_dn	;jump of no roll over
	LDA	#FEh		;max count
Feeding_dn:
	STA	Hungry_counter	;update


;;;;;	JSR	Life		;go finist sick/hungry speech



;*******************************************************************************

	LDA	#Feed_split	;get random/sequential split
	STA	IN_DAT		;save for random routine

	LDX	#Seq_feed	;get how many sequential selections
	LDA	#Ran_feed	;get random assignment
	JSR	Ran_seq		;go decide random/sequential

	LDX	Sensor_timer	;get current  for training subroutine

	BCS	Feedrand	;Random mode when carry set

	LDA	Sensor_timer	;ck if timed out since last action
	BEQ	Feed_reset	;yep

	LDA	Feed_count	;save current
	STA	BIT_CT		;temp store

	INC	Feed_count	;if not then next table entry
	LDA	Feed_count	;get
	CLC
	SBC	#Seq_feed-1	;ck if > assignment
	BCC	Feed_set	;jump if <
	LDA	#Seq_feed-1	; dont inc off end
	STA	Feed_count	;
	JMP	Feed_set	;do it
Feed_reset:
;;; page 077 end
;;; page 078 start complete
	LDA	#00		;reset to 1st entry of sequential
	STA	BIT_CT		;temp store
	STA	Feed_count	;
Feed_set:
	LDA	#Global_time	;get timer reset value
	STA	Sensor_timer	;reset it
	LDA	BIT_CT		;get current pointer to tables

Feedrand:

	STA	IN_DAT		;save decision
	LDA	#Feed_ID	;which ram location for learned word count (offset)
	JSR	Start_learn	;go record training info
	LDA	IN_DAT		;get back word to speak

	JSR	Decid_age	;do age calculation for table entry
	LDX	TEMP0		;age offset
	LDA	Feed_S1,X	;get lo byte
	STA	Macro_Lo	;save lo byte of Macro table entry
	INX
	LDA	Feed_S1,X	;get hi byte
	STA	Macro_Hi	;save hi byte of Marco table entry
	JMP	Start_macro	; go set group/table pointer for motor & spch

;
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;*******************************************************************************
;

Ck_light:			;Bright light sensor

	JSR	Get_light	;now handled as subroutine
	BCC	Ck_light2	;jump if new level > reff
	JMP	Idle		;nothing to do
Ck_light2:
	JMP	Normal_light	;jump if new level > reff



   Include Light5.asm


Normal_light:

; below routines are jumped to by light exec if > reff

;*******************************************************************************

	JSR	Life		;go tweek health/nungry counters
	BCS	More_light	;if clear then do sensor else bail
	JMP	Idle		;done

More_light:

;*******************************************************************************

	LDA	#Light_split	;get random/sequential split
	STA	IN_DAT
;;; page 078 end
;;; page 079 start XXX
Lght_reset:

Light_set:

Lghtrand:

Do_dark:
;;; page 079 end
;;; page 080 start XXX
Ck_sound:

Ck_sound2:

Get_sound:

Ck_snd2:

Ck_snd3:

Snd_over:
;;; page 080 end
;;; page 081 start XXX
Ck_snd4:

No_snd:

No_snd2:

Normal_sound:

More_sound:
;;; page 081 end
;;; page 082 start XXX
Snd_reset:

Snd_set:

Sndrand:
;;; page 082 end
;;; page 083 start XXX
Start_learn:

Not_BCK:
;;; page 083 end
;;; page 084 start XXX
Do_lrn2:

Do_lrn2a:

Not_learned:

Learn_update:

Lrn_upd1:

Lrn_upd2:
;;; page 084 end
;;; page 085 start complete
; on 1st cycle of new learn, we set counter 1/2 way ..... (chicken)

	BNE	Lrn_upd2a	;jmp if not 0
	LDA	#80h		;1/2 way point
	STA	Tilt_lrn_cnt,X	;update sensor counter
	JMP	Clear_learn	;go finish
Lrn_upd2a:
;--------- end 1st cycle preload

	ADC	#Learn_chg	;add increment value
	BCS	Learn_overflw	;jump if rolled over
	STA	Tilt_lrn_cnt,X	;update sensor counter
	JMP	Clear_learn	;go finish
Learn_overflw:
	LDA	#FFh		;set to max
	STA	Tilt_lrn_cnt,X	;save it
Clear_learn:
	JMP	Do_lrn2		;done

;*******************************************************************************


;
; When IRQ gets turned off, and the restarted, we wait two completer
; cycle to unsure the motor R/C pulses are back in sync.

Kick_IRQ:
	LDA	Stat_3		;get system
	AND	#Nt_IRQdn	;clear IRQ occured status
	STA	Stat_3		;update system
	LDX	#03		;loop counter
Kick2:
	LDA	Stat_3		;system
	AND	#IRQ_dn		;ck if IRQ occured
	BEQ	Kick2		;wait till IRQ happens
	LDA	Stat_3		;get system
	AND	#Nt_IRQdn	;clear IRQ occured status
	STA	Stat_3		;update system
	DEX
	BNE	Kick2		;loop til done
	RTS			;is done


;*******************************************************************************
;*******************************************************************************


;EEPROM READ/WRITE

; Read & write subroutines

;*******************************************************************************

Do_EE_write:

; EEPROM WRITE
;;; page 085 end
;;; page 086 start complete
; Enter with 'TEMP0' holding adrs of 0-63. Areg holds lo byte and
; Xreg holds hi byte. IF carry is clear then it was successful, if
; carry is set the write failed.

; MODIFIED eeprom , load lo byte in temp1 and hi byte in temp2
;  call call EEWRIT2.

	LDA	#00		;use DAC output to put TI in reset
	STA	DAC1		;
	SEI			;turn IRQ off

	LDA	#00		;EEPROM adrs to write data to
	STA	Sgroup		;sve adrs
	LDA	#13		;number of ram adrs to transfer (x/2)
	STA	Which_delay	;save
	LDA	#00		;Xref offset
	STA	Which_motor	;save

; Need one read cycle before a write to wake up EEPROM

	LDA	Which_motor	;eeprom address to read from
	JSR	EEREAD		;get data (wakes up eeprom)


Write_loop:

	LDA	Sgroup		;get next EEPROM adrs
	STA	TEMP0		;buffer
	LDX	Which_motor	;ram source
	LDA	Age,X		;lo byte (data byte $1)
	STA	TEMP1		;save data bytes
	INC	Which_motor	;
	INX
	LDA	Age,X		;
	STA	TEMP2		;hi byte (data byte #2_
	JSR	EEWRIT2		;send em
	BCS	EEfail		;jump if bad

	INC	Sgroup		;0-63 EEPROM adrs next
	INC	Sgroup		;0-63 EEPROM adrs next (eemprom write 2 bytes)
	INC	Which_motor	;next adrs
	DEC	Which_delay	;how many to send
	BNE	Write_loop	;send some more

	RTS			;done




; READ EEPROM HERE AND SETUP RAM

S_EEPROM_READ:

; Xreg is the adrs 0-62, system returns lo byte in Areg & hi byte in Xreg.

;     on call: X = EEPROM data addrss (0-63)
;     on return: ACC = EEPROM data (low byte)  (also in TEMP0)
;                X = EEPROM data (high byte)  (alsi in TEMP1)
;;; page 086 end
;;; page 087 start complete
	LDA	#00		;use DAC output to put R1 in rest
	STA	DAC1		;
	SEI			;turn IRQ off

	LDX	#00		;eeprom address to read from
	JSR	EEREAD		;get data (one read in init system)

	LDA	#00		;EEPROM adrs to read
	STA	Sgroup		;save adrs
	LDA	#14		;numbe rof am adrs to transfer (x/2)
	STA	Which_delay	;save
	LDA	#00		;Xreg offset to write ram data
	STA	Which_motor	;save

Read_loop:

	LDX	Sgroup		;EEPROM adrs
	JSR	EEREAD		;get data

	LDX	Which_motor	;ram destination
	LDA	TEMP0		;get data
	STA	Age,X		;lo byte (data byte #1)
	INC	Which_motor	;
	INX
	INC	Sgroup		;0-63 EEPROM adrs next
	LDA	TEMP1		;get data
	STA	Age,X		; lo byte (data byte #2)
	INC	Which_motor	;next adrs
	INC	Sgroup		;0-63 EEPROM adrs next
	DEC	Which_delay	;how many to get
	BNE	Read_loop	;send some more

	LDA	#00		;clear rams used
	STA	Sgroup
	STA	Which_motor	;
	STA	Which_delay	;

	  CLI			;Enable IRQ
	JSR	Kick_IRQ	;wait for interrupt to retart
	JSR	TI_reset		;go init TI  (uses 'Cycle_timer')
;*******************************************************************************

;*******************************************************************************
; Begin Kobll's code
;*******************************************************************************

;
; Enable or Disable EEPROM by setting/clearing CS
;     (CS = B.0)
;
;     on call: --
;     on return: --
;     stack usage: 0
;     RAM usage: B_IMG
;
;;; page 087 end
;;; page 088 start complete
;*******************************************************************************
;
EEENA:
	LDA	Port_B_Image	;get prev state of port B.
	ORA	#001H		;turn on B.0
	JMP	EEE02		;
;
EEDIS:
	LDA	Port_B_Image	;get prev state of port B.
	AND	#0FEH		;turn on B.0
;
EEE02:
	STA	Port_B		;output to port
	STA	Port_B_Image	; and save port image
	RTS
;

;*******************************************************************************
;
; Output data bit to EEPROM by placing data bit on
; EEPRROM DI line and toggling EEPROM CLK line.
;
;	EEPROM DI = A.1
;	EEPROM CLK = A.0
;
;	on call: C = data bit to be output
;	on return; --
;	stack usage: 0
;	RAM usage: Port_A_image
;
;*******************************************************************************
;
OUTBIT:
	BCS	OUTB02		;branch if output bit = 1
;
	LDA	Port_A_image	;get prev state of port 1.
	AND	#0FDH		; turn off A.1
	JMP	OUTB04
;
OUTB02:
	LDA	Port_A_image	;get prev state of port 1.
	ORA	#02H		; turn on A.1
;
OUTB04:
	STA	Port_A		;output to port
	STA	Port_A_image	; and save image
;
; toggle EEPROM clock
;
TOGCLK:
	LDA	Port_A_image	;get prev state of A
	ORA	#001H		;turn of A.0,
	STA	Port_A		;output to port
	NOP			;delay
	NOP			;
	NOP			;
	AND	#0FEH		;turn off A.0
	STA	Port_A		;output to port
;;; page 088 end
;;; page 089 start complete
	STA	Port_A_image	;save image
	RTS
;
;*******************************************************************************
;
; Read data 16-bit data work from EEPROM at specified address
;
;	on call: X = EEPROM data address (0-63)
;	on return; ACC = EEPROM datat (low byte)
;		X = EEPROM data (high byte)
;	stack usage: 2
;	RAM usage: TEMP0
;
;*******************************************************************************
;
EEREAD:
	STX	TEMP0		;store data addr
	JSR	EEENA		;turn on CS
;
	SEC			;send start bit
	JSR	OUTBIT		;
;
	SEC			;send READ opcode (10)
	JSR	OUTBIT		;
;
	LDX	#6		;init addr bit count
	ROL	TEMP0		;align MS addr bit in bit 7
	ROL	TEMP0		;
;
EERD02:
	ROL	TEMP0		;shift address but into carry
	JSR	OUTBIT		;send it to EEPROM
	DEX			;bump bit counter
	BNE	EERD02		; and repeat until done
;
	LDX	#16		;init data bit count
	LDA	#0		;
	STA	TEMP0		;init data bit accumulators
	STA	TEMP1		;
;
EERD04:
	JSR	TOGCLK		;toggle clock for next bit
	LDA	#02H		;test data bit (B.5) from EEPROM
	BIT	Port_B		;
	BNE	EERD10		;
	CLC			;EEPEOM data bit = 0
	JMP	EERD10		;
;
EERD08:
	SEC			;EEPROM data bit = 1
;
EERD10:
	ROL	TEMP0		;rotate data bit into 16-bit
	ROL	TEMP1		; accumulator
	DEX			;bump bit counter
;;; page 089 end
;;; page 090 start complete
	BNE	EERD04		; and repeat until done
;
	JSR	EEDIS		;turn off CS and return
	LDA	TEMP0		;ret w/data byte in ACC
	LDX	TEMP1		; and X regs
	RTS
;
;*******************************************************************************
;
; Issue ERASE/WITE ENABLE or DISABLE instruction to EEPROM
;  	(instruciotn = 100100000)
;
;	on call: --
;	on return: --
;	stack usage: 2
;	RAM usage: TEMP3
;
;*******************************************************************************
;
EEWEN:
	LDA	#0FFH		;set up enable inst
	JMP	EEWE02		;
;
EEWDS:
	LDA	#000h		;set up disable inst
;
EEWE02:
	STA	TEMP3		;save instruction
	JSR	EEENA		;turn CS
;
	SEC			;send start bit
	JSR	OUTBIT		;
;
	CLC			;send ENA/DIS opcore (00)
	JSR	OUTBIT		;
	CLC			;
	JSR	OUTBIT		;
;
	LDX	#6		;init instr bit count
;
EEWE04:
	ROL	TEMP3		;shift instruction bit into carry
	JSR	OUTBIT		;send it to EEPROM
	DEX			;bump bit counter
	BNE	EEWE04		;and repeat until done
	RTS
;
;*******************************************************************************
;
; Write data byte to EEPROM at specified address
;
;	on call:  TEMP0 = EEPROM data address (0-63)
;	           ACC = data to be written (low byte)
;	           X = data to be written (high byte)
;	on return: C = 0 on succesful write cycle
;	           C = 1 on write cycle time out
;	stack usage: 4
;;; page 090 end
;;; page 091 start complete
;	RAM usage: TEMP0, TEMP1, TEMP2
;
Y;*******************************************************************************
;
EEWRIT:
	STA	TEMP1		;save data bytes
	STA	TEMP2		;
EEWRIT2:
;
	JSR	EEWEN		;send write enable inst to EEPROM
	JSR	EEDIS		;set ??? low
	JSR	EEENA		; then high again
;
	SEC			;send start bit
	JSR	OUTBIT		;
;
	CLC			;send WRITE opcode (01)
	JSR	OUTBIT		;
	SEC			;
	JSR	OUTBIT		;

;
	LDX	#6		;init addr bit count
	ROL	TEMP0		;align MS addr bit in bit 7
	ROL	TEMP0		;
;
EEWR02:
	ROL	TEMP0		;shift address bit into carry
	JSR	OUTBIT		;
	DEX			;bump bit counter
	BNE	EEWR02		; and repeat untol done
;
	LDX	#16		;init data bit count
;
EEWR06:
	ROL	TEMP1		;shift data bit into carry
	ROL	TEMP2		;
	JSR	OUTBIT		;send it to EEPROM
	DEX			;bump bit counter
	BNE	EEWR06		; and repeat untol done
;
	JSR	EEDIS		;cycle CS low
	JSR	EEENA		; then high again
;
	LDA	#0		;init write cycle
	STA	TEMP0		; time out counter
	STA	TEMP1		;
;
EEWR08:
	LDA	#020H		;test READY/BUSY bit (B.5)
	BIT	Port_B		; from EEPROM
	BNE	EEWR10		;wait for write cycle to finish
;
	DEC	TEMP0		;wrute cycle time out counter
	BNE	EEWR08		;
	DEC	TEMP1		;
	BNE	EEWR08		;
;
	JSR	EEWR10		;time out, disable EEPROM and
	SEC			; set carry to signal error
;;; page 091 end
;;; page 092 start complete
	RTS			;
;
EEWR10:
	JSR	EEWDS		;send write diable inst to EEPROM
	JSR	EEDIS		;set CS low
	CLC			;clear carry to signal successful write
	RTS			;
;
;*******************************************************************************
;*******************************************************************************
;

; Subroutine creates sensor table entry for the selected age
; One table for each age
; Enter with Acc holding the 1-16 table selection.
; Exit wtih Acc & Temp0 holding the offset 0-FF of the 1-4 age entry.

; Special condition where we have only two tables instead of 4
; (where each table is called based on age), if the "half_age" bit is
; set then ages 1 & 2 call table 1 and ades 3 & 4 to call table 2.


Decid_age:
	STA	TEMP0		;save 0-0f selection

	LDA	Stat_1		;system
	AND	#Half_age		;test if this is a special 2 table select
	BEQ	Decid_normal	;jump if not
	LDA	Stat_1		;
	AND	#Nt_half_age	;clear req
	STA	Stat_1		;update system

	LDA	Age		;

	AND	#03h		;get rug of bit 7 (9th counter bit )

	CLC
	SBC	#01		;actual age is 0-3, test if <2
	BCC	Dec_age1		;choose age 1 (actuall 0 here)
	JMP	Spc1_age2		;choose age 2 (actuall 1 here)
Decid_normal:

;;; mod TestR3a... 25% of time chose age1 to add more furbish after
;;;                he is age 4.

	JSR	Random		;get a number
	CLC
	SBC	#Random_age	;below this lovel selects age 1
	BCS	Nospc1_age	;jump if >
	LDA	#00		;set age 1
	JMP	Do_age		;go do it
;;; end mod

Nospc1_age:

	LDA	Age		;get current
	AND	#03H	;get rig of bit 7 (9th counter bit )
	CMP	#03	;is it age 4
	BNE	Dec_age3	;jump iof not
	LDA	#96	;point to 4th field
	JMP	Do_age	;finish load from table
;;; page 092 end
;;; page 093 start complete
Dec_age3:
	CMP	#02		;is it age 3
	BNE	Dec_age2	;jump if not
	LDA	#64		;point to 3rd field
	JMP	Do_age		;finish load from table
Dec_age2:
	CMP	#01		;is it age 3
	BNE	Dec_age1	;jump it not
Spc1_age2:
	LDA	#32		;point to 2nd field
	JMP	Do_age		;finish	load from table
Dec_age1:
	LDA	#00		;point to 1st field
Do_age:
	STA	TEMP2		;save age offset for speech
	CLC
	ROL	TEMP0		;16 bit offset for speech
	LDA	TEMP2		;which table entry
	ADC	TEMP0		;create speech field offset pointer
	STA	TEMP0		;save
	RTS

;*******************************************************************************
;*******************************************************************************

; Random/sequential decision control for all sensors
;
; Enter with Acc holding the number of randow selections for sensor
; Enter with Xreg honging number of sequential selections
; It returns with Acc holding the random select and the carry will
; be cleared for a sequential node and set for a random more.
; NOTE: if the caller has no random selections then carry will be cleared.

Ran_seq:
	STA	TEMP1		;save random max
	STX	TEMP5		;save number of sequentials
	LdA	TEMP1		;force cpu status ck
	BEQ	Seq_decisn	;jump if no randoms
	DEC	TEMP1		;make offset from 0
Ran_loop:
	JSR	Random		;get n
	ROR	A		; move hi nibble to lo
	ROR	A
	ROR	A
	ROR	A
	AND	#0Fh		;get lo nibble
	STA	TEMP2		;save
	CLC
	SBC	TEMP1		;get max random number from sensor
	BCS	Ran_loop		;loop until =< max value
	LDA	TEMP2		;get new number
	CMP	Prev_random	;ch if duplicate from last attempt
	BEQ	Ran_loop		;loop if it is
	STA	Prev_random	;update for next pass
	STA	TEMP1		;new

	LDA	TEMP5		;ck if no sequentials
;;; page 093 end
;;; page 095 start complete
	BEQ	Ran_decisn	;force random if none

	JSR	Random		;get random/sequention decision

	CMP	IN_DAT		;random/sequenctial split
;;;;;	CMP	#80h		;>80=random else sequential

	BCC	Seq_decisn	;jump if less

Ran_decisn:
	LDA	TEMP5		;get number of sequential of this pass
	CLC
	ADC	TEMP1		;add to random for correct table start point
	STA	TEMP1		;update
	SEC			;set carry to indicate random
	RTS
Seq_decisn:
	CLC			;clear carry to indicate sequential
	RTS			;done (Acc holds answer)


;*******************************************************************************
;*******************************************************************************


; Random number generator
; SEED_1 & SEED_2 are always saved through power down
; TEMP3 & TEMP4 are random temporary files.
; Acc returns with random number, Seed_1 also holds random number

Random:
	LDA	Seed_1
	STA	TEMP3
	LDA	Seed_2
	STA	TEMP4
	CLC
	ROL	A
	ROL	Seed_1
	CLC
	ROL	A
	ROL	Seed_1
	CLC
	ADC	TEMP4
	STA	Seed_2
	LDA	#00
	ADC	TEMP3
	STA	Seed_1
	LDA	#00
	INC	Seed_2
	ADC	Seed_1
	STA	Seed_1
	RTS		;return with random number in Acc & seed_1	

;*******************************************************************************
;*******************************************************************************
;;; page 094 end
;;; page 095 start XXX
Life:

frst_life:
;;; page 095 end
;;; page 096 start XXX
Max_Sref:

fret_sick:

Sick_inc:

No_sick_inc:

Hunger1:

Life_normal:

Hunger2:

Decd_Hung_sck_norm:

Decd_Hung_norm:
;;; page 096 end
;;; page 097 start XXX
Decd_Sick_norm:

Decd_Hung_Sick:

Say_hunger:

Hunger_reset:

Hunger_side:

Hunger_ran:

Say_sick:
;;; page 097 end
;;; page 098 start XXX
Sick_reset:

Sick_side:

Sick_ran:

GoToSleep:

Nodrk_prev:

Os2:
;;; page 098 end
;;; page 099 start XXX
IWrite_loop:

GoToSleep_2:

   Include Sleep.asm
;;; page 099 end
;;; page 100 start XXX
NMI:

IRQ:

CkTimerA:

Ck_timerB:

Do_timeB:

Cal_noroll:
;;; page 100 end
;;; page 101 start XXX
No_cal_sw:

No_lim_stp:

WTa:

Timer_norm:

No_spd_m:

No_matop:

TimeB1:

TimeB2:

TimeB3:

TimerB_dn:
;;; page 101 end
;;; page 102 start XXX
Clr_pos:

ExtportC:

Force_int:

Cnt_rev:

Cnt_dn:   ; XXX ????

Updt_cnt:
;;; page 102 end
;;; page 103 start XXX
Pc_done:

Mot_led_off:

Mot_led_dn:

M_drft_F1:

M_drft_F2:

M_drft_R1:
;;; page 103 end
;;; page 104 start complete
	JMP	Intt_motor_end
M_drft_R2:
	DEC	Drift_rev	;-1
	LDA	Port_D_Image	;get system
	ORA	#Motor_off	;turn both motors off
	JMP	Intt_motor_end

Intt_motor:
	LDA	Stat_3
	AND	#C0h		;get motor command bits
	STA	Intt_Temp	;save motor direction

;________ Furby16 ... move potor pulse width to interrupt routine

	LDA	Motor_pulse1	;get on time
	BEQ	Intmotor1	;jump if 0
	DEC	Motor_pulse1	;-1
	JMP	Intmotor_dn	;exit (dont change Intt_temp if on)
Intmotor1:
	LDA	Motor_pulse2	;get off time
	BEQ	Intmotor2	;got reset timer
	DEC	Motor_pulse2	;-1
	LDA	#C0h		;shut motor off
	STA	Intt_Temp	;
	JMP	Intmotor_dn	;exit
Intmotor2:
	LDA	Mon_len		;reset on time
	STA	Motor_pulse1	;
	LDA	Moff_len	;reset off time
	STA	Motor_pulse2	;
Intmotor_dn:

;----- end motor pulse width

	LDA	Port_D_Image	;get system
	AND	#3Fh		;clear motor direction bits
	CLC
	ADC	Intt_Temp	;put in motor commands


Intt_motor_end:
	STA	Port_D_Image	;update system

; at Tracker
	EOR	#%11000000	;;Tracker add  invert motor drivers
; end Tracker

	STA	Port_D		;output

Intt_done:			;general return

	LDA	Stat_3		;system
	ORA	#IRQ_dn		;flag system IRQ occured
	STA	Stat_3		;update
Intt_false:
	LDA	#00H		;clear all intts first
	STA	Interrupts	;
	  LDA	  #Intt_dflt	;get default for interrupt reg
	  STA	  Interrupts	;set rag & clear intt flag

	PLP			;recover CPU
;;; page 104 end
;;; page 105 start complete
	PLA			;recover ACC

	RTI			;reset interrupt

;*******************************************************************************
;*******************************************************************************
;*******************************************************************************

; Communication protocol iwth the TI is:
;
;    FF is a no action command. (used as end of speech command)
;    FE sets the command data mode an the TI expects two
;    additional data bytes to complete the string. (3 TOTAL)
;    ALL OTHERS (0-FD) ARE CONSIDERED START OF A SPEECH WORD !
;    Command data structure is BYTE 1 + BYTE 2 + BYTE 3

; BYTE 1 is always FE

; Command 1
;    BYTE 2 = FE is pitch table control;
;    BYTE 3 = bit 7 set = subtract value from current course value
;                   clr = add value to current course value
;             bit 6 set = select music pitch table
;                    clr = select normal speech pitch table
;             bit 0-5 value to change course value (no change = 0)
;
; Command 2
;    BYTE 2 = FD is Infrared transmit cmnd
;    BYTE 3 = Is the I.R> code to send  ( 0 - 0Fh only)
;
; Command 3
;    BYTE 2 = FC is the speech speed control
;    BYTE 3 = a value of 0 -255 where 2Eh is normal speed

; Enter subroutine with TEMP1 = command byte (1st)
;                       TEMP2 = data byte (2nd)

Xmit_TI:
	LDA	#FEh		;tells TI command data to follow
	JSR	Spch_more	;out data
	LDA	TEMP1		;command code
	JSR	Spch_more	;out data
	LDA	TEMP2		;data to send
	JSR	Spch_more	;out data
	RTS			;done

;*******************************************************************************
;*******************************************************************************
;
; There is an entry for each back of speech and only the words in that
; back are in the list. THis is a subroutine call.

; The first time thru, we call SYA_x and as long as WORD_ACTIV of SAY_ACTIV
; is set we call DO_NEXTSENT until saysent is fone.

; There are 4 groups of 128 pointers in each group. This gives 512 saysents.
;;; page 105 end
;;; page 106 start complete
; 1. Enter with 'Which_word' hold 0127 and 'Sgroup' for the 1 of 4 tables
;    which point to two byte adrs of a saysent. These two bytes are
;    loaded into Saysent_lo & Saysent_hi.

; 2. Data is shuffled to the TI according to the BUSY/REQ line
;

; Currently we have 167 speech words or sounnds in ROM. Words 1-12
; are in bank 0 and 13-122 are in back 1 & 123-167 in bank 2.

Say_0:
	LDA	Which_word	;get offsett   ; XXX CAC guessing
	TAX			;load offset to Xreg ; XXX CAC guessing
	CMP	#03		;is it in table group 4
	BEQ	Dec_say4	;jump if is
	CMP	#02		;is it in table group 3
	BEQ	Dec_say3	;jump if is
	CMP	#01		;is it in table group 2
	BEQ	Dec_say2	;jump if is
Dec_say1:
	LDA	Spch_grp1,X	;get lo pointer
	STA	Saysent_lo	;save
	INX			;X+1
	LDA	Spch_grp1,X	;get hi pointer
	STA	Saysent_hi	;save
	JMP	Dec_say5	;go calc word
Dec_say2:
	LDA	Spch_grp2,X	;get lo pointer
	STA	Saysent_lo	;save
	INX			;X+1
	LDA	Spch_grp2,X	;get hi pointer
	STA	Saysent_hi	;save
	JMP	Dec_say5	;go calc word
Dec_say3:
	LDA	Spch_grp3,X	;get lo pointer
	STA	Saysent_lo	;save
	INX			;X+1
	LDA	Spch_grp3,X	;get hi pointer
	STA	Saysent_hi	;save
Dec_say4:
	LDA	Spch_grp4,X	;get lo pointer
	STA	Saysent_lo	;save
	INX			;X+1
	LDA	Spch_grp4,X	;get hi pointer
	STA	Saysent_hi	;save
Dec_say5:
	LDX	#00		;no offsett
	LDA	(Saysent_lo,X)	;get data @ 15 bit adrs
	STA	TEMP2		;save new speech speed
	LDA	#FCh		;command for TI to except speed data
	STA	TEMP1		;
	JSR	Xmit_TI		;send it ti TI
	INC	Saysent_lo	;next saysent pointer
	BNE	Xney_say	;jump if no roll over
	INC	Saysent_hi	;+1
;;; page 106 end
;;; page 107 start complete
Xney_say:
	LDX	#00		;no offsett
	LDA	(Saysent_lo,X)	;get data @ 16 bit adrs
	CLC
	ADC	Rvoice		;adjut to voice selected on power up
	STA	TEMP2		;save new speech pitch
	LDA	#FEh		;command for TI to except pitch data
	STA	TEMP1		;


; The math routine converts the value to 00 for 80 and
; if ???0 then subtracats from 80 to get the minus versio of 00
; ie, if number is 70 then TI gets send 10 (-1

	LDA	TEMP2		;get voice with offset
	BMI	No_voice_chg	;if >80 then no chan
	LDA	#80h		;remove offsett if <80
	CLC
	SBC	TEMP2		;kill offset
	STA	TEMP2		;update
No_voice_chg:
	JSR	Xmit_TI		;send it to TI

Do_nextsent:
Frst_say:
	INC	Saysent_lo	;next saysent pointer
	BNE	Scnd_say	;jump if no roll over
	INC	Saysent_hi	;+1
Scnd_say:
	LDX	#00		;no offset
	LDA	(Saysent_lo,X)	;get data @ 16 bit adrs
	CMP	#FFH		;check for end
	BEQ	Say_end		;done
	LDA	(Saysent_lo,X)	;get data @ 16 bit adrs
	STA	Which_word	;
Wtest:
	CLC
	SBC	#12		;ck if in bank 1
	BCS	Get_group1	;jump if is

Get_group0:
	LDA	#00		;set bank
	  STA	  Bank_ptr	;Bank number
	CLC			;clear carry
	LDA	Which_word	;get word
	ROL	A		;2^s offset
	TAX			;load offset to Xreg
	LDA	Word_group0,X	;get lo pointer
	STA	Word_lo		;save
	INX			;X_1
	LDA	Word_group0,X	;get hi pointer
	STA	Word_hi		;save
	JMP	Word_fini	;go do it

Get_group1:
	LDA	Which_word	;selection
	CLC
	SBC	#122		;ck if in bank 2
;;; page 107 end
;;; page 108 start complete
	LDA	#01		;set bank
	  STA	  Bank_ptr	;Bank number
	CLC
	LDA	Which_word	;get word
	SBC	#12		;1st 12 in word_group0
	CLC
	ROL	A		;2's offsett
	TAX			;load offset to Xreg
	LDA	Word_group1,X	;get lo pointer
	STA	Word_lo		;save
	INX			;X+1
	LDA	Word_group1,X	;get hi pointer
	STA	Word_hi		;save
	JMP	Word_fini

Get_group2:
	LDA	#02		;set bank
	STA	Bank_ptr	;Bank number
	CLC			;clear carry
	LDA	Which_word	;get word
	SBC	#122		;1st .22 in word_group 0 & 1
	CLC
	ROL	A		;2's offset
	TAX			;load offset to Xreg
	LDA	Word_group2,X	;get lo pointer
	STA	Word_lo		;save
	INX			;X+1
	LDA	Word_group2,X	;get hi pointer
	STA	Word_hi		;save
Word_fini:
	LDA	Stat_1		;get system
	ORA	#Say_active	;Set spch acrive afer word pointer loaded
	ORA	#Word_active	;Set status
	STA	Stat_1		;update system
	JMP	Do_spch		;go say it

Say_end:
	LDA	Stat_1		;get system
	AND	#Clr_spch	;tune say_activ & Spch_activ off
	STA	Stat_1		;save system
	RTS			;done

; This is the re-entry point during speech for all words to be spoken

; ******** start of chg for - - #FFh xmits ti TI

Do_spch:
	  LDA	  Bank_ptr	;Bank number
	  STA	  Bank		;set it

	  LDX	  #00H
	  LDA	  (Word_lo,X)	;Get the speech data
	CMP	#FFH		;is it end of word
	BNE	Clr_word_end	;jump of not end

	LDA	Stat_1		;get system
	AND	#Word_term	;was it prev set
	BEQ	Set_end		;nope
;;; page 109 end




;;;
;;;  page 109 Wake2.asm
;;;  page 111 Light5.asm
;;;  page 116   Diag7.asm
;;;  page 126   Furby27.inc
;;;  missing  IR2.Asm
;;;  missing  Sleep.Asm
;;;

