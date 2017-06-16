mkdir ~/.vim
mkdir ~/.vim/colors

git clone https://github.com/tomasr/molokai
cp molokai/colors/molokai.vim ~/.vim/colors/
rm -rf molokai

echo "PLEASE_WRITE_.vimrc => colorscheme molokai"
