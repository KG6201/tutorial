parameter  (ksize=5)        ! parameter 文
dimension k(0;ksize)        ! 配列宣言
data  k /3,7,15.1,292,1/    ! data文

pi = 4*atan(1.0)
write(*,'(a3,a9,a16)') 'n','p','p-pi'
do n=0,ksize
  p = k(n)
  do i=n-1,0,-1
    p = k(i)+1/p
  end do
  write(*,'(1x,i2,f13.6,e15.4)') n,p,p-pi
end do
end

