begin
  require "skeleton_ext/skeleton_ext"
rescue LoadError
  puts "Failed loading native extensions, falling back to pure ruby methods. Install with `rake compile`."
  require "skeleton/skeleton_pure"
  Skeleton::Performance = Skeleton::PerformancePure
end
