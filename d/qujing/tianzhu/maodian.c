// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ñ��");
  set ("long", @LONG

����һ��ר����ñ�ĵ��̣���������һ���ķ���������������
�涼���˸�ñ�ӡ�����������һˮĥͭ�����˿�������ñ��֮
����������ͭ��ǰ��ñ���վ��ӡ�

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao68",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_tian"   : 1,
      ]));

  setup();
}


