///
/// <summary>エフェクト管理</summary>
///
public class EffectManager : MonoBehaviour
{
    private Gameobject effectCache = null;

    public void CreateEffect()
    {
        Object.Destroy(effectCache);

        effectCache = Object.Instantiate<GameObject>("hoge/piyo/fuga");
        effectCache.transform.localPosition = Vector3.zero;
        effectCache.transform.localScale = Vector3.one;
    }

    public void DeleteEffect()
    {
        Object.Destroy(effectCache);
        effectCache = null;
    }
}
