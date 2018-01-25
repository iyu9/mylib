## 参考ページ:
- JokerScript
> http://jokerscript.jp/adv/next/scene  
> http://jokerscript.jp/home/tag  

- 宴
> http://madnesslabo.net/utage/?page_id=402

## 宴利用方法

- unitypackageをインポートして、プロジェクトに組み込みます。
- using Novel; を追加
- NovelSingleton.StatusManager.callJoker("scenerioname", "");を呼び出してJokerScript処理に遷移

## 注意点

### 宴

- ADVシナリオ呼び出し時に、専用のシーンへの遷移が発生する。
シーンの遷移自体は大きな問題にはならない。（ただし、再度HomeViewに遷移しなおす必要がある）

- ADVシナリオが（当然だが）ローカルからのリソースフォルダの読み込み処理になっているため、
アセットバンドルからの読み込みに対応する必要がある。
シナリオをパース直後のリソース割り当て処理を改変できる？

## JokerScript利用方法

- using Utage; を追加
- Engine.JumpScenario(scenarioName);

どちらのエンジンでも立ち絵、背景のアセットバンドル対応は必要。
この初期化処理が非同期になるため、対処可能かを調査する。
JokerScriptは[storage]コマンドの引数に入れて読み込んでいるため、
その周りを調査する。

## 調査結果等
- L72 ImageObject.set(Dictionary<string, string> param)内で画像リソースの共通読み込みを行っている。
立ち絵、背景についてはここだけ変更できないかどうか。

- WebPlayerの対応が怪しい？マクロで画像を読み込んでいない。

