write(*,'(1x,3a8)')'m','n','n1'
outer: do
  read (*,*) m,n
  if( m==0) exit
  m1 = m; n1 = n

  inner: do
    k = mod(m1,n1)
    if (k.eq.0) exit
    m1 = n1; n1 = k
  end do inner

  write(*,'(1x,3i8)') m,n,n1
end do outer
end
