dimension H(50)	! 配列宣言
read(*,*)n
sumH = 0			! sumH : 身長の和
do i=1,n
	read(*,*) H(i)
	sumH = sumH+H(i)
end do
ave = sumH/n
write(*,'(3x,a,f7.2)') 'Ave. =',ave

write(*,'(6x,a)') 'H		H(i)-Ave'
do i=1,n
	write(*,'(2f9.2)') H(i),H(i)-ave
end do
end
