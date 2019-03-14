open (10, file='rei3-2.dat')  ! 10の部分は読み込むとき
!read(*,*)n    ! n:人数
read(10,*) n
summ = 0; sumw = 0
write(*,*)'Men  Women'
do i=1,n
!  read (*,*) hm,hw
  read (10,*) hm,hw
  write(*,*) hm,hw
  summ = summ+hm
  sumw = sumw+hw
end do
close (10)
write(*,*) 'Hm_av. =', summ/n
write(*,*) 'Hw_av. =', sumw/n
end

