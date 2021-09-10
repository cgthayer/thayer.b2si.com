#!/bin/bash

#scp resume2010.html mbops@mediabridge.com:webapps/thayer_b2si/resume2010.html
rsync --progress -av --delete ./ \
  mbops@mediabridge.com:webapps/b2si_thayer/ \
  --exclude=\*cgwiki\* --exclude=sync.sh
