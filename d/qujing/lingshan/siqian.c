//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��ǰ");
  set ("long", @LONG

ֻ������������ǰΪһ�㳡��һ·������������觻�ש���㳡
������ɼ����������﹬�����������𡣶�������Գժ������
�֣������а׺�������֦ͷ�������вʷ�˫˫������һ������
�𣬳��������Զԣ�ӭ��ҫ������ϡ��

LONG);

  set("exits", ([
        "north"   : __DIR__"shandian",
        "south"   : __DIR__"yimen",
      ]));
  set("objects", ([
        __DIR__"npc/anuo" : 1,
        __DIR__"npc/jiaye" : 1,
     ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  object where = this_object ();
  object anuo = present ("anuo zunzhe",where); 
  object jiaye = present ("jiaye zunzhe",where); 

  if (dir == "north")
    return ::valid_leave (who, dir);

  if (who->query_temp("obstacle/lingshan_enter"))
    return ::valid_leave (who, dir);

  if (anuo)
    return notify_fail ("���н����������ҷ����ݲ�����Ҳ��\n");
  if (jiaye)
    return notify_fail ("��Ҷ�����������ҷ����ݲ�����Ҳ��\n");
  return ::valid_leave (who, dir);
}

