abstract sig Osoba { 
	pracuje: Zawod,
	plec: String 
}{
  plec = "m" || plec = "k"
}
one sig Anderson, Crowford, Smith, Evans, Davis extends Osoba {}

abstract sig Zawod {
}
one sig  Zaopatrzeniowiec, Kasjer, Ekspedient, Pietrowy, Menadzer extends Zawod {}

fact{
	Anderson.plec = "k"
	Crowford.plec = "k"
	Smith.plec = "m"
	Evans.plec = "m"
	Davis.plec = "m"
	-- 1 zawod wykonywany przez 1 osobe
	all disj o1, o2: Osoba | o1.pracuje != o2.pracuje

	-- kropka 1
	-- kasjer i menadzer sa tej samej plci, bo mieszkali razem w internacie
	one o1, o2: Osoba | o1.pracuje = Kasjer && o2.pracuje = Menadzer && o1.plec = o2.plec

	-- kropka 2
	-- pan Smith nie jest kawalerem
	Smith.pracuje != Zaopatrzeniowiec
	-- zaopatrzeniowiec jest mezczyzna
	one o1: Osoba | o1.pracuje = Zaopatrzeniowiec && o1.plec = "m"

	-- kropka 3
	-- Davis i Anderson nie moga wziac slubu bo lacza ich jedynie stosunki sluzbowe
	not ((Davis.pracuje = Kasjer && Anderson.pracuje = Ekspedient) || (Davis.pracuje = Ekspedient && Anderson.pracuje = Kasjer))

	-- kropka 4
	-- nie moze byc swoim wlasnym menadzerem
	Smith.pracuje != Menadzer	

	-- kropka 5
	-- slub miedzy osobami roznych plci // dana zbedna
	--	one o1, o2: Osoba | o1.pracuje = Kasjer && o2.pracuje = Ekspedient &&  o1.plec != o2.plec 
	-- nie moze byc swiadkiem na wlasnym slubie
	Evans.pracuje != Kasjer && Evans.pracuje != Ekspedient
	-- pan Smith posiada juz zone
	Smith.pracuje != Kasjer && Smith.pracuje != Ekspedient
}


pred show() {}

run show

	
	
