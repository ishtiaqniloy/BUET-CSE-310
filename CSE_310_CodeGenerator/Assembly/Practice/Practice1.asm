TITLE PRACTICE PROBLEM 8

.MODEL SMALL    
    
   
.DATA
   X DB '?'
   Y DB '?'
   Z DW '?'
       
        
.CODE

MAIN PROC
        MOV DX, @DATA
        MOV DS, DX
        
        MOV AH,1
        INT 21h
        MOV X, AL
        
        MOV AH,1
        INT 21h
        MOV Y, AL
             
        MOV AH,1
        INT 21h
        MOV BL, AL
        MOV BH, 0
        MOV Z, BX
        
        MOV AH, 2
        MOV DX, Z
        INT 21h
        
        MOV BH, X
        ADD BH, Y
        SUB BH, '0'
        SUB BH, '0'
        
        MOV BL, X
        SUB BL, Y
        
        MOV Z, BX
         
        
        
        
            
        MOV AH, 4Ch ;RETURN
        INT 21h
        
         
        
        
    MAIN ENDP

END MAIN





