# Klasa obsługująca wszystkie działania na wielomianie
class Wielomian
  attr_accessor :bis, :newt, :bp, :np, :epsilon
  def initialize(a, c)
    @epsilon = a
    @limit = 10_000
    @przedzial = c
    @bis = nil
    @newt = nil
    @bp = nil
    @np = nil
  end

  def f(x)
    x**5 + x - 10
  end

  def fprime(x)
    5 * x**4 + 1
  end

  def bisekcja
    @przebieg = 0
    1.upto(@limit) do |k|
      @przebieg = k
      x = (@przedzial[0] + @przedzial[1]) / 2
      wybierz_przedzial(x)
      next unless f(x) == 0 || (@przedzial[1] - @przedzial[0]).abs / @przedzial[0].abs < @epsilon
      @bis = x
      @bp = @przebieg
      break
    end
    puts 'METODA BISEKCJI: Osiągnięto limit powtórzeń. Podaj inny przedział, lub dokładność' if @przebieg == @limit
  end

  def wybierz_przedzial(x)
    if f(x) > 0
      @przedzial[1] = x if f(x) > 0
    else
      @przedzial[0] = x
    end
  end

  def newton_raphson
    x0 = 1.0
    x1 = 1.0
    @przebieg = 0
    1.upto(@limit) do |k|
      @przebieg = k
      y = f(x0)
      yprime = fprime(x0)
      x1 = x0 - y / yprime
      if (x1 - x0).abs / x1.abs < @epsilon
        @newt = x1
        @np = @przebieg
        break
      end
      x0 = x1
    end
    puts 'METODA NEWTONA: Osiągnięto limit powtórzeń. Podaj inną dokładność' if @przebieg == @limit
  end
end
# Klasa obługująca porozumiewanie się z użytkownikiem
class Menu
  def start
    puts 'Obliczany przykład: x^5 + x - 10'
    a = podaj_dokladnosc
    c = przedzial?
    wielomian = Wielomian.new(a, c)
    count(wielomian)
    puts 'Obliczenia metodą bisekcji'
    puts "x = #{wielomian.bis}, ilość kroków: #{wielomian.bp}"
    puts 'Obliczenia metodą Newtona'
    puts "x = #{wielomian.newt}, ilosć kroków: #{wielomian.np}"
    restart?
  end

  def count(obj)
    obj.newton_raphson
    obj.bisekcja
    return unless (obj.bis - obj.newt).abs > 0.1
    puts 'Podano błędny przedział, zaczynam od początku'
    start
  end

  def podaj_dokladnosc
    puts 'Podaj dokładność obliczeń 0 < e < 1'
    print 'e = '
    dokladnosc = gets.chomp.to_f
    until dokladnosc < 1.0 && dokladnosc > 0.0
      print "Wprowadzono niepoprawną dokładność, ponów:\ne = "
      dokladnosc = gets.chomp.to_f
    end
    dokladnosc
  end

  def podaj_przedzial
    print "Podaj przedział do metody bisekcji\nDolna granica: "
    d = gets.chomp.to_f
    print 'Górna granica: '
    g = gets.chomp.to_f
    przedzial = sprawdz_przedzial(d, g)
    przedzial
  end

  def sprawdz_przedzial(d, g)
    until d < 0 && g > 0
      puts 'Końce przedziału muszą być różnych znaków'
      puts 'Dolna granica przedziału musi być mniejsza od górnej' if d > g
      print "Podaj przedział ponownie\nDolna granica: "
      d = gets.chomp.to_f
      print 'Górna granica: '
      g = gets.chomp.to_f
    end
    [d, g]
  end

  def przedzial?
    puts 'Domyślny przedział dla metody bisekcji wynosi [-2,2], wczytać inny?(t/n)'
    ans = gets.chomp.downcase until %w(t n tak nie).include? ans
    c = podaj_przedzial if %w(t tak).include? ans
    c = [-2.0, 2.0] if %w(n nie).include? ans
    c
  end

  def restart?
    puts 'Powtórzyć dla nowych danych?(t/n)'
    ans = gets.chomp.downcase until %w(t n tak nie).include? ans
    start if %w(t tak).include? ans
  end
end
