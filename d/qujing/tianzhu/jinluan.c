// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���ǵ�");
  set ("long", @LONG

���ǵ���ׯ�Ͼ��࣬ʮ������������������𡣴��컨�嶥��
����������������������һյյ�������������Ʒ��������
��ʡ�����м���һ����̨�ף�����һ�ߴ�����Ʊ�����

LONG);

  set("exits", ([
        "south"   : __DIR__"zhaoyang",
        "north"   : __DIR__"yuhua",
      ]));
  set("objects", ([
        __DIR__"npc/king"   : 1,
        __DIR__"npc/junji"   : 1,
        __DIR__"npc/taijian"   : 2,
      ]));

  setup();
}


