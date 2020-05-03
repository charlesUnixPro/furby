;;; page 126 start complete; FURBY27.INC page 1
; Furby27.inc ;;  change twinkle egg song to one pass in macro


; Lowered voice+10,voice+9 to voice+8
; Wayne's mods:
; Furby5b.inc = add voice selection table
;
; Dave's
; added feed (mouth open)
; 170,171,173,174,175,182,183,190,191,194
; mod for ir
; NOW 24 NAMES
;
;TABLES         MACRO   |SAY
;-------------------------------------
;FRONT          2-64    |1-61
;FORTUNE        65-83   |62-78
;o-too-mah      84
;HANGOUT        85-101  |79-106
;delay          102     |107
;FEED           103-145 |108-123
;WAKE           146-169 |124-156
;HUNGER         170-201 |157-168
;INVERT         202-238 |169-192
;BACK           239-275 |193-236
;SICK           276-292 |237-250
;LIGHT          293-307 |251-265
;DARK           308-331 |266-289
;SOUND          332-351 |290-309
;TILT           352-392 |310-350
;IR             393-429 |351-390
;FURBY SAYS     430-434 |50 TICKLE,196 PET,71 SOUND,391 LIGHT,198 PURR
;               435,436 |392 NO LIGHT, 393 LOUD SOUND
;               437,438 |115,116	; hide and seek sounds
;               95,96,97|98,99,100	; hide and seek reuse
;               439     |		; furby says win sound
;Diagnostic     440-450 |400-410
;               451,452 | 117,118	; hide and seek sounds
;Names          453	| 399,395,110	; me koko     (more)
;               454     | 399,395,396   ; me meme     (very)
;               455     | 399,395,112   ; me e-day     (good)
;               456     | 399,395,397   ; me do-moh    (please)
;               457     | 399,395,114   ; me toh-dye   (done)
;               458     | 399,395,117   ; me boo       (no)
;               459     | 399,395,398   ; me toh-loo   (like)
;               460     | 399,395,120   ; me ay-tay    (hungry)
;                       | 399           ; delay 1.3    seconds
;               461     | 399,395,131   ; me way-loh   (sleep)
;               462     | 399,395,143   ; me u-tye     (up)
;               463     | 399,395,145   ; me ay-loh    (light)
;               464     | 399,395,152   ; me kah       (me)
;               465     | 399,395,166   ; me dah       (big)
;               466     | 399,395,175   ; me boh-bay   (worry)
;               467     | 399,395,177   ; me nah-bah   (down)
; NEW EASTER EGGS
;               468     ; DODLE DO, ME LOVE YOU
;               469     ; SING A SONG
;               470     ; BURB ATTACK
;               471			; furby says win sound
;               472     |46		; furby says lose sound
;;; page 126 end
;;; page 127 start complete; FURBY27.INC page 2
;               473     |53,123		; me done (leaving any game)
;               474     |394		; LISTEN ME
;               475     |411		; HIDE ME (hide and seek)
;                       |412		;aaah,aaah,aaah feed dmh
;
; MORE NAMES
;               476     | 399,395,186	; me loo-loo  (joke)
;               477     | 399,395,194	; me ah-may   (pet)
;               478     | 399,395,201	; me noo-loo  (happy)
;               479     | 399,395,208	; me may-may  (love)
;               480     | 399,395,224	; me may-lah  (hug)
;               481     | 399,395,228	; me dah-noh-lah  (big dance)
;               482     | 399,395,398,152	; me toh-loo-ka  (like me)
;               483     | 399,395,152,166	; me ka-da        (me big)
;               484     | 399,395,224,152	; me may-lah-ka  (hug me)
;
;not used       476-511 |413-510

; TRAP FOLLOW MACROS FOR NAME
;
; SENSOR
; HANGOUT 97
; WAKE-UP 149
; BACK 248
; LIGHT BRIGHT 305
; IR 393,404,414,421
;
; GAMES
; FORTUNE 69,77
; HIDE AND SEEK 475
; FURBY SAYS 474
;
; end trap macros for name
;
; reused ; reused ; reused ; reused ; reused
;               72,380  |		; furby says win sounds
;             15       |15		; LAUGH
;                      |395		; me (for use with names)
;DANCE        407,416  |367,376		; reused for dance easter egg
;
;not used              |396-399
;
;*******************************************************************************

; Sensor tables
; Each sensor has 4 speech/motor tables based on age 1-4, of 16 entries each.
; These tables are 16 bit entries, the user enters as a decimal 1-511
; **** '00' is illegal ****
; This number calls the MACRO tables to get specific speech and motor
; tables. MACRO tables chain together multiple motor and speech tables.
; The first 8 entries of speech is random selections and
; the second 8 entries is sequential.


;
;
; one of three voice pitch selections, randomly load table and
; table is randomly called on power up to select a new voice.
; THis gives a number added to voice 3 to create which voice will be used.
;;; page 127 end
;;; page 128 start complete; FURBY27.INC page 3

Voice_table:
	DB	S_voice1
	DB	S_voice2
	DB	S_voice3
	DB	S_voice1
	DB	S_voice2
	DB	S_voice3
	DB	S_voice1
	DB	S_voice2
	DB	S_voice3
	DB	S_voice1
	DB	S_voice2
	DB	S_voice3
	DB	S_voice1
	DB	S_voice2
	DB	S_voice3
	DB	S_voice1

;Ball tilt sensor table
;DO TILT

Tilt_S1:	DW	352	; #1  AGE 1
	DW	353	; #2  AGE 1
	DW	354	; #3  AGE 1
	DW	352	; #4  AGE 1
	DW	355	; #5  AGE 1
	DW	356	; #6  AGE 1
	DW	357	; #7  AGE 1
	DW	358	; #8  AGE 1
	DW	359	; #9  AGE 1
	DW	360	; #10 AGE 1
	DW	361	; #11 AGE 1
	DW	362	; #12 AGE 1
	DW	363	; #13 AGE 1
	DW	352	; #14 AGE 1
	DW	364	; #15 AGE 1
	DW	365	; #16 AGE 1

Tilt_S2:	DW	366	; #1  AGE 2
	DW	367	; #2  AGE 2
	DW	366	; #3  AGE 2
	DW	355	; #4  AGE 2
	DW	368	; #5  AGE 2
	DW	357	; #6  AGE 2
	DW	369	; #7  AGE 2
	DW	370	; #8  AGE 2
	DW	359	; #9  AGE 2
	DW	360	; #10 AGE 2
	DW	371	; #11 AGE 2
	DW	372	; #12 AGE 2
	DW	373	; #13 AGE 2
	DW	374	; #14 AGE 2
	DW	365	; #15 AGE 2
	DW	375	; #16 AGE 2

Tilt_S3:	DW	366	; #1  AGE 3
	DW	355	; #2  AGE 3
;;; page 128 end
;;; page 129 start complete; FURBY27.INC page 4
	DW	376	; #3  AGE 3
	DW	377	; #4  AGE 3
	DW	378	; #5  AGE 3
	DW	379	; #6  AGE 3
	DW	380	; #7  AGE 3
	DW	381	; #8  AGE 3
	DW	382	; #9  AGE 3
	DW	383	; #10 AGE 3
	DW	384	; #11 AGE 3
	DW	385	; #12 AGE 3
	DW	365	; #13 AGE 3
	DW	375	; #14 AGE 3
	DW	363	; #15 AGE 3
	DW	386	; #16 AGE 3

Tilt_S4:	DW	366	; #1  AGE 4
	DW	355	; #2  AGE 4
	DW	387	; #3  AGE 4
	DW	377	; #4  AGE 4
	DW	388	; #5  AGE 4
	DW	389	; #6  AGE 4
	DW	380	; #7  AGE 4
	DW	381	; #8  AGE 4
	DW	382	; #9  AGE 4
	DW	383	; #10 AGE 4
	DW	390	; #11 AGE 4
	DW	385	; #12 AGE 4
	DW	391	; #13 AGE 4
	DW	375	; #14 AGE 4
	DW	384	; #15 AGE 4
	DW	392	; #16 AGE 4
;
;
Sick_S1:
	DW	276	; #1  AGE 1
	DW	280	; #2  AGE 1
	DW	283	; #3  AGE 1
	DW	286	; #4  AGE 1
	DW	288	; #5  AGE 1
	DW	288	; #6  AGE 1
	DW	289	; #7  AGE 1
	DW	290	; #8  AGE 1
	DW	291	; #9  AGE 1
	DW	292	; #10 AGE 1
	DW	288	; #11 AGE 1
	DW	288	; #12 AGE 1
	DW	289	; #13 AGE 1
	DW	290	; #14 AGE 1
	DW	291	; #15 AGE 1
	DW	292	; #16 AGE 1

