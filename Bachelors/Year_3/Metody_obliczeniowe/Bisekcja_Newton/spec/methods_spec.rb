require 'simplecov'
SimpleCov.start

require 'methods.rb'

describe Wielomian do
  let(:wielomian) { Wielomian.new(0.001, [-2.0, 2.0]) }

  describe '#f(x)' do
    it 'should be defined' do
      expect { wielomian.f(1) }.not_to raise_error
    end
    it 'should count properly' do
      expect(wielomian.f(1)).to eq(-8)
      expect(wielomian.f(-1)).to eq(-12)
    end
  end

  describe '#fprime(x)' do
    it 'should be defined' do
      expect { wielomian.fprime(1) }.not_to raise_error
    end
    it 'should count properly' do
      expect(wielomian.fprime(1)).to eq(6)
      expect(wielomian.fprime(-1)).to eq(6)
    end
  end

  describe '#bisekcja' do
    it 'should be defined' do
      expect { wielomian.bisekcja }.not_to raise_error
    end
    before do
      wielomian.bisekcja
    end
    it 'should count properly' do
      expect(wielomian.bis).to be_between(1.53, 1.54).inclusive
    end
  end

  describe '#wybierz_przedzial' do
    it 'should be described' do
      expect { wielomian.wybierz_przedzial(1) }.not_to raise_error
    end
  end

  describe '#newton_raphson' do
    it 'should be described' do
      expect { wielomian.newton_raphson }.not_to raise_error
    end
    before do
      wielomian.newton_raphson
    end
    it 'should count properly' do
      expect(wielomian.newt).to be_between(1.53, 1.54).inclusive
    end
  end
end

describe Menu do
  let(:wielomian) { Wielomian.new(0.001, [-2.0, 2.0]) }
  let(:wielomian2) { Wielomian.new(0.1, [-0.18, 0.83]) }
  let(:menu) { Menu.new }
  describe '#start' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      allow(menu).to receive(:gets).and_return('0.001','n')
      expect { menu.start }.not_to raise_error
    end
  end

  describe '#count' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      expect { menu.count(wielomian) }.not_to raise_error
    end
    it 'should restart when interval is bad' do
      allow(menu).to receive(:gets).and_return('0.001','n')
      expect { menu.count(wielomian2) }.not_to raise_error
    end
    before do
      menu.count(wielomian)
    end
    it 'should count bisection' do
      expect(wielomian.bis).not_to eq(nil)
    end
    it 'should count newton' do
      expect(wielomian.newt).not_to eq(nil)
    end
  end

  describe '#podaj_dokladnosc' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      allow(menu).to receive(:gets).and_return('0.001')
      expect { menu.podaj_dokladnosc }.not_to raise_error
    end
    it 'should not accept wrong value' do
      allow(menu).to receive(:gets).and_return('1.2','1','0.01')
      menu.podaj_dokladnosc
      expect(menu).to have_received(:gets).exactly(3).times
    end
  end

  describe '#podaj_przedzial' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      allow(menu).to receive(:gets).and_return('-2.0','2.0')
      expect { menu.podaj_przedzial }.not_to raise_error
    end
  end

  describe 'sprawdz_przedzial' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      expect { menu.sprawdz_przedzial(-2.0,2.0) }.not_to raise_error
    end
    it 'should check ends' do
      allow(menu).to receive(:gets).and_return('-1.0','1.0')
      expect(menu.sprawdz_przedzial(2.0,-2.0)).to eq([-1.0,1.0])
    end
    it 'should check signs' do
      allow(menu).to receive(:gets).and_return('-1.0','1.0')
      expect(menu.sprawdz_przedzial(-2.0,-2.0)).to eq([-1.0,1.0])
    end
  end

  describe 'przedzial?' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      allow(menu).to receive(:gets).and_return('n')
      expect { menu.przedzial? }.not_to raise_error
    end
    it 'should use default' do
      allow(menu).to receive(:gets).and_return('n')
      c = menu.przedzial?
      expect(c).to eq([-2.0,2.0])
    end
    it 'should allow input when asked' do
      allow(menu).to receive(:gets).and_return('t','-3.0','2.0')
      c = menu.przedzial?
      expect(c).to eq([-3.0,2.0])
    end
  end

  describe 'restart?' do
    before do
      allow($stdout).to receive(:write) {}
    end
    it 'should be described' do
      allow(menu).to receive(:gets).and_return('n')
      expect { menu.restart? }.not_to raise_error
    end
  end
end
