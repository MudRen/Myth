// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������辫����һ����ʯ���ϰ���ϡ���������ǽ����
��һ��������̴���񣬺����ǽ�Ϲ�������Ƥ���ǡ���������
��һ��ͨ�����档

LONG);

  set("exits", ([
        "northwest"   : __DIR__"dating",
"enter" : "/d/qujing/jilei/bed.c",
      ]));
  set("objects", ([
        __DIR__"npc/yumian" : 1,
        __DIR__"npc/niumo" : 1,
        __DIR__"npc/jinjing" : 1,
      ]));

  setup();
}



