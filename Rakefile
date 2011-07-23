##------------------------------------------------------------------------------
# VARIABLES:
#
include_dirs         = []
additional_cxx_flags = []
additional_ld_flags  = []

##------------------------------------------------------------------------------
# CONSTANTS:
#
CC  = "g++-mp-4.6.1"
CXX = "g++-mp-4.6.1"
RM  = "rm -f"
SRC = FileList[ "*.cpp" ]
OBJ = SRC.ext( "o" )

CXXFLAGS = %w( -Wall -g -std=c++0x -c )
LDFLAGS  = []
CLEAN = FileList[ "simple", "*.o" ]

##------------------------------------------------------------------------------
# TASKS:
#
task :default => [ :build ]

desc "Build the simple executable"
task :build => "simple"

desc "Clean up all generated files"
task :clean do
  sh "#{ RM } #{ CLEAN.join( " " ) }"
end

##------------------------------------------------------------------------------
# RULES:
#
rule ".o" => ".cpp" do |t|
  flags = CXXFLAGS + additional_cxx_flags
  sh "#{ CXX } #{ flags.join( " " ) } -o #{ t.name } #{ t.source }"
end

##------------------------------------------------------------------------------
# FILES:
#
file "simple" => OBJ do |t|
  flags = LDFLAGS + additional_ld_flags
  sh "#{ CC } #{ flags.join( " " ) } #{ t.prerequisites.join( " " ) } -o #{ t.name }"
end
