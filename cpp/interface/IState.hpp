class IState
{
  public:
    bool PrevState(IState* state);
    bool NextState(IState* state);
    bool Intput(IState* param);
};
