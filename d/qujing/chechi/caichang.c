// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/caichang.c

inherit ROOM;

void create ()
{
  set ("short", "���ǲ˳�");
  set ("long", @LONG

�˳��ǳ��ٹ�ƽ�����ճ��Ϲ��߲�����ĵط�������������һ
Ƭ��Ƥ��Ҷ��������һ�ص���Ǽ�ë����Զ�����м����ƾɵĿ�
��ͣ��·�ߡ�

LONG);

  set("exits", ([
        "north"        : __DIR__"jieshi2",
        "east"         : __DIR__"jieshi4",
        "west"         : __DIR__"jiuguan",
        "south"        : __DIR__"taiping",
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}