Sick_S2:
	DW	277	; #1  AGE 2
	DW	280	; #2  AGE 2
	DW	284	; #3  AGE 2
	DW	286	; #4  AGE 2
	DW	288	; #5  AGE 2
	DW	288	; #6  AGE 2
	DW	289	; #7  AGE 2
	DW	290	; #8  AGE 2
;;; page 129 end
;;; page 130 start complete; FURBY27.INC page 5
	DW	291	; #9  AGE 2
	DW	292	; #10 AGE 2
	DW	288	; #11 AGE 2
	DW	288	; #12 AGE 2
	DW	289	; #13 AGE 2
	DW	290	; #14 AGE 2
	DW	291	; #15 AGE 2
	DW	292	; #16 AGE 2


Sick_S3:
	DW	276	; #1  AGE 3
	DW	281	; #2  AGE 3
	DW	285	; #3  AGE 3
	DW	287	; #4  AGE 3
	DW	288	; #5  AGE 3
	DW	288	; #6  AGE 3
	DW	289	; #7  AGE 3
	DW	290	; #8  AGE 3
	DW	291	; #9  AGE 3
	DW	292	; #10 AGE 3
	DW	288	; #11 AGE 3
	DW	288	; #12 AGE 3
	DW	289	; #13 AGE 3
	DW	290	; #14 AGE 3
	DW	291	; #15 AGE 3
	DW	292	; #16 AGE 3


Sick_S4:
	DW	279	; #1  AGE 4
	DW	282	; #2  AGE 4
	DW	285	; #3  AGE 4
	DW	287	; #4  AGE 4
	DW	288	; #5  AGE 4
	DW	288	; #6  AGE 4
	DW	289	; #7  AGE 4
	DW	290	; #8  AGE 4
	DW	291	; #9  AGE 4
	DW	292	; #10 AGE 4
	DW	288	; #11 AGE 4
	DW	288	; #12 AGE 4
	DW	289	; #13 AGE 4
	DW	290	; #14 AGE 4
	DW	291	; #15 AGE 4
	DW	292	; #16 AGE 4


; SWITCH FOR DO SOUND) js
Sound_S1:	DW	332	; #1  AGE 1
	DW	333	; #2  AGE 1
	DW	334	; #3  AGE 1
	DW	335	; #4  AGE 1
	DW	336	; #5  AGE 1
	DW	337	; #6  AGE 1
	DW	338	; #7  AGE 1
	DW	339	; #8  AGE 1
	DW	332	; #9  AGE 1
	DW	333	; #10 AGE 1
	DW	334	; #11 AGE 1
;;; page 130 end
;;; page 131 start complete; FURBY27.INC page 6
	DW	335	; #12 AGE 1
	DW	336	; #13 AGE 1
	DW	337	; #14 AGE 1
	DW	338	; #15 AGE 1
	DW	339	; #16 AGE 1

Sound_S2:	DW	332	; #1  AGE 2
	DW	333	; #2  AGE 2
	DW	340	; #3  AGE 2
	DW	341	; #4  AGE 2
	DW	342	; #5  AGE 2
	DW	337	; #6  AGE 2
	DW	343	; #7  AGE 2
	DW	344	; #8  AGE 2
	DW	332	; #9  AGE 2
	DW	333	; #10 AGE 2
	DW	340	; #11 AGE 2
	DW	341	; #12 AGE 2
	DW	342	; #13 AGE 2
	DW	337	; #14 AGE 2
	DW	343	; #15 AGE 2
	DW	344	; #16 AGE 2

Sound_S3:	DW	332	; #1  AGE 3
	DW	333	; #2  AGE 3
	DW	345	; #3  AGE 3
	DW	346	; #4  AGE 3
	DW	342	; #5  AGE 3
	DW	337	; #6  AGE 3
	DW	347	; #7  AGE 3
	DW	339	; #8  AGE 3
	DW	332	; #9  AGE 3
	DW	333	; #10 AGE 3
	DW	345	; #11 AGE 3
	DW	346	; #12 AGE 3
	DW	342	; #13 AGE 3
	DW	337	; #14 AGE 3
	DW	347	; #15 AGE 3
	DW	339	; #16 AGE 3

Sound_S4:	DW	348	; #1  AGE 4
	DW	333	; #2  AGE 4
	DW	349	; #3  AGE 4
	DW	346	; #4  AGE 4
	DW	342	; #5  AGE 4
	DW	350	; #6  AGE 4
	DW	347	; #7  AGE 4
	DW	351	; #8  AGE 4
	DW	348	; #9  AGE 4
	DW	333	; #10 AGE 4
	DW	349	; #11 AGE 4
	DW	346	; #12 AGE 4
	DW	342	; #13 AGE 4
	DW	350	; #14 AGE 4
	DW	347	; #15 AGE 4
	DW	351	; #16 AGE 4


;*******************************************************************************
;;; page 131 end
;;; page 132 start XXX; FURBY27.INC page 7
Hunger_S1:

Hunger_S2:

Hunger_S3:

Hunger_S4:
;;; page 132 end
;;; page 133 start XXX; FURBY27.INC page 8
Fortyes_S1:

Fortyes_S2:
;;; page 133 end
;;; page 134 start XXX; FURBY27.INC page 9
Tfrnt_S1:

Tfrnt_S2:

Tfrnt_S3:

Tfrnt_S4:
;;; page 134 end
;;; page 135 start XXX; FURBY27.INC page 10
Feed_S1:

Feed_S2:

Feed_S3:
;;; page 135 end
;;; page 136 start XXX; FURBY27.INC page 11
Feed_S4:

Wakeup_S1:

Wakeup_S2:
;;; page 136 end
;;; page 137 start XXX; FURBY27.INC page 12
Wakeup_S3:

Wakeup_S4:

Bored_S1:
;;; page 137 end
;;; page 138 start XXX; FURBY27.INC page 13
Bored_S2:

Bored_S3:

Bored_S4:
;;; page 138 end
;;; page 139 start XXX; FURBY27.INC page 14
Invrt_S1:

Invrt_S2:

Invrt_S3:

Invrt_S4:
;;; page 139 end
;;; page 140 start XXX; FURBY27.INC page 15
Tback_S1:

Tback_S2:

Tback_S3:
;;; page 140 end
;;; page 141 start XXX; FURBY27.INC page 16
Tback_S4:

IR_S1:

IR_S2:
;;; page 141 end
;;; page 142 start XXX; FURBY27.INC page 17
IR_S3:

IR_S4:

Light_S1:
;;; page 142 end
;;; page 143 start XXX; FURBY27.INC page 18
Light_S2:

Light_S3:

Light_S4:
;;; page 143 end
;;; page 144 start XXX; FURBY27.INC page 19
Dark_S1:

Dark_S2:

Dark_S3:

Dark_S4:
;;; page 144 end
;;; page 145 start XXX; FURBY27.INC page 20
Peek_S1:

Peek_S2:

Peek_S3:
;;; page 145 end
;;; page 146 start XXX; FURBY27.INC page 21
Peek_S4:

Macro_grp1:
;;; page 146 end
;;; page 147 start XXX; FURBY27.INC page 22
Macro_grp2:

Macro_grp3:
;;; page 147 end
;;; page 148 start XXX; FURBY27.INC page 23
Macro_grp4:

;;; page 148 end
;;; page 149 start XXX; FURBY27.INC page 24

;;; page 149 end
;;; page 150 start XXX; FURBY27.INC page 25

Tbl1_Macro0:

Tbl1_Macro1:

Tbl1_Macro2:

Tbl1_Macro3:

Tbl1_Macro4:

Tbl1_Macro5:

Tbl1_Macro6:

;;; page 150 end
;;; page 151 start XXX; FURBY27.INC page 26

Tbl1_Macro7:
Tbl1_Macro8:
Tbl1_Macro9:
Tbl1_Macro10:
Tbl1_Macro11:
Tbl1_Macro12:
Tbl1_Macro13:
Tbl1_Macro14:
Tbl1_Macro15:
Tbl1_Macro16:
Tbl1_Macro17:
Tbl1_Macro18:
Tbl1_Macro19:

;;; page 151 end
;;; page 152 start XXX; FURBY27.INC page 27

Tbl1_Macro20:
Tbl1_Macro21:
Tbl1_Macro22:
Tbl1_Macro23:
Tbl1_Macro24:
Tbl1_Macro25:
Tbl1_Macro26:
Tbl1_Macro27:
Tbl1_Macro28:
Tbl1_Macro29:
Tbl1_Macro30:
Tbl1_Macro31:

