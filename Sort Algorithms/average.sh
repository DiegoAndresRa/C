#!/bin/bash
echo "Input: $*"
sorts=$(ls|grep -E '.*.c')
for sort in $sorts;do
  echo "$sort"
  gcc "$sort" && time ./a.out $@
  echo ""
  rm ./a.out
done
