require 'simplecov'
SimpleCov.start

require_relative '../lib/quicksort.rb'

describe "#quicksort" do
  it "should be defined" do
    expect { quicksort([2,5,3,9,4]) }.not_to raise_error
  end
  it "returns sorted array" do
    expect(quicksort([2,5,3,9,4])).to eq([2,3,4,5,9])
    expect(quicksort([92,81,74,6,5])).to eq([5,6,74,81,92])
    expect(quicksort([19,28,37,46,56])).to eq([19,28,37,46,56])
    expect(quicksort([2,5,-3,9,4,-1])).to eq([-3,-1,2,4,5,9])
    expect(quicksort([2,9.2,-3,9.25,4.5,-1])).to eq([-3,-1,2,4.5,9.2,9.25])
  end
  it "does nothing on empty array" do
    expect(quicksort([])).to be_empty
  end
end

