using UnityEngine;
using UnityEngine.Events;
using UnityEngine.UI;
using System.Collections.Generic;

/// <summary>
/// ADVの会話ログ確認ポップアップ
/// </summary>
public class MessageLogPopup : MonoBehaviour//BasePopup
{
	[SerializeField]
	private /*UIImageButton*/Button btnClose;
	[SerializeField]
	private ScrollRect scrMessageLogs;

	private const string MessageDataRowPath
		//= "Prefabs/HomeView/Event/MessageDataRow";
		= "MessageDataRow";

	/// <summary>
	/// ポップアップの初期化を行います。
	/// </summary>
	public void Init (List<string> textList, int textIdx)
	{
		SetCallbacks ();
		CreateList (textList, textIdx);
	}

	private void SetCallbacks ()
	{
		btnClose.onClick.AddListener (OnClose);
	}

	/// <summary>
	/// 過去のログメッセージのリストを作成します。
	/// </summary>
	private void CreateList (List<string> textList, int currentMsgIdx)
	{
		int idx = 0;
		foreach (var message in textList)
		{
			var prefab = Resources.Load<MessageDataRow> (MessageDataRowPath);
			var row = Instantiate<MessageDataRow>(prefab);
			row.Init (message);
			row.transform.SetParent(scrMessageLogs.content, false);

			if (idx >= currentMsgIdx)
			{
				break;
			}
			idx++;
		}
	}

	private void OnClose ()
	{
		//this.Hide ();

		/* NOT LAST USE*/
		Destroy (this.gameObject);
	}

	/// <summary>
	/// ポップアップクローズアニメーション完了時にコールされます。
	/// </summary>
	public /*override*/ void FinishHideAnimation ()
	{
		/*
		base.FinishHideAnimation ();
		if (this.PopUpActCallBack != null) {
			this.PopUpActCallBack (0);
		}
		*/
	}
}