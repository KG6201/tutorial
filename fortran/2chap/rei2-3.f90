      !  Free Source Form
write(*,*)'w1[kg], w2[g],x[cm] ?'
read (*,*) w1,w2,x
write(*,*)'w1=',w1,'   w2=',w2, &
      '  x =',x
w2=w2/1000
F =6.67e-11*w1*w2/(x/100)**2
write(*,*)'F =',F,'   w2=',w2
end

