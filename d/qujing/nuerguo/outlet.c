// created by snowcat.c 4/4/1997
// room: /d/nuerguo/outlet.c

inherit ROOM;

void create ()
{
  set ("short", "�Թ�����");
  set ("long", @LONG

ͻȻ�������������г�����һ����ڣ������ƺ���һ����·��
������һϲ��������Թ����߳����ˡ�

LONG);

  set("exits", ([
        "westup" : __DIR__"shanpo",
      ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object me, string dir)
{
  // once get into here, reset all greenyard temps, to prevent abuse
  me->set("startroom","/d/city/kezhan");
  me->set_temp("lost_in_greenyard",0);
  me->set_temp("out_of_greenyard",0);
  return 1;
}






