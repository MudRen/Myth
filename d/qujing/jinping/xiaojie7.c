// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С��");
  set ("long", @LONG

����������·�ڵ�С�֣�����ʯ�����̳ɣ����˾�������������
��ͷ�д�������Ʈ��������ζ����Զ�������Ҽһ������׵�
���������д��˼�ե���͵Ĵ���ζ��

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaojie6",
        "north"   : __DIR__"xiaojie3",
        "southeast"   : __DIR__"cunlu3",
      ]));
  set("objects", ([
        __DIR__"npc/people"   : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "southeast")
    return 0;

  return ::valid_leave (who, dir);
}

