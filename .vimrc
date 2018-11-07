" <leader> for shortchuts
let mapleader = ","

" compile and run
function! Compile()
    :!g++ -std=c++14 -Wall -Wshadow -O2 %
endfunction

function! Run()
    :!i=1; for input in in*; do echo SAMPLE $i; time ./a.out < $input; echo -----; ((i++)); done
endfunction

map <leader>c :call Compile()<cr>
map <leader>r :call Run()<cr>

" Indentation and code-style
filetype plugin indent on
set et ts=4 sts=4 sw=4

" Syntax highlighting
syn on

" Relative line numbers
set nu rnu

" colors
colors evening
set t_Co=8

" template
autocmd BufNewFile *.cpp :0r ~/cpp | +5

"#include <bits/stdc++.h>
"using namespace std;
"typedef long long ll;
"
"int main() {
"
"}
