.text
__start:
.globl __start
      li a0, 4
      la a1, str
      ecall #вызов строки перед вводом числа
      
      li a0, 5
      ecall #ввод числа
      
      add t0, a0, zero
      la t1, numfib
      sw t0, 0(t1)
      
      la a3, numfib
      lw a3, 0(a3) #numfib = 8
      
      
      
      li a7, 2 #fib(1)=1 and fib(2)=1
      
      li a4, 1 #first = 1
      li a5, 1 #last = 1
      
      li a6, 0 #ans = 0
      
      li a2, 2
      
      bge zero, a3, finish #if numfib <= 0 go to finish
      
      bgeu a7, a3, case1 #if numfib <= 2 go to case1 
      
      jal zero, loop_check
      loop:
          add a6, a4, a5 # ans = first + last
          
          #сделать переприсваивание
          add t0, a6, zero # t0 = ans
          add t1, a5, zero # t1 = last
          add a4, t1, zero # first = last
          add a5, t0, zero # last = ans
          
          addi a2, a2, 1 #a2+=1 
          
          bgeu a2, a3, finish # if (a2 >= a3) go to loop_exit
        
      loop_check:
          bltu a2 , a3, loop # if (a2 < a3) go to loop 
          

case1:
    addi a6, a6, 1 # a6+=1
    jal zero, finish
          
finish:
    li a0, 1 #x10
    addi a1, a6, 0 #a1 = ans
    ecall
    li a0, 10 #x10
    ecall #остановка симулятора при x10=10
    
.data
numfib:
    .word 0
    
.rodata
str:
    .string "Please enter the number of row Fibonacci: "
