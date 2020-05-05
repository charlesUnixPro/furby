;;; page 116 start complete; DIAG7 page 1

;------------------------------------------------------------
;* Diagnostics and calibration routine
;------------------------------------------------------------
;
; Mods to the diagnostic routines :

; DIAG6 :
; Init memory,voice,name and write EEPROM before exiting.

; Diag7:
; EEprom memory test, reads and writes all locations.
; On power up if port D woke us, then bypass diagnostics.

;************************************************************

; refer to self test mode documentation

;****************** START
;
; Diagnostic EQU's

Dwait_tilt	EQU	02	;full test waiting for no tilt (step 1)

Diagnostic:

; All speech / motor calls use standard macro routines, except we
; force the macro directly. Be carefull to load the 'MACRO_LO' and
; 'MACRO_HI' bytes properly. We use a common subroutine to set the macro
; so 'MACRO_HI' is loaded only once in the subroutine. Be sure the macros
; are in the same 128 byte block. Initially chose adrs 400 (190) for these
; diags.

	LDA	Warm_cold		;get startup condition
	CMP	#11h		;ck for port D wakeup
	BEQ	No_Diag		;jump if not

	LDX	#FFh		;loop   counter
DportD_tst:
	LDA	Port_D		;get I/O
	AND	#03		;ck for tilt and invert
	BNE	No_Diag		;if either hi then bail out
	DEX			;-1
	BNE	DportD_tst	;loop till done (ckg for Port D bounce)

	LDA	Port_C		;get I/O
	AND	#0Ch		;ck for front and back switches made
	BEQ	Diag1		;if both not lo then bail out else start diag 

No_Diag:
	JMP	Test_byp		;no diagnostic request

Diag1:				;Start test
	;; force voice to normal condition while diag is active
	LDA	#9			;;Tracker add for constant
	STA	Rvoice		;;Tracker add
	LDA	#0		;hi beep for start of test
	JSR	Diag_macro	;go send motor/speech

;wait for front & back to clear

	LDA	Port_C		;get I/O
;;; page 116 end
;;; page 117 start complete; DIAG7 page 2
	AND	#0Ch		;get keys
	CMP	#0Ch		;must be both hi
	BNE	Diag1		;wait till are
New_top:
	LDA	#03		;set delay for switch bounce
	JSR	Half_delay	;x *  delay
;
Diag2a:		;press front key & go to EEPROM test
	LDA	Port_C		;get I/O
	AND	#Touch_frnt	;wait for switch
	BNE	Diag2b		;go ck if next test is requesting

	LDA	#01		;hi beep for start of test
	JSR	Diag_macro	;go send motor/speech

Diag2a1:
	LDA	Port_C
	AND	#Touch_frnt
	BEQ	Diag2a1

; EEPROM WRITE

; init ram as 1,2,3,4,5,..... to 26

	LDA	#01H		; data for fill
	LDX	#Age		; start at ram location


RAMset:
	STA	00,X		; base 00, offset x
	CLC
	ADC	#01		;inc Acc
	INX			; next ram location
	CPX	#Age+26		; check for end
	BNE	RAMset		; branch, not finished
				; fill done

	JSR	Do_EE_write	;write the EEPROM
	JSR	S_EEPROM_READ	;read data to ram

	LDA	#00		;clear
	STA	Task_ptr		;
	LDX	#Age		;start at ram location
RAMtest:
	LDA	00,X		; base 00, offset X
	CLC			;
	ADC	Task_ptr		;running CRC
	STA	Task_ptr		;running total
	INX			; next ram location
	CPX	#Age+26		; check for end
	BNE	RAMtest		; branch, not finished
	LDA	Task_ptr		;get result
	CMP	#5Fh		;matching CRC (actual total is 15Fh )
	BNE	EEfail		;jump if bad

EEpass:
	LDA	#02		;beep to signal good test
	STA	Feed_count	;Use as temp storage
	JMP	EEdone		;send sounds
EEfail:
	LDA	#03		;beep indicates failure
	STA	Feed_count	;temp storage
EEdone:
;;; page 117 end
;;; page 118 start complete; DIAG7 page 3
	CLI			;enable IRQ
	JSR	Kick_IRQ		;wait for timer to re-sync
	JSR	TI_reset	i	;clear TI from ?????????

	LDA	Feed_count	;get lo byte of macro to call
	JSR	Diag_macro	;go send motor/speech

Diag2b:		; Speaker tone / I.R. xmit
	LDA	Port_C		;get I/O
	AND	#Touch_bck	;wait for switch
	BNE	Diag2c		;go check if next test is requesting

	LDA	#1		;hi beep for start of test
	JSR	Diag_macro	;go send motor/speech
