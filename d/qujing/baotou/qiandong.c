// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ǰ��");
  set ("long", @LONG

ǰ��������Ȼʯ��ʯͤ��Ϫˮ��ʯ��������������ʯ���Ϲ���
������������ʯͤ�߳���һЩ��С�Ļ��ݹ�ľ���ϱ���·ͨ��
���⣬��������һͨ����

LONG);

  set("exits", ([
        "south"   : __DIR__"hukou",
        "northeast"   : __DIR__"houdong",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 3,
        __DIR__"npc/yaowang"  : 1,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object wang = present ("yao wang",this_object());

  if (wang &&
      living (wang) &&
      dir == "northeast")
    return notify_fail ("��������ȵ��������ӣ�\n");
  return ::valid_leave(who,dir);
}

