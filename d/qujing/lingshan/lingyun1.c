//Cracked by Roath
// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ƶ�");
  set ("long", @LONG

�����У�һ��ɽ�������������˷�����ɽ���������ɷɺ磬ˮ
�����������ǧ���������ɿڰ�������������·���ߣ������
��һ����ľ�š�

LONG);

  set("exits", ([
        "southeast"   : __DIR__"dumuqiao",
        "westup"   : __DIR__"shandian",
      ]));
  set("outdoors", __DIR__);

  setup();
}



