all : FURBY.OBJ

FURBY.OBJ : FURBY.ASM DIAG7.ASM FURBY27.INC IR2.ASM LIGHT5.ASM SLEEP.ASM WAKE2.ASM
	dosbox -c "mount c ." -c "c:" -c "x6502 furby.asm -D" -c "exit"

%.asm : %.ASM
	sed < $< 'sed "/^;;;>/d" | sed "s/^;;;<//" > $@

FURBY.ASM : furby.asm
DIAG7.ASM : diag7.asm
FURBY27.INC : furby27.inc
IR2.ASM : ir2.asm
LIGHT5.ASM : light5.asm
SLEEP.ASM : sleep.asm
WAKE2.ASM : wake2.asm
	
clean :
	rm FURBY.OBJ FURBY.LST FURBY.ASM DIAG7.ASM FURBY27.INC IR2.ASM LIGHT5.ASM SLEEP.ASM WAKE2.ASM
