guard 'shell' do
  watch(%r{^.+\.(cpp)$}) do |f|
    puts "Compiling #{f.first}..."
    `ls *.cpp | grep -v skeleton | xargs g++`
    puts "=============================================="
  end
end
