      dimension  k(0:5), A(5)
      write(*,*)'  ',('-', i=1,35)
      read (*,*)         (k(i), i=0,5)
      write(*,'(1x,6i6)')(k(i), i=0,5)
      read (*,*) A
      write(*,'(1x,6f6.1)') A
      write(*,10)   (k(i),A(i), i=1,5)
  10  format((' ',3(i6,f6.1)))
      write(*,*)'  ',('-', i=1,35)
      end

