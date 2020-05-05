;;; page 111 start complete; LIGHTS page 1
;************************************************************

;;   MODS :

; LIGHT3.asm
; Add test to light counter so that if the oscillator
; fails, the system will ignore light sensor and keep running.
;
; Light4
; When goes to complete dark and hits the 'Dark_sleep' level
; and stays there until the reff level updates, at that point
; we send Furby to sleep.
;
; Light5 (used in F-RELS2 )
; Change detection of light threshold to prevent false or continuous trigger.


;************************************************************

Bright		EQU	15	;light sensor trigger > reff level (Hon)
Dim		EQU	15	;Light sensor trigger < reff level (Hon)

Shift_reff	EQU	10	;max count to set or clear prev done flag

Dark_sleep	EQU	B0h	;when timer A hi =0f and timer A low
;				is = to this EQU then send him to sleep


; The CDS light sensor generates a square wave of 500hz to 24khz based on
; light brightness. We can loop on the sense line and count time for the
; lo period to determine if light has changed and compare it to previous
; samples. This also determines going lighter or darker. We also set a timer
; so that if someone holds their hand over the sensor and we announce it,
; if the change isnt stable for 10 second, we ignore the change back to the
; previous state. If it does exist for > 10 seconds, then it becomes the
; new sample to compare against on the next cycle.

; In order to announce light change,    the system must have a consistent
; count > 'Shift_reff'.

; If a previous reff has been set then the 'Up_light' bit is set to
; look for counts greater than the reff. The system passes through the
; light routine 'Shift_reff' times. If it is consistently greater than
; the reff level, we get a speech trigger.  If any single pass is less
; than the reff, the counter is set back to zero. This scenario also
; is obeyed when the trigger goes away, ie remove your hand, and the system
; counts down to zero.('Up_light' bit is cleared ) If during this time any
; trigger greater than reff occurs, the count is set back to max.
; This should prevent false triggers.




Get_light:	;alt entry for diagnostics

; This uses timer A to get a count from the lo period of the clk

	SEI			;interrupts off
	LDA	#0C0H		;disable timer, clock, ext ints,
	STA	Interrupts	; & watchdog; select IRQ int.
	LDA	#000H		;set timer A for timer mode
	STA	TMA_CON		;
;;; page 111 end
;;; page 112 start complete; LIGHTS page 2
	LDA	#000H		;re-start timer A
	STA	TMA_LSB		;
	LDA	#000H		;now CPUCLK; was #010H = CPUCLK/4 (Hon)
	STA	TMA_MSB		;
Ck_lght2:
	LDA	TMA_MSB		;test for dead light osc
	AND	#0Fh		;get timer
	CMP	#0Fh		;ck for > 0E
	BNE	Ck_lt2a		;jump if not
	LDA	TMA_LSB		;get lo byte
	CLC
	SBC	#E0h		;ck for > (msb+lsb =0FE0)
	BCC	Ck_lt2a		;jump if not
	JMP	Light_fail	;bail out if >

Ck_lt2a:
	LDA	Port_D		;get I/O
	AND	#Light_in		;ck light clk is hi
	BEQ	Ck_lght2		;wait for it to go hi

	LDA	#000H		;re-start timer A
	STA	TMA_LSB		;
	LDA	#000H		;now CPUCLK; was #010H = CPUCLK/4 (Hon)
	STA	TMA_MSB		;

Ck_lght3:
	LDA	TMA_MSB		;test for dead light osc
	AND	#0Fh		;get timer
	CMP	#0Fh		;ck for > 0E
	BNE	Ck_lt3a		;jump if not
	LDA	TMA_LSB		;get lo byte
	CLC
	SBC	#E0h		;ck for > (msb+lsb =0FE0)
	BCS	Light_fail	;bail out if >

Ck_lt3a:
	LDA	Port_D		;get I/O
	AND	#Light_in		;ck light clk is lo
	BNE	Ck_lght3		;wait for it to go lo to insure the clk edge
Ck_lght4:

	LDA	#000H		;re-start timer A
	STA	TMA_LSB		;
	LDA	#000H		;now CPUCLK/ was #010H = CPUCLK/4 (Hon)
	STA	TMA_MSB		;


Ck_lght4a:
	LDA	Port_D		;get I/O
	AND	#Light_in		;ck if still lo
	BEQ	Ck_lght4a		;loop till hi

; Timer A holds count for lo period of clk

Lght4cmp:
	LDA	TMA_MSB		;get timer high byte
	AND	#00FH		; mask out high nybble
	STA	TEMP2		; and save   it
	LDA	TMA_LSB		;get timer   low byte
	STA	TEMP1		; and save   it

	LDA	TMA_MSB		;get timer A high byte again
;;; page 112 end
;;; page 113 start complete; LIGHTS page 3
	AND	#00FH		; mask out high nybble
	CMP	TEMP2		; and compare it with last reading
	BNE	Lght4cmp		;loop until they're equal

; take 12 bit timer (2 bytes) and move to one byte and trash lo nible
; of low byte. End up with hi 8 bits out of 12.

	LDX	#04		;loop counter
Light_byte:
	ROR	TEMP2		;get lo bit into carry
	ROR	TEMP1		;shuffle down and get carry from TEMP2
	DEX			;-1
	BNE	Light_byte	;loop till done

