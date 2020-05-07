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
; DO HUNGER
;
;
Hunger_S1:
	DW   170     ; #1    AGE   1
	DW   173     ; #2    AGE   1
	DW   176     ; #3    AGE   1
	DW   180     ; #4    AGE   1
	DW   182     ; #5    AGE   1
	DW   173     ; #6    AGE   1
	DW   185     ; #7    AGE   1
	DW   189     ; #8    AGE   1
	DW   193     ; #9    AGE   1
	DW   194     ; #10   AGE   1
	DW   173     ; #11   AGE   1
	DW   195     ; #12   AGE   1
	DW   189     ; #13   AGE   1
	DW   193     ; #14   AGE   1
	DW   194     ; #15   AGE   1
	DW   199     ; #16   AGE   1

Hunger_S2:
	DW   171     ; #1    AGE   2
	DW   174     ; #2    AGE   2
	DW   177     ; #3    AGE   2
	DW   181     ; #4    AGE   2
	DW   183     ; #5    AGE   2
	DW   174     ; #6    AGE   2
	DW   186     ; #7    AGE   2
	DW   190     ; #8    AGE   2
	DW   193     ; #9    AGE   2
	DW   194     ; #10   AGE   2
	DW   174     ; #11   AGE   2
	DW   196     ; #12   AGE   2
	DW   190     ; #13   AGE   2
	DW   193     ; #14   AGE   2
	DW   194     ; #15   AGE   2
	DW   200     ; #16   AGE   2

Hunger_S3:
	DW   172     ; #1    AGE   3
	DW   174     ; #2    AGE   3
	DW   178     ; #3    AGE   3
	DW   181     ; #4    AGE   3
	DW   184     ; #5    AGE   3
	DW   175     ; #6    AGE   3
	DW   187     ; #7    AGE   3
	DW   191     ; #8    AGE   3
	DW   193     ; #9    AGE   3
	DW   173     ; #10   AGE   3
	DW   175     ; #11   AGE   3
	DW   197     ; #12   AGE   3
	DW   191     ; #13   AGE   3
	DW   193     ; #14   AGE   3
	DW   173     ; #15   AGE   3
	DW   200     ; #16   AGE   3

Hunger_S4:
	DW   171     ; #1    AGE   4
	DW   175     ; #2    AGE   4
;;; page 132 end
;;; page 133 start XXX; FURBY27.INC page 8
	DW    179             ; #3    AGE    4
	DW    181             ; #4    AGE    4
	DW    184             ; #5    AGE    4
	DW    175             ; #6    AGE    4
	DW    188             ; #7    AGE    4
	DW    192             ; #8    AGE    4
	DW    194             ; #9    AGE    4
	DW    193             ; #10   AGE    4
	DW    174             ; #11   AGE    4
	DW    198             ; #12   AGE    4
	DW    192             ; #13   AGE    4
	DW    193             ; #14   AGE    4
	DW    194             ; #15   AGE    4
	DW    201             ; #16   AGE    4

; Fortune teller game
; GEORGE 07/04/98       MACRO 65-83, SAY 62-78
Fortyes_S1:

	DW    065               ; #1    AGE    1
	DW    066               ; #2    AGE    1
	DW    067               ; #3    AGE    1
	DW    068               ; #4    AGE    1
	DW    069               ; #5    AGE    1
	DW    070               ; #6    AGE    1
	DW    071               ; #7    AGE    1
	DW    072               ; #8    AGE    1
	DW    073               ; #9    AGE    1
	DW    074               ; #10   AGE    1
	DW    075               ; #11   AGE    1
	DW    076               ; #12   AGE    1
	DW    077               ; #13   AGE    1
	DW    078               ; #14   AGE    1
	DW    079               ; #15   AGE   1
	DW    080               ; #16   AGE    1

Fortyes_S2;

	DW    081               ; #1    AGE    2
	DW    082               ; #2    AGE    2
	DW    083               ; #3    AGE    2
	DW    065               ; #4    AGE    2
	DW    066               ; #5    AGE    2
	DW    067               ; #6    AGE    2
	DW    068               ; #7    AGE    2
	DW    069               ; #8    AGE    2
	DW    070               ; #9    AGE    2
	DW    071               ; #10   AGE    2
	DW    072               ; #11   AGE    2
	DW    073               ; #12   AGE    2
	DW    074               ; #13    AGE    2
	DW    075               ; #14   AGE    2
	DW    076               ; #15   AGE    2
	DW    077               ; #16   AGE    2

;END FORTUNE
;END GEORGE 07/04/98
;
;
;
;;; page 133 end
;;; page 134 start XXX; FURBY27.INC page 9
;touch £ront sensor table
;GEORGE 07/03/98 MACRO 2-64,SAY 1-61
Tfrnt_S1: DW    002             ; #l     AGE   1
	DW    003             ; #2     AGE   1
	DW    004             ; #3     AGE   1
	DW    005             ; #4     AGE   1
	DW    006             ; #5     AGE   1
	DW    007             ; #6     AGE   1
	DW    008             ; #7     AGE   1
	DW    009             ; #8     AGE   1
	DW    010             ; #9     AGE   1
	DW    011             ; #10    AGE   1
	DW    012             ; #11    AGE   1
	DW    013             ; #12    AGE   1
	DW    014             ; #13    AGE   1
	DW    015             ; #14    AGE   1
	DW    016             ; #15    AGE   1
	DW    017             ; #16    AGE   1

Tfrnt_S2: DW    018             ; #1     AGE   2
	DW    019             ; #2     AGE   2
	DW    020             ; #3     AGE   2
	DW    021             ; #4     AGE   2
	DW    022             ; #5     AGE   2
	DW    023             ; #6     AGE   2
	DW    024             ; #7     AGE   2
	DW    025             ; #8     AGE   2
	DW    026             ; #9     AGE   2
	DW    027             ; #10    AGE   2
	DW    028             ; #11    AGE   2
	DW    029             ; #12    AGE   2
	DW    030             ; #13    AGE   2
	DW    031             ; #14    AGE   2
	DW    032             ; #15    AGE   2
	DW    033             ; #16    AGE   2

Tfrnt_S3: DW    034             ; #1     AGE   3
	DW    035             ; #2     AGE   3
	DW    036             ; #3     AGE   3
	DW    037             ; #4     AGE   3
	DW    038             ; #5     AGE   3
	DW    039             ; #6     AGE   3
	DW    040             ; #7     AGE   3
	DW    041             ;025    ; #8    AGE 3
	DW    002             ; #9     AGE   3
	DW    042             ; #10    AGE   3
	DW    043             ; #11    AGE   3
	DW    044             ; #12    AGE   3
	DW    045             ; #13    AGE   3
	DW    046             ; #14    AGE   3
	DW    047             ; #15    AGE   3
	DW    048             ; #16    AGE   3

Tfmt_S4: DW     049             ; #1     AGE   4
	DW     050             ; #2     AGE   4
	DW     051             ; #3     AGE   4
	DW     052             ; #4     AGE   4
	DW     053             ; #5     AGE   4
	DW     054             ; #6     AGE   4
	DW     055             ; #7     AGE   4
;;; page 134 end
;;; page 135 start XXX; FURBY27.INC page 10
	DW    056     ; #8  AGE 4
	DW    057     ; #9  AGE 4
	DW    058     ; #10 AGE 4
	DW    059     ; #11 AGE 4
	DW    060     ; #12 AGE 4
	DW    061     ; #13 AGE 4
	DW    062     ; #14 AGE 4
	DW    063     ; #15 AGE 4
	DW    064     ; #16 AGE 4
;END GEORGE 07/03/98

;
;
;feed sense table
; DO FEED (Do 1INVERT)
;GEORGE 07/05/98
Feed_S1:

	DW    117     ; #1  AGE 1
	DW    103     ; #2  AGE 1
	DW    104     ; #3  AGE 1
	DW    105     ; #4  AGE 1
	DW    106     ; #5  AGE 1
	DW    107     ; #6  AGE 1
	DW    108     ; #7  AGE 1
	DW    109     ; #8  AGE 1
	DW    110     ; #9  AGE 1
	DW    111     ; #10 AGE 1
	DW    112     ; #11 AGE 1
	DW    113     ; #12 AGE 1
	DW    114     ; #13 AGE 1
	DW    111     ; #14 AGE 1
	DW    115     ; #15 AGE 1
	DW    116     ; #16 AGE 1

Feed_S2:

	DW    118     ; #1  AGE 2
	DW    119     ; #2  AGE 2
	DW    120     ; #3  AGE 2
	DW    121     ; #4  AGE 2
	DW    122     ; #5  AGE 2
	DW    123     ; #6  AGE 2
	DW    124     ; #7  AGE 2
	DW    125     ; #8  AGE 2
	DW    126     ; #9  AGE 2
	DW    127     ; #10 AGE 2
	DW    128     ; #11 AGE 2
	DW    113     ; #12 AGE 2
	DW    114     ; #13 AGE 2
	DW    111     ; #14 AGE 2
	DW    129     ; #15 AGE 2
	DW    116     ; #16 AGE 2
Feed_S3:

	DW    118     ; #1  AGE 3
	DW    130     ; #2  AGE 3
	DW    131     ; #3  AGE 3
	DW    132     ; #4  AGE 3
	DW    122     ; #5  AGE 3
;;; page 135 end
;;; page 136 start XXX; FURBY27.INC page 11
	DW    107          ; #6  AGE 3
	DW    133          ; #7  AGE 3
	DW    134          ; #8  AGE 3
	DW    110          ; #9  AGE 3
	DW    111          ; #10 AGE 3
	DW    135          ; #11 AGE 3
	DW    113          ; #12 AGE 3
	DW    114          ; #13 AGE 3
	DW    111          ; #14 AGE 3
	DW    135          ; #15 AGE 3
	DW    116          ; #16 AGE 3
Feed_S4:

	DW    145          ; #1  AGE   4
	DW    136          ; #2  AGE   4
	DW    137          ; #3  AGE   4
	DW    138          ; #4  AGE   4
	DW    139          ; #5  AGE   4
	DW    140          ; #6  AGE   4
	DW    141          ; #7  AGE   4
	DW    142          ; #8  AGE   4
	DW    110          ; #9  AGE   4
	DW    111          ; #10 AGE   4
	DW    143          ; #11 AGE   4
	DW    113          ; #12 AGE   4
	DW    114          ; #13 AGE   4
	DW    111          ; #14 AGE   4
	DW    144          ; #15 AGE   4
	DW    116          ; #16 AGE   4
;END GEORGE 07/05/98
;touch front sensor table
; DO WAKE   ;DONE SG
Wakeup_S1:
	DW    146          ; #1  AGE   1
	DW    149          ; #2  AGE   1
	DW    150          ; #3  AGE   1
	DW    154          ; #4  AGE   1
	DW    158          ; #5  AGE   1
	DW    159          ; #6  AGE   1
	DW    163          ; #7  AGE   1
	DW    166          ; #8  AGE   1
	DW    146          ; #9  AGE   1
	DW    149          ; #10 AGE   1
	DW    150          ; #11 AGE   1
	DW    154          ; #12 AGE   1
	DW    158          ; #13 AGE   1
	DW    159          ; #14 AGE   1
	DW    163          ; #15 AGE   1
	DW    166          ; #16 AGE   1

Wakeup_S2: DW     147         ; #1   AGE 2
	DW     149          ; #2  AGE 2
	DW     151          ; #3  AGE 2
	DW     155          ; #4  AGE 2
	DW     158          ; #5  AGE 2
	DW     160          ; #6  AGE 2
	DW     163          ; #7  AGE 2
	DW     167          ; #8  AGE 2
	DW     147          ; #9  AGE 2
	DW     149          ; #10 AGE 2
;;; page 136 end
;;; page 137 start XXX; FURBY27.INC page 12
	DW      151              ; #11 AGE 2
	DW      155              ; #12 AGE 2
	DW      158              ; #13 AGE 2
	DW      160              ; #14 AGE 2
	DW      163              ; #15 AGE 2
	DW      167              ; #16 AGE 2

Wakeup_S3: DW      148              ; #1  AGE 3
	DW      149              ; #2  AGE 3
	DW      152              ; #3  AGE 3
	DW      156              ; #4  AGE 3
	DW      158              ; #5  AGE 3
	DW      161              ; #6  AGE 3
	DW      164              ; #7  AGE 3
	DW      168              ; #8  AGE 3
	DW      148              ; #9  AGE 3
	DW      149              ; #10 AGE 3
	DW      152              ; #11 AGE 3
	DW      156              ; #12 AGE 3
	DW      158              ; #13 AGE 3
	DW      161              ; #14 AGE 3
	DW      164              ; #15 AGE 3
	DW      168              ; #16 AGE 3

Wakeup_S4: DW      148              ; #1  AGE 4
	DW      149              ; #2  AGE 4
	DW      153              ; #3  AGE 4
	DW      157              ; #4  AGE 4
	DW      158              ; #5  AGE 4
	DW      162              ; #6  AGE 4
	DW      165              ; #7  AGE 4
	DW      169              ; #8  AGE 4
	DW      148              ; #9  AGE 4
	DW      149              ; #10 AGE 4
	DW      153              ; #11 AGE 4
	DW      157              ; #12 AGE 4
	DW      158              ; #13 AGE 4
	DW      162              ; #14 AGE 4
	DW      165              ; #15 AGE 4
	DW      169              ; #16 AGE 4

;Ball tilt sensor table
; DO TILT (HANGING OUT)
;START HANGOUT MACRO 85-101,SAY 79-106
;GEORGE 07/04/98
;
;
;   DO HANGOUT
;   DO BORED
Bored_S1:         ;bored time out
	DW    085             ; #1  AGE 1
	DW    086             ; #2  AGE 1
	DW     087            ; #3  AGE 1
	DW     088            ; #4  AGE 1
	DW     089            ; #5  AGE 1
	DW     090            ; #6  AGE 1
	DW     091            ; #7  AGE 1 ;sleep
	DW     092            ; #8  AGE 1
	DW     093            ; #9  AGE 1 ;dobedo
	DW     094            ; #10 AGE 1 ;yawn




A-137
;;; page 137 end
;;; page 138 start XXX; FURBY27.INC page 13
	DW     095   ;   #11   AGE   1   ;sigh
	DW     095   ;   #12   AGE   1   ;sigh
	DW     096   ;   #13   AGE   1   ;haa
	DW     091   ;   #14   AGE   1   ;sleep was 96 dmh
	DW     097   ;   #15   AGE   1   ;heey
	DW     098   ;   #16   AGE   1   ;phone

Bored_S2:   DW     085   ; #1      AGE   2
	DW     086   ; #2      AGE   2
	DW     087   ; #3      AGE   2
	DW     088   ; #4      AGE   2
	DW     089   ; #5      AGE   2
	DW     099   ; #6      AGE   2
	DW     091   ; #7      AGE   2
	DW     092   ; #8      AGE   2
	DW     093   ; #9      AGE   2
	DW     094   ; #10     ACE   2
	DW     095   ; #11     AGE   2
	DW     095   ; #12     AGE   2
	DW     096   ; #13     AGE   2
	DW     091   ; #14     AGE   1 ;sleep was 96 dmh
	DW     097   ; #15     AGE   2
	DW     098   ; #16     AGE   2

Bored_S3: DW      085   ; #1      AGE   3
	DW      086   ; #2      AGE   3
	DW     087   ; #3      AGE   3
	DW     088   ;   #4    AGE   3
	DW     101   ; #5      AGE   3
	DW     100   ; #6      AGE   3
	DW     091   ;   #7    AGE   3
	DW     092   ;   #8    AGE   3
	DW     093   ;   #9    AGE   3
	DW     094   ;   #10   AGE   3
	DW     095   ;   #11   AGE   3
	DW     095   ;   #12   AGE   3
	DW     096   ;   #13   AGE   3
	DW     091   ;   #14   AGE   1 ;sleep was 96 dmh
	DW     097   ;   #15   AGE   3
	DW     098   ;   #16   AGE   3

Bored_S4: DW      085   ;   #1    AGE   4
	DW      086   ;   #2    AGE   4
	DW      087   ;   #3    AGE   4
	DW      088   ;   #4    AGE   4
	DW      101   ;   #5    AGE   4
	DW      100   ;   #6    AGE   4
	DW      091   ;   #7    AGE   4
	DW      092   ;   #8    AGE   4
	DW      093   ;   #9    AGE   4
	DW      094   ;   #10   AGE   4
	DW      095   ;   #11   AGE   4
	DW      095   ;   #12   AGE   4
	DW      096   ;   #13   AGE   4
	DW      091   ;   #14   AGE   1 ;sleep was 96 dmh
	DW      097   ;   #15   AGE   4 FIXED DMH WAS 96
	DW      098   ;   #16   AGE   4

;END HANGOUT
;END GEORGE 07/04/98
;;; page 138 end
;;; page 139 start XXX; FURBY27.INC page 14
;GEORGE 07/07/98
;INVERT
;Ball invert sensor table
;
Invrt_S1: DW       202        ;  #1     AGE   1
	DW       203        ;  #2     AGE   1
	DW       206        ;  #3     AGE   1
	DW       208        ;  #4     AGE   1
	DW       212        ;  #5     AGE   1
	DW       213        ;  #6     AGE   1
	DW       217        ;  #7     AGE   1
	DW       219        ;  #8     AGE   1
	DW       220        ;  #9     AGE   1
	DW       224        ;  #10   AGE   1
	DW       228        ;  #11    AGE   1
	DW       232        ;  #12   AGE   1
	DW       234        ;  #13    AGE   1
	DW       232        ;  #14    AGE   1
	DW       234        ;  #15   AGE   1
	DW       235        ;  #16   AGE   1

Invrt_S2: DW       202        ;  #1     AGE   2
	DW       203        ;  #2     AGE   2
	DW       207        ;  #3     AGE   2
	DW       209        ;  #4     AGE   2
	DW       212        ;  #5     AGE   2
	DW       214        ;  #6     AGE   2
	DW       217        ;  #7     AGE   2
	DW       219        ;  #8     AGE   2
	DW       221        ;  #9     AGE   2
	DW       225        ;  #10   AGE   2
	DW       229        ;  #11   AGE   2
	DW       232        ;  #12   AGE   2
	DW       234        ;  #13    AGE   2
	DW       232        ;  #14   AGE   2
	DW       234        ;  #15   AGE   2
	DW       236        ;  #16   AGE   2

Invrt_S3: DW       202        ;   #1   AGE 3
	DW       204        ;   #2   AGE 3
	DW       207        ;    #3   AGE 3
	DW       210        ;    #4   AGE 3
	DW       212        ;    #5 AGE 3
	DW       215        ;    #6 AGE 3
	DW       218        ;    #7   AGE 3
	DW       219        ;    #8 AGE 3
	DW       222        ;    #9   AGE 3
	DW       226        ;    #10 AGE 3
	DW       230        ;    #11 AGE 3
	DW       232        ;    #12 AGE 3
	DW       234        ;    #13 AGE 3
	DW       232        ;    #14 AGE 3
	DW       234        ;    #15 AGE 3
	DW       237      ;  #16 AGE 3

Invrt_S4: DW   202       ;    #1    AGE   4
	DW   205       ;    #2    AGE   4
	DW   207       ;    #3    AGE   4
	DW   211       ;    #4    AGE   4
;;; page 139 end
;;; page 140 start XXX; FURBY27.INC page 15
	DW    212             ; #5    AGE   4
	DW    216             ; #6    AGE   4
	DW    218             ; #7    AGE   4
	DW    219             ; #8    AGE   4
	DW    223             ; #9    AGE   4
	DW    227             ; #10   AGE   4
	DW    231             ; #11   AGE   4
	DW    233             ; #12   AGE   4
	DW    231             ; #13   AGE   4
	DW    233             ; #14   AGE   4
	DW    234             ; #15   AGE   4
	DW    238             ; #16   AGE   4

;GEORGE 07/07/98
;BACK
;touch back sensor table

Tback_S1: DW    239         ; #1     AGE   1
	DW    240         ; #2     AGE   1
	DW    244         ; #3     AGE   1
	DW    248         ; #4     AGE   1
	DW    249         ; #5     AGE   1
	DW    248         ; #6     AGE   1
	DW    253         ; #7     AGE   1
	DW    256         ; #8     AGE   1
	DW    258         ; #9     AGE   1
	DW    239         ; #10    AGE   1
	DW    248         ; #11    AGE   1
	DW    261         ; #12    AGE   1
	DW    263         ; #13    AGE   1
	DW    266         ; #14    AGE   1
	DW    269         ; #15    AGE   1
	DW    272         ; #16    AGE   1

Tback_S2: DW    239         ; #1     AGE   2
	DW    241         ; #2     AGE   2
	DW    245         ; #3     AGE   2
	DW    248         ; #4     AGE   2
	DW    250         ; #5     AGE   2
	DW    248         ; #6     AGE   2
	DW    253         ; #7     AGE   2
	DW    257         ; #8     AGE   2
	DW    259         ; #9     AGE   2
	DW    239         ; #10    AGE   2
	DW    248         ; #11    AGE   2
	DW    262         ; #12    AGE   2
	DW    264         ; #13    AGE   2
	DW    267         ; #14    AGE   2
	DW    270         ; #15    AGE   2
	DW    273         ; #16    AGE   2

Tback_S3: DW    239         ; #1     AGE   3
	DW    242         ; #2     AGE   3
	DW    246         ; #3     AGE   3
	DW    248         ; #4     AGE   3
	DW    251         ; #5     AGE   3
	DW    248         ; #6     AGE   3
	DW    254         ; #7     AGE   3
	DW    257         ; #8     AGE   3
	DW    260         ; #9     AGE   3
;;; page 140 end
;;; page 141 start XXX; FURBY27.INC page 16
	DW    239             ; #10 AGE 3
	DW    248             ; #11 AGE 3
	DW    261             ; #12 AGE 3
	DW    265             ; #13 AGE 3
	DW    268             ; #14 AGE 3
	DW    271             ; #15 AGE 3
	DW    274             ; #16 AGE 3

Tback_S4: DW    239             ; #1  AGE 4
	DW    243             ; #2  AGE 4
	DW    247             ; #3  AGE 4
	DW    248             ; #4  AGE 4
	DW    252             ; #5  AGE 4
	DW    248             ; #6  AGE 4
	DW    255             ; #7  AGE 4
	DW    257             ; #8  AGE 4
	DW    260             ; #9  AGE 4
	DW    239             ; #10 AGE 4
	DW    248             ; #11 AGE 4
	DW    262             ; #12 AGE 4
	DW    265             ; #13 AGE 4
	DW    268             ; #14 AGE 4
	DW    271             ; #15 AGE 4
	DW    275             ; #16 AGE 4
;
;END GEORGE 07/07/98


;
;I.R. receive table
;DO IR

IR_S1:    DW    393             ; #1  AGE 1
	DW    393             ; #2  AGE 1
	DW    393             ; #3  AGE 1
	DW    393             ; #4  AGE 1
	DW    394             ; #5  AGE 1
	DW    395             ; #6  AGE 1
	DW    396             ; #7  AGE 1
	DW    396             ; #8  AGE 1
	DW    291             ; #9  AGE 1
	DW    399             ; #10 AGE 1
	DW    399             ; #11 AGE 1
	DW    400             ; #12 AGE 1
	DW    401             ; #13 AGE 1
	DW    401             ; #14 AGE 1
	DW    402             ; #15 AGE 1
	DW    403             ; #16 AGE 1

IR_S2:    DW    404             ; #1  AGE 2
	DW    404             ; #2  AGE 2
	DW    404             ; #3  AGE 2
	DW    405             ; #4  AGE 2
	DW    405             ; #5  AGE 2
	DW    406             ; #6  AGE 2
	DW    407             ; #7  AGE 2
	DW    407             ; #8  AGE 2
	DW    291             ; #9  AGE 2
	DW    409             ; #10 AGE 2
	DW    409             ; #11 AGE 2
;;; page 141 end
;;; page 142 start XXX; FURBY27.INC page 17
	DW    400                    ;   #12      AGE       2
	DW    411                    ;   #13      AGE       2
	DW    411                    ;   #14      AGE       2
	DW    412                    ;   #15      AGE       2
	DW    413                    ;   #16      AGE       2

IR_S3:    DW     414               ;   #1       AGE       3
	DW     414                   ;   #2       AGE       3
	DW     414                   ;   #3       AGE       3
	DW     414                   ;   #4       AGE       3
	DW     414                   ;   #5       AGE       3
	DW     415                   ;   #6       AGE       3
	DW     416                   ;   #7       AGE       3
	DW     416                   ;   #8       AGE       3
	DW     291                   ;   #9       AGE       3
	DW     406                   ;   #10      AGE       3
	DW     418                   ;   #11      AGE       3
	DW     428                   ;   #12      AGE       3
	DW     419                   ;   #13      AGE       3
	DW     419                   ;   #14      AGE       3
	DW     420                   ;   #15      AGE       3
	DW     403                   ;   #16      AGE       3

IR_S4:    DW     421              ;   #1       AGE       4
	DW     421                   ;   #2       AGE       4
	DW     421                   ;   #3       AGE       4
	DW     421                   ;   #4       AGE       4
	DW     421                   ;   #5       AGE       4
	DW     422                   ;   #6       AGE       4
	DW     423                   ;   #7       AGE       4
	DW     423                   ;   #8       AGE       4
	DW     291                   ;   #9       AGE       4
	DW     425                   ;   #10      AGE       4
	DW     426                   ;   #11      AGE       4
	DW     427                   ;   #12      AGE       4
	DW     428                   ;   #13      AGE       4
	DW     428                   ;   #14      AGE       4
	DW     429                   ;   #15      AGE       4
	DW     413                   ;   #16      AGE       3
;
;
;
;light sense table (bright sense)
;DO LIGHT
Light_S1:

	DW     293               ;   #1       AGE 1
	DW     305       ; 003              ;    #2 AGE 1
	DW     294                   ; #3             AGE 1
	DW     295                   ; #4             AGE 1
	DW     296                   ; #5             AGE 1
	DW     297                   ; #6             AGE 1
	DW     298                   ; #7             AGE 1
	DW     299                ; #8             AGE 1
	DW     293               ; #9             AGE 1
	DW     305       ; 003                          ;       #10 AGE 1
	DW     294                   ;    #11     AGE       1
	DW     295                   ;    #12     AGE       1
	DW     296                   ;    #13     AGE       1
	DW     297                   ;    #14     AGE       1
;;; page 142 end
;;; page 143 start XXX; FURBY27.INC page 18
;;; page 143 end
	DW   298             ; #15 AGE 1
	DW   299             ; #16 AGE 1
Light_S2:
	DW   293            ; #1  AGE 2
	DW   305    ;003              ; #2  AGE 2
	DW   294            ; #3  AGE 2
	DW   300            ; #4  AGE 2
	DW   296            ; #5  AGE 2
	DW   301            ; #6  AGE 2
	DW   298            ; #7  AGE 2
	DW   299            ; #8  AGE 2
	DW   293           ; #9  AGE 2
	DW   305    ;003             ; #10 AGE 2
	DW   294            ; #11 AGE 2
	DW   295            ; #12 AGE 2
	DW   296            ; #13 AGE 2
	DW   301            ; #14 AGE 2
	DW   298            ; #15 AGE 2
	DW   299            ; #16 AGE 2

Light_S3:
	DW   302            ; #1  AGE 3
	DW   305    ;003             ; #2  AGE 3
	DW   294            ; #3  AGE 3
	DW   303            ; #4  AGE 3
	DW   296            ; #5  AGE 3
	DW   304            ; #6  AGE 3
	DW   298            ; #7  AGE 3
	DW   299            ; #8  AGE 3
	DW   302            ; #9  AGE 3
	DW   305    ;003             ; #10 AGE 3
	DW   294            ; #11 AGE 3
	DW   303            ; #12 AGE 3
	DW   296            ; #13 AGE 3
	DW   304            ; #14 AGE 3
	DW   298            ; #15 AGE 3
	DW   299            ; #16 AGE 3

Light_S4:
	DW   302            ; #1  AGE 4
	DW   305    ;003             ; #2  AGE 4
	DW   294            ; #3  AGE 4
	DW   306            ; #4  AGE 4
	DW   296            ; #5  AGE 4
	DW   307            ; #6  AGE 4
	DW   298            ; #7  AGE 4
	DW   299            ; #8  AGE 4
	DW   302            ; #9  AGE 4
	DW   305    ;003             ; #10 AGE 4
	DW   294            ; #11 AGE 4
	DW   306            ; #12 AGE 4
	DW   296            ; #13 AGE 4
	DW   307            ; #14 AGE 4
	DW   298            ; #15 AGE 4
	DW   299            ; #16 AGE 4
;
;
;light sense table (DARK SENSE)
; DO DARK
;;; page 144 start XXX; FURBY27.INC page 19
; DO LIGHT DARKER
Dark_S1:  DW    308    ; #1     AGE   1
	DW    309    ; #2     AGE   1
	DW    310    ; #3     AGE   1
	DW    311    ; #4     AGE   1
	DW    312    ; #5     AGE   1
	DW    313    ; #6     AGE   1
	DW    314    ; #7     AGE   1
	DW    315    ; #8     AGE   1
	DW    308    ; #9     AGE   1
	DW    309    ; #10   AGE   1
	DW    310    ; #11   AGE   1
	DW    311    ; #12   AGE   1
	DW    312    ; #13   AGE   1
	DW    313    ; #14   AGE   1
	DW    314    ; #15   AGE   1
	DW    315    ; #16   AGE   1

Dark_S2:
	DW    316   ; #1     AGE   2
	DW    317   ; #2     AGE   2
	DW    318   ; #3     AGE   2
	DW    311   ; #4     AGE   2
	DW    319   ; #5     AGE   2
	DW    313   ; #6     AGE   2
	DW    320   ; #7     AGE   2
	DW    315   ; #8     AGE   2
	DW    316   ; #9     AGE   2
	DW    317   ; #10   AGE   2
	DW    318   ; #11   AGE   2
	DW    311   ; #12    AGE   2
	DW    319   ; #13   AGE   2
	DW    313   ; #14   AGE   2
	DW    320   ; #15   AGE   2
	DW    315   ; #16   AGE   2

Dark_S3:   DW    321   ; #1     AGE   3
	DW    322   ; #2     AGE   3
	DW    323   ; #3     AGE   3
	DW    311   ; #4     AGE   3
	DW    319   ; #5     AGE   3
	DW    313   ; #6     AGE   3
	DW    324   ; #7     AGE   3
	DW    325   ; #8     AGE   3
	DW    321   ; #9     AGE   3
	DW    322   ; #10   AGE   3
	DW    323   ; #11   AGE   3
	DW    311   ; #12   AGE   3
	DW    319   ; #13    AGE   3
	DW    313   ; #14   AGE   3
	DW    324   ; #15   AGE   3
	DW    325   ; #16   AGE   3

Dark_S4:   DW    326   ; #1     AGE   4
	DW    327   ; #2     AGE   4
	DW    328   ; #3     AGE   4
	DW    311   ; #4     AGE   4
	DW    329   ; #5     AGE   4
	DW    313   ; #6     AGE   4
	DW    330   ; #7     AGE   4
;;; page 144 end
;;; page 145 start XXX; FURBY27.INC page 20
	DW         331              ;  #8    AGE   4
	DW         326              ;  #9    AGE   4
	DW         327              ;  #10   AGE   4
	DW         328              ;  #11   AGE   4
	DW         311              ;  #12   AGE   4
	DW         329              ;  #13   AGE   4
	DW         313              ;  #14   AGE   4
	DW         330              ;  #15   AGE   4
	DW         331              ;  #16   AGE   4
;
;
;
;
; Hide and Seek game table

Peek_S1:     DW         000              ; #0    AGE 1
	DW   000           ;  #1    AGE   1
	DW   000           ;  #2    AGE   1
	DW   000           ;  #3    AGE   1
	DW   000           ;  #4    AGE   1
	DW   000           ;  #5    AGE   1
	DW   000           ;  #6    AGE   1
	DW   000           ;  #7    AGE   1
	DW   000           ;  #8    AGE   1
	DW   000           ;  #9    AGE   1
	DW   000           ;  #10   AGE   1
	DW   000           ;  #11   AGE   1
	DW   000           ;  #12   AGE   1
	DW   000           ;  #13   AGE   1
	DW   000           ;  #14   AGE   1
	DW   000           ;  #15   AGE   1

Peek_S2:     DW     000                  ; #0    AGE 2
	DW   000           ;  #1    AGE   2
	DW   000           ;  #2    AGE   2
	DW   000           ;  #3    AGE   2
	DW   000           ;  #4    AGE   2
	DW   000           ;  #5    AGE   2
	DW   000           ;  #6    AGE   2
	DW   000           ;  #7    AGE   2
	DW   000           ;  #8    AGE   2
	DW   000           ;  #9    AGE   2
	DW   000           ;  #10   AGE   2
	DW   000           ;  #11   AGE   2
	DW   000           ;  #12   AGE   2
	DW   000           ;  #13   AGE   2
	DW   000           ;  #14   AGE   2
	DW   000           ;  #15   AGE   2

Peek_S3:     DW     000                  ; #0    AGE 3
	DW   000           ;  #1    AGE   3
	DW   000           ;  #2    AGE   3
	DW   000           ;  #3    AGE   3
	DW   000           ;  #4    AGE   3
	DW   000           ;  #5    AGE   3
	DW   000           ;  #6    AGE   3
	DW   000           ;  #7    AGE   3
	DW   000           ;  #8    AGE   3
	DW   000           ;  #9    AGE   3
	DW   000           ;  #10   AGE   3
;;; page 145 end
;;; page 146 start XXX; FURBY27.INC page 21
	DW   000        ; #11 AGE 3
	DW   000        ; #12 AGE 3
	DW   000        ; #13 AGE 3
	DW   000        ; #14 AGE 3
	DW   000        ; #15 AGE 3

Peek_S4:  DW   000              ; #0   AGE 4
	DW  000         ; #1  AGE 4
	DW  000         ; #2  AGE 4
	DW  000         ; #3  AGE 4
	DW  000         ; #4  AGE 4
	DW  000         ; #5  AGE 4
	DW  000         ; #6  AGE 4
	DW  000         ; #7  AGE 4
	DW  000         ; #8  AGE 4
	DW  000         ; #9  AGE 4
	DW  000         ; #10 AGE 4
	DW  000         ; #11 AGE 4
	DW  000         ; #12 AGE 4
	DW  000         ; #13 AGE 4
	DW  000         ; #14 AGE 4
	DW    000             ; #15 AGE 4
;
;
;***********************************************
;***********************************************
;***********************************************

Macro_grp1:  ;points into macro tables

	DW   Tbl1_Macro0
	DW   Tbl1_Macro1,Tbl1_Macro2,Tbl1_Macro3,Tbl1_Macro4,Tbl1_Macro5
	DW   Tbl1_Macro6,Tbl1_Macro7,Tbl1_Macro8,Tbl1_Macro9,Tbl1_Macro10
	DW   Tbl1_Macro11,Tbl1_Macro12,Tbl1_Macro13,Tbl1_Macro14,Tbl1_Macro15
	DW   Tbl1_Macro16,Tbl1_Macro17,Tbl1_Macro18,Tbl1_Macro19,Tbl1_Macro20
	DW   Tbl1_Macro21,Tbl1_Macro22,Tbl1_Macro23,Tbl1_Macro24,Tbl1_Macro25
	DW   Tbl1_Macro26,Tbl1_Macro27,Tbl1_Macro28,Tbl1_Macro29,Tbl1_Macro30
	DW   Tbl1_Macro31,Tbl1_Macro32,Tbl1_Macro33,Tbl1_Macro34,Tbl1_Macro35
	DW   Tbl1_Macro36,Tbl1_Macro37,Tbl1_Macro38,Tbl1_Macro39,Tbl1_Macro40
	DW   Tbl1_Macro41,Tbl1_Macro42,Tbl1_Macro43,Tbl1_Macro44,Tbl1_Macro45
	DW   Tbl1_Macro46,Tbl1_Macro47,Tbl1_Macro48,Tbl1_Macro49,Tbl1_Macro50
	DW   Tbl1_Macro51,Tbl1_Macro52,Tbl1_Macro53,Tbl1_Macro54,Tbl1_Macro55
	DW   Tbl1_Macro56,Tbl1_Macro57,Tbl1_Macro58,Tbl1_Macro59,Tbl1_Macro60
	DW   Tbl1_Macro61,Tbl1_Macro62,Tbl1_Macro63,Tbl1_Macro64,Tbl1_Macro65
	DW   Tbl1_Macro66,Tbl1_Macro67,Tbl1_Macro68,Tbl1_Macro69,Tbl1_Macro70
	DW   Tbl1_Macro71,Tbl1_Macro72,Tbl1_Macro73,Tbl1_Macro74,Tbl1_Macro75
	DW   Tbl1_Macro76,Tbl1_Macro77,Tbl1_Macro78,Tbl1_Macro79,Tbl1_Macro80
	DW   Tbl1_Macro81,Tbl1_Macro82,Tbl1_Macro83,Tbl1_Macro84,Tbl1_Macro85
	DW   Tbl1_Macro86,Tbl1_Macro87,Tbl1_Macro88,Tbl1_Macro89,Tbl1_Macro90
	DW   Tbl1_Macro91,Tbl1_Macro92,Tbl1_Macro93,Tbl1_Macro94,Tbl1_Macro95
	DW   Tbl1_Macro96,Tbl1_Macro97,Tbl1_Macro98,Tbl1_Macro99
	DW   Tbl1_Macro100,Tbl1_Macro101,Tbl1_Macro102,Tbl1_Macro103,Tbl1_Macro104
	DW   Tbl1_Macro105,Tbl1_Macro106,Tbl1_Macro107,Tbl1_Macro108,Tbl1_Macro109
	DW   Tbl1_Macro110,Tbl1_Macro111,Tbl1_Macro112,Tbl1_Macro113,Tbl1_Macro114
	DW   Tbl1_Macro115,Tbl1_Macro116,Tbl1_Macro117,Tbl1_Macro118,Tbl1_Macro119
	DW   Tbl1_Macro120,Tbl1_Macro121,Tbl1_Macro122,Tbl1_Macro123,Tbl1_Macro124
;;; page 146 end
;;; page 147 start XXX; FURBY27.INC page 22
	DW     Tbl1_Macro125,Tbl1_Macro126,Tbl1_Macro127

Macro_grp2:    ;points into macro tables

	DW   Tbl2_Macro128
	DW   Tbl2_Macro129,Tbl2_Macro130,Tbl2_Macro131,Tbl2_Macro132,Tbl2_Macro133
	DW   Tbl2_Macro134,Tbl2_Macro135,Tbl2_Macro136,Tbl2_Macro137,Tbl2_Macro138
	DW   Tbl2_Macro139,Tbl2_Macro140,Tbl2_Macro141,Tbl2_Macro142,Tbl2_Macro143
	DW   Tbl2_Macro144,Tbl2_Macro145,Tbl2_Macro146,Tbl2_Macro147,Tbl2_Macro148
	DW   Tbl2_Macro149,Tbl2_Macro150,Tbl2_Macro151,Tbl2_Macro152,Tbl2_Macro153
	DW   Tbl2_Macro154,Tbl2_Macro155,Tbl2_Macro156,Tbl2_Macro157,Tbl2_Macro158
	DW   Tbl2_Macro159,Tbl2_Macro160,Tbl2_Macro161,Tbl2_Macro162,Tbl2_Macro163
	DW   Tbl2_Macro164,Tbl2_Macro165,Tbl2_Macro166,Tbl2_Macro167,Tbl2_Macro168
	DW   Tbl2_Macro169,Tbl2_Macro170,Tbl2_Macro171,Tbl2_Macro172,Tbl2_Macro173
	DW   Tbl2_Macro174,Tbl2_Macro175,Tbl2_Macro176,Tbl2_Macro177,Tbl2_Macro178
	DW   Tbl2_Macro179,Tbl2_Macro180,Tbl2_Macro181,Tbl2_Macro182,Tbl2_Macro183
	DW   Tbl2_Macro184,Tbl2_Macro185,Tbl2_Macro186,Tbl2_Macro187,Tbl2_Macro188
	DW   Tbl2_Macro189,Tbl2_Macro190,Tbl2_Macro191,Tbl2_Macro192,Tbl2_Macro193
	DW   Tbl2_Macro194,Tbl2_Macro195,Tbl2_Macro196,Tbl2_Macro197,Tbl2_Macro198
	DW   Tbl2_Macro199,Tbl2_Macro200,Tbl2_Macro201,Tbl2_Macro202,Tbl2_Macro203
	DW   Tbl2_Macro204,Tbl2_Macro205,Tbl2_Macro206,Tbl2_Macro207,Tbl2_Macro208
	DW   Tbl2_Macro209,Tbl2_Macro210,Tbl2_Macro211,Tbl2_Macro212,Tbl2_Macro213
	DW   Tbl2_Macro214,Tbl2_Macro215,Tbl2_Macro216,Tbl2_Macro217,Tbl2_Macro218
	DW   Tbl2_Macro219,Tbl2_Macro220,Tbl2_Macro221,Tbl2_Macro222,Tbl2_Macro223
	DW   Tbl2_Macro224,Tbl2_Macro225,Tbl2_Macro226,Tbl2_Macro227,Tbl2_Macro228
	DW   Tbl2_Macro229,Tbl2_Macro230,Tbl2_Macro231,Tbl2_Macro232,Tbl2_Macro233
	DW   Tbl2_Macro234,Tbl2_Macro235,Tbl2_Macro236,Tbl2_Macro237,Tbl2_Macro238
	DW   Tbl2_Macro239,Tbl2_Macro240,Tbl2_Macro241,Tbl2_Macro242,Tbl2_Macro243
	DW   Tbl2_Macro244,Tbl2_Macro245,Tbl2_Macro246,Tbl2_Macro247,Tbl2_Macro248
	DW   Tbl2_Macro249,Tbl2_Macro250,Tbl2_Macro251,Tbl2_Macro252,Tbl2_Macro253
	DW   Tbl2_Macro254,Tbl2_Macro255

Macro_grp3:   ; points into macro tables
;;; page 147 end
;;; page 148 start XXX; FURBY27.INC page 23
	DW  Tbl3_Macro256
	DW  Tbl3_Macro257,Tbl3_Macro258,Tbl3_Macro259,Tbl3_Macro260,Tbl3_Macro261
	DW  Tbl3_Macro262,Tbl3_Macro263,Tbl3_Macro264,Tbl3_Macro265,Tbl3_Macro266
	DW  Tbl3_Macro267,Tbl3_Macro268,Tbl3_Macro269,Tbl3_Macro270,Tbl3_Macro271
	DW  Tbl3_Macro272,Tbl3_Macro273,Tbl3_Macro274,Tbl3_Macro275,Tbl3_Macro276
	DW  Tbl3_Macro277,Tbl3_Macro278,Tbl3_Macro279,Tbl3_Macro280,Tbl3_Macro281
	DW  Tbl3_Macro282,Tbl3_Macro283,Tbl3_Macro284,Tbl3_Macro285,Tbl3_Macro286
	DW  Tbl3_Macro287,Tbl3_Macro288,Tbl3_Macro289,Tbl3_Macro290,Tbl3_Macro291
	DW  Tbl3_Macro292,Tbl3_Macro293,Tbl3_Macro294,Tbl3_Macro295,Tbl3_Macro296
	DW  Tbl3_Macro297,Tbl3_Macro298,Tbl3_Macro299,Tbl3_Macro300,Tbl3_Macro301
	DW  Tbl3_Macro302,Tbl3_Macro303,Tbl3_Macro304,Tbl3_Macro305,Tbl3_Macro306
	DW  Tbl3_Macro307,Tbl3_Macro308,Tbl3_Macro309,Tbl3_Macro310,Tbl3_Macro311
	DW  Tbl3_Macro312,Tbl3_Macro313,Tbl3_Macro314,Tbl3_Macro315,Tbl3_Macro316
	DW  Tbl3_Macro317,Tbl3_Macro318,Tbl3_Macro319,Tbl3_Macro320,Tbl3_Macro321
	DW  Tbl3_Macro322,Tbl3_Macro323,Tbl3_Macro324,Tbl3_Macro325,Tbl3_Macro326
	DW  Tbl3_Macro327,Tbl3_Macro328,Tbl3_Macro329,Tbl3_Macro330,Tbl3_Macro331
	DW  Tbl3_Macro332,Tbl3_Macro333,Tbl3_Macro334,Tbl3_Macro335,Tbl3_Macro336
	DW  Tbl3_Macro337,Tbl3_Macro338,Tbl3_Macro339,Tbl3_Macro340,Tbl3_Macro341
	DW  Tbl3_Macro342,Tbl3_Macro343,Tbl3_Macro344,Tbl3_Macro345,Tbl3_Macro346
	DW  Tbl3_Macro347,Tbl3_Macro348,Tbl3_Macro349,Tbl3_Macro350,Tbl3_Macro351
	DW  Tbl3_Macro352,Tbl3_Macro353,Tbl3_Macro354,Tbl3_Macro355,Tbl3_Macro356
	DW  Tbl3_Macro357,Tbl3_Macro358,Tbl3_Macro359,Tbl3_Macro360,Tbl3_Macro361
	DW  Tbl3_Macro362,Tbl3_Macro363,Tbl3_Macro364,Tbl3_Macro365,Tbl3_Macro366
	DW  Tbl3_Macro367,Tbl3_Macro368,Tbl3_Macro369,Tbl3_Macro370,Tbl3_Macro371
	DW  Tbl3_Macro372,Tbl3_Macro373,Tbl3_Macro374,Tbl3_Macro375,Tbl3_Macro376
	DW  Tbl3_Macro377,Tbl3_Macro378,Tbl3_Macro379,Tbl3_Macro380,Tbl3_Macro381
	DW  Tbl3_Macro382,Tbl3_Macro383
;
Macro_grp4:  ;points into macro tables

	DW   Tbl4_Macro384
	DW   Tbl4_Macro385,Tbl4_Macro386,Tbl4_Macro387,Tbl4_Macro388,Tbl4_Macro389
	DW   Tbl4_Macro390,Tbl4_Macro391,Tbl4_Macro392,Tbl4_Macro393,Tbl4_Macro394
;;; page 148 end
;;; page 149 start XXX; FURBY27.INC page 24
	DW   Tbl4_Macro395,Tbl4_Macro396,Tbl4_Macro397,Tbl4_Macro398,Tbl4_Macro399
	DW   Tbl4_Macro400,Tbl4_Macro401,Tbl4_Macro402,Tbl4_Macro403,Tbl4_Macro404
	DW   Tbl4_Macro405,Tbl4_Macro406,Tbl4_Macro407,Tbl4_Macro408,Tbl4_Macro409
	DW   Tbl4_Macro410,Tbl4_Macro411,Tbl4_Macro412,Tbl4_Macro413,Tbl4_Macro414
	DW   Tbl4_Macro415,Tbl4_Macro416,Tbl4_Macro417,Tbl4_Macro418,Tbl4_Macro419
	DW   Tbl4_Macro420,Tbl4_Macro421,Tbl4_Macro422,Tbl4_Macro423,Tbl4_Macro424
	DW   Tbl4_Macro425,Tbl4_Macro426,Tbl4_Macro427,Tbl4_Macro428,Tbl4_Macro429
	DW   Tbl4_Macro430,Tbl4_Macro431,Tbl4_Macro432,Tbl4_Macro433,Tbl4_Macro434
	DW   Tbl4_Macro435,Tbl4_Macro436,Tbl4_Macro437,Tbl4_Macro438,Tbl4_Macro439
	DW   Tbl4_Macro440,Tbl4_Macro441,Tbl4_Macro442,Tbl4_Macro443,Tbl4_Macro444
	DW   Tbl4_Macro445,Tbl4_Macro446,Tbl4_Macro447,Tbl4_Macro448,Tbl4_Macro449
	DW   Tbl4_Macro450,Tbl4_Macro451,Tbl4_Macro452,Tbl4_Macro453,Tbl4_Macro454
	DW   Tbl4_Macro455,Tbl4_Macro456,Tbl4_Macro457,Tbl4_Macro458,Tbl4_Macro459
	DW   Tbl4_Macro460,Tbl4_Macro461,Tbl4_Macro462,Tbl4_Macro463,Tbl4_Macro464
	DW   Tbl4_Macro465,Tbl4_Macro466,Tbl4_Macro467,Tbl4_Macro468,Tbl4_Macro469
	DW   Tbl4_Macro470,Tbl4_Macro471,Tbl4_Macro472,Tbl4_Macro473,Tbl4_Macro474
	DW   Tbl4_Macro475,Tbl4_Macro476,Tbl4_Macro477,Tbl4_Macro478,Tbl4_Macro479
	DW   Tbl4_Macro480,Tbl4_Macro481,Tbl4_Macro482,Tbl4_Macro483,Tbl4_Macro484
	DW   Tbl4_Macro485,Tbl4_Macro486,Tbl4_Macro487,Tbl4_Macro488,Tbl4_Macro489
	DW   Tbl4_Macro490,Tbl4_Macro491,Tbl4_Macro492,Tbl4_Macro493,Tbl4_Macro494
	DW   Tbl4_Macro495,Tbl4_Macro496,Tbl4_Macro497,Tbl4_Macro498,Tbl4_Macro499
	DW   Tbl4_Macro500,Tbl4_Macro501,Tbl4_Macro502,Tbl4_Macro503,Tbl4_Macro504
	DW   Tbl4_Macro505,Tbl4_Macro506,Tbl4_Macro507,Tbl4_Macro508,Tbl4_Macro509
	DW   Tbl4_Macro510,Tbl4_Macro511


;***********************************************
;***********************************************
;***********************************************


; MACRO TABLES
;
; The sensor cables point into the Macro table. This table in turn
; gets speech and motor table data.
; This can be an entry of 1-511 and effectively chains motor and
; speech tables together to reuse previous speech motor segments.
;;; page 149 end
;;; page 150 start XXX; FURBY27.INC page 25
; The first group of numbers is the speech/motor table value.
; The last line is the terminator of 00. (00 so 'DB' takes 1 less byte)
;
; ex:  1 = will call the saysent 1 and the motor table 1.

Tbl1_Macro0:
	DW             511
	DW         00      ;end

; FOR NAME TESTING DMH
; WAKE
;	DW      124                     ;02
;	DW      125
;	DW      126
;
;
;	DW          399          ; delay
;	DW          395          ; ME
;	DW          224          ; MAY-LAH-KA
;	DW          152
;	DW         00          ;end


;
; (MIDDLE)
;
;
; put     sounds and motions together
;  DW     5         (first sound and motion, in this case "5")
;  DW     3         (next sound and motion, in this case "3")
;  DW     00        ( end of sequence)
;

Tbl1_Macro1:
	DW                        01
	DW                        00           ;end

;GEORGE 07/03/98
Tbl1_Macro2:
	DW       001                           ;FRONT SEQ1AGE1
	DW       00                           ;end
;
Tbl1_Macro3:
	DW                       002            ;FRONT SEQ2AGE1
	DW                       00           ;end
;
Tbl1_Macro4:
	DW                       003          ;FRONT SEQ3AGE1
	DW                       004
	DW                       00           ;end
;
Tbl1_Macro5:
	DW                       003          ;FRONT SEQ4AGE1
	DW                       005
	DW                       00           ;end
;
Tbl1_Macro6:
	DW                       006            ;FRONT SEQ5AGE1
	DW                       00           ;end
;
;;; page 150 end
;;; page 151 start XXX; FURBY27.INC page 26
Tbl1_Macro7:
	DW      006   ;FRONTSEQ6AGE1
	DW      007
	DW      00    ;end
;
Tbl1_Macro8:
	DW      008   ;FRONT SEQ7AGE1
	DW      003
	DW      00    ;end
;
Tbl1_Macro9:
	DW      009   ;FRONTSEQ8AGE1
	DW      003
	DW      00    ;end
;
Tbl1_Macro10:
	DW      010   ;FRONT SEQ9age1
	DW      00    ;end
;
Tbl1_Macro11:
	DW       011
	DW       001   ;frontseq10age1
	DW       00    ;end
;
Tbl1_Macro12:
	DW       012
	DW       001   ;seq11 FRONT AGE1 ADD SAY001
	DW       00    ;end
;
Tbl1_Macro13
	DW       001
	DW       013   ;seq12 FRONT AGE1 ADD SAY001
	DW       00    ;end
;
Tbl1_Macro14:
	DW       014   ;seq13 FRONT AGE1 ADD SAY003
	DW       003
	DW       00    ;end
;
Tbl1_Macro15:
	DW       015   ;seq14 FRONT AGE1
	DW       00    ;end
;
Tbl1_Macro16:
	DW       016   ;seq15 FRONT AGE1
	DW       00    ;end
;
Tbl1_Macro17:
	DW       001
	DW       017
	DW       018
	DW       001   ;seq16 FRONT AGE1 BETWEEN 2(20)
	DW       00    ;end
;
Tbl1_Macro18:
	DW       019   ;FRONT SEQ1AGE2
	DW       00    ;end
;
Tbl1_Macro19:
	DW       001
;;; page 151 end
;;; page 152 start XXX; FURBY27.INC page 27
	DW       020             ;FRONT SEQ2 AGE2
	DW       00    ; end
;
Tbl1_Macro20:
	DW       010
	DW       021    ;SEQ3AGE2 FRONT ADD SEQ9AGE1
	DW       00    ;end
;
Tbl1_Macro21:
	DW       022     ;SEQ4 AGE2    FRONT
	DW       023
	DW       00     ;end
;
Tbl1_Macro22:
	DW       024      ; SEQ5 AGE2 FRONT
	DW       00     ; end
;
Tbl1_Macro23:
	DW       025      ; SEQ6 AGE2   FRONT
	DW       00     ; end
;
Tbl1_Macro24:
	DW       026    ; SEQ 7 AGE2 FRONT PARTI
	DW       027
	DW       00    ; end
;
Tbl1_Macro25:

	DW       026
	DW       026    ; SEC 8 AGE2    FRONT
	DW       028
	DW       003
	DW       00    ;end
;
Tbl1_Macro26:
	DW       029                            ;SEQ 9 FRONT
	DW       00    ; end
;
Tbl1_Macro27:
	DW       030
	DW       029     ;SEQ 10 FRONT AGE2
	DW       00    ; end
;
Tbl1_Macro28:
	DW       022
	DW       031     ;SEQ 11 FRONT AGE2
	DW       00    ; end
;
Tbl1_Macro29:
	DW       001
	DW       032     ;SEQ 12 FRONT AGE 2
	DW       00    ; end
;
Tbl1_Macro30:
	DW       014               ;seq13 FRONT AGE1&2 ADD SAY003
	DW       003
	DW       00    ;end
;
Tbl1_Macro31:
	DW      033    ;SEQ14 FRONT AGE2
;;; page 152 end
;;; page 153 start XXX; FURBY27.INC page 28
	DW          00    ;end
;
Tbl1_Macro32:
	DW          034            ;SEQ15 FRONT AGE2
	DW          001
	DW          00    ;end
;
Tbl1_Macro33:
	DW          001
	DW          035            ;SEQ16 FRONT AGE2
	DW          00    ;end
;
Tbl1_Macro34:
	DW          001
	DW          036            ;SEQ1 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro35:
	DW          003
	DW          037            ;SEQ2 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro36:
	DW          010
	DW          038            ;SEQ3 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro37:
	DW          015
	DW          039            ;SEQ4 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro38:
	DW          015
	DW          023            ;SEQ5 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro39:
	DW          040            ;SEQ6 FROOT AGE3
	DW          00    ;end
;
Tbl1_Macro40:
	DW          041            ;SEQ7 FRONT AGE3
	DW          003
	DW          00    ;end
;
Tbl1_Macro41:
	DW          042
	DW          003            ;SEQ8 FRONT AGE3
	DW          00    ;end
;
Tbl1_Macro42:
	DW          043            ;SEQ10 FRONT AGE3
	DW          001
	DW          00    ;end
;
Tbl1_Macro43:
	DW          044            ;SEQ11 FRONT AGE3
	DW          00    ;end
;
;;; page 153 end
;;; page 154 start XXX; FURBY27.INC page 29
Tbl1_Macro44:
	DW       045
	DW       001         ;SEQ12 FRONT AGE3 (HEEY,TICKLE ME) ADD20
	DW       00       ;end

Tbl1_Macro45:
	DW       001
	DW       046            ;SEQ13 fRONT AGE3 (NANNY,NANNY)   ADD20
	DW       047       ;RASBERRY HE HE HE
	DW       00       ;end
;
Tbl1_Macro46:
	DW       003
	DW       028        ;SEQ14 FRONT AGE3
	DW       003
	DW       00       ;end
;
Tbl1_Macro47:
	DW       034         ;SEQ15 FRONT AGE3
	DW       001
	DW       00       ;end
;
Tbl1_Macro48:
	DW       001
	DW       048
	DW       049           ;SEQ6 FRONT AGE3
	DW       00        ;end
;
Tbl1_Macro49:
	DW       044        ;SEQ1  FRONT AGE4
	DW       00        ;end
;
Tbl1_Macro50:
	DW       001
	DW       050          ; SEQ2  FRONT AGE4
	DW       051
	DW       00        ; end
;
Tbl1_Macro51:
	DW       003
	DW       052          ;SEQ3 (YOU) FRONT AGE4
	DW       050
	DW       053          ;SEQ3 (ME) FRONT AGE4
	DW       00        ;end
;
Tbl1_Macro52:
	DW       026
	DW       053
	DW       054
	DW       050  ;SEQ4  FRONT AGE4
	DW       001
	DW       00        ;end
;
Tbl1_Macro53:
	DW       007
	DW       055
	DW       056                ;  SEQ5 FRONT AGE4
	DW       00        ;end
;
Tbl1_Macro54:
;;; page 154 end
;;; page 155 start XXX; FURBY27.INC page 30
	DW       026
	DW       053
	DW       054
	DW       052
	DW       018                    ;SEQ6 FRONT AGE4
	DW       00        ; end
;
Tbl1_Macro55:
	DW       001
	DW       046
	DW       055         ;SEQ7 FRONT AGE4
	DW       00        ;end
;
Tbl1_Macro56:
	DW       026
	DW       057
	DW       050
	DW       051
	DW       058
	DW       003          ;SEQ8 FRONT AGE4
	DW       00        ; end
;
Tbl1_Macro57:
	DW       042,001       ;SEQ9 FRONT AGE4
	DW       00        ; end
;
Tbl1_Macro58:
	DW       059        ;SEQ10 FRONT AGE4
	DW       050
	DW       00        ;end
;
Tbl1_Macro59:
	DW       044
	DW       003         ;SEQ11 FRONT AGE4
	DW       00        ; end
;
Tbl1_Macro60:
	DW       001           ;SEQ12
	DW       00        ; end
;
Tbl1_Macro61:
	DW       001
	DW       046
	DW       047        SEQ13 FRONT AGE4
	DW      00        ;end
;
Tbl1_Macro62:
	DW       026
	DW       060         ;SE014 FRONT AGE4
	DW       00        ; end
;
Tbl1_Macro63:
	DW       061
	DW       003        SEQ15 FRONT AGE4
	DW       00        ;end
;
Tbl1_Macro64:
	DW       007
	DW       051        ;SEQ16 FRONT AGE4
	DW       00        ;end
;;; page 155 end
;;; page 156 start XXX; FURBY27.INC page 31
;END GEORGE 07/03/98



;GEORGE 07/04/98
;START FORTUNE
;

Tbl1_Macro65:
	DW           062
	DW           051 ;72        ;FORTUNE 1
	DW    00         ;end
;
Tbl1_Macro66:
	DW           003
	DW           063       ;FORTUNE 2
	DW           003
	DW    00         ;end
;
Tbl1_Macro67:
	DW           090       ;94
	DW           064
	DW           063       ;FORTUNE 3
	DW    00         ;end
;
Tbl1_Macro68:
	DW           065       ;FORTUNE 4
	DW           063
	DW    00         ;end

Tbl1_Macro69:                  ; MODIFIED FOR NAME DMH
;	DW           067       ;FORTUNE
;	DW           068
	DW           053
	DW           066       ;FORTUNE 5
	DW           063
	DW    00         ;end
;
Tbl1_Macro70:
	DW           069       ;FORTUNE 6
	DW           070
	DW           00        ;end
;
Tbl1_Macro71:
	DW          067
	DW          068        ;FORTUNE 7
	DW          071
	DW          073
	DW          072
	DW    00        ;end

Tbl1_Macro72:
	DW          074        ;FORTUNE 8
	DW    00        ;end

Tbl1_Macro73:
	DW          074        ;FORTUNE 9
	DW          063
	DW    00        ;end
;
Tbl1_Macro74:
;;; page 156 end
;;; page 157 start XXX; FURBY27.INC page 32
	DW      069     ;FORTUNE 10
	DW    00    ;end
;
Tbl1_Macro75:
	DW      064     ;FORTUNE 11
	DW      069
	DW     00   ;end
;
Tbl1_Macro76:
	DW      073
	DW      064     ;FORTUNE 12
	DW      069
	DW    00    ;end
;
Tbl1_Macro77:           ; MODIFIED TO WORK WITH NAME DMH
;	DW      067
;	DW      068
	DW      053      ;FORTUNE 13
	DW      066
	DW      069
	DW    00    ;end

Tbl1_Macro78:
	DW      071
	DW      073
	DW      069
	DW      075     ;FORTUNE 14
	DW    00    ;end
;
Tbl1_Macro79:
	DW      076
	DW      077     ;FORTUNE 15
	DW      00      ;end
;
Tbl1_Macro80:
	DW      076
	DW      069     ;FORTUNE 16
	DW    00    ;end
;
Tbl1_Macro81:
	DW      078     ;FORTUNE 17 SEQ1 AGE2
	DW    00    ;end
;
Tbl1_Macro82:
	DW      078     ;FORTUNE 18  SEQ2 AGE2
	DW      063
	DW    00    ;end
;
Tbl1_Macro83:
	DW      078     ;FORTUNE 19  SEQ2 AGE2
	DW      069
	DW    00    ;end


Tbl1_Macro84             ;SPECIAL "O TWO MA"
	DW      067      ;
	DW      068      ;
	DW      00
;END GEORGE 07/04/98
;END FORTUNE
;;; page 157 end
;;; page 158 start XXX; FURBY27.INC page 33
;START HANGOUT
;GEORGE 07/04/98
Tbl1_Macro85:
	DW       079
	DW       080
	DW       079        ;SEQ1 HANGING
	DW       080
	DW    00     ;end
;
Tbl1_Macro86:
	DW       081        ;SEQ2 HANGING
	DW       081
	DW    00     ;end
;
Tbl1_Macro87:
	DW       082
	DW       083
;	DW      083
	DW       084 ;SEQ3 HANGING (YA DA DA OMPAH  bRUMM BABABUM)
	DW    00     ;end
;
Tbl1_Macro88:
	DW       085
	DW       085
	DW       086
	DW       087   ;SEQ4 HANGING (LA LA)
	DW    00     ;end
;
Tbl1_Macro89:
	DW       087
	DW       088    ;SEQ5 HANGING
	DW    00     ;end
;
Tbl1_Macro90:
	DW       089
	DW       089
	DW       090      ;SEQ6 HANGING
	DW       091
	DW       092
	DW    00     ;end
;
Tbl1_Macro91:
	DW       093       ;SEQ7 HANGING (SOFTER)
	DW       093
	DW       093
	DW       094
	DW    00     ;end
;
Tbl1_Macro92:
	DW       095
	DW       095
	DW       055     ;WAS 76      ;SEQ8 HANGING
	DW    00     ;end
;
Tbl1_Macro93:
	DW       096       ;SEQ9 HANGING
	DW    00     ;end
;;; page 158 end
;;; page 159 start XXX; FURBY27.INC page 34
Tbl1_Macro94:
	DW            097       ;SEQ10 HANGING
	DW    00          ;end
;
Tbl1_Macro95:
	DW            098         ;SEQ11 AND SEQ12 HANGING (SIGH)
	DW    00          ;end
;
Tbl1_Macro96:
	DW           099         ;SEQ13 HANGING (HAA)
	DW     00         ;end
;
Tbl1_Macro97:
	DW         100        ;SEQ14 SEQ15 HANGING (hEEY)
	DW         00     ;end
;
Tbl1_Macro98:
	DW            101       ;SEQ16  hANGING (PHONE)
	DW            102
	DW            101
	DW            101
	DW            001        ; 20
	DW            00         ; end
;
Tbl1_Macro99:
	DW            089       ;SEQ6 HANGING AGE2
	DW            089
	DW            090
	DW            091
	DW            103
	DW    00          ;end
;
Tbl1_Macro100:
	DW             089       ;SEQ6 HANGING AGE2
	DW             089
	DW             090
	DW             105
	DW             104
	DW             103
	DW         00     ;end
;
Tbl1_Macro101:
	DW           087
	DW           106        ;SEQ5 AGE3 4
	DW     00         ;end
;END HANGOUT
;
Tbl1_Macro102:
	DW             107        ;Fortune pause
	DW         00     ;end
;
;END GEORGE 07/04/98
;GEORGE 07/05/98

;FEED TABLE
Tbl1_Macro103:
	DW            108
	DW            110        ;SEQ2 FEED AGE1
	DW            109
	DW         00     ;end
;;; page 159 end
;;; page 160 start XXX; FURBY27.INC page 35
;
Tbl1_Macro104:
	DW        108           ;SEQ3 FEED AGE1
	DW        111
	DW        112
	DW        109
	DW    00       ;end
;
Tbl1_Macro105:
	DW        108           ;SEQ4 FEED AGE1
	DW        110
	DW        113
	DW        109
	DW    00       ;end
;
Tbl1_Macro106:
	DW        108           ;SEQ5 FEED AGE1
	DW        108
	DW        078          ;127
	DW        110
	DW        109
	DW    00          ;end
;
Tbl1_Macro107:
	DW        108           ;SEQ6 FEED AGE1
	DW        105           ;109
	DW        114
	DW    00       ;end
;
Tbl1_Macro108:
	DW       108           ;SEQ7 FEED AGE1
	DW       115
	DW       116
	DW       117
	DW       110
	DW    00       ;end
;
Tbl1_Macro109:
	DW        076           ;125      ;SEQ8 FEED AGE1
	DW        117
	DW        120
	DW        118
	DW    00       ;end
;
Tbl1_Macro110:
	DW        108
	DW        115
	DW    20                   ; SEQ9 FEED AGE1
	DW    00       ;end
;
Tbl1_Macro111:
	DW         108           ;SEQ10 FEED AGE1
	DW         109
	DW    00        ;end
;
Tbl1_Macro112:
	DW         108           ;SEQ11 FEED AGE1
	DW         076           ;125
	DW         117
	DW         119
;;; page 160 end
;;; page 161 start XXX; FURBY27.INC page 36
	DW        00     ;end
;
Tbl1_Macro113:
	DW          108          ;SEQ12 FEED AGE1
	DW          108
	DW          109
	DW    00         ;end
;
Tbl1_Macro114:
	DW          108          ;SEQ13 REUSE 10 FOR14    FEED AGE1
	DW          115
	DW          001          ;20
	DW    00         ;end
;
Tbl1_Macro115:
	DW            108          ;SEQ15 FEED AGE1
	DW            076          ;125
	DW            117
	DW            119
	DW            00
;
Tbl1_Macro116:
	DW           108
	DW           108
	DW           109          ;SEQ1 FEED AGE1  ()
	DW    00         ;end
;
Tbl1_Macro117:                            ;WIERD SHIT SEE 101
	DW          108
	DW          120
	DW          109
	DW    00         ;end
;				;end-----------------AGE1
Tbl1_Macro118:
	DW           108
	DW           121
	DW           109          ;SEQ1 FEED AGE2
	DW        00     ;end
;
Tbl1_Macro119:
	DW           108
	DW           051          ;72
	DW           109          ;SEQ2 FEED AGE2
	DW    00         ;end
;
Tbl1_Macro120:
	DW           108
	DW           073          ;122
	DW           112
	DW           109          ;SEQ3 FEED AGE2
	DW        00     ;end
;
Tbl1_Macro121:
	DW           108
	DW           051          ;72
	DW           113
	DW           109          ;SEQ4 FEED AGE2
	DW        00     ;end
;
Tbl1_Macro122:
;;; page 161 end
;;; page 162 start XXX; FURBY27.INC page 37
	DW         108
	DW         108
	DW         078       ; 127          ;SEQ5 FEED AGE2
	DW         051       ;72
	DW         109
	DW      00     ;end
;
Tbl1_Macro123:
	DW           108
	DW           105       ; 109
	DW          114       ; SEQ6   FEED AGE2
	DW    00         ; end
;
Tbl1_Macro124:
	DW          108
	DW          115
	DW          116
	DW          069       ; 118     ;SEQ7 FEED AGE2
	DW          110
	DW    00         ; end
;
Tbl1_Macro125:
	DW          076       ; 125
	DW          057       ; 78
	DW          120
	DW          118       ; SEQ8 FEED AGE2
	DW    00         ; end
;
Tbl1_Macro126:
	DW           108
	DW         115       ; SEQ9   FEED AGE2
	DW        001       ; 20
	DW      00     ; end
;
Tbl1_Macro127:
	DW          108
	DW          109       ;SEQ10 FEED AGE2
	DW    00         ;end

;
; Macro_grp2 was here


;
Tbl2_Macro128:
	DW          108
	DW          076        ;125
	DW          069        ;118
	DW          119        ;SEQ11   FEED AGE2
	DW    00         ;end
;
; Macro_grp2 was here

Tbl2_Macro129:
	DW          108
	DW          076        ;125
	DW          069        ;118
	DW           119       ;SEQ15    FEED AGE2
	DW    00         ; end
;		----------------------------END AGE2----------------|
;;; page 162 end
;;; page 163 start XXX; FURBY27.INC page 38
Tbl2_Macro130:
	DW      108
	DW      110
	DW      109     ;SEQ2 FEED AGE3
	DW    00    ;end
;
Tbl2_Macro131:
	DW      108
	DW      111
	DW      072 ;143
	DW      109      ;SEQ3 FEED AGE3
	DW    00    ;end
;
Tbl2_Macro132:
	DW      108
	DW      110
	DW      058 ;144
	DW      109      ;SEQ4 FEED AGE3
	DW    00    ;end
;
Tbl2_Macro133:
	DW      108
	DW      115
	DW      116
	DW      117
	DW      051     ;72       ;SEQ7 FEED AGE3
	DW    00    ;end
;
Tbl2_Macro134:
	DW      076     ;125
	DW      117
	DW      121
	DW      118      ;SEQ8 FEED AGE3
	DW    00    ;end
;
Tbl2_Macro135:
	DW      108
	DW      076     ;125
	DW      117      ;SEQ11 FEED AGE3
	DW      122
	DW    00    ;end
;		----------------------------------
Tbl2_Macro136:
	DW      108
	DW      051     ;72
	DW      109
	DW    00    ;end
;
Tbl2_Macro137:
	DW      108
	DW      073     ;122
	DW      072     ;121
	DW      109
	DW    00    ;end
;
Tbl2_Macro138:
	DW      108
	DW      051     ;72
	DW      058     ;144
	DW      109
;;; page 163 end
;;; page 164 start XXX; FURBY27.INC page 39
	DW    00    ;end
;
Tbl2_Macro139:
	DW      108
	DW      108
	DW      078     ;127
	DW      051     ;72
	DW      109
	DW    00    ;end
;
Tbl2_Macro140:
	DW      108     ;SEQ 6
	DW      105     ;109
	DW      123
	DW    00    ;end
;
Tbl2_Macro141:
	DW      108
	DW      115
	DW      116
	DW      057     ;78
	DW      051     ;72
	DW    00    ;end
;
Tbl2_Macro142:
	DW      076     ;125
	DW      069     ;118
	DW      121
	DW      118
	DW    00    ;end
;
Tbl2_Macro143:
	DW      108
	DW      125
	DW      057     ;78
	DW      122
	DW    00    ;end
;
Tbl2_Macro144:
	DW      108
	DW      125
	DW      057     ;78
	DW      122
	DW    00    ;end
;
Tbl2_Macro145:
	DW      108
	DW      121
	DW      109
	DW    00    ;end
;END FEED
;END GEORGE 07/05/98

;WAKE
;GEORGE 07/06/98
Tbl2_Macro146:    ;SG DONE
	DW      124     ;02
	DW      125
	DW      126
	DW      00      ;end
;;; page 164 end
;;; page 165 start XXX; FURBY27.INC page 40
;
Tbl2_Macro147:         ;SG DONE
	DW            124
	DW            125
	DW           127
	DW        00     ;end
;
Tbl2_Macro148:         ;SG DONE
	DW           124
	DW           128
	DW          127
	DW    00         ;end
;
Tbl2_Macro149:         ;SG DONE
	DW           124
	DW           129
	DW          055     ;*08
	DW    00         ; end
;
Tbl2_Macro150:         ;SG DONE
	DW          124
	DW          130
	DW           131
	DW          132
	DW    00         ; end
;
Tbl2_Macro151:         ;SG DONE
	DW           124
	DW           130
	DW           131
	DW           123       ;*12
	DW    00         ; end
;
Tbl2_Macro152:         ;SG DONE
	DW          124
	DW          130
	DW          133
	DW          132
	DW    00          ; end
;
Tbl2_Macro153:         ; SG DONE
	DW           124
	DW           130
	DW          133
	DW          123       ;*12
	DW    00         ; end
;
Tbl2_Macro154:         ;SG DONE
	DW            124
	DW        134
	DW        135
	DW        131
	DW        00     ; end
;
Tbl2_Macro155:        ; SG DONE
	DW           124
	DW          134
	DW          136
	DW          131
	DW    00         ; end
;;; page 165 end
;;; page 166 start XXX; FURBY27.INC page 41
;
Tbl2_Macro156:            ;SG DONE
	DW               124
	DW               134
	DW               135
	DW               133
	DW    00              ;end
;
Tbl2_Macro157:            ;SG DONE
	DW               124
	DW               134
	DW               136
	DW               137
	DW               133
	DW    00              ;end
;
Tbl2_Macro158:            ;SG DONE
	DW               124
	DW              138
	DW               139
	DW    00              ;end
;
Tbl2_Macro159:            ;SG DONE
	DW                124
	DW                140
;	DW         141
	DW        00      ;end
;
Tbl2_Macro160:          ;SG DONE
	DW              124
	DW              142
	DW              143
;	DW         141
	DW        00     ;end
;
Tbl2_Macro161:            ;SG DONE
	DW               124
	DW               144
	DW               145
	DW               146
;DW              141
	DW     00             ;end
;
Tbl2_Macro162:            ;SG DONE
	DW               124
	DW               147
	DW               141
	DW    00             ;end
;
Tbl2_Macro163:            ;SG DONE
	DW        124
	DW        148
	DW        00     ;end
;
Tbl2_Macro164:            ;SG DONE
	DW                124
	DW                053     ;29
	DW                149
	DW        150
	DW        00      ;end
;;; page 166 end
;;; page 167 start XXX; FURBY27.INC page 42
;
Tbl2_Macro165:          ;SG DONE
	DW             124
	DW             151
	DW         00      ; end
;
Tbl2_Macro166:          ;SG DONE
	DW             124
	DW             152
	DW             131
	DW             153
	DW             154
	DW    00            ;end
;
Tbl2_Macro167:          ;SG DONE
	DW             124
	DW             152
	DW             155
	DW             153
	DW             154
	DW    00            ;end
;
Tbl2_Macro168:          ;SG DONE
	DW             124
	DW             152
; DW           153
	DW             131
	DW            156
	DW             154
	DW      00          ;end

Tbl2_Macro169:          ;SG DONE
	DW              124
	DW              053     ;*38
	DW              155
	DW      156
	DW     154
	DW    00     ; end
;END WAKE 07/06/98
;END GEORGE
;
;GEORGE 07/06/98
;HUNGER
Tbl2_Macro170:           ;SG D-NE        ;HUNGER
	DW             159
	DW             165
	DW            412        ; DMH
	DW        00       ; end
;
Tbl2_Macro171:                ;SG DONE
	DW          160
	DW          165
	DW          412        ; DMH
	DW        00       ; end
;
Tbl2_Macro172:           ;SG DONE
	DW          160
	DW         00      ; end
;
Tbl2_Macro173:          ;SG DONE
;;; page 167 end
;;; page 168 start XXX; FURBY27.INC page 43
	DW            168
	DW            159
	DW            165
	DW            412         ;DMH
	DW         00     ;end
;
Tbl2_Macro174:                   ;SG DONE
	DW            168
	DW            160
	DW            165
	DW            412         ;DMH
	DW         00     ;end
;
Tbl2_Macro175:           ;SG DONE
	DW           168
	DW           160
	DW           412       ;DMH
	DW    00         ;end
;
Tbl2_Macro176:                  ;SG DONE
	DW                163
	DW                158
	DW                 159
	DW     00              ;end
;
Tbl2_Macro177:                    ;SG DONE
	DW                 163
	DW                 158
	DW                 160
	DW    00               ;end
;
Tbl2_Macro178:                 ;SG DONE
	DW                 163
	DW                 157
	DW                 159
	DW    00               ;end
;
Tbl2_Macro179:                  ;SG DONE
	DW                  163
	DW                  157
	DW                  160
	DW        00     ;end
;
Tbl2_Macro180:                  ;SG DONE
	DW              163
	DW              168

	DW        159
	DW        163
	DW        00     ;end
;
Tbl2_Macro181:                 ;SG DONE
	DW              163
	DW              168
	DW              160
	DW              163
	DW    00 ;end
;
Tbl2_Macro182:                   ;SG DONE
	DW               163
;;; page 168 end
;;; page 169 start XXX; FURBY27.INC page 44
	DW      163
	DW      168
	DW      161
	DW      159
	DW      165
	DW      412     ;DMH
	DW    00    ;end
;
Tbl2_Macro183:      ;SG DONE
	DW      163
	DW      163
	DW      168
	DW      161
	DW      160
	DW      165
	DW      412     ;DMH
	DW    00    ;end
;
Tbl2_Macro184:       ;SG DONE
	DW      163
	DW      163
	DW      168
	DW      162
	DW      160
	DW    00    ;end
;
Tbl2_Macro185:       ;SG DONE
	DW      168
	DW      161
	DW      159
	DW    00    ;end
;
Tbl2_Macro186:       ;SG DONE
	DW      168
	DW      161
	DW      160
	DW    00    ;end
;
Tbl2_Macro187:       ;SG DONE
	DW      168
	DW      162
	DW      159
	DW    00    ;end
;
Tbl2_Macro188:        ;SG DONE
	DW      168
	DW      162
	DW      160
	DW    00    ;end
;
Tbl2_Macro189:        ;SG DONE
	DW      168
	DW      166
	DW      159
	DW    00    ;end
;
Tbl2_Macro190:        ;SG DONE
	DW      168
	DW      167
	DW      159
;;; page 169 end
;;; page 170 start XXX; FURBY27.INC page 45
	DW       165
	DW       412        ;DMH
	DW    00     ;end
;
Tbl2_Macro191:              ;SG DONE
	DW      168
	DW       167
	DW       160
	DW       165
	DW       412        ;DMH
	DW    00     ;end
;
Tbl2_Macro192:              ;SG DONE
	DW      168
	DW       167
	DW       160
	DW    00     ;end
;
Tbl2_Macro193:              ;SG DONE
	DW      163
	DW       163
	DW    00     ;end
;
Tbl2_Macro194:              ;SG DONE
	DW      163
	DW       163
	DW       165
	DW       412        ;DMH
	DW    00     ;end
;
Tbl2_Macro195:              ;SG DONE
	DW      168
	DW       161
	DW       159
	DW    00     ;end
;
Tbl2_Macro196:              ;SG DONE
	DW      168
	DW       161
	DW       160
	DW    00     ;end
;
Tbl2_Macro197:              ;SG DONE
	DW      168
	DW       162
	DW       159
	DW    00     ;end
;
Tbl2_Macro198:              ;SG DONE
	DW      168
	DW       162
	DW       160
	DW    00     ;end
;
Tbl2_Macro199:             ;SG DONE
	DW        164
	DW        168
	DW        161
	DW       159
	DW       165
;;; page 170 end
;;; page 171 start XXX; FURBY27.INC page 46
	DW         00     ;end
;
Tbl2_Macro200:                   ;SG DONE
	DW            164
	DW            168        ; fs40
	DW            162
	DW            159
	DW            165
	DW    00          ;end
;
Tbl2_Macro201:                  ;SG DONE
	DW            164
	DW            168        ;40
	DW            162
	DW            160
	DW            165
	DW         00     ;end

;END HUNGER
;END GEORGE 07/06/98
;
;
;INVERT
;GEORGE 07/07/98
Tbl2_Macro202:       ;SG DONE             ;INVERT
	DW      164       ;64
	DW    00     ;end
;
Tbl2_Macro203:            ;SG DONE
	DW            164       ;64
	DW            169
	DW    00          ;end
;
Tbl2_Macro204:               ;SG DONE
	DW            164        ;64
	DW            168        ;40
	DW            174
	DW            166
	DW            175
	DW        00     ;end
;
Tbl2_Macro205:              ;SG DONE
	DW           164        ;64
	DW           176
	DW    00          ;end
;
Tbl2_Macro206:            ;SG DONE
	DW            188
	DW            177
	DW    00          ;end
;
Tbl2_Macro207:          ;SG DONE
	DW        188
	DW        178
	DW        00     ;end
;
Tbl2_Macro208:          ;SG DONE
	DW            170
	DW            177
	DW            177
;;; page 171 end
;;; page 172 start XXX; FURBY27.INC page 47
	DW        00     ;end
;
Tbl2_Macro209:         ;SG DONE
	DW           170
	DW           178
	DW           177
	DW    00         ;end
;
Tbl2_Macro210:        ;SG DONE
	DW           170
	DW           177
	DW           178
	DW        00     ;end
;
Tbl2_Macro211:        ;SG DONE
	DW           170
	DW           178
	DW           178
	DW     00        ;end
;
Tbl2_Macro212:        ;SG DONE
	DW           171
	DW           163      ;63
	DW     00        ;end
;
Tbl2_Macro213:        ;SG DONE
	DW           171
	DW           168       ;40
	DW           179
	DW           180
	DW           165       ;65
	DW        00     ;end
;
Tbl2_Macro214:        ;SG DONE
	DW          171
	DW          168       ;40
	DW          181
	DW          180
	DW          165       ;65
	DW    00         ;end
;
Tbl2_Macro215:        ;SG DONE
	DW           171
	DW           168
	DW           179
	DW           182
	DW           165       ;65
	DW    00         ;end
;
Tbl2_Macro216:        ;SG DONE
	DW           171
	DW           168       ;40
	DW           181
	DW           182
	DW        00     ;end
;
Tbl2_Macro217:        ;SG DONE
	DW           164      ;64
	DW           175
	DW           164      ;64
;;; page 172 end
;;; page 173 start XXX; FURBY27.INC page 48
	DW          00     ;end
;
Tbl2_Macro218:          ;SG DONE
	DW            164     ;64
	DW            183
	DW            164     ;64
	DW    00            ;end
;
Tbl2_Macro219:          ;SG DONE
	DW             164      ;64
	DW             170
	DW             170
	DW    00            ;end
;
Tbl2_Macro220:          ;SG DONE
	DW            171
	DW            179
	DW            180
	DW    00            ;end
;
Tbl2_Macro221:          ;SG DONE
	DW            171
	DW            181
	DW            180
	DW    00            ;end
;
Tbl2_Macro222:          ;SG DONE
	DW            171
	DW            179
	DW            184
	DW             163       ;63
	DW    00           ;end
;
Tbl2_Macro223:          ;SG DONE
	DW             171
	DW             181
	DW             185
	DW          00     ;end
;
Tbl2_Macro224:        ;SG DONE
	DW            164      ;64
	DW            179
	DW            186
	DW     00           ;end
;
Tbl2_Macro225:          ;SG DONE
	DW             164      ;64
	DW             181
	DW             186
	DW    00            ;end
;
Tbl2_Macro226:          ;SG DONE
	DW             164     ;64
	DW         181
	DW         185
	DW         00      ;end
;
Tbl2_Macro227:          ;SG DONE
	DW         164     ;64
	DW         181
;;; page 173 end
;;; page 174 start XXX; FURBY27.INC page 49
	DW           184
	DW          163         ; 63
	DW        00     ;end
;
Tbl2_Macro228:       ;SG DONE
	DW          164      ;64
	DW          179
	DW          187
	DW    00         ;end
;
Tbl2_Macro229:       ;SG DONE
	DW          164       ;64
	DW         181
	DW         187
	DW       00      ;end
;
Tbl2_Macro230:        ;SG DONE
	DW           172
	DW           158
	DW        178
	DW        00     ;end
;
Tbl2_Macro231:        ;SG DONE
	DW          164      ;64
	DW          181
	DW          189
	DW    00          ;end
;
Tbl2_Macro232:     ;SG DONE
	DW          172
	DW           175
	DW      00        ;end
;
Tbl2_Macro233:       ;SG DONE
	DW           172
	DW           183
	DW    00         ;end
;
Tbl2_Macro234:     ;SG DONE
	DW           172
	DW           172
	DW          164         ;64
	DW     00        ;end
;
Tbl2_Macro235:       ;SG DONE
	DW           173
	DW    00          ;end
;
Tbl2_Macro236:        ;SG DONE
	DW           190
	DW       00     ;end
;
Tbl2_Macro237:       ;SG DONE
	DW           191
	DW    00         ;end
;
Tbl2_Macro238: ;SG DONE
	DW      192
	DW     00    ;end
;END GEORGE 07/07/98
;;; page 174 end
;;; page 175 start XXX; FURBY27.INC page 50
;END INVERT

;GEORGE 07/07/98
;BACK
Tbl2_Macro239:  ;BACKSG  ;SGDONE
	DW      193
	DW      193
	DW   00    ;end
;
Tbl2_Macro240:         ;SGDONE
	DW      193
	DW      194
	DW      195
	DW    00    ;end
;
Tbl2_Macro241:         ;SGDONE
	DW      193
	DW      196
	DW      195
	DW    00    ;end
;
Tbl2_Macro242:         ;SGDONE
	DW      193
	DW      194
	DW      197
	DW    00    ;end
;
Tbl2_Macro243:         ;SGDONE
	DW      193
	DW      196
	DW      197
	DW    00    ;end
;
Tbl2_Macro244:         ;SGDONE
	DW      198
	DW      199
	DW      200
	DW      201
	DW    00    ;end
;
Tbl2_Macro245:         ;SGDONE
	DW      198
	DW      199
	DW      202
	DW      201
	DW    00    ;end
;
Tbl2_Macro246:         ;SGDONE
	DW      198
	DW      199
	DW      200
	DW      184     ;148     ;212
	DW      00      ;end
;
Tbl2_Macro247:         ;SGDONE
	DW      198
	DW      199
	DW      202
	DW      184     ;148     ;212
	DW    00    ;end
;;; page 175 end
;;; page 176 start XXX; FURBY27.INC page 51
;
Tbl2_Macro248:              ;SGDONE
	DW        198
	DW        198
	DW    00      ;end
;
Tbl2_Macro249:              ;SGDONE
	DW       198
	DW       203
	DW       204
	DW    00      ;end
;
Tbl2_Macro250:              ;SGDONE
	DW       198
	DW       205
	DW       206
	DW       207
	DW       204
	DW    00      ;end
;
Tbl2_Macro251:              ;SGDONE
	DW       198
	DW        205
	DW        208
	DW        233
	DW        204
	DW    00      ;end
;
Tbl2_Macro252:             ;SGDONE
	DW        198
	DW        205
	DW        206
	DW        233
	DW        204
	DW     00     ;end
;
Tbl2_Macro253:              ;SGDONE
	DW        198
	DW        209
	DW        210
	DW        00         ;end
;
Tbl2_Macro254:              ;SGDONE
	DW       198
	DW       209
	DW       211
	DW       212
	DW       213
	DW    00      ;end
;
Tbl2_Macro255:              ;SGDONE
	DW        198
	DW        209
	DW        214
	DW    00      ;end
;
Tbl3_Macro256:             ;SGDONE
	DW        198
	DW        215
	DW        216
;;; page 176 end
;;; page 177 start XXX; FURBY27.INC page 52
	DW           217
	DW           00             ;end
;
Tbl3_Macro257:                     ;SGDONE
	DW           198
	DW           215
	DW           216
	DW           218
	DW        00     ; end
;
Tbl3_Macro258:                    ;SGDONE
	DW          219
	DW          220
	DW          209
	DW          217
	DW          199
	DW          234
	DW    00         ; end
;
Tbl3_Macro259:                    ;SGDONE
	DW           219
	DW           220
	DW           209
	DW           205
	DW           217
	DW           234
	DW           00            ;end
;
Tbl3_Macro260:                     ;SGDONE
	DW           219
	DW           220
	DW           209
	DW           205
	DW           218
	DW           234
	DW    00         ; end
;
Tbl3_Macro261:                     ;SGDONE
	DW           221
	DW        222
	DW        00        ; end
;
Tbl3_Macro262:                     ;SGDONE
	DW          221
	DW          223
	DW          222
	DW    00            ; end
;
Tbl3_Macro263:                      ;SGDONE
	DW           198
	DW           224
	DW           199
	DW    00         ; end
;
Tbl3_Macro264:                      ;SGDONE
	DW           198
	DW        224
	DW        205
	DW        00     ; end
;
;;; page 177 end
;;; page 178 start XXX; FURBY27.INC page 53
Tbl3_Macro265:                ;SGDONE
	DW         198
	DW         225
	DW         205
	DW    00       ; end
;
Tbl3_Macro266:                ;SGDONE
	DW         226
	DW         201
	DW    00       ;end
;
Tbl3_Macro267:                ;SGDONE
	DW         198
	DW         227
	DW         227
	DW         228
	DW         229
	DW      00     ;end
;
Tbl3_Macro268:                ;SGDONE
	DW         198
	DW         227
	DW         227
	DW        230
	DW         229
	DW      00     ; end
;
Tbl3_Macro269:                ;SGDONE
	DW         198
	DW         194
	DW         199
	DW    00       ;end
;
Tbl3_Macro270:               ;SGDONE
	DW         198
	DW         194
	DW         205
	DW      00     ;end
;
Tbl3_Macro271:               ;SGDONE
	DW         198
	DW         196
	DW         205
	DW      00     ;end
;
Tbl3_Macro272:               ;SGDONE
	DW         198
	DW         235
	DW         231
	DW         199
	DW      00     ;end
;
Tbl3_Macro273:              ;SGDONE
	DW        198
	DW        235
	DW        231
	DW        205
	DW     00      ;end
;
Tbl3_Macro274:               ;SGDONE
;;; page 178 end
;;; page 179 start XXX; FURBY27.INC page 54
	DW      198
	DW      235
	DW      232
	DW      205
	DW    00    ;end
;
Tbl3_Macro275:         ;SGDONE
	DW      198
	DW      236
	DW      232
	DW      205
	DW    00    ;end
;END GEORGE 07/07/98
;END BACK
;
;GEORGE 07/08/98
;SICK


Tbl3_Macro276:   ;SG DONE  ;SICK3
	DW      237
	DW      168     ;135     ;40
	DW      117     ;41
	DW      238
	DW    00    ;end
;
Tbl3_Macro277:   ;SG DONE
	DW      237
	DW      168     ;135     ;40
	DW      239
	DW      238
	DW    00    ;end
;
Tbl3_Macro278:   ;SG DONE
	DW      237
	DW      168     ;135     ;40
	DW      117     ;41
	DW      240
	DW    00    ;end
;
Tbl3_Macro279:   ;SG DONE
	DW      237
	DW      53      ;45
	DW      239
	DW      240
	DW    00    ;end
;
Tbl3_Macro280:   ;SG DONE
	DW      237
	DW      241
	DW    00    ;end
;
Tbl3_Macro281:   ;SG DONE
	DW      237
	DW      242
	DW    00    ;end
;
Tbl3_Macro282:   ;SG DONE
	DW      237
	DW      243
;;; page 179 end
;;; page 180 start XXX; FURBY27.INC page 55
	DW            244
	DW        00      ;end
;
Tbl3_Macro283:            ;SG DONE
	DW               250
	DW               117      ;41
	DW               245
	DW        00       ;end
;
Tbl3_Macro284:            ;SG DONE
	DW               250
	DW               239
	DW               245
	DW        00      ;end
;
Tbl3_Macro285:            ;SG DONE
	DW               250
	DW               239
	DW               182      ;51
	DW               00       ;end
;
Tbl3_Macro286:            ;SG DONE
	DW               237
	DW               246
	DW               250
	DW        00        ;end
;
Tbl3_Macro287:            ;SG DONE
	DW               237
	DW               247
	DW               250
	DW        00         ;end
;
Tbl3_Macro288:            ;SG DONE
	DW               237
	DW        00         ;end
;
Tbl3_Macro289:            ;SG DONE
	DW               237
	DW               248
	DW               250
	DW        00
;
Tbl3_Macro290:            ;SG DONE
	DW               237
	DW               249
	DW               00         ;end
;
Tbl3_Macro291:            ;SG DONE
	DW               250
	DW               250
	DW    00             ;end
;
Tbl3_Macro292:            ;SG DONE
	DW               250
	DW               248
	DW        00         ;end
;END SICK
;END GEORGE 07/08/98
;;; page 180 end
;;; page 181 start XXX; FURBY27.INC page 56
;GEORGE 07/08/98
;LIGHT
Tbl3_Macro293:
	DW         251
	DW         00           ;end   RB
;
;Tbl1_Macro294:
;	DW         263
;	DW         00            ;end        RB
;
Tbl3_Macro294:
	DW         252
	DW         00           ; end         RB
;
Tbl3_Macro295:
	DW         253
	DW         00           ;end               RB
;
Tbl3_Macro296:
	DW         254
	DW         00           ;end                    RB
;
Tbl3_Macro297:
	DW         255
	DW         00           ;end                     RB
;
Tbl3_Macro298:
	DW         256
	DW    00       ;end
;
Tbl3_Macro299:
	DW         257
	DW         00           ;end
;
Tbl3_Macro300:
	DW         258
	DW    00       ; end
;
Tbl3_Macro301:
	DW         259
	DW    00       ;end
;
Tbl3_Macro302:
	DW        260
	DW    00       ;end
;
Tbl3_Macro303:
	DW         261
	DW     00         ;end
;
Tbl3_Macro304:
	DW         262
	DW    00       ;end
;
Tbl3_Macro305:
	DW        263
	DW    00       ;end
;
Tbl3_Macro306:
	DW         264
;;; page 181 end
;;; page 182 start XXX; FURBY27.INC page 57
	DW    00        ;end
;
Tbl3_Macro307:
	DW      265
	DW   00     ;end
;END GEORGE 07/08/98
;END LIGHT
;GEORGE 07/08/98
;DARK


Tbl3_Macro308:
	DW      266
	DW    00     ;end
;
Tbl3_Macro309:
	DW          267
	DW    00         ;end
;
Tbl3_Macro310:
	DW          268
	DW    00         ;end
;
Tbl3_Macro311:
	DW            269
	DW    00          ;end
;
Tbl3_Macro312:
	DW          270
	DW    00         ;end
;
Tbl3_Macro313:
	DW          271
	DW    00         ;end
;
Tbl3_Macro314:
	DW          272
	DW    00         ;end
;
Tbl3_Macro315:
	DW          273
	DW    00         ;end
;
Tbl3_Macro316:
	DW           274
	DW           00           ;end
;
Tbl3_Macro317:
	DW           275
	DW    00         ;end
;
Tbl3_Macro318:
	DW          276
	DW    00         ;end
;
Tbl3_Macro319:
	DW          277
	DW     00        ;end
;
Tbl3_Macro320:
	DW           278
;;; page 182 end
;;; page 183 start XXX; FURBY27.INC page 58
	DW        00      ;end
;
Tbl3_Macro321:
	DW            279
	DW    00          ;end
;
Tbl3_Macro322:
	DW             280
	DW     00          ;end
;
Tbl3_Macro323:
	DW            281
	DW    00          ;end
;
Tbl3_Macro324:
	DW            282
	DW    00          ;end
;
Tbl3_Macro325:
	DW           283
	DW    00          ;end
;
Tbl3_Macro326:
	DW            284
	DW    00          ;end
;
Tbl3_Macro327:
	DW            285
	DW    00          ;end
;
Tbl3_Macro328:
	DW         286
	DW        00      ;end
;
Tbl3_Macro329:
	DW           287
	DW    00          ;end
;
Tbl3_Macro330:
	DW            288
	DW       00      ;end
;
Tbl3_Macro331:
	DW           289
	DW    00         ;end
;END DARK
;END GEORGE 07/08/98

;GEORGE 07/08/98
;SOUND

Tbl3_Macro332:
	DW             290         ;Sl-Al/S9-A1/S1-A2 SOUND js
	DW     00       ;end

Tbl3_Macro333:
	DW            291         ;S2-A1/S10-A1/S2-A2 SOUND js
	DW      00      ;end

Tbl3_Macro334:
;;; page 183 end
;;; page 184 start XXX; FURBY27.INC page 59
	DW          292         ;S3-A1/S11-A1 SOUND js
	DW        00      ;end
;
Tbl3_Macro335:
	DW         293         ;S4-A1/S12-A1 SOUND js
	DW        00     ;end
;
Tbl3_Macro336:
	DW          310
	DW          294         ;S5-A1/S13-A1 SOUND (with say/m2) js
	DW         00     ;end
;
Tbl3_Macro337:
	DW          295         ;S6-A1/S14-A1 SOUND js
	DW        00      ;end
;
Tbl3_Macro338:
	DW          310
	DW          296         ;S7-A1/S15-A1 SOUND (with say/m2) js
	DW        00      ;end
;
Tbl3_Macro339:
	DW          297         ;S8-A1/S16-A1 SOUND js
	DW        00      ;end
;
Tbl3_Macro340:
	DW          298         ;S3-A2 SOUND js
	DW        00      ;end
;
Tbl3_Macro341:
	DW          299         ;S4-A2 SOUND js
	DW        00      ;end
;
Tbl3_Macro342:
	DW          310
	DW          300         ;S5-A2 SOUND (with say/m2) js
	DW        00      ;end
;
Tbl3_Macro343:
	DW          310
	DW          301         ;S7-A2 SOUND (with say/m2) js
	DW        00      ;end
;
Tbl3_Macro344:
	DW          302         ;S8-A2 SOUND js
	DW        00      ;end
;
Tbl3_Macro345:
	DW          303         ;S3-A3 SOUND js
	DW        00      ;end
;
Tbl3_Macro346:
	DW          304         ;S4-A3 SOUND js
	DW          00         ;end
;
Tbl3_Macro347:
	DW          310
	DW          305         ;S7-A3 SOUND (with say/m2) js
	DW         00     ;end
;
;;; page 184 end
;;; page 185 start XXX; FURBY27.INC page 60
Tbl3_Macro348:
	DW            306       ;S1-A4 SOUND js
	DW    00           ; end
;
Tbl3_Macro349:
	DW            307       ;S3-A4 SOUND js
	DW    00           ; end
;
Tbl3_Macro350:
	DW             308       ;S6-A4 SOUND js
	DW    00           ;end
;
Tbl3_Macro351:
	DW             309       ;S8-A4 SOUND js
	DW    00           ; end
;
;END GEOROE 07/08/98
;END SOUND
;
;
;TILT
;GEORGE 07/09/93
Tbl3_Macro352:
	DW       310            ;S1 A1 TILT/S4 A1 TILT js
	DW      00   ; end
;
Tbl3_Macro353:
	DW             311       ;S2 A1 TILT js
	DW    00           ;end
;
Tbl3_Macro354:
	DW        312       ;S3 A1 TILT js
	DW        00     ;end
;
Tbl3_Macro355:
	DW             313       ;S5 A1 TILT js
	DW    00           ;end
;
Tbl3_Macro356:
	DW            314       ;S6 A1 TILT js
	DW    00           ; end
;
Tbl3_Macro357:
	DW          315       ;S7 A1 TILT js
	DW       00     ; end
;
Tbl3_Macro358:
	DW            313       ;S8 A1 TILT js
	DW             316
	DW    00           ; end
;
Tbl3_Macro359:
	DW            317       ;S9 A1 TILT js
	DW    00           ; end
;
Tbl3_Macro360:
	DW            318       ;S10 A1 TILT js
	DW    00           ; end
;
Tbl3_Macro361:
;;; page 185 end
;;; page 186 start XXX; FURBY27.INC page 61
;;; page 186 end
	DW           310         ;S11 A1 TILT js
	DW           319
	DW        00     ;end
;
Tbl3_Macro362:
	DW           320         ;S12 A1 TILT js
	DW    00         ;end
;
Tbl3_Macro363:
	DW           321         ;S13 A1 TILT js
	DW    00         ;end
;
Tbl3_Macro364:
	DW          322         ;S15 A1 TILT js
	DW    00         ;end
;
Tbl3_Macro365:
	DW          323         ;S16 A1 TILT js
	DW    00         ;end
;
Tbl3_Macro366:
	DW           324         ;S1 A1 TILT js
	DW        00     ;end
;
Tbl3_Macro367:
	DW          324
	DW          325         ;S2 A1 TILT js
	DW    00         ;end
;
Tbl3_Macro368:
	DW          326         ;S5 A2 TILT js
	DW    00         ;end
;
Tbl3_Macro369:
	DW           313
	DW           327         ;S7 A2 TILT js
	DW    00         ;end
;
Tbl3_Macro370:
	DW           313
	DW           328         ;S8   A2 TILT js
	DW    00         ;end
;
Tbl3_Macro371:
	DW        310
	DW        329         ;S11 A2 TILT js
	DW        00     ;end
;
Tbl3_Macro372:
	DW           330         ;S12 A2 TILT js
	DW        00     ;end
;
Tbl3_Macro373:
	DW          313
	DW           331         ;S13 A2 TILT js
	DW     00        ;end
;
Tbl3_Macro374:
	DW           332         ;S12 A2 TILT js
	DW    00         ;end
;;; page 187 start XXX; FURBY27.INC page 62
;
Tbl3_Macro375:
	DW          333
	DW    00         ;end
;
Tbl3_Macro376:
	DW           334
	DW    00         ;end
;
Tbl3_Macro377:
	DW           334
	DW           335
	DW    00         ;end
;
Tbl3_Macro378:
	DW          336
	DW    00         ;end
;
Tbl3_Macro379:
	DW           313
	DW           337
	DW        00     ;end
;
Tbl3_Macro380:
	DW           313
	DW        338
	DW        00     ;end
;
Tbl3_Macro381:
	DW           339
	DW    00         ;end
;
Tbl3_Macro382:
	DW           317
	DW          340
	DW    00         ;end
;
Tbl3_Macro383:
	DW           341
	DW    00         ;end
;
Tbl4_Macro384:
	DW           310
	DW           329
	DW           342
	DW    00         ;end
;
Tbl4_Macro385:
	DW          313
	DW          343
	DW    00         ;end
;
Tbl4_Macro386:
	DW           313
	DW           344
	DW    00         ;end
;
Tbl4_Macro387:
	DW           334
	DW           345
;;; page 187 end
;;; page 188 start XXX; FURBY27.INC page 63
	DW    00    ;end
;
Tbl4_Macro388:
	DW      346
	DW    00    ;end
;
Tbl4_Macro389:
	DW      313
	DW      347
	DW    00    ;end
;
Tbl4_Macro390:
	DW      310
	DW      348
	DW    00    ;end
;
Tbl4_Macro391:
	DW      313
	DW      349
	DW    00    ;end
;
Tbl4_Macro392:
	DW      313
	DW      350
	DW    00    ;end
;END TILT
;END GEORGE 07/09/98
;
;IR
;GEORGE 07/09/98
Tbl4_Macro393:
	DW      351
	DW    00    ;end
;
;
Tbl4_Macro394:
	DW      352      seq5, IR age1
	DW    00    ;end
;
Tbl4_Macro395:
	DW      353        seq6, IR age1
	DW      354
	DW    00    ;end
;
Tbl4_Macro396:
	DW      356        ;seq7 ir age1
	DW      355
	DW    00    ;end
;
Tbl4_Macro397:
	DW      357      ;seq8 ir age1
	DW    00    ;end
;
Tbl4_Macro398:
	DW      358      ;seq9 ir age1
	DW    00    ;end
;
Tbl4_Macro399:
	DW      359      ;seq        10,360 ir age1
	DW    00    ;end
;;; page 188 end
;;; page 189 start XXX; FURBY27.INC page 64
Tbl4_Macro400:
	DW       360       ;seq12 ir age1,age2,age,3
	DW    00     ;end
;
Tbl4_Macro401:
	DW      361       ;seq13,14 ir age1
	DW    00     ;end
;
Tbl4_Macro402:
	DW       362        ;seq15    ir age1
	DW    00     ;end
;
Tbl4_Macro403:
	DW       363       ;seq16 ir age1
	DW    00     ;end
;
Tbl4_Macro404:
	DW      364       ;seq1,2,3 ir age2
	DW    00     ;end
;
Tbl4_Macro405:
	DW      365       ;seq4,5 ir age2
	DW    00     ;end
;
Tbl4_Macro406:
	DW      366       ;seq6 ir age2
	DW    00     ;end
;
Tbl4_Macro407:
	DW        367         ;seq7,8 ir age 2
	DW    00     ;end
;
Tbl4_Macro408:
	DW      368         ;seq9    ir age2
	DW    00     ;end
;
Tbl4_Macro409:
	DW      369         ;seq10    ir age2
	DW    00     ;end
;
Tbl4_Macro410:
	DW      370       ;seq11 ir age2
	DW    00     ;end
;
Tbl4_Macro411:
	DW      371        ;seq13,14 ir age2
	DW    00     ;end
;
Tbl4_Macro412:
	DW      372       ;seq15 ir age2
	DW    00     ;end
;
Tbl4_Macro413:
	DW       373        ;seq16 ir age2
	DW    00     ;end
;
Tbl4_Macro414:
	DW       374        ;seq1,2,3,4,5 ir age3
	DW    00     ;end
;;; page 189 end
;;; page 190 start XXX; FURBY27.INC page 65
;
Tbl4_Macro415:
	DW      375     ;seq6 ir age3
	DW    00    ;end
;
Tbl4_Macro416:
	DW      376     ;seq7,8   ir age3
	DW    00    ;end
;
Tbl4_Macro417:
	DW      377     ;seq9 ir age3
	DW    00    ;end
;
Tbl4_Macro418:
	DW      378     ;seq11 ir age3
	DW    00    ;end
;
Tbl4_Macro419:
	DW      379     ;seq13,14 ir age3
	DW    00    ;end
;
Tbl4_Macro420:
	DW      380     ;seq15 ir age3
	DW    00    ;end
;
Tbl4_Macro421:
	DW      381     ;seq1,2,3,4,5 ir age4
	DW    00    ;end
;
Tbl4_Macro422:
	DW      382     ;seq6 ir age4
	DW    00    ;end
;
Tbl4_Macro423:
	DW      383     ;seq7.8 ir age4
	DW    00    ;end
;
Tbl4_Macro424:
	DW      384     ;seq9 ir age4
	DW    00    ;end
;
Tbl4_Macro425:
	DW      385     ;seq1O ir age4
	DW    00    ;end
;
Tbl4_Macro426:
	DW      386     ;seq11 ir age4
	DW    00    ;end
;
Tbl4_Macro427:
	DW      387     ;seq12 ir age4
	DW    00    ;end
;
Tbl4_Macro428:
	DW      389
	DW      388     ;seq14 ir age4
	DW      389
	DW  00    ;end
;
Tbl4_Macro429:
;;; page 190 end
;;; page 191 start XXX; FURBY27.INC page 66
	DW         389          ;seq15 ir age4
	DW         390
	DW    00        ; end
;END GEORGE
;END IR
;

; START FURBY SAYS DMH
Tbl4_Macro430:
	DW    50       ; TICKLE
	DW    00    ; end
;
Tbl4_Macro431:
	DW    196          ; PET
	DW    00        ; end
;
Tbl4_Macro432:
	DW    71           ; SOUND
	DW    00        ; end
;
Tbl4_Macro433:
	DW    391         ; LIGHT
	DW    00        ;end
;
Tbl4_Macro434:
	DW    198          ; soft purr
	DW    00        ; end
;
Tbl4_Macro435:
	DW     392        ; no light
	DW     00      ; end
;
Tbl4_Macro436:
	DW     393         ; loud sound
	DW     00       ; end
;
Tbl4_Macro437:
	DW     115        ; burp     (hide and seek)
	DW     00       ;end
;
Tbl4_Macro438:
	DW    116          ; sigh     (hide and   seek)
	DW    00         ;end
;
Tbl4_Macro439:                 ;   win sound    (dmh)
	DW          376
	DW          376
	DW          367
	DW    00    ;end
; END FURBY SAYS DMH
;
;
; start diagnostic tables
Tbl4_Macro440:                           ;   start diagnostic beeps
	DW    400
	DW    00    ;end
;
Tbl4_Macro441:                           ;   press key beep
	DW    401
	DW    00         ; end
;;; page 191 end
;;; page 192 start XXX; FURBY27.INC page 67
;
Tbl4_Macro442:                          ;   pass beep
	DW    402
	DW    00      ; end
;
Tbl4_Macro443:
	DW    403                   ;   fail beep
	DW    00      ; end
;
Tbl4_Macro444:                          ;   speaker test tone
	DW    404
	DW    00      ; end
;
Tbl4_Macro445:                          ;   motor cal
	DW    405
	DW    00      ; end
;
Tbl4_Macro446:                          ;   feed1
	DW    406
	DW    00      ; end
;
Tbl4_Macro447:                          ;   feed2
	DW    407
	DW    00      ;end
;
Tbl4_Macro448:                          ;   light
	DW    408
	DW    00      ; end
;
Tbl4_Macro449:                          ;   sound
	DW    409
	DW    00      ; end
;
Tbl4_Macro450:                          ;   go to sleep
	DW    410
	DW    00      ;end
;
; end of diagnostic tables dmh
;
Tbl4_Macro451:
	DW        117       ;   HIDE AND SEEK SOUND DHM
	DW    00      ;end
;
Tbl4_Macro452:
	DW        118       ;   HIDE AND SEEK SOUND DHM
	DW    00      ; end
;
Tbl4_Macro453:
	DW       399       ;   delay
	DW       395       ;   ME DHM
	DW       110       ;   NAME "KOKO" DMH
	DW    00      ; end
;
Tbl4_Macro454:
	DW       399          ; delay
	DW       395          ; ME DHM
	DW       396          ; NAME "MEME" DMH
	DW    00      ;end
;
Tbl4_Macro455:
;;; page 192 end
;;; page 193 start XXX; FURBY27.INC page 68
	DW        399               ; delay
	DW        395               ; ME
	DW        112               ; NAME "E-DAY" DMH
	DW	00     ;end

Tbl4_Macro456:
	DW        399       ; delay
	DW        395       ; ME
	DW        397       ; NAME "DO-MOH" DMH
	DW        00        ; end
Tbl4_Macro457:
	DW        399       ;       delay
	DW       395       ;       ME
	DW       114       ;       NAME "TO-TYE" DMH
	DW    00      ; end

Tbl4_Macro458:
	DW        399       ;       delay
	DW        395       ;       ME
	DW        117       ;       NAME "BOO" DHM
	DW    00      ; end

Tbl4_Macro459:
	DW       399       ;        delay
	DW       395       ;        ME
	DW       398       ;        NAME "TOH-LOO" DHM
	DW    00      ; end

Tbl4_Macro460:
	DW        399       ;       delay
	DW       395       ;        ME
	DW        120       ;        NAME "A-TAY" DHM
	DW    00      ; end

Tbl4_Macro461:
	DW        399       ;       delay
	DW        395       ;       ME
	DW       131       ;       NAME "WAY-LOH"   DMH
	DW    00      ; end

Tbl4_Macro462:
	DW        399       ;       delay
	DW        395       ;       ME
	DW       143       ;       NAME "U-TYE"
	DW       00

Tbl4_Macro463:
	DW        399           ;   delay
	DW        395           ;   ME
	DW        145           ;   NAME "A-LOH" DMH
	DW     00     ; end

Tbl4_Macro464:
	DW        399           ;   delay
	DW        395           ;   ME
	DW        152           ;   NAME "KA" DMH
	DW    00      ; end

Tbl4_Macro465:
	DW        399           ;   delay
;;; page 193 end
;;; page 194 start XXX; FURBY27.INC page 69
	DW         395        ; ME
	DW         166        ;   NAME "DAH" DMH
	DW         00     ;end
;
Tbl4_Macro466:
	DW            399        ; delay
	DW         395       ; ME
	DW         175        ; NAME "BOH-BAY" DMH
	DW         00      ;end
;
Tbl4_Macro467:
	DW            399        ; delay
	DW             395        ; ME
	DW         177        ; NAME "NAH-BAH" DMH
	DW         00     ;end
;
Tbl4_Macro468:
	DW            129        ;   dodle do, me love you DMH
	DW           129
	DW         151
	DW         00     ;end
;
Tbl4_Macro469:                   ;   SING A SONG DMH

	DW         219
	DW        220
;	DW         219
	DW         220
	DW         219
	DW         220
	DW         00     ;end
;
Tbl4_Macro470:                   ;   BURB ATTACK DMH
	DW         115
	DW         115
	DW         115
	DW         115
	DW         115
	DW         115
	DW          115
	DW         115
	DW         00     ;end
;
Tbl4_Macro471:                   ;   WIN SOUND DMH
	DW           313
	DW           338
	DW           376
	DW    00          ;end
;
Tbl4_Macro472:
	DW    46
	DW    00          ;end
;
Tbl4_Macro473:                   ;   ME DONE   (DMH)
	DW           53
	DW           123
	DW    00           ;end
;
Tbl4_Macro474:                   ;   LISTEN ME    (DMH)
	DW    394
;;; page 194 end
;;; page 195 start XXX; FURBY27.INC page 70
	DW        53
	DW        00        ;end
;
Tbl4_Macro475:
	DW    411
	DW    00            ;end
;
Tbl4_Macro476:
	DW          399            ; delay
	DW        395            ; ME
	DW        186            ; NAME "LOO-LOO" DMH
	DW        00        ;end
;
Tbl4_Macro477:
	DW          399            ; delay
	DW          395            ; ME
	DW          194            ; NAME "AH-MAY" DMH
	DW    00         ;end
;
Tbl4_Macro478:
	DW           399            ; delay
	DW           395            ; ME
	DW           201            ; NAME "NOO-LOO" DMH
	DW    00         ;end
;
Tbl4_Macro479:
	DW           399            ; delay
	DW           395            ; ME
	DW           208            ;   ME "MAY-MAY" DMH
	DW        00     ;end
;
Tbl4_Macro480:
	DW           399            ; delay
	DW           395            ; ME
	DW           224            ; NAME "MAY-LAH" DMH
	DW    00         ;end
;
Tbl4_Macro481:
	DW           399            ; delay
	DW        395            ; ME
	DW        228            ; DAH-NOH-LAH
	DW        00     ;end
;
Tbl4_Macro482:
	DW           399            ; delay
	DW           395            ; ME
	DW           398            ; NAME "TOH-LOO-KAH" DMH
	DW           152
	DW        00     ;end
;
Tbl4_Macro483:
	DW          399          ;   delay
	DW          395          ;   ME
	DW          152          ;   KA-DA
	DW          166
	DW    00         ;end
;
Tbl4_Macro484:
	DW            399          ;   delay
	DW            395          ;   ME
;;; page 195 end
;;; page 196 start XXX; FURBY27.INC page 71
	DW        224       ; MAY-LAH-KA
	DW        152
	DW     00     ;end
;
Tbl4_Macro485:
	DW    4
	DW     00     ;end
;
Tbl4_Macro486:
	DW    4
	DW     00     ;end
;
Tbl4_Macro487:
	DW    4
	DW    00      ;end
;
Tbl4_Macro488:
	DW    4
	DW    00      ;end
;
Tbl4_Macro489:
	DW    4
	DW     00     ;end
;
Tbl4_Macro490:
	DW    4
	DW     00     ;end
;
Tbl4_Macro491:
	DW    4
	DW    00      ;end
;
Tbl4_Macro492:
	DW    4
	DW    00      ;end
;
Tbl4_Macro493:
	DW     4
	DW     00     ;end
;
Tbl4_Macro494:
	DW    4
	DW    00      ;end
;
Tbl4_Macro495:
	DW    4
	DW     00     ; end
;
Tbl4_Macro496:
	DW    4
	DW     00     ;end
;
Tbl4_Macro497:
	DW    4
	DW     00     ;end
;
Tbl4_Macro498:
	DW    4
	DW     00     ;end
;
;;; page 196 end
;;; page 197 start XXX; FURBY27.INC page 72
Tbl4_Macro499:
	DW    4
	DW    00   ;end
;
Tbl4_Macro500:
	DW    4
	DW    00   ;end
;
Tbl4_Macro501:
	DW    4
	DW    00   ;end
;
Tbl4_Macro502:
	DW    4
	DW    00   ;end
;
Tbl4_Macro503:
	DW    4
	DW    00   ;end
;
Tbl4_Macro504:
	DW    4
	DW    00   ;end
;
Tbl4_Macro505:
	DW    4
	DW    00   ;end
;
Tbl4_Macro506:
	DW    4
	DW    00   ;end
;
Tbl4_Macro507:
	DW    4
	DW    00   ;end
;
Tbl4_Macro508:
	DW    4
	DW    00   ;end
;
Tbl4_Macro509:
	DW    4
	DW    00   ;end
;
Tbl4_Macro510:
	DW    4
	DW    00   ;end
;
Tbl4_Macro511:
	DW    4
	DW    00   ;end
;



;***********************************************
;***********************************************
;***********************************************
;;; page 197 end
;;; page 198 start XXX; FURBY27.INC page 73
;
;
;***********************************************
;***********************************************
;***********************************************
;***********************************************
;***********************************************

;;;;;;;  SAYSENT pointer tables (128 max per table ---- 255 tables max)

Spch_grp1:

	DW      Tbl1_say000
	DW
Tbl1_say001,Tbl1_say002,Tbl1_say003,Tbl1_say004,Tbl1_say005
	DW
Tbl1_say006,Tbl1_say007,Tbl1_say008,Tbl1_say009,Tbl1_say010
	DW
Tbl1_say011,Tbl1_say012,Tbl1_say013,Tbl1_say014,Tbl1_say015
	DW
Tbl1_say016,Tbl1_say017,Tbl1_say018,Tbl1_say019,Tbl1_say020
	DW
Tbl1_say021,Tbl1_say022,Tbl1_say023,Tbl1_say024,Tbl1_say025
	DW
Tbl1_say026,Tbl1_say027,Tbl1_say026,Tbl1_say029,Tbl1_say030
	DW
Tbl1_say031,Tbl1_say032,Tbl1_say033,Tbl1_say034,Tbl1_say035
	DW
Tbl1_say036,Tbl1_say037,Tbl1_say038,Tbl1_say039,Tbl1_say040
	DW
Tbl1_say041,Tbl1_say042,Tbl1_say043,Tbl1_say044,Tbl1_say045
	DW
Tbl1_say046,Tbl1_say047,Tbl1_say048,Tbl1_say049,Tbl1_say050
	DW
Tbl1_say051,Tbl1_say052,Tbl1_say053,Tbl1_say054,Tbl1_say055
	DW
Tbl1_say056,Tbl1_say057,Tbl1_say058,Tbl1_say059,Tbl1_say060
	DW
Tbl1_say061,Tbl1_say062,Tbl1_say063,Tbl1_say064,Tbl1_say065
	DW
Tbl1_say066,Tbl1_say067,Tbl1_say068,Tbl1_say069,Tbl1_say070
	DW
Tbl1_say071,Tbl1_say072,Tbl1_say073,Tbl1_say074,Tbl1_say075
	DW
Tbl1_say076,Tbl1_say077,Tbl1_say078,Tbl1_say079,Tbl1_say080
	DW
Tbl1_say081,Tbl1_say082,Tbl1_say063,Tbl1_say084,Tbl1_say085
	DW
Tbl1_say086,Tbl1_say087,Tbl1_say088,Tbl1_say089,Tbl1_say090
	DW
Tbl1_say091,Tbl1_say092,Tbl1_say093,Tbl1_say094,Tbl1_say095
	DW      Tbl1_say096,Tbl1_say097,Tbl1_say098,Tbl1_say099
	DW
Tbl1_say100,Tbl1_say101,Tbl1_say102,Tbl1_say103,Tbl1_say104
	DW    Tbl1_say105,Tbl1_say106,Tbl1_say107,Tbl1_say108,Tbl1_say109
	DW    Tbl1_say110,Tbl1_say111,Tbl1_say112,Tbl1_say113,Tbl1_say114
	DW    Tbl1_say115,Tbl1_say116,Tbl1_say117,Tbl1_say118,Tbl1_say119
	DW    Tbl1_say120,Tbl1_say121,Tbl1_say122,Tbl1_say123,Tbl1_say124
	DW    Tbl1_say125,Tbl1_say126,Tbl1_say127
;;; page 198 end
;;; page 199 start XXX; FURBY27.INC page 74
;
Spch_grp2:

	DW      Tbl2_say128
	DW      Tbl2_say129,Tbl2_say130,Tbl2_say131,Tbl2_say132,Tbl2_say133
	DW      Tbl2_say134,Tbl2_say135,Tbl2_say136,Tbl2_say137,Tbl2_say138
	DW      Tbl2_say139,Tbl2_say140,Tbl2_say141,Tbl2_say142,Tbl2_say143
	DW      Tbl2_say144,Tbl2_say145,Tbl2_say146,Tbl2_say147,Tbl2_say143
	DW      Tbl2_say149,Tbl2_say150,Tbl2_say151,Tbl2_say152,Tbl2_say153
	DW      Tbl2_say154,Tbl2_say155,Tbl2_say156,Tbl2_say157,Tbl2_say158
	DW      Tbl2_say159,Tbl2_say160,Tbl2_say161,Tbl2_say162,Tbl2_say163
	DW      Tbl2_say164,Tbl2_say165,Tbl2_say166,Tbl2_say167,Tbl2_say168
	DW      Tbl2_say169,Tbl2_say170,Tbl2_say171,Tbl2_say172,Tbl2_say173
	DW      Tbl2_say174,Tbl2_say175,Tbl2_say176,Tbl2_say177,Tbl2_say178
	DW      Tbl2_say179,Tbl2_say180,Tbl2_say181,Tbl2_say182,Tbl2_say183
	DW      Tbl2_say184,Tbl2_say185,Tbl2_say186,Tbl2_say187,Tbl2_say188
	DW      Tbl2_say189,Tbl2_say190,Tbl2_say191,Tbl2_say192,Tbl2_say193
	DW      Tbl2_say194,Tbl2_say195,Tbl2_say196,Tbl2_say197,Tbl2_say198
	DW      Tbl2_say199,Tbl2_say200,Tbl2_say201,Tbl2_say202,Tbl2_say203
	DW      Tbl2_say204,Tbl2_say205,Tbl2_say206,Tbl2_say207,Tbl2_say208
	DW      Tbl2_say209,Tbl2_say210,Tbl2_say211,Tbl2_say212,Tbl2_say213
	DW      Tbl2_say214,Tbl2_say215,Tbl2_say216,Tbl2_say217,Tbl2_say218
	DW      Tbl2_say219,Tbl2_say220,Tbl2_say221,Tbl2_say222,Tbl2_say223
	DW      Tbl2_say224,Tbl2_say225,Tbl2_say226,Tbl2_say227,Tbl2_say228
	DW      Tbl2_say229,Tbl2_say230,Tbl2_say231,Tbl2_say232,Tbl2_say233
	DW      Tbl2_say234,Tbl2_say235,Tbl2_say236,Tbl2_say237,Tbl2_say238
	DW      Tbl2_say239,Tbl2_say240,Tbl2_say241,Tbl2_say242,Tbl2_say243
	DW      Tbl2_say244,Tbl2_say245,Tbl2_say246,Tbl2_say247,Tbl2_say248
	DW      Tbl2_say249,Tbl2_say250,Tbl2_say251,Tbl2_say252,Tbl2_say253
	DW      Tbl2_say254,Tbl2_say255
;
;
Spch_grp3:

	DW       Tbl3_say256
	DW      Tbl3_say257,Tbl3_say258,Tbl3_say259,Tbl3_say260,Tbl3_say261
	DW      Tbl3_say262,Tbl3_say263,Tbl3_say264,Tbl3_say265,Tbl3_say266
	DW      Tbl3_say267,Tbl3_say268,Tbl3_say269,Tbl3_say270,Tbl3_say271
	DW      Tbl3_say272,Tbl3_say273,Tbl3_say274,Tbl3_say275,Tbl3_say276
	DW      Tbl3_say277,Tbl3_say278,Tbl3_say279,Tbl3_say280,Tbl3_say281
	DW      Tbl3_say282,Tbl3_say283,Tbl3_say284,Tbl3_say285,Tbl3_say286
	DW      Tbl3_say287,Tbl3_say288,Tbl3_say289,Tbl3_say290,Tbl3_say291
	DW      Tbl3_say292,Tbl3_say293,Tbl3_say294,Tbl3_say295,Tbl3_say296
	DW      Tbl3_say297,Tbl3_say298,Tbl3_say299,Tbl3_say300,Tbl3_say301
	DW      Tbl3_say302,Tbl3_say303,Tbl3_say304,Tbl3_say305,Tbl3_say306
	DW      Tbl3_say307,Tbl3_say308,Tbl3_say309,Tbl3_say310,Tbl3_say311
	DW      Tbl3_say312,Tbl3_say313,Tbl3_say314,Tbl3_say315,Tbl3_say316
	DW      Tbl3_say317,Tbl3_say318,Tbl3_say319,Tbl3_say320,Tbl3_say321
	DW      Tbl3_say322,Tbl3_say323,Tbl3_say324,Tbl3_say325,Tbl3_say326
	DW      Tbl3_say327,Tbl3_say328,Tbl3_say329,Tbl3_say330,Tbl3_say331
	DW      Tbl3_say332,Tbl3_say333,Tbl3_say334,Tbl3_say335,Tbl3_say336
	DW      Tbl3_say337,Tbl3_say338,Tbl3_say339,Tbl3_say340,Tbl3_say341
	DW      Tbl3_say342,Tbl3_say343,Tbl3_say344,Tbl3_say345,Tbl3_say346
	DW      Tbl3_say347,Tbl3_say348,Tbl3_say349,Tbl3_say350,Tbl3_say351
	DW      Tbl3_say352,Tbl3_say353,Tbl3_say354,Tbl3_say355,Tbl3_say356
	DW      Tbl3_say357,Tbl3_say358,Tbl3_say359,Tbl3_say360,Tbl3_say361
	DW      Tbl3_say362,Tbl3_say363,Tbl3_say364,Tbl3_say365,Tbl3_say316
	DW      Tbl3_say367,Tbl3_say368,Tbl3_say369,Tbl3_say370,Tbl3_say371
	DW      Tbl3_say372,Tbl3_say373,Tbl3_say374,Tbl3_say375,Tbl3_say376
	DW      Tbl3_say377,Tbl3_say378,Tbl3_say379,Tbl3_say380,Tbl3_say381
;;; page 199 end
;;; page 200 start XXX; FURBY27.INC page 75
	DW    Tbl3_say382,Tbl3_say383
;
;
Spch_grp4:
	DW    Tbl4_say384
	DW    Tbl4_say385,Tbl4_say386,Tbl4_say387,Tbl4_say388,Tbl4_say389
	DW    Tbl4_say390,Tbl4_say391,Tbl4_say392,Tbl4_say393,Tbl4_say394
	DW    Tbl4_say395,Tbl4_say396,Tbl4_say397,Tbl4_say398,Tbl4_say399
	DW    Tbl4_say400,Tbl4_say401,Tbl4_say402,Tbl4_say403,Tbl4_say404
	DW    Tbl4_say405,Tbl4_say406,Tbl4_say407,Tbl4_say408,Tbl4_say409
	DW    Tbl4_say410,Tbl4_say411,Tbl4_say412,Tbl4_say413,Tbl4_say414
	DW    Tbl4_say415,Tbl4_say416,Tbl4_say417,Tbl4_say418,Tbl4_say419
	DW    Tbl4_say420,Tbl4_say421,Tbl4_say422,Tbl4_say423,Tbl4_say424
	DW    Tbl4_say425,Tbl4_say426,Tbl4_say427,Tbl4_say428,Tbl4_say429
	DW    Tbl4_say430,Tbl4_say431,Tbl4_say432,Tbl4_say433,Tbl4_say434
	DW    Tbl4_say435,Tbl4_say436,Tbl4_say437,Tbl4_say438,Tbl4_say439
	DW    Tbl4_say440,Tbl4_say441,Tbl4_say442,Tbl4_say443,Tbl4_say444
	DW    Tbl4_say445,Tbl4_say446,Tbl4_say447,Tbl4_say448,Tbl4_say449
	DW    Tbl4_say450,Tbl4_say451,Tbl4_say452,Tbl4_say453,Tbl4_say454
	DW    Tbl4_say455,Tbl4_say456,Tbl4_say457,Tbl4_say458,Tbl4_say459
	DW    Tbl4_say460,Tbl4_say461,Tbl4_say462,Tbl4_say463,Tbl4_say464
	DW    Tbl4_say465,Tbl4_say466,Tbl4_say467,Tbl4_say468,Tbl4_say469
	DW    Tbl4_say470,Tbl4_say471,Tbl4_say472,Tbl4_say473,Tbl4_say474
	DW    Tbl4_say475,Tbl4_say476,Tbl4_say477,Tbl4_say478,Tbl4_say479
	DW    Tbl4_say480,Tbl4_say481,Tbl4_say482,Tbl4_say483,Tbl4_say484
	DW    Tbl4_say485,Tbl4_say486,Tbl4_say487,Tbl4_say488,Tbl4_say489
	DW    Tbl4_say490,Tbl4_say491,Tbl4_say492,Tbl4_say493,Tbl4_say494
	DW    Tbl4_say495,Tbl4_say496,Tbl4_say497,Tbl4_say498,Tbl4_say499
	DW    Tbl4_say500,Tbl4_say501,Tbl4_say502,Tbl4_say503,Tbl4_say504
	DW    Tbl4_say505,Tbl4_say506,Tbl4_say507,Tbl4_say508,Tbl4_say509
	DW    Tbl4_say510,Tbl4_say511

;***********************************************************************
***
;***********************************************************************
***
;***********************************************************************
***
;***********************************************************************
***
;***********************************************************************
***

; ALL SPEECH SAYSENT START HERE ;;;;;;;;;
;; Saysent groups for Tbl 1


; The first line of each group is the speech speed command.
; This is a number from 40 - 55 where 46 is standard speed
;
;
; The next line is PITCH control which works as follows:
; Actual numeric value for TI pitch control

;  bit 7 set = subtract value from current course value
;        clr = add value to current course value
;  bit 6 set = select music pitch table
;        clr = select normal speech pitch table
;  bit 0-5 value to change course value (no change = 0)
;;; page 200 end
;;; page 201 start XXX; FURBY27.INC page 76
;         8Fh     ;hi voice (8f is very squeeeeeke) (8F= 143)
;         81h     ;one step higher than normal  use range 81-8F (129-143)
;         00      ;normal voice
;         01      ;one step lower than normal
;         2fh     ;lo voice ( very low)   use range 01-2F (01-47)
;

; A math routine in 'say_0’ converts the value for + or -
; if <80 then subtracts from 80 to get the minus version of 00
; ie. if number is 70 then TI gets 10 (which is -10)
; If number is 80 or > 80 then get sent literal as positive.

;   NOTE: MAX POSITIVE IS 8B
;         MAX NEGATIVE is 2F ( 80h - 2Fh or 51h)
;   8Bh is hi voice  (8f is very squeeeeeke)
;   2Fh lo voice ( very low)



;      When entering changes, ’Voice' holds the current pitch for Furby
;      and it is modified by adding or subtracting a pitch change :::

;       ex:   Voice+8      increases the pitch from the current voice by 8

;       ex:   Voice-10      decreases the pitch from the current voice by 10




;       The next group of entries are the speech words.
;       Th® last line is the terminator of ’FF’

;       (BOTTOM)
;
;  1 is very fast
;  46 is average
;  255 is very slow
;
;  DB     46         (speed of speech)
;  DB     123        (do sound 123)
;  DB     43         (do sound 43)
;  DB     FFH
;	PITCH PROGRAMMING RANGE:
;	Voice+8 (highest)
;	Voice-20 (lowest)
;;
Tbl1_say000:
	DB         46
	DB         Voice
	DB         163
	DB         FFH



;GEORGE 07/03/98
Tbl1_say001:                                                ;dON START   SEQ1 AGE1
	DB       46      ;speech speed
	DB       Voice+8
	DB       149,162,162,164,149      ;DONE 1FRONT SEQ1
	DB       FFH     ;end



Tbl1_say002:
;;; page 201 end
;;; page 202 start XXX; FURBY27.INC page 77
	DB      52         ;speech speed
	DB      Voice+8       ;system pitch setting
	DB      117,59                    ;DONE lFRONT SEQ2 age1
	DB      FFH        ; end
;
Tbl1_say003:
	DB      46         ;speech speed
	DB      Voice-4     ;system pitch setting
	DB      118                ;lfront seq3 - seq4-partl-SEQ7PART2
	DB      FFH        ; end
;
Tbl1_say004:
	DB      46         ;speech speed
	DB      Voice      ;system pitch setting
	DB      62,22,85                           ;lfront seq3 part2
	DB      FFH       ; end
;
Tbl1_say005:
	DB      50         ;speech speed
	DB      Voice+8       ;system pitch setting
	DB      58,39           ;lfront seq4 part 2
	DB      FFH        ; end
;
Tbl1_say006:
	DB      46       ;speech speed
	DB      Voice    ;pitch control
	DB      162,162,99,117    ;seq5 age1 front part of seq6
	DB      FFH        ; end
;
Tbl1_say007:
	DB       55          ;speech speed
	DB      Voice+8     ;system pitch setting
	DB      156          ;seq6 age1 front back part
	DB      FFH          ; end
;
Tbl1_say008:
	DB      46        ;speech speed
	DB     Voice   ;pitch control
	DB     162,162,99,10,39           ;SEQ7 FRONT AGE1 ADD SAY 003
	DB      FFH       ; end
;
Tbl1_say009:
	DB      46       ;speech speed
	DB       Voice   ;system pitch setting
	DB      99,99,145      ;SEQ8 FRONT AGEl
	DB      FFH     ; end
;
Tbl1_say010:
	DB      46         ;speech speed
	DB      Voice      ;system pitch setting
	DB      98           ;seq9 FRONT AGE1
	DB      FFH        ; end
;
Tbl1_say011:
	DB       30    ;speech speed
	DB   Voice+8   ;system pitch setting
	DB     96,165,165,165,129,149               ;seq10 FRONT AGE1 ADD SAY20
	DB   FFH     ;end
;
Tbl1_say012:
;;; page 202 end
;;; page 203 start XXX; FURBY27.INC page 78
	DB      50      ;speech speed
	DB      Voice   ;system pitch   setting
	DB      136,165,162,45            ;  seq11 FRONT AGE1 ADD SAY20
	DB      FFH     ; end
;
Tbl1_say013:
	DB      58       ;speech speed
	DB      Voice    ;system pitch setting
	DB      138,136,117            ;seq12 FRONT AGE1 ADD SAY20 ON FRONTPART
	DB      FFH      ;end
;
Tbl1_say014:
	DB      60        ;Speech speed
	DB      Voice+8     ;system pitch setting
	DB      145,162                                    ;seq13 FRONI AGE1 ADD SAY22
	DB      FFH       ; end
;
Tbl1_say015:
	DB      46       ;speech speed
	DB      Voice+8     ;system pitch setting
	DB      156                      ;seq14 FRONT AGE1
	DB      FFH       ; end
;
Tbl1_say016:
	DB      46        ;speech speed
	DB      Voice+7     ;system pitch setting
	DB      119,58                                ;seq15 FRONT AGE1
	DB      FFH       ; end
;
Tbl1_say017:
	DB      46        ;speech speed
	DB      Voice     ;system pitch setting
	DB      37        ;seql6 FRONT AGE1 BETWEEN 2(FAY20)ADDSAY37
	DB      FFH       ; end
;
Tbl1_say018:
	DB      46        ;speech speed
	DB      Voice     ;system pitch setting
	DB      123          ;SEQ16 FRONT AGE1
	DB      FFH       ; end
;
Tbl1_say019:
	DB      46        ;speech speed
	DB      Voice     ;system pitch setting
	DB      118            ;SEQ1 FRONT AGE2 REPEAT 22
	DB      FFH       ;end
;
Tbl1_say020:
	DB      46        ;speech speed
	DB      Voice+7      ;system pitch setting
	DB      77,35     ;SEQ2 FRONT ADD 20 TO FRONT
	DB      FFH       ;end
;
Tbl1_say021:
	DB      46        ;speech speed
	DB      Voice     ;system pitch setting
	DB       39,39          ; SEQ3AGE2 FRONT AID SEQ9AGE1
	DB      FFH       ;end
;;; page 203 end
;;; page 204 start XXX; FURBY27.INC page 79
;
Tbl1_say022:
	DB      56        ;speech speed
	DB      Voice+7   ;system pitch setting
	DB      156       ;SEQ4 AGE2 FRONT
	DB      FFH       ;end
;
Tbl1_say023:
	DB      46        ;speech speed
	DB      Voice+7   ;system pitch setting
	DB      8,162,22  ;SEQ4 AGE2 FRONT
	DB      FFH       ;end
;
Tbl1_say024:
	DB      46        ;speech speed
	DB      Voice+7   ;system pitch setting
	DB      117,81,27 ;SEQ5 AGE2 FRONT
	DB      FFH       ;end
;
Tbl1_say025:
	DB      46       ;speech speed
	DB      Voice    ;system pitch setting
	DB      99,35,48,164,77        ; SEQ6 AGE2 FRONT
	DB      FFH      ;end
;
Tbl1_say026:
	DB      46        ;speech speed
	DB      Voice+8   ;system pitch setting
	DB      99        ;SEQ 7 AGE2 FRONT PART 1
	DB      FFH       ;end
;
Tbl1_say027:
	DB      46         ;speech speed
	DB      Voice+7    ;system pitch setting
	DB      60,39,117  ;SEQ 7 AGE2 FRONT PART 2
	DB      FFH        ;end
;
Tbl1_say028:
	DB      46        ;speech speed
	DB      Voice     ;system pitch setting
	DB      145       ;SEQ 8 AGE2 FRONT say45(2)+22
	DB      FFH       ;end
;
Tbl1_say029:
	DB      46        ;speech speed
	DB      Voice+5   ;system pitch setting
	DB      149,162,162,164,149    ;FRONT SEQ9 AGE2
	DB      FFH       ;end
;
Tbl1_say030:
	DB      60         ;speech speed
	DB      Voice+7    ;system pitch setting
	DB      96,163,163,129    ;SEQ10 FRONT AGE 2 ADD 48
	DB      FFH        ;end
;
Tbl1_say031:
	DB     60         ;speech speed
	DB     Voice+8    ;system pitch setting
	DB     39,63      ;SEQ11 FRONT AGE 2
	DB     FFH        ;end
;;; page 204 end
;;; page 205 start XXX; FURBY27.INC page 80
;
Tbl1_say032:
	DB             46        ;speech speed
	DB             Voice+7     ;system pitch setting
	DB             128,117         ;SEQ12 FRONT AGE 2 ADD 20
	DB             FFH       ;end
;
Tbl1_say033:
	DB             56      ;speech speed
	DB             Voice+7    ;system pitch setting
	DB             99,55,162,28  ;SEQ14 FRONT AGE2
	DB             FFH     ;end
;
Tbl1_say034:
	DB             46        ;speech speed
	DB             Voice+6     ;system pitch setting
	DB             136,34               ;SEQ15 FRONT AGE2 ADD 20
	DB       FFH       ;end
;
Tbl1_say035:
	DB             56      ;speech speed
	DB             Voice+6   ;system pitch setting
	DB     35,162,48,162,93,133    ;SEQ16 FRONT AGE2 ADD20 TO BEGGINING
	DB       FFH       ;end
;
Tbl1_say036:
	DB             50        ;speech speed
	DB             Voice+3     ;system pitch setting
	DB             162,1          ;SEQl FRONT AGE3 ADD 20
	DB             FFH       ;end
;
Tbl1_say037:
	DB             46        ;speech speed
	DB             Voice    ;system pitch setting
	DB             81,77,52       ;SEQ2 FRONT AGE3
	DB             FFH      ; end
;
Tbl1_say038:
	DB             46        ;speech speed
	DB             Voice+8     ;system pitch setting
	DB             1,1                 ;SEQ3 FRONT AGE3 ADD29
	DB             FFH       ; end

Tbl1_say039:
	DB             50      ;speech speed
	DB      Voice+6   ;system pitch setting
	DB      162,14,27            ;SEQ4 FRONT A3E4 ADD41
	DB      FFH       ;end
;

;ERROR
;Tbl1_say040:
;	DB      46        ;speech speed
;	DB      Voice     ;system pitch setting
;	DB
;	DB      FFH       ;end

;
;;; page 205 end
;;; page 206 start XXX; FURBY27.INC page 81
Tbl1_say040:
	DB         46         ;speech speed
	DB         Voice   ;system pitch setting
	DB         99,35,47,58        ;SEQ6 FRONT AGE3
	DB         FFH     ;end
;
Tbl1_say041:
	DB          46      ;speech speed
	DB           Voice   ;system pitch setting
	DB         99,60,77,23     ;SEQ7 FRONT AGE3 ADD 22
	DB         FFH     ;end
;
Tbl1_say042:
	DB         46         ;speech speed
	DB         Voice      ;system pitch setting
	DB         99,145        ;SEQ8 FRONT AGE3 ADD 22
	DB         FFH        ;end
;
;ERROR
;Tbl1_say044:
;	DB          46      ;speech speed
;	DB          Voice   ;system pitch setting
;	DB          4  GO TO 22
;	DB          FFH     ;end



;
Tbl1_say043:
	DB   30         ;speech speed
	DB   Voice+8      ;system pitch setting
	DB        96,165,165,165,129,149           ;seql0 FRONT AGE3 ADD SAY20
	DB   FFH        ;end
;
Tbl1_say044:
	DB          50         ;speech speed
	DB          Voice+4       ;system pitch setting
	DB          145           ;SEQ11 FRONT AGE3
	DB          FFH        ;end
;
Tbl1_say045:
	DB          46         ;speech speed
	DB          Voice      ;system pitch setting
	DB          119,77     ;SEQ12 FRONT AGE3  (HEEY,TICKLE ME)     ADD20
	DB          FFH        ; end
;
Tbl1_say046:
	DB         46         ;speech speed
	DB         Voice      ;system pitch setting
	DB         128           ;SEQ13 fRONT AGE3 (NANNY,NANNY)   ADD20
	DB         FFH        ;end
;
Tbl1_say047:
	DB         46         ;speech speed
	DB         Voice      ;system pitch setting
	DB         136,117     ;SEQ13   fRONT AGE3 (RASBERRY+ hE HE HE )   ADD20
	DB         FFH        ;end
;
Tbl1_say048:
	DB         46         ;speech speed
;;; page 206 end
;;; page 207 start XXX; FURBY27.INC page 82
	DB       Voice    ;system pitch setting
	DB       35,162,47        ;SEQ16 kAH LOVE FRONT AGE3 ADD 20
	DB       FFH        ;end
;
Tbl1_say049:
	DB       56      ;speech speed
	DB       Voice+6   ;system pitch setting
	DB       81,133     ;SEQ16 (U-NYE QUICK KISS) FRONT AGE3 ADD20
	DB       FFH     ;end
;
Tbl1_say050:
	DB       46      ;speech speed
	DB       Voice   ;system pitch setting
	DB       77     ; SEQ2 (TICKLE) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say051:
	DB       46      ;speech speed
	DB       Voice+6   ;system pitch setting
	DB       1       ;SEQ2 (AGAIN) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say052:
	DB       46      ;speech speed
	DB       Voice   ;system pitch setting
	DB       93      ;SEQ3 (YOU) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say053:
	DB       46      ;speech speed
	DB       Voice   ;system pitch setting
	DB       52       ;SEQ3 (ME) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say054:
	DB       46      ;speech speed
	DB       Voice   ;system pitch setting
	DB       47      ;SEQ4 (LOVE) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say055:
	DB       46      ;speech speed
	DB       Voice+8   ;system pitch setting
	DB       117       ;SEQ5 (HE HE HE) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say056:
	DB       46      ;speech speed
	DB       Voice   ; system pitch setting
	DB       8,27        ;SEQ5 (BIG FUN) FRONT AGE4 ADD26
	DB       FFH     ;end
;
Tbl1_say057:
	DB       46      ;speech speed
	DB       Voice   ;system pitch setting
	DB       60       ;SEQ6 (NO) FRONT AGE4
	DB       FFH     ;end
;
Tbl1_say058:
	DB       46      ;speech speed
;;; page 207 end
;;; page 208 start XXX; FURBY27.INC page 83
	DB             Voice        ;system pitch setting
	DB             68           ;SEQ8 (PLEASE) FRONT AGE4
	DB             FFH          ;end
;
Tbl1_say059:
	DB             46           ;speech speed
	DB             Voice+8      ;system pitch setting
	DB             119          ;SE39 (HEEY) FRONT AGE4 ADD71
	DB             FFH          ;end
;
Tbl1_say060:
	DB             46           ;speech speed
	DB             Voice        ;system pitch setting
	DB             66           ;SEQ14 (PARTY) FRONT AGE4
	DB             FFH          ;end
;
Tbl1_say061:
	DB             46           ;speech speed
	DB             Voice        ;system pitch setting
	DB             108          ;SEQ15 (WA WA WA) fRONT AGE4 ADD 22
	DB             FFH          ;end
;END GEORGE 07/03/98
;
;GEORGE 07/04/98
;START SAY FORTUNE
Tbl1_say062:
	DB      46                                  ;speech speed
	DB      Voice-6                             ;system pitch setting
	DB      3                                   ;FORTUNE TELL (ASK)
	DB     FFH    ; end
;
Tbl1_say063:
	DB          46                            ;speech speed
	DB          Voice                         ;system pitch setting
	DB          92                            ;FORTUNE TELL (YES)
	DB         FFH        ; end
;
Tbl1_say064:
	DB            46                             ;speech spevd
	DB            Voice                          ;system pitch setting
	DB             8                             ;FORTUNE TELL (BIG)
	DB         FFH        ; end
;
Tbl1_say065:
	DB      46                                  ;speech speed
	DB      Voice+8                             ;system pitch setting
	DB      84,8                                ;FORTUNE TELL (VERY BIG)
	DB     FFH    ;end
;
Tbl1_say066:
	DB              100                           ;speech speed
	DB          Voice                         ;system pitch setting
	DB          162,70                        ;FORTUNE TELL (SEE YES)
	DB        FFH      ; end
;
Tbl1_say067:
	DB          0                             ;speech speed ****TODO: CHECK IF THIS MAKES SENSE??****
	DB          Voice-4                         ;system pitch setting
	DB       157,162,157                     ;Fortune tell (SLOW WHINE)
	DB        FFH   ; end
;;; page 208 end
;;; page 209 start XXX; FURBY27.INC page 84
;;; page 209 end
;
Tbl1_say068:
	DB       46                    ;speech speed
	DB       Voice                 ;system pitch setting
	DB       64                    ;FORTUNE TELL (02WHA)
	DB        FFH    ;end
;
Tbl1_say069:
	DB            46                  ;speech speed
	DB            Voice+5             ;system pitch setting
	DB            60                  ;FORTUNE TELL  (NO)
	DB            FFH          ;end
;
Tbl1_say070:
	DB          46                  ;speech speed
	DB          Voice+7             ;system pitch setting
	DB          90                  ;FORTUNE (WORRY)
	DB       FFH        ;end
;
Tbl1_say071:
	DB         46                  ;speech speed
	DB         Voice+7             ;system pitch setting
	DB         73                  ;FORTUNE (SOUND)
	DB        FFH        ; end
;
Tbl1_say072:
	DB          46                    ;speech speed
	DB       Voice                 ;system pitch setting
	DB       28                    ;FORTUNE (GOOD)
	DB        FFH    ; end
;
Tbl1_say073:
	DB        46                    ;speech speed
	DB        Voice                 ;system pitch setting
	DB        84                    ;FORTUNE (VERY)
	DB       FFH    ;end
;
Tbl1_say074:
	DB          50                    ;speech speed
	DB          Voice+8              ;system pitch setting
	DB          159                   ;FORTUNE (WHOOPEE)
	DB        FFH    ;end
;
Tbl1_say075:
	DB        46                    ;speech speed
	DB        Voice-5               ;system pitch setting
	DB         28                   ;FORTUNE (GOOD)
	DB       FFH    ;end
;
Tbl1_say076:
	DB         56                   ;speech speed
	DB         Voice+7             ;system pitch setting
	DB         136                 ;FORTUNE (RASPBERRY)
	DB        FFH     ; end
;
Tbl1_say077:
	DB           50                   ;speech speed
	DB           Voice               ;system pitch setting
	DB           129                 ;FORTUNE (oH oH)
	DB        FFH     ; end
;;; page 210 start XXX; FURBY27.INC page 85
Tbl1_say078:
	DB         50       ;speech speed
	DB         Voice+7  ;system pitch setting
	DB         49       ;FORTUNE (MAY BEE)
	DB        FFH        ;end

;END SAY FORTUNE
;END GEORGE 07/04/98

;START HANGOUT
;GEORGE 07/04/98
Tbl1_say079:
	DB      56                       ;speech speed
	DB      Voice+8                  ;system pitch setting
	DB      110                     ;SEQ1 HANGING (DE DE DE ,DUM   DUM DUM DUM) AGE1
	DB    FFH      ;end
;
Tbl1_say080:
	DB       60                     ;speech speed
	DB       Voice+8                ;system pitch setting
	DB       109               ;SEQ1 HANGING( DUM DUM DUM)     AGE1;  ADD 83
	DB        FFH    ;end
;
Tbl1_say081:
	DB            56           ;speech speed
	DB            Voice+8         ;system pitch setting
	DB            116          ;SEQ2 HANGING (BEEDO)
	DB        FFH        ;end
;
Tbl1_say082:
	DB      46                        ;speech speed
	DB      Voice+7                   ;system pitch setting
	DB      113                       ;SEQ3 HANGING (YA DA DA ) {yes, a colon - that's an error in the original thing!}
	DB     FFH    ;end
;
Tbl1_say083:
	DB            53                           ;speech speed
	DB            Voice+5                      ;system pitch setting
	DB            162,114,162,114              ;SEQ3 HANGING (OMPAH  bRUMM) {transcription note: see above}
	DB       FFH        ;end
;
Tbl1_say084:
	DB            46      ;speech speed
	DB            Voice+8 ;system pitch setting
	DB            115     ;SEQ3 HANGING (YA DA DA OMPAH          bRUMM BABABUM) {transcription note: see above}
	DB       FFH        ;end
;
Tbl1_say085:
	DB            60      ;speech speed
	DB            Voice+5 ;system pitch setting
	DB            126,163 ;SEQ4 HANGING (LA LA)
	DB       FFH        ;end
;
Tbl1_say086:
	DB            56           ;speech speed
	DB            Voice+5       ;system pitch setting
	DB            127          ;SEQ4 HANGING (LA LA)
	DB       FFH        ;end
;;; page 210 end
;;; page 211 start XXX; FURBY27.INC page 86
Tbl1_say087:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      101      ;SEQ5 HANGING (HUMMMMMM)
	DB          FFH     ;end
;
Tbl1_say088:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      11      ;SEQ5 HANGING (BO DAH WA LO)
	DB         FFH     ;end
;
Tbl1_say089:
	DB      46                   ;speech speed
	DB      Voice+7              ;system pitch setting
	DB      143,163              ;SEQ6 HANGING (SNORE)
	DB     FFH    ;end
;
Tbl1_say090:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      148     ;SEQ6 HANGING (SHOUT)
	DB         FFH     ;end
;
Tbl1_say091:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      63,35   ;SEQ6 HANGING (OK,KAH)
	DB         FFH      ;end
;
Tbl1_say092:
	DB     46       ;speech speed
	DB     Voice ;system pitch setting
	DB     82       ;SEQ6 HANGING (U-TYE)
	DB    FFH    ;end
;
Tbl1_say093:
	DB            60        ;speech speed
	DB            Voice+8     ;system pitch setting
	DB            144         ; SEQ7 HANGING (SOFTER)
	DB        FFH      ;end
;
Tbl1_say094:
	DB            46          ;speech speed
	DB            Voice-4       ;system pitch setting
	DB            144           ;SEQ7 HANGING (SOFTER)
	DB          FFH    ;end
;
Tbl1_say095:
	DB              46        ;speech speed
	DB              Voice     ;system pitch setting
	DB              124,162         ;SEQ8 hANGING (kITTY KITTY)
	DB         FFH     ;end
;
Tbl1_say096:
	DB          56
	DB          Voice     ;system pitch setting
	DB          112       ;SEQ9 HANGING (DO BE DOBE DO)
	DB         FFH      ;end
;;; page 211 end
;;; page 212 start XXX; FURBY27.INC page 87
;
Tbl1_say097:
	DB      60      ;speech speed
	DB      Voice+7   ;system pitch setting
	DB      161,164,164,161   ;SEQ10 HANGING            (YAWN)
	DB     FFH    ;end
;
Tbl1_say098:
	DB      100                ;speech speed
	DB      Voice+6             ;system pitch setting
	DB      140                ;SEQ11 AND SEQ12 HANGING (SIGH)
	DB     FFH   iend
;
Tbl1_say099:
	DB      46                ;speech speed
	DB      Voice+8              ;system pitch sorting
	DB      100                  ; SEQ13 SEQ14 HANGING (HAA)
	DB     FFH    ; end
;
Tbl1_say100:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      119     ; SEC 14 HANGING (HEEY)
	DB     FFH    ;end
;
Tbl1_say101:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      132,165,132      ;SEQ16 HANGING (PHONE)   ADD20
	DB     FFH    ;end
;
Tbl1_say102:
	DB      46        ; speech speed
	DB     Voice ;system, pitch setting
	DB      165,165,165,165         ;SEQ16 HANGING (PAUSE)   ADD20
	DB     FFH        ;end
;
Tbl1_say103:
	DB      46            ;speech speed
	DB      Voice+5          ;system pitch setting
	DB      83            ;SEQ6 HANGING (UP)
	DB     FFH    ;end
;
Tbl1_say104:
	DB      46        ;speech speed
	DB     Voice ;system pitch setting
	DB      52        ;SEQ6 HANGING AGE3 (ME)
	DB     FFH    ;end
;
Tbl1_say105:
	DB      46        {speech speed
	DB     Voice ;system pitch setting
	DB      63        {SEQ6 HANGING AGE3 (OK)
	DB     FFH    ;end
;
Tbl1_say106:
	DB      46      .-speech speed
	DB     Voice ;system pitch setting
	DB      13          ;SEQ5 HANGING AGE3 AND 4
	DB     FFH       ;end
;
;;; page 212 end
;;; page 213 start XXX; FURBY27.INC page 88
;END HANGOUT
;
;
;
Tbl1_say107:
	DB            46             ;speech speed
	DB            Voice          ;system pitch setting
	DB       165,165        ;Fortune delay
	DB        FFH    ; end
;
;END GEORGE 07/04/98
;START FEED
;GEORGE 07/05/98

;----------------------------------------sTART fEED
;
; spch_grp2 was here
;; Saysent groups for Tbl 2


;STARTS AT 128
Tbl1_say108:
	DB      100       ;speech speed
	DB     Voice ;system pitch setting
	DB     166   ; SEQ1 FEED AGE1 (UUMMM)
	DB       FFH    ;end

;NOT USED
;Tbl2_say129:
;	DB         46      ;speech speed
;	DB         Voice+8   ;system pitch setting
;;	DB             ;SEQ1 FEED AGE1 (AY-TAY)
;	DB          FFH          ;end

Tbl1_say109:
	DB      100      ;speech speed
	DB     Voice ;system pitch setting
	DB      167,167      ;SEQ1 FEED AGE1             (AAAAH)
	DB       FFH        ; end
;
Tbl1_say110:
	DB      56                  ;speech speed
	DB      Voice+3               ;system pitch setting
	DB     39     ;SEQ2 FEED AGE1 IKOH-KOH)
	DB     FFH    ;end
;
Tbl1_say111:
	DB               56           ;speech speed
	DB               Voice+7        ;system pitch setting
	DB           55           ;SEQ2 FEED AGE1 (MEE HEE)
	DB       FFH        ;end
;
Tbl1_say112:
	DB      50      ;speech speed
	DB     Voice ;system pitch setting
	DB      25      ;SEQ2 FEED AGE1              (E-DAY)
	DB     FFH    ;end

;
;;; page 213 end
;;; page 214 start XXX; FURBY27.INC page 89
Tbl1_say113:
	DB      58      ;speech speed
	DB      Voice+7   ;system pitch setting
	DB    23    ;SEQ2 FEED AGE1 (DO MOH)
	DB    FFH   ;end
;
Tbl1_say114:
	DB      58      ;speech speed
	DB    Voice ;system pitch setting
	DB    79    ;TOH-DYE
	DB    FFH   ;end
;
Tbl1_say115:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB    97    ;BURP
	DB    FFH   ;end
;
Tbl1_say116:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB    140   ;SIGH
	DB    FFH   ; end
;
Tbl1_say117:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      10      ;BOO
	DB    FFH   ;end
;
Tbl1_say118:
	DB      46       ;speech speed
	DB    Voice ;system pitch setting
	DB    85    ;WAH
	DB    FFH   ;end
;
Tbl1_say119:
	DB      60       ;speech speed
	DB      Voice+8    ;system pitch setting
	DB      80      ;TOH-LOO
	DB    FFH   ;end
;
Tbl1_say120:
	DB      46       ;speech speed
	DB      Voice+8    ;system pitch setting
	DB      7
	DB    FFH   ;end
;
Tbl1_say121:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      33       ;SEQ1 FEED AGE2 HUNGRY
	DB    FFH    ;end
;
;143 SAME AS TBL1_SAY072
;Tbl2_say143:
;	DB      46       ;speech speed
;	DB      Voice    ;system pitch setting
;	DB      28       ;SEQ2 FEED AGE3 (GOOD)
;	DB      FFH      ; end
;;; page 214 end
;;; page 215 start XXX; FURBY27.INC page 90
;144 SAME AS TBL1_SAY058
;Tbl2_say144:
;	DB     46                  ;speech speed
;	DB     Voice+7                 ;system pitch setting
;	DB     68                  ;SEQ2 FEED AQE3 PLEASE
;	DB     FFH                 ; end
;;
Tbl1_say122:
	DB      46                ;speech speed
	DB      Voice-2              ;system pitch setting
	DB      43                  ;SEQ2 FEED AGE3 LIKE
	DB     FFH    ;end

;Tbl2_say118:
;	DB                60       ;speech speed
;	DB                Voice-8    ;system pitch setting
;	DB                161,164,161     ;SEQ10 HANGING (YAWN)
;	DB                FFH      ;end

;Tbl2_say119:
;	DB                60      ;speech speed
;	DB               55      ;speech speed
;	DB                Voice+3    ;system pitch setting
;	DB                165,165,144,165,144,165,144,165,144

;	DB           Voice      ;system pitch setting
;	DB           144
;	DB           FFH        ;end

Tbl1_say123:
	DB      46        ;speech speed
	DB     Voice ;system, pitch setting
	DB      20        ;seq4 feed done
	DB     FFH    ; end
;END GEORGE 07/05/98
;END FEED
;
;

; WAKE
;GEORGE 07/06/98



;START AT 2
Tbl1_say124:                         ;SG DONE
	DB      70                ;speech speed
	DB      Voice+6             ;pitch control
	DB      165,161
	DB     FFH    ;end
;PASS
Tbl1_say125:                       ;SG DONE
	DB             55        ;speech speed
	DB             Voice-2         ;pitch control
	DB          162,63,35
	DB         FFH     ; end
; PASS
Tbl1_say126:                         ;SG DONE
	DB               55        ;speech speed
	DB         Voice ;system pitch setting
;;; page 215 end
;;; page 216 start XXX; FURBY27.INC page 91
	DB             82
	DB           FFH         ; end
; PASS
Tbl1_say127:                           ;SG DONE
	DB          55       ;speech speed
	DB           Voice ;system pitch setting
	DB          164,83
	DB           FFH    ;end
;
Tbl2_say128:               ;SG DONE
	DB      55      ;speech speed
	DB     Voice ;system pitch setting
	DB             63,52
	DB           FFH      ;end

Tbl2_say129:                  ;SG DONE
	DB       40       ;speech speed
	DB      Voice ;system pitch setting
	DB       163,139
	DB      FFH    ; end
;TBL1_SAY55
;Tbl1_say8:                 ;SG DONE
;	DB       46        ;speech speed
;	DB       Voice+8       ;system pitch setting
;	DB       117
;	DB       FFH       ; end


Tbl2_say130:                               ; SG DONE
	DB      55                    ;speech speed
	DB      Voice-2               ;system pitch setting
	DB      63
	DB     FFH    ;end

Tbl2_say131:                       ;SG DONE
	DB             46        ;speech speed
	DB         Voice ;system pitch setting
	DB        86
	DB        FFH       ; end

Tbl2_say132:                ; SG DONE
	DB       46       ;speech speed
	DB      Voice ;system pitch setting
	DB       79
	DB      FFH    ; end
;TBL1_SAY123
;Tbl1_say12:                 ;SG DONE
;	DB       46        ;speech speed
;	DB       Voice     ;system pitch setting
;	DB               20
;	DB               FFH     ;end
;
Tbl2_say133:              ; SG DONE
	DB       46      ;speech speed
	DB      Voice ;system pitch setting
	DB           72
	DB           FFH         ;end

Tbl2_say134:                              ;SG DONE
	DB                55            ;speech speed
	DB                Voice+3       ;system pitch setting
;;; page 216 end
;;; page 217 start XXX; FURBY27.INC page 92
	DB      158
	DB    FFH   ;end
;
Tbl2_say135:              ;SG DONE
	DB       46      ;speech speed
	DB     Voice ;system pitch setting
	DB       35
	DB     FFH    ;end
;
Tbl2_say136:                 ;SG DONE
	DB       46         ;speech speed
	DB       Voice+5    ;system pitch setting
	DB       52
	DB       FFH        ;end
;
Tbl2_say137:               ;SG DONE
	DB       55       ;speech speed
	DB       Voice+8    ;system pitch setting
	DB       8
	DB     FFH  ;end
;
Tbl2_say138:               ;SG DONE
	DB       45       ;speech speed
	DB       Voice+8    ;system pitch setting
	DB       137,137,137,138
	DB     FFH    ;end
;
Tbl2_say139:              ;SG DONE
	DB       60      ;speech speed
	DB     Voice ;system pitch setting
	DB      149
	DB     FFH   ;end
;
Tbl2_say140:              ;SG DONE
	DB      40      ;speech speed
	DB      Voice-3   ;system pitch setting
	DB      16
	DB      FFH     ;end
;
Tbl2_say141:              ;SG DONE
	DB      20      ;speech speed
	DB      Voice+5   ;system pitch setting
	DB      161
	DB    FFH   ;end
;
Tbl2_say142:              ;SG DONE
	DB      46      ;speech speed
	DB      Voice-9   ;system pitch setting
	DB      74
	DB    FFH   ;end
;
Tbl2_say143:              ;SG DONE
	DB      80      ;speech speed
	DB      Voice+4   ;system pitch setting
	DB      82
	DB    FFH   ;end
;
Tbl2_say144:              ;SG DONE
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
;;; page 217 end
;;; page 218 start XXX; FURBY27.INC page 93
	DB          14
	DB         FFH        ;end
;
Tbl2_say145:               ;SG DONE
	DB      46       ;speech speed
	DB     Voice ;pitch control
	DB      6
	DB     FFH    ; end
;
Tbl2_say146:              ;SG DONE
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      83
	DB     FFH    ;end
;
Tbl2_say147:                        ;SG DONE
	DB        70      ;speech speed
	DB         Voice ;pitch control
	DB        76
	DB         FFH    ;end
;
Tbl2_say148:               ;SG DONE
	DB      60       ;speech speed
	DB     Voice ;system pitch setting
	DB      37
	DB     FFH    ; end
;TBL1_SAY53
;Tbl1_say29:                ;SG DONE
;	DB      46        ;speech speed
;	DB      Voice     ;system pitch setting
;	DB          52
;	DB          FFH          ;end
;
Tbl2_say149:                         ;SG DONE
	DB             30           ;speech speed
	DB             Voice-5   ;system pitch setting
	DB          47
	DB         FFH        ;end
;
Tbl2_say150:                         ;SG DONE
	DB      60                 ;speech speed
	DB      Voice-3              ;system pitch setting
	DB      81
	DB     FFH    ;end
;
Tbl2_say151:                         ;SG DONE
	DB             55           ;speech speed
	DB             Voice-7        ;system pitch setting
	DB          53
	DB         FFH        ;end
;
Tbl2_say152:                      ;SG DONE
	DB             40       ;speech speed
	DB             Voice-10     ;system pitch setting
	DB          35
	DB         FFH        ; end
;
Tbl2_say153:                     ;SG DONE
	DB             46       ;speech speed
	DB             Voice-10    ;system pitch setting
;;; page 218 end
;;; page 219 start XXX; FURBY27.INC page 94
	DB          39
	DB         FFH        ;end
;
Tbl2_say154:                     ;SG DONE
	DB             55      ;speech speed
	DB             Voice+3    ;system pitch setting
	DB             165,165,144,165,144,165,144,165,165,165,165,144
	DB         FFH        ;end
;
Tbl2_say155:              ;SG DONE
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB          72
	DB         FFH        ;end
;
Tbl2_say156:                          ;SG DONE
	DB             60            ;speech speed
	DB         Voice ;system pitch setting
	DB        1
	DB         FFH   ;end



;TBL1_SAY53
;Tbl1_say38:                          ;SG DONE
;	DB             46           ;speech speed
;	DB             Voice        ;system pitch setting
;	DB          52
;	DB          FFH           ;end
;END GEORGE 07/06/98
;END WAKE
;
;
;GEORGE 07/06/98
;HUNGER
Tbl2_say157:                           ;SG DONE  ;HUNGER
	DB       65                    ;speech speed
	DB       Voice+8               ;system pitch setting
	DB          68
	DB         FFH        ;end
;
Tbl2_say158:                ;SG DONE
	DB      75       ;speech speed
	DB     Voice ;system pitch setting
	DB          23
	DB         FFH        ;end
;
Tbl2_say159:                           ;SG DONE
	DB             40            ;speech speed
	DB             Voice-7           ;system pitch setting
	DB          7
	DB         FFH        ;end
;
Tbl2_say160:                         ;SG DONE
	DB            55            ;speech speed
	DB         Voice ;system pitch setting
	DB          33
	DB          FFH           ;end
;
Tbl2_say161:                           ;SG DONE
	DB             75            ;speech speed




A-219
;;; page 219 end
;;; page 220 start XXX; FURBY27.INC page 95
	DB        Voice ;system pitch setting
	DB       55
	DB        FFH    ;end

Tbl2_say162:               ;SG DONE
	DB      40       ;speech speed
	DB      Voice-15    ;system pitch setting
	DB      84
	DB     FFH    ;end

Tbl2_say163:                        ;SG DONE
	DB      65                ;speech speed
	DB      Voice+8              ;system pitch setting
	DB      157
	DB     FFH    ;end

Tbl2_say164:                         ;SG DONE
	DB           55            ;speech speed
	DB           Voice+6          ;system pitch setting
	DB       119
	DB        FFH    ;end

Tbl2_say165:                          ;SG DONE
	DB          65            ;speech speed
	DB          Voice+8           ;system pitch setting
	DB          85
	DB         FFH    ;end

Tbl2_say166:                     ;SG DONE
	DB       55       ;speech speed
	DB        Voice ;system pitch setting
	DB       14
	DB        FFH    ;end

Tbl2_say167:                ;SG DONE
	DB     40       ;speech speed
	DB    Voice ;system pitch setting
	DB     8
	DB    FFH    ;end

Tbl2_say168:                        ;SG DONE   ;SAME AS SAY135 WITH DIFFERENT MOTOR
POS.
	DB       46      ;speech speed
	DB        Voice ;system pitch setting
	DB         35
	DB        FFH        ;end
;END GEORGE 07/06/98
;END HUNGER


;
;
;GEORGE 07/07/98
;INVERT
;WAS68
Tbl2_say169:              ;SG DONE  ;INVERT
	DB     85      ;speech speed
	DB    Voice ;system pitch setting
	DB         36
	DB         FFH    ;end
;
;;; page 220 end
;;; page 221 start XXX; FURBY27.INC page 96
Tbl2_say170:              ;SG DONE
	DB       55      ;speech speed
	DB      Voice+8    ;system pitch setting
	DB      94
	DB     FFH    ;end
;
Tbl2_say171:                           ;SG DONE
	DB      70                   ;speech speed
	DB      Voice+8                 ;system pitch setting
	DB      158
	DB     FFH    ;end
;
Tbl2_say172:                              ;SG DONE
	DB              55            ;speech speed
	DB              Voice+8             ;system am pitch setting
	DB         148
	DB        FFH     ;end
;
Tbl2_say173:                              ;SG DONE
	DB              100               ;speech speed
	DB              Voice+8            ;system pitch netting
	DB         97
	DB        FFH        ;end
;
Tbl2_say174:                            ;SG DONE
	DB              50            ;speech speed
	DB              Voice+5          ;system pitch setting
	DB         8
	DB        FFH        ;end
;
Tbl2_say175:                     ;SG DONE
	DB              55   --  ;speech speed
	DB              Voice-5    ;system pitch setting
	DB         9
	DB        FFH        ;end
;
Tbl2_say176:                      ;SG DONE
	DB              50       ;speech speed
	DB              Voice-10     ;system pitch setting
	DB         54
	DB        FFH        ;end
;
Tbl2_say177:                     ;SG DONE
	DB              70      ;speech speed
	DB              Voice-6   ;system pitch setting
	DB         57
	DB        FFH        ;end
;
Tbl2_say178:               ;SG DONE
	DB      24     ;speech speed
	DB     Voice ;system pitch setting
	DB         24
	DB        FFH        ;end
;
Tbl2_say179:                               ;SG DONE
	DB              55                ;speech speed
	DB              Voice-5              ;system pitch setting
	DB         10
	DB        FFH        ;end
;
;;; page 221 end
;;; page 222 start XXX; FURBY27.INC page 97
Tbl2_say180:                         ;SG DONE
	DB           65              ;speech speed
	DB          Voice-5          ;system pitch setting
	DB          80
	DB         FFH    ;end
;
Tbl2_say181:                         ;SG DONE
	DB             55            ;speech speed
	DB          Voice-10        ;system pitch setting
	DB          60
	DB         FFH        ;end
;
Tbl2_say182:               ;SG DONE
	DB       55       ;speech speed
	DB      Voice-10     ;system pitch setting
	DB      43
	DB     FFH    ;end
;
Tbl2_say183:                          ;SG DONE
	DB      75                  ;speech speed
	DB      Voice-8                ;system pitch setting
	DB      90
	DB     FFH    ;end
;
Tbl2_say184:                          ;SG DONE
	DB      75                  ;speech speed
	DB      Voice-4                ;system pitch setting
	DB      29
	DB     FFH    ;end
;
Tbl2_say185:                           ;SG DONE
	DB             55            ;speech speed
	DB             Voice+5           ;system pitch setting
	DB             34
	DB             FFH           ;end
;
Tbl2_say186:                          ;SG DONE
	DB             65            ;speech speed
	DB             Voice+2          ;system pitch setting
	DB             45
	DB        FFH         ;end
;
Tbl2_say187:                        ;SG DONE
	DB       65                ;speech speed
	DB       Voice-7              ;system pitch   setting
	DB       39
	DB      FFH    ;end
;
Tbl2_say188:                         ;SG DONE
	DB          35           ;speech speed
	DB          Voice        ;system pitch setting
	DB            130
	DB     FFH            ;end
;Tbl2_say158:
;Tbl1_say88:                          ;SG DONE
;	DB               75         ;speech speed
;	DB               Voice     ;system pitch setting
;	DB               23
;	DB               FFH        ;end
;



A-222
;;; page 222 end
;;; page 223 start XXX; FURBY27.INC page 98
Tbl2_say189:              ;SG DONE
	DB      55      ;speech speed
	DB     Voice ;system pitch setting
	DB      1
	DB     FFH    ;end
;
Tbl2_say190:
	DB          100                      ;speech speed
	DB          Voice                    ;system pitch setting
	DB         97
	DB        FFH    ;end
;
Tbl2_say191:
	DB      100                         ;speech speed
	DB      Voice-10                    ;system pitch setting
	DB      97
	DB     FFH    ;end
;
Tbl2_say192:
	DB      100                         ;speech speed
	DB      Voice-20                    ;system pitch setting
	DB      97
	DB     FFH    ; end
;END GEORGE 07/07/98
;END INVERT

;start at 202
Tbl2_say193:          ;SG DONE   ;BACKSG
	DB            70       ;speech speed
	DB        Voice ;system pitch setting
	DB       153
	DB        FFH   ;end

Tbl2_say194:     ;SG DONE
	DB      75       ;speech speed
	DB     Voice ;system pitch setting
	DB         2
	DB         FFH          ;end

Tbl2_say195:     ;SG DONE
	DB      55       ;speech speed
	DB     Voice ;system pitch setting
	DB         39
	DB        FFH        ;end

Tbl2_say196:          ;SG DONE
	DB            65       ;speech speed
	DB            Voice+4    ;system pitch setting
	DB         67           ; PET
	DB        FFH        ; end

Tbl2_say197:          ;SG DONE
	DB            75       ;speech speed
	DB            Voice+5    ;system pitch setting
	DB         1
	DB        FFH        ; end

Tbl2_say198:          ;SG DONE
	DB            55       ;speech speed
	DB            Voice-10    ;system pitch setting
;;; page 223 end
;;; page 224 start XXX; FURBY27.INC page 99
	DB          146
	DB         FFH        ;end
;
Tbl2_say199:     ;SG DONE
	DB     55       ;speech speed
	DB     Voice+5    ;system pitch setting
	DB     35
	DB    FFH    ;end
;
Tbl2_say200:         ;SG DONE
	DB         80        ;speech speed
	DB         Voice-5     ;system pitch setting
	DB         55
	DB        FFH    ;end
;
Tbl2_say201:          ;SG DONE
	DB          70       ;speech speed
	DB          Voice-5     ;system pitch setting
	DB          62
	DB         FFH    ;end
;
Tbl2_say202          ;SG DONE
	DB          80        ;speech speed
	DB          Voice-5    ;system pitch setting
	DB          84
	DB         FFH    ;end
;
;Tbl2_say148
;
;Tbl2_say212:           ;SG DONE
;	DB             70        ;speech speed
;	DB             Voice-5       ;system pitch setting
;	DB             29
;	DB             FFH         ;end
;
Tbl2_say203:     ;SG DONE
	DB     70        ;speech speed
	DB    Voice    ;system pitch setting
	DB     37
	DB    FFH    ;end
;
Tbl2_say204:     ;SG DONE
	DB      55        ;speech speed
	DB     Voice ;system pitch setting
	DB      152
	DB     FFH    ;end
;
Tbl2_say205:           ;SG DONE
	DB         65      ;speech speed
	DB         Voice-5   ;system pitch setting
	DB         52
	DB        FFH        ;end
;
Tbl2_say206:           ;SG DONE
	DB            65       ;speech speed
	DB            Voice+2    ;system pitch setting
	DB            47
	DB     FFH          ;end
;
Tbl2_say207:           ;SG DONE
;;; page 224 end
;;; page 225 start XXX; FURBY27.INC page 100
	DB       65             ;speech speed
	DB       Voice-3          ;system pitch setting
	DB       81
	DB        FFH    ;end
;
Tbl2_say208:          ;SG DONE
	DB       70             ;speech speed
	DB       Voice+6         ; system pitch setting
	DB       48
	DB        FFH    ; end
;
Tbl2_say209:          ;SG DONE
	DB           70       ;speech speed
	DB           Voice+3   ; system pitch setting
	DB           161
	DB     FFH         ;end
;
Tbl2_say210:     ;SG DONE
	DB      55       ;speech speed
	DB     Voice ;system pitch setting
	DB         15
	DB        FFH        ;end
;
Tbl2_say211:          ;SG DONE
	DB           45       ;speech speed
	DB           Voice-10    ;system pitch setting
	DB           8
	DB     FFH         ; end
;
Tbl2_say212:          ;SG DONE
	DB            55       ;speech speed
	DB            Voice-10    ;system pitch setting
	DB         42
	DB        FFH        ;end
;
Tbl2_say213:          ;SG DONE
	DB            65        ;speech speed
	DB            Voice-15      ;system pitch setting
	DB            57
	DB            FFH       ;end
;
Tbl2_say214:     ;SG DONE
	DB      50       ;speech speed
	DB     Voice  ;system pitch setting
	DB      75
	DB     FFH    ;end
;
Tbl2_say215:     ;SG DONE
	DB      55       ;speech speed
	DB     Voice ;system pitch setting
	DB         101
	DB        FFH     ;end
;
Tbl2_say216:          ;SG DONE
	DB            70       ;speech speed
	DB            Voice-3    ;system pitch setting
	DB         49
	DB        FFH        ;end
;
Tbl2_say217:          ;SG DONE
;;; page 225 end
;;; page 226 start XXX; FURBY27.INC page 101
	DB         75          ;speech speed
	DB         Voice+5       ;system pitch setting
	DB         86
	DB        FFH     ;end
;
Tbl2_say218:     ;SG DONE
	DB      55       ;speech speed
	DB     Voice ;system pitch setting
	DB      72
	DB     FFH    ;end
;
Tbl2_say219:          ;SG DONE
	DB            55       ;speech speed
	DB       Voice+5         ;system pitch setting
	DB       150
	DB        FFH   ;end
;
Tbl2_say220:          ;SG DONE
	DB           55       ;speech speed
	DB           Voice+5    ;system pitch setting
	DB           151
	DB     FFH         ;end
;
Tbl2_say221:     ;SG DONE
	DB      55       ;speech speed
	DB     Voice ;system pitch setting
	DB      97
	DB     FFH    ;end
;
Tbl2_say222:          ;SG DONE
	DB            70       ;speech speed
	DB        Voice ;system pitch setting
	DB       165,149
	DB        FFH   ;end
;
Tbl2_say223:          ;SG DONE
	DB            55       ;speech speed
	DB            Voice    ;system pitch setting
	DB         129
	DB        FFH     ;end
;
Tbl2_say224:          ;SG DONE
	DB            75       ;speech spued
	DB            Voice-4    ;system pitch setting
	DB         50
	DB        FFH        ;end
;
Tbl2_say225:          ;SG DONE
	DB            55       ;speech speed
	DB            Voice+5    ;system pitch setting
	DB         32
	DB        FFH        ;end
;
Tbl2_say226:     ;SG DONE
	DB      55       ;speech speed
	DB      Voice+5    ;system pitch setting
	DB      165,140
	DB     FFH    ;end
;
Tbl2_say227:          ;SG DONE
;;; page 226 end
;;; page 227 start XXX; FURBY27.INC page 102
	DB       65      ;speech speed
	DB        Voice ;system pitch setting
	DB       144
	DB        FFH    ;end
;
Tbl2_say228:     ;SG DONE
	DB      85       ;speech speed
	DB     Voice ;system pitch setting
	DB      18
	DB     FFH    ;end
;
Tbl2_say229:     ;SG DONE
	DB     50       ;speech speed
	DB     Voice+8    ;system pitch setting
	DB     118
	DB    FFH    ; end
;
Tbl2_say230:     ;SG DONE
	DB      65        ;speech speed
	DB     Voice ;system pitch setting
	DB      66
	DB     FFH    ; end
;
Tbl2_say231:         ;SG DONE
	DB         70       ;speech speed
	DB         Voice+8    ;system pitch setting
	DB         87
	DB        FFH    ; end
;
Tbl2_say232:         ;SG DONE
	DB         60       ;speech speed
	DB         Voice+8    ;system pitch setting
	DB         71
	DB        FFH    ;end
;
Tbl2_say233:      ;SG DONE
	DB      55       ;speech speed
	DB    Voice ;system pitch setting
	DB      93
	DB    FFH    ;end
;
Tbl2_say234:                    ; SG DONE
	DB           46       ;speech speed
	DB           Voice-20     ;system pitch setting
	DB           161
	DB        FFH     ; end
;
Tbl2_say235:
	DB            70           ;speech speed
	DB            Voice        ;system pitch setting
	DB            81
	DB        FFH        ;end
;
Tbl2_say236:
	DB         70           ;speech speed
	DB         Voice        ;system pitch setting
	DB         93
	DB        FFH        ;end
;;; page 227 end
;;; page 228 start XXX; FURBY27.INC page 103
;SICK
;GEORGE 07/08/98
;start at 39
Tbl2_say237:                           ;SG DONE   ;SICK1
	DB      55                    ;speech speed
	DB      Voice+5               ;system pitch setting
	DB      165,141
	DB     FFH    ; end
;Tbl2_say135
;Tbl1_say40:                          ;SG DONE
;	DB           46              ;speech speed
;	DB           Voice           ;system pitch setting
;	DB           35
;	DB           FFH             ;end
;Tbl1_say117
;Tbl1_say41:                           ;SG DONE
;	DB           46              ;speech speed
;	DB           Voice           ;system pitch setting
;	DB           10
;	DB           FFH             ;end

Tbl2_say238:               ;SG DONE
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      40
	DB     FFH    ; end

Tbl2_say239:                            ; SG DONE
	DB      46                    ;speech speed
	DB      Voice-5                  ;system pitch setting
	DB      60
	DB     FFH    ; end

Tbl2_say240:                ; SG DONE
	DB      50       ;speech speed
	DB     Voice ;system pitch setting
	DB      30
	DB     FFH     end
;Tbl1_say53
;Tbl1_say45:                ;SG DONE
;	DB      46        ;speech speed
;	DB      Voice     ;system pitch setting
;	DB           52
;	DB           FFH             ; end
;
Tbl2_say241:                             ; SG DONE
	DB            70              ;speech speed
	DB            Voice-8           ;system pitch setting
	DB            17
	DB         FFH        ; end
;
Tbl2_say242:                      ;SG DONE
	DB            80       ;speech speed
	DB            Voice-10    ;system pitch setting
	DB            46
	DB         FFH        ; end
;
Tbl2_say243:                            ; SG DONE
	DB            55              ;speech speed
	DB            Voice-8            ;system pitch setting
;;; page 228 end
;;; page 229 start XXX; FURBY27.INC page 104
	DB      8
	DB    FFH   ;end
;
Tbl2_say244:             ;SG DONE
	DB      40      ;speech speed
	DB      Voice-8   ;system pitch setting
	DB      73
	DB    FFH   ;end
;
Tbl2_say245:             ;SG DONE
	DB      75      ;speech speed
	DB      Voice-5   ;system pitch setting
	DB      80
	DB    FFH   ;end
;Tbl2_say182
;Tbl1_say51:             ;SG DONE
;	DB      55      ;speech speed
;	DB      Voice-10   ;system pitch setting
;	DB      43
;	DB      FFH     ;end
;
Tbl2_say246:             ;SG DONE
	DB      70      ;speech speed
	DB   Voice ;system pitch setting
	DB      9
	DB   FFH   ;end
;
Tbl2_say247:             ;SG DONE
	DB      60      ;speech speed
	DB      Voice-12   ;system pitch setting
	DB      90,165
	DB      FFH     ;end
;
Tbl2_say248:             ;SG DONE
	DB      100      ;speech speed
	DB    Voice ;system pitch setting
	DB      140
	DB    FFH   ;end
;
Tbl2_say249:             ;SG DONE
	DB      40      ;speech speed
	DB      Voice-20   ;system pitch setting
	DB      162,129
	DB    FFH        z end
;
Tbl2_say250:              ;SG DONE
	DB      100      ;speech speed
	DB    Voice ;system pitch setting
	DB      142
	DB    FFH   ;end
;END GEORGE 07/08/98
;END SICK
;
;
;LIGHT
;GEORGE 07/08/98
;starts at 2
Tbl2_say251:
	DB       40    ;speech speed    DONE RB       BEGIN LIGHT D.(BRIGHTER)
;;; page 229 end
;;; page 230 start XXX; FURBY27.INC page 105
	DB         Voice ;pitch control
	DB        119,18
	DB        FFH     ;end
;
;Tbl1_say252:
;	DB            40            ;speech speed               DO NOT USE
;	DB                         ;pitch control                SEE SAY 15
;	DB            FFH           ;end

;
Tbl2_say252:
	DB      75                  ;speech speed      Done RB
	DB      Voice+5              ;system pitch setting
	DB      142
	DB     FFH    ;end
;
Tbl2_say253:
	DB          46      ;speech speed   done RB
	DB         Voice ;system pitch setting
	DB          158,165,165,14,6
	DB         FFH      ;end
;
Tbl2_say254:
	DB     46       ;speech speed  done RB
	DB    Voice ;system pitch setting
	DB     102,149
	DB         FFH      ;end

Tbl2_say255:
	DB              46      ;speech speed DONE RB
	DB              Voice+8   ;system pitch setting
	DB              119,35,164,5,81
	DB        FFH      ;end
;
Tbl3_say256:
	DB              46      ;speech speed  DONE RB
	DB              Voice-4   ;system pitch setting
	DB              148,163,145
	DB        FFH      ;end
;
Tbl3_say257:
	DB      46       ;speech speed        DONE RB
	DB     Voice ;system pitch setting
	DB      131,164,95,149,123
	DB        FFH         ;end
;
Tbl3_say258:
	DB              55           ;speech speed      SEQ 4, AGE 2 DONE RB
	DB          Voice-4   ;system pitch setting
	DB          158,163,8,6
	DB         FFH        ;end
;
Tbl3_say259:
	DB              45      ;speech speed SEQ 6, AGE 2   DONE RB
	DB              Voice+8    ;system pitch setting
	DB          119,35,70,81
	DB         FFH        ;end
;
Tbl3_say260:
	DB             46           ;speech speed       RB            DONE
;;; page 230 end
;;; page 231 start XXX; FURBY27.INC page 106
	DB           Voice+8       ;system pitch setting     SEQ 1,   AGE 3
	DB         119,66
	DB          FFH   ;end
;
Tbl3_say261:
	DB                 46           ;speech speed   SEQ 4, AGE 3    RB DONE
	DB                 Voice-3        ;system pitch setting
	DB           158,14,42
	DB          FFH   ;end
;
Tbl3_say262:
	DB                 46      ;speech speed      SEQ 6 AGE 3           RB DONE
	DB                 Voice-3   ;system pitch setting
	DB          119,35,5,93
	DB          FFH     ;end
;
Tbl3_say263:
	DB                 60           ;speech speed    SEQ 2, AGE 1      RB DONE
	DB                 Voice+8        ;system pitch setting
	DB          131,95,149
	DB         FFH     ;end
;
Tbl3_say264:
	DB                 46           ;speech speed            RB DONE
	DB                 Voice-4        ;system pitch setting
	DB         158,8,42
	DB         FFH     ;end
;
Tbl3_say265:               ;                                               RB DONE
	DB                 46      ;speech speed
	DB                 Voice-4    ;system pitch setting
	DB                 119,35,70,93
	DB    FFH   ;end
;END GEORGE 07/08/98
;END LIGHT
;DARK
;GEORGE 07/08/98

Tbl3_say266:
	DB                 52       ;speech speed           BEGIN LIGHT D. (DARKER)
	DB                 Voice +8   ;system pitch setting     SEQ 1 AGE 1 RB DONE
	DB         119,10,162,6
	DB         FFH        ;end
;
Tbl3_say267:
	DB                 46           ;speech speed         SEQ 2 AGE 1 DONE RB
	DB         Voice+8        ;system pitch setting
	DB         119,6,21
	DB        FFH        ; end
;
Tbl3_say268:
	DB             55      ;speech speed
	DB             Voice+8   ;system pitch setting SEQ 3 AGE 1 DONE RB
	DB             119,6,163,82,163,23
	DB         FFH        ;end
;
Tbl3_say269:
	DB             40           ;speech speed
	DB             Voice+8        ;system pitch setting SEQ 4 AGE 1 DONE RB
	DB         158,101,163,104
;;; page 231 end
;;; page 232 start XXX; FURBY27.INC page 107
	DB          FFH          ;               end

Tbl3_say270:
	DB             70      ;speech speed
	DB             Voice+8   ;system pitch setting
	DB             148,10,6,148
	DB         FFH     ; end

Tbl3_say271:
	DB             59      ;speech speed
	DB             Voice+4   ;system pitch setting
	DB             149,163,21,21   ;SEQ6 AGE4/SEQ14 AGE4 LIGHT js
	DB          FFH          ; end

Tbl3_say272:
	DB             52      ; speech speed
	DB             Voice+8    ;system pitch setting
	DB             119,35,162,10,5,81
	DB             FFH     ;end    DONE RB

Tbl3_say273:
	DB             60      ;speech speed
	DB             Voice+8   ;pitch control  DONE RB
	DB             63,163,149,163,163,51,35,152
	DB         FFH     ; end

Tbl3_say274:
	DB             52      ;speech speed
	DB             Voice+2   ;system pitch setting
	DB          119,60,6
	DB         FFH     ; end

Tbl3_say275:
	DB             52      ;speech speed
	DB             Voice+2    ;pitch control
	DB             119,60,45,85
	DB             FFH     ; end DONE RB

Tbl3_say276:
	DB             60               ;speech speed
	DB             Voice+2            ;system pitch setting    DONE RB
	DB        119,42,82,23
	DB         FFH   ;end

Tbl3_say277:
	DB             70      ;speech speed
	DB             Voice+2   ;system pitch setting
	DB             148,60,6,148
	DB          FFH              ;end   DONE RB

Tbl3_say278:
	DB             52      ;speech speed
	DB             Voice+2   ;system pitch setting            DONE RB
	DB             119,52,60,70,81
	DB        FFH         ;end

Tbl3_say279:
	DB      52      ;speech speed
	DB     Voice ;system pitch setting
	DB          119,10,42
;;; page 232 end
;;; page 233 start XXX; FURBY27.INC page 108
	DB           FFH        ;end    DONE RB
;
Tbl3_say280:
	DB      52       ;speech speed
	DB      Voice    ;system pitch setting DONE RB
	DB      119,10,34,85
	DB     FFH    ;end
;
Tbl3_say281:
	DB      60      ;speech speed
	DB     Voice ;system pitch setting
	DB      119,42,83,23
	DB      FFH     ;end   DONE RB
;
Tbl3_say282:
	DB      52       ;speech speed
	DB     Voice ;system pitch setting
	DB      119,52,60,5,93
	DB      FFH      ;end   DONE RB
;
Tbl3_say283:
	DB      60      ;speech speed   !!NOTE!!  PRINTED TA  K HAD WRONG WORD NUMBER FOR "KISS"
	DB     Voice ;system pitch setting
	DB      63,149,162,38,35,152
	DB      FFH     ;end   DONE RB
;
Tbl3_say284:
	DB      52      ;speech speed
	DB     Voice ;system pitch setting
	DB      119,60,42
	DB      FFH     ;end  DONE RB
;
Tbl3_say285:
	DB           52      ;speech speed
	DB           Voice-3    ;system pitch setting
	DB           119,60,34,85
	DB       FFH     ;end
;
Tbl3_say286:
	DB      60      ;speech speed
	DB     Voice ;system pitch setting
	DB      119,42,83,68
	DB       FFH     ;end
;
Tbl3_say287:
	DB      70      (speech speed
	DB     Voice ;system pitch setting
	DB      148,60,42,148
	DB       FFH     ;end
;
Tbl3_say288:
	DB      46       (speech speed
	DB     Voice ;system pitch setting
	DB      119,163.52,60,70,93      ;SEQ7 AGE4/SEQ15 AGE 4 LIGHT js
	DB       FFH     ;end
;
Tbl3_say289:
	DB      50      ;speech speed
	DB     Voice ;system pitch setting
;;; page 233 end
;;; page 234 start XXX; FURBY27.INC page 109
	DB         63,165,149,38,52,152           ; SEQS AGE4/SEQ16 AGE 4 LIGHT js
	DB        FFH     ; end

;END GEORGE 07/08/98
;END DARK
;SOUND
;
;start 43
Tbl3_say290:
	DB     50      ;speech speed
	DB    Voice ;system pitch setting
	DB     163,148,165,17          ;S1-A1/S9-A1/SI-A2 SOUND js
	DB     FFH     ; end           ; S9-A2/S1-A3/S9-A3 SOUND js
;
Tbl3_say291:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      85,165,165,165       ;S2-A1/S10-A1/S2-A1 SOUND js
	DB      165,165,140          ;S10-A2/S2-A3/S10-A3 SOUND js
	DB         FFH          ;end         ;S2-A4/S10-A4 SOUND js
;
Tbl3_say292:
	DB      50      ;speech speed
	DB     Voice ;system pitch setting
	DB      121,165,164,14,163,41,21                ;S3-A1/S11-A1 SOUND js
	DB        FFH        ;end
;
Tbl3_say293:
	DB      46       ;speech speed
	DB    Voice ;system pitch setting
	DB     163.125,164,5,162,41                   ;S4-A1/S12-A1 SOUND js
	DB     FFH    ;end
;
Tbl3_say294:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      35,163,89   ;S5-A1/S11 A1 SOUND              (with say/m2)        js
	DB        FFH        ; end
;
Tbl3_say295:
	DB            53           ;speech speed
	DB        Voice ;system pitch setting
	DB       163,148,163,36  ;S6-A1/S14-A1/S6-A2 SOUND js
	DB       FFH     ;end    ;S14-A2/S6-A3/S14-A3 SOUND js
;
Tbl3_say296:
	DB       53      ;speech speed
	DB        Voice ;system pitch setting
	DB       17      ;S7-A1/S15-A1 SOUND           (with say/m2)       js
	DB        FFH        ; end
;
Tbl3_say297:
	DB      60      ;speech speed
	DB     Voice ;system pitch setting
	DB      122,164,21,164,21    ;S8-A1/S16-A1 SOUND js
	DB      FFH     ;end         ;S8-A3/S16-A3 SOUND js
;
Tbl3_say298:
	DB            46           ;speech speed
	DB       Voice ;system pitch setting
;;; page 234 end
;;; page 235 start XXX; FURBY27.INC page 110
	DB         121,165,164,8,167,41,21  ; S3-A2/S11-A2 SOUND js
	DB        FFH     ;end
;
Tbl3_say299:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      163,129,164,5,165,73       ;S4-A2/S12-A2 SOUND js
	DB     FFH    ;end
;
Tbl3_say300:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      35,165,31       ;S5-A2/S13-A2/S5-A3 SOUND (with say/m2) js
	DB         FFH       ;end   ;S13-A3/S5-A4/S13-A4 SOUND (with say/m2) js
;
Tbl3_say301:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      8,162,41,163,85           ;S7-A2/S15-A2 SOUND    (with say/m2) js
	DB        FFH     ; end
;
Tbl3_say302:
	DB      60      ;speech speed
	DB     Voice ;system pitch setting
	DB      122,164,21       ;S8-A2/S16-A2 SOUND js
	DB        FFH     ;end
;
Tbl3_say303:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      121,165,164,14,163,73,21        ;S3-A3/S11-A3 SOUND js
	DB         FFH       ;end
;
Tbl3_say304:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      163,129,164,35,165,44              ;S4-A3/S12-A3 SOUND js
	DB      FFH     ;end                       ;S4-A4/S12-A4 SOUND js
;
Tbl3_say305:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      8,73,164,85           ;S7-A3/S15-A3 SOUND   (with say/m2)js
	DB      FFH     ;end          ;S7-A4/S15-A4 SOUND   (with say/m2)js
;
Tbl3_say306:
	DB      55      ;speech speed
	DB     Voice ;system pitch setting
	DB      164,148,164,163,46                 ;S1-A4/S9-A4 SOUND js
	DB        FFH     ;end
;
Tbl3_say307:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      121,165,164,8,163,73,21         ;S3-A4/S11-A4 SOUND js
	DB        FFH     ;end
;
;;; page 235 end
;;; page 236 start XXX; FURBY27.INC page 111
Tbl3_say308:
	DB      55      ;speech speed
	DB      Voice   ;system pitch setting
	DB      164,148,164,163,54       ;S6-A4/S14-A4 SOUND js
	DB      FFH        ; end
;
Tbl3_say309:
	DB      60      ;speech speed
	DB      Voice   ;system pitch setting
	DB      122,164,163,88,164,21    ;S8-A4/S16-A4 SOUND js
	DB      FFH        ;end
;
;
;END SOUND
;
;TILT
;GEORGE 07/09/98
Tbl3_say310:
	DB      56       ;speech speed
	DB      Voice+8  ;pitch control
	DB      160      ;S1 A1 TILT/S4 A1 TILT/S14 A1 TILT js
	DB      FFH      ;end
;
Tbl3_say311:
	DB      46       ;speech speed
	DB      Voice    ;pitch control
	DB      157,36   ;S2 A1 TILT js
	DB      FFH      ;end
;
Tbl3_say312:
	DB      46       ;speech speed
	DB      Voice    ;system pitch setting
	DB      158,9    ;S3 A1 TILT js
	DB      FFH      ;end
;
Tbl3_say313:
	DB      46       ;speech speed
	DB      Voice+8  ;system pitch setting
	DB      154      ;S5 A1/S4 A2/S2 A3/S2 A4 TILT js
	DB      FFH      ;end
;
Tbl3_say314:
	DB      46       ;speech speed
	DB      Voice    ;system pitch setting
	DB      159,82,39 ;S6 A1 TILT js
	DB      FFH      ;end
;
Tbl3_say315:
	DB      46       ;speech speed
	DB      Voice    ;system pitch setting
	DB      155,39,39  ;S7 A1 TILT/S6 A2 TILT ja
	DB      FFH      ;end
;
Tbl3_say316:
	DB      46       ;speech speed
	DB      Voice    ;system pitch setting
	DB      37,152   ;S8 A1 TILT (with say/m5) js
	DB      FFH      ;end
;
Tbl3_say317:
;;; page 236 end
;;; page 237 start XXX; FURBY27.INC page 112
	DB            46           ;speech speed
	DB           Voice ;system pitch setting
	DB          154,120              ;S9 A1 TILT/S9 A2 TILT js
	DB           FFH        ; end
;
Tbl3_say318:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      155,120,120     ;S10 A1 TILT/S10 A2 TILT js
	DB           FFH        ;end
;
Tbl3_say319:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      35,57           ;S11 A1 TILT          (with say/m2)   js
	DB           FFH        ;end
;
Tbl3_say320:
	DB      48      ;speech speed
	DB     Voice ;system pitch setting
	DB      158,10,80       ;S12 A1 TILT js
	DB           FFH        ;end
;
Tbl3_say321:
	DB               46           ;speech speed
	DB           Voice ;system pitch setting
	DB       119,160              ;S13 A1   / S15 A3 TILT js
	DB        FFH        ; end
;
Tbl3_say322:
	DB               46           ;speech speed
	DB        Voice ;system pitch setting
	DB       160,9                ;S15 A1 TILT js
	DB        FFH        ;end
;
Tbl3_say323:
	DB           46           ;speech speed
	DB        Voice ;system pitch setting
	DB       154,149     ;S16 A1 / S15 A2    / S13 A3 TILT js
	DB        FFH        ;end
;
Tbl3_say324:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      160             ;S1 A2/S3 A2/S1 A3/S1 A4 TILT js
	DB        FFH        ;end
;
Tbl3_say325:
	DB               46           ;speech speed
	DB        Voice ;system pitch setting
	DB       52,9            ;S2 A1 TILT    (with say/m16)   js
	DB        FFH         ;end
;
Tbl3_say326:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB     159,83,39       ;S5 A2 TILT js
	DB        FFH         ;end
;
Tbl3_say327:
;;; page 237 end
;;; page 238 start XXX; FURBY27.INC page 113
	DB        46      ;speech speed
	DB         Voice ;system pitch setting
	DB        52,48,81,152         ;S7 A2 TILT      (with say/m5)      js
	DB         FFH     ; end
;
Tbl3_say328:
	DB        46      ;speech speed
	DB         Voice ;system pitch setting
	DB        155             ;S8 A2 TILT        (with say/m5)    js
	DB         FFH     ; end
;
Tbl3_say329:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      52,57            ;S11 A2 TILT           (with say/m2)    js
	DB         FFH     ; end
;
Tbl3_say330:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      158,60,80       ;S12 A2 TILT js
	DB     FFH    ;end
;
Tbl3_say331:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      163,156              ;S13 A2            TILT   (with say/m5)       js
	DB         FFH         ; end
;
Tbl3_say332:
	DB              46           ;speech speed
	DB         Voice ;system pitch setting
	DB        8,22,85         ;S14 A2 TILT js
	DB         FFH         ;end
;
Tbl3_say333:
	DB              46           ;speech speed
	DB         Voice ;pitch control
	DB        154,118,163,145,165,162,118            ;S16 A2/S14 A3/S14 A4 TILT js
	DB         FFH         ; end
;
Tbl3_say334:
	DB              46           ;speech speed
	DB         Voice ;system pitch setting
	DB       159                              ;S3 A3 TILT js
	DB         FFH         ;end
;
Tbl3_say335:
	DB              46           ;speech speed
	DB         Voice ;pitch control
	DB       83,1                      ;S4 A3/S4 A4 TILT   (with say/m26)        js
	DB         FFH        ; end
;
Tbl3_say336:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      155,52,62,85                        ;S5 A3 TILT js
	DB         FFH        ;end
;
;;; page 238 end
;;; page 239 start XXX; FURBY27.INC page 114
Tbl3_say337:
	DB      50      ;speech speed
	DB    Voice ;system pitch setting
	DB      52,48,93,152        ;S6 A3 TILT (with say/m5) js
	DB    FFH   ;end
;
Tbl3_say338:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      155             ;S7 A3/S7 A4 TILT (with say/m5) js
	DB    FFH   ;end
;
Tbl3_say339:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      155,120,163,149     ;S8 A3/S8 A4 TILT js
	DB    FFH   ;end
;
Tbl3_say340:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      165,129         ;S9 A3/S9 A4 TILT (with say/m9) js
	DB    FFH   ;end
;
Tbl3_say341:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      160,163,120,120     ;S10 A3/S10 A4 TILT (with say/m16)js
	DB    FFH   ;end
;
Tbl3_say342:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      163,23          ;S11 A3/S15 A4 TILT (with say/m2&21) js
	DB    FFH   ;end
;
Tbl3_say343:
	DB      55      ;speech speed
	DB    Voice ;system pitch setting
	DB      164,156             ;S12 A3 TILT (with say/m5) js
	DB    FFH   ;end
;
Tbl3_say344:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB      163,1,163,1,117     ;S16 A3 TILT (with say/m5) js
	DB    FFH   ;end
;
Tbl3_say345:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB       27,162,149         ;S3 A4 TILT (with say/m26) js
	DB    FFH   ;end
;
Tbl3_say346:
	DB      46      ;speech speed
	DB    Voice ;system pitch setting
	DB       155,52,29,163,85      ;S5 A4 TILT js
	DB    FFH   ;end
;
;;; page 239 end
;;; page 240 start XXX; FURBY27.INC page 115
Tbl3_say347:
	DB       46       ;speech speed
	DB        Voice ;system pitch setting
	DB       52,47,93,164,152        ;S6 A4 TILT          (with say/m5)     js
	DB        FFH    ;end
;
Tbl3_say348:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      52,24,68                ;S11 A4 TILT             (with say/m2)    js
	DB        FFH         ;end
;
Tbl3_say349:
	DB             46          ;speech speed
	DB        Voice ;system pitch setting
	DB       22,149          ;S13 A4 TILT         (with say/m5)     js
	DB        FFH         ;end
;
Tbl3_say350:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      163,1,163,39,163,117                 ;S16 A4 TILT      (with say/m5)    js
	DB        FFH         ;end

;END GEORGE 07/09/98
;
;GEORGE
;IR 07/09/98
Tbl3_say351:
	DB             46          ;speech speed
	DB             Voice+8       ;pitch control
	DB             40             ;SEQ1,seq2,seq3,seq4   ir age 1
	DB        FFH         ;end
;
Tbl3_say352:
	DB             46      ;speech speed
	DB             Voice      ;pitch control
	DB             66,162,85     ;seq5, ir age 1
	DB        FFH         ;end
;
Tbl3_say353:
	DB      46      ;speech speed
	DB     Voice ;system pitch setting
	DB      19,85   ;seq6, ir age1                      DANCE WAH
	DB       FFH         ;end
;
Tbl3_say354:
	DB             46      ;speech speed
	DB             Voice+8    ;system pitch setting
	DB             162,164,134,134   ;seq6, ir age1 DO DO DO
	DB       FFH         ;end
;
Tbl3_say355:
	DB            46      ;speech speed
	DB            Voice+2   ;system pitch setting
	DB            134,134,25,19   ;seq7 ir age1
	DB        FFH        ;end
;
Tbl3_say356:
	DB            50           ;speech speed
;;; page 240 end
;;; page 241 start XXX; FURBY27.INC page 116
	DB             Voice+8        ;system pitch setting
	DB             162
	DB             FFH          ;end            EMPTY SPACE
;
Tbl3_say357:
	DB             42      ;speech speed
	DB             Voice   ;system pitch setting
	DB             102,97,118,34       ;seq8 ir age1
	DB        FFH     ;end
;
Tbl3_say358:
	DB      50      ;speech speed
	DB     Voice ;system pitch setting
	DB      117,34,22       ;seq9 ir age1
	DB     FFH    ;end
;
Tbl3_say359:
	DB      50       ;speech speed
	DB     Voice ;system pitch setting
	DB      34,78,145,145    ;seq10,11             ir age1
	DB        FFH        ;end
;
Tbl3_say360:
	DB      50      ;speech speed
	DB     Voice ;system pitch setting
	DB      150,151,93,71   ;seq12 ir age1 TWINKLE
	DB        FFH        ;end
;
Tbl3_say361:
	DB             46           ;speech speed
	DB        Voice ;system pitch setting
	DB       91,31,165,165,165,165,165,165,128,31       ;seq13,14 ir age1
	DB        FFH        ;end
;
Tbl3_say362:
	DB      46       ;speech speed
	DB     Voice ;system pitch setting
	DB      161,72,161       ;seq15 ir age1
	DB        FFH        ;end
;
Tbl3_say363:
	DB       60       ;speech speed
	DB      Voice ;system pitch setting
	DB       144,144,144,144                             ;seq16 ir age1
	DB        FFH        ;end
;
Tbl3_say364:
	DB             46           ;speech speed
	DB             Voice+5        ;system pitch setting
	DB         81,40        ;seql,2,3 ir age2
	DB        FFH        ;end
;
Tbl3_say365:
	DB             46           ;speech speed
	DB             Voice+8        ;system pitch setting
	DB             81,40         ;seq4,5 ir age2
	DB        FFH        ;end
;
Tbl3_say366:
;;; page 241 end
;;; page 242 start XXX; FURBY27.INC page 117
	DB        46             ;speech speed
	DB        Voice+8          ;system pitch setting
	DB        66,159         ;seq6 ir age2
	DB         FFH    ;end
;
Tbl3_say367:
	DB          46      ;speech speed
	DB          Voice+7   ;system pitch setting
	DB          19,165,165,165,164,85,134,165,135                  ;seq7,8 ir age2
	DB         FFH     ;end
;
Tbl3_say368:
	DB      46       ;speech speed
	DB      Voice+3   ;system pitch setting
	DB      118,25,34                                              ;seq9 ir age2
	DB     FFH    ; end
;
Tbl3_say369:
	DB      51       ;speech speed
	DB      Voice+8    ;system pitch setting
	DB      102,97,118               ;seq10 ir age2
	DB     FFH    ; end
;
Tbl3_say370:
	DB      46      ;speech speed
	DB      Voice+5   ;system pitch setting
	DB      117,34,22               ;SEQ11 ir age2
	DB     FFH    ;end
;
Tbl3_say371:
	DB       48      ;speech speed
	DB        Voice ;system pitch setting
	DB       91,31,165,165,165,165,165,165,124,31             ;seq13,14 ir age2
	DB        FFH        ;end
;
Tbl3_say372:
	DB         55           ;speech cpeed
	DB        Voice ;system pitch setting
	DB       161,72,161                                      ;seq15 ir age2
	DB        FFH        ; end
;
Tbl3_say373:
	DB      50       ;speech speed
	DB     Voice ;system pitch setting
	DB      143,144,143                                     ;seq16 ir age2
	DB     FFH    ; end
;
Tbl3_say374:
	DB      50      ;speech speed
	DB     Voice ;pitch control
	DB      14,40            ;seq1,2,3,4,5 ir age3
	DB        FFH        ;end
;
Tbl3_say375:
	DB      46       ;speech speed
	DB      Voice+5    ;system pitch setting
	DB      35,48,66          ;seq6 ir age3
	DB     FFH    ; end
;;; page 242 end
;;; page 243 start XXX; FURBY27.INC page 118
;
Tbl3_say376:
	DB          50       ; speech speed
	DB       Voice+8     ;pitch control
	DB       19,12,134,134    ;seq7,8 ir age3
	DB        FFH    ; end
;
Tbl3_say377:
	DB      46       ; speech speed
	DB      Voice+3     ;system pitch setting
	DB      34,85,99           ;SEQ9 ir age3
	DB     FFH    ; end
;
Tbl3_say378:
	DB          46        ;speech speed
	DB          Voice+2    ;system pitch setting
	DB          156,25,34        ;seq11 ir age3
	DB        FFH    ; end
;
Tbl3_say379:
	DB     50       speech speed
	DB     Voice+3   ;system pitch setting
	DB     63,165,165,165,165,165,124,31.   ;seq13,14 ir age3
	DB    FFH    ;end
;
Tbl3_say380:
	DB            70      ;speech speed
	DB            Voice+4   ;system pitch setting
	DB            35,72,162,162,162,162.162,162,162,162,162,162,161
	DB        FFH     ;end
;
Tbl3_say381:
	DB            58        ;speech speed
	DB            Voice+5     ; system pitch setting
	DB            40,85     ;SEQ1,2,3,4,5 IR AGE4
	DB        FFH     ;end
;
Tbl3_say382:
	DB            46       ;speech speed
	DB            Voice+6    ;system pitch setting
	DB            81,66,21          ;seq6 ir age4
	DB        FFH     ;end
;
Tbl3_say383:
	DB            46        ;speech speed
	DB            Voice+7     ;system pitch setting
	DB         134,134,25,19     ;seq7,8 ir age4
	DB        FFH     ;end
;
Tbl4_say384:
	DB            50      ;speech speed
	DB            Voice+8    ;system pitch setting
	DB            34,78,145,145     ;seq9 ir age4
	DB        FFH     ;end
;
Tbl4_say385:
	DB            50      ;speech speed
	DB            Voice+8   ;system pitch setting
	DB            119,44,52,71,150        ;seq10 ir age4
	DB            FFH     ;end    SAY NUMBERS MODIFIED TO MATCH CORRECT DIALOGUE
;;; page 243 end
;;; page 244 start XXX; FURBY27.INC page 119
;
Tbl4_say386:
	DB       46       ;speech speed
	DB       Voice+8    ;system pitch setting
	DB       34,85,99        ;seq11 ir age4
	DB        FFH    ;end


Tbl4_say387:
	DB       50      ;speech speed
	DB       Voice+1   ;system pitch setting
	DB       119,124,31       ;seq12 ir ago4
	DB        FFH   ;end

Tbl4_say388:
	DB       56          ;speech speed
	DB       Voice+3       ;system pitch setting
	DB       162,63          ;seq14 ir age4
	DB        FFH    ; end

Tbl4_say389:
	DB      60       ;speech speed
	DB      Voice-8    ;system pitch setting
	DB      161,164,161     ;SEQ10 HANGING (YAWN)
;	DB      46       ;speech speed
;	DB      Voice+3    ;system pitch setting
;	DB      161,144,144       ;seq15 ir age4
	DB     FFH    ;end

;Tbl1_say41:
;	DB           46       ;speech speed
;	DB           Voice+4    ;system pitch setting
;	DB           143,144,143     ;seql6 ir age4
;	DB           FFH      ;end
;
;Tbl1_say42:
;	DB           46         ;speech speed
;	DB           Voice      ;system pitch setting
;	DB           4
;	DB           FFH        ;end
;
;
;
Tbl4_say390:
	DB     55      ;speech speed
	DB     Voice+3   ;system pitch setting
	DB     165,165,144,165,144,165,144,165,144
	DB    FFH    ;end
;END IR
;END GEORGE

; ADDED BY DMH      (FOR FURBY SAYS)
Tbl4_say391:
	DB           46         ;speech speed
	DB           Voice      ;system pitch setting
	DB           42         ; LIGHT (FURBY SAYS)
	DB       FFH        ;end

;	ADDED BY DMH    (FOR FURBY SAYS)
;;; page 244 end
;;; page 245 start XXX; FURBY27.INC page 120
Tbl4_say392:
	DB      52       ;speech speed
	DB     Voice ;system pitch setting
	DB      60,42    ;no light
	DB      FFH      ;end
;
Tbl4_say393:
	DB     55      ;speech speed
	DB    Voice ;system pitch setting
	DB     164,163,46 ; LOUD SOUND
	DB    FFH    ;end
;
;
Tbl4_say394:                           ; DMH
	DB          46        ;speech speed
	DB          Voice     ;system pitch setting
	DB          164,163,44        ; LISTEN (FURBY SAYS)
	DB          FFH       ;end
;
Tbl4_say395:
	DB          46        ;speech speed
	DB          Voice     ;system pitch setting
	DB          52,163    ; (ME) with names (dmh)
	DB          FFH       ;end
;
Tbl4_say396:
	DB          56        ;speech speed
	DB          Voice     ;system pitch setting
	DB          162,55    ;name (MEE MEE) (dmh)
	DB    FFH    ;end
;
Tbl4_say397:
	DB          58           ;speech speed
	DB          Voice        ;system pitch setting
	DB       163,23             ; (DO MOH)
	DB       FFH    ;end
;
Tbl4_say398:
	DB     60                ;speech speed
	DB     Voice             ;system pitch setting
	DB     80                ;TOH-LOO
	DB    FFH    ;end
;
Tbl4_say399:
	DB          60           ;speech speed
	DB          Voice        ;system pitch setting
	DB          165          ; DELAY 1 SECOND DMH
	DB       FFH     ;end
;
; start of diagnostic tables dmh
Tbl4_say400:
	DB     0                ;speech speed
	DB     Voice+16         ;system pitch setting
	DB     168,168,168      ; used at start of diagnostics
	DB    FFH   ;end
;
Tbl4_say401:
	DB           20                       ;speech speed
	DB           Voice+13                 ;system pitch setting
	DB           169,165                  ;key beep
;;; page 245 end
;;; page 246 start XXX; FURBY27.INC page 121
;	DB       1
	DB       FFH        ;end
;
Tbl4_say402:
	DB      20                            ;speech speed
	DB     Voice+5                 ;system pitch setting
	DB     169,163,169,163,169          ;pass test
;	DB     2
	DB     FFH    ;end
;
Tbl4_say403:
	DB      96                          ;speech speed
	DB      Voice-40                    ;system pitch setting
	DB      169,163                     ;fail test tone
	DB     FFH    ;end
;
Tbl4_say404:
	DB     46                            ;speech speed
	DB    Voice                      ;system pitch setting
	DB     169                           ;speaker tone test
	DB       FFH                     ; end
;
Tbl4_say405:
	DB     46       ;speech speed
	DB    Voice ;system pitch setting
	DB    163    ; no sound for start of motor cal
	DB    FFH    ;end
;
Tbl4_say406:
	DB           20                       ;speech speed
	DB       Voice+5               ;system pitch setting
	DB       169,163,169,163,169        ;feed1
	DB       FFH        ;end
;
Tbl4_say407:
	DB       20     ;speech speed
	DB     Voice+5    ; system pitch setting
	DB     169,163,169,163,169      ;pass feed sw
	DB       FFH        ;end
;
Tbl4_say408:
	DB       20      ;speech speed
	DB     Voice+5     ;system pitch setting
	DB     169,163,169,163,169      ;pass light test
	DB     FFH     ;end
;
Tbl4_say409:
	DB      20      ;speech speed
	DB     Voice+5     ;system pitch setting
	DB     169,163,169,163,169     ;pass sound test
	DB       FFH        ;end
;
Tbl4_say410:
	DB        20      ;speech speed
	DB       Voice+5     ;system pitch setting
	DB       169,163,169,163,169     ;pass all test complete
	DB       159
	DB       FFH        ;end
;
Tbl4_say411:
;;; page 246 end
;;; page 247 start XXX; FURBY27.INC page 122
	DB       60         ;speech speed    ; HIDE ME   (HIDE AND SEEK)   DHM
	DB       Voice+3     ;system pitch setting
	DB       31,52                       ; HIDE ME
	DB        FFH    ;end
;
Tbl4_say412:
	DB       100       ;speech speed
	DB        Voice ;system pitch setting
	DB         167,167,167      ;SEQ1 FEED AGE1   (AAAAH)
	DB        FFH     ;end
;
Tbl4_say413:
;
Tbl4_say414:
;
Tbl4_say415:
;
Tbl4_say416:
;
Tbl4_say417:
;
Tbl4_say418:
;
Tbl4_say419:
;
Tbl4_say420:
;
Tbl4_say421:
;
Tbl4_say422:
;
Tbl4_say423:
;
Tbl4_say424:
;
Tbl4_say425:
;
Tbl4_say426:
;
Tbl4_say427:
;
Tbl4_say428:
;
Tbl4_say429:
;
Tbl4_say430:
;
Tbl4_say431:
;
Tbl4_say432:
;
Tbl4_say433:
;
Tbl4_say434:
;
Tbl4_say435:
;
Tbl4_say436:
;
Tbl4_say437:
;;; page 247 end
;;; page 248 start XXX; FURBY27.INC page 123
;
Tbl4_say438:
;
Tbl4_say439:
;
Tbl4_say440:
;
Tbl4_say441:
;
Tbl4_say442:
;
Tbl4_say443:
;
Tbl4_say444:
;
Tbl4_say445:
;
Tbl4_say446:
;
Tbl4_say447:
;
Tbl4_say448:
;
Tbl4_say449:
;
Tbl4_say450:
;
Tbl4_say451:
;
Tbl4_say452:
;
Tbl4_say453:
;
Tbl4_say454:
;
Tbl4_say455:
;
Tbl4_say456:
;
Tbl4_say457:
;
Tbl4_say458:
;
Tbl4_say459:
;
Tbl4_say460:
;
Tbl4_say461:
;
Tbl4_say462:
;
Tbl4_say463:
;
Tbl4_say464:
;
Tbl4_say465:
;
Tbl4_say466:
;
Tbl4_say467:
;;; page 248 end
;;; page 249 start XXX; FURBY27.INC page 124
;
Tbl4_say468:
;
Tbl4_say469:
;
Tbl4_say470:
;
Tbl4_say471:
;
Tbl4_say472:
;
Tbl4_say473:
;
Tbl4_say474:
;
Tbl4_say475:
;
Tbl4_say476:
;
Tbl4_say477:
;
Tbl4_say478:
;
Tbl4_say479:
;
Tbl4_say480:
;
Tbl4_say481:
;
Tbl4_say482:
;
Tbl4_say483:
;
Tbl4_say484:
;
Tbl4_say485:
;
Tbl4_say486:
;
Tbl4_say487:
;
Tbl4_say488:
;
Tbl4_say489:
;
Tbl4_say490:
;
Tbl4_say491:
;
Tbl4_say492:
;
Tbl4_say493:
;
Tbl4_say494:
;
Tbl4_say495:
;
Tbl4_say496:
;
Tbl4_say497:
;;; page 249 end
;;; page 250 start XXX; FURBY27.INC page 125
;
Tbl4_say498:
;
Tbl4_say499:
;
Tbl4_say500:
;
Tbl4_say501:
;
Tbl4_say502:
;
Tbl4_say503:
;
Tbl4_say504:
;
Tbl4_say505:
;
Tbl4_say506:
;
Tbl4_say507:
;
Tbl4_say508:
;
Tbl4_say509:
;
Tbl4_say510:
;
Tbl4_say511:
; ON POWER UP.     UNTIL WAKE-UP TABLE INSTALLED (Dave)
	DB          46     ;speech speed
	DB         Voice
	DB         165
	DB         FFH     ;end

;

;*********************************************************************
;*********************************************************************
;*********************************************************************
;*********************************************************************

; Motor tables

; Offsett pointer

Motor_grp1:

	DW        Tbl1_M000
	DW        Tbl1_M001,Tbl1_M002,Tbl1_M003,Tbl1_M004,Tbl1_M005
	DW        Tbl1_M006,Tbl1_M007,Tbl1_M008,Tbl1_M009,Tbl1_M010
	DW        Tbl1_M011,Tbl1_M012,Tbl1_M013,Tbl1_M014,Tbl1_M015
	DW        Tbl1_M016,Tbl1_M017,Tbl1_M018,Tbl1_M019,Tbl1_M020
	DW        Tbl1_M021,Tbl1_M022,Tbl1_M023,Tbl1_M024,Tbl1_M025
	DW        Tbl1_M026,Tbl1_M027,Tbl1_M028,Tbl1_M029,Tbl1_M030
	DW        Tbl1_M031,Tbl1_M032,Tbl1_M033,Tbl1_M034,Tbl1_M035
	DW         Tbl1_M036,Tbl1_M037,Tbl1_M038,Tbl1_M039,Tbl1_M040
	DW         Tbl1_M041,Tbl1_M042,Tbl1_M043,Tbl1_M044,Tbl1_M045
	DW         Tbl1_M046,Tbl1_M047,Tbl1_M048,Tbl1_M049,Tbl1_M050
	DW         Tbl1_M051,Tbl1_M052,Tbl1_M053,Tbl1_M054,Tbl1_M055
	DW         Tbl1_M056,Tbl1_M057,Tbl1_M058,Tbl1_M059,Tbl1_M060
;;; page 250 end
;;; page 251 start XXX; FURBY27.INC page 126
	DW  Tbl1_M061,Tbl1_M062,Tbl1_M063,Tbl1_M064,Tbl1_M065
	DW  Tbl1_M066,Tbl1_M067,Tbl1_M068,Tbl1_M069,Tbl1_M070
	DW  Tbl1_M071,Tbl1_M072,Tbl1_M073,Tbl1_M074,Tbl1_M075
	DW  Tbl1_M076,Tbl1_M077,Tbl1_M078,Tbl1_M079,Tbl1_M080
	DW  Tbl1_M081,Tbl1_M082,Tbl1_M083,Tbl1_M084,Tbl1_M085
	DW  Tbl1_M086,Tbl1_M087,Tbl1_M088,Tbl1_M089,Tbl1_M090
	DW  Tbl1_M091,Tbl1_M092,Tbl1_M093,Tbl1_M094,Tbl1_M095
	DW  Tbl1_M096,Tbl1_M097,Tbl1_M098,Tbl1_M099
	DW  Tbl1_M100,Tbl1_M101,Tbl1_M102,Tbl1_M103,Tbl1_M104
	DW  Tbl1_M105,Tbl1_M106,Tbl1_M107,Tbl1_M108,Tbl1_M109
	DW  Tbl1_M110,Tbl1_M111,Tbl1_M112,Tbl1_M113,Tbl1_M114
	DW  Tbl1_M115,Tbl1_M116,Tbl1_M117,Tbl1_M118,Tbl1_M119
	DW  Tbl1_M120,Tbl1_M121,Tbl1_M122,Tbl1_M123,Tbl1_M124
	DW  Tbl1_M125,Tbl1_M126,Tbl1_M127
;
Motor_grp2:
	DW  Tbl2_M128
	DW  Tbl2_M129,Tbl2_M130,Tbl2_M131,Tbl2_M132,Tbl2_M133
	DW  Tbl2_M134,Tbl2_M135,Tbl2_M136,Tbl2_M137,Tbl2_M138
	DW  Tbl2_M139,Tbl2_M140,Tbl2_M141,Tbl2_M142,Tbl2_M143
	DW  Tbl2_M144,Tbl2_M145,Tbl2_M146,Tbl2_M147,Tbl2_M148
	DW  Tbl2_M149,Tbl2_M150,Tbl2_M151,Tbl2_M152,Tbl2_M153
	DW  Tbl2_M154,Tbl2_M155,Tbl2_M156,Tbl2_M157,Tbl2_M158
	DW  Tbl2_M159,Tbl2_M160,Tbl2_M161,Tbl2_M162,Tbl2_M163
	DW  Tbl2_M164,Tbl2_M165,Tbl2_M166,Tbl2_M167,Tbl2_M168
	DW  Tbl2_M169,Tbl2_M170,Tbl2_M171,Tbl2_M172,Tbl2_M173
	DW  Tbl2_M174,Tbl2_M175,Tbl2_M176,Tbl2_M177,Tbl2_M178
	DW  Tbl2_M179,Tbl2_M180,Tbl2_M181,Tbl2_M182,Tbl2_M183
	DW  Tbl2_M184,Tbl2_M185,Tbl2_M186,Tbl2_M187,Tbl2_M188
	DW  Tbl2_M189,Tbl2_M190,Tbl2_M191,Tbl2_M192,Tbl2_M193
	DW  Tbl2_M194,Tbl2_M195,Tbl2_M196,Tbl2_M197,Tbl2_M198
	DW  Tbl2_M199,Tbl2_M200,Tbl2_M201,Tbl2_M202,Tbl2_M203
	DW  Tbl2_M204,Tbl2_M205,Tbl2_M206,Tbl2_M207,Tbl2_M208
	DW  Tbl2_M209,Tbl2_M210,Tbl2_M211,Tbl2_M212,Tbl2_M213
	DW  Tbl2_M214,Tbl2_M215,Tbl2_M216,Tbl2_M217,Tbl2_M218
	DW  Tbl2_M219,Tbl2_M220,Tbl2_M221,Tbl2_M222,Tbl2_M223
	DW  Tbl2_M224,Tbl2_M225,Tbl2_M226,Tbl2_M227,Tbl2_M228
	DW  Tbl2_M229,Tbl2_M230,Tbl2_M231,Tbl2_M232,Tbl2_M233
	DW  Tbl2_M234,Tbl2_M235,Tbl2_M236,Tbl2_M237,Tbl2_M238
	DW  Tbl2_M239,Tbl2_M240,Tbl2_M241,Tbl2_M242,Tbl2_M243
	DW  Tbl2_M244,Tbl2_M245,Tbl2_M246,Tbl2_M247,Tbl2_M248
	DW  Tbl2_M249,Tbl2_M250,Tbl2_M251,Tbl2_M252,Tbl2_M253
	DW  Tbl2_M254,Tbl2_M255
;
;
Motor_grp3:
	DW  Tbl3_M256
	DW  Tbl3_M257,Tbl3_M258,Tbl3_M259,Tbl3_M260,Tbl3_M261
	DW  Tbl3_M262,Tbl3_M263,Tbl3_M264,Tbl3_M265,Tbl3_M266
	DW  Tbl3_M267,Tbl3_M268,Tbl3_M269,Tbl3_M270,Tbl3_M271
	DW  Tbl3_M272,Tbl3_M273,Tbl3_M274,Tbl3_M275,Tbl3_M276
	DW  Tbl3_M277,Tbl3_M278,Tbl3_M279,Tbl3_M280,Tbl3_M281
	DW  Tbl3_M282,Tbl3_M283,Tbl3_M284,Tbl3_M285,Tbl3_M286
	DW  Tbl3_M287,Tbl3_M288,Tbl3_M289,Tbl3_M290,Tbl3_M291
	DW  Tbl3_M292,Tbl3_M293,Tbl3_M294,Tbl3_M295,Tbl3_M296
	DW  Tbl3_M297,Tbl3_M298,Tbl3_M299,Tbl3_M300,Tbl3_M301
	DW  Tbl3_M302,Tbl3_M303,Tbl3_M304,Tbl3_M305,Tbl3_M306
	DW  Tbl3_M307,Tbl3_M308,Tbl3_M309,Tbl3_M310,Tbl3_M311
;;; page 251 end
;;; page 252 start XXX; FURBY27.INC page 127
	DW    Tbl3_M312,Tbl3_M313,Tbl3_M314,Tbl3_M315,Tbl3_M316
	DW    Tbl3_M317,Tbl3_M318,Tbl3_M319,Tbl3_M320,Tbl3_M321
	DW    Tbl3_M322,Tbl3_M323,Tbl3_M324,Tbl3_M325,Tbl3_M326
	DW    Tbl3_M327,Tbl3_M328,Tbl3_M329,Tbl3_M330,Tbl3_M331
	DW    Tbl3_M332,Tbl3_M333,Tbl3_M334,Tbl3_M335,Tbl3_M336
	DW    Tbl3_M337,Tbl3_M338,Tbl3_M339,Tbl3_M340,Tbl3_M341
	DW    Tbl3_M342,Tbl3_M343,Tbl3_M344,Tbl3_M345,Tbl3_M346
	DW    Tbl3_M347,Tbl3_M348,Tbl3_M349,Tbl3_M350,Tbl3_M351
	DW    Tbl3_M352,Tbl3_M353,Tbl3_M354,Tbl3_M355,Tbl3_M356
	DW    Tbl3_M357,Tbl3_M358,Tbl3_M359,Tbl3_M360,Tbl3_M361
	DW    Tbl3_M362,Tbl3_M363,Tbl3_M364,Tbl3_M365,Tbl3_M366
	DW    Tbl3_M367,Tbl3_M368,Tbl3_M369,Tbl3_M370,Tbl3_M371
	DW    Tbl3_M372,Tbl3_M373,Tbl3_M374,Tbl3_M375,Tbl3_M376
	DW    Tbl3_M377,Tbl3_M378,Tbl3_M379,Tbl3_M380,Tbl3_M381
	DW    Tbl3_M382,Tbl3_M383
;
;
Motor_grp4:
	DW    Tbl4_M384
	DW    Tbl4_M385,Tbl4_M386,Tbl4_M387,Tbl4_M388,Tbl4_M389
	DW    Tbl4_M390,Tbl4_M391,Tbl4_M392,Tbl4_M393,Tbl4_M394
	DW    Tbl4_M395,Tbl4_M396,Tbl4_M397,Tbl4_M398,Tbl4_M399
	DW    Tbl4_M400,Tbl4_M401,Tbl4_M402,Tbl4_M403,Tbl4_M404
	DW    Tbl4_M405,Tbl4_M406,Tbl4_M407,Tbl4_M408,Tbl4_M409
	DW    Tbl4_M410,Tbl4_M411,Tbl4_M412,Tbl4_M413,Tbl4_M414
	DW    Tbl4_M415,Tbl4_M416,Tbl4_M417,Tbl4_M418,Tbl4_M419
	DW    Tbl4_M420,Tbl4_M421,Tbl4_M422,Tbl4_M423,Tbl4_M424
	DW    Tbl4_M425,Tbl4_M426,Tbl4_M427,Tbl4_M428,Tbl4_M429
	DW    Tbl4_M430,Tbl4_M431,Tbl4_M432,Tbl4_M433,Tbl4_M434
	DW    Tbl4_M435,Tbl4_M436,Tbl4_M437,Tbl4_M438,Tbl4_M439
	DW    Tbl4_M440,Tbl4_M441,Tbl4_M442,Tbl4_M443,Tbl4_M444
	DW    Tbl4_M445,Tbl4_M446,Tbl4_M447,Tbl4_M448,Tbl4_M449
	DW    Tbl4_M450,Tbl4_M451,Tbl4_M452,Tbl4_M453,Tbl4_M454
	DW    Tbl4_M455,Tbl4_M456,Tbl4_M457,Tbl4_M458,Tbl4_M459
	DW    Tbl4_M460,Tbl4_M461,Tbl4_M462,Tbl4_M463,Tbl4_M464
	DW    Tbl4_M465,Tbl4_M466,Tbl4_M467,Tbl4_M468,Tbl4_M469
	DW    Tbl4_M470,Tbl4_M471,Tbl4_M472,Tbl4_M473,Tbl4_M474
	DW    Tbl4_M475,Tbl4_M476,Tbl4_M477,Tbl4_M478,Tbl4_M479
	DW    Tbl4_M480,Tbl4_M481,Tbl4_M482,Tbl4_M483,Tbl4_M484
	DW    Tbl4_M485,Tbl4_M486,Tbl4_M487,Tbl4_M488,Tbl4_M489
	DW    Tbl4_M490,Tbl4_M491,Tbl4_M492,Tbl4_M493,Tbl4_M494
	DW    Tbl4_M495,Tbl4_M496,Tbl4_M497,Tbl4_M498,Tbl4_M499
	DW    Tbl4_M500,Tbl4_M501,Tbl4_M502,Tbl4_M503,Tbl4_M504
	DW    Tbl4_M505,Tbl4_M506,Tbl4_M507,Tbl4_M508,Tbl4_M509
	DW    Tbl4_M510,Tbl4_M511

;*******************************************************************
;*******************************************************************
;*******************************************************************

; Each motor table has the following format:
; The first line is the delay between motor steps.
; The next group of lines are the motor steps.
; The last line is the terminator command.

; Delay table - a number from 0 - 255. THe entry is multiplied by
; a 2.9 mSec timer. Therefore l=2.9mSec 2=5.8msec 255=739mSec.
;
; The motor step is entered as a decimal number of 10-190.
; '00' is a PAUSE command base on the motor delay setting.
;;; page 252 end
;;; page 253 start XXX; FURBY27.INC page 128
; 'FF'   or    '255'   is the end of table command.
;
;
;TABLES WITH ENDING STEP NOT WITHIN REQUIRED RANGE(10-20),(132,136)
;------------------------------------------------------------------
;M94,M127,M131,M139,M140,M143,M146
;
;WITH DUPLICATE STEPS PUT CONSECUTIVELY
;--------------------------------------
;M187,M193,M219,M220,M229,M237,M241,M242
;M250,M310,M321,M369

Tbl1_M000:
	DB                50                 ;motor delay between steps
	DB       10,135
	DB        FFH   ; end



;GEORGE 07/03/96
Tbl1_M001:                                             ;dON START  SEQ1 AGE1
	DB       1                          ;motor delay between steps
	DB       190,133
	DB       FFH
;
Tbl1_M002:                                             ;dON START   SEQ2 AGE1
	DB                1               ;motor delay between steps
	DB                150,145,138,120,145,133,147,133
	DB                FFH       ;end
;
Tbl1_M003:
	DB                10              ;motor delay between steps
	DB                90,100,0,0,0,100,0,0,0,0,133   ;CONNECTED M23 ;dON START SEQ3 AGE1
;	DB                145,160,0,0,0,160
	DB                 FFH      ;end
;
Tbl1_M004:
	DB             1               ;motor delay between steps
	DB            200,190,160,100,133         ;CONNECTED M22 ;dON START SEQ3 AGE1
	DB             FFH      ;end
;
Tbl1_M005:
	DB             5               ;motor delay between steps
	DB             170,130,90,100,133      ; DONE conected m22 seq4 age1
	DB             FFH      ;end
;
Tbl1_M006:
	DB               10             ;motor delay between steps
	DB        150,200,0,0,150,133      ;seq5 front1 age1
	DB        FFH      ;end
;
Tbl1_M007:
	DB             1                 ;motor delay between steps
	DB             120,150,133        ;SEQ6 FRONT1 AGE1 HORSE LAUGH
	DB             FFH   ;end
;
Tbl1_M008:
	DB             10               ;motor delay between steps
	DB        150,200,150,170,133              ;SEQ7 FRONT AGE1
;;; page 253 end
;;; page 254 start XXX; FURBY27.INC page 129
	DB   FFH     ; end
;
Tbl1_M009:
	DB        10              ;motor delay between steps
	DB        150,200,150,190,170,120,133      ;SEQ8,FRONT AGE1
	DB   FFH     ;end
;
Tbl1_M010:
	DB        1                ;motor delay between steps
	DB        180,100,133                        ;SEQ9,FRONT AGE1
	DB   FFH     ;end
;
Tbl1_M011:
	DB        1              ;motor delay between steps
	DB        80,0,150,0,125,0,0,133           ;SEQ10,FRONT AGE1
	DB   FFH     ; end
;
Tbl1_M012:
	DB        10              ;motor delay between steps
	DB        125,0,0,0,0,0,0,0,0,133,80,133    ;SEQ11,FRONT AGE1
	DB   FFH     ; end
;
Tbl1_M013:
	DB        20             ;motor delay between steps
	DB        145,133,145,133,145,133,145
	DB        125,0,0,0,0,0,130,0,0,90,133     ;seql2 FRONT AGE1 ADD SAY20 TO FRONT
	DB        FFH     ;end
;
Tbl1_M014:
	DB        10                                 ;motor delay between steps
	DB   90,130,120,0,0,133                 ;seq13 FRONT AGE1 ADD SAY 22
	DB   FFH      ;end
;
Tbl1_M015:
	DB    10                                 ;motor delay between steps
	DB   125,110,133                        ;seql4 FRONT AGE1 ADD SAY22
	DB   FFH      ;end
;
Tbl1_M016:
	DB    1              ;motor delay between steps
	DB    160,0,0,133,125,150,133           ;seql5 FRONT AGE1
	DB   FFH      ;end
;
Tbl1_M017:
	DB    10             ;motor delay between steps
	DB    120,133,125,150,120,0,0,0,0,0,0,0,0,133         ;seql6 FRONT AGE1 ADD 37
	DB    FFH      ;end
;
Tbl1_M018:
	DB     1               ;motor delay between steps
	DB     124,0,115,0,133,120,133                       ;seql6 FRONT AGE1 ADD 37
	DB     FFH     ; end
;
;;; page 254 end
;;; page 255 start XXX; FURBY27.INC page 130
Tbl1_M019:
	DB        10              ;motor delay between steps
;	DB        90,100,0,0,0,100,0,0,0,0,133        ;SEQ1 FRONT AGE2
	DB        175,160,0,0,0,160,0,0,0,0,133
	DB        FFH        ;end

Tbl1_M020:
	DB        10               ;motor delay between steps
	DB        143,150,133,155,133               ;SEQ2 FRONT AGE2
	DB        FFH        ;end
;
Tbl1_M021:
	DB        1               ;motor delay between steps
	DB        180,133,180,133
;	DB        100,70,10,133            ;SEQ3AGE2 FRONT ADD SEQ9AGE1
	DB        FFH        ;end

Tbl1_M022:
	DB        10                  ;motor delay between steps
	DB        140,150,133                    ;SEQ4 AGE2 FRONT
	DB        FFH      ;end

Tbl1_M023:
	DB        1               ;motor delay between steps
	DB        120,133,0,0,0,0,0,0,0,140,150,133       ;SEQ4 AGE2
	DB        FFH        ;end

Tbl1_M024:
	DB        5              ;motor delay between steps
;	;SEQ5 AGE2 FRONT
	DB        150,140,138,120,145,133,0,147,133
	DB        FFH        ; end

Tbl1_M025:
	DB        1               ;motor delay between steps
	DB        150,200,0,0,150,133,143,133,143
	DB        133,110,133       ;SEQ6 AGE2 FRONT
	DB        FFH        ;end

Tbl1_M026:
	DB        10                           ;motor delay between steps
	DB        142,150,133                  ;SEQ 7 AGE2 FRONT PART1
	DB        FFH         ;end

Tbl1_M027:
	DB       1                   ;motor delay between steps
;SEQ 7 AGE2 FRONT PART2
	DB             150,145,160,133,145,133,145,133
	DB             FFH     ;end

; danger always   followed by 003: dmh
Tbl1_M028:
	DB        1                    ;motor delay between steps
	DB        30,70 ;<- OK        ;SEQ8 MIDDLE OF 22,AND 4SOMETHING
	DB        FFH         ;end     ;


Tbl1_M029:
	DB         1                  ;motor delay between steps
	DB        190,133             ;SEQ 9 TITTER
	DB        FFH        ;end
;;; page 255 end
;;; page 256 start XXX; FURBY27.INC page 131
;
Tbl1_M030:
	DB      1               ;motor delay between steps
	DB      120,133,140,150,133     ; SEQ10 FRONT AGE2
	DB      FFH     ;end
;
Tbl1_M031:
	DB      5               ;motor delay between steps
	DB      180,160,133,115,105,133                   ;SEQ11 FRONT AGE 2 ADD 41
	DB      FFH     ;end
;
Tbl1_M032:
	DB      10              ;motor delay between steps
	DB      145,133,145,133,145,133,0,120,115,133
	DB      FFH             ;SEQ12 FRONT AGE 2 ADD 20
;
Tbl1_M033:
	DB      1               ;motor delay between steps
	DB      150,170,190,133,120,133,135,133,150,0,0,133       ;SEQ14 FRONT
	DB      FFH     ;end
;
Tbl1_M034:
	DB      10               ;motor delay between steps
	DB      125,0,0,0,0,0,133,145,133      ;SEQ15 FRONT AGE2 ADD 20
	DB      FFH     ;end
;
Tbl1_M035:
	DB      1               ;motor delay between steps
	DB      120,0,0,0,0,0,0,0,133,145
	DB      133,0,150,133,110,133,120,0,0,133     ;SEQ16 FRONT AGE2 ADD 20
	DB      FFH     ;end
;
Tbl1_M036:
	DB      1                ;motor delay between steps
	DB      155,0,0,0,133                   ;SEQ1 FRONT AGE3
	DB      FFH      ;end
;
Tbl1_M037:
	DB      1              ;motor delay between steps
	DB      140,150,133,120,133,110,133     ;SEQ2 FRONT AGE3
	DB      FFH     ;end
;
Tbl1_M038:
	DB      1              ;motor delay between steps
	DB      155,0,0,0,133,155,0,0,0,133      ;SEQ3 FRONT AGE3
	DB      FFH     ;end
;
Tbl1_M039:
	DB      1                ;motor delay between steps
	DB      190,0,0,133                         ;SEQ4 FRONT AGE3
	DB      FFH      ;end
;ERROR
;Tbl1_M040:
;	DB     10                ;motor delay between steps
;	DB     140,150,133                        ;SEQ5 FRONT AGE3 ADD SEQ14AGE1
;	DB      FFH      ;end




A-256
;;; page 256 end
;;; page 257 start XXX; FURBY27.INC page 132
;
Tbl1_M040:
	DB         10                     ;motor delay between steps
	DB         150,200,0,0,150,133,143,133
	DB         143,133,110,0,0,133                   ;SEQ6 FRONT AGE3
	DB         FFH     ;end
;
Tbl1_M041:
	DB         1              ;motor delay between steps
	DB       160,140,0,150,133,160,140,133
	DB       150,160,133     ;SEQ7 FRONT AGE3
	DB       FFH     ;end
;
Tbl1_M042:
	DB         1                  ;motor delay between steps
	DB         30,70,120         ;SEQ?
;	DB         160,140,0,150,133,160,140,133
	DB         FFH     ;end
;
Tbl1_M043:
	DB       10              ;motor delay between steps
	DB       80,0,150,0,125,0,0,133          ;SEQ10 FRONT AGE3
	DB       FFH      ;end
;
Tbl1_M044:
	DB         1                      ;motor delay between steps
	DB         100,133,120,133                    ;SEQ11
	DB         FFH      ; end
;
Tbl1_M045:
	DB         10               ;motor delay between steps
	DB         150,0,0,133,120,100,133         ;SEQ12 FRONT AGE3 (HEEY,TICKLE ME) ADD20               DB           4
	DB      FFH         ;end
;
Tbl1_M046:
	DB          10             ;motor delay between steps
	DB          145,133,145,133,145,133         ;SEQ13 £RONT AGE3 (NANNY,NANNY)     ADD20
	DB        FFH     ;end
;
Tbl1_M047:
	DB          1            ;motor delay between steps
	DB          125,0,130,0,0,90,133   ;SEQ13 fRONT AGE3 (RASBERRY, HE HE HE )   ADD20
	DB        FFH     ;end
;
Tbl1_M048:
	DB          1                    ;motor delay between steps
	DB          200,0,0,133            ;SEQ16 FRONT AGE3
	DB          FFH     ;end
;
Tbl1_M049:
	DB          1                   ;motor delay between steps
	DB          120,110,133,115,133               ;SEQ16
	DB          FFH     ;end
;
Tbl1_M050:
	DB          10                    ;motor delay between steps
	DB         140,150,133      ;   SEQ2 (TICKLE)   FRONT AGE4
;;; page 257 end
;;; page 258 start XXX; FURBY27.INC page 133
	DB       FFH        ; end
;
Tbl1_M051:
	DB      10                   ;motor delay between steps
	DB      125,100,133                ; SEQ2 (AGAIN) FRONT AGE4
	DB      FFH        ;end
;
Tbl1_M052:
	DB      1                    ;motor delay between steps
	DB      120,133              ;SEQ3 (YOU) FRONT AGE4
	DB      FFH        ;end
;
Tbl1_M053:
	DB      10                     ;motor delay between steps
	DB      160,133              ;SEQ3 (ME) FRONT AGE4
	DB      FFH        ;end
;
Tbl1_M054:
	DB      20                     ;motor delay between steps
	DB      150,133              ;SEQ4 (LOVE) FRONT AGE4 ADD45 74 71 20
	DB      FFH        ;end
;
Tbl1_M055:
	DB      10                ;motor delay between steps
	DB      135,133,150,0,0,133          ;SEQ5 (HE HE HE)       FRONT AGE4 ADD26
	DB      FFH        ;end
;
Tbl1_M056:
	DB       10                ;motor delay between steps
	DB       154,133,115,0,0,0,0,0,0,133         ;SEQ5 (BIG FUN!      FRONT AGE4 ADD26
	DB       FFH        ;end
;
Tbl1_M057:
	DB       10                   ;motor delay between steps
	DB       120,133              ;SEQ8 (NO) FRONT AGE4
	DB       FFH        ;end
;
Tbl1_M058:
	DB       1                   ;motor delay between steps
	DB       100,133                     ;SEQ8 (PLEASE) FRONT AGE4
	DB       FFH        ;end
;
Tbl1_M059:
	DB      10                    ;motor delay between steps
	DB      150,0,0,0,133           ;SEQ9 (HEEY) FRONT AGE4 ADD71
	DB      FFH        ;end
;
Tbl1_M060:
	DB      1                   ;motor delay between steps
	DB      120,100,133            ;SEQ14 (PARTY) AGE4 ADD45
	DB      FFH     ;end

;
Tbl1_M061:
	DB      10                    ;motor delay between steps
	DB      143,150,170,133              ;SEQ15 (WA WA WA) FRONT AGE4 ADD22
	DB      FFH        ;end
;END GEORGE 07/03/98
;
;;; page 258 end
;;; page 259 start XXX; FURBY27.INC page 134
;

; (BOTTOM)
;GEORGE 07/04/98
Tbl1_M062:
	DB      20                              ;motor delay between steps
	DB      150,0,0,0,133                   ;FORTUNE ASK
	DB    FFH     ;end
;
Tbl1_M063:
	DB          1                           ;motor delay between steps
	DB          150,0,0,133                 ;FORTUNE ASK
	DB         FFH   ;end
;
Tbl1_M064:
	DB             1                         ;motor delay between steps
	DB          150,0,0,0,133             ;FORTUNE TELL         (BIG)
	DB         FFH     ;end
;
Tbl1_M065:
	DB          10                          ;motor delay between steps
	DB          190,150,0,0,133             ;FORTUNE TELL (VERY,BIG)
	DB         FFH    ;end
;
Tbl1_M066:
	DB            1                         ;motor delay between steps
	DB            120,0,0,0,0,0,0,0,0,133   ;FORTUNE TELL (SEE)
	DB         FFH     ;end

; danger always followed by 68:   dmh
Tbl1_M067:
	DB        10                          ;motor delay between steps
	DB        30,10,30,10,30,10,70        ;<- OK   ;FORTUNE WHINE START
	DB         FFH    ;end
;
Tbl1_M068:
	DB            1                         ;motor delay between steps
	DB            100,133,150,133,150,133   ;FORTUNE WHINE START
	DB         FFH     ;end
;
Tbl1_M069:
	DB          1                           ;motor delay between steps
	DB          150,133                     ;FORTUNE TELL (NO)
	DB         FFH   ;end
;
Tbl1_M070:
	DB            1                         ;motor delay between steps
	DB            125,100,133               ;FORTUNE TELL (WORRY)
	DB         FFH     ;end
;
Tbl1_M071:
	DB            10                        ;motor delay between steps
	DB            110,120,133               ;FORTUNE (SOUND)
	DB         FFH      ;end
;
Tbl1_M072:
	DB             1                         ;motor delay between steps
	DB         150,133                   ;FORTUNE  (GOOD)
	DB        FFH     ;end
;
;;; page 259 end
;;; page 260 start XXX; FURBY27.INC page 135
Tbl1_M073:
	DB             1                             ;motor delay between steps
	DB       150,0,133                       ;FORTUNE TELL (VERY)
	DB        FFH   ; end
;
Tbl1_M074:
	DB             1                            ;motor delay between steps
	DB             145,133,150,0,0,0,0,0,133      ;FORTUNE (WHOOPEE)
	DB         FFH           ; end
;
Tbl1_M075:
	DB             1                             ;motor delay between steps
	DB             115,133                       ;FORTUNE (GOOD)
	DB        FFH        ;end
;
Tbl1_M076:
	DB          1                               ;motor delay between steps
	DB          120,0,0,0,0,133                 ;FORTUNE (RASPBERRY)
	DB         FFH   ;end
;
Tbl1_M077:
	DB       1                               ;motor delay between steps
	DB       150,115,133                     ;FORTUNE (OH OH)
	DB        FFH   ;end
;
Tbl1_M078:
	DB            1                             ;motor delay between steps
	DB            150,115,133                   ;FORTUNE (MAY BEE)
	DB            FFH                   ;end


;END GEORGE 07/04/98
;START HANGOUT
;GEORGE 07/04/98
;
Tbl1_M079:
	DB                                      ;motor delay between steps
	DB     150,133,135,150,133              ;SEQ1 HANGING(DE DE DE ,DUM  DUM DUM DUM) AGE1
	DB    FFH   ;end
;
Tbl1_M080:
	DB                                       ;motor delay between steps
	DB             190,133                   ;SEQ1 HANGING(DUM  DUM DUM DUM) AGE1
	DB        FFH         ; end
;
Tbl1_M081:
	DB             1                     ;motor delay between steps
	DB             120,100,133
	DB             120,100,133           ;SEOl HANGING   (bEEDO)
	DB        FFH         ;end
;
Tbl1_M082:
	DB                 1                    ;motor delay between steps
	DB                 143,150,170,0,0,0,0,190        ;-133
;	DB                120,100,160,133   ;SEQl HANGING    (YA DA DA)
	DB                 FFH      ;end
;
Tbl1_M083:
	DB                1    ;motor delay between steps
;;; page 260 end
;;; page 261 start XXX; FURBY27.INC page 136
	DB           190,120,133
	DB           150,133,150,133      ;SEQ3 HANGING   ( OMPAH   bRUMM
BABABUM)
	DB           FFH        ;end
;
Tbl1_M084:
	DB              10                              ;motor delay between steps
	DB              125,120,125,115,133             ;SEQ3 HANGING (bRUMM BABABUM)
	DB         FFH     ;end
;
Tbl1_M085:
	DB              1                               ;motor delay between steps
	DB              115,125,110,125,100,133   ;SEQ4 HANGING (LA LA)
	DB         FFH     ;end
;
Tbl1_M086:
	DB              1                       ;motor delay between steps
	DB              120,130,115             ;SEQ4 HANGING (LA LA)
	DB              100,125,115,125,115,125,115,125,115,133
	DB         FFH     ;end
;
Tbl1_M087:
	DB          1                       ;motor delay between steps
	DB          120,0,0,0,0,0,0,0,133   ;SEQ5 HANGING (HUMM BO DAH WAY- LOH)
	DB         FFH     ; end

;Tbl1_M088:
;	DB           10                         ;motor delay between steps
;	DB           115,133,139,155,160,133    ;SEQ5 HANGING (HUMM BO DAH WAY- LOH)
;	DB          FFH        ;end

Tbl1_M088:
	DB              10                      ;motor delay between steps
	;DB              115,133,139,155,160,133 ;SEQ5 HANGING (HUMM BO DAH WAY LOH)
	DB          115,133,160,133       ;SEQ5 HANGING   (HUMM BO DAH WAY-LOH)
	DB          FFH        ;end
;
Tbl1_M089:
	DB              60                            ;motor delay between steps
	DB              190,170,150,133,0,0,0,0,0,0   ;SEQ6 HANGING (SNORE)
	DB         FFH     ;end
;
Tbl1_M090:
	DB          10                              ;motor delay between steps
	DB          150,133                         ;SEQ6 HANGING (SHOUT)
	DB         FFH     ;end
;
Tbl1_M091:
	DB          1                             ;motor delay between steps
	DB          143,150,140,0,150,0,0,133       ;SEQ6 HANGING (OK KAH)
	DB         FFH     ;end
;
Tbl1_M092:
	DB              5                              ;motor delay between steps
	DB              110,133                         ;SEQ6 HANGING (U-TYE)
	DB         FFH     ;end
;
;;; page 261 end
;;; page 262 start XXX; FURBY27.INC page 137
Tbl1_M093:
	DB              60                          ;motor delay between steps
	DB              190,180,170,150,133         ;SEQ7 HANGING (SOFTER)
	DB           FFH     ;end
;
; danger sleep
Tbl1_M094:
	DB         50                         ;motor delay between steps
	DB         190,170,150,10           ;SEQ7 HANGING (SOFTER)
	DB        FFH     ;end
;
Tbl1_M095:
	DB              20                          ;motor delay between steps
	DB            145,133,115,0,133             ;SEQ8 HANGING ADD 76
	DB           FFH   ;end
;
Tbl1_M096:
	DB              1                           ;motor delay between steps
	DB              150,115,150,133             ;SEQ9 HANGING (DO BE DOBE DO)
	DB           FFH     ;end
;
Tbl1_M097:
	DB         46                       ;motor delay between steps
	DB         170,0,0,0,200,150,0,0,150,0,133      ;SEQ10 HANGING (YAWN)
	DB        FFH        ;end
;
Tbl1_M098:
	DB            255                           ;motor delay between steps
	DB            150,133                       ;SEQ11 AND SEQ12 HANGING (SIGH)
	DB           FFH   ;end
;
Tbl1_M099:
	DB              1                           ;motor delay between steps
	DB              144,133                     ;SEQ13 SEQ14 HANGING (HA)
	DB           FFH     ;end
;
Tbl1_M100:
	DB            10                            ;motor delay between steps
	DB            104,0,0,0,133
	DB           FFH    ;end
;
Tbl1_M101:
	DB              20                          ;motor delay between steps
	DB              100,133,0,0,0,100,133                    ;SEQ16
	DB           FFH     ;end
;
;danger. USED IN ONE CASE,          HANGING OUT,   FOLLOWED BY 101
Tbl1_M102:
	DB     10                                  ;motor delay between steps
	DB     0                                   ;SEQ16 HANGING (PAUSE) ADD20
	DB    FFH    ;end
;
Tbl1_M103:
	DB              1                 ;motor delay between steps
	DB              114,133           ;SEQ6 HANGING (UP)
	DB           FFH     ;end
;
Tbl1_M104:
	DB             1                           ;motor delay between steps




A-262
;;; page 262 end
;;; page 263 start XXX; FURBY27.INC page 138
	DB          120,133                      ;SEQ6 HANGING   (ME)
	DB         FFH     ;end
;
Tbl1_M105:
	DB          1                           ;motor delay between steps
	DB        120,133                       ;UP
	DB         FFH   ;end
;
Tbl1_M106:
	DB          10                          ;motor delay between steps
	DB          125,104,133                 ;SEQ5 BORING
	DB         FFH     ;end
;	------------------------------------------------------


;END HANGOUT
;
;
; danger, OK PAUSE FOR FORTUNE TELLING
Tbl1_M107:
	DB          1                 ;motor delay between steps
	DB          0
	DB       FFH               ;end    ; Fortune pause
;END GEORGE 07/04/98
;FEED
;GEORGE 07/05/98
Tbl1_M108:
	DB         10           ;motor delay between steps
	DB        115,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB        133 ;SEQ1 FEED AGE1 (UUMMMMM)
	DB         FFH   ; end

Tbl1_M109:
	DB          1                ;motor delay between steps
;	DB             140
	DB     165,0,0,0,0,0,0,150,0,0,165,0,0,0,0,0,0,133            ;SEQ1 FEED AGE1 (AAAAH)
	DB    FFH   ;end
;
Tbl1_M110:
	DB            1               ;motor delay between steps
	DB            120,130,110,133    ;SEQ2 FEED AGE1 (KOH KOH)
	DB           FFH   ;end
;
Tbl1_M111:
	DB               1               ;motor delay between steps
	DB               120,130,120,133 ;ME ME
	DB         FFH     ;end
;
Tbl1_M112:
	DB        1               ;motor delay between steps
	DB        145,133,150,133   ;E-DAY
	DB         FFH    ;end
;
Tbl1_M113:
	DB           1           ;motor delay between steps
	DB           115,130,110,133   ;DO MOH
	DB           FFH   ;end
;
Tbl1_M114:
;;; page 263 end
;;; page 264 start XXX; FURBY27.INC page 139
	DB        1               ;motor delay between steps
	DB        115,130,120,133    ;TOH DYE
	DB         FFH   ;end
;
Tbl1_M115:
	DB         10              ;motor delay between steps
	DB        110,133                        ; BURP
	DB         FFH   ;end
;
Tbl1_M116:
	DB           1                   ;motor delay between steps
	DB           145,133           ;SIGH
	DB          FFH   ;end
;
Tbl1_M117:
	DB         10              ;motor delay between steps
	DB         150,133
	DB         FFH     ;end
;
Tbl1_M118:
	DB          10           ;motor delay between steps
	DB          120,0,0,0,133
	DB          FFH   ; end
;
Tbl1_M119:
	DB           1              ;motor delay between steps
	DB           120,130,110,133 ;TOH LOO
	DB          FFH   ;end
;
Tbl1_M120:
	DB          1               ;motor delay between steps
	DB          120,133,120,133
	DB         FFH     ; end
;
Tbl1_M121:
	DB           1               ;motor delay between steps
	DB           145,130,120,133    ;HUNGRY
	DB          FFH   ; end
;
Tbl1_M122:
	DB             1                  ;motor delay between steps
	DB             150,133            ;LIKE
	DB          FFH     ; end
;
Tbl1_M123:
	DB              1                  ;motor delay between steps
	DB              150,0,0,133        ;seq4 feed done
	DB              FFH                ; end
;
;END FEED
;END GEORGE 07/05/98
;
;
;WAKE
;GEORGE 07/06/98
Tbl1_M124:                                  ;SG DONE
	DB       255                      ;motor delay between steps
	DB       95,133
	DB         FFh
; danger
;;; page 264 end
;;; page 265 start XXX; FURBY27.INC page 140
Tbl1_M125:                                     ;SG DONE
	DB           1                   ;motor delay between steps
	DB           75,90     ;<- OK
	DB             FFh
Tbl1_M126:                                      ;SG DONE
	DB                                 ;motor delay between steps
	DB             135,120,135
	DB          FFh
Tbl1_M127:                                    ; SG DONE
	DB          1               ;motor delay between steps
	DB             80,133
	DB          FFh
; danger
Tbl2_M128:                                      ; SG DONE
	DB           1                    ;motor delay between steps
	DB           75,90                ; <-OK
	DB           FFh

Tbl2_M129:                                      ;SG DONE
	DB               1                    ;motor delay between steps
	DB               90,110,133
; DB           90,110,70
	DB          FFh

Tbl2_M130:                                     ;SG DONE
	DB              1                   ;motor delay between steps
	DB              115,133
	DB           FFh
; danger
Tbl2_M131:                                     ; SG DONE
	DB              1                   ;motor delay between steps
	DB              90,70
	DB           FFh
Tbl2_M132:                                   ;SG DONE
	DB           1               ; motor delay between steps
	DB              95,133
	DB           FFh


Tbl2_M133:                                     ;SG DONE
	DB              1                    ;motor delay between steps
	DB              115,133
	DB           FFh

; danger
Tbl2_M134:                                     ;SG DONE
	DB             1                   ;motor delay between steps
	DB             185
	DB          FFh
; danger
Tbl2_M135:                                    ;SG DONE
	DB              1                  ;motor delay between steps
	DB              133
	DB           FFh
; danger
Tbl2_M136:                                   ;SG DONE
	DB              1                  ;motor delay between steps
	DB              133
	DB           FFh
; danger
;;; page 265 end
;;; page 266 start XXX; FURBY27.INC page 141
Tbl2_M137:                       ;SG DONE
	DB      1              ;motor delay between steps
	DB      145
	DB      FFh
; danger
Tbl2_M138:                      ;SG DONE
	DB      1              ;motor delay between steps
	DB      120,133,120,133,120,133,120,133,120,133,120,133,70,85
	DB      0,0,70,0,0,0,0,0,0
	DB      FFh
; danger
Tbl2_M139:                      ;SG DONE
	DB      1              ;motor delay between steps
	DB      82,70
	DB    FFh
; danger
Tbl2_M140:                      ;SG DONE
	DB      1               ;motor delay between steps
	DB      120,115,130,120,70
	DB      FFH     ;end
;
; danger
Tbl2_M141:                      ;SG DONE
	DB      1               ;motor delay between steps
	DB      133
	DB    FFH   ;end
; danger
Tbl2_M142:                       ;SG  DONE
	DB      1              ;motor delay between steps
	DB      75
	DB    FFH   ;end
;
Tbl2_M143:                       ;SG DONE
	DB      1              ;motor delay between steps
; DB      90,80,100,75
	DB      90,80,100,133
	DB      FFH     ;end
;
; danger
Tbl2_M144:                       ;SG DONE
	DB      1              ;motor delay between steps
	DB      120
	DB    FFH   ;end
;
; danger
Tbl2_M145:                      ;SG DONE
	DB      1              ;motor delay between steps
	DB      110,75
	DB    FFH   ;end
;
Tbl2_M146:                      ;SG DONE
	DB      1              ;motor delay between steps
;DB      90,75

	DB      90,133
	DB      FFH     ;end
;
;danger
Tbl2_M147:                        ;SG DONE
	DB      1               ;motor delay between steps
;;; page 266 end
;;; page 267 start XXX; FURBY27.INC page 142
	DB         70,90,75
	DB        FFH        ;end
;
Tbl2_M148:                            ;SG DONE
	DB         1              ;motor delay between steps
	DB         120,130, 115,126,115,140,110,0,0,0,0,0,0,0,0,0,133
	DB        FFH   ;end
;
; danger
Tbl2_M149:                           ;SG DONE
	DB         1              ;motor delay between steps
	DB         75
	DB        FFH        ; end
;
Tbl2_M150:                          ;SG DONE
	DB         1               ;motor delay between steps
	DB         146,135
	DB        FFH   ; end
;
Tbl2_M151:                           ;SG DONE
	DB            1              ;motor delay between steps
	DB            120,133,70,0,135
	DB            FFH      ; end
;
; danger
Tbl2_M152:                           ;SG DONE
	DB           1              ;motor delay between steps
	DB           75
	DB        FFH        ; end
;
; danger
Tbl2_M153:                      ;SG DONE
	DB     1               ;motor delay between steps
	DB     115,75
	DB    FFH    ; end
; danger sleep
Tbl2_M154:                         ;SG DONE
	DB     100                ;motor delay between steps
	DB 0,0,0,85,30,0,20,0,85,30,0,20,0,85,30,0,20,0,75,0,0,0,0,85
	DB     30,0,20,0,10
	DB    FFH    ;end
;danger
Tbl2_M155:                       ;SG DONE
	DB     1               ;motor delay between steps
	DB     90,70
	DB    FFH    ;end
; danger
Tbl2_M156:                       ;SG DONE
	DB     1               ;motor delay between steps
	DB     115,75
	DB    FFH   ; end
;END WAKE
;END GEORGE 07/06/98


;HUNGER
;GEORGE 07/06/98

Tbl2_M157:                            ;SG DONE     ; HUNGER
;;; page 267 end
;;; page 268 start XXX; FURBY27.INC page 143
	DB          50                   ;motor delay between steps
;DB          120,120,133
	DB          120,0,133
	DB          FFH         ;end
;
Tbl2_M158:                                     ;SG DONE
	DB             1                    ;motor delay between steps
	DB          180,133
	DB         FFH     ;end
;
Tbl2_M159:                                     ;SG DONE
	DB          1                      ;motor delay between steps
	DB          115,110,133
	DB         FFH   ;end
;
Tbl2_M160:                                     ;SG DONE
	DB             1                    ;motor delay between steps
	DB          75,133
	DB         FFH     ;end
;
Tbl2_M161:                                     ;SG DONE
	DB        1                      ;motor delay between steps
	DB        115,130,115,130
	DB         FFH   ;end
;
Tbl2_M162:                                     ;SG DONE
	DB          1                      ;motor delay between steps
	DB          115,110,133
	DB         FFH  ;end
;
Tbl2_M163:                                     ;SG DONE
	DB          50                      ;motor delay between steps
	DB          190,133
	DB         FFH    ;end
;
Tbl2_M164:                                     ;SG DONE
	DB             50                    ;motor delay between steps
;DB             148,148,133

	DB          148,0,133
	DB          FFH     ;end
;
Tbl2_M165:                                     ;SG DONE
	DB             50                    ;motor delay between steps
;DB             150,150,150,133

	DB          150,0,0,133
	DB          FFH      ;end
;
Tbl2_M166:                                    ;SG DONE
	DB          1                      ;motor delay between steps
	DB          120,133
	DB         FFH   ;end
;
Tbl2_M167:                                     ;SG DONE
	DB          1                    ;motor delay between steps
	DB          115,133
	DB         FFH        ;end
;
Tbl2_M168:                                    ;SG DONE
;;; page 268 end
;;; page 269 start XXX; FURBY27.INC page 144
	DB           1              ;motor delay between steps
	DB           115,133
	DB          FFh

;END GEORGE 07/06/98
;END HUNGER

;INVERT
;GEORGE 07/07/98
Tbl2_M169:                                 ;SG DONE   ;INVERT
	DB      1                     ;motor delay between steps
	DB      110, 122,        75,130,117,133
	DB    FFH    ; end
;
Tbl2_M170:                                ;SG DONE
	DB          10            ;motor delay between steps
; DB          165,165,133

	DB           165,0,133
	DB           FFH     ;end
;
Tbl2_M171:                                ;SG DONE
	DB             10               ;motor delay between steps
	DB             105,133
	DB          FFH      ; end
;
Tbl2_M172:                                ;SG DONE
	DB           1                 ;motor delay between steps
	DB           150,133
	DB          FFH   ; end
;
Tbl2_M173:                                 ;SG DONE
	DB           1                 ;motor delay between steps
	DB           155,190,133
	DB          FFH   ; end
;
Tbl2_M174:                                 ;SG DONE
	DB             1               ;motor delay between steps
	DB             145,133
	DB          FFH     ;end
;
Tbl2_M175:                               ;SG DONE
	DB           1               ;motor delay between steps
	DB           150,135,145,133
	DB          FFH   ;end
;
Tbl2_M176:                                 ;SG DONE
	DB            1                 ;motor delay between steps
	DB            75,133
	DB          FFH   ;end
;
Tbl2_M177:                               ;SG DONE
	DB           1               ;motor delay between steps
	DB           110,133,115,133
	DB          FFH   I end
;
Tbl2_M178:                                ;SG DONE
	DB         1                 ;motor delay between steps
	DB         115,133
	DB          FFH   ;end
;;; page 269 end
;;; page 270 start XXX; FURBY27.INC page 145
;
Tbl2_M179:                                 ;SG DONE
	DB         1                 ;motor delay between steps
	DB         115,133
	DB        FFH     ;end
;
Tbl2_M180:                           ;SG DONE
	DB       1             ;motor delay between steps
	DB       110,125,115,133
	DB        FFH   ;end
;
Tbl2_M181:                                 ;SG DONE
	DB           1                 ;motor delay between steps
	DB           150,133
	DB        FFH     ;end
;
Tbl2_M182:                                ;SG DONE
	DB           1                 ;motor delay between steps
	DB           115,133
	DB        FFH      end
;
Tbl2_M183:                               ;SG DONE
	DB           1               ;motor delay between steps
	DB           115,130,110,133
	DB        FFH     ;end
;
Tbl2_M184:                                ;SG DONE
	DB         1                   ;motor delay between steps
	DB         75,133
	DB        FFH   ;end
;
Tbl2_M185:                                ;SG DONE
	DB            1                ;motor delay between steps
;DB               150,150,133

	DB         150,0,133
	DB         FFH     ;end
;
Tbl2_M186:                                ;SG DONE
	DB       1               ;motor delay between steps
	DB       115,130,115,133
	DB        FFH   ;end
;
Tbl2_M187:                                ;SG DONE
	DB       1               ;motor delay between steps
	DB       115,130,115,133
	DB        FFH   ;end
;
Tbl2_M188:                                ;SG DONE
	DB       1               ;motor delay between steps
	DB       145,135,145,133
	DB        FFH   ;end
;
Tbl2_M189:                                 ;SG DONE
	DB            1                 ;motor delay between steps
	DB         120,105,133
	DB        FFH     ;end
;
Tbl2_M190:
;;; page 270 end
;;; page 271 start XXX; FURBY27.INC page 146
	DB         1                ;motor delay between steps
	DB         155,190,133
	DB        FFH     ;end
;
Tbl2_M191:
	DB          1                  ;motor delay between steps
	DB          155,190,133
	DB         FFH   ;end
;
Tbl2_M192:
	DB     1                      ;motor delay between steps
	DB     155,190,133
	DB    FFH   ;end
;END GEORGE 07/07/98
;END INVERT

;start at 202
Tbl2_M193:             ;BACKSG                  ;SG DONE
	DB             100               ;motor delay between steps
;DB             200,200,200,200,133
	DB             200,0,0,0,133
	DB             FFH     ;end
;
Tbl2_M194:                                ;SG DONE
	DB          1                  ;motor delay between steps
	DB          75,133
	DB         FFH   ;end
;
Tbl2_M195:                            ;SG DONE
	DB           1               ;motor delay between steps
	DB        115,125,115,133
	DB         FFH   ;end
;
Tbl2_M196:                                ;SG DONE
	DB         10              ;motor delay between steps
	DB            148,133
	DB         FFH     ;end
;
Tbl2_M197:                               ;SG DONE
	DB          1               ;motor delay between steps
	DB          115,125,115,133
	DB         FFH     ;end
;
Tbl2_M198:                               ;SG DONE
	DB            100                ;motor delay between steps
	DB          145,0,0,133
	DB         FFH   ;end
;
Tbl2_M199:                               ;SG DONE
	DB             10                ;motor delay between steps
	DB          110,133
	DB         FFH     ;end
;
Tbl2_M200:                                ;SG DONE
	DB          1                  ;motor delay between steps
	DB          75,133
	DB         FFH   ;end
;
Tbl2_M201:                               ;SG DONE
	DB         10              ;motor delay between steps
;;; page 271 end
;;; page 272 start XXX; FURBY27.INC page 147
	DB         115,125,115,133
	DB        FFH     ;end
;
Tbl2_M202:                                     ;SG DONE
	DB           1                      ;motor delay between steps
	DB           75,133
	DB          FFH   ; end
;
; danger
Tbl2_M203:                               ;SG DONE
	DB             1               ;motor delay between steps
	DB             120,128,79,133,146,0,0,0,133,145
	DB          FFH     ; end
;
Tbl2_M204:                            ; SG DONE
	DB          10          ;motor delay between steps
	DB           190,0,133
	DB          FFH   ;end
;
Tbl2_M205:                                    ;SG DONE
	DB           1                      ;motor delay between step
	DB           115,133
	DB          FFH   ;end
;
; danger
Tbl2_M206:                                     ; SG DONE
	DB             1                    ;motor delay between steps
	DB             75
	DB          FFH        ; end
; danger
Tbl2_M207:                                    ;SG DONE
	DB        10                  ;motor delay between steps
	DB         150
	DB        FFH     ;end
;
Tbl2_M208:                                     ;SG DONE
	DB          10                  ;motor delay between steps
	DB             75,133
	DB          FFH     ;end
;
Tbl2_M209:                                   ;SG DONE
	DB            100                       ;motor delay between steps
	DB            150,0,0,0,133
	DB        FFH   ; end
;
Tbl2_M210:                             ;SG DONE
	DB          10          ;motor delay between steps
	DB           123,110,75,133,115,133
	DB          FFH   ; end
; danger
Tbl2_M211:                                     ;SG DONE
	DB             1                    ;motor delay between steps
	DB             75
	DB          FFH         end
; danger
Tbl2_M212:                                    ;SG DONE
	DB             1                    ;motor delay between steps
	DB         133
	DB        FFH        ;end
;
;;; page 272 end
;;; page 273 start XXX; FURBY27.INC page 148
Tbl2_M213:                              ;SG DONE
	DB            10                 ;motor delay between steps
	DB            115,150,133
	DB            FFH      ;end
;
Tbl2_M214:                                ;SG DONE
	DB           1                 ;motor delay between steps
	DB           80,133
	DB        FFH     ;end
;
; danger
Tbl2_M215:                               ;SG DONE
	DB         100                  ;motor delay between steps
	DB         138
	DB        FFH   ;end
;
Tbl2_M216:                              ;SG DONE
	DB        10              ;motor delay between steps
	DB           75,133
	DB        FFH     ;end
;
Tbl2_M217:                            ;SG DONE
	DB         1               ;motor delay between steps
	DB         115,130,115,133
	DB        FFH   ;end
;
Tbl2_M218:                               ;SG DONE
	DB            50                 ;motor delay between steps
	DB            114,133
	DB            FFH       ;end
;
Tbl2_M219:                       ;SG DONE
	DB     10          ;motor delay between steps
;	DB 120,130,120, 130,120,130,120,130,120,130,120,130,115,115,133
	DB 120,130,120, 130,120,130,120,130,120,130,120,130,115,0,133
	DB      FFH     ;end
;
Tbl2_M220:                               ;SG DONE
	DB        10              ;motor delay between steps
; DB 120,130,120, 130,120,130,120,130,120,130,120,130,115,115,133
	DB 120,130,120, 130,120,130,120,130,120,130,120,130,115,0,133
	DB       FFH     ;end
;
Tbl2_M221:                               ; SG DONE
	DB         10                 ;motor delay between steps
	DB       145,133
	DB        FFH   ;end
;
Tbl2_M222:                               ;SG DONE
	DB         50                   ;motor delay between steps
	DB         0,0,0,0,115,133
	DB        FFH    ;end
;
Tbl2_M223:                                ;SG DONE
	DB            1                 ;motor delay between steps
	DB         115,125,115,133
;;; page 273 end
;;; page 274 start XXX; FURBY27.INC page 149
	DB        FFH        ;end

Tbl2_M224:                              ;SG DONE
	DB            1               ;motor delay between steps
	DB            75,133
	DB         FFH     ;end

Tbl2_M225:                              ;SG DONE
	DB             1              ;motor delay between steps
	DB            110,133
	DB         FFH     ; end

Tbl2_M226:                             ;SG DONE
	DB          100                 ;motor delay between steps
	DB          120,133
	DB         FFH   ; end

Tbl2_M227:                           ;SG DONE
	DB          30              ;motor delay between steps
	DB          190,120.125,120,125,120,125,133
	DB         FFH    ; end

Tbl2_M228:                            ;SG DONE
	DB          1              ;mctor delay between steps
	DB          115,130.110,130,115,133
	DB         FFH   ;end

Tbl2_M229:                              ;SG DONE
	DB             30               .-motor delay between steps
; DB            115,120,110,110,110,133
	DB             115,120,110,0,0,133
	DB             FFH     ;end

Tbl2_M230:                               ;SG DONE
	DB            1               ;motor delay between steps
	DB            110,125.115,133
	DB         FFH     ;end

Tbl2_M231:                              ;SG DONE
	DB         1              ;motor delay between steps
	DB         75,133
	DB        FFH     ; end

Tbl2_M232:                              ;SG DONE
	DB                            ;motor delay between steps
	DB            110,133
	DB         FFH     ; end
; danger
Tbl2_M233:                              ;SG DONE
	DB             1               ;motor delay between steps
	DB         145
	DB        FFH     ; end

; danger sleep
Tbl2_M234:                              ;SG DONE
	DB            10               ;motor delay between steps
	DB            10
	DB        FFH        ; end

Tbl2_M235:                            ;SG DONE




A-274
;;; page 274 end
;;; page 275 start XXX; FURBY27.INC page 150
	DB      10              ;motor delay between steps
	DB      115,125,110,133
	DB    FFH    ;end
;
Tbl2_M236:
	DB      10              ;motor delay between steps
	DB      115,133
	DB    FFH   ;end

Tbl2_M237:                       ;SG DONE    ;SICK2
	DB      100              ;motor delay between steps
;DB      133,140,140,150,150,180,133
	DB      133,140,0,150,0,180,133
	DB  FFH         ;end
;
Tbl2_M238:                       ;SG DONE
	DB      1              ;motor delay between steps
	DB      120,110,133
	DB   FFH   ;end
;
Tbl2_M239:                       ;SG DONE
	DB      1              ;motor delay between steps
	DB      115,133
	DB  FFH   ;end
;
Tbl2_M240:                       ;SG DONE
	DB      10              ;motor delay between steps
	DB      115,0,0,0,0,133
	DB    FFH   ;end
;
Tbl2_M241:                       ;SG DONE
	DB      1              ;motor delay between steps
;DB      124,133,120,133,115,115,0,0,133
	DB      124,133,120,133,115,0,0,0,133
	DB  FFH         ;end
;
Tbl2_M242:                       ;SG DONE
	DB      50              ;motor delay between steps
;DB      115,70,120,120,133
	DB      115,70,120,0,133
	DB  FFH         ;end
;
; danger
Tbl2_M243:                       ;SG DONE
	DB      50              ;motor delay between steps
	DB      70
	DB    FFH   ;end
;
Tbl2_M244:                       ;SG DONE
	DB      50              ;motor delay between steps
	DB      120,133
	DB    FFH   ;end
;
Tbl2_M245:                       ;SG DONE
	DB      50              ;motor delay between steps
	DB      75,133
	DB      FFH     ;end
;
Tbl2_M246:                       ;SG DONE
	DB        10      ;motor delay between steps
;;; page 275 end
;;; page 276 start XXX; FURBY27.INC page 151
	DB         70,133
	DB        FFH     ;end
;
Tbl2_M247:                             ;SG DONE
	DB         10         ;motor delay between steps
	DB          110,133,0,0
	DB         FFH   ;end
;
Tbl2_M248:                               ;SG DONE
	DB          10                ;motor delay between steps
	DB          145,0,0,0,133
	DB         FFH    ;end
;
Tbl2_M249:                               ;SG DONE
	DB          1                ;motor delay between steps
	DB          115,0,0,0,133
	DB         FFH   ;end
;
Tbl2_M250:                              ;SG DONE
	DB             10              ;motor delay between steps
; DB            150,150,150,190,0,133

	DB       150,0,0,190,0,133
	DB       FFH      ;end
;GEORGE 07/08/98
;LIGHT
;
Tbl2_M251:
	DB             5             ;motor delay between steps SGTEST
	DB             115,132,125,110,132
	DB             FFh

Tbl2_M252:
	DB          1               ;motor delay between steps
	DB          190,133
	DB          FFh
Tbl2_M253:
	DB       1             ;motor delay between steps
	DB          10,152,133,160,0,133
	DB       FFh
Tbl2_M254:
	DB          1               ;motor delay between steps
;	DB          143,133,143,137,150,133,155,133
	DB          143,137,143,137,150,0,0,0,133,155,133
	DB       FFh
Tbl2_M255:
	DB          1             ;motor delay between steps
	DB          60,90,60,85,90,60,90,133
	DB       FFh
Tbl3_M256:
	DB          10              ;motor delay between st      DONE RB
	DB          180,165,185,133
	DB       FFh
Tbl3_M257:
	DB       10           ;motor delay between steps
	DB          190,133,105,133,105,160,133 ;WOW              DONE
	DB       FFh
Tbl3_M258:
	DB          4               ;motor delay between steps     DONE
	DB          60,133,0,0,0,0,0,155,133,145,133
;;; page 276 end
;;; page 277 start XXX; FURBY27.INC page 152
	DB       FFh
Tbl3_M259:
	DB          1               ;motor delay between steps     DONE
	DB          160,133,180,133,147,160,133
	DB       FFh

Tbl3_M260:
	DB          1                ;motor delay between steps
	DB          160,133,90,133
	DB       FFh

Tbl3_M261:
	DB         7               ;motor delay between steps
	DB         190,133,100,133
	DB         FFh
Tbl3_M262:
	DB         7              ;motor delay between steps
	DB         60,133,140,153,0,0,133,150,133
	DB      FFh
Tbl3_M263:
	DB         1              ;MOTOR DELAY BETWEEN STEPS
	DB         155,133,160,133,120,110,133
	DB         FFh
Tbl3_M264:
	DB         10              ;motor delay between steps
	DB         190,133,0,0,0,0,110,0,0,0,133
	DB      FFh
Tbl3_M265:
	DB         1              ;motor delay between steps
	DB         60,133,180,133
	DB      FFh
;END LIGHT
;END GEORGE   07/08/98
;
;DARK
;GEORGE 07/08/98
Tbl3_M266:
	DB      1               ;motor delay between steps
	DB      150,133,160,133,120,112,0,0,0,0,0,0,0,0,133
	DB     FFh
Tbl3_M267:
	DB      1               ;motor delay between steps DONE RB
	DB      150,133,120,112,0,0,0,0,0,133,149,0,0,133
	DB     FFh
;
Tbl3_M268:
	DB     10          ;motor delay between steps
	DB      150,133,112,133,120,133,148,133,118,0,0,0,133,146,133
	DB      147,0,0,0,0,0,0,133
	DB      FFH     ;end DONE RB
;
Tbl3_M269:
	DB          1              ;motor delay between steps DONE RB
	DB          10,20,123,115,123,115,123,115,133
	DB          FFH     ;end
;
Tbl3_M270:
	DB        1             ;motor delay between steps    DONE
	DB        190,133,120,133,112,0,0,0,0,0,0,130,112,133
	DB       FFH   ;end
;;; page 277 end
;;; page 278 start XXX; FURBY27.INC page 153
;
Tbl3_M271:
	DB       1               ;motor delay between steps
	DB       147,155,139,149
	DB       133,149,0,0,0,133        ;SEQ6 AGE4/SEQ14 AGE 4 LIGHT js
	DB      FFH   ; end
;
Tbl3_M272:
	DB        1               ;motor delay between steps
	DB        150,133,0,0,0,159,133,150,0,0,133
	DB        145,137,114,133,117,125,117,133
	DB        FFH     ;end DONE

Tbl3_M273:
	DB       1               ;motor delay between steps
	DB       145,155,133,120,115,133,190,133
	DB       0,0,0,150,0,0,0,0,0,0,0,0,133
	DB       0,0,0,0,0,0,0,0,0,0,115,133
	DB       FFH      ;end

Tbl3_M274:
	DB       1             ;motor delay between steps
	DB       150,133,150,0,0,0,133,0,0,0,0,120,115,0,0,0,0,0,0,133
	DB      FFH   ;end

Tbl3_M275:
	DB    10           ;motor delay between steps
	DB 150,133,0,0,0,150,0,0,0,133,0,120,133,120,133,155,0,0,0,0,133
	DB    FFH   ;end

Tbl3_M276:
	DB       1              ;motor delay between steps
	DB       190,0,0,0,0,133,0,0,0,0,0,148,133,118,133,0,0,0
	DB       146,133,147,0,0,0,0,0,0,133
	DB      FFH   ; end

Tbl3_M277:
	DB       1             ;motor delay between steps
	DB       190,133,120,133,112,0,0,0,0,0,0,130,112,133
	DB      FFH   ;end

Tbl3_M278:
	DB       1              ;motor delay between steps
	DB       60,133,60,133,146,154,133
	DB      FFH   ; end

Tbl3_M279:
	DB       1             ;motor delay between steps
	DB       190,133,0,0,0,110,0,0,0,0,133
	DB      FFH   ; end

Tbl3_M280:
	DB       10             ;motor delay between steps
	DB       153,133,0,0,0,116,0,0,0,133,190,155,0,0,0,133
	DB      FFH    ; end

Tbl3_M281:
	DB        1              ;motor delay between steps
	DB        190,155,0,0,0,133,119,0,0,0,0,0,0,133
;;; page 278 end
;;; page 279 start XXX; FURBY27.INC page 154
	DB         146,133,147,0,0,0,0,0,0,133
	DB        FFH     ;end
;
Tbl3_M282:
	DB          1              ;motor delay between steps
	DB          60,133,75,83,78,83,78,133
	DB        FFH   ;end
;
Tbl3_M283:
	DB             1              ;motor delay between steps
	DB            145,155,133,120,115,133,72,0,0,0,0,0,92,133,190,133
	DB             FFH     ;end
;
Tbl3_M284:
	DB         1              ;motor delay between steps
	DB         190,133,0,0,0,110,0,0,0,0,133
	DB        FFH   ;end
;
Tbl3_M285:
	DB        10           ;motor delay between steps
	DB         150,133,0,0,0,116,0,0,0,133,190,155,0,0,0,133
	DB        FFH   ;end
;
Tbl3_M286:
	DB         1              ;motor delay between steps
	DB         190,155,0,0,0,133,119,0,0,0,0,0,0,133
	DB         147,0,0,0,0,0,0,0,0,0,133
	DB        FFH   ;end
;
Tbl3_M287:
	DB         1              ;motor delay between steps
	DB         190,133,110,0,0,0,0,0,133,112,0,0,0,133
	DB        FFH   ;end
;
Tbl3_M288:
	DB     1                ;motor delay between steps
	DB     110,0,0,0,133,115,133,147
	DB     133,190,133    ;SEQ7 AGE4/SEQ15 AGE 4 LIGHT js
	DB    FFH   ;end
;
Tbl3_M289:
	DB     1                ;motor delay between steps
	DB     145,155,133,0,0,0,0,120,115,133,150,133
	DB     160,0,0,0,0,190,0,0,0,0,0,0,0,0,0,133
	DB     0,0,0,0,0,0,0,0,0,0,133       ;SEQ8 AGE4/SEQ 16 AGE 4 INVERT js
	DB    FFH   ;end
;END GEORGE 07/08/98
;END DARK
;
;SOUND
Tbl3_M290:
	DB             1               ;motor delay between steps
	DB             155,133,0,0,0,0,125
	DB             115,145,155,133          ;S1-A1/S9-A1/S1-A2 SOUND js
	DB             FFH     ;end             ;S9-A2/S1-A3/S9-A3 SOUND js
;
Tbl3_M291:
	DB             1              ;motor delay between steps
	DB             100,0,0,0,10




A-279
;;; page 279 end
;;; page 280 start XXX; FURBY27.INC page 155
	DB       0,0,0,0,0,0,0
	DB       0,0,0,70,0,0,0,0       ;S2-A1/S10-A1/S2-A2 SOUND js
	DB       0,0,100,0,0,0,133      ;S10-A2/S2-A3/S10-A3 SOUND js
	DB       FFH     ;end           ;S2-A4 SOUND js

Tbl3_M292:
	DB       1               ;motor delay between steps
	DB       110,0,0,133,0,0,0,0
	DB       0,0,155,0,0,0,0
	DB       133,120,0,112,0
	DB       148,0,0,0,0,0,133           ;S3-A1/S11-A1 SOUND js
	DB      FFH   ;end
;
Tbl3_M293:
	DB       15              .-motor delay between steps
	DB       110,0,120,0,0,0,0,0
	DB       145,0,0,0,155,115
	DB       118,0,0,0,0,133         ;S4-A1/S12-A1 SOUND js
	DB      FFH    ;end
;
Tbl3_M294:
	DB       1               ;motor delay between steps
	DB       115,0,0,0,148
	DB       115,0,0,133         ;S5-A1/S13-A1 LIGHT (with say/m2) js
	DB      FFH   ;end
;
Tbl3_M295:
	DB       1               ;motor delay between steps
	DB       155,133,122,0                ;S6-A1/S14-A1/S6-A2 SOUND js
	DB       115,145,120,0,0,133          ;S14-A2/S6-A3/S14-A3 SOUND js
	DB      FFH   ;end
;
Tbl3_M296:
	DB       1              ;motor delay between steps
	DB       14,150      ;****TODO: doublecheck (judging from the spaces might be 14?,150)****
	DB       125,115
	DB       0,0,0,0,133         ;S7-A1/S15-A1 SOUND (with say/m2) js
	DB      FFH    ;end
;
Tbl3_M297:
	DB       1            ;motor delay between steps
	DB       115,0,0,148,0,0,0,0
	DB       138,0,0,0,148,0,0,0
	DB       0,0,0,0,133         ;S8-A1/S16-A1/S8-A3/S16-A3 SOUND js
	DB       FFH      ; end
;
Tbl3_M298:
	DB       1               ;motor delay between steps
	DB       110,0,0,133,0,0,0,0
	DB       0,0,155,0,0,0,0
	DB       133,120,0,112,0
	DB       148,0,0,0,0,0,133         ;S3-A2/S11-A2 SOUND js
	DB      FFH   ;end
;
Tbl3_M299:
	DB       1               ;motor delay between steps
	DB       110,0,120,0,0,0,0,0
	DB       145,0,0,0,155,190
	DB       0,0,0,0,0,0,160,0,133          ;S4-A2/S12-A2 SOUND js
	DB      FFH   ;end
;;; page 280 end
;;; page 281 start XXX; FURBY27.INC page 156
;
Tbl3_M300:
	DB      1              ;motor delay between steps
	DB      165,0,0,0,190,0,0        ;S5-A2/S13-A2 SOUND (with say/m2) js
	DB      0,0,165,0,0,0,0,133      ;S5-A3/S13-A3 SOUND (with say/m2) js
	DB      FFH     ;end             ;S5-A4 SOUND (with say/m2) js
;
Tbl3_M301:
	DB      1              ;motor delay between steps
	DB      115,0,0,0,0,145,0,0,165        ;S7-A2/S15-A2 SOUND (with say/m2) js
	DB      0,0,190,165,0,0,0,133
	DB    FFH   ;end
;
Tbl3_M302:
	DB      1              ;motor delay between steps
	DB      115,0,0,148,0,0,0
	DB      0,0,0,0,133       ;S8-A2/S16-A2 SOUND js
	DB    FFH   ;end
;
Tbl3_M303:
	DB      1              ;motor delay between steps
	DB      110,0,0,133,0,0,0,0
	DB      0,0,155,0,0
	DB      133,0,112,0
	DB      148,0,0,0,0,0,133       ;S3-A3/SI1-A3 SOUND js
	DB    FFH   ;end
;
Tbl3_M304:
	DB      1              ;motor delay between steps
	DB      110,0,120,0,0,0,0,0
	DB      160,0,0,0,190
	DB      160,0,0,0,0,133     ;S4-A3/S12-A3 SOUND js
	DB      FFH     ;end        ;S4-A4 SOUND js
;
Tbl3_M305:
	DB      1              ;motor delay between steps
	DB      115,0,0,0,0,160
	DB      0,0,190,0,0,0,0
	DB      0,165,133       ;S7-A3/S15/A3 SOUND (with say/m2) js
	DB      FFH     ;end    ;S7-A4 SOUND (with say/m2) js
;
Tbl3_M306:
	DB      1              ;motor delay between steps
	DB      157,0,0,0,133
	DB      0,0,120,0,0,0
	DB      133,150,0,0,0,0,133     ;S1-A4 SOUND js
	DB    FFH   ;end
;
Tbl3_M307:
	DB      1              ;motor delay between steps
	DB      110,0,0,133,0,0,0,0
	DB      0,0,155,0,0
	DB      133,0,112,0,0,0
	DB      148,0,0,0,0,0,0,0,0,133       ;S3-A4 SOUND js
	DB    FFH   ;end
;
Tbl3_M308:
;;; page 281 end
;;; page 282 start XXX; FURBY27.INC page 157
	DB       1              ;motor delay between steps
	DB       157,0,0,0,133
	DB       0,0,120,0,0,0
	DB       133,150,0,0,0,0,0,0,133          ;S6-A4 SOUND js
	DB        FFH   ;end
;
Tbl3_M309:
	DB      1               ;motor delay between steps
	DB      115,0,0,148,0,0,0,0,0,0,0,0
	DB      138,0,0,0,0,0,148,0,0,0
	DB      0,0,0,0,133          ;S8-A4 SOUND js
	DB   FFH   ;end
;END GEORGE
;END SOUND
;GEORGE 07/09/98
;TILT
Tbl3_M310:
	DB       1               ;motor delay between steps
;DB       170,170,0,0,0
	DB       170,0,0,0,0
	DB       0,0,0,0,133           ;S1 A1/S4 A1/S2 A4 TILT js
	DB       FFh
Tbl3_M311:
	DB       1                 ;motor delay between steps
	DB       125,0,0,0,133,120,145,110,133        ;S2 A1 TILT js
	DB       FFH

Tbl3_M312:
	DB       1              ;motor delay between steps
	DB       150,133,145,133,120,133      ;S3 A1 TILT js
	DB     FFh
Tbl3_M313:
	DB     1               ;motor delay between steps
	DB       100,0,0,0,0
	DB       0,0,0,0,133      ;S5 A1/S4 A2/S2 A3/S2 A4 TILT js
	DB       FFh
Tbl3_M314:
	DB       1               ;motor delay between steps
	DB       120,100,0,0,0,0,0,0,70,80,90
	DB       70,85,100,0,0,133      ;S6 A1 TILT js
	DB     FFh
Tbl3_M315:
	DB       1             ;motor delay between steps
	DB       125,133,100,133,145,0,0,160
	DB       190,0,0,175,160,133      ;S7 A1 TILT/S6 A2 TILT js
	DB     FFh
Tbl3_M316:
	DB       1               ;motor delay between steps
	DB       145,133,145,160,145,160
	DB       0,0,0,0,0,0,190,0,0,0,0,0
	DB       0,0,0,0,0,0,0,150,133          ;S8 A1 TILT (with say/m5) js
	DB      FFh
Tbl3_M317:
	DB     10             ;motor delay between steps
	DB       160,0,0,0,0,0,0,0,190,133          ;S9 A1 TILT/S9 A2 TILT js
	DB     FFh
Tbl3_M318:
	DB     10             ;motor delay between steps
;;; page 282 end
;;; page 283 start XXX; FURBY27.INC page 158
	DB          145,165,0,0,0,0,0,0,0,0,0,0
	DB          190,0,0,180,190,133     ;S10 A1 TILT/S10 A2 TILT js
	DB      FFh
Tbl3_M319:
	DB      1             ;motor delay between steps
	DB         0,120,0,0,133,141
	DB         133,120,0,0,0,133        ;S11 A1 TILT (with say/m2) js
	DB         FFh

Tbl3_M320:
	DB         1               ;motor delay between steps
	DB         150,133,123,0,0,133,142
	DB         0,0,150,0,0,0,0,0,133          ;S12 A1 TILT js
	DB      FFh

Tbl3_M321:
	DB          1                 ;motor delay between steps
;DB             200,170,170,0,0,0,0,133     ;S13 A1 / S15 A3 TILT js

	DB          200,170,0,0,0,0,0,133       ;S13 A1 / S15 A3 TILT js
	DB          FFh

Tbl3_M322:
	DB         1               ;motor delay between steps
	DB         170,0,0,0,0,133,126,130,118,133          ;S15 A1 TILT js
	DB      FFh
Tbl3_M323:
	DB         1             ;motor delay betweer steps
	DB         155,0,0,0,0,185
	DB         160,0,0,133     ;S16 A1 / S15 A2 / S13 A3 TILT js
	DB      FFh
Tbl3_M324:
	DB         1              ;motor delay between steps
	DB         170,160,0,0,0,0,0,133    ;S1 A2/S3 A2/S1 A3/S1 A4 TILT js
	DB      FFh
Tbl3_M325:
	DB      10            ;motor delay between steps
	DB         120,145,110,133          ;S2 A2 TILT (with say/m16) js
	DB      FFh
Tbl3_M326:
	DB      10            ;motor delay between steps
	DB         120,100,0,0,0,0,0,0,133
	DB         148,133,142,115,0,0,133            ;S5 A2 TILT js
	DB         FFh
Tbl3_M327:
	DB         1              ;motor delay between steps
	DB         145,133,145,160,145,160,0,0,0,0,0,0
	DB         190,0,0,0,0,0,0,0,0
	DB         150,133                 ;S7 A2 TILT (with say/m5) js
	DB      FFh
;
Tbl3_M328:
	DB       1               ;motor delay between steps
	DB       145,0,0,160,0.0,0,0
	DB       0,0,0,0,0,0,133           ;S8 A2 TILT (with say/m5)     js
	DB      FFH   ;end
;
Tbl3_M329:
	DB          1                 ;motor delay between steps
;;; page 283 end
;;; page 284 start XXX; FURBY27.INC page 159
	DB       0,120,133,143
	DB       118,0,0,0,133           ;S11 A2 TILT (with say/m2) js
	DB        FFH   ;end
;
Tbl3_M330:
	DB         1               ;motor delay between steps
	DB         150,133,123,0,0,133,142
	DB         0,0,150,0,0,0,0,0,133     ;S12 A2 TILT js
	DB        FFH   ;end
;
Tbl3_M331:
	DB         1               ;motor delay between steps
	DB         120,150,133             ;S13 A2 TILT (with say/m5) js
	DB        FFH   ;end
;
Tbl3_M332:
	DB         1              ;motor delay between steps
	DB         120,0,0,0,0,150,0,0,0
	DB         160,0,0,0,133,110,0,0,133        ;S14 A2 TILT js
	DB        FFH   ;end
;
Tbl3_M333:
	DB        10           ;motor delay between steps
	DB         155,0,0,0,0,190,0,0,183,0,0,0
	DB         175,0,0,0,162,0,0,0,0,0,0,0,133
	DB         0,0,120,115,110,115,105,133
	DB         145,155,165,0,0,0,0
	DB         0,0,0,0,0,133         ;S16 A2/S14 A3/S14 A4 TILT js
	DB        FFH   ;end
;
Tbl3_M334:
	DB        10           ;motor delay between steps
	DB         120,100,0,0,0,0,0,0,133         ;S3 A3 TILT js
	DB        FFH   ;end
;
Tbl3_M335:
	DB         1               ;motor delay between steps
	DB         145,133,120,117
	DB         110,0,0,133     ;S4 A3/S4 A4 TILT (with say/m26) js
	DB        FFH   ;end
;
Tbl3_M336:
	DB           1              ;motor delay between steps
	DB           145,165,0,0,0,0,0,0,0,0,0,0,133
	DB           120,133,145,155,0,0,0,133,115,0,0,0,133 ;S4 A3 TILT js
	DB           FFH     ;end

Tbl3_M337:
	DB         1              ;motor delay between steps
	DB         145,133,122,147,139,160
	DB         190,0,0,0,0
	DB         0,0,0,0,155,133          ;S6 A3 TILT (with say/m5)    js
	DB        FFH   ;end
;
Tbl3_M338:
	DB         1               ;motor delay between steps
	DB         145,165,0,0,0,0,0,0,0
	DB         0,0,0,0,0,0,133    ;S7 A3/S7 A4 TILT (with say/m5) js
	DB        FFH   ;end
;
;;; page 284 end
;;; page 285 start XXX; FURBY27.INC page 160
Tbl3_M339:
	DB        1              ;motor delay between steps
	DB        145, 165,0,0,0,0,0,0,0
	DB        0,0,0,0,0,0,190,133,155,133      ;S8 A3/S8 A4 TILT js
	DB       FFH   ;end
;
Tbl3_M340:
	DB           1              ;motor delay between steps
	DB           0,0,0,110,0,0
	DB           115,0,0,0,0,0,0,133      ;S9 A3/S9 A4 TILT (with say/m9) js
	DB      FFH     ;end
;
Tbl3_M341:
	DB         10               ;motor delay between steps
	DB         165,0,0,0,0,0,0,0,0
	DB         0,0,190,180,190,133     ;S10 A3/S10 A4 TILT (with say/ml6)js
	DB      FFH     ;end
;
Tbl3_M342:
	DB           1               ;motor delay between steps
	DB           143,118,0,0,0,0,0,133    ;S11 A3/S15 A4 TILT (with say/m2&34)js
	DB           FFH       ;end
;
Tbl3_M343:
	DB          1              ;motor delay between steps
	DB          145,150,145,160,133          ;S12 A3 TILT (with say/m5) js
	DB       FFH     ;end
;
Tbl3_M344:
	DB          10               ;motor delay between steps
	DB          148,155,0,0,0,0,138,148,155
	DB          0,0,0,0,133,125,120,115,133     ;S16 A3 TILT (with say/m5)js
	DB       FFH     ;end
;
Tbl3_M345:
	DB          1              ;motor delay between steps
	DB          155,0,0,120,0,0,0,0,133      ;S3 A4 TILT (with say/m26) js
	DB       FFH     ;end
;
Tbl3_M346:
	DB        1               ;motor delay between steps
	DB        145,165,0,0,0,0,0,0,0,0,0,0,133
	DB        120,133,145,125,0,0,0
	DB        133,115,0,0,0,133        ;S5 A4 TILT js
	DB       FFH   ;end
;
Tbl3_M347:
	DB       10           ;motor delay between steps
	DB        115,133,120,160
	DB        0,0,0,0,0,190,0,0,0,0
	DB        0,0,0,0,0,0,0,0,155,133     ;S6 A4 TILT (with say/m5) js
	DB       FFH   ;end
;
Tbl3_M348:
;;; page 285 end
;;; page 286 start XXX; FURBY27.INC page 161
	DB       1               ;motor delay between steps
	DB       120,133,115,133,155
	DB       0,0,0,0,0,0,133        ;S11 A4 TILT (with say/m2) js
	DB        FFH   ;end
;
Tbl3_M349:
	DB         1               ;motor delay between steps
	DB         145,155,115,133           ;S13 A4 TILT (with say/m5) js
	DB        FFH   ;end
;
Tbl3_M350:
	DB         5               ;motor delay between steps
	DB         145,158,0,0,0,0,138,147,155
	DB         0,0,0,0,0,0,133
	DB         125,120,115,133      ;S16 A4 TILT (with say/m5l js
	DB        FFH   ;end
;
;END TILT
;END GEORGE
;GEORGE
;IR 07/09/98
Tbl3_M351:
	DB            20               ;motor delay between steps SGTEST
	DB            120,100,133      ;seq1,seq2,seq3,seq4 IR age 1
	DB            FFh
Tbl3_M352:
	DB            46                 ;motor delay between steps SGTEST
	DB            115,100,75,133        ;seq5  ir age 1
	DB            FFh

; DANGER
Tbl3_M353:
	DB           30                 ;motor delay between steps
	DB           115,130,100,70     ;SEQ6 (DANCE,WAH) ir AGE1
	DB        FFh
;
Tbl3_M354:
	DB           1               ;motor delay between steps
	DB           133,145,155,190,133,155,175,145,133  ;SEQ6 (DO DO DO) ir AGE1
	DB           FFh
Tbl3_M355:
	DB         8              ;motor delay between steps
	DB         145,115,145,133,145,115,145,133,0,0,0,0,0
	DB         125,110,133,0,160,0,0,0,133
	DB        FFH   ;end
Tbl3_M356:
	DB           1                ;motor delay between steps
	DB           0
	DB           FFh                   ;empty space
Tbl3_M357:
	DB           1              ;motor delay between steps
	DB           120,115,110,105,100,80,100,120,115,100,45,133      ;seq8 ir age1
	DB        FFh
Tbl3_M358:
	DB        10            ;motor delay between steps
	DB           120,115,100,80,133,145,160,133          ;seq9 ir age1
	DB        FFh
Tbl3_M359:
;;; page 286 end
;;; page 287 start XXX; FURBY27.INC page 162
	DB         1              ;motor delay between steps
	DB         115,133,140,145,133,160,180
	DB         173,167,160,180,173,167,160,140,145,133        ;seq10,11 ir age1
	DB      FFh
Tbl3_M360:
	DB      1             ;motor delay between steps
	DB         120,107,122,113,100,75,90,80,88,100,0,0,133
	DB         120,107,122,113,100,75,90,80,88,100,0,133
	DB         146,140,155,133                             ;seq12 ir age1
	DB         FFh

Tbl3_M361:
	DB    5               ;motor delay between steps
	DB    115,125,100,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB    0,0,0,0,0,0,0,0,0.0,75,80,85,90,95,100,115
	DB    110,118,100,0,133                           ;seq13,14 ir age1
	DB    FFh

Tbl3_M362:
	DB          10
	DB          160,0,0,190,160,0,0,133,100,0,0,0,133            ;seq15 ir age1
	DB          FFh

; DANGER SLEEP
Tbl3_M363:
	DB         90        ;10              ;motor delay between steps
	DB         85,40,30,85,40,30,0,85,40,30,0,85,40,30,10  ;seq16 ir age1
	DB    FFh
Tbl3_M364:
	DB         1             ;motor delay between steps
	DB         125,113,125,118,105,133   ;seq1,2,3 ir age2
	DB    FFh
Tbl3_M365:
	DB    10              .-motor delay between steps
	DB         125,113.125,118,105,133   ;SEQ4,5 IR AGE2
	DB         FFh


Tbl3_M366:
	DB     10             ;motor delay between steps
	DB         145,155,140,145,142,150,0,0,0,0,0,0,0,133              ;seq6 ir age2
	DB     FFh
Tbl3_M367:
	DB         5               ;motor delay between steps
	DB         10,40,10,40,133,143,140,145,143,145
;DB          133
	DB         100,133
	DB         125,113,133                        ;seq7,8 ir age 2
	DB         125,113,133                        ;seq7,8 ir age 2
	DB         FFh

Tbl3_M368:
	DB      10            ;motor delay between steps
;;; page 287 end
;;; page 288 start XXX; FURBY27.INC page 163
	DB      125,115,105,0,0,133,145,143,155,133,100,133           ;seq9 ir age2
	DB    FFh
;
Tbl3_M369:
	DB      1              ;motor delay between steps
	DB      125,120,115,113,110,105,123,108
;DB      123,115,110,100,100,100,100,0,0,0,0,0,0,0,0,133
;seq1O ir age2

	DB      123,115,110,100,0,0,0,0,0,0,0,0,0,0,0,133   ;seq1O ir age2
	DB      FFH     ;end
;
Tbl3_M370:
	DB      1              ;motor delay between steps
	DB      125,119,113,120,113,140,150,133                 ;seq11 ir age2
	DB   FFH    ;end
;
Tbl3_M371:
	DB      1              ;motor delay between steps
	DB      150,0,0,0,100,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB      115,90,110,100,133                  ;seq13,14 ir age2
	DB    FFH  ;end
;
Tbl3_M372:
	DB      43              ;motor delay between steps
	DB      100,0,0,150,0,0,100,0,0,0,0,133          ;seq15 ir age2
	DB      FFH     ;end
; DANGER SLEEP
Tbl3_M373:
	DB      90              ;motor delay between steps
	DB      85,40,30,85,40,30,85,40,30,10      ;seq16 ir age2
	DB    FFH   ;end
;
Tbl3_M374:
	DB      1               ;motor delay between steps
	DB      115,145,140,160,133         ;seq1,2,3,4,5 ir age3
	DB    FFH   ;end
;
Tbl3_M375:
	DB      1             ;motor delay between steps
	DB      120,0,0,145,138,150,120,105,133      ;seq6 ir age3
	DB    FFH   ;end
;
Tbl3_M376:
	DB      1              ;motor delay between steps
	DB      115,0,145,155,0,0,136,150,145,190,151,133,150
	DB      145,190,151,0,133     ;seq7,8 ir age3
	DB    FFH   ;end
;
Tbl3_M377:
	DB      1              ;motor delay between steps
	DB      120,123,112,133,143,151,160,133    ;seq9 ir age3
	DB     FFH   ;end
;
Tbl3_M378:
	DB      1              ;motor delay between steps
;;; page 288 end
;;; page 289 start XXX; FURBY27.INC page 164
	DB          120,122,115,125,112,150,0,0,0,133         ;seq11 ir age3
	DB        FFH       ; end
;
Tbl3_M379:
	DB           1              ;motor delay between steps
	DB           115,10,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0
	DB           0,0,0,0,0,0,0,0,0
	DB           145,110,0,0,0,0,0,0,133              ;seq13,14 ir age3
	DB          FFH   ;end
;
Tbl3_M380:
	DB           12            ;motor delay between steps
	DB           117,0,0,0,0,0,0,133,0,0,0,0,0,0,0,100,0,0,0,0,30
	DB           100,0,0,0,0,0,0,0,0,0,0,0,0,0,133        ;seq15 ir age3
	DB          FFH    ;end
;
Tbl3_M381:
	DB           5             ;motor delay between steps
	DB              120,150,110,0,0,0,133               ;seq1,2,3,4,5 ir age4
	DB          FFH     ; end
;
Tbl3_M382:
	DB          10          ;motor delay between steps
	DB           120,110,145,155,100,133                   ;seq6 ir age4
	DB          FFH   ;end
;
Tbl3_M383:
	DB               8              ;motor delay between steps
	DB               145,115,145,133,145,115,145,133,0,0,0,0,0
	DB               125,110,133,0,160,0,0,0,133
	DB              FFH   ;end
;
Tbl4_M384:
	DB                  1              ;motor delay between steps
	DB                  115,133,143,148,136,160,180
	DB                  173,167,160,180,173,167,160,140,145,133      ;seq9 ir age4
	DB              FFH      ;end
;
Tbl4_M385:
	DB                  1               ;motor delay between steps
	DB                  118,0,0,155,0,0,133,0,0,118,0,133,0,0,0,0,110
	DB                  0,0,0,133,120,107,122,113,100,75,90,80,88,100,133
	DB                  FFH     ;end   SAY NUMBERS MODIFIED TO MATCH CORRECT DIALOGUE
;
Tbl4_M386:
	DB               1              ;motor delay between steps
	DB               120,123,112,133,143,151,160,133
	DB              FFH   ;end
;
Tbl4_M387:
	DB                1              ;motor delay between steps
	DB               120,0,0,145,110,145,110,0,0,0,0,0,133
	DB              FFH    ;end
;
Tbl4_M388:
	DB                   1              ;motor delay between steps
	DB                   120,110,133 ;OK                 ;seql4 ir age4
;;; page 289 end
;;; page 290 start XXX; FURBY27.INC page 165
	DB     FFH    ; end
;
Tbl4_M389:
	DB      90              ;motor delay between steps
	DB      150,0,130,0,100,0,133          ; YAWN
	DB     FFH    ;end
; DANGER SLEEP
Tbl4_M390:
	DB      90               ;motor delay between steps
	DB      0,0,0,85,30,0,20,0,85,30,0,20,0,85,30,0,20,0,85,10
	DB      FFH     ;end
;END GEORGE 07/09/98
;END IR

; FURBY SAYS: (LIGHT) DMH
Tbl4_M391:
	DB     10                           ;motor delay between steps
	DB     110,133                      ;LIGHT (furby says)
;	DB      110,120,133                  ;LIGHT (furby says)
	DB    FFH    ; end

;
Tbl4_M392:                                  ; dmh no light
	DB        1                       ;motor delay between steps
	DB        150,0,0,0,115,0,0,0,0,133
	DB       FFH   ;end
;
Tbl4_M393:                                  ; dmh loud sound
	DB        30                      ;motor delay between steps
	DB        150,0,0,0,115,0,0,0,0,133
	DB       FFH    ; end
;
Tbl4_M394:                                   ; LISTEN DMH

	DB        10                        ;motor delay between steps
	DB        140,150,0,0,133
	DB        FFH
;
Tbl4_M395:
	DB       10                ;motor delay between steps
	DB       160,133           ;(ME)
	DB       FFH     ;end
;
Tbl4_M396:
	DB        1               ;motor delay between steps
	DB        120,130,120,133 ;ME ME
	DB       FFH   ; end
;
;
Tbl4_M397:
	DB       1           ;motor delay between steps
	DB        115,130,110,133   ;DO MOH
	DB       FFH   ; end
;
Tbl4_M398:
	DB        1              ;motor delay between steps
	DB        120,130,110,133 ;TOH LOO
	DB       FFH   ;end
;
;
;;; page 290 end
;;; page 291 start XXX; FURBY27.INC page 166
Tbl4_M399:
	DB         1                   ;motor delay between steps
	DB      FFH       ;jend
;
;
Tbl4_M400:
	DB      1                  ;motor delay between steps
	DB      FFH        ;end     ; start diagnostic
;
Tbl4_M401:
	DB      1                  ;motor delay between steps
	DB      FFH        ;end       ; key press beep
;
Tbl4_M402:
	DB      1                  ;motor delay between steps
	DB      FFH        ; end     ; pass beep
;
Tbl4_M403:
	DB      1                  ;motor delay between steps
	DB      FFH        ; end      ; fail beep
;
Tbl4_M404:
	DB      1                  .•motor delay between steps
	DB      FFH        ; end
;
Tbl4_M405:
	DB      1           ;motor delay between steps
	DB      10,200,10,134   ; motor cal
	DB      FFH   ;end
;
Tbl4_M406:
	DB      1                  ;motor delay between steps
	DB      120                     ; feed 1
	DB      FFH        ;end
;
Tbl4_M407:
	DB        255                    ;motor delay between steps
	DB        0,134                  ; feed 2
	DB    FFH     ;end
;
Tbl4_M408:
	DB      1                  ;motor delay between steps
	DB         30                   ; light pass
	DB      FFH        ;end
;
Tbl4_M409:
	DB      1                  ;motor delay between steps
	DB        160                     ; sound pass
	DB      FFH   ;end
;
Tbl4_M410:
	DB      1                  ;motoe delay between steps
	DB         10                    ; sleep
	DB      FFH        ;end
;
Tbl4_M411:                          ; PEEK-BOO (HIDE AND SEEK) DHM
	DB         20              ;MOTOR DELAY BETWEEN STEPS
	DB         155.133,0,0,147,133
	DB         FFh
;
;;; page 291 end
;;; page 292 start XXX; FURBY27.INC page 167
Tbl4_M412:                         ; feed dmh
	DB      1           ;motor delay between steps
	DB       165,0,0,0,0,0.0.150,0,0,165,0,0,0,0,0,0,150 ; (AAAAH)
	DB       0,0,165,0,0,0,0,0,0,133 ;(AAAAH)
	DB      FFH   ;end
;

;	DB      FFH        ;end
;
Tbl4_M413:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M414:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M415:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M416:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M417:
	DB          1                    ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M418:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M419:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M420:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M421:
	DB      1                   ;motor delay between steps
	DB      FFH       ;end
;
Tbl4_M422:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M423:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M424:
	DB      1                   ;motor delay between steps
	DB      FFH        ;end
;
Tbl4_M425:
	DB      1                   ;motor delay between steps
;;; page 292 end
;;; page 293 start XXX; FURBY27.INC page 168
	DB      FFH   ;end
;
Tbl4_M426:
	DB       1              ;motor delay between steps
	DB       FFH   ;end
;
Tbl4_M427:
	DB       1              ;motor delay between steps
	DB       FFH   ; end
;
Tbl4_M428:
	DB       1              ;motor delay between steps
	DB       FFH   ; end
;
Tbl4_M429:
	DB       1              ;motor delay between steps
	DB       FFH   ; end
;
Tbl4_M430:
	DB       1              ;motor delay between steps
	DB       FFH   ;end
;
Tbl4_M431:
;
Tbl4_M432:
;
Tbl4_M433:
;
Tbl4_M434:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ; end

Tbl4_M435:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ;end
;
Tbl4_M436:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ;end
;
Tbl4_M437:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ;end
;
Tbl4_M438:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ;end
;
Tbl4_M439:
	DB       1              ;motor delay between steps
	DB       0
	DB       FFH   ;end
;
Tbl4_M440:
	DB       1              ;motor delay between steps
;;; page 293 end
;;; page 294 start XXX; FURBY27.INC page 169
	DB      0
	DB      FFH   ; emd
;
Tbl4_M441:
;
Tbl4_M442:
;
Tbl4_M443:
;
Tbl4_M444:
;
Tbl4_M445:
;
Tbl4_M446:
;
Tbl4_M447:
;
Tbl4_M448:
;
Tbl4_M449:
;
Tbl4_M450:
;
Tbl4_M451:
;
Tbl4_M452:
;
Tbl4_M453:
;
Tbl4_M454:
;
Tbl4_M455:
;
Tbl4_M456:
;
Tbl4_M457:
;
Tbl4_M458:
;
Tbl4_M459:
;
Tbl4_M460:
;
Tbl4_M461:
;
Tbl4_M462:
;
Tbl4_M463:
;
Tbl4_M464:
;
Tbl4_M465:
;
Tbl4_M466:
;
Tbl4_M467:
;
Tbl4_M468:
;
Tbl4_M469:
;
;;; page 294 end
;;; page 295 start XXX; FURBY27.INC page 170
;
Tbl4_M470:
;
Tbl4_M471:
;
Tbl4_M472:
;
Tbl4_M473:
;
Tbl4_M474:
;
Tbl4_M475:
;
Tbl4_M476:
;
Tbl4_M477:
;
Tbl4_M478:
;
Tbl4_M479:
;
Tbl4_M480:
;
Tbl4_M481:
;
Tbl4_M482:
;
Tbl4_M483:
;
Tbl4_M484:
;
Tbl4_M485:
;
Tbl4_M486:
;
Tbl4_M487:
;
Tbl4_M488:
;
Tbl4_M489:
;
Tbl4_M490:
;
Tbl4_M491:
;
Tbl4_M492:
;
Tbl4_M493:
;
Tbl4_M494:
;
Tbl4_M495:
;
Tbl4_M496:
;
Tbl4_M497:
;
Tbl4_M498:
;
Tbl4_M499:
;;; page 295 end
;;; page 296 start XXX; FURBY27.INC page 171
;
Tbl4_M500:
;
Tbl4_M501:
;
Tbl4_M502:
;
Tbl4_M503:
;
Tbl4_M504:
;
Tbl4_M505:
;
Tbl4_M506:
;
Tbl4_M507:
;
Tbl4_M508:
;
Tbl4_M509:
;
Tbl4_M510:
	DB     10           ;motor delay between steps
	DB     10,200,134   ;
	DB     FFH          ;end
;
Tbl4_M511:
	DB     10           ;motor delay between steps
	DB     10,200,10    ;
	DB     FFH          ;end
;;; page 296 end

