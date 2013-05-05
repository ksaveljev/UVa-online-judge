guard 'shell' do
  watch(%r{^.+\.(cpp)$}) do |f|
    puts "Compiling #{f.first}..."
    `g++ #{f.first}`
    puts "=============================================="
  end
end
