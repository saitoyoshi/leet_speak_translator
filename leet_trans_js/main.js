'use strict';

const textsElem = document.querySelector('#texts');
let texts = '';
let transTable = new Map([
  ['a','4'],
  ['l', '1'],
  ['e', '3'],
  ['A' ,'4'],
  [  'B' ,'13'],
  [     'C' ,'('],
  [     'D' ,'|)'],
  [     'E' ,'3'],
  [     'F' ,'|='],
  [     'G' ,'9'],
  [     'H' ,'#'],
  [     'I' ,'1'],
  [     'J' ,'_|'],
  [     'K' ,'|<'],
  [     'L' ,'1_'],
  [     'M' ,'(V)'],
  [     'N' ,'(\)'],
  [     'O' ,'0'],
  [     'P' ,'|D'],
  [     'Q' ,'(,)'],
  [     'R' ,'|2'],
  [     'S' ,'5'],
  [     'T' ,'7'],
  [     'U' ,'|_|'],
  [     'V' ,'V'],
  [     'W' ,'\\/\\'],
  [     'X' ,'><'],
  [     'Y' ,'`/'],
  [     'Z' ,'2'],
  [     'a' ,'4'],
  [     'b' ,'b'],
  [     'c' ,'c'],
  [     'd' ,'d'],
  [     'e' ,'3'],
  [     'f' ,'f'],
  [     'g' ,'9'],
  [     'h' ,'#'],
  [     'i' ,'1'],
  [     'j' ,'j'],
  [     'k' ,'|<'],
  [     'l' ,'1'],
  [     'm' ,'m'],
  [     'n' ,'n'],
  [     'o' ,'0'],
  [     'p' ,'p'],
  [     'q' ,'q'],
  [     'r' ,'r'],
  [     's' ,'5'],
  [     't' ,'7'],
  [     'u' ,'u'],
  [     'v' ,'v'],
  [     'w' ,'w'],
  [     'x' ,'x'],
  [     'y' ,'y'],
  [     'z' ,'2'],
  [     '0' ,'O'],
  [     '1' ,'|'],
  [     '2' ,'Z'],
  [     '3' ,'E'],
  [     '4' ,'A'],
  [     '5' ,'S'],
  [     '6' ,'b'],
  [     '7' ,'T'],
  [     '8' ,'B'],
  [     '9' ,'g'],
       //追記
  [   '_' ,'_',]
,  [     '{' ,'{'],
  [     '}' ,'}'],
  [     '?' ,'?'],
  [     '=' ,'='],
  [     '/' ,'/'],
  [     '&' ,'&'],
  [     '.' ,'.'],
  [     ' ' ,' '],
  [     ',' ,','],
  [     '-' ,'-'],
  [     "\"" ,"\""],
  [     ':' ,':'],
  [     '\\' ,'\\'],
]);
const forRange = (a, z) => {
  const lst = [];
  for (let i = a; i <= z; i++) {
    lst.push(i);
  }
  return lst;
}
let transTableForDecode = new Map();
for (let [key, value] of transTable.entries()) {
  transTableForDecode.set(value, key);
}
const btn = document.querySelector('#btn');
btn.addEventListener('click', () => {
  const encElem = document.querySelector('#encode');
  const decElem = document.querySelector('#decode');
  let table = null;
  if (encElem.checked) {
    // alert(encElem.value);
    table = transTable;
  } else if (decElem.checked) {
    // alert(decElem.value);
    table = transTableForDecode;
    let numbers = forRange('0', '9');
    let lowercases = [...'abcdefghijklmnopqrstuvwxyz'];
    let uppercases = [...'ABCDEFGHIJKLMNOPQRSTUVWXYZ'];
    let merged = [...numbers, ...lowercases,...uppercases];
    // alert(merged);
    merged.forEach(v => {
      table.set(v, v);
    });
    // $numbers = range('0', '9');
    //         $lowercases = range('a', 'z');
    //         $uppsercases = range('A', 'Z');
    //         $letters = array_merge($numbers, $lowercases, $uppsercases);
    //         foreach ($letters as $letter) {
    //             if (!array_key_exists($letter, $trans_table)) {
    //                 $trans_table[$letter] = $letter;
    //             }
    //         }
    // for (const num of [0])
  }
  texts = textsElem.value;
  let output = [];
  for (const char of texts) {
    // console.log(char);
    output.push(table.get(char));
  }
  // alert(output.join(''));
  const messageArea = document.querySelector('#message');
  messageArea.textContent = output.join('');
});
