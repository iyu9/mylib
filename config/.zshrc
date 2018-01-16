# thanks to:
# https://h2ham.net/zsh-prompt-color

# ディスプレイ設定
export DISPLAY=localhost:0.0

# カラー設定
autoload colors
colors
PROMPT="%{$fg[green]%}%m%(!.#.$) %{$reset_color%}"
PROMPT2="%{$fg[green]%}%_> %{$reset_color%}"
SPROMPT="%{$fg[red]%}correct: %R -> %r [nyae]? %{$reset_color%}"
RPROMPT="%{$fg[cyan]%}[%~]%{$reset_color%}"

# コマンドエイリアス
if [ "$(uname)" = 'Darwin' ]; then
  alias ls='ls -G'
else
  alias ls='ls --color=auto'
fi

alias l='ls'
alias la='ls -a'
alias ll='ls -l'

alias -g G='| grep'
alias -g L='| less'

alias sel_vim='ls | percol | xargs vim'
alias sel_emacs='ls | percol | xargs emacs'
alias sel_less='ls | percol | xargs less'
alias sel_head='ls | percol | xargs head'
alias sel_tail='ls | percol | xargs vim'

alias reload_zsh='source ~/.zshrc'

# コマンド履歴
HISTFILE=~/.zsh_history
HISTSIZE=1000000
SAVEHIST=1000000

# コマンド履歴検索
autoload history-search-end
zle -N history-beginning-search-backward-end history-search-end
zle -N history-beginning-search-forward-end history-search-end
bindkey "^P" history-beginning-search-backward-end
bindkey "^N" history-beginning-search-forward-end

# 単語検索
function dict() {
  if [ $# != 0 ]; then
    w3m "http://eow.alc.co.jp/$*/UTF-8/?ref=sa"
  else
    w3m "http://www.alc.co.jp/"
  fi
}

# BoWショートカット
export WIN_USER=/mnt/c/Users/mobiledev
export WIN_DESKTOP=$WIN_USER/Desktop
export WIN_WORKSPACE=$WIN_USER/Source/Repos/
alias cdesk="cd $WIN_DESKTOP"

# Git
alias git_all="git add -A && git commit -m update_all && git push"
