#!/bin/sh
wget -q -O - https://projecteuler.net/project/resources/p079_keylog.txt | xargs -I DIGITS echo 'echo $(echo DIGITS | cut -c 1) $(echo DIGITS | cut -c 2) \\n $(echo DIGITS | cut -c 2) $(echo DIGITS | cut -c 3)' | sh | tsort | tr -d \\n | sed s/$/\\n/
