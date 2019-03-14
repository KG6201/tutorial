read(*,*)n
do i=1,n
  read(*,*)k1,k2
  kav=(k1+k2)/2.0+0.5

  select case (kav)
    case (80:)    ! 80 以上
      write(*,10) k1,k2,kav,'A'
    case (70:79)  ! 70 以上 79 以下
      write(*,10) k1,k2,kav,'B'
    case (60:69)  ! 60 以上 69 以下
      write(*,10) k1,k2,kav,'C'
    case default
      write(*,10) k1,k2,kav,'D'
  end select

end do
10  format(3i6,a5)
end
