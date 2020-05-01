all : FURBY.OBJ

FURBY.OBJ : furby.asm DIAG7.ASM FURBY27.INC IR2.ASM LIGHT5.ASM SLEEP.ASM WAKE2.ASM
	dosbox -c "mount c ." -c "c:" -c "x6502 furby.asm -D" -c "exit"

clean :
	rm FURBY.OBJ FURBY.LST
