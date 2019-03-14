      rad = 4*atan(1.0)/180   ! rad:pi/180
      write(*,10)
      do 100 i=-10,10,2       ! 文番号do文
                    ! 2:増分値
        x = real(i)/10
        k = i*18;   y = k*rad
        write(*,20)i,x,exp(x),k,sin(y)
 100  continue                ! do端末文
  10  format('    i',5x,'x',6x,'exp(x)',
     +   6x,'k',7x,'sin(k)')
  20  format(' ',i4,f7.2,e13.5,i6,e14.5)
      end
