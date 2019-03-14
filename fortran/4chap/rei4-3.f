      integer    size
      parameter (size=24)
      integer   Bin(size)     ! 配列宣言
              ! Bin : Binary
      read(*, *) x0
      x = x0
      do n=1,size
        x = x*2
        Bin(n) = x
        x = x-Bin(n)
        if (x.le.0) go to 100
      end do
      n = n-1
 100  write(*,10) x0,n
      write(*,20)(Bin(j),j=1,n)   ! do系反復
  10  format('  x =',f10.7,5x,'n =',i3)
  20  format('  0.',(' ',16i2))
!  20  format(' ',16i2)
      end

