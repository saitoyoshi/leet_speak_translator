<?php
$options = getopt("dev", ['version','decode','encode']);
$input = $argv[$argc -1];
$mode = null;
if (isset($options['v'])) {
    if ($options['v'] === false)
    echo 'leet speack translate command - version 0.0.1' . PHP_EOL;
    exit(7);
}
if (isset($options['e'])) {
    if ($options['e'] === false) {
        $mode = 'encode';
    }
} elseif (isset($options['encode'])) {
    if ($options['encode'] === false) {
        $mode = 'encode';
    }
}
if (isset($options['d'])) {
    if ($options['d'] === false) {
        $mode = 'decode';
    }
} elseif (isset($options['decode'])) {
    if ($options['decode'] === false) {
        $mode = 'decode';
    }
}
$input = str_split($input);
$trans_table = [
    'A' => '4',
    'B' => '13',
    'C' => '(',
    'D' => '|)',
    'E' => '3',
    'F' => '|=',
    'G' => '9',
    'H' => '#',
    'I' => '1',
    'J' => '_|',
    'K' => '|<',
    'L' => '1_',
    'M' => '(V)',
    'N' => '(\)',
    'O' => '0',
    'P' => '|D',
    'Q' => '(,)',
    'R' => '|2',
    'S' => '5',
    'T' => '7',
    'U' => '|_|',
    'V' => 'V',
    'W' => '\\/\\/',
    'X' => '><',
    'Y' => '`/',
    'Z' => '2',
    'a' => '4',
    'b' => 'b',
    'c' => 'c',
    'd' => 'd',
    'e' => '3',
    'f' => 'f',
    'g' => '9',
    'h' => '#',
    'i' => '1',
    'j' => 'j',
    'k' => '|<',
    'l' => '1',
    'm' => 'm',
    'n' => 'n',
    'o' => '0',
    'p' => 'p',
    'q' => 'q',
    'r' => 'r',
    's' => '5',
    't' => '7',
    'u' => 'u',
    'v' => 'v',
    'w' => 'w',
    'x' => 'x',
    'y' => 'y',
    'z' => '2',
    '0' => 'O',
    '1' => '|',
    '2' => 'Z',
    '3' => 'E',
    '4' => 'A',
    '5' => 'S',
    '6' => 'b',
    '7' => 'T',
    '8' => 'B',
    '9' => 'g',
    //追記
    '_' => '_',
    '{' => '{',
    '}' => '}',
    '?' => '?',
    '=' => '=',
    '/' => '/',
    '&' => '&',
    '.' => '.',
    ' ' => ' ',
    ',' => ',',
];
if ($mode === 'encode') {
    ;
} elseif ($mode === 'decode') {
    $trans_table = array_flip($trans_table);
    // このテーブルにないアルファベットと数字を加える
    // リストをとってきて、その値がなかったらキーと値としてくわえる。キーがなかったら
    $numbers = range('0', '9');
    $lowercases = range('a', 'z');
    $uppsercases = range('A', 'Z');
    $letters = array_merge($numbers, $lowercases, $uppsercases);
    foreach ($letters as $letter) {
        if (!array_key_exists($letter, $trans_table)) {
            $trans_table[$letter] = $letter;
        }
    }
}
$output = [];
foreach ($input as $letter) {
    if ($letter === '_') {
        $output[] = '_';
    } else {
        $output[] = $trans_table[$letter];
    }
}
$outputStr = implode($output);
echo $outputStr . PHP_EOL;