;;; page 152 end
;;; page 153 start XXX; FURBY27.INC page 28


Tbl1_Macro32:
Tbl1_Macro33:
Tbl1_Macro34:
Tbl1_Macro35:
Tbl1_Macro36:
Tbl1_Macro37:
Tbl1_Macro38:
Tbl1_Macro39:
Tbl1_Macro40:
Tbl1_Macro41:
Tbl1_Macro42:
Tbl1_Macro43:

;;; page 153 end
;;; page 154 start XXX; FURBY27.INC page 29

Tbl1_Macro44:
Tbl1_Macro45:
Tbl1_Macro46:
Tbl1_Macro47:
Tbl1_Macro48:
Tbl1_Macro49:
Tbl1_Macro50:
Tbl1_Macro51:
Tbl1_Macro52:
Tbl1_Macro53:
Tbl1_Macro54:

;;; page 154 end
;;; page 155 start XXX; FURBY27.INC page 30

Tbl1_Macro55:
Tbl1_Macro56:
Tbl1_Macro57:
Tbl1_Macro58:
Tbl1_Macro59:
Tbl1_Macro60:
Tbl1_Macro61:
Tbl1_Macro62:
Tbl1_Macro63:
Tbl1_Macro64:

;;; page 155 end
;;; page 156 start XXX; FURBY27.INC page 31

Tbl1_Macro65:
Tbl1_Macro66:
Tbl1_Macro67:
Tbl1_Macro68:
Tbl1_Macro69:
Tbl1_Macro70:
Tbl1_Macro71:
Tbl1_Macro72:
Tbl1_Macro73:
Tbl1_Macro74:

;;; page 156 end
;;; page 157 start XXX; FURBY27.INC page 32

Tbl1_Macro75:
Tbl1_Macro76:
Tbl1_Macro77:
Tbl1_Macro78:
Tbl1_Macro79:
Tbl1_Macro80:
Tbl1_Macro81:
Tbl1_Macro82:
Tbl1_Macro83:
Tbl1_Macro84:

;;; page 157 end
;;; page 158 start XXX; FURBY27.INC page 33

Tbl1_Macro85:
Tbl1_Macro86:
Tbl1_Macro87:
Tbl1_Macro88:
Tbl1_Macro89:
Tbl1_Macro90:
Tbl1_Macro91:
Tbl1_Macro92:
Tbl1_Macro93:

;;; page 158 end
;;; page 159 start XXX; FURBY27.INC page 34

Tbl1_Macro94:
Tbl1_Macro95:
Tbl1_Macro96:
Tbl1_Macro97:
Tbl1_Macro98:
Tbl1_Macro99:
Tbl1_Macro100:
Tbl1_Macro101:
Tbl1_Macro102:
Tbl1_Macro103:

;;; page 159 end
;;; page 160 start XXX; FURBY27.INC page 35

Tbl1_Macro104:
Tbl1_Macro105:
Tbl1_Macro106:
Tbl1_Macro107:
Tbl1_Macro108:
Tbl1_Macro109:


Tbl1_Macro110:
Tbl1_Macro111:
Tbl1_Macro112:

;;; page 160 end
;;; page 161 start XXX; FURBY27.INC page 36

Tbl1_Macro113:
Tbl1_Macro114:
Tbl1_Macro115:
Tbl1_Macro116:
Tbl1_Macro117:
Tbl1_Macro118:
Tbl1_Macro119:


Tbl1_Macro120:
Tbl1_Macro121:
Tbl1_Macro122:

;;; page 161 end
;;; page 162 start XXX; FURBY27.INC page 37

Tbl1_Macro123:
Tbl1_Macro124:
Tbl1_Macro125:
Tbl1_Macro126:
Tbl1_Macro127:
Tbl2_Macro128:
Tbl2_Macro129:


;;; page 162 end
;;; page 163 start XXX; FURBY27.INC page 38


Tbl2_Macro130:
Tbl2_Macro131:
Tbl2_Macro132:
Tbl2_Macro133:
Tbl2_Macro134:
Tbl2_Macro135:
Tbl2_Macro136:
Tbl2_Macro137:
Tbl2_Macro138:

;;; page 163 end
;;; page 164 start XXX; FURBY27.INC page 39

Tbl2_Macro139:


Tbl2_Macro140:
Tbl2_Macro141:
Tbl2_Macro142:
Tbl2_Macro143:
Tbl2_Macro144:
Tbl2_Macro145:
Tbl2_Macro146:

;;; page 164 end
;;; page 165 start XXX; FURBY27.INC page 40

Tbl2_Macro147:
Tbl2_Macro148:
Tbl2_Macro149:


Tbl2_Macro150:
Tbl2_Macro151:
Tbl2_Macro152:
Tbl2_Macro153:
Tbl2_Macro154:
Tbl2_Macro155:

;;; page 165 end
;;; page 166 start XXX; FURBY27.INC page 41

Tbl2_Macro156:
Tbl2_Macro157:
Tbl2_Macro158:
Tbl2_Macro159:


Tbl2_Macro160:
Tbl2_Macro161:
Tbl2_Macro162:
Tbl2_Macro163:
Tbl2_Macro164:

;;; page 166 end
;;; page 167 start XXX; FURBY27.INC page 42

Tbl2_Macro165:
Tbl2_Macro166:
Tbl2_Macro167:
Tbl2_Macro168:
Tbl2_Macro169:


Tbl2_Macro170:
Tbl2_Macro171:
Tbl2_Macro172:
Tbl2_Macro173:

;;; page 167 end
;;; page 168 start XXX; FURBY27.INC page 43

Tbl2_Macro174:
Tbl2_Macro175:
Tbl2_Macro176:
Tbl2_Macro177:
Tbl2_Macro178:
Tbl2_Macro179:


Tbl2_Macro180:
Tbl2_Macro181:
Tbl2_Macro182:

;;; page 168 end
;;; page 169 start XXX; FURBY27.INC page 44

Tbl2_Macro183:
Tbl2_Macro184:
Tbl2_Macro185:
Tbl2_Macro186:
Tbl2_Macro187:
Tbl2_Macro188:
Tbl2_Macro189:


Tbl2_Macro190:

;;; page 169 end
;;; page 170 start XXX; FURBY27.INC page 45

Tbl2_Macro191:
Tbl2_Macro192:
Tbl2_Macro193:
Tbl2_Macro194:
Tbl2_Macro195:
Tbl2_Macro196:
Tbl2_Macro197:
Tbl2_Macro198:
Tbl2_Macro199:


;;; page 170 end
;;; page 171 start XXX; FURBY27.INC page 46


Tbl2_Macro200:
Tbl2_Macro201:
Tbl2_Macro202:
Tbl2_Macro203:
Tbl2_Macro204:
Tbl2_Macro205:
Tbl2_Macro206:
Tbl2_Macro207:
Tbl2_Macro208:

;;; page 171 end
;;; page 172 start XXX; FURBY27.INC page 47

Tbl2_Macro209:


Tbl2_Macro210:
Tbl2_Macro211:
Tbl2_Macro212:
Tbl2_Macro213:
Tbl2_Macro214:
Tbl2_Macro215:
Tbl2_Macro216:
Tbl2_Macro217:

;;; page 172 end
;;; page 173 start XXX; FURBY27.INC page 48

Tbl2_Macro218:
Tbl2_Macro219:


Tbl2_Macro220:
Tbl2_Macro221:
Tbl2_Macro222:
Tbl2_Macro223:
Tbl2_Macro224:
Tbl2_Macro225:
Tbl2_Macro226:
Tbl2_Macro227:

;;; page 173 end
;;; page 174 start XXX; FURBY27.INC page 49

Tbl2_Macro228:
Tbl2_Macro229:


Tbl2_Macro230:
Tbl2_Macro231:
Tbl2_Macro232:
Tbl2_Macro233:
Tbl2_Macro234:
Tbl2_Macro235:
Tbl2_Macro236:
Tbl2_Macro237:
Tbl2_Macro238:

;;; page 174 end
;;; page 175 start XXX; FURBY27.INC page 50

Tbl2_Macro239:


Tbl2_Macro240:
Tbl2_Macro241:
Tbl2_Macro242:
Tbl2_Macro243:
Tbl2_Macro244:
Tbl2_Macro245:
Tbl2_Macro246:
Tbl2_Macro247:

;;; page 175 end
;;; page 176 start XXX; FURBY27.INC page 51

Tbl2_Macro248:
Tbl2_Macro249:


Tbl2_Macro250:
Tbl2_Macro251:
Tbl2_Macro252:
Tbl2_Macro253:
Tbl2_Macro254:
Tbl2_Macro255:
Tbl3_Macro256:

