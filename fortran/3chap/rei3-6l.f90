read(*,*)n
do i=1,n
  read(*,*)k1,k2
  kav=(k1+k2)/2.0+0.5

  select case (kav>=60)
    case (.true.)
      write(*,10) k1,k2,kav,'Goukaku'
    case (.false.)
      write(*,10) k1,k2,kav,'FuGoukaku'
  end select

end do
10  format(3i6,a12)
end
