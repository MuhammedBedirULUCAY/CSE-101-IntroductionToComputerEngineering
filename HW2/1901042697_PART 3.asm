load R0,16
load R1,1
load R2,112
load R7,112
load R9,2

;fonction which put the value in the adress

adr:	
	store R8,[R2] ;value
	addi R2,R2,R1 ;change adress
	addi R8,R8,R9 ;change value
	addi R6,R6,R1 ;increase loop
	jmpEQ R6=R0,Topla ;when the loop is finish the fonction to go
	jmp adr ;loop

;the fonction addition and average

Topla:
	load R4,[R7] ;the value in R7 send to R3 
	addi R7,R7,R1 ;change adress	
	addi R5,R5,R1 ;increase loop
	addi R3,R4,R3 ;to store the sum of values
	jmpEQ R5=R0,avg ;the place when the loop is finish
	jmp Topla ;loop


avg : ror R3,4 ;to divide 16 (2^4)
	move R0,R3 ; send 0000 

	halt ;to finish the program