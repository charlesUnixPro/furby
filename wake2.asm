;;; page 109 start complete; WAKE2 page 1
; WAKE2
;     adds deep sleep mode. If 'Deep_aleep'=11h then tilt will not
;     wake us up, only invert.



; Power up reset decision for three types of startup:
; 1. Powerup with feed switch zeros ram & EEPROM, & calls 10-200-10 macro.
; 2. Power up from battery change wont clear EEPROM but calls 10-200-10 macro.
; 3. Wake up from Port_D clears ram and jumps directly to startup. No macro.



	SEI			;interrupts off
	LDX	#C0H		;startup setting
	STX	Interrupts	;disable Watch Dog
	LDX	#FFH		;Reset stack pointer address S0FFH
	TXS

	LDX	#0
	LDA	Wake_up		;Get the information from hardware to check
				;whether reset is from power up or wakeup
	STA	TEMP5
	STX	Wake_up		;disable wakeup immediately, this action can
				;stop the reset occupied by another changed on
				;portD, so once the program can execute to
				;this line then chip will not be reset due to
				;port changed again



	AND	#%00000001	;mask the rest of bit and just check the port
				;wake up information
	BEQ	Power_battery	;jump to power up initial if not port D

; Need to debounce tilt and invert since they are very unstable

Ck_wakeup:
	LDA	#00		;clear
	STA	TEMP1		;
	STA	TEMP2		;
	LDX	#FFh		;loop counter
Dbnc_lp:
	LDA	Port_D
	AND	#01		;ck tilt sw
	BEQ	Dbnc_lp2		;jump if not tilt
	INC	TEMP1		;switch counter
Dbnc_lp2:
	LDA	Port_D
	AND	#02		;ck invert sw
	BEQ	Dbnc_lp3		;jump if not invert
	INC	TEMP2		;switch counter
Dbnc_lp3:
	DEX			;-1 loop count
	BNE	Dbnc_lp		;loop

	LDA	Deep_sleep	;decide if normal or deep sleep
	CMP	#11h		;
	BEQ	Dbnc_lp4		;if deep sleep then only test invert
	LDA	TEMP1		;get tilt count
	BEQ	Dbnc_lp4		;jump if 0
	CLC
	SBC	#10		;min count to insure not noise
	BCS	Power_Port_D	;jump if > min
;;; page 109 end
;;; page 110 start complete; WAKE2 page 2
Dbnc_lp4:
	LDA	TEMP2		;get invert count
	BEQ	Dbnc_lp5		;jump if 0
	CLC
	SBC	#10		;min count to insure not noise
	BCS	Power_Port_D	;jump if > min
Dbnc_lp5:

;Verify that Port_D is no longer changing before going to sleep.
;If not, the CPU will lock up without setting the low power mode.
;Before we exit here when count is less than minimum count, we must
;be sure Port_D is not changing. If we jump to sleep routine when
;it is not stable, the sleep routine will wait forever to be stable
;which causes Furby appear to be locked up.

	LDA	#00		;
	STA	TEMP1		;counter
	LDA	Port_D		;get current status
Test_sleep:
	CMP	Port_D		;check if changed
	BNE	Ck_wakeup		;start over if did
	DEC	TEMP1		;-1 counter
	BNE	Test_sleep	;loop
	JMP	GoToSleep_2	;otherwise, just goto sleep again


Power_Port_D:
	LDA	#11h		;signal port D wakeup
	STA	Warm_cold		;
	JMP	L_PowerOnInitial	;

Power_battery:
	LDA	#05h		;signal battery wakeup
	STA	Warm_cold		;




L_PowerOnInitial:
	LDA	#00		;clear deep sleep command
	STA	Deep_sleep	;
;;; page 110 end
