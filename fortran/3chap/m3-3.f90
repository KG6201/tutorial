!xsum = 0
!do 100 x = 0.1, 1.0, 0.1
!  write(*,10) x, 1/x
!  xsum = xsum+x
!100 end do
!write(*,'(f12.7)')
xsum = 0
do 200 n = 1, 10
  x=real(n)/10
  write(*,10) x, 1/x
  xsum = xsum+x
200 end do
10 format(f10.7, e15.7)
end

