using UnityEngine;
using UnityEngine.UI;
using System.Collections;

/// <summary>
/// 移動処理テスト
/// </summary>
public class MoveTest : MonoBehaviour
{
  void Start()
  {
    Vector2 dest = new Vector2(300, 300);
    StartMove(this.gameObject, dest, 1f);
  }

  /// <summary>
  /// 移動開始
  /// </summary>
  /// <param name="obj">対象オブジェクト</param>
  /// <param name="dest">目的地</param>
  /// <param name="seconds">秒数</param>
  public void StartMove(GameObject obj, Vector2 dest, float seconds)
  {
    StartCoroutine(WaitForMove(obj, dest, seconds));
  }

  /// <summary>
  /// 移動処理
  /// </summary>
  private IEnumerator WaitForMove(GameObject obj, Vector2 dest, float seconds)
  {
    Vector2 startPos = obj.transform.localPosition;
    Vector2 endPos = dest;

    float timer = 0f;
    float normalizedTime = (timer / seconds);

    while (normalizedTime < 1)
    {
      timer += Time.deltaTime;
      normalizedTime = (timer / seconds);
      obj.transform.localPosition = Vector2.Lerp(startPos, endPos, normalizedTime);
      yield return null;
    }
    obj.transform.localPosition = endPos;

    yield break;
  }
  /// <summary>
  /// 移動処理(UI)
  /// </summary>
  private IEnumerator WaitForMoveUI(GameObject obj, Vector2 dest, float seconds)
  {
    Vector2 startPos = obj.GetComponent<RectTransform>().anchoredPosition;
    Vector2 endPos = dest;

    float timer = 0f;
    float normalizedTime = (timer / seconds);

    while (normalizedTime < 1)
    {
      timer += Time.deltaTime;
      normalizedTime = (timer / seconds);
      obj.transform.localPosition = Vector2.Lerp(startPos, endPos, normalizedTime);
      yield return null;
    }
    obj.transform.localPosition = endPos;

    yield break;
  }
}