Diag2b1p:
	LDA	Port_C
	AND	#Touch_bck
	BEQ	Diag2b1p

Diag2b1:
	LDA	#04		;send long tone (1k sinewave)
	JSR	Diag_macro	;go send motor/speech

	LDA	Port_C		;
	AND	#Touch_bck	;mask for back switch
	BNE	Diag2b1		;loop until back switch pressed

Xmit_1p:
	LDA	#01		; beep
	JSR	Diag_macro	;go send motor/speech

;	LDA	Port_C
;	AND	#Touch_bck	;mask for back switch
;	BNE	Xmit_1p		;loop until back switch pressed

	LDA	#05h		;send '5' to I.R. xmiter
	STA	TEMP2		;
	LDA	#FDh		;send command I.R. to TI
	STA	TEMP1		;
	JSR	Xmit_TI		;send it

dumb:	LDA	Port_C		;get I/O
	AND	#Touch_bck	;wait for switch
	BNE	dumb		;wait for back to be pressed

dumber:	LDA	Port_C		;get I/O
	AND	#Touch_frnt	;ck switch
	BEQ	Next_1
	JMP	Xmit_1p

Next_1:	LDA	#2		;hi beep for start of test
	JSR	Diag_macro	;go send motor/speech
	LDA	Port_C		;get I/O
	AND	#0Ch		;ck for front and back switches made
	BEQ	Next_1		;if both not lo then bail out else start diag
	JMP	New_top


; Full test starts here
Diag2c: LDA	Port_D		;get I/O
	AND	#Ball_invert	;wait for switch
	BNE	Diag2d		;onward if key pressed
;;; page 118 end
;;; page 119 start complete; DIAG7 page 4
	JMP	Diag2a		;loop back Co Cop if none

Diag2d:
	LDA	#01		;hi beep for start of test
	JSR	Diag_macro	;go send motor/speech

; FULL TEST MODE

DiagF1:		;wait for no tilt to start full diag
	LDA	#Dwait_tilt	;set delay to be sure no tilts
	STA	TEMP1		;
DiagF1a:
	LDA	Port_D
	AND	#3
	BNE	DiagF1
	DEC	TEMP1
	BNE	DiagF1a

	LDA	#2		;pass beep
	JSR	Diag_macro	;go send motor/speech
;
DiagF2:		;test tilt 45 deg

	LDA	Port_C
	AND	#00001100b
	CMP	#0CH
	BEQ	DiagF22
	LDA	#3		; fail beep
	JSR	Diag_macro	;

DiagF22:
	LDA	Port_D
	AND	#2
	BEQ	DiagF23

	LDA	#3		; fail beep
	JSR	Diag_macro	;

DiagF23:
	LDA	Port_D		;get I/O
	AND	#Ball_side	;ck for tilt switch (hi = tilted)
	BEQ	DiagF2		;wait for tilt

	LDA	Port_D		;get I/O
	AND	#Ball_invert	;ck if invert sw mode
	BNE	DiagF2a		;jump to error if so

	LDA	Port_C		;get I/O
	AND	#0Ch		;get front & back
	CMP	#0Ch		;must be hi else error
	BEQ	DiagF2b		;if hi then pass

DiagF2a:
	LDA	#3		;fail beep
	JSR	Diag_macro	;go send motor/speech
	JMP	DiagF2		;loop till no error

DiagF2b:
	LDA	#2		;pass beep
	JSR	Diag_macro	;go send motor/speech

DiagF2c:           ;wait for no tilt before continuing
;;; page 119 end
;;; page 120 start complete; DIAG7 page 5
	LDA	Port_C
	AND	#Touch_bck
	BEQ	DiagF3b

	LDA	Port_D		;get I/O
	AND	#Ball_side	;ck for tilt switch (hi = tilted)
	BNE	DiagF2c		;wait for no tilt

;DANGER
;	LDA	Port_C		;get I/O
;	AND	#Touch_frnt	;ck switch
;	BEQ	DiagF3		; no other switch can be made here else error
;	JMP	DiagF23		; allow multiple checks

DiagF3:		;test back switch
;	LDA	Port_C		;get I/O
;	AND	#Touch_bck	;wait for switch
;	BEQ	release		;loop if hi (touch is not pressed)
	JMP	DiagF23

release:
	LDA	Port_C		;get I/O
	AND	#Touch_frnt	;ck switch
	BEQ	DiagF3a		;no other switch can be made here else error

	LDA	Port_D		;get I/O
	AND	#03		;ck for tilt and invert
	BEQ	DiagF3b		;if either hi then error else continue


