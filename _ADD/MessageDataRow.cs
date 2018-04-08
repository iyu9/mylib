using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// ADVのメッセージログ行の表示を行います。
/// </summary>
public class MessageDataRow : MonoBehaviour
{
	[SerializeField]
	public Text txtMessage;

	//会話ログの整形を行います。改行を反映すれば問題ないはずなので、そのまま表示する。
	public void Init(string msg)
	{
		string formatMessage = msg.Replace("¥n", "\n");
		txtMessage.text = formatMessage;
	}
}
