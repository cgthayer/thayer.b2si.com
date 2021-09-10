#!/bin/sh

run () {
  time perl -e '
    $|++;
    $c = $ARGV[0];
    print "$c => " . `$c | wc -l`; 
    for $i (1..20) { 
      print "."; `$c > /dev/null`; 
    }
    ' "$*"
  echo
}


for file in todo /etc/magic never_going_to_find
do 
  echo Old fashioned
  run "locate $file"

  echo New fashioned
  run "locate/locate $file"

  echo New fashioned with --ignore_case on
  run "locate/locate -i $file"
done


