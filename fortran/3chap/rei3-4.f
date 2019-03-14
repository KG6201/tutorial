      write(*,10)'m','','n1'
 100  read (*, *) m,n

      if (m.eq.0) stop    ! if文

      m1 = m
      n1 = n
 200  k  = mod(m1,n1)

      if (k.ne.0) then    ! if構文
        m1 = n1
        n1 = k
        go to 200
      end if

      write(*,20) m,n,n1
      go to 100
  10  format(' ',3a8)
  20  format(' ',3i8)
      end
