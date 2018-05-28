暗黙的なリンクと明示的なリンクの両方で、Windows は、Kernel32.dll や User32.dll などの "既知の DLL" を最初に検索します。 次に、以下に示す順序で DLL が検索されます。
1. 実行中のプロセスの実行形式モジュールがあるフォルダー。
2. 現在のフォルダー。
3. Windows システム フォルダー。 このフォルダーへのパスは、GetSystemDirectory 関数が取得します。
4. Windows ディレクトリ。 このフォルダーへのパスは、GetWindowsDirectory 関数が取得します。
5. 環境変数 PATH 内に記述されたフォルダー。
