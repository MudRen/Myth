// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/zuofang.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����������Ÿ�ʽ�����������г�����������С�����������衣
���涼��ӡ�����ι�״�Ļ��ơ����������ݺ��һЩСѧͽ����ƹ
ƹ���ҵ��ô���������

LONG);

  set("exits", ([
        "south"       : __DIR__"xi4",
      ]));
  set("objects", ([ 
    __DIR__"npc/xijiang" : 1,
  ]));
  setup();
}

