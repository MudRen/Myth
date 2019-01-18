// created by snowcat 10/05/1997
// room: /d/huanggong/fst.c

inherit ROOM;

#define MAXCATEGORY 5
#define MAXPOSITION 3

string *categories = ({
  "���",
  "����",
  "ͭ��",
  "����",
  "����",
 });

string *positions = ({
  "״Ԫ",
  "����",
  "̽��",
 });

void create ()
{
  set ("short", "�����");

  set ("long", @LONG

�������̵���ţ����ָ��࣬�ڹ��¹ڳ������侲��������һ
Ⱥ��Ů������Ʈ������裬������˫��˫�����̨�����������
Ƕ��׺�麺���񾫵�����״Ԫ���

LONG);

  set("exits", ([
        "north" : __DIR__"ywc5b",
        "southwest"  : __DIR__"yhy1a",
        "southeast"  : __DIR__"yhy1b",
      ]));

  set("objects", ([
         __DIR__"npc/pang"   : 1,
      ]));

  remove_call_out ("reset_long");
  call_out ("reset_long",1,this_object());
  setup();
}

void reset_long (object where);

void init()
{
  add_action("do_look", "look");
  reset_long(this_object());
}

void reset_long (object where)
{
  int i, j, k;
  string str = @LONG

��������̵���ţ����ָ��࣬�ڹ��¹ڳ������侲��������һ
Ⱥ��Ů������Ʈ������裬������˫��˫�����̨�����������
Ƕ��׺�麺���񾫵�����״Ԫ���

          ����������������������������������

LONG;

  seteuid(getuid());

  if (where == 0)
    where = this_object ();

  for (i = 1; i <= MAXCATEGORY; i++)
  {
    int found_player = 0;
    for (j = 1; j <= MAXPOSITION; j++)
    {
      string npc = __DIR__"npc/wu"+sprintf("%d%d",i,j);
      string s;
      object ob = find_object(npc);
      if (! ob ||
          ! ob->restore())
        ob = new (npc);
      if (ob)
      {
        string honor = categories[i-1]+positions[j-1];
        s = ob->query("current_player");
        if (s != "none of us")
        {
          honor = honor + " " + ob->query("name") + " " + s;
          for (k = strlen(honor); k < 30; k++)
            honor = honor + " ";
          str = str + "            " + honor + "   \n";
          found_player = 1;
        }
      }
    }
    if (found_player)
      str = str + "\n";
  }
  str = str + "          ����������������������������������\n\n";
  where->set("long",str);
}

int do_look ()
{
  object where = this_object();

  reset_long(where);
  return 0; // return 0 to invoke normal commands
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="pang xuanling" &&
      (dir=="southeast" || dir=="southwest")) 
    return 0;
  return 1;
}

