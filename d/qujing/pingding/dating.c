// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ܣ��ɼ������ľ߹�ģ���������ľ��ľ��֮�࣬����
�ı���������һ��ͭ�ӣ�������ǣ���š�������ͨ����������
����ǰ����

LONG);

  set("exits", ([
        "west"   : __DIR__"qianting",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 3,
      ]));

  setup();
}



