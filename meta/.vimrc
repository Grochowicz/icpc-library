source $VIMRUNTIME/defaults.vim

"colorscheme koehler

set nu
set nohls
set ai
set undofile

"custom syntax
"autocmd filetype cpp set syntax=custom si cindent

"quint
"au BufNewFile,BufReadPost *.qnt runtime syntax/quint.vim

set belloff=all

set encoding=utf-8

"Whitespace
set wrap
set textwidth=110
set tabstop=4
set shiftwidth=4
set softtabstop=4
set noexpandtab
autocmd filetype cpp set expandtab
set noshiftround

" Last Line
set showmode
set showcmd

"Key Mapping
nnoremap k gk
nnoremap j gj
autocmd filetype cpp nnoremap gc 0i//<Esc>j
autocmd filetype cpp nnoremap fc 02xj
autocmd filetype c nnoremap gc 0i//<Esc>j
autocmd filetype c nnoremap fc 02xj
autocmd filetype py nnoremap gc 0i#<Esc>j
autocmd filetype py nnoremap fc 0xj

" import t.cpp
autocmd filetype cpp nnoremap <F1> :0r $HOME/t.cpp<Return>15jo
autocmd filetype c nnoremap <F1> :0r $HOME/t.c<Return>2jo

" compile
"autocmd filetype cpp nnoremap <F4> :w<Return>:!g++ -o /tmp/%.out % -std=c++2a -fsanitize=address,undefined -O2 -DLOCAL -Wall -Wextra -Wconversion -Wfatal-errors <Return>
autocmd filetype cpp nnoremap <F4> :w<Return>:!g++ -o /tmp/%.out % -std=c++23 -fsanitize=address,undefined -O2 -DLOCAL -Wall -Wfatal-errors <Return>
"autocmd filetype cpp nnoremap <F4> :w<Return>:!g++ -o /tmp/%.out % -std=c++2a -O2 -DLOCAL -Wfatal-errors <Return>
autocmd filetype c nnoremap <F4> :w<Return>:!gcc -o /tmp/%.out % -lm<Return>

" compile and run
autocmd filetype py nnoremap <F5> :w<Return>:!python3 %<Return>
"autocmd filetype cpp nnoremap <F5> :w<Return>:!g++ -o /tmp/%.out % -std=c++2a -fsanitize=address,undefined -O2 -DLOCAL -Wall -Wextra -Wconversion -Wfatal-errors && /tmp/%.out<Return>
autocmd filetype cpp nnoremap <F5> :w<Return>:!g++ -o /tmp/%.out % -std=c++23 -fsanitize=address,undefined -O2 -DLOCAL -Wall -Wextra -Wfatal-errors && /tmp/%.out<Return>
autocmd filetype c nnoremap <F5> :w<Return>:!gcc -o /tmp/%.out % -lm && /tmp/%.out<Return>

autocmd filetype cpp nnoremap <c-F5> :w<Return>:!g++ -o /tmp/%.out % -std=c++23 -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wfatal-errors -O2 && /tmp/%.out<Return>

" run
nnoremap <F6> :!/tmp/%.out<Return>
" run in
nnoremap <F7> :!/tmp/%.out < /tmp/%.in<Return>
" run in time
nnoremap <F8> :!time /tmp/%.out < /tmp/%.in<Return>
" run in out
nnoremap <F9> :!/tmp/%.out < /tmp/%.in > out%.txt<Return>
" bill
nnoremap <F10> :!~/bill_startup.sh<return>

"run python
cmap run :w<return>:!python3 %

" bracket remap
"inoremap {} {<cr>}<esc>O
inoremap {} {}<left><return><up><end><return>

"old bracket translator
"nnoremap ç :g/{/normal kJx<return>
"nnoremap Ç :g/{/normal $xo{<return>

"save in windows from wsl
"cmap wd w! /mnt/d/_code/%
"cmap wp w! /mnt/c/Users/ericg/Downloads/%

" commands
cmap ein e /tmp/%.in
cmap erc e $HOME/.vimrc
cmap e!rc e! $HOME/.vimrc
inoremap <F2> <Esc>:r ~/template/
nnoremap <F2> :r ~/template/
nnoremap <F3> :w<return>:!clip.exe < % && cowsay % copied.<return>
cmap ind %normal ==
" Allow saving of files as sudo without starting Vim using sudo.
cmap w!! w !sudo tee > /dev/null %
