//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/shandao.c

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

����һ������εķ��ӣ�����ŵĶ���Щ����ӣ���Ȼ����ȫ������
���ģ�����������㣬�ı���ޣ���س��Ͼ�Ȼ���д˰��á�
LONG);

  set("exits", ([
        "north": __DIR__"dadian",
      ]));
  set("objects", ([
        __DIR__"npc/monk_gm":1,
        ]));
  setup();

}
