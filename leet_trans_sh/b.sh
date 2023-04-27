#!/bin/bash

usage() {
  echo "Usage: $0 [-e|--encode] [-d|--decode] [-h|--help] <input string>"
}

encode() {
  input="$1" #第一引数
  leet_encoded=$(echo "$input" | sed -e 's/a/4/g' -e 's/b/8/g' -e 's/e/3/g' -e 's/l/1/g' -e 's/o/0/g' -e 's/t/7/g' -e 's/s/5/g' -e 's/A/4/g' -e 's/B/8/g' -e 's/E/3/g' -e 's/L/1/g' -e 's/O/0/g' -e 's/T/7/g' -e 's/S/5/g')
  echo "$leet_encoded"
}

decode() {
  input="$1" #この関数に与えられた第一引数が
  #echo "第一引数、この関数に与えられたのは:$1"
  leet_decoded=$(echo "$input" | sed -e 's/4/a/g' -e 's/8/b/g' -e 's/3/e/g' -e 's/1/l/g' -e 's/0/o/g' -e 's/7/t/g' -e 's/5/s/g')
  echo "$leet_decoded"
}

opt_encode=0
opt_decode=0
#echo hikisuu
#echo $#
while [[ $# -gt 0 ]]; do #引数が0より大きい
  case "$1" in
    -e|--encode)
      opt_encode=1
      shift
      ;;
    -d|--decode)
      opt_decode=1
      shift
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      if [ -z "$input_string" ]; then # $input_stringが空文字列である場合に
        input_string="$1"
      else
        echo "Invalid option: $1" #入力文字列が複数あったら、エラーメッセージ
        usage
        exit 1
      fi
      shift
      ;;
  esac
done

if [ -z "$input_string" ]; then
  echo "Error: No input string provided."
  usage
  exit 1
fi

if [ $opt_encode -eq 1 ]; then
  result=$(encode "$input_string")
elif [ $opt_decode -eq 1 ]; then
  result=$(decode "$input_string")
else
  echo "Error: No operation specified. Use -e|--encode or -d|--decode."
  usage
  exit 1
fi

echo "$result"
