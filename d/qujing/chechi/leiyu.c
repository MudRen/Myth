// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/leiyi.c

inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

���﹩��ʯ�񣬷ֱ�Ϊ����֮�񡣵�����һ��Ƕ�������������
������ǩ�����߷������ĸ��廨�������ţ��Թ����ҹ�����ʱ
ʹ�á�

LONG);

  set("exits", ([
        "south"        : __DIR__"qiyu",
        "west"         : __DIR__"jinluan",
      ]));

  set("objects",([
        __DIR__"npc/taijian" : 1,
      ]));
  setup();
}

