integer tanka
write(*,*)'Tanka, Zei_ritsu ?'
read (*,*) tanka, zei_ritsu
write(*,*)'Tanka =',tanka,' Zei_ritsu =',zei_ritsu
write(*,*)'Kosuu  Kakaku  Neden'

do kosuu=1,10
  kakaku = tanka*kosuu
  nedan  = kakaku*(1+zei_ritsu)+0.5
  write(*,*)kosuu,kakaku,nedan
end do

end