;;; page 176 end
;;; page 177 start XXX; FURBY27.INC page 52

Tbl3_Macro257:
Tbl3_Macro258:
Tbl3_Macro259:


Tbl3_Macro260:
Tbl3_Macro261:
Tbl3_Macro262:
Tbl3_Macro263:
Tbl3_Macro264:

;;; page 177 end
;;; page 178 start XXX; FURBY27.INC page 53

Tbl3_Macro265:
Tbl3_Macro266:
Tbl3_Macro267:
Tbl3_Macro268:
Tbl3_Macro269:


Tbl3_Macro270:
Tbl3_Macro271:
Tbl3_Macro272:
Tbl3_Macro273:
Tbl3_Macro274:

;;; page 178 end
;;; page 179 start XXX; FURBY27.INC page 54

Tbl3_Macro275:
Tbl3_Macro276:
Tbl3_Macro277:
Tbl3_Macro278:
Tbl3_Macro279:


Tbl3_Macro280:
Tbl3_Macro281:
Tbl3_Macro282:

;;; page 179 end
;;; page 180 start XXX; FURBY27.INC page 55

Tbl3_Macro283:
Tbl3_Macro284:
Tbl3_Macro285:
Tbl3_Macro286:
Tbl3_Macro287:
Tbl3_Macro288:
Tbl3_Macro289:


Tbl3_Macro290:
Tbl3_Macro291:
Tbl3_Macro292:

;;; page 180 end
;;; page 181 start XXX; FURBY27.INC page 56

Tbl3_Macro293:
Tbl3_Macro294:
Tbl3_Macro295:
Tbl3_Macro296:
Tbl3_Macro297:
Tbl3_Macro298:
Tbl3_Macro299:



Tbl3_Macro300:
Tbl3_Macro301:
Tbl3_Macro302:
Tbl3_Macro303:
Tbl3_Macro304:
Tbl3_Macro305:

;;; page 181 end
;;; page 182 start XXX; FURBY27.INC page 57

Tbl3_Macro306:
Tbl3_Macro307:
Tbl3_Macro308:
Tbl3_Macro309:


Tbl3_Macro310:
Tbl3_Macro311:
Tbl3_Macro312:
Tbl3_Macro313:
Tbl3_Macro314:
Tbl3_Macro315:
Tbl3_Macro316:
Tbl3_Macro317:
Tbl3_Macro318:
Tbl3_Macro319:


Tbl3_Macro320:

;;; page 182 end
;;; page 183 start XXX; FURBY27.INC page 58

Tbl3_Macro321:
Tbl3_Macro322:
Tbl3_Macro323:
Tbl3_Macro324:
Tbl3_Macro325:
Tbl3_Macro326:
Tbl3_Macro327:
Tbl3_Macro328:
Tbl3_Macro329:


Tbl3_Macro330:
Tbl3_Macro331:
Tbl3_Macro332:
Tbl3_Macro333:
Tbl3_Macro334:

;;; page 183 end
;;; page 184 start XXX; FURBY27.INC page 59

Tbl3_Macro335:
Tbl3_Macro336:
Tbl3_Macro337:
Tbl3_Macro338:
Tbl3_Macro339:


Tbl3_Macro340:
Tbl3_Macro341:
Tbl3_Macro342:
Tbl3_Macro343:
Tbl3_Macro344:
Tbl3_Macro345:
Tbl3_Macro346:
Tbl3_Macro347:

;;; page 184 end
;;; page 185 start XXX; FURBY27.INC page 60

Tbl3_Macro348:
Tbl3_Macro349:


Tbl3_Macro350:
Tbl3_Macro351:
Tbl3_Macro352:
Tbl3_Macro353:
Tbl3_Macro354:
Tbl3_Macro355:
Tbl3_Macro356:
Tbl3_Macro357:
Tbl3_Macro358:
Tbl3_Macro359:


Tbl3_Macro360:
Tbl3_Macro361:

;;; page 185 end
;;; page 186 start XXX; FURBY27.INC page 61

Tbl3_Macro362:
Tbl3_Macro363:
Tbl3_Macro364:
Tbl3_Macro365:
Tbl3_Macro366:
Tbl3_Macro367:
Tbl3_Macro368:
Tbl3_Macro369:


Tbl3_Macro370:
Tbl3_Macro371:
Tbl3_Macro372:
Tbl3_Macro373:
Tbl3_Macro374:

;;; page 186 end
;;; page 187 start XXX; FURBY27.INC page 62

Tbl3_Macro375:
Tbl3_Macro376:
Tbl3_Macro377:
Tbl3_Macro378:
Tbl3_Macro379:


Tbl3_Macro380:
Tbl3_Macro381:
Tbl3_Macro382:
Tbl3_Macro383:
Tbl4_Macro384:
Tbl4_Macro385:
Tbl4_Macro386:
Tbl4_Macro387:

;;; page 187 end
;;; page 188 start XXX; FURBY27.INC page 63

Tbl4_Macro388:
Tbl4_Macro389:


Tbl4_Macro390:
Tbl4_Macro391:
Tbl4_Macro392:
Tbl4_Macro393:
Tbl4_Macro394:
Tbl4_Macro395:
Tbl4_Macro396:
Tbl4_Macro397:
Tbl4_Macro398:
Tbl4_Macro399:


;;; page 188 end
;;; page 189 start XXX; FURBY27.INC page 64




Tbl4_Macro400:
Tbl4_Macro401:
Tbl4_Macro402:
Tbl4_Macro403:
Tbl4_Macro404:
Tbl4_Macro405:
Tbl4_Macro406:
Tbl4_Macro407:
Tbl4_Macro408:
Tbl4_Macro409:


Tbl4_Macro410:
Tbl4_Macro411:
Tbl4_Macro412:
Tbl4_Macro413:
Tbl4_Macro414:

;;; page 189 end
;;; page 190 start XXX; FURBY27.INC page 65

Tbl4_Macro415:
Tbl4_Macro416:
Tbl4_Macro417:
Tbl4_Macro418:
Tbl4_Macro419:


Tbl4_Macro420:
Tbl4_Macro421:
Tbl4_Macro422:
Tbl4_Macro423:
Tbl4_Macro424:
Tbl4_Macro425:
Tbl4_Macro426:
Tbl4_Macro427:
Tbl4_Macro428:
Tbl4_Macro429:

;;; page 190 end
;;; page 191 start XXX; FURBY27.INC page 66



Tbl4_Macro430:
Tbl4_Macro431:
Tbl4_Macro432:
Tbl4_Macro433:
Tbl4_Macro434:
Tbl4_Macro435:
Tbl4_Macro436:
Tbl4_Macro437:
Tbl4_Macro438:
Tbl4_Macro439:


Tbl4_Macro440:
Tbl4_Macro441:

;;; page 191 end
;;; page 192 start XXX; FURBY27.INC page 67

Tbl4_Macro442:
Tbl4_Macro443:
Tbl4_Macro444:
Tbl4_Macro445:
Tbl4_Macro446:
Tbl4_Macro447:
Tbl4_Macro448:
Tbl4_Macro449:


Tbl4_Macro450:
Tbl4_Macro451:
Tbl4_Macro452:
Tbl4_Macro453:
Tbl4_Macro454:
Tbl4_Macro455:

;;; page 192 end
;;; page 193 start XXX; FURBY27.INC page 68

Tbl4_Macro456:
Tbl4_Macro457:
Tbl4_Macro458:
Tbl4_Macro459:


Tbl4_Macro460:
Tbl4_Macro461:
Tbl4_Macro462:
Tbl4_Macro463:
Tbl4_Macro464:
Tbl4_Macro465:

;;; page 193 end
;;; page 194 start XXX; FURBY27.INC page 69

Tbl4_Macro466:
Tbl4_Macro467:
Tbl4_Macro468:
Tbl4_Macro469:


Tbl4_Macro470:
Tbl4_Macro471:
Tbl4_Macro472:
Tbl4_Macro473:
Tbl4_Macro474:

;;; page 194 end
;;; page 195 start XXX; FURBY27.INC page 70

Tbl4_Macro475:
Tbl4_Macro476:
Tbl4_Macro477:
Tbl4_Macro478:
Tbl4_Macro479:


Tbl4_Macro480:
Tbl4_Macro481:
Tbl4_Macro482:
Tbl4_Macro483:
Tbl4_Macro484:

;;; page 195 end
;;; page 196 start XXX; FURBY27.INC page 71

Tbl4_Macro485:
Tbl4_Macro486:
Tbl4_Macro487:
Tbl4_Macro488:
Tbl4_Macro489:


