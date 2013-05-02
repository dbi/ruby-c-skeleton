#!/usr/bin/env rake

require 'rake/testtask'
require 'rake/clean'

NAME = 'skeleton_ext'
EXTENSION = RbConfig::CONFIG['DLEXT']

desc "Compile c extensions"
task :compile => "lib/#{NAME}/#{NAME}.#{EXTENSION}"

# rule to build the extension: this says
# that the extension should be rebuilt
# after any change to the files in ext
file("lib/#{NAME}/#{NAME}.#{EXTENSION}" => Dir.glob("ext/#{NAME}/*{.rb,.c,.h}")) do
  Dir.chdir("ext/#{NAME}") do
    # this does essentially the same thing
    # as what RubyGems does
    ruby "extconf.rb"
    sh "make"
  end
  sh "mkdir -p lib/#{NAME}"
  cp "ext/#{NAME}/#{NAME}.#{EXTENSION}", "lib/#{NAME}/#{NAME}.#{EXTENSION}"
end

# use 'rake clean' and 'rake clobber' to
# easily delete generated files
CLEAN.include("ext/**/*{.o,.log,.#{EXTENSION}}")
CLEAN.include("ext/**/Makefile")
CLOBBER.include("lib/#{NAME}")

Rake::TestTask.new do |t|
  t.pattern = "test/**/*_spec.rb"
end

desc "Run tests"
task :default => :test
task :spec => :test
