// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

һ�����ߵ�ɽ���ϣ�����һ���������������������ա���
���м�ֻС��ԶԶ�س��Ųݡ�������ſڴ�ɨ�øɸɾ�������
����һ���ң������¡�

LONG);

  set("exits", ([
        "westdown"   : __DIR__"cunlu6",
        "east"   : __DIR__"qian",
      ]));
  set("outdoors", __DIR__);

  setup();
}