DiagF3a:
	LDA	#3		;fail beep
	JSR	Diag_macro	;go send motor/speech
	JMP	DiagF3		;loop till no error

DiagF3b:
	LDA	#2		;pass beep
	JSR	Diag_macro	;go send motor/speech
;
DiagF4:
	LDA	Port_C		;get I/O   wait for front to clear
	AND	#Touch_frnt	;ck switch
	BEQ	DiagF4		;if pressed then wait for release

;  Send motor forward until front switch pressed

	LDA	Stat_2		;get system
	ORA	#Motor_fwd	;set = motor fwd (inc)
	ORA	#Motor_actv	;set motor in motion
	STA	Stat_2		;update system
	LDA	Stat_3		;get current status
	ORA	#Motor_off	;turn both motors off
	AND	#Motor_fwds	;move motor in fwd dir
	STA	Stat_3		;update


DiagF4a1:
	LDA	Port_C		;get I/O	wait for front
	AND	#Touch_frnt	;ck switch
	BEQ	DiagF4a2		;got it
	JMP	DiagF4a1		;loop till found

;   Send motor reverse until front switch pressed
;;; page 120 end
;;; page 121 start complete; DIAG7 page 6
DiagF4a2:
	LDA	Port_C		;get I/O   wait for front to clear
	AND	#Touch_frnt	;ck switch
	BEQ	DiagF4a2		;if pressed then wait for release

	LDA	Stat_2		;get system
	AND	#Motor_rev	;clear fwd flag
	ORA	#Motor_actv	;set motor in motion
	STA	Stat_2		;update system
	LDA	Stat_3		;get current status
	ORA	#Motor_off	;turn both motors off
	AND	#Motor_revs	;move motor in rev dir
	STA	Stat_3

DiagF4a3:
	LDA	Port_C		;get I/O   wait for front
	AND	#Touch_frnt	;ck switch
	BEQ	DiagF4a4		;got it
	JMP	DiagF4a3		;loop till found

;   Send motor end to end and stop on cal sw, else error

DiagF4a4:
	LDA	Stat_3		;get current status
	ORA	#Motor_off	;turn both motors off
	STA	Stat_3		;update
	LDA	Stat_2		;get system
	AND	#Motor_inactv	;clear activ flag
	STA	Stat_2		;update system

	LDA	#5		;start motor test
	JSR	Diag_macro	;go
	LDA	#33		;set delay for motor to stop
	JSR	Half_delay	;x * half sec delay
;	LDA	Porc_C		;get I/O
;	AND	#Motor_cal	;lo when hit
	BNE	DiagF4b		;no position switch found
	LDA	#2		;pass beep
	JSR	Diag_macro	;go send it
	JMP	DiagF5		;done
DiagF4b:
	LDA	#3		;fail beep
	JSR	Diag_macro	;go send it

DiagF5:		;send motor to mouth open for feed sw test
	LDA	Port_C		;get I/O
	AND	#Touch_frnt	;wait for switch
	BNE	DiagF5		;loop

	LDA	#6		;feed position
	JSR	Diag_macro	;send it
;
DiagF6:
; ck for feed sw, all other sw = error
; Remember to test invert before setting feed sw test, else conflict.

	LDA	#00
	STA	DAC2		;clear feed sw enable
	LDA	Port_C		;get I/O
	AND	#0Ch		;ck for front and back switches made
	CMP	#0Ch		;ck both are clear
	BNE	DiagF6a		;wait till are
;;; page 121 end
;;; page 122 start complete; DIAG7 page 7
	LDA	Port_D		;get I/O
	AND	#03		;ck for tilt and invert
	BNE	DiagF6a		;if either hi then wait till clear
	JMP	DiagF6b		;jump when all clear
DiagF6a:
	LDA	#3		;fail beep when any other switch made
	JSR	Diag_macro	;send it
	JMP	DiagF6		;loop
DiagF6b:

;mod diag6 ;   inc random number seeds until feed switch down

	INC	Seed_1		;create random based on switches
	LDA	TMA_LSB		;get timer A also (should be unknown)
	STA	Seed_2		;save it

; end mod

	LDA	#FFh		;turn DAC2 on to enable feed switch
	STA	DAC2		;out
	LDA	Port_D		;get I/O
	AND	#Ball_invert	;ck if feed switch closed
	BEQ	DiagF6		;loop until switch closed
	LDA	#00
	STA	DAC2		;clear feed sw enable
	LDA	#7		;pass beep
	JSR	Diag_macro	;go send motor/speech
;
DiagF7:	;Light sensor test

