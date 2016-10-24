class Camera
{
  public:
    float waitTime = 0f;
    
    float sec = 1.5f;
    float amp = 1f;
    float freq = 20f;

    /*
     * カメラの振動を開始します。
     * sec_ : 振動時間
     * amp_ : 振幅
     * freq_: 振動数
     */
    void StartShakeCamera(float sec_, float amp_, float freq_)
    {
        sec = sec_;
        amp = amp_;
        freq = freq_;   
    }
    
    void Update()
    {
        if (waitTime > 0f)
        {
            waitTime -= 0.000001f;       
        }else
        {
            waitTime = 0f;        
        }        
    }     
};
