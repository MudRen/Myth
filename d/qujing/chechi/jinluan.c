// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/jinluan.c

inherit ROOM;

void create ()
{
  set ("short", "���ǵ�");
  set ("long", @LONG

�����ƻ�ͨ�������������߸����ϡ�����ǰ�����һ��������
�غ�������׺���Ϻ�����������֮��������ɷ��裬�����
�������Ƶ���

LONG);

  set("exits", ([
        "north"        : __DIR__"hougong2",
        "south"        : __DIR__"wufeng",
        "west"         : __DIR__"fengyun",
        "east"         : __DIR__"leiyu",
      ]));

  set("objects",([
         __DIR__"npc/taijian" : 1,
         __DIR__"npc/king" : 1,
      ]));


  setup();
}


