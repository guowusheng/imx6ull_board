.global _start    //全局标号

_start:
//进入SVC模式
  mrs r0, cpsr
  bic r0, r0, #0x1f   //将r0的低５位清零　也就是cpsr的M0~M4
  orr r0, r0, #0x13   //r0或上０x１３　使用SVC模式
  msr cpsr, r0        //将数据写入cpsr

  ldr sp, =0x80200000 //设置堆栈指针
  b main
  