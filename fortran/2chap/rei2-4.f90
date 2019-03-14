read (*,*) a,b,c
write(*,*)"a =",a, "  b =",b &
      , " c =",c
sq = sqrt(b*b-4*a*c)  !平方根
de = 2*a    ! de:denominator
x1 = (-b+sq)/de
x2 = -(b+sq)/de
write(*,*)"x1=",x1, "   x2=",x2
end

