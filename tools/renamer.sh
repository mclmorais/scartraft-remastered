#!/bin/bash

prefixes=("Marine" "Hydralisk" "Thor" "Void Ray" "Colossus")

for prefix in "${prefixes[@]}"; do
  find . -type f -name "${prefix} Rear Right *" -print0 | while IFS= read -r -d '' file; do
    num=${file##* }
    echo "Renaming file: $file"
    mv "$file" "$(dirname "$file")/${prefix,,}-up-right-$num"
  done

  find . -type f -name "${prefix} Rear Left *" -print0 | while IFS= read -r -d '' file; do
    num=${file##* }
    echo "Renaming file: $file"
    mv "$file" "$(dirname "$file")/${prefix,,}-up-left-$num"
  done

  find . -type f -name "${prefix} Right *" -print0 | while IFS= read -r -d '' file; do
    num=${file##* }
    echo "Renaming file: $file"
    mv "$file" "$(dirname "$file")/${prefix,,}-down-right-$num"
  done

  find . -type f -name "${prefix} Left *" -print0 | while IFS= read -r -d '' file; do
    num=${file##* }
    echo "Renaming file: $file"
    mv "$file" "$(dirname "$file")/${prefix,,}-down-left-$num"
  done
done