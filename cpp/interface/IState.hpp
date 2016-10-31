class IState
{
  public:
    bool PrevState(IState* state);
    bool NextState(IState* state);
    bool Input(int cmd);
};
