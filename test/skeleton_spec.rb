$:.unshift File.join(File.dirname(__FILE__), '..', 'lib')

require "minitest/autorun"
require "skeleton"

describe Skeleton::Performance do

  it "runs" do
    Skeleton::Performance.new.run
  end

end
