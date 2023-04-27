#!/bin/bash

usage() {
  echo "Usage: $0 [-e|--encode] [-d|--decode] [-h|--help] <input string>"
}

encode() {
  input="$1"
  echo "$input" | tr 'a-zA-Z' '4-93-90-9A-A9' #1文字対応の変換なので使えない
}

decode() {
  input="$1"
  echo "$input" | tr '4-93-90-9A-A9' 'a-zA-Z'
}

opt_encode=0
opt_decode=0

while [[ $# -gt 0 ]]; do #引数の数がある間は0より大きい間は
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
      if [ -z "$input_string" ]; then
        input_string="$1"
      else
      #入力文字列が複数あった場合
        echo "Invalid option: $1"
        usage
        exit 1
      fi
      shift
      ;;
  esac
done

if [ -z "$input_string" ]; then
#そもそも入力文字列が与えられなかった場合
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
