// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dong.c

inherit ROOM;

void create ()
{
  set ("short", "���¶�");
  set ("long", @LONG

����ʪ�����ƣ���ɭ���ˡ����⿴������̦޺�߰ߣ����￴����
֪��ǳ����Լ��������ˮ֮������һ����ľ�ᵣ�����ٹҷ壬��
֪�����������ɾ���

LONG);

  set("exits", ([
        "northwest"  : __DIR__"dongwai",
      ]));
  set("objects", ([ 
      __DIR__"npc/shanyao" : 6,
      __DIR__"npc/huangpao" : 1,
      __DIR__"npc/baihua" : 1,
      ]));

  setup();
}

