// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����ϼ�ɺ�Ʈ����ɫ���ӭ��������ϼ���һ�޴�ķ��ܣ�
������˫����ʻ��ȣ��ɾŸ�������ס��������һդ���ţ���
���ǵ��

LONG);

  set("exits", ([
        "west"    : __DIR__"qiankun",
        "north"    : __DIR__"junying",
        "east"    : __DIR__"jinluan",
      ]));
  set("objects", ([
        __DIR__"npc/junshi"    : 2,
      ]));
  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive (who) &&
      dir == "east")
    return 0;
  return ::valid_leave(who,dir);
}
