#!/bin/bash
#
# Usage: bandwidth.sh <host> [<freq>] [<port>]
#
# Measure the bandwidth every <freq> seconds between here and <host>.
#
# Typically stored in a log: "bandwidth.sh ny.com >> /tmp/b.log 2>&1"
#
# (c) 2003 Charles Thayer <thayer@b2si.com> 


host=$1
freq=${2:-60}
port=${3:-3087}

ssh -f $host "(while true; do echo starting; if ! ttcp -p $port -r -s -v; then exit; fi; done)"

sleep 1
while true; do
  now=`date "+%Y/%m/%d %H:%M:%S"`
  echo "$now  Bandwidth from $(hostname) to $host, every $freq sec"
  ttcp -t $host -n 512 -l $((128*1024)) -p $port -t -s -v
  echo
  sleep $freq
done
