public class Effector : MonoBehaviour
{
  [SerializeField]
  private GraphFunc func = GraphFunc.EaseInOut; //演出グラフ設定
  private enum GraphFunc
  {
    None,
    Sin,
    Cos,
    Linear,
    Curve2,
    EaseIn,
    EaseInOut,
  };

  [SerializeField]
  private EffectType type;                      //演出指定
  private enum EffectType
  {
    BlurredExpand,
    Blink,
  };

  [SerializeField]
  private EffectStep step = EffectStep.Ready;   //演出管理ステップ
  private enum EffectStep
  {
    Ready,
    Start,
    Wait,
  };

  [SerializeField]
  private float untilTime = 0.5f; //演出待ち時間
  [SerializeField]
  private float weight    = 1f;   //演出の大きさ
  [SerializeField]
  private float freq      = 1f;   //演出の反復回数

  private float waitTime  = 0f;   //演出カウント用待ち時間

  /// <summary>
  /// 演出用リスナー
  /// </summary>
  void Update()
  {
    if (step == EffectStep.Start)
    {
      step = EffectStep.Wait;

      //演出前の状態を一時保存//

      waitTime = 0;
    }

    if (step == EffectStep.Wait)
    {
      waitTime += Time.deltaTime;

      float normalizedTime = waitTime / untilTime;
      float f = GetGraphFunc(normalizedTime);

      //e.g. エフェクトをかける対象コンポーネント
      //Color colorBlurred = txtTurn.color;
      //colorBlurred.a = (1f - normalizedTime);
      //txtTurn.color = colorBlurred;
      //txtTurn.transform.localScale = (1 + f) * Vector3.one;

      if (waitTime > untilTime)
      {
        waitTime = 0;

        //演出開始前の状態復元//

        step = EffectStep.Ready;
      }
    }
  }

  /// <summary>
  /// ターン用エフェクトを開始します。
  /// </summary>
  /// <param name="effectType"></param>
  /// <returns>成功or失敗</returns>
  public bool StartEffect()
  {
    if (step == EffectStep.Ready)
    {
      type = EffectType.BlurredExpand;
      step = EffectStep.Start;
      return true;
    }

    return false;
  }

  /// <summary>
  /// 簡易グラフカーブ選択
  /// </summary>
  /// <param name="normalizedTime">[0,1]に正規化した経過時間</param>
  private float GetGraphFunc(float normalizedTime)
  {
    float PI = Mathf.PI;
    float t = normalizedTime;

    switch (func)
    {
      case GraphFunc.None:
        return 0;

      case GraphFunc.Sin:
        return weight * Mathf.Sin(2 * PI * freq * t);

      case GraphFunc.Cos:
        return weight * Mathf.Cos(2 * PI * freq * t);

      case GraphFunc.Linear:
        return weight * t;

      case GraphFunc.Curve2:
        return weight * -4 * t * (t - 1);

      case GraphFunc.EaseIn:
        return weight * t * (2 - t);

      case GraphFunc.EaseInOut:
        return weight * (t * t) * (3 - 2 * t);

      default:
        return normalizedTime;
    }
  }
}

