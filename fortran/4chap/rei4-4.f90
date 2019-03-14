parameter   (n=5)
dimension  A(n,n)
data (A(1,j),j=1,n)/1.1, 1.2, 1.3, 1.4, 1.5/

do i=2,n
  A(i,1) = A(i-1,n)
  do j=2,n
    A(i,j) = A(i-1,j-1)  
  end do
end do
write(*,'(a,i2)')' n =',n
write(*,'(1x,5f5.1)')((A(i,j),j=1,n), i=1,n)
end

