require 'simplecov'
SimpleCov.start

require_relative '../lib/insertionsort.rb'

describe "#insertion_sort" do
  it "should be defined" do
    expect { insertion_sort([2,5,3,9,4]) }.not_to raise_error
  end
  it "returns sorted array" do
    expect(insertion_sort([2,5,3,9,4])).to eq([2,3,4,5,9])
    expect(insertion_sort([92,81,74,6,5])).to eq([5,6,74,81,92])
    expect(insertion_sort([19,28,37,46,56])).to eq([19,28,37,46,56])
    expect(insertion_sort([2,5,-3,9,4,-1])).to eq([-3,-1,2,4,5,9])
    expect(insertion_sort([2,9.2,-3,9.25,4.5,-1])).to eq([-3,-1,2,4.5,9.2,9.25])
  end
  it "does nothing on empty array" do
    expect(insertion_sort([])).to eq([nil])
  end
end