Tbl4_Macro490:
Tbl4_Macro491:
Tbl4_Macro492:
Tbl4_Macro493:
Tbl4_Macro494:
Tbl4_Macro495:
Tbl4_Macro496:
Tbl4_Macro497:
Tbl4_Macro498:

;;; page 196 end
;;; page 197 start XXX; FURBY27.INC page 72

Tbl4_Macro499:




Tbl4_Macro500:
Tbl4_Macro501:
Tbl4_Macro502:
Tbl4_Macro503:
Tbl4_Macro504:
Tbl4_Macro505:
Tbl4_Macro506:
Tbl4_Macro507:
Tbl4_Macro508:
Tbl4_Macro509:


Tbl4_Macro510:
Tbl4_Macro511:


;;; page 197 end
;;; page 198 start XXX; FURBY27.INC page 73

Spch_grp1:

;;; page 198 end
;;; page 199 start XXX; FURBY27.INC page 74

Spch_grp2:

Spch_grp3:

;;; page 199 end
;;; page 200 start XXX; FURBY27.INC page 75

Spch_grp4:

;;; page 200 end
;;; page 201 start XXX; FURBY27.INC page 76

Tbl1_say000:

Tbl1_say001:

Tbl1_say002:


;;; page 201 end
;;; page 202 start XXX; FURBY27.INC page 77

Tbl1_say003:

Tbl1_say004:

Tbl1_say005:

Tbl1_say006:
Tbl1_say007:
Tbl1_say008:
Tbl1_say009:
Tbl1_say010:
Tbl1_say011:
Tbl1_say012:

;;; page 202 end
;;; page 203 start XXX; FURBY27.INC page 78

Tbl1_say013:
Tbl1_say014:
Tbl1_say015:
Tbl1_say016:
Tbl1_say017:
Tbl1_say018:
Tbl1_say019:
Tbl1_say020:
Tbl1_say021:

;;; page 203 end
;;; page 204 start XXX; FURBY27.INC page 79

Tbl1_say022:
Tbl1_say023:
Tbl1_say024:
Tbl1_say025:
Tbl1_say026:
Tbl1_say027:
Tbl1_say028:
Tbl1_say029:
Tbl1_say030:
Tbl1_say031:

;;; page 204 end
;;; page 205 start XXX; FURBY27.INC page 80


Tbl1_say032:
Tbl1_say033:
Tbl1_say034:
Tbl1_say035:
Tbl1_say036:
Tbl1_say037:
Tbl1_say038:
Tbl1_say039:

;;; page 205 end
;;; page 206 start XXX; FURBY27.INC page 81

Tbl1_say040:
Tbl1_say041:
Tbl1_say042:
Tbl1_say043:
Tbl1_say044:
Tbl1_say045:
Tbl1_say046:
Tbl1_say047:
Tbl1_say048:

;;; page 206 end
;;; page 207 start XXX; FURBY27.INC page 82

Tbl1_say049:
Tbl1_say050:
Tbl1_say051:
Tbl1_say052:
Tbl1_say053:
Tbl1_say054:
Tbl1_say055:
Tbl1_say056:
Tbl1_say057:
Tbl1_say058:

;;; page 207 end
;;; page 208 start XXX; FURBY27.INC page 83

Tbl1_say059:
Tbl1_say060:
Tbl1_say061:
Tbl1_say062:
Tbl1_say063:
Tbl1_say064:
Tbl1_say065:
Tbl1_say066:
Tbl1_say067:

;;; page 208 end
;;; page 209 start XXX; FURBY27.INC page 84

Tbl1_say068:
Tbl1_say069:
Tbl1_say070:
Tbl1_say071:
Tbl1_say072:
Tbl1_say073:
Tbl1_say074:
Tbl1_say075:
Tbl1_say076:
Tbl1_say077:

;;; page 209 end
;;; page 210 start XXX; FURBY27.INC page 85

Tbl1_say078:
Tbl1_say079:
Tbl1_say080:
Tbl1_say081:
Tbl1_say082:
Tbl1_say083:
Tbl1_say084:
Tbl1_say085:
Tbl1_say086:

;;; page 210 end
;;; page 211 start XXX; FURBY27.INC page 86

Tbl1_say087:
Tbl1_say088:
Tbl1_say089:
Tbl1_say090:
Tbl1_say091:
Tbl1_say092:
Tbl1_say093:
Tbl1_say094:
Tbl1_say095:
Tbl1_say096:

;;; page 211 end
;;; page 212 start XXX; FURBY27.INC page 87

Tbl1_say097:
Tbl1_say098:
Tbl1_say099:
Tbl1_say100:
Tbl1_say101:
Tbl1_say102:
Tbl1_say103:
Tbl1_say104:
Tbl1_say105:
Tbl1_say106:

;;; page 212 end
;;; page 213 start XXX; FURBY27.INC page 88

Tbl1_say107:
Tbl1_say108:
Tbl1_say109:


Tbl1_say110:
Tbl1_say111:
Tbl1_say112:

;;; page 213 end
;;; page 214 start XXX; FURBY27.INC page 89

Tbl1_say113:
Tbl1_say114:
Tbl1_say115:
Tbl1_say116:
Tbl1_say117:
Tbl1_say118:
Tbl1_say119:


Tbl1_say120:
Tbl1_say121:

;;; page 214 end
;;; page 215 start XXX; FURBY27.INC page 90

Tbl1_say122:
Tbl1_say123:
Tbl1_say124:
Tbl1_say125:
Tbl1_say126:

;;; page 215 end
;;; page 216 start XXX; FURBY27.INC page 91

Tbl1_say127:
Tbl2_say128:
Tbl2_say129:

Tbl2_say130:
Tbl2_say131:
Tbl2_say132:
Tbl2_say133:
Tbl2_say134:

;;; page 216 end
;;; page 217 start XXX; FURBY27.INC page 92

Tbl2_say135:
Tbl2_say136:
Tbl2_say137:
Tbl2_say138:
Tbl2_say139:


Tbl2_say140:
Tbl2_say141:
Tbl2_say142:
Tbl2_say143:
Tbl2_say144:

;;; page 217 end
;;; page 218 start XXX; FURBY27.INC page 93

Tbl2_say145:
Tbl2_say146:
Tbl2_say147:
Tbl2_say148:
Tbl2_say149:


Tbl2_say150:
Tbl2_say151:
Tbl2_say152:
Tbl2_say153:

;;; page 218 end
;;; page 219 start XXX; FURBY27.INC page 94

Tbl2_say154:
Tbl2_say155:
Tbl2_say156:
Tbl2_say157:
Tbl2_say158:
Tbl2_say159:


Tbl2_say160:
Tbl2_say161:

;;; page 219 end
;;; page 220 start XXX; FURBY27.INC page 95

Tbl2_say162:
Tbl2_say163:
Tbl2_say164:
Tbl2_say165:
Tbl2_say166:
Tbl2_say167:
Tbl2_say168:
Tbl2_say169:

;;; page 220 end
;;; page 221 start XXX; FURBY27.INC page 96



Tbl2_say170:
Tbl2_say171:
Tbl2_say172:
Tbl2_say173:
Tbl2_say174:
Tbl2_say175:
Tbl2_say176:
Tbl2_say177:
Tbl2_say178:
Tbl2_say179:

;;; page 221 end
;;; page 222 start XXX; FURBY27.INC page 97



Tbl2_say180:
Tbl2_say181:
Tbl2_say182:
Tbl2_say183:
Tbl2_say184:
Tbl2_say185:
Tbl2_say186:
Tbl2_say187:
Tbl2_say188:

;;; page 222 end
;;; page 223 start XXX; FURBY27.INC page 98

Tbl2_say189:


Tbl2_say190:
Tbl2_say191:
Tbl2_say192:
Tbl2_say193:
Tbl2_say194:
Tbl2_say195:
Tbl2_say196:
Tbl2_say197:
Tbl2_say198:

;;; page 223 end
;;; page 224 start XXX; FURBY27.INC page 99

Tbl2_say199:

Tbl2_say200:
Tbl2_say201:
Tbl2_say202:
Tbl2_say203:
Tbl2_say204:
Tbl2_say205:
Tbl2_say206:
Tbl2_say207:

;;; page 224 end
;;; page 225 start XXX; FURBY27.INC page 100

Tbl2_say208:
Tbl2_say209:


Tbl2_say210:
Tbl2_say211:
Tbl2_say212:
Tbl2_say213:
Tbl2_say214:
Tbl2_say215:
Tbl2_say216:
Tbl2_say217:

;;; page 225 end
;;; page 226 start XXX; FURBY27.INC page 101

