n = 1;  pi = 2*acos(0.0)
do k = 1,3          ! (1)
  n = n*2           ! n:確定
  write(*,'(a5,i2)') 'n =',n
  write(*,'(a5,a15,a11,a17)') &
    'x','cos(x)','uhen','cos(x)-uhen'
  do j = 0,10       ! (2)
    x = j*pi/10     ! x:確定

    p = 1; uhen = p
    do i = 1,n      ! (3)
      p = p*(-x*x)/((2*i)*(2*i-1))
      uhen = uhen+p
    end do
    c = cos(x)
    write(*,'(3f12.6,e15.5)') x,c,uhen,c-uhen

  end do
end do
end

