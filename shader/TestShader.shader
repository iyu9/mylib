Shader "Custom/Sprite/TestShader"
{
  Properties
  {
    [PerRendererData] _MainTex ("Sprite Texture", 2D) = "white" {}
    _Color ("Tint", Color) = (1,1,1,1)
    _AddLevel ("ColorAddLevel", Range(0.0,1.0)) = 0.0
    _AddLevelMax ("AddLevelMax",Float) = 0.3
    [MaterialToggle] PixelSnap ("Pixel snap", Float) = 0
  }

  SubShader
  {
    Tags
    { 
      "Queue"="Transparent" 
      "IgnoreProjector"="True" 
      "RenderType"="Transparent" 
      "PreviewType"="Plane"
      "CanUseSpriteAtlas"="True"
    }

    Cull Off
    Lighting Off
    ZWrite Off
    Blend One OneMinusSrcAlpha

    Pass
    {
    CGPROGRAM
      #pragma vertex vert
      #pragma fragment frag
      #pragma multi_compile _ PIXELSNAP_ON
      #include "UnityCG.cginc"
      
      struct appdata_t
      {
        float4 vertex   : POSITION;
        float4 color    : COLOR;
        float2 texcoord : TEXCOORD0;
      };

      struct v2f
      {
        float4 vertex   : SV_POSITION;
        fixed4 color    : COLOR;
        half2 texcoord  : TEXCOORD0;
      };
      
      fixed4 _Color;

      v2f vert(appdata_t IN)
      {
        v2f OUT;
        OUT.vertex = mul(UNITY_MATRIX_MVP, IN.vertex);
        OUT.texcoord = IN.texcoord;
        
		//TEST
        OUT.texcoord.x += 0.25 * sin(3.14 * IN.texcoord.y + _Time[3]);
		//
        OUT.color = IN.color * _Color;
        #ifdef PIXELSNAP_ON
        OUT.vertex = UnityPixelSnap (OUT.vertex);
        #endif

        return OUT;
      }

      sampler2D _MainTex;
      sampler2D _AlphaTex;
      float _AlphaSplitEnabled;
      float _AddLevel;
      float _AddLevelMax;

      fixed4 SampleSpriteTexture (float2 uv)
      {
        fixed4 color = tex2D (_MainTex, uv);
        if (_AlphaSplitEnabled)
          //color.a = tex2D (_AlphaTex, uv).r;
          color.a = 1;
        return color;
      }

      fixed4 frag(v2f IN) : SV_Target
      {
        fixed4 tex = tex2D(_MainTex, IN.texcoord);
        fixed4 c = SampleSpriteTexture (IN.texcoord) * IN.color;
        c.rgb = tex.rgb * IN.color.rgb + (_Color.rgb * lerp(0, _AddLevel, _AddLevelMax));

		//TEST
        //c.rgb *= sin(2.0 * 3.14 * _Time[1]); //c.a;
		
		//BIZ
		c.rgb *= c.a;
        return c;
      }
    ENDCG
    }
  }
}
