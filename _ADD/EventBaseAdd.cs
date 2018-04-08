using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// ADV機能に付け足してね。
/// あとbtn管理追加してください
/// </summary>
public class EventBaseAdd : MonoBehaviour
{
	//これは既存
	public List<string> textList;
	public int textIndex;

	private const string MessageLogPopupPrefabPath = "Prefabs/HomeView/Event/MessageLogPopup";
	private MessageLogPopup messageLogPopup;

	//ADVログ表示ポップアップを生成します。
	private void CreateMessageLogPopup()
	{
		/*
		isLockScreen = true;

		isPause = false;
		btnSkip.IsEnable = false;
		btnAuto.IsEnable = false;
		btnSpeedUp.IsEnable = false;
		btnMessageLog.IsEnable = false;
		*/
		var prefab = Resources.Load<MessageLogPopup>(MessageLogPopupPrefabPath);
		messageLogPopup = Instantiate<MessageLogPopup>(prefab);
		messageLogPopup.transform.SetParent(this.transform, false);

		messageLogPopup.Init(textList, textIndex);
	}

	//ADVログ表示ポップアップを閉じた際に呼ばれます。
	private void OnCloseMessageLogPopup(int act)
	{
		/*
		isPause = false;
		btnSkip.IsEnable = true;
		btnAuto.IsEnable = true;
		btnSpeedUp.IsEnable = true;
		btnMessageLog.IsEnable = true;

		Destroy(messageLogPopup.gameObject);
		messageLogPopup = null;
		isLockScreen = false;
		*/
	}
}
