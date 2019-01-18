// created by snowcat.c 5/23/1997
// room: /d/pantao/fengb.c

#define MAXPOSITION 7

inherit ROOM;

void create ()
{
  set ("short", "����̨");
  set ("long", @LONG

                      �����̨��

������̨Ρ����ΰ����赻Ի͡�ֻ�������̳������������ϻϣ�
������ʥ�������������󸨡��������������������������
�Ⱚ�����ڴ������Ʈ����������������������������������ߡ�

LONG);

  set("exits", ([
        "north" : __DIR__"palace7",
        "west"  : __DIR__"fenga",
        "east"  : __DIR__"fengc",
      "out" :"/d/dntg/yaochi/wmj6",
      ]));

  set("objects", ([
         __DIR__"npc/male"   : 1,
         __DIR__"npc/female" : 1,
      ]));

  remove_call_out ("reset_long");
  call_out ("reset_long",1,this_object());
  remove_call_out ("drop_zishoulu");
  call_out ("drop_zishoulu",10);
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
  int i, j;
  string str = @LONG

                      �����̨��

������̨Ρ����ΰ����赻Ի͡�ֻ�������̳������������ϻϣ�
������ʥ�������������󸨡��������������������������
�Ⱚ�����ڴ������Ʈ����������������������������������ߡ�

          �ԡԡԡԡԡԡԷ����ԡԡԡԡԡԡ�
LONG;

  seteuid(getuid());
  if (where == 0)
    where = this_object ();

  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = __DIR__"npc/tian"+sprintf("%d",i);
    string s;
    object ob = find_object(npc);
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob &&
        s = ob->query("short"))
    {
      string honor;
      sscanf(s, "%s(%s", honor, s);
      s = ob->query("current_player");
      if (s != "none of us")
      {
        honor = honor + " " + s;
        for (j = strlen(honor); j < 30; j++)
          honor = honor + " ";
        str = str + "            " + honor + "   \n";
      }
    }
  }
  str = str + "          �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n\n";
  where->set("long",str);
}

int do_look ()
{
  object where = this_object();

  reset_long(where);
  return 0; // return 0 to invoke normal commands
}

void drop_zishoulu ()
{
  int i, j;
  object who;
  object *list;

  remove_call_out("drop_zishoulu");
  call_out("drop_zishoulu",random(7200)+7200);
  list = users();
  j = 100;
  while  (j--)
  {
    string there;

    i = random(sizeof(list));
    if (!environment(list[i]))
      continue;
    if (!living(list[i]))
      continue;

    who = list[i];
    break;
  }
  if (! who)
    return;
  //who = find_living ("snowcat");
  remove_call_out ("zishoulu_fly");
  call_out ("zishoulu_fly",2,who,"���з·���ʲô��ɫ�Ķ���Ʈ������\n");
  call_out ("zishoulu_fly",6,who,"һ����ɫ�д���Ķ��������Ʈ����������\n");
  call_out ("zishoulu_fly",10,who,"����أ���ɫ�д�Ʈ��$N��ͷ�ϡ�\n");
  remove_call_out ("zishoulu_drop");
  call_out ("zishoulu_drop",12,who);
}

void zishoulu_fly (object who, string msg)
{
  message_vision (msg,who);
}

void zishoulu_drop (object who)
{
  string str = __DIR__;
  object ob;

  ob = new (str+"obj/zishoulu");
  message_vision ("��ɫ�д�Ʈ��$N�Ļ��С�\n",who);
  ob->move(who);
}

