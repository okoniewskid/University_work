require 'benchmark'

require '../lib/bubblesort.rb'
require '../lib/mergesort.rb'
require '../lib/quicksort.rb'
require '../lib/insertionsort.rb'
require '../lib/heapsort.rb'

array100 = (1..100).map { rand }
array1000 = (1..1000).map { rand }
array10000 = (1..10000).map { rand }

n = 5000

puts "\n"
puts 'Bubblesort benchmark'
Benchmark.bmbm do |x|
    x.report("Length = 100") { n.times do ; bubble_sort(array100); end }
    x.report("Length = 1000") { n.times do ; bubble_sort(array1000); end }
end

puts "\n"
puts 'Mergesort benchmark'
Benchmark.bmbm do |x|
    x.report("Length = 100") { n.times do ; mergesort(array100); end  }
    x.report("Length = 1000") { n.times do ; mergesort(array1000); end  }
end

puts "\n"
puts 'Quicksort benchmark'
Benchmark.bmbm do |x|
    x.report("Length = 100") { n.times do ; quicksort(array100); end }
    x.report("Length = 1000") { n.times do ; quicksort(array1000); end }
end

puts "\n"
puts 'Heapsort benchmark'
Benchmark.bmbm do |x|
    x.report("Length = 100") { n.times do ; heap_sort(array100); end }
    x.report("Length = 1000") { n.times do ; heap_sort(array1000); end }
end

puts "\n"
puts 'Insertionsort benchmark'
Benchmark.bmbm do |x|
    x.report("Length = 100") { n.times do ; insertion_sort(array100); end }
    x.report("Length = 1000") { n.times do ; insertion_sort(array1000); end }
end
