// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�Է�");
  set ("long", @LONG

һ��ʯ�Է����������Ÿ�����Ƥ��ʯ����Ҳ��������Ƥ��ͷ��
�ǡ���ǽ����һ����ɫʯ����һ�Ŵ�ľ�Ρ�����������һʯ��
ͨ���ڵ

LONG);

  set("exits", ([
        "northeast"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 2,
        __DIR__"npc/huaqi"   : 1,
        __DIR__"obj/shoupi"   : 2,
      ]));

  setup();
}


