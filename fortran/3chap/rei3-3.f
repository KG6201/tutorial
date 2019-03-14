      rad = 4*atan(1.0)/180   ! rad:pi/180
      do 100 i=-10,10,2       ! 文番号do文
                    ! 2:増分値
        x = i/10.0
        k = i*18
        y = k*rad
       ! write(*,*)i,x,exp(x),k,sin(y)
       ! write (*,20) i,k
        write(*,20)i,k,x,exp(10*x)
!  20    format(i4,i6)
!  20    format(i4,i6,f7.2,f8.4)
  20    format(i4,i6,f7.2,e13.5)
 100  continue                ! do端末文
      end
