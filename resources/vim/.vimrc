" pathogen is a plugin manager for vim. There are a lot of useful plugins out
" there that can make the editing code in a terminal with vim super powerful!
"execute pathogen#infect('bundle/{}')

set autoindent
set smartindent
set smarttab
set shiftwidth=4
set softtabstop=4
set tabstop=4
set expandtab
set nowrap              "don't wrap lines
set wildmenu            "better command-line completion
set showcmd             "show partial commands in the last line of the screen
set hlsearch
set laststatus=2        "always show the status bar
set mouse=a             "don't copy numbers when selecting an area with a mouse

set number                  "turn numbers (on the left side) on
set printoptions=number:y   "print with numbers
set history=1000            "keep a long list of history
set noeb vb t_vb=           "get ride of error bells
set autoread                "reload files changed outside of vim
set t_Co=256                "set 256bit color
set clipboard=unnamedplus   "alias for X Windows clipboard

" remap <F1> to escape...stupid fat fingers...
nmap <F1> <nop>
map <F1> <Esc>
imap <F1> <Esc>

syntax on
set encoding=utf-8

" fix backspacing issues
set backspace=indent,eol,start

" <Ctrl-l> redraws the screen and removes any search highlighting
noremap <silent> <C-l> :nohl<CR><C-l>

" remap space to run the macro in reg q
noremap <Space> @q

" remap enter to put in a newline
noremap <CR> o<Esc>k

"maps <F3> to spellcheck
noremap <F3> <C-o>:setlocal spell! spelllang=en_us<CR>

" shows unwanted whitespace characters
set listchars=tab:>-,trail:~,extends:>,precedes:<
set list

" remove trailing whitespace before save
autocmd BufWritePre * :%s/\s\+$//e

" status bar configuration
set statusline+=%F      "show filename
set statusline+=%9*\ %= " Space
set statusline+=%7*\ %{(&fenc!=''?&fenc:&enc)}\[%{&ff}]\ " Encoding & Fileformat
set statusline+=%=%P\ \         "percent through file
set statusline+=%((%l,%c)%)\    "line and column (right aligned)

" Allow saving of files s sudo when I forget to start vim using sudo.
cmap w!! w !sudo tee > /dev/null %

"setup the 80 column line
if exists('+colorcolumn')
    set colorcolumn=80
else
    au BufWinEnter * let w:m2=matchadd('ErrorMsg', '\%80v.\+', -1)
endif

set scrolloff=5 "start scrolling 5 lines before bottom
set sidescrolloff=15
set sidescroll=1


" fix my cursor to look like a | in insert mode because ubuntu broke it...
if has("autocmd")
  au InsertEnter * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape ibeam"
  au InsertLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape block"
  au VimLeave * silent execute "!gconftool-2 --type string --set /apps/gnome-terminal/profiles/Default/cursor_shape block"
endif



" Below you'll see a lot of configuration for plugins. Perhaps these will be of
" interest to you?

"" YCM Stuff
"" default auto completion for c family using YCM
"let g:ycm_global_ycm_extra_conf = "~/.vim/.ycm_extra_conf.py"
"let g:ycm_server_python_interpreter = 'python3'
""let g:ycm_global_ycm_extra_conf = '/usr/share/vim/vimfiles/third_party/ycmd/cpp/ycm/.ycm_extra_conf.py'
"let g:ycm_always_populate_location_list = 1 " enable jump to errors...kinda
"
"
"" Vim Latex Stuff
"" REQUIRED. This makes vim invoke Latex-Suite when you open a tex file.
"filetype plugin on
"
"" IMPORTANT: win32 users will need to have 'shellslash' set so that latex
"" can be called correctly.
""set shellslash
"
"" OPTIONAL: This enables automatic indentation as you type.
"filetype indent on
"
"" OPTIONAL: Starting with Vim 7, the filetype of empty .tex files defaults to
"" 'plaintex' instead of 'tex', which results in vim-latex not being loaded.
"" The following changes the default filetype back to 'tex':
"let g:tex_flavor='latex'
"
"" only pdfs are needed for now
"let g:Tex_DefaultTargetFormat='pdf'
"let g:Tex_CompileRule_pdf = 'pdflatex -interaction=nonstopmode $*'
"let g:Tex_MultipleCompileFormats='pdf,bib,pdf'
"let g:Tex_ViewRule_pdf =  'zathura'
"
"
"
""Syntastic stuff
"set statusline+=%#warninmsg#
"set statusline+=%{SyntasticStatuslineFlag()}
"set statusline+=%*
"
"let g:syntastic_always_populate_loc_list = 1
"let g:syntastic_auto_loc_list = 1
"let g:syntastic_check_on_open = 0
"let g:syntastic_check_on_wq   = 0
"
"" get rid of warnings for LaTeX
"let g:syntastic_quiet_messages = {
"    \ "file:p":  ['.*\.tex'] }
"
""let g:syntastic_c_compiler = "gcc"
""let g:syntastic_c_compiler_options = "-O2 -Wall"
""
""let g:syntastic_cpp_compiler = "g++"
""let g:syntastic_cpp_compiler_options = "-O2 -Wall -std=c++11"
"
"" enable switching between version of python
"" Call these with :call PyN()
"function Py2()
"  let g:syntastic_python_python_exec = 'python2'
"endfunction
"
"function Py3()
"  let g:syntastic_python_python_exec = 'python3'
"endfunction
"
"call Py3()   " default to Py3 because I try to use it when possible
"
" map <F7>        :call Py2()<CR>
"imap <F7>   <Esc>:call Py2()<CR>
"
" map <F8>      :call Py3()<CR>
"imap <F8> <Esc>:call Py3()<CR>
