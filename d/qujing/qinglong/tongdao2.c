// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "ͨ��");
  set ("long", @LONG

ͨ���ɶ��������쿪�����Ƚ���խ�������ϳ�����ɫ�����ݣ�
��ʯ��ء�������������Ѩ��ڣ���֪ͨ��δ���ͨ��������
�й��ߴ�����

LONG);

  set("exits", ([
        "northeast"   : __DIR__"wowang1",
        "east"   : __DIR__"wowang2",
        "southeast"   : __DIR__"wowang3",
        "west"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



