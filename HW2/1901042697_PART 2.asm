load R0,189 	
load R1,186   ;numbers
load R2,187
load R3,177

load R4,255	 ;to calculate complement	
load R8,1

load R5,1
load R6,181 ;to loop and adress
load R7,2

nxt :load R9,[R5] ;to keep mind the numbers
	addi R5,R5,R7;change adress
	addi R6,R6,R7 ;increase R6 loop
	xor R9,R9,R4 ;to calculate 1's complement				
	jmpEQ R6=R0,twocomp;check the loop
	move RF,R9	;-- TO WRITE NUMBERS --
	jmp nxt ;for next number 
	
twocomp:addi R9,R9,R8 ;to calculate 2's complement
	  move RF,R9

son :	halt ;to end 
