//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�ڶ������Ҳ��һ�Ծ޴��̴����Ƥľ�ţ��ű��ǳ�ɫ���Ϸ
ˮ������������Ҹ���һ������߰����𶦣���������������
һ�ţ�����Ϊ���ϱ��ǵ���������š�

LONG);

  set("exits", ([
        "north"   : __DIR__"yimen",
        "south"   : __DIR__"sanmen",
        "west"   : __DIR__"sidian23",
        "east"   : __DIR__"sidian25",
      ]));
  set("objects", ([
        __DIR__"npc/jingang" : 4,
     ]));

  setup();
}


