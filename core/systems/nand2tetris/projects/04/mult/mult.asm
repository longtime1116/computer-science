// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.


// R10: i(0, 1, ..., R2-1)

(PRE)
  @R2
  M=0
  @R10
  M=0

(LOOP)
  // if (@i == R2) goto END
  @R10
  D=M
  @R1
  D=D-M
  @POST
  D;JEQ

  // R2にR0を足す
  @R0
  D=M
  @R2
  M=D+M

  // i++
  @R10
  M=M+1

  @LOOP
  0;JMP

(POST)
  // 掃除
  @R10
  M=0

(END)
  @END
  0;JMP