Tbl2_say218:
Tbl2_say219:


Tbl2_say220:
Tbl2_say221:
Tbl2_say222:
Tbl2_say223:
Tbl2_say224:
Tbl2_say225:
Tbl2_say226:
Tbl2_say227:

;;; page 226 end
;;; page 227 start XXX; FURBY27.INC page 102

Tbl2_say228:
Tbl2_say229:


Tbl2_say230:
Tbl2_say231:
Tbl2_say232:
Tbl2_say233:
Tbl2_say234:
Tbl2_say235:
Tbl2_say236:

;;; page 227 end
;;; page 228 start XXX; FURBY27.INC page 103

Tbl2_say237:
Tbl2_say238:
Tbl2_say239:


Tbl2_say240:
Tbl2_say241:
Tbl2_say242:
Tbl2_say243:

;;; page 228 end
;;; page 229 start XXX; FURBY27.INC page 104

Tbl2_say244:
Tbl2_say245:
Tbl2_say246:
Tbl2_say247:
Tbl2_say248:
Tbl2_say249:


Tbl2_say250:

;;; page 229 end
;;; page 230 start XXX; FURBY27.INC page 105

Tbl2_say251:
Tbl2_say252:
Tbl2_say253:
Tbl2_say254:
Tbl2_say255:
Tbl3_say256:
Tbl3_say257:
Tbl3_say258:
Tbl3_say259:


Tbl3_say260:

;;; page 230 end
;;; page 231 start XXX; FURBY27.INC page 106

Tbl3_say261:
Tbl3_say262:
Tbl3_say263:
Tbl3_say264:
Tbl3_say265:
Tbl3_say266:
Tbl3_say267:
Tbl3_say268:
Tbl3_say269:

;;; page 231 end
;;; page 232 start XXX; FURBY27.INC page 107



Tbl3_say270:
Tbl3_say271:
Tbl3_say272:
Tbl3_say273:
Tbl3_say274:
Tbl3_say275:
Tbl3_say276:
Tbl3_say277:
Tbl3_say278:
Tbl3_say279:

;;; page 232 end
;;; page 233 start XXX; FURBY27.INC page 108



Tbl3_say280:
Tbl3_say281:
Tbl3_say282:
Tbl3_say283:
Tbl3_say284:
Tbl3_say285:
Tbl3_say286:
Tbl3_say287:
Tbl3_say288:
Tbl3_say289:

;;; page 233 end
;;; page 234 start XXX; FURBY27.INC page 109



Tbl3_say290:
Tbl3_say291:
Tbl3_say292:
Tbl3_say293:
Tbl3_say294:
Tbl3_say295:
Tbl3_say296:
Tbl3_say297:
Tbl3_say298:

;;; page 234 end
;;; page 235 start XXX; FURBY27.INC page 110

Tbl3_say299:



Tbl3_say300:
Tbl3_say301:
Tbl3_say302:
Tbl3_say303:
Tbl3_say304:
Tbl3_say305:
Tbl3_say306:
Tbl3_say307:

;;; page 235 end
;;; page 236 start XXX; FURBY27.INC page 111

Tbl3_say308:
Tbl3_say309:


Tbl3_say310:
Tbl3_say311:
Tbl3_say312:
Tbl3_say313:
Tbl3_say314:
Tbl3_say315:
Tbl3_say316:
Tbl3_say317:

;;; page 236 end
;;; page 237 start XXX; FURBY27.INC page 112

Tbl3_say318:
Tbl3_say319:


Tbl3_say320:
Tbl3_say321:
Tbl3_say322:
Tbl3_say323:
Tbl3_say324:
Tbl3_say325:
Tbl3_say326:
Tbl3_say327:

;;; page 237 end
;;; page 238 start XXX; FURBY27.INC page 113

Tbl3_say328:
Tbl3_say329:


Tbl3_say330:
Tbl3_say331:
Tbl3_say332:
Tbl3_say333:
Tbl3_say334:
Tbl3_say335:
Tbl3_say336:

;;; page 238 end
;;; page 239 start XXX; FURBY27.INC page 114

Tbl3_say337:
Tbl3_say338:
Tbl3_say339:


Tbl3_say340:
Tbl3_say341:
Tbl3_say342:
Tbl3_say343:
Tbl3_say344:
Tbl3_say345:
Tbl3_say346:

;;; page 239 end
;;; page 240 start XXX; FURBY27.INC page 115

Tbl3_say347:
Tbl3_say348:
Tbl3_say349:


Tbl3_say350:
Tbl3_say351:
Tbl3_say352:
Tbl3_say353:
Tbl3_say354:
Tbl3_say355:
Tbl3_say356:

;;; page 240 end
;;; page 241 start XXX; FURBY27.INC page 116

Tbl3_say357:
Tbl3_say358:
Tbl3_say359:


Tbl3_say360:
Tbl3_say361:
Tbl3_say362:
Tbl3_say363:
Tbl3_say364:
Tbl3_say365:
Tbl3_say366:

;;; page 241 end
;;; page 242 start XXX; FURBY27.INC page 117

Tbl3_say367:
Tbl3_say368:
Tbl3_say369:


Tbl3_say370:
Tbl3_say371:
Tbl3_say372:
Tbl3_say373:
Tbl3_say374:
Tbl3_say375:

;;; page 242 end
;;; page 243 start XXX; FURBY27.INC page 118

Tbl3_say376:
Tbl3_say377:
Tbl3_say378:
Tbl3_say379:


Tbl3_say380:
Tbl3_say381:
Tbl3_say382:
Tbl3_say383:
Tbl4_say384:
Tbl4_say385:

;;; page 243 end
;;; page 244 start XXX; FURBY27.INC page 119

Tbl4_say386:
Tbl4_say387:
Tbl4_say388:
Tbl4_say389:


Tbl4_say390:
Tbl4_say391:

;;; page 244 end
;;; page 245 start XXX; FURBY27.INC page 120

Tbl4_say392:
Tbl4_say393:
Tbl4_say394:
Tbl4_say395:
Tbl4_say396:
Tbl4_say397:
Tbl4_say398:
Tbl4_say399:




Tbl4_say400:
Tbl4_say401:

;;; page 245 end
;;; page 246 start XXX; FURBY27.INC page 121

Tbl4_say402:
Tbl4_say403:
Tbl4_say404:
Tbl4_say405:
Tbl4_say406:
Tbl4_say407:
Tbl4_say408:
Tbl4_say409:


Tbl4_say410:
Tbl4_say411:

;;; page 246 end
;;; page 247 start XXX; FURBY27.INC page 122

Tbl4_say412:
Tbl4_say413:
Tbl4_say414:
Tbl4_say415:
Tbl4_say416:
Tbl4_say417:
Tbl4_say418:
Tbl4_say419:


Tbl4_say420:
Tbl4_say421:
Tbl4_say422:
Tbl4_say423:
Tbl4_say424:
Tbl4_say425:
Tbl4_say426:
Tbl4_say427:
Tbl4_say428:
Tbl4_say429:


Tbl4_say430:
Tbl4_say431:
Tbl4_say432:
Tbl4_say433:
Tbl4_say434:
Tbl4_say435:
Tbl4_say436:
Tbl4_say437:

;;; page 247 end
;;; page 248 start XXX; FURBY27.INC page 123

Tbl4_say438:
Tbl4_say439:


Tbl4_say440:
Tbl4_say441:
Tbl4_say442:
Tbl4_say443:
Tbl4_say444:
Tbl4_say445:
Tbl4_say446:
Tbl4_say447:
Tbl4_say448:
Tbl4_say449:


Tbl4_say450:
Tbl4_say451:
Tbl4_say452:
Tbl4_say453:
Tbl4_say454:
Tbl4_say455:
Tbl4_say456:
Tbl4_say457:
Tbl4_say458:
Tbl4_say459:


Tbl4_say460:
Tbl4_say461:
Tbl4_say462:
Tbl4_say463:
Tbl4_say464:
Tbl4_say465:
Tbl4_say466:
Tbl4_say467:

;;; page 248 end
;;; page 249 start XXX; FURBY27.INC page 124

Tbl4_say468:
Tbl4_say469:


Tbl4_say470:
Tbl4_say471:
Tbl4_say472:
Tbl4_say473:
Tbl4_say474:
Tbl4_say475:
Tbl4_say476:
Tbl4_say477:
Tbl4_say478:
Tbl4_say479:


Tbl4_say480:
Tbl4_say481:
Tbl4_say482:
Tbl4_say483:
Tbl4_say484:
Tbl4_say485:
Tbl4_say486:
Tbl4_say487:
Tbl4_say488:
Tbl4_say489:


