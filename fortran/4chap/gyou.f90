parameter (m=3,n=4)
dimension  k(m,n),d(m,n)
do i=1,n
  read(*,*) (k(i,j), j=1,n)
end do
do i=1,n
  do j=1,n
    d(i,j) = 1/real(k(i,j))
  end do
end do
do i=1,n
  write(*,'(1x,5f9.5)')(d(i,j),j=1,n)
end do
end

