require "bundler/gem_tasks"
require "rake/extensiontask"
require "rspec/core/rake_task"

spec = Gem::Specification.load("pi_wire.gemspec")

RSpec::Core::RakeTask.new(:spec)
Rake::ExtensionTask.new("pi_wire", spec) do |ext|
  ext.lib_dir = File.join("lib", "pi_wire")
end

task default: :spec
