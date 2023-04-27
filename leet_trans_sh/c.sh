#!/bin/bash

if [ "$#" -ne 2 ]; then # $#は与えられた引数の数　すなわち、$1,$2が存在するとき
  echo "Usage: $0 [-e | -d] <input>" #$0は自分自身のファイル名が入る
  exit 1
fi

option=$1 #オプションを第一引数
input=$2 #入力文字を第2引数

if [ "$option" == "-e" ]; then #$optionが変数展開されて、"-e"と比較評価される
  encoded=$(echo "$input" | tr 'aAeElLoOtTsS' '443311007755') #一文字対応の変換しかしないので、sedで一文字ずつ変換するのがよい
  echo "Encoded: $encoded"
elif [ "$option" == "-d" ]; then
  decoded=$(echo "$input" | tr '443311007755' 'aAeElLoOtTsS')
  echo "Decoded: $decoded"
else
  echo "Invalid option"
  exit 1
fi
