// localStorageが使用出来るかチェック
if (!window.localStorage) {
    alert("お使いのブラウザはlocalstorageに対応してません");
}

// localStorageに値を保存
function setItem(key, val) {
    window.localStorage.setItem(key, val);
}

// localStorageから値を取得
function getItem(key) {
    return window.localStorage.getItem(key);
}

// localStorageに保存されているあるkeyの値を削除する
function removeItem(key) {
    window.localStorage.removeItem(key);
}

// localStorageに保存されているすべての値を削除する
function clear() {
    window.localStorage.clear();
}
