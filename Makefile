all : FURBY.OBJ

FURBY.OBJ : FURBY.ASM DIAG7.ASM FURBY27.INC IR2.ASM LIGHT5.ASM SLEEP.ASM WAKE2.ASM
	dosbox -c "mount c ." -c "c:" -c "x6502 FURBY.ASM -D" -c "exit"

%.ASM : %.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

FURBY.ASM : furby.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

DIAG7.ASM : diag7.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

FURBY27.INC : furby27.inc
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

IR2.ASM : ir2.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

LIGHT5.ASM : light5.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

SLEEP.ASM : sleep.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

WAKE2.ASM : wake2.asm
	sed < $< "/^;;;>/d" | sed "s/^;;;<//" > $@

clean :
	rm FURBY.OBJ FURBY.LST FURBY.ASM DIAG7.ASM FURBY27.INC IR2.ASM LIGHT5.ASM SLEEP.ASM WAKE2.ASM
