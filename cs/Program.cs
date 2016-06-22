using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SampleGame
{
  public class Tile {
    private int id;
    private int type;
    private int eventId;
    private string imgTile;

    public Tile() {
      id = type = eventId = 0;
      imgTile = "";
    }
  }

  public class Cell
  {
    public int id;
    public int x, y;
    public int w, h;
    public byte[,] matrix;
    public Node<Cell> node;

    public Cell()
    {
      Random rand = new Random();

      this.x = rand.Next(0, 100);
      this.y = rand.Next(0, 100);

      this.w = rand.Next(4, 10) ;
      this.h = rand.Next(4, 10) ;
    }

    public void Print() { 
      
    }
  }

  public class Node<Type> {
    private int id;
    private Type[] prev;
    private Type[] next;

    public Node(int id, Type[] prev, Type[] next) {
      this.id = id;
      this.prev = prev;
      this.next = next;
    }
  }

  public class Map {

    private byte w;
    private byte h;

    private byte[,] matrix;

    public Map(byte w, byte h) 
    {
      this.w = w;
      this.h = h;

      Init();
    }

    private void Init()
    {
      matrix = new byte[w, h];

      for(int y=0; y<10; y++)
      {
        for(int x=0; x<10; x++)
        {
          if (x == 0 || y == 0 || x == w-1 || y == h-1)
          {
            matrix[x, y] = 1;
          }
          else 
          {
            matrix[x, y] = 0;
          }
        }
      }
    }

    public void Print(Actor[] actors)
    {
      for (int y = 0; y < h; y++)
      {
        for (int x = 0; x < h; x++)
        {
          bool isOverlay = false;
          foreach(var actor in actors)
          {
            if (x == actor.x && y == actor.y)
            {
              isOverlay = true;
              System.Console.Out.Write("@");
              break;
            }
          }
          if (isOverlay) {
            //
          }
          else if (matrix[x, y] == 1)
          {
            System.Console.Out.Write("#");
          }
          else {
            System.Console.Out.Write(" ");
          }
        }

        System.Console.Out.WriteLine("");
      }      
    }
  }

  public class Actor {
    int id;
    string name;
    int hp;
    int atk;
    int def;

    public int x, y;

    public Actor()
    {
      this.name = "NO_NAME";
      hp = 10;
      x = y = 1;
    }

    public Actor(string name)
    {
      this.name = name;
      hp = 10;
      x = y = 1;

      if (name == "X")
      {
        hp = 6;
        atk = 5;
        def = 5;
      }
      else {
        hp = 99;
        atk = 10;
        def = 10;
      }
    }

    public void OnDamage(Actor op)
    {
      int damage = (op.atk - this.def);
      damage = (damage > 0) ? damage : 1;
      hp -= (op.atk - this.def);

      System.Console.Out.WriteLine("DAMAGE: " + damage);      

      if(hp <= 0)
      {
        System.Console.Out.WriteLine("DEAD: " + name);
      }
    }

    public void Print() 
    {
      System.Console.Out.WriteLine("NAME: " + name);
      System.Console.Out.WriteLine("HP: " + hp);
    }

    public Actor[] Search(Map map, Actor enemys)
    {
      return null;
    }
  }

  public class BattleScene {

    private Map map;
    private Actor[] allys;
    private Actor[] enemys;

    private bool isQuit = false;
    public bool IsQuit 
    {
      get {
        return isQuit;
      }
    }

    private BattleState state = BattleState.Intro;
    private enum BattleState
    { 
      Intro,
      MyTurn,
      MyUnitControl,
      EnemyTurn,
      Outro,
      Exit,
    }

    public BattleScene()
    {
      map = new Map(10, 10);
      allys = new Actor[1];
      allys[0] = new Actor("j-gun");
      enemys = new Actor[1];
      enemys[0] = new Actor("X");
    }

    public void Update()
    {
      //STATE
      WL(state.ToString());

      map.Print(allys);

      if(state == BattleState.EnemyTurn)
      {
        state = BattleState.MyTurn;
      }
    }

    private string RL()
    {
      return System.Console.In.ReadLine();
    }
    private void WL(string str)
    {
      System.Console.Out.WriteLine(str);
    }

    public void Input()
    {
      string cmd = RL();

      if (cmd == "q")
      {
        isQuit = true;
      }

      if (cmd == "te")
      {
        WL("TurnEnd");
        state = BattleState.EnemyTurn;
      }

      if (cmd == "mv")
      {
        WL("Num: ");
        string num = RL();

        state = BattleState.MyUnitControl;
      }

      if (cmd == "wait")
      {
        WL("WAIT");
        state = BattleState.EnemyTurn;
      }


      if (cmd == "atack")
      {
        WL("ATACK");

        enemys[0].OnDamage(allys[0]);

        allys[0].Print();
        enemys[0].Print();

        state = BattleState.EnemyTurn;
      }

      if (cmd == "n")
      {
        state++;
      }

      if (cmd == "p")
      {
        state--;
      }
    }

    public void Render() 
    {
      WL("RENDER");
    }
  }

  class Program
  {
    public static void Main(string[] args)
    {
      BattleScene bs = new BattleScene();

      while (!bs.IsQuit)
      {
        bs.Input();
        bs.Update();
        bs.Render();
      }
    }
  }
}
