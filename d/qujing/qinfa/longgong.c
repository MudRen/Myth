// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�������Ļ��Ȼ��ƣ��м��������Ĺ��ң��ɰ�������Ľ�ɫ
����Χ�����гȺ�ɫ�Ʋ���̺��������һϸ�۶�����ͷ��β
����������

LONG);

  set("exits", ([
        "west"    : __DIR__"jinluan",
        "east"    : __DIR__"fenggong",
        "northeast"    : __DIR__"qingong1",
        "southeast"    : __DIR__"qingong2",
      ]));
  set("objects", ([
        __DIR__"npc/king"    : 1,
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

