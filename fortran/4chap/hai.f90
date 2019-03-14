integer,parameter::m=2, n=3
real,dimension(n)::A_0=(/2.0,-4.0,5.0/)
                        !   初期値式
real,dimension(m,n)::A,B,C,E
real,dimension(:)  ::D(m)

A(1,1:n)=A_0;  A(2,*)=-A_0
write(*,10)'A =',((A(i,j),j=1,n),i=1,m)
B = 2.0                  ! 全要素を2に
write(*,10)'B =',((B(i,j),j=1,n),i=1,m)
C = A*B                  ! 要素ごとの積
write(*,10)'C =',((C(i,j),j=1,n),i=1,m)
D = A(:,n)+C(1,2:n)      ! 部分配列の和
write(*,10)'D =',(D(i),i=1,m)

where (A>0)              ! where構文
  E = log(A)
 elsewhere
  E = A
end where
write(*,10)'E =',((E(i,j),j=1,n),i=1,m)
10  format(' ',a/(3f10.4))
end

