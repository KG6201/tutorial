m=1;p=1
pi=acos(-1.0)
do n=1,13
  m=m*n
  p=p*n
  r=sqrt(2*pi*n)*n**real(n)*exp(-real(n))
  write(*,10)n,m,p,(p-m)/p,r,(p-r)/p
10 format(i2,i10,4e15.7)
end do
end