Tbl4_say490:
Tbl4_say491:
Tbl4_say492:
Tbl4_say493:
Tbl4_say494:
Tbl4_say495:
Tbl4_say496:
Tbl4_say497:

;;; page 249 end
;;; page 250 start XXX; FURBY27.INC page 125

Tbl4_say498:
Tbl4_say499:




Tbl4_say500:
Tbl4_say501:
Tbl4_say502:
Tbl4_say503:
Tbl4_say504:
Tbl4_say505:
Tbl4_say506:
Tbl4_say507:
Tbl4_say508:
Tbl4_say509:


Tbl4_say510:
Tbl4_say511:

Motor_grp1:


;;; page 250 end
;;; page 251 start XXX; FURBY27.INC page 126


Motor_grp2:
Motor_grp3:

;;; page 251 end
;;; page 252 start XXX; FURBY27.INC page 127

Motor_grp4:

;;; page 252 end
;;; page 253 start XXX; FURBY27.INC page 128

Tbl1_M000:

Tbl1_M001:

Tbl1_M002:

Tbl1_M003:

Tbl1_M004:

Tbl1_M005:

Tbl1_M006:
Tbl1_M007:
Tbl1_M008:
;;; page 253 end
;;; page 254 start XXX; FURBY27.INC page 129
Tbl1_M009:
Tbl1_M010:
Tbl1_M011:
Tbl1_M012:
Tbl1_M013:
Tbl1_M014:
Tbl1_M015:
Tbl1_M016:
Tbl1_M017:
Tbl1_M018:
;;; page 254 end
;;; page 255 start XXX; FURBY27.INC page 130
Tbl1_M019:
Tbl1_M020:
Tbl1_M021:
Tbl1_M022:
Tbl1_M023:
Tbl1_M024:
Tbl1_M025:
Tbl1_M026:
Tbl1_M027:
Tbl1_M028:
Tbl1_M029:
;;; page 255 end
;;; page 256 start XXX; FURBY27.INC page 131
Tbl1_M030:
Tbl1_M031:

Tbl1_M032:
Tbl1_M033:
Tbl1_M034:
Tbl1_M035:
Tbl1_M036:
Tbl1_M037:
Tbl1_M038:
Tbl1_M039:
;;; page 256 end
;;; page 257 start XXX; FURBY27.INC page 132
Tbl1_M040:
Tbl1_M041:
Tbl1_M042:
Tbl1_M043:
Tbl1_M044:
Tbl1_M045:
Tbl1_M046:
Tbl1_M047:
Tbl1_M048:
Tbl1_M049:
Tbl1_M050:
;;; page 257 end
;;; page 258 start XXX; FURBY27.INC page 133
Tbl1_M051:
Tbl1_M052:
Tbl1_M053:
Tbl1_M054:
Tbl1_M055:
Tbl1_M056:
Tbl1_M057:
Tbl1_M058:
Tbl1_M059:
Tbl1_M060:
Tbl1_M061:
;;; page 258 end
;;; page 259 start XXX; FURBY27.INC page 134
Tbl1_M062:
Tbl1_M063:
Tbl1_M064:
Tbl1_M065:
Tbl1_M066:
Tbl1_M067:
Tbl1_M068:
Tbl1_M069:
Tbl1_M070:
Tbl1_M071:
Tbl1_M072:
;;; page 259 end
;;; page 260 start XXX; FURBY27.INC page 135
Tbl1_M073:
Tbl1_M074:
Tbl1_M075:
Tbl1_M076:
Tbl1_M077:
Tbl1_M078:
Tbl1_M079:
Tbl1_M080:
Tbl1_M081:
Tbl1_M082:
Tbl1_M083:
Tbl1_M084:
;;; page 260 end
;;; page 261 start XXX; FURBY27.INC page 136
Tbl1_M085:
Tbl1_M086:
Tbl1_M087:
Tbl1_M088:
Tbl1_M089:
Tbl1_M090:
Tbl1_M091:
Tbl1_M092:
;;; page 261 end
;;; page 262 start XXX; FURBY27.INC page 137
Tbl1_M093:
Tbl1_M094:
Tbl1_M095:
Tbl1_M096:
Tbl1_M097:
Tbl1_M098:
Tbl1_M099:
Tbl1_M100:
Tbl1_M101:
Tbl1_M102:
Tbl1_M103:
Tbl1_M104:
;;; page 262 end
;;; page 263 start XXX; FURBY27.INC page 138
Tbl1_M105:
Tbl1_M106:
Tbl1_M107:
Tbl1_M108:
Tbl1_M109:


Tbl1_M110:
Tbl1_M111:
Tbl1_M112:
Tbl1_M113:
Tbl1_M114:
;;; page 263 end
;;; page 264 start XXX; FURBY27.INC page 139
Tbl1_M115:
Tbl1_M116:
Tbl1_M117:
Tbl1_M118:
Tbl1_M119:


Tbl1_M120:
Tbl1_M121:
Tbl1_M122:
Tbl1_M123:
Tbl1_M124:
;;; page 264 end
;;; page 265 start XXX; FURBY27.INC page 140
Tbl1_M125:
Tbl1_M126:
Tbl1_M127:
Tbl2_M128:
Tbl2_M129:

Tbl2_M130:
Tbl2_M131:
Tbl2_M132:
Tbl2_M133:
Tbl2_M134:
Tbl2_M135:
Tbl2_M136:
;;; page 265 end
;;; page 266 start XXX; FURBY27.INC page 141
Tbl2_M137:
Tbl2_M138:
Tbl2_M139:


Tbl2_M140:
Tbl2_M141:
Tbl2_M142:
Tbl2_M143:
Tbl2_M144:
Tbl2_M145:
Tbl2_M146:
Tbl2_M147:
;;; page 266 end
;;; page 267 start XXX; FURBY27.INC page 142
Tbl2_M148:
Tbl2_M149:


Tbl2_M150:
Tbl2_M151:
Tbl2_M152:
Tbl2_M153:
Tbl2_M154:
Tbl2_M155:
Tbl2_M156:
Tbl2_M157:
Tbl2_M158:
;;; page 267 end
;;; page 268 start XXX; FURBY27.INC page 143
Tbl2_M159:


Tbl2_M160:
Tbl2_M161:
Tbl2_M162:
Tbl2_M163:
Tbl2_M164:
Tbl2_M165:
Tbl2_M166:
Tbl2_M167:
Tbl2_M168:
;;; page 268 end
;;; page 269 start XXX; FURBY27.INC page 144
Tbl2_M169:


Tbl2_M170:
Tbl2_M171:
Tbl2_M172:
Tbl2_M173:
Tbl2_M174:
Tbl2_M175:
Tbl2_M176:
Tbl2_M177:
Tbl2_M178:
;;; page 269 end
;;; page 270 start XXX; FURBY27.INC page 145
Tbl2_M179:


Tbl2_M180:
Tbl2_M181:
Tbl2_M182:
Tbl2_M183:
Tbl2_M184:
Tbl2_M185:
Tbl2_M186:
Tbl2_M187:
Tbl2_M188:
Tbl2_M189:


Tbl2_M190:
;;; page 270 end
;;; page 271 start XXX; FURBY27.INC page 146
Tbl2_M191:
Tbl2_M192:
Tbl2_M193:
Tbl2_M194:
Tbl2_M195:
Tbl2_M196:
Tbl2_M197:
Tbl2_M198:
Tbl2_M199:

Tbl2_M200:
Tbl2_M201:
;;; page 271 end
;;; page 272 start XXX; FURBY27.INC page 147
Tbl2_M202:
Tbl2_M203:
Tbl2_M204:
Tbl2_M205:
Tbl2_M206:
Tbl2_M207:
Tbl2_M208:
Tbl2_M209:


Tbl2_M210:
Tbl2_M211:
Tbl2_M212:
;;; page 272 end
;;; page 273 start XXX; FURBY27.INC page 148
Tbl2_M213:
Tbl2_M214:
Tbl2_M215:
Tbl2_M216:
Tbl2_M217:
Tbl2_M218:
Tbl2_M219:


Tbl2_M220:
Tbl2_M221:
Tbl2_M222:
Tbl2_M223:
;;; page 273 end
;;; page 274 start XXX; FURBY27.INC page 149
Tbl2_M224:
Tbl2_M225:
Tbl2_M226:
Tbl2_M227:
Tbl2_M228:
Tbl2_M229:


Tbl2_M230:
Tbl2_M231:
Tbl2_M232:
Tbl2_M233:
Tbl2_M234:
Tbl2_M235:
;;; page 274 end
;;; page 275 start XXX; FURBY27.INC page 150
Tbl2_M236:
Tbl2_M237:
Tbl2_M238:
Tbl2_M239:


