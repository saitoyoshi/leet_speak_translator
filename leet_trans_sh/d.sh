#!/bin/bash

input_string="Your input string goes here"

encoded_string=$(echo "$input_string" | sed -e 's/[aA]/4/g' -e 's/[bB]/8/g' -e 's/[cC]/</g' -e 's/[dD]/|)/g' -e 's/[eE]/3/g' -e 's/[fF]/|=/g' -e 's/[gG]/6/g' -e 's/[hH]/|-|/g' -e 's/[iI]/1/g' -e 's/[jJ]/_|/g' -e 's/[kK]/|</g' -e 's/[lL]/1/g' -e 's/[mM]/|\\/|/g' -e 's/[nN]/|\\|/g' -e 's/[oO]/0/g' -e 's/[pP]/|D/g' -e 's/[qQ]/(,)/g' -e 's/[rR]/|2/g' -e 's/[sS]/5/g' -e 's/[tT]/7/g' -e 's/[uU]/|_|/g' -e 's/[vV]/\\//g' -e 's/[wW]/|\\/\\|/g' -e 's/[xX]/></g' -e 's/[yY]/`\\//g' -e 's/[zZ]/2/g')

echo "Encoded: $encoded_string"
