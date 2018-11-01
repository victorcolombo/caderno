" <leader> for shortchuts
let mapleader = ","

" Indentation and code-style
filetype plugin indent on
set et ts=4 sts=4 sw=4

" Syntax highlighting
syntax on

" Relative line numbers
set nu rnu

" colors
colors evening
set t_Co=8

" template
autocmd BufNewFile *.cpp :0r ~/cpp
autocmd BufNewFile *.cpp +6

" compile and run
map <leader>c :execute "!g++ -std=c++14 -Wall -Wshadow -O2 " . expand("%d")<cr>
map <leader>r :execute "!i=1; for input in in*; do echo SAMPLE $i; time ./a.out < $input; echo ------------; ((i++)); done"<cr>