Tbl2_M240:
Tbl2_M241:
Tbl2_M242:
Tbl2_M243:
Tbl2_M244:
Tbl2_M245:
Tbl2_M246:
;;; page 275 end
;;; page 276 start XXX; FURBY27.INC page 151
Tbl2_M247:
Tbl2_M248:
Tbl2_M249:


Tbl2_M250:
Tbl2_M251:
Tbl2_M252:
Tbl2_M253:
Tbl2_M254:
Tbl2_M255:
Tbl3_M256:
Tbl3_M257:
Tbl3_M258:
;;; page 276 end
;;; page 277 start XXX; FURBY27.INC page 152
Tbl3_M259:


Tbl3_M260:
Tbl3_M261:
Tbl3_M262:
Tbl3_M263:
Tbl3_M264:
Tbl3_M265:
Tbl3_M266:
Tbl3_M267:
Tbl3_M268:
Tbl3_M269:


Tbl3_M270:
;;; page 277 end
;;; page 278 start XXX; FURBY27.INC page 153
Tbl3_M271:
Tbl3_M272:
Tbl3_M273:
Tbl3_M274:
Tbl3_M275:
Tbl3_M276:
Tbl3_M277:
Tbl3_M278:
Tbl3_M279:


Tbl3_M280:
Tbl3_M281:
;;; page 278 end
;;; page 279 start XXX; FURBY27.INC page 154
Tbl3_M282:
Tbl3_M283:
Tbl3_M284:
Tbl3_M285:
Tbl3_M286:
Tbl3_M287:
Tbl3_M288:
Tbl3_M289:


Tbl3_M290:
Tbl3_M291:
;;; page 279 end
;;; page 280 start XXX; FURBY27.INC page 155
Tbl3_M292:
Tbl3_M293:
Tbl3_M294:
Tbl3_M295:
Tbl3_M296:
Tbl3_M297:
Tbl3_M298:
Tbl3_M299:



;;; page 280 end
;;; page 281 start XXX; FURBY27.INC page 156
Tbl3_M300:
Tbl3_M301:
Tbl3_M302:
Tbl3_M303:
Tbl3_M304:
Tbl3_M305:
Tbl3_M306:
Tbl3_M307:
Tbl3_M308:
;;; page 281 end
;;; page 282 start XXX; FURBY27.INC page 157
Tbl3_M309:


Tbl3_M310:
Tbl3_M311:
Tbl3_M312:
Tbl3_M313:
Tbl3_M314:
Tbl3_M315:
Tbl3_M316:
Tbl3_M317:
Tbl3_M318:
;;; page 282 end
;;; page 283 start XXX; FURBY27.INC page 158
Tbl3_M319:


Tbl3_M320:
Tbl3_M321:
Tbl3_M322:
Tbl3_M323:
Tbl3_M324:
Tbl3_M325:
Tbl3_M326:
Tbl3_M327:
Tbl3_M328:
Tbl3_M329:


;;; page 283 end
;;; page 284 start XXX; FURBY27.INC page 159
Tbl3_M330:
Tbl3_M331:
Tbl3_M332:
Tbl3_M333:
Tbl3_M334:
Tbl3_M335:
Tbl3_M336:
Tbl3_M337:
Tbl3_M338:
;;; page 284 end
;;; page 285 start XXX; FURBY27.INC page 160
Tbl3_M339:


Tbl3_M340:
Tbl3_M341:
Tbl3_M342:
Tbl3_M343:
Tbl3_M344:
Tbl3_M345:
Tbl3_M346:
Tbl3_M347:
Tbl3_M348:
;;; page 285 end
;;; page 286 start XXX; FURBY27.INC page 161
Tbl3_M349:


Tbl3_M350:
Tbl3_M351:
Tbl3_M352:
Tbl3_M353:
Tbl3_M354:
Tbl3_M355:
Tbl3_M356:
Tbl3_M357:
Tbl3_M358:
Tbl3_M359:


;;; page 286 end
;;; page 287 start XXX; FURBY27.INC page 162
Tbl3_M360:
Tbl3_M361:
Tbl3_M362:
Tbl3_M363:
Tbl3_M364:
Tbl3_M365:
Tbl3_M366:
Tbl3_M367:
Tbl3_M368:
;;; page 287 end
;;; page 288 start XXX; FURBY27.INC page 163
Tbl3_M369:


Tbl3_M370:
Tbl3_M371:
Tbl3_M372:
Tbl3_M373:
Tbl3_M374:
Tbl3_M375:
Tbl3_M376:
Tbl3_M377:
Tbl3_M378:
;;; page 288 end
;;; page 289 start XXX; FURBY27.INC page 164
Tbl3_M379:


Tbl3_M380:
Tbl3_M381:
Tbl3_M382:
Tbl3_M383:
Tbl4_M384:
Tbl4_M385:
Tbl4_M386:
Tbl4_M387:
Tbl4_M388:
;;; page 289 end
;;; page 290 start XXX; FURBY27.INC page 165
Tbl4_M389:


Tbl4_M390:
Tbl4_M391:
Tbl4_M392:
Tbl4_M393:
Tbl4_M394:
Tbl4_M395:
Tbl4_M396:
Tbl4_M397:
Tbl4_M398:
;;; page 290 end
;;; page 291 start XXX; FURBY27.INC page 166
Tbl4_M399:




Tbl4_M400:
Tbl4_M401:
Tbl4_M402:
Tbl4_M403:
Tbl4_M404:
Tbl4_M405:
Tbl4_M406:
Tbl4_M407:
Tbl4_M408:
Tbl4_M409:


Tbl4_M410:
Tbl4_M411:
;;; page 291 end
;;; page 292 start XXX; FURBY27.INC page 167
Tbl4_M412:
Tbl4_M413:
Tbl4_M414:
Tbl4_M415:
Tbl4_M416:
Tbl4_M417:
Tbl4_M418:
Tbl4_M419:


Tbl4_M420:
Tbl4_M421:
Tbl4_M422:
Tbl4_M423:
Tbl4_M424:
Tbl4_M425:
;;; page 292 end
;;; page 293 start XXX; FURBY27.INC page 168
Tbl4_M426:
Tbl4_M427:
Tbl4_M428:
Tbl4_M429:


Tbl4_M430:
Tbl4_M431:
Tbl4_M432:
Tbl4_M433:
Tbl4_M434:
Tbl4_M435:
Tbl4_M436:
Tbl4_M437:
Tbl4_M438:
Tbl4_M439:


Tbl4_M440:
;;; page 293 end
;;; page 294 start XXX; FURBY27.INC page 169
Tbl4_M441:
Tbl4_M442:
Tbl4_M443:
Tbl4_M444:
Tbl4_M445:
Tbl4_M446:
Tbl4_M447:
Tbl4_M448:
Tbl4_M449:


Tbl4_M450:
Tbl4_M451:
Tbl4_M452:
Tbl4_M453:
Tbl4_M454:
Tbl4_M455:
Tbl4_M456:
Tbl4_M457:
Tbl4_M458:
Tbl4_M459:


Tbl4_M460:
Tbl4_M461:
Tbl4_M462:
Tbl4_M463:
Tbl4_M464:
Tbl4_M465:
Tbl4_M466:
Tbl4_M467:
Tbl4_M468:
Tbl4_M469:


;;; page 294 end
;;; page 295 start XXX; FURBY27.INC page 170
Tbl4_M470:
Tbl4_M471:
Tbl4_M472:
Tbl4_M473:
Tbl4_M474:
Tbl4_M475:
Tbl4_M476:
Tbl4_M477:
Tbl4_M478:
Tbl4_M479:


Tbl4_M480:
Tbl4_M481:
Tbl4_M482:
Tbl4_M483:
Tbl4_M484:
Tbl4_M485:
Tbl4_M486:
Tbl4_M487:
Tbl4_M488:
Tbl4_M489:


Tbl4_M490:
Tbl4_M491:
Tbl4_M492:
Tbl4_M493:
Tbl4_M494:
Tbl4_M495:
Tbl4_M496:
Tbl4_M497:
Tbl4_M498:
Tbl4_M499:




;;; page 295 end
;;; page 296 start XXX; FURBY27.INC page 171
Tbl4_M500:
Tbl4_M501:
Tbl4_M502:
Tbl4_M503:
Tbl4_M504:
Tbl4_M505:
Tbl4_M506:
Tbl4_M507:
Tbl4_M508:
Tbl4_M509:


Tbl4_M510:
Tbl4_M511:

