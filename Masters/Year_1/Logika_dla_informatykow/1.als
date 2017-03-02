sig Osoba
{
  uscisk: set Osoba,
  partner: Osoba
}

one sig Ola, Marek extends Osoba {}

fact
{
	--nikt nie uściska siebie
  all o:Osoba | not o in o.uscisk
	--nikt nie uściska partnera
  all o:Osoba, o2:Osoba | o in o2.partner implies o not in o2.uscisk
	--partnerzy symetryczne
  partner = ~partner
	--uściski symetryczne
  all o:Osoba, o2:Osoba | o in o2.uscisk implies o2 in o.uscisk
  	--Marek i Ola są partnerami
	Marek.partner in Ola
	--osoba nie jest parnerem z samym sobą
  all o:Osoba | o not in o.partner
	--inna liczba usciskow wszystkich poza Oli
  all disj o,o2:Osoba - Ola | #o.uscisk != #o2.uscisk
}

pred show() {}

run show for exactly 10 Osoba
