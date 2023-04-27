<?php

$app = new LeetTrans($argc, $argv);
$app->execute();

abstract class App
{
    abstract public function execute();

    protected function message(string $message)
    {
        echo escapeshellcmd($message);
    }
    protected function line(string $message)
    {
        echo escapeshellcmd($message) . PHP_EOL;
    }
}
class LeetTrans extends App
{
    private array $options;
    private string $input;
    private string $programName;
    private const TRANS_TABLE = [
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
        'W' => '\\/\\',
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
        '-' => '-',
        "\"" => "\"",
        ':' => ':',
        '\\' => '\\',
    ];
    public function __construct($argc, $argv)
    {
        $this->options = getopt('vhde');
        $this->input = $argv[$argc - 1];
        $this->programName = $argv[0];
        if (basename($this->input) === basename($this->programName)) {
            $this->usage();
        }
    }
    private function getMode()
    {
        if (empty($this->options)) {
            return 'encode';
        }
        if ($this->requestUsage()) {
            return 'help';
        }
        if ($this->requestVersion()) {
            return 'version';
        }
        if ($this->requestEncode()) {
            return 'encode';
        }
        if ($this->requestDecode()) {
            return 'decode';
        }
    }
    private function requestVersion()
    {
        if (isset($this->options['v'])) {
            if ($this->options['v'] === false) {
                return true;
            }
        }
        return false;
    }
    private function requestUsage()
    {
        if (isset($this->options['h'])) {
            if ($this->options['h'] === false) {
                return true;
            }
        }
        return false;
    }
    private function requestDecode()
    {
        if (isset($this->options['d'])) {
            if ($this->options['d'] === false) {
                return true;
            }
        }
        return false;
    }
    private function requestEncode()
    {
        if (isset($this->options['e'])) {
            if ($this->options['e'] === false) {
                return true;
            }
        }
        return false;
    }
    public function execute()
    {
        $this->run($this->getMode());
    }
    private function usage() {
        $this->line('Usage : ' . $this->programName . ' [options(d:decode,e:encode,h:help,v:version] <strings>');
            exit(4);
    }
    public function run(?string $mode)
    {
        if ($mode === 'help') {
            $this->usage();
            exit(3);

        }
        if ($mode === 'version') {
            $this->line($this->programName . ' leet spake translate command version 0.0.1');
            exit(7);
        }
        $result = $this->getTranslate($mode);
        $this->line($result);
    }
    private function getTranslate(?string $mode)
    {
        if ($mode === 'encode' || is_null($mode)) {
            $trans_table = self::TRANS_TABLE;
        } elseif ($mode === 'decode') {
            $trans_table = array_flip(self::TRANS_TABLE);
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
        $translatedChars = [];
        $inputChars = str_split($this->input);
        foreach ($inputChars as $letter) {
            if (!array_key_exists($letter, $trans_table)) {
                continue;
            }
            $translatedChars[] = $trans_table[$letter];
        }
        return implode($translatedChars);
    }
}
