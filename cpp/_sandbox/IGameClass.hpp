const int RENDER_TYPE_NONE = 0;
const int RENDER_TYPE_RECT = 1;
const int RENDER_TYPE_POLY = 2;

/*
** 描画機能コンポーネント
*/
class Renderer
{
private:
  int type;             //描画タイプ
  float vertices[99];   //頂点データ
  float texture[99];    //テクスチャデータ

public:
  Renderer()
  {
    type = RENDER_TYPE_RECT;
  }
  Renderer(int type_)
  {
    type = type_;
  }
  Renderer(int type_, float* vertices)
  {
    type = type_;
    vertices = vertices;
  }
  ~Renderer(){}

  /*
  ** 描画メソッド選択
  */
  void RenderMethod(int type_)
  {
    switch (type_)
    {
      case RENDER_TYPE_NONE:
        break;

      case RENDER_TYPE_RECT:
        break;

      case RENDER_TYPE_POLY:
        break;
    }
  }

  /*
  ** 描画処理
  */
  void Render()
  {
    RenderMethod(this->type);
  }
};

/*
** オブジェクトクラス
*/
class Object
{
private:
  int id;
  std::string name;
  Renderer renderer;
  float x, y, z, w;

public:
  Object(){}
  ~Object(){}

  void Render()
  {
    renderer.Render();
  }
};

/*
** シーン単体クラス
*/
class Scene
{
private:
  int id;
  std::string name;
  Object object[99];

public:

  Scene(){}
  ~Scene(){}

  /*
  ** 描画更新
  */
  void Render()
  {
    for (int i = 0; i < 99; i++)
    {
      object[i].Render();
    }
  }
};


/*
** シーン管理クラス
*/
class SceneManager
{
private:
  Scene currentScene;

  Scene LoadScene(std::string name)
  {
    
  }

public:
  Scene Instance(){}

  void ChageScene(std::string name)
  {
    
  }
};

/*
** DirectXグラフィックス管理クラス
*/
class DXManager
{
private:
  HWND                    m_hWnd = nullptr;
  LPDIRECT3D9             m_pD3D = nullptr;
  LPDIRECT3DDEVICE9       m_pDev = nullptr;

  /*
  ** 初期化処理
  */
  HRESULT Initialize(HWND hWnd, LPDIRECT3D9 pD3D, LPDIRECT3DDEVICE9 pDev)
  {
    
  }

  /*
  ** 解放処理
  */
  HRESULT Release()
  {

  }

  /*
  ** シーン中の描画可能オブジェクトの描画を実行する
  */
  void Render()
  {
    
  }
};

/*
** DirectX入力管理クラス
*/
class DXInputManager
{
private:
  LPDIRECTINPUT8 m_pDInput;
  LPDIRECTINPUTDEVICE8 m_pDIDevice;

public:
  HRESULT Initialize(HINSTANCE hInstance)
  {
    if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDInput, nullptr)))
    {
      return E_FAIL;
    }
    if (FAILED(m_pDInput->CreateDevice(GUID_SysKeyboard, &m_pDIDevice, nullptr)))
    {
      return E_FAIL;
    }

    m_pDIDevice->SetDataFormat(&c_dfDIKeyboard);
    m_pDIDevice->SetCooperativeLevel(g_hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
    m_pDIDevice->Acquire();

    return S_OK;
  }

  HRESULT Release()
  {
    SAFE_RELEASE(m_pDInput);
    SAFE_RELEASE(m_pDIDevice);
  }

  void CheckInput()
  {
    const int MOVE_DIST = 4;

    HRESULT hr;
    BYTE diKeyState[256];

    hr = m_pDIDevice->GetDeviceState(256, diKeyState);

    if (SUCCEEDED(hr))
    {
      if (diKeyState[DIK_LEFT] & 0x80)
      {
        g_message = "LEFT";
        pos.x -= MOVE_DIST;
      }

      if (diKeyState[DIK_RIGHT] & 0x80)
      {
        g_message = "RIGHT";
        pos.x += MOVE_DIST;
      }

      if (diKeyState[DIK_UP] & 0x80)
      {
        g_message = "UP";
        pos.y += MOVE_DIST;
      }

      if (diKeyState[DIK_DOWN] & 0x80)
      {
        g_message = "DOWN";
        pos.y -= MOVE_DIST;
      }

      if (diKeyState[DIK_LSHIFT] & 0x80)
      {
        g_message = "SHIFT";
      }

      if (diKeyState[DIK_Z] & 0x80)
      {
        g_message = "Z";
        pos.z += MOVE_DIST;
      }

      if (diKeyState[DIK_X] & 0x80)
      {
        g_message = "X";
        pos.z -= MOVE_DIST;
      }

      if (diKeyState[DIK_C] & 0x80)
      {
        g_message = "C";
      }
    }
    else
    {
      m_pDIDevice->Acquire();
    }
  }
};
DXInputManager inputManager;

/*
** DirectX音声管理クラス
*/
class DXSoundManager
{
  HRESULT Initialize()
  {
  
  }

  HRESULT Release()
  {

  }

  void Play()
  {
  
  }
};

/*
** テキスト
*/
class DXFont
{
private:
  LPD3DXFONT m_font;

public:
  HRESULT Initialize()
  {
    //ひとまず固定パラメータ
    if (FAILED(D3DXCreateFont(
      g_pDev, 24, 0, FW_HEAVY, 1, false, SHIFTJIS_CHARSET, OUT_TT_ONLY_PRECIS,
      ANTIALIASED_QUALITY, FF_DONTCARE, "ＭＳ ゴシック", &m_font)))
    {
      return(E_FAIL);
    }
    return S_OK;
  }

  HRESULT Release()
  {
    SAFE_RELEASE(m_font);
  };

  LPD3DXFONT GetFont()
  {
    return m_font;
  }
};

/*
** スプライト
*/
class DXSprite
{
private:
  LPD3DXSPRITE m_sprite;

public:
  HRESULT Initialize()
  {
    if (FAILED(D3DXCreateSprite(g_pDev, &m_sprite)))
    {
      return E_FAIL;
    }
    return S_OK;
  }

  HRESULT Release()
  {
    SAFE_RELEASE(m_sprite);
  }

  LPD3DXSPRITE GetSprite()
  {
    return m_sprite;
  }
};
