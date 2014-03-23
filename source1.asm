.sample program for SIC/XE architecture
.
.This program should assemble correctly
.
prog    start   $1000    .start of sample program
        lds     #3
        ldt     #300
        ldx     #0
addlf   lda     alpha,x   .loop control     
        add     beta,x
        sta     gamma,x                         
        addr    s,x
        compr   x,t 
        jlt     addlp 
testthis  
        .
. storage allocation section        
alpha   resw    100
beta    resw    100
gamma   resw    100   
        
        end     source1    .end of sample program