;mod to compensate for new light sense routine

;	LDA	#00		;clear light timer to force new reff cycle
;	STA	Light_timer	;set it
;	LDA	Stat_3		;get system
;	ORA	#Lt_reff		;make this pass a new light reff
;	STA	Stat_3		;update
;	JSR	Get_light		;go get light level, establish 1st level

	LDA	Stat_4
	AND	#Nt_do_lt_dim	;clear indicating change > reff level
	STA	Stat_4		;update system

	JSR	Get_light		;go get light level sample
	LDA	TEMP1		;get new count
	STA	Light_reff	;update system



DiagF7a:
	JSR	Get_light		;go get again and test for lower level
	LDA	Stat_4		;get system
	AND	#Do_lght_dim	;check if went dinner
	BEQ	DiagF7a		;loop if no change
	LDA	#8		;pass beep and motor motion
	JSR	Diag_macro	;send it

DiagF8:		;Sound sensor test
	LDA	#00		;clear sound timer to force new reff cycle
	STA	Sound_timer	;set
	LDA	Stat_1		;get system again
	ORA	#Snd_reff		;make this pass a new sound reff
;;; page 122 end
;;; page 123 start complete; DIAG7 page 8
	STA	Stat_1		;update
	JSR	Get_sound		;go get light level, establish 1st level
	LDA	Stat_4		;
	AND	#Nt_do_snd	;clear indicating change > reff level
	STA	Stat_4		;update system
DiagF8a:
	JSR	Get_sound		;go get again and test for lower level
	LDA	Stat_4		;get system
	AND	#Do_snd		;check if went louder
	BEQ	DiagF8a		;loop if no change
	LDA	#9		;pass beep and motor motion
	JSR	Diag_macro	;send it
;
DiagF9:		;wait for I.R. data received

	LDX	#10		;;Tracker change, original is 100

DiagF9a1:
	LDA	#1
	JSR	Half_delay
	DEX
	BNE	DiagF9a1

	JSR	D_IR_test		;go ck for data
	BCC	DiagF9		;;loop until data receive
	CMP	#A5H		;is it the expected data
	BNE	DiagF9a		;jump if wrong data
	LDA	#1		;pass beep and motor motion
	JSR	Diag_macro	;send it
	JMP	DiagF1O		;done

DiagF9a:
	LDA	#3		;fail beep and motor motion
	JSR	Diag_macro	;send it

DiagF1O:		;all tests complete, send to sleep node
	LDA	#10		;
	JSR	Half_delay	;

	LDA	#10		;put furby in sleep postion
	JSR	Diag_macro	;send it

; Clear RAM to 00H

; we dont clear Seed_1 or Seed_2 since they are randomized at startup.

; ------------------------------------------------------------
	LDA	#00H		; data for fill
	LDX	#D7h		; start at ram location

Clear:
	STA	00,X		; base 00, offset x
	DEX			; next ram location
	CPX	#7FH		; check for end
	BNE	Clear		; branch, not finished

;************************************************************


; Random voice selection here

	LDA	#80h		;get random/sequential split
;;; page 123 end
;;; page 124 start complete; DIAG7 page 9
	STA	IN_DAT		;save for random routine

	LDX	#00		;make sure only gives random
	LDA	#10h		;get number of random selections
	JSR	Ran_seq		;go get random selection

	TAX
	LDA	Voice_table,X	;get new voice
	STA	Rvoice		;set new voice pitch

;************************************************************


; On power up or reset. Furby must go select a new name ,,, ahw how cute.

	JSR	Random		;
	AND	#1Fh		;get 32 possible
	STA	Name		;set new name pointer

;************************************************************

	LDA	#FFh		;insure not hungry or sick
	STA	Hungry_counter	;max not hungry
	STA	Sick_counter	;Max not sick


; Clear training or all sensors

	LDA	#00

	STA	Temp_ID
	STA	Temp_ID2

	STA	Tilt_learned
	STA	Tilt_lrn_cnt

	STA	Feed_learned
	STA	Feed_lrn_cnt

	STA	Light_learned
	STA	Light_lrn_cnt

	STA	Dark_learned
	STA	Dark_lrn_cnt

	STA	Front_learned
	STA	Front_lrn_cnt

	STA	Sound_learned
	STA	Sound_lrn_cnt

	STA	Wake_learned
	STA	Wake_lrn_cnt

	STA	Invert_learned
	STA	Invert_lrn_cnt



	JMP	GoToSleep		;write ee memory YO !
;;; page 124 end
;;; page 125 start complete; DIAG7 page 10 (blank)
;;; page 125 end
