# Klasa obslugujaca kostki
class Dice
  attr_reader :color, :symbols
  COLORS = %w(red yellow green)
  def initialize(color)
    @color = color
    @symbols = []
  end

  def add_symbols
    if color == 'red'
      @symbols = %w(shotgun shotgun shotgun runner runner brain)
    elsif color == 'yellow'
      @symbols = %w(brain brain shotgun shotgun runner runner)
    elsif color == 'green'
      @symbols = %w(brain brain brain runner runner shotgun)
    end
  end
end
# Klasa obslugujaca graczy
class Player
  attr_accessor :nick, :score, :brains, :shots, :last_player
  @@last_player = 0
  PLAYERS = []

  def initialize(nick)
    @shots = 0
    @brains = 0
    @nick = nick
    @score = 0
    PLAYERS << self
  end

  def roll_dice
    d = Dice.new(Dice::COLORS.sample)
    d.add_symbols
    d.symbols.sample
  end

  def do_rolling
    puts 'Wykonuje rzut 3 kostkami...'
    3.times do
      r = roll_dice
      if r == 'brain'
        self.brains += 1
        puts 'Wynik rzutu: mózg! :)'
      elsif r == 'shotgun'
        self.shots += 1
        puts 'Wynik rzutu: postrzał! :('
      else
        puts 'Wynik rzutu: uciekinier! :|'
      end
    end
  end

  def die
    self.brains = 0
    self.shots = 0
  end

  def next_player
    @@last_player += 1
    if PLAYERS.length == 1
      PLAYERS[0]
    elsif PLAYERS.length > 1 && @@last_player == 1
      PLAYERS[1]
    elsif PLAYERS.length > 2 && @@last_player == 2
      PLAYERS[2]
    elsif PLAYERS.length > 3 && @@last_player == 3
      PLAYERS[3]
    else
      @@last_player = 0
      PLAYERS[0]
    end
  end

  def to_continue?
    print "Zjedzono #{self.brains} mózgów, uzyskano #{self.shots} postrzałów",
          "\nŁącznie zebrano #{score + brains} mózgów\n",
          "Kontynuowac turę? Tak/Nie\n"
    answer = gets.chomp.downcase
    answer
  end

  def continue_turn(answer)
    if answer == 'nie' || answer == 'n'
      self.score += self.brains
      if self.score >= 24
        puts "Gracz #{nick.chomp} wygrywa!"
      else
        die
        pl = next_player
        pl.start_turn
      end
    else
      if self.score + brains >= 24
        puts "Gracz #{nick.chomp} wygrywa!"
      else
        start_turn
      end
    end
  end

  def start_turn
    puts `clear`,
         "~~Tura gracza #{nick.chomp}~~"
    do_rolling
    if self.shots >= 3
      puts '3 postrzały! Koniec tury :('
      die
      pl = next_player
      pl.start_turn
    else
      answer = to_continue?
      until answer == 'tak' || answer == 'nie' || answer == 'n' || answer == 't'
        puts `clear`,
             'Nieznana odpowiedź, wprowadź ponownie.'
        answer = to_continue?
      end
      continue_turn(answer)
    end
  end
end

def check_players(players)
  until %w(1 2 3 4).include? players
    puts `clear`,
         'Błędne dane, podaj ponownie liczbę graczy (1-4)'
    players = gets.chomp
  end
  players.to_i
end

def create_players(players)
  pl = 1
  until pl > players
    puts `clear`,
         "Gracz #{pl} podaj nick"
    nick = gets
    Player.new(nick)
    pl += 1
  end
  nick
end

def menu
  puts `clear`,
       'Implementacja gry planszowej "Zombie Dice" w jezyku Ruby',
       'Menu:',
       '1 - Zagraj w grę',
       '2 - Wyświetl zasady',
       '3 - Zamknij program'
  c = gets.chomp
  case c
  when '1'
    puts `clear`,
         'Ilu graczy bierze udział w grze? (Maksymalnie 4)'
    players = gets.chomp
    players = check_players(players)
    create_players(players)
    Player::PLAYERS[0].start_turn
  when '2'
    puts `clear`
    print 'Każdy z graczy wciela się w zombie. W turze rzuca się 3 kostkami, ',
          'każdy symbol mózgu dodaje punkt, symbol uciekiniera oznacza iż obia',
          'd nam uciekł, symbol strzału oznacza że mocno oberwaliśmy. Po każdy',
          'm rzucie 3 kostkami gracz podlicza mózgi i strzały, oraz podejmuje ',
          'decyzje - gra dalej, lub kończy rundę. Jeśli gra dalej, ponownie ',
          'rzuca 3 kostkami i dodaje mózgi i strzały do poprzednich. Jeśli w ',
          'dowolnym momencie gracz posiada 3 lub więcej strzałów traci mózgi z',
          ' tej rundy i konczy ją. Jeśli gracz zdecyduje się po rzucie skończy',
          'ć rundę dodaje zdobyte w niej mózgi do swojej puli i swoją rundę za',
          'czyna kolejny gracz. Pierwsza osoba która zdobędzie 24 punkty wygry',
          'wa. (wciśnij dowolny klawisz aby powrócić do menu)'
    gets
    menu
  when '3'
    puts `clear`,
         'Do zobaczenia!'
    abort
  else
    puts `clear`,
         'Wybierz ponownie opcje od 1 do 3'
    menu
  end
end
