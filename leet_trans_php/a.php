<?php

/*
|--------------------------------------------------------------------------
| サンプルプログラム
|--------------------------------------------------------------------------
|
| 勉強用のCLI（Command Line Interface）アプリのサンプル
| 年齢を入力させて、20歳以上かを判定するだけのものです。
|
*/

// アプリケーション本体の「インスタンス」を生成
$app = new SampleApp();

// アプリケーション実行
$app->execute();


/*
|--------------------------------------------------------------------------
| 以下、クラス定義
|--------------------------------------------------------------------------
|
*/

/**
 * アプリケーションのベースとなる「抽象クラス」
 * メッセージ表示・入力受付などの基本的なメソッドが用意されています。
 */
abstract class App
{

    /**
     * アプリケーション実行メソッド
     * 「抽象メソッド」です。「継承」したクラスで、このメソッドを定義しないとエラーになります。
     *
     * @return void
     */
    abstract public function execute();


    /*
    |--------------------------------------------------------------------------
    | 以下、汎用的な「メソッド」を定義
    |--------------------------------------------------------------------------
    |
    */

    /**
     * 画面に文字を表示：末尾に改行なし
     *
     * @param string $message
     */
    protected function message(string $message)
    {
        // 危険な文字はエスケープする（HTMLエスケープのシェル版みたいなもの）
        echo escapeshellcmd($message);
    }

    /**
     * 画面に文字を表示：末尾に改行あり
     *
     * @param string $message
     */
    protected function line(string $message)
    {
        echo escapeshellcmd($message) . "\n";
    }

    /**
     * 画面に文字を表示して、入力を受け付ける
     *
     * @param string $message
     * @return string
     */
    protected function ask(string $message)
    {
        // メッセージを表示し、「標準入力」の受け付け待ち。
        // 前後のスペースなど、入力ミスと思われるものを除外（trim）してあげるのは優しさ。
        $this->message($message);
        return trim(fgets(STDIN));
    }

}

/**
 * アプリケーション本体
 *
 * Appクラスを「継承」して、アプリケーションに必要なロジックをここに記述します。
 */
class SampleApp extends App
{
    /**
     * アプリケーション実行メソッド
     * アプリケーション独自の処理を記述する
     *
     * @return void
     */
    public function execute()
    {
        // 年齢を聞く
        $age = $this->listen();
        // 年齢として正しくない値が返ってきたら、メッセージを出力して終了する。
        if (false === $age) {
            $this->line('年齢を入力して！！');
            return;
        }
        // 大人かどうかで処理わけ
        if ($this->isAdult($age)) {
            $this->line('あなたは大人です。');
        } else {
            $this->line('お子ちゃまですね。');
            $this->line('早く寝なさい！！');
        }
    }

    /**
     * 年齢を聞きます
     * 年齢としておかしい値の場合はfalseを返します。
     *
     * @return false|int
     */
    protected function listen()
    {
        $input = $this->ask('年齢を入力してください：');

        // 優しさ。もし全角数値が入力されたら、半角数値に変換してあげる。
        $value = mb_convert_kana($input, 'n');

        // 年齢として扱えない：数値として扱えない文字列
        if (!is_numeric($value)) {
            return false;
        }
        // is_numeric()は、小数とかも許容してしまう。「キャスト」して無理やり整数にする。
        // 正確にやるなら、「正規表現」を使いますが、理解が難しいと思うのでここでは手抜き。
        $age = (int)$value;
        if (200 < $age) {
            // 200歳より大きかったら人間じゃないよね・・ということでfalseを返す
            return false;
        }
        // 入力された年齢を返す。
        return $age;
    }

    /**
     * 大人（20歳以上）ならtrueを返す。
     *
     * @param int $age
     * @return bool
     */
    protected function isAdult(int $age)
    {
        return (20 <= $age);
    }

}
