//Cracked by Roath
// create by snowcat.c 4/8/1997
// room: /d/westway/west3.c

inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĵ�ٵ�������ݵ���ʮ���ۡ�����ͨ��
��ǿ���������������Ҫ����������ֱ����ƹ��������ǡ�

LONG);

  set("exits", ([
        "east" : __DIR__"west2",
        "northwest" : __DIR__"jincheng",
      ]));
       set("tsj_exst","northwest");
  set("outdoors", __DIR__);

  set("objects", ([ 
  "/d/obj/weapon/throwing/shi.c" : 1, 
  ]));
  setup();
}






