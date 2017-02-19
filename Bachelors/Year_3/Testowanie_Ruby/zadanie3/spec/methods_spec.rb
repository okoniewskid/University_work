require 'simplecov'
SimpleCov.start

require 'methods.rb'

describe '#check_players' do
  before do
    allow($stdout).to receive(:write) {}
  end
  it 'should be defined' do
    expect { check_players('2') }.not_to raise_error
  end
  it 'should check input correctly' do
    expect(check_players('2')).to eq(2)
    expect(check_players('3')).not_to eq(2)
  end
end

describe '#create_players' do
  let(:player) { Player.new('Daniel') }
  before do
    allow($stdout).to receive(:write) {}
  end
  it 'should be defined' do
    expect { create_players(1) }.not_to raise_error
  end
  it 'should have correct nickname' do
    expect(player.nick).to eq('Daniel')
  end
  it 'should be initialized properly' do
    expect(player.score).to eq(0)
    expect(player.brains).to eq(0)
    expect(player.shots).to eq(0)
  end
  it 'should ask for nickname' do
    expect(STDOUT).to receive(:puts).with("\e[3;J\e[H\e[2J",
                                          'Gracz 1 podaj nick')
    create_players(1)
  end
end

describe Player do
  let(:player) { Player.new('Daniel') }
  before do
    allow($stdout).to receive(:write) {}
  end
  describe '#roll_dice' do
    it 'should be described' do
      expect { player.roll_dice }.not_to raise_error
    end
    it 'should return correct value' do
      expect(player.roll_dice).to eq('brain').or eq('shotgun').or eq('runner')
    end
  end # roll_dice
  describe '#do_rolling' do
    before do
      5.times do
        player.do_rolling
      end
    end
    it 'should be described' do
      expect { player.do_rolling }.not_to raise_error
    end
    it 'should increase values properly' do
      expect(player.shots).to_not eq(0)
    end
  end # do_rolling
  describe '#die' do
    it 'should be described' do
      expect { player.die }.not_to raise_error
    end
    before do
      player.brains = 10
      player.shots = 2
      player.die
    end
    it 'should reset points' do
      expect(player.brains).to eq(0)
      expect(player.shots).to eq(0)
    end
  end # die
  describe '#next_player' do
    it 'should be described' do
      expect { player.next_player }.not_to raise_error
    end
    before do
      @@last_player = 0
      4.times do
        player.next_player
      end
    end
    it 'should go through all players' do
      expect(@@last_player).to eq(0)
    end
  end # next_player
  describe '#to_continue?' do
    it 'should be described' do
      allow(player).to receive(:gets).and_return('tak')
      expect { player.to_continue? }.not_to raise_error
    end
    it 'should ask for correct value' do
      allow(player).to receive(:gets).and_return('tak')
      expect(player.to_continue?).to eq 'tak'
    end
  end # to_continue?
  describe '#continue_turn' do
    before do
      player.score = 20
      player.brains = 10
    end
    it 'should be described' do
      expect { player.continue_turn('tak') }.not_to raise_error
    end
    it 'should update score' do
      player.continue_turn('nie')
      expect(player.score).to eq(30)
    end
  end # continue_turn
end # Player
describe Dice do
  let(:dice) { Dice.new('green') }

  describe '.initialize' do
    it 'should be initialized properly' do
      expect(dice.color).to eq('green').or eq('yellow').or eq('red')
      expect(dice.symbols).to eq([])
    end
  end
  describe '#add_symbols' do
    it 'should be described' do
      expect { dice.add_symbols }.not_to raise_error
    end
    it 'should add proper symbols' do
      dice.add_symbols
      expect(dice.symbols).to eq(%w(brain brain brain runner runner shotgun))
    end
  end
end
