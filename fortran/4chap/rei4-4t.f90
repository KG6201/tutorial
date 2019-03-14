parameter   (n=4)
dimension  m(2,3), d(n,n)

data m /11,21, 12,22, 13,23/
write(*,*) ' m ='
do i=1,2
  write(*,'(1x,5i5)')(m(i,j),j=1,3)
end do

data ((d(i,j), j=1,n),  i=1,n) /10*1.0/
data ((d(i,j), j=1,i-1),i=2,n) / 6*0.0/
write(*,*) ' d ='
write(*,'(1x,4f5.1)')((d(i,j),j=1,n),i=1,n)
end

