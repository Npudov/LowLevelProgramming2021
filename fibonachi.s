.text
fibonachi:
.globl fibonachi
      
      add t0, a0, zero #t0 = a0(там хранится входное число)
      la t1, numfib
      sw t0, 0(t1)
      
      la a3, numfib
      lw a3, 0(a3) #numfib = 8
      
      
      
      li a7, 2 #fib(1)=1 and fib(2)=1
      
      li a4, 1 #first = 1
      li a5, 1 #last = 1
      
      li a6, 0 #ans = 0
      
      li a2, 2 #переменная цикла
      
      bge zero, a3, finish #if 0 >= a3 (numfib <= 0) go to finish
      
      bgeu a7, a3, case1 #if a7 >= a3 (numfib <= 2) go to case1 
      
      jal zero, loop_check
      loop:
          add a6, a4, a5 # ans = first + last
          
          add a4, a5, zero # first = last
          add a5, a6, zero # last = ans
          
          addi a2, a2, 1 #a2+=1
          
          bgeu a2, a3, finish # if (a2 >= a3) go to loop_exit
        
      loop_check:
          bltu a2 , a3, loop # if (a2 < a3) go to loop 
          

case1:
    addi a6, a6, 1 # a6+=1
          
finish:
    addi a1, a6, 0 #a1 = ans
    ret
    
.data
numfib:
    .word 0