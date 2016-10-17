using UnityEngine;
using UnityEngine.UI;
using System.Collections;

/// <summary>
/// デジタル表示セグメント管理
/// </summary>
public class DigitSegments : MonoBehaviour
{
  [SerializeField]
  private Image[] imgSegment;

  private enum Segment
  {
    A, B, C, D, E, F, G, Count
  }

  private readonly int[] Pattern0 =
  {
    1,1,1,1,1,1,0
  };
  private readonly int[] Pattern1 =
  {
    0,1,1,0,0,0,0
  };
  private readonly int[] Pattern2 =
  {
    1,1,0,1,1,0,1
  };
  private readonly int[] Pattern3 =
  {
    1,1,1,1,0,0,1
  };
  private readonly int[] Pattern4 =
  {
    0,1,1,0,0,1,1
  };
  private readonly int[] Pattern5 =
  {
    1,0,1,1,0,1,1
  };
  private readonly int[] Pattern6 =
  {
    1,0,1,1,1,1,1
  };
  private readonly int[] Pattern7 =
  {
    1,1,1,0,0,1,0
  };
  private readonly int[] Pattern8 =
  {
    1,1,1,1,1,1,1
  };
  private readonly int[] Pattern9 =
  {
    1,1,1,1,0,1,1
  };

  private readonly int[] ErrorPattern =
  {
    1,0,0,1,1,1,1
  };

  private int[] GetSegmentsPattern(int number)
  {
    switch(number)
    {
      case 0:
        return Pattern0;
      case 1:
        return Pattern1;
      case 2:
        return Pattern2;
      case 3:
        return Pattern3;
      case 4:
        return Pattern4;
      case 5:
        return Pattern5;
      case 6:
        return Pattern6;
      case 7:
        return Pattern7;
      case 8:
        return Pattern8;
      case 9:
        return Pattern9;
      default:
        return ErrorPattern;
    }
  }

  /// <summary>
  /// デジタル表示更新時のルーレット処理コルーチン
  /// </summary>
  private IEnumerator IERandomize(int resultNum, float interval, int times)
  {
    for (int i = 0; i <= times; i++)
    {
      SetNumber(Random.Range(0, 10));
      yield return new WaitForSeconds(interval);
    }

    SetColor(resultNum);
    SetNumber(resultNum);
  }

  /// <summary>
  /// デジタル表示の数字をセットします。
  /// </summary>
  /// <param name="number"></param>
  private void SetNumber(int number)
  {
    int[] pattern = this.GetSegmentsPattern(number);

    for (int i = 0; i < (int)Segment.Count; i++)
    {
      imgSegment[i].enabled = (pattern[i] > 0);
    }
  }

  /// <summary>
  /// デジタル表示の色をセットします。
  /// </summary>
  /// <param name="number"></param>
  private void SetColor(int number)
  {
    if (number < 99)
    {
      for(int i = 0; i < (int)Segment.Count; i++)
      {
        imgSegment[i].color = Color.green;
      }
    }

    if (number < 4)
    {
      for (int i = 0; i < (int)Segment.Count; i++)
      {
        imgSegment[i].color = Color.yellow;
      }
    }

    if (number < 2)
    {
      for (int i = 0; i < (int)Segment.Count; i++)
      {
        imgSegment[i].color = Color.red;
      }
    }
  }

  /// <summary>
  /// デジタル表示更新時のルーレット開始
  /// </summary>
  public void StartUpdateNumber(int num, float interval, int times)
  {
    StartCoroutine(IERandomize(num, interval, times));
  }

#if DEBUG_FUNCTION
  void Update()
  {
    if (Input.GetKeyUp(KeyCode.A))
    {
      StartUpdateNumber(0, 0.02f, 10000);
    }
  }
#endif

/*
#if DEBUG_FUNCTION
  /// <summary>
  /// デバッグ確認用
  /// </summary>
  void OnGUI()
  {
    if (GUI.Button(new Rect(0, 0, 200, 60), new GUIContent("DIGIT_0")))
    {
      StartUpdateNumber(0);
    }

    if (GUI.Button(new Rect(0, 65, 200, 60), new GUIContent("DIGIT_1")))
    {
      StartUpdateNumber(1);
    }

    if (GUI.Button(new Rect(0, 130, 200, 60), new GUIContent("DIGIT_2")))
    {
      StartUpdateNumber(2);
    }

    if (GUI.Button(new Rect(0, 195, 200, 60), new GUIContent("DIGIT_3")))
    {
      StartUpdateNumber(3);
    }

    if (GUI.Button(new Rect(0, 260, 200, 60), new GUIContent("DIGIT_4")))
    {
      StartUpdateNumber(4);
    }

    if (GUI.Button(new Rect(0, 325, 200, 60), new GUIContent("DIGIT_5")))
    {
      StartUpdateNumber(5);
    }

    if (GUI.Button(new Rect(0, 390, 200, 60), new GUIContent("DIGIT_6")))
    {
      StartUpdateNumber(6);
    }

    if (GUI.Button(new Rect(0, 455, 200, 60), new GUIContent("DIGIT_7")))
    {
      StartUpdateNumber(7);
    }

    if (GUI.Button(new Rect(0, 520, 200, 60), new GUIContent("DIGIT_8")))
    {
      StartUpdateNumber(8);
    }

    if (GUI.Button(new Rect(0, 585, 200, 60), new GUIContent("DIGIT_9")))
    {
      StartUpdateNumber(9);
    }
  }
#endif
 */
}

