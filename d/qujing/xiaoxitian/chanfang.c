// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

һ�����°�ɵ��������Ѳ���ʹ�ã��ֱ����������ֿ⣬ǽ��
����һЩ�������ϱ�ԭ�����ȴ��ӣ��ѱ���ľ�������������
ͨ���԰���š�

LONG);

  set("exits", ([
        "north"   : __DIR__"caiyuan",
      ]));
  set("objects", ([
        __DIR__"obj/jinnao"   : 1,
        __DIR__"npc/tong"   : 3,
      ]));

  setup();
}



