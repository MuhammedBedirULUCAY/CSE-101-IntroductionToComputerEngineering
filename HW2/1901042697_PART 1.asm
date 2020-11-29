load R0,189 ;have determineted number 1
load R1,171;I have determined the number 2
load R5,255;1111,1111 xor 
load R2,1;to convert 1'complement to 2'complement
 
 xor R0,R5,R0;calculte the 1'complement of number 1
 xor R1,R5,R1;calculte the 1'complement of number 2

;addi R0,R0,R2 this is don't use because R0 and R1 are together just one number
addi R1,R1,R2 ;add 1 to make it 2'complement
	
move RF,R0;writing
move RF,R1;writing

halt;close the program
