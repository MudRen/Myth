// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���۱���");
  set ("long", @LONG

���۱�����������̨�ϣ�̨ǰ����һ����������ľ�㰸����
������ͭ��¯һ�ԣ���¯����ð����������̡������������
��Ժ����������¥���ϱ��Ǳ���

LONG);

  set("exits", ([
        "north"   : __DIR__"zhenlou",
        "south"   : __DIR__"baoge",
        "west"   : __DIR__"siyuan",
        "east"   : __DIR__"houdian",
      ]));
  set("objects", ([
        __DIR__"npc/xiaotong"   : 3,
        __DIR__"npc/huangmei"   : 1,
      ]));

  setup();
}



