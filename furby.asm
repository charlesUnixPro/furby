; page 3

Voice1	EQU	83h
Voice2	EQU	7Ah
Voice3	EQU	71H

Voice	EQU	Voice3

S_voice1	EQU	18
S_voice2	EQU	09

; page 4

Mpulse_on	EQU	134
Mpulse_off	EQU	134

; page 5

Ports_dir	EQU	00

.CODE
.SYNTAX 6502
.LINKLIST
.SYMBOLS

	ORG	0600H

RESET:
;    Include Wake2.asm

	LDA	#00H
	LDX	#E9H
RAMClear:
	STA	00,X

	DW	91
	DB	FFH, FFh

