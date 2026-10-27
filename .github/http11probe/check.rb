# frozen_string_literal: true

# Compares Http11Probe results against the list of known failures.
#
# Exits non-zero when a scored test fails that is not listed in
# known_failures.txt (a regression). Tests that are listed but now pass are
# reported as warnings so the list can be pruned.
#
#   ruby .github/http11probe/check.rb results.json

require "json"

results_path = ARGV.fetch(0) { abort "usage: #{$PROGRAM_NAME} RESULTS_JSON" }
known_path = File.expand_path("known_failures.txt", __dir__)

known = File.readlines(known_path, chomp: true)
  .map(&:strip).reject { |l| l.empty? || l.start_with?("#") }

data = JSON.parse(File.read(results_path))
scored = data.fetch("results").select { |r| r["scored"] }
failures = scored.select { |r| r["verdict"] == "Fail" }.map { |r| r["id"] }

regressions = failures - known
stale = known - failures
not_found = stale - scored.map { |r| r["id"] }
fixed = stale - not_found

if (summary = data["summary"])
  puts "Http11Probe: #{summary.map { |k, v| "#{k}=#{v}" }.join(" ")}"
end
puts "Scored failures: #{failures.size} (known: #{known.size})"

gha = ENV["GITHUB_ACTIONS"] == "true"

report = lambda do |level, title, ids|
  return if ids.empty?
  puts "\n#{title}:"
  ids.sort.each { |id| puts "  #{id}" }
  puts "::#{level} title=Http11Probe::#{title}: #{ids.sort.join(', ')}" if gha
end

report.("error", "New failures (regressions)", regressions)
report.("warning", "Now passing, remove from .github/http11probe/known_failures.txt", fixed)
report.("warning", "Known failures missing from scored results", not_found)

exit 1 unless regressions.empty?
puts "\nOK: no new failures"
