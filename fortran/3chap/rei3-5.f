      write(*,10)
      read (*, *)n
      do i=1,n
        read(*,*)k1,k2
        kav=real(k1+k2)/2+0.5   ! kav:2科目の平均

        if (i==1)then
          mx=kav    ! mx:最高点
          mn=kav    ! mn:最低点
        end if
        if (kav>mx) mx=kav
        if (kav<mn) mn=kav

        if (kav>=80) then
          write(*,20)k1,k2,kav, 'A' ! 80 点以上
          go to 100
        end if

        if (kav>=70) then
          write(*,20)k1,k2,kav, 'B' ! 70 点以上
         else
          write(*,20)k1,k2,kav, 'C' ! 70 点未満
        end if
 100  end do
      write(*,30)'Saikou-ten =', mx
      write(*,30)'Saitei-ten =', mn
  10  format(' Kamoku-1  Kamoku-2   Heikin   Hantei')
  20  format(' ',i5,2(4x,i6),8x,a)
  30  format(10x,a,i4)
      end

