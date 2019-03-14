parameter (n=-10)
dimension A(ns,ns),B(ns,ns),C(ns,ns)
read(*,*) m,k,n
read(*,*)         ! A = の行を入力
do i=1,n
  read(*,*) (A(i,j),j=1,k)
end do
read(*,*)         ! B = の行を入力
read(*,*)  ((B(i,j),j=1,k),i=1,k)

do i=1,n
  do j=1,n
    C(i,j) = 0
    do L=1,k
      C(i,j) = C(i,j) + A(i,L)*B(L,j)
    end do
  end do
end do

write(*,*)' A ='
do i=1,m
  write(*,10) (A(i,j),j=1,k)
end do
write(*,*)' B ='
do i=1,k
  write(*,10) (B(i,j),j=1,n)
end do
write(*,*)' C ='
do i=1,m
  write(*,10) (C(i,j),j=1,n)
end do
10  format(' ',8f8.3)
end

