#!/bin/bash -x
set -o errexit

#pandoc -i "$1" -t markdown -o "$1"
git add "$1"
git commit -uno -m "added $1"
