.text
main:
.globl main
      # в a0 - номер члена фибоначчи
      
      li a0, 4 #x10 = 4 (ecall code)
      la a1, str
      ecall #вызов строки перед вводом числа
      
      li a0, 5 #(сохраняет число в a0)
      ecall #ввод числа

      
      call fibonachi
      #в а1 - ответ
      
      
      li a0, 1 #x10 = 1 (вывод результата)
      ecall
      
      li a0, 17 # ecall code
      li a1, 0  # status code value
      ecall #завершение работы программы с кодом завершения
      
      
.rodata
str:
    .string "Please enter the number of row Fibonacci: "