Ck_lght4b:
	LDA	#Intt_dflt	;Initialize timers, etc.
	STA	Interrupts	;re-establish normal system
	CLI			;re-enable interrupt
	JSR	Kick_IRQ		;wait for motor R/C to start working again
	CLC			;clear

;---now have new count in 'TEMP1'

	LDA	Light_reff	;get previous sample
	SBC	TEMP1		;ck against current sample
	BCC	Ck_lght5		;jump if negative
	CLC
	SBC	#Bright		;ck if difference > reff
	BCS	Lght_brt		;go do speech
	JMP	Kill_ltrf		;bail out if not

Ck_lght5:
	CLC
	LDA	TEMP1		;try the reverse subtraction
	SBC	Light_reff	; prev
	BCC	Kill_ltrf		;quit if negative
	CLC
	SBC	#Dim		;is diff < reff
	BCC	Kill_ltrf		;bail out if not
Lght_dim:
	LDA	Stat_3		;system
	AND	#Nt_lght_stat	;clear bit to indicate dark table
	STA	Stat_3		;update system
	JMP	Do_lght		;go fini
Lght_brt:
	LDA	Stat_3		;system
	ORA	#Lght_stat	;set bit to indicate light table
	STA	Stat_3		;update system
	JMP	Do_lght		;

Light_fail:
	LDA	#FFh		;force lo number so no conflicts
	STA	TEMP1
	LDA	#Intt_dflt	;Initialize timers, etc.
	STA	Interrupts	;re-establish normal system
	CLI			;re-enable interrupt
	JSR	Kick_IRQ		;wait for motor R/C to start working again
	JMP	Kill_shift	;ret with no req

;------------------------------------------------------------

Do_lght:
;;; page 113 end
;;; page 114 start complete; LIGHTS page 4
	LDA	Stat_1		;system
	AND	#Up_light		;ck if incrmnt mode
	BNE	Rst_shftup	;jump if incrmnt mode
	LDA	#Shift_reff	;set to max
	STA	Light_shift	;
	JMP	No_lt_todo	;
Rst_shftup:

	INC	Light_shift	;+1
	LDA	Light_shift	;get counter
	CLC
	SBC	#Shift_reff	;ck if > max reff count
	BCC	No_lt_todo	;jump if < max count
	LDA	#Shift_reff	;reset to max
	STA	Light_shift	;

	LDA	Stat_0		;system
	AND	#Lt_prev_dn	;check if previously done
	BNE	New_ltreff	;jump if was

	LDA	Stat_0		;system
	ORA	#Lt_prev_dn	;set previously done
	STA	Stat_0		;update

;	LDA	Stat_1		;system
;	AND	#EFh		:set sytem to shift decrmnt mode
;	STA	Stat_1		;update

	LDA	#Light_reload	;reset for next trigger
	STA	Light_timer	;set it
	JMP	Do_ltchg		;go announce it

New_ltreff:
	LDA	Light_timer	;get current
	BNE	No_lt_todo	;nothing to do
	LDA	TEMP1		;get new count
	STA	Light_reff	;update system

	LDA	Stat_1		;system
	AND	#EFh		;set sytem to shift decrmnt mode
	STA	Stat_1		;update

	LDA	TEMP1		;get current value
	CLC
	SBC	#Dark_sleep	;ck if > sleep level
	BCS	Ck_drk		;jump if >
	LDA	Stat_0		;system
	AND	#7Fh		;kill prev done
	STA	Stat_0		;update
	JMP	Kill_ltrf		;


Ck_drk:
	LDA	Stat_0		;system
	AND	#Dark_sleep_prev	;ck if this was already done
	BNE	Kill_ltrf		;jump if was

	LDA	Stat_0		;system
	ORA	#REQ_dark_sleep	;set it
	ORA	#Dark_sleep_prev	;set also
	STA	Stat_0		;update

Kill_ltrf:
;;; page 114 end
;;; page 115 start XXX; LIGHTS page 5
;	LDA	Stat_0		;system
;	AND	#Lt_prev_dn	;check if previously done
;	BEQ	No_lt_todo	;jump if clear
	LDA	Light_shift	;get shift counter
	BEQ	Kill_shift	;jump if went zero last time
	LDA	Stat_1		;system
	AND	#Up_light		;ck if incrmnt mode
	BEQ	Rst_shftdn	;jump if decrmnt mode
	LDA	#00		;set to min
	STA	Light_shift	;
	JMP	No_lt_todo	;
Rst_shftdn:
	DEC	Light_shift	;-1
	JMP	No_lt_todo	;done
Kill_shift:
	LDA	Stat_0		;system
	AND	#FDh		;clears Lt_prev_dn
	STA	Stat_0		;update

	LDA	Stat_1		;system
	ORA	#Up_light		;prepare to incrmnt 'Light_shift'
	STA	Stat_1		;update


No_lt_todo:
	SEC			;carry set indicates no light change
	RTS

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;****** alert system to start speech

Do_ltchg:
	LDA	Stat_3		;system
	AND	#Lght_stat	;ck if went light or dark
	BNE	LT_ref_brt	;went brighter if set
	LDA	Stat_4		;get system
	ORA	#Do_lght_dim	;set indicating change < reff level
	JMP	Ltref_egg		;

LT_ref_brt:
	LDA	Stat_4		;
	ORA	#Do_lght_brt	;set indicating change > reff level
Ltref_egg:
	STA	Stat_4		;update egg info
	CLC			;carry clear indicates light > reff
	RTS			;done
;;; page 115 end
